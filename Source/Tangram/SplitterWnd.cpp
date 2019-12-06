/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2019 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS
* OUTLINED IN THE GPL LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
********************************************************************************/

// TangramSplitterWnd.cpp : implementation file

#include "stdafx.h"
#include "TangramApp.h"
#include "WndNode.h"
#include "Compositor.h"
#include "NodeWnd.h"
#include "WPFView.h"
#include "SplitterWnd.h"
#include "TangramHtmlTreeWnd.h"
#include "VisualStudioPlus\VSAddin.h"
#include "chromium/BrowserWnd.h"
#include "chromium/HtmlWnd.h"

struct AUX_DATA
{
	// system metrics
	int cxVScroll, cyHScroll;
	int cxIcon, cyIcon;

	int cxBorder2, cyBorder2;

	// device metrics for screen
	int cxPixelsPerInch, cyPixelsPerInch;

	// convenient system color
	HBRUSH hbrWindowFrame;
	HBRUSH hbrBtnFace;

	// color values of system colors used for CToolBar
	COLORREF clrBtnFace, clrBtnShadow, clrBtnHilite;
	COLORREF clrBtnText, clrWindowFrame;

	// standard cursors
	HCURSOR hcurWait;
	HCURSOR hcurArrow;
	HCURSOR hcurHelp;       // cursor used in Shift+F1 help

	// special GDI objects allocated on demand
	HFONT   hStatusFont;
	HFONT   hToolTipsFont;
	HBITMAP hbmMenuDot;

	// Implementation
	AUX_DATA();
	~AUX_DATA();
	void UpdateSysColors();
	void UpdateSysMetrics();
};

extern AFX_DATA AUX_DATA afxData;
#ifndef AFX_CX_BORDER
#define AFX_CX_BORDER CX_BORDER 
#endif

#ifndef AFX_CY_BORDER
#define AFX_CY_BORDER CY_BORDER 
#endif
#define CX_BORDER   1
#define CY_BORDER   1

// CSplitterNodeWnd
enum HitTestValue
{
	noHit = 0,
	vSplitterBox = 1,
	hSplitterBox = 2,
	bothSplitterBox = 3,        // just for keyboard
	vSplitterBar1 = 101,
	vSplitterBar15 = 115,
	hSplitterBar1 = 201,
	hSplitterBar15 = 215,
	splitterIntersection1 = 301,
	splitterIntersection225 = 525
};

IMPLEMENT_DYNCREATE(CSplitterNodeWnd, CSplitterWnd)

CSplitterNodeWnd::CSplitterNodeWnd()
{
	bInited = false;
	m_bCreated = false;
	m_bNeedRefreh = false;
	m_pWndNode = nullptr;
	m_pHostNode = nullptr;
	m_nHostWidth = m_nHostHeight = 0;
	m_nNeedRefreshCol = -1;
	m_Vmin = m_Vmax = m_Hmin = m_Hmax = 0;
}

CSplitterNodeWnd::~CSplitterNodeWnd()
{
}

BEGIN_MESSAGE_MAP(CSplitterNodeWnd, CSplitterWnd)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEACTIVATE()
	ON_MESSAGE(WM_TABCHANGE, OnActivePage)
	ON_MESSAGE(WM_TANGRAMGETNODE, OnGetTangramObj)
	ON_MESSAGE(WM_TANGRAMMSG, OnSplitterNodeAdd)
	ON_MESSAGE(WM_TGM_SETACTIVEPAGE, OnActiveTangramObj)
	ON_MESSAGE(WM_HOSTNODEFORSPLITTERCREATED, OnSplitterCreated)
END_MESSAGE_MAP()

// CSplitterNodeWnd diagnostics

#ifdef _DEBUG
void CSplitterNodeWnd::AssertValid() const
{
	//CSplitterWnd::AssertValid();
}

#ifndef _WIN32_WCE
void CSplitterNodeWnd::Dump(CDumpContext& dc) const
{
	CSplitterWnd::Dump(dc);
}
#endif
#endif //_DEBUG

BOOL CSplitterNodeWnd::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	if (CWnd::OnNotify(wParam, lParam, pResult))
		return TRUE;

	// route commands to the splitter to the parent frame window
	//*pResult = EnsureParentFrame()->SendMessage(WM_NOTIFY, wParam, lParam);
	return true;
}

void CSplitterNodeWnd::TrackRowSize(int y, int row)
{
	ASSERT_VALID(this);
	ASSERT(m_nRows > 1);

	CPoint pt(0, y);
	ClientToScreen(&pt);
	GetPane(row, 0)->ScreenToClient(&pt);
	m_pRowInfo[row].nIdealSize = pt.y;      // new size
	if (pt.y < m_pRowInfo[row].nMinSize)
	{
		// resized too small
		m_pRowInfo[row].nIdealSize = 0; // make it go away
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteRow(row);
	}
	else if (m_pRowInfo[row].nCurSize + m_pRowInfo[row + 1].nCurSize
		< pt.y + m_pRowInfo[row + 1].nMinSize)
	{
		// not enough room for other pane
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteRow(row + 1);
	}
	if (m_pHostNode&&row != m_nRows - 1)
	{
		ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane

		CRect rectInside;
		GetInsideRect(rectInside);

		int i;
		int _nSize = rectInside.Height();
		CSplitterWnd::CRowColInfo* pInfo;

		if (_nSize < 0)
			_nSize = 0;  // if really too small, layout as zero size

		for (i = 0, pInfo = m_pRowInfo; i < m_nRows - 1; i++, pInfo++)
		{
			if (pInfo->nIdealSize < pInfo->nMinSize)
				pInfo->nIdealSize = 0;      // too small to see
			_nSize -= pInfo->nIdealSize;
		}
		_nSize -= (m_nRows - 1)*m_cxSplitterGap;
		pInfo->nCurSize = _nSize;
		pInfo->nIdealSize = _nSize;
	}
}

void CSplitterNodeWnd::TrackColumnSize(int x, int col)
{
	ASSERT_VALID(this);
	ASSERT(m_nCols > 1);

	CPoint pt(x, 0);
	ClientToScreen(&pt);
	GetPane(0, col)->ScreenToClient(&pt);
	m_pColInfo[col].nIdealSize = pt.x;      // new size
	if (pt.x < m_pColInfo[col].nMinSize)
	{
		// resized too small
		m_pColInfo[col].nIdealSize = 0; // make it go away
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteColumn(col);
	}
	else if (m_pColInfo[col].nCurSize + m_pColInfo[col + 1].nCurSize
		< pt.x + m_pColInfo[col + 1].nMinSize)
	{
		// not enough room for other pane
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteColumn(col + 1);
	}
	if (m_pHostNode&&col != m_nCols - 1)
	{
		ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane

		CRect rectInside;
		GetInsideRect(rectInside);

		int i;
		int _nSize = rectInside.Width();
		CSplitterWnd::CRowColInfo* pInfo;

		if (_nSize < 0)
			_nSize = 0;  // if really too small, layout as zero size

		for (i = 0, pInfo = m_pColInfo; i < m_nCols - 1; i++, pInfo++)
		{
			if (pInfo->nIdealSize < pInfo->nMinSize)
				pInfo->nIdealSize = 0;      // too small to see
			_nSize -= pInfo->nIdealSize;
		}
		_nSize -= (m_nCols - 1)*m_cxSplitterGap;
		pInfo->nCurSize = _nSize;
		pInfo->nIdealSize = _nSize;
	}
}

LRESULT CSplitterNodeWnd::OnSplitterNodeAdd(WPARAM wParam, LPARAM lParam)
{
	if (lParam == 1992 || wParam == 0x01000 || wParam == 0)
	{
		return 0;
	}
	if (lParam == 1993)
	{
		//fix bug for .net Control or Window Form
		switch (wParam)
		{
		case 1:
		{
			bInited = true;
			::PostMessage(m_hWnd, WM_TANGRAMMSG, 2, 1993);
			return 0;
		}
		break;
		case 2:
		{
			m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->HostPosChanged();
			return 0;
		}
		break;
		case 3:
		{
			RecalcLayout();
			return 0;
		}
		break;
		}
		return 0;
	}
	IWndNode* _pNode = nullptr;
	CString str = (LPCTSTR)lParam;
	CWndNode* pOldNode = (CWndNode*)g_pTangram->m_pDesignWindowNode;
	CTangramXmlParse* pOld = pOldNode->m_pHostParse;

	long	m_nRow;
	g_pTangram->m_pDesignWindowNode->get_Row(&m_nRow);
	long	m_nCol;
	g_pTangram->m_pDesignWindowNode->get_Col(&m_nCol);
	IWndNode* _pOldNode = nullptr;
	m_pWndNode->GetNode(m_nRow, m_nCol, &_pOldNode);
	CWndNode* _pOldNode2 = (CWndNode*)_pOldNode;
	CTangramXmlParse* _pOldParse = _pOldNode2->m_pHostParse;
	m_pWndNode->OpenEx(m_nRow, m_nCol, CComBSTR(L""), str.AllocSysString(), &_pNode);
	CWndNode* pNode = (CWndNode*)_pNode;
	if (pNode&&pOldNode)
	{
		CCompositor* pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
		pNode->m_pTangramNodeCommonData->m_pCompositor->m_bDesignerState = true;
		pNode->m_pTangramNodeCommonData->m_pCompositor->m_pDoc = pCompositor->m_pDoc;
		((CWndNode*)pNode)->m_pTangramNodeCommonData->m_pOfficeObj = m_pWndNode->m_pTangramNodeCommonData->m_pOfficeObj;
		CTangramNodeVector::iterator it;
		it = find(m_pWndNode->m_vChildNodes.begin(), m_pWndNode->m_vChildNodes.end(), pOldNode);

		if (it != m_pWndNode->m_vChildNodes.end())
		{
			pNode->m_pRootObj = m_pWndNode->m_pRootObj;
			pNode->m_pParentObj = m_pWndNode;
			m_pWndNode->m_pTangramNodeCommonData->m_mapLayoutNodes[((CWndNode*)pNode)->m_strName] = (CWndNode*)pNode;
			CTangramNodeVector vec = pNode->m_vChildNodes;
			CWndNode* pChildNode = nullptr;
			for (auto it2 : pNode->m_vChildNodes)
			{
				pChildNode = it2;
				pChildNode->m_pRootObj = m_pWndNode->m_pRootObj;
			}
			CTangramXmlParse* pNew = pNode->m_pHostParse;
			CTangramXmlParse* pRet = m_pWndNode->m_pHostParse->ReplaceNode(pOld, pNew, _T(""));
			m_pWndNode->m_vChildNodes.erase(it);
			m_pWndNode->m_vChildNodes.push_back(pNode);
			pOldNode->m_pHostWnd->DestroyWindow();
			CString strXml = m_pWndNode->m_pTangramNodeCommonData->m_pTangramParse->xml();
			g_pTangram->m_pHostDesignUINode = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->m_pWorkNode;
			if (g_pTangram->m_pHostDesignUINode)
			{
				CTangramHtmlTreeWnd* pTreeCtrl = g_pTangram->m_pDocDOMTree;
				pTreeCtrl->DeleteItem(g_pTangram->m_pDocDOMTree->m_hFirstRoot);

				if (pTreeCtrl->m_pHostXmlParse)
				{
					delete pTreeCtrl->m_pHostXmlParse;
				}
				g_pTangram->InitDesignerTreeCtrl(strXml);
				g_pTangram->m_pHostDesignUINode->m_pDocXmlParseNode = pTreeCtrl->m_pHostXmlParse;
			}
#ifndef _WIN64
			if (g_pTangram->m_strExeName == _T("devenv"))
			{
				VisualStudioPlus::CVSAddin* pAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;
				if (pAddin->m_pOutputWindowPane)
					pAddin->m_pOutputWindowPane->OutputString(strXml.AllocSysString());
			}
#endif
			g_pTangram->m_pDesignWindowNode = nullptr;
			RecalcLayout();
		}
	}
	return -1;
}

LRESULT CSplitterNodeWnd::OnActiveTangramObj(WPARAM wParam, LPARAM lParam)
{
	RecalcLayout();
	m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->HostPosChanged();
	::InvalidateRect(::GetParent(m_hWnd), nullptr, true);
	return -1;
}

LRESULT CSplitterNodeWnd::OnSplitterCreated(WPARAM wParam, LPARAM lParam)
{
	int _nWidth = 0;
	SetColumnInfo(lParam, m_nHostWidth, _nWidth);
	SetRowInfo(wParam, m_nHostHeight, _nWidth);
	return 0;
}

LRESULT CSplitterNodeWnd::OnActivePage(WPARAM wParam, LPARAM lParam)
{
	if (g_pTangram->m_pDocDOMTree&&g_pTangram->m_pCLRProxy)
	{
		CCompositor* pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
		if (pCompositor->m_bDesignerState)
			g_pTangram->m_pCLRProxy->SelectNode(m_pWndNode);
	}
	return CWnd::DefWindowProc(WM_TABCHANGE, wParam, lParam);;
}

void CSplitterNodeWnd::StartTracking(int ht)
{
	ASSERT_VALID(this);
	if (ht == noHit)
		return;

	CWndNode* pNode = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->m_pWorkNode;
	if (pNode&&pNode->m_pTangramNodeCommonData->m_pHostClientView)
	{
		pNode->m_pHostWnd->ModifyStyle(WS_CLIPSIBLINGS, 0);
	}

	GetInsideRect(m_rectLimit);

	if (ht >= splitterIntersection1 && ht <= splitterIntersection225)
	{
		// split two directions (two tracking rectangles)
		int row = (ht - splitterIntersection1) / 15;
		int col = (ht - splitterIntersection1) % 15;

		GetHitRect(row + vSplitterBar1, m_rectTracker);
		int yTrackOffset = m_ptTrackOffset.y;
		m_bTracking2 = true;
		GetHitRect(col + hSplitterBar1, m_rectTracker2);
		m_ptTrackOffset.y = yTrackOffset;
	}
	else if (ht == bothSplitterBox)
	{
		// hit on splitter boxes (for keyboard)
		GetHitRect(vSplitterBox, m_rectTracker);
		int yTrackOffset = m_ptTrackOffset.y;
		m_bTracking2 = true;
		GetHitRect(hSplitterBox, m_rectTracker2);
		m_ptTrackOffset.y = yTrackOffset;

		// center it
		m_rectTracker.OffsetRect(0, m_rectLimit.Height() / 2);
		m_rectTracker2.OffsetRect(m_rectLimit.Width() / 2, 0);
	}
	else
	{
		// only hit one bar
		GetHitRect(ht, m_rectTracker);
	}

	// steal focus and capture
	SetCapture();
	SetFocus();

	// make sure no updates are pending
	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_UPDATENOW);

	// set tracking state and appropriate cursor
	m_bTracking = true;
	OnInvertTracker(m_rectTracker);
	if (m_bTracking2)
		OnInvertTracker(m_rectTracker2);
	m_htTrack = ht;
}

void CSplitterNodeWnd::StopTracking(BOOL bAccept)
{
	if (!m_bTracking)
		return;
	CCompositor* pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
	CWndNode* pNode = pCompositor->m_pWorkNode;
	if (pNode&&pNode->m_pTangramNodeCommonData->m_pHostClientView)
	{
		pNode->m_pHostWnd->ModifyStyle(0, WS_CLIPSIBLINGS);
		::InvalidateRect(pCompositor->m_hWnd, NULL, false);
		pNode->m_pHostWnd->Invalidate();
	}

	CSplitterWnd::StopTracking(bAccept);

	if (bAccept)
	{
		pCompositor->UpdateVisualWPFMap(::GetParent(m_hWnd), false);
		::InvalidateRect(pCompositor->m_hWnd, nullptr, true);
		if (pCompositor->m_bDesignerState&&g_pTangram->m_pDesignWindowNode)
		{
			g_pTangram->UpdateWndNode(g_pTangram->m_pDesignWindowNode->m_pRootObj);
			CComBSTR bstrXml(L"");
			g_pTangram->m_pDesignWindowNode->m_pRootObj->get_DocXml(&bstrXml);
			g_pTangram->put_AppKeyValue(CComBSTR(L"TangramDesignerXml"), CComVariant(bstrXml));
		}
		ChromePlus::CHtmlWnd* pWebWnd = nullptr;
		if (pCompositor->m_pWebWnd)
		{
			pWebWnd = pCompositor->m_pWebWnd;
		}
		else if(g_pTangram->m_pDesignWindowNode&&g_pTangram->m_pDesignWindowNode->m_pTangramNodeCommonData->m_pCompositor->m_pWebWnd)
			pWebWnd = g_pTangram->m_pDesignWindowNode->m_pTangramNodeCommonData->m_pCompositor->m_pWebWnd;
		pCompositor->HostPosChanged();
		if (pWebWnd)
		{
			//::SendMessage(pWebWnd->m_hWnd, WM_LBUTTONDOWN, 0, 0);
			::SendMessage(::GetParent(pWebWnd->m_hWnd), WM_BROWSERLAYOUT, 0, 2);
		}
	}
}

void CSplitterNodeWnd::PostNcDestroy()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	delete m_pWndNode;
	CSplitterWnd::PostNcDestroy();
	delete this;
}

// Generic routine:
//  for X direction: pInfo = m_pColInfo, nMax = m_nMaxCols, nSize = cx
//  for Y direction: pInfo = m_pRowInfo, nMax = m_nMaxRows, nSize = cy
void CSplitterNodeWnd::TangramLayoutRowCol(CSplitterWnd::CRowColInfo* pInfoArray, int nMax, int nSize, int nSizeSplitter, CWndNode* pHostNode, bool bCol)
{
	ASSERT(pInfoArray != NULL);
	ASSERT(nMax > 0);
	ASSERT(nSizeSplitter > 0);

	CSplitterWnd::CRowColInfo* pInfo;
	CSplitterWnd::CRowColInfo* pInfoHost = nullptr;
	int i;

	if (nSize < 0)
		nSize = 0;  // if really too small, layout as zero size

					// start with ideal sizes
	int _indexHost = -1;
	int _nSize = nSize;
	if (pHostNode)
	{
		if (bCol)
			_indexHost = pHostNode->m_nCol;
		else
			_indexHost = pHostNode->m_nRow;
	}
	if (_indexHost != -1)
		pInfoHost = &pInfoArray[_indexHost];

	for (i = 0, pInfo = pInfoArray; i < nMax; i++, pInfo++)
	{
		if (pInfo->nIdealSize < pInfo->nMinSize)
			pInfo->nIdealSize = 0;      // too small to see
		pInfo->nCurSize = pInfo->nIdealSize;
		if (_indexHost != -1)
		{
			if (_indexHost != i)
			{
				_nSize -= pInfo->nIdealSize;
			}
		}
		if (i == nMax - 1)
		{
			if (_indexHost != -1 && pInfoHost)
			{
				if (_indexHost != nMax - 1)
				{
					_nSize -= (nMax - 1)*nSizeSplitter;
					if (_nSize < 0)
						_nSize = 0;
					pInfoHost->nCurSize = _nSize;
				}
				else
					pInfoHost->nCurSize = INT_MAX;  // last row/column takes the rest
				if (bCol)
					m_nHostWidth = _nSize;
				else
					m_nHostHeight = _nSize;
			}
			else
				pInfo->nCurSize = INT_MAX;  // last row/column takes the rest
		}
	}

	for (i = 0, pInfo = pInfoArray; i < nMax; i++, pInfo++)
	{
		ASSERT(nSize >= 0);
		if (nSize == 0)
		{
			// no more room (set pane to be invisible)
			pInfo->nCurSize = 0;
			continue;       // don't worry about splitters
		}
		else if (nSize < pInfo->nMinSize && i != 0)
		{
			// additional panes below the recommended minimum size
			//   aren't shown and the size goes to the previous pane
			pInfo->nCurSize = 0;

			// previous pane already has room for splitter + border
			//   add remaining size and remove the extra border
			ASSERT(afxData.cxBorder2 == afxData.cyBorder2);
			(pInfo - 1)->nCurSize += nSize + afxData.cxBorder2;
			nSize = 0;
		}
		else
		{
			// otherwise we can add the second pane
			ASSERT(nSize > 0);
			if (pInfo->nCurSize == 0)
			{
				// too small to see
				if (i != 0)
					pInfo->nCurSize = 0;
			}
			else if (nSize < pInfo->nCurSize)
			{
				// this row/col won't fit completely - make as small as possible
				pInfo->nCurSize = nSize;
				nSize = 0;
			}
			else
			{
				// can fit everything
				nSize -= pInfo->nCurSize;
			}
		}

		// see if we should add a splitter
		ASSERT(nSize >= 0);
		if (i != nMax - 1)
		{
			// should have a splitter
			if (nSize > nSizeSplitter)
			{
				nSize -= nSizeSplitter; // leave room for splitter + border
				ASSERT(nSize > 0);
			}
			else
			{
				// not enough room - add left over less splitter size
				ASSERT(afxData.cxBorder2 == afxData.cyBorder2);
				pInfo->nCurSize += nSize;
				if (pInfo->nCurSize > (nSizeSplitter - afxData.cxBorder2))
					pInfo->nCurSize -= (nSizeSplitter - afxData.cyBorder2);
				nSize = 0;
			}
		}
	}
	//ASSERT(nSize == 0); // all space should be allocated
}

// repositions client area of specified window
// assumes everything has WS_BORDER or is inset like it does
//  (includes scroll bars)
void CSplitterNodeWnd::TangramDeferClientPos(AFX_SIZEPARENTPARAMS* lpLayout, CWnd* pWnd, int x, int y, int cx, int cy, BOOL bScrollBar)
{
	ASSERT(pWnd != NULL);
	ASSERT(pWnd->m_hWnd != NULL);
	CRect rect(x, y, x + cx, y + cy);

	// adjust for 3d border (splitter windows have implied border)
	if ((pWnd->GetExStyle() & WS_EX_CLIENTEDGE) ||
		pWnd->IsKindOf(RUNTIME_CLASS(CSplitterWnd)))
		rect.InflateRect(afxData.cxBorder2, afxData.cyBorder2);

	// first check if the new rectangle is the same as the current
	CRect rectOld;
	pWnd->GetWindowRect(rectOld);
	pWnd->GetParent()->ScreenToClient(&rectOld);
	if (rect != rectOld)
	{
		ASSERT(pWnd->m_hWnd != NULL);
		ASSERT(rect != NULL);
		HWND hWndParent = ::GetParent(pWnd->m_hWnd);
		ASSERT(hWndParent != NULL);

		if (lpLayout != NULL && lpLayout->hDWP == NULL)
			return;

		// first check if the new rectangle is the same as the current
		CRect rectOld;
		::GetWindowRect(pWnd->m_hWnd, rectOld);
		::ScreenToClient(hWndParent, &rectOld.TopLeft());
		::ScreenToClient(hWndParent, &rectOld.BottomRight());
		if (::EqualRect(rectOld, rect))
			return;     // nothing to do

		// try to use DeferWindowPos for speed, otherwise use SetWindowPos
		if (lpLayout != NULL)
		{
			lpLayout->hDWP = ::DeferWindowPos(lpLayout->hDWP, pWnd->m_hWnd, NULL,
				rect.left, rect.top, rect.right - rect.left,
				rect.bottom - rect.top, SWP_NOACTIVATE | SWP_NOZORDER);
		}
		else
		{
			::SetWindowPos(pWnd->m_hWnd, NULL, rect.left, rect.top, rect.right - rect.left,
				rect.bottom - rect.top,
				SWP_NOACTIVATE | SWP_NOZORDER);
		}
	}
	else
	{
		::PostMessage(pWnd->m_hWnd, WM_SPLITTERREPOSITION, 0, 0);
	}
}

void CSplitterNodeWnd::RecalcLayout()
{
	ASSERT_VALID(this);
	ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane||::IsWindowVisible(m_hWnd) == FALSE
	if (m_bCreated == false || GetDlgItem(IdFromRowCol(0, 0)) == NULL)
		return;
	_RecalcLayout();
	m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->UpdateVisualWPFMap(m_hWnd, false);
}

void CSplitterNodeWnd::_RecalcLayout()
{
	ASSERT_VALID(this);
	ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane

	if (m_nMaxCols >= 2)
	{
		int LimitWidth = 0;
		int LimitWndCount = 0;
		int Width = 0;
		RECT SplitterWndRect;
		GetWindowRect(&SplitterWndRect);
		Width = SplitterWndRect.right - SplitterWndRect.left - m_nMaxCols * m_cxSplitterGap - LimitWidth + m_cxBorder * m_nMaxCols;
		if (Width < 0)
			return;
	}
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CRect rectClient;
	GetClientRect(rectClient);
	rectClient.InflateRect(-m_cxBorder, -m_cyBorder);

	CRect rectInside;
	GetInsideRect(rectInside);

	// layout columns (restrict to possible sizes)
	TangramLayoutRowCol(m_pColInfo, m_nCols, rectInside.Width(), m_cxSplitterGap, m_pHostNode, true);
	TangramLayoutRowCol(m_pRowInfo, m_nRows, rectInside.Height(), m_cySplitterGap, m_pHostNode, false);

	// give the hint for the maximum number of HWNDs
	AFX_SIZEPARENTPARAMS layout;
	layout.hDWP = ::BeginDeferWindowPos((m_nCols + 1) * (m_nRows + 1) + 1);

	//BLOCK: Reposition all the panes
	{
		int x = rectClient.left;
		for (int col = 0; col < m_nCols; col++)
		{
			int cxCol = m_pColInfo[col].nCurSize;
			int y = rectClient.top;
			for (int row = 0; row < m_nRows; row++)
			{
				int cyRow = m_pRowInfo[row].nCurSize;
				CWnd* pWnd = GetPane(row, col);
				TangramDeferClientPos(&layout, pWnd, x, y, cxCol, cyRow, FALSE);
				y += cyRow + m_cySplitterGap;
			}
			x += cxCol + m_cxSplitterGap;
		}
	}

	// move and resize all the windows at once!
	if (layout.hDWP == NULL || !::EndDeferWindowPos(layout.hDWP))
		TRACE(traceAppMsg, 0, "Warning: DeferWindowPos failed - low system resources.\n");

	// invalidate all the splitter bars (with NULL pDC)
	DrawAllSplitBars(NULL, rectInside.right, rectInside.bottom);
	::InvalidateRect(m_hWnd, nullptr, false);
}

BOOL CSplitterNodeWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_pWndNode = g_pTangram->m_pActiveNode;
	m_pWndNode->m_pHostWnd = this;
	m_pWndNode->m_nViewType = Splitter;
	m_pWndNode->m_nID = nID;
	m_pWndNode->m_pDisp = nullptr;
	m_pWndNode->m_pTangramNodeCommonData->m_mapLayoutNodes[m_pWndNode->m_strName] = m_pWndNode;

	int r, g, b;
	CComBSTR bstrVal(L"");
	m_pWndNode->get_Attribute(CComBSTR("lefttopcolor"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("RGB(%d,%d,%d)"), &r, &g, &b);
		rgbLeftTop = RGB(r, g, b);
	}
	else
	{
		rgbLeftTop = RGB(240, 240, 240);
	}

	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR("rightbottomcolor"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("RGB(%d,%d,%d)"), &r, &g, &b);
		rgbRightBottom = RGB(r, g, b);
	}
	else
	{
		rgbRightBottom = RGB(240, 240, 240);
	}
	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR(L"middlecolor"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("RGB(%d,%d,%d)"), &r, &g, &b);
		rgbMiddle = RGB(r, g, b);
	}
	else
	{
		rgbMiddle = RGB(240, 240, 240);
	}
	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR(L"splitterwidth"), &bstrVal);
	m_cxSplitterGap = m_cySplitterGap = m_cxSplitter = m_cySplitter = !CString(bstrVal).IsEmpty()?_ttoi(CString(bstrVal)):7;

	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR(L"borderwidth"), &bstrVal);
	m_cxBorder = m_cyBorder = !CString(bstrVal).IsEmpty()?_ttoi(CString(bstrVal)):2;

	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR(L"vmin"), &bstrVal);
	m_Vmin = !CString(bstrVal).IsEmpty()?_ttoi(CString(bstrVal)):0;

	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR(L"vmax"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		m_Vmax = _ttoi(CString(bstrVal));
		if (m_Vmax <= 0)
			m_Vmax = 65535;
	}
	else
		m_Vmax = 65535;
	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR(L"hmin"), &bstrVal);
	m_Hmin = !CString(bstrVal).IsEmpty()?_ttoi(CString(bstrVal)):0;

	bstrVal.Empty();
	m_pWndNode->get_Attribute(CComBSTR(L"hmax"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		m_Hmax = _ttoi(CString(bstrVal));
		if (m_Hmax <= 0)
			m_Hmax = 65535;
	}
	else
		m_Hmax = 65535;

	m_pWndNode->m_nRows = m_pWndNode->m_pHostParse->attrInt(TGM_ROWS, 0);
	m_pWndNode->m_nCols = m_pWndNode->m_pHostParse->attrInt(TGM_COLS, 0);

	if (nID == 0)
		nID = 1;

	if (CreateStatic(pParentWnd, m_pWndNode->m_nRows, m_pWndNode->m_nCols, dwStyle, nID))
	{
		CString strWidth = m_pWndNode->m_pHostParse->attr(TGM_WIDTH, _T(""));
		strWidth += _T(",");
		CString strHeight = m_pWndNode->m_pHostParse->attr(TGM_HEIGHT, _T(""));
		strHeight += _T(",");

		int nWidth, nHeight, nPos;
		CString strW, strH, strOldWidth, strName;

		strOldWidth = strWidth;
		long nSize = m_pWndNode->m_pHostParse->GetCount();
		int nIndex = 0;
		CTangramXmlParse* pSubItem = m_pWndNode->m_pHostParse->GetChild(nIndex);
		for (int i = 0; i < m_pWndNode->m_nRows; i++)
		{
			nPos = strHeight.Find(_T(","));
			strH = strHeight.Left(nPos);
			strHeight = strHeight.Mid(nPos + 1);
			nHeight = _ttoi(strH);

			strWidth = strOldWidth;
			for (int j = 0; j < m_pWndNode->m_nCols; j++)
			{
				nPos = strWidth.Find(_T(","));
				strW = strWidth.Left(nPos);
				strWidth = strWidth.Mid(nPos + 1);
				nWidth = _ttoi(strW);
				strName = pSubItem->attr(TGM_NAME, _T(""));
				strName.Trim();
				strName.MakeLower();
				CWndNode* pObj = new CComObject<CWndNode>;
				pObj->m_pRootObj = m_pWndNode->m_pRootObj;
				if (nIndex < nSize)
					pObj->m_pHostParse = pSubItem;

				pObj->m_pParentObj = m_pWndNode;

				m_pWndNode->AddChildNode(pObj);
				pObj->InitWndNode();

				if (pObj->m_pObjClsInfo)
				{
					pObj->m_nRow = i;
					pObj->m_nCol = j;

					pObj->m_nWidth = nWidth;
					pObj->m_nHeigh = nHeight;
					if (pContext->m_pNewViewClass == nullptr)
						pContext->m_pNewViewClass = RUNTIME_CLASS(CNodeWnd);
					CreateView(pObj->m_nRow, pObj->m_nCol, pObj->m_pObjClsInfo, CSize(max(pObj->m_nWidth, m_Hmin), max(pObj->m_nHeigh, m_Vmin)), pContext);
				}
				nIndex++;
				if (nIndex < nSize)
					pSubItem = m_pWndNode->m_pHostParse->GetChild(nIndex);
				else if(nIndex< m_pWndNode->m_nCols* m_pWndNode->m_nRows)
				{
					CString strName = _T("");
					strName.Format(_T("%s_splitterchild_%i"), m_pWndNode->m_strName, nIndex);
					pSubItem = m_pWndNode->m_pHostParse->AddNode(strName);
				}
			}
		}
		SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOREDRAW);
		if (m_pWndNode->m_pTangramNodeCommonData->m_pCompositorManager)
			m_pWndNode->m_pTangramNodeCommonData->m_pCompositorManager->Fire_NodeCreated(m_pWndNode);

		SetWindowText(m_pWndNode->m_strNodeName);
		m_bCreated = true;
		CWndNode* pHostNode = nullptr;
		CWndNode* pParent = nullptr;
		CCompositor* pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
		bool bHasHostView = false;
		if (pCompositor->m_pBindingNode)
		{
			pHostNode = pCompositor->m_pBindingNode;
			if (::IsChild(m_hWnd, pHostNode->m_pHostWnd->m_hWnd))
			{
				bHasHostView = true;
				pParent = pHostNode->m_pParentObj;
				while (pParent != m_pWndNode)
				{
					pHostNode = pParent;
					pParent = pHostNode->m_pParentObj;
				}
			}
		}
		if (pHostNode&&::IsChild(m_hWnd, pHostNode->m_pHostWnd->m_hWnd))
			m_pHostNode = pHostNode;

		_RecalcLayout();

		return true;
	}
	return false;
}

LRESULT CSplitterNodeWnd::OnGetTangramObj(WPARAM wParam, LPARAM lParam)
{
	if (m_pWndNode)
		return (LRESULT)m_pWndNode;
	return (long)CWnd::DefWindowProc(WM_TANGRAMGETNODE, wParam, lParam);;
}

void CSplitterNodeWnd::OnPaint()
{
	ASSERT_VALID(this);
	CPaintDC dc(this);

	CRect rectClient;
	GetClientRect(&rectClient);

	CRect rectInside;
	GetInsideRect(rectInside);
	rectInside.InflateRect(4, 4);


	// draw the splitter boxes
	if (m_bHasVScroll && m_nRows < m_nMaxRows)
	{
		OnDrawSplitter(&dc, splitBox, CRect(rectInside.right, rectClient.top, rectClient.right, rectClient.top + m_cySplitter));
	}

	if (m_bHasHScroll && m_nCols < m_nMaxCols)
	{
		OnDrawSplitter(&dc, splitBox,
			CRect(rectClient.left, rectInside.bottom,
				rectClient.left + m_cxSplitter, rectClient.bottom));
	}

	// extend split bars to window border (past margins)
	DrawAllSplitBars(&dc, rectInside.right, rectInside.bottom);
	// draw splitter intersections (inside only)
	GetInsideRect(rectInside);
	dc.IntersectClipRect(rectInside);
	CRect rect;
	rect.top = rectInside.top;
	for (int row = 0; row < m_nRows - 1; row++)
	{
		rect.top += m_pRowInfo[row].nCurSize + m_cyBorderShare;
		rect.bottom = rect.top + m_cySplitter;
		rect.left = rectInside.left;
		for (int col = 0; col < m_nCols - 1; col++)
		{
			rect.left += m_pColInfo[col].nCurSize + m_cxBorderShare;
			rect.right = rect.left + m_cxSplitter;
			OnDrawSplitter(&dc, splitIntersection, rect);
			rect.left = rect.right + m_cxBorderShare;
		}
		rect.top = rect.bottom + m_cxBorderShare;
	}
}

void CSplitterNodeWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rectArg)
{
	if (pDC == nullptr)
	{
		RedrawWindow(rectArg, NULL, RDW_INVALIDATE | RDW_NOCHILDREN);
		return;
	}
	ASSERT_VALID(pDC);
	;

	// otherwise, actually draw
	CRect rect = rectArg;
	switch (nType)
	{
	case splitBorder:
		//ASSERT(afxData.bWin4);
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);
		rect.InflateRect(-AFX_CX_BORDER, -AFX_CY_BORDER);
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);

		return;

	case splitIntersection:

		//ASSERT(afxData.bWin4);
		break;

	case splitBox:
		//if (afxData.bWin4)
	{
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);
		rect.InflateRect(-AFX_CX_BORDER, -AFX_CY_BORDER);
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);
		rect.InflateRect(-AFX_CX_BORDER, -AFX_CY_BORDER);
		break;
	}
	// fall through...
	case splitBar:

	{
		pDC->FillSolidRect(rect, rgbMiddle);
		pDC->FillSolidRect(rect, rgbMiddle);
		//if((rect.bottom - rect.top) > (rect.right - rect.left))
		//{
		//}
		//else
		//{
		//}
	}
	break;

	default:
		ASSERT(false);  // unknown splitter type
	}
}

BOOL CSplitterNodeWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = g_pTangram->m_lpszSplitterClass;
	cs.style |= WS_CLIPSIBLINGS;
	return CSplitterWnd::PreCreateWindow(cs);
}

void CSplitterNodeWnd::DrawAllSplitBars(CDC* pDC, int cxInside, int cyInside)
{
	//ColRect.clear();
	//RowRect.clear();
	ASSERT_VALID(this);

	int col;
	int row;
	CRect rect;

	// draw pane borders
	GetClientRect(rect);
	int x = rect.left;
	for (col = 0; col < m_nCols; col++)
	{
		int cx = m_pColInfo[col].nCurSize + 2 * m_cxBorder;
		if (col == m_nCols - 1 && m_bHasVScroll)
			cx += afxData.cxVScroll - CX_BORDER;
		int y = rect.top;
		for (row = 0; row < m_nRows; row++)
		{
			int cy = m_pRowInfo[row].nCurSize + 2 * m_cyBorder;
			if (row == m_nRows - 1 && m_bHasHScroll)
				cy += afxData.cyHScroll - CX_BORDER;
			OnDrawSplitter(pDC, splitBorder, CRect(x, y, x + cx, y + cy));
			y += cy + m_cySplitterGap - 2 * m_cyBorder;
		}
		x += cx + m_cxSplitterGap - 2 * m_cxBorder;
	}


	// draw column split bars
	GetClientRect(rect);
	rect.left += m_cxBorder;
	for (col = 0; col < m_nCols - 1; col++)
	{
		rect.left += m_pColInfo[col].nCurSize + m_cxBorderShare;
		rect.right = rect.left + m_cxSplitter;
		if (rect.left > cxInside)
			break;      // stop if not fully visible
		//ColumnsplitBar = rect;
		//ColRect.push_back(rect);
		OnDrawSplitter(pDC, splitBar, rect);

		rect.left = rect.right + m_cxBorderShare;
	}

	// draw row split bars
	GetClientRect(rect);
	rect.top += m_cyBorder;
	for (row = 0; row < m_nRows - 1; row++)
	{
		rect.top += m_pRowInfo[row].nCurSize + m_cyBorderShare;
		rect.bottom = rect.top + m_cySplitter;
		if (rect.top > cyInside)
			break;      // stop if not fully visible
		//RowsplitBar = rect;
		//RowRect.push_back(rect);
		OnDrawSplitter(pDC, splitBar, rect);

		rect.top = rect.bottom + m_cyBorderShare;
	}
}

CWnd* CSplitterNodeWnd::GetActivePane(int* pRow, int* pCol)
{
	CWnd* pView = nullptr;
	pView = GetFocus();

	// make sure the pane is a child pane of the splitter
	if (pView != nullptr && !IsChildPane(pView, pRow, pCol))
		pView = nullptr;


	return pView;
}

int CSplitterNodeWnd::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (g_pTangram->m_pActiveHtmlWnd)
	{
		g_pTangram->m_pActiveHtmlWnd = nullptr;
	}

	CCompositor* pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;

	if (m_pWndNode->m_pParentObj)
	{
		if (m_pWndNode->m_pParentObj->m_nViewType & TabbedWnd)
			m_pWndNode->m_pParentObj->m_pVisibleXMLObj = m_pWndNode;
	}
	if (g_pTangram->m_pDocDOMTree)
	{
		if (g_pTangram->m_hVSToolBoxWnd)
		{
			if (::IsChild(g_pTangram->m_hVSToolBoxWnd, m_hWnd) == false)
				g_pTangram->m_pCLRProxy->SelectNode(m_pWndNode);
		}
		else if (g_pTangram->m_pCLRProxy&&::IsChild(g_pTangram->m_hHostWnd, m_hWnd) == false)
			g_pTangram->m_pCLRProxy->SelectNode(m_pWndNode);
	}

	if (pCompositor->m_pCompositorManager->m_pTangramAppProxy)
	{
		HWND hMenuWnd = pCompositor->m_pCompositorManager->m_pTangramAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
	else if ((long)(g_pTangram->m_pActiveAppProxy) > 1)
	{
		HWND hMenuWnd = g_pTangram->m_pActiveAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}

	return MA_ACTIVATE;// CSplitterWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

void CSplitterNodeWnd::Save()
{
	CString strWidth = _T("");
	CString strHeight = _T("");

	int minCx, minCy;

	for (int i = 0; i < m_pWndNode->m_nRows; i++)
	{
		int iHeight;
		CString strH;
		GetRowInfo(i, iHeight, minCy);
		strH.Format(_T("%d,"), iHeight);

		strHeight += strH;
	}

	for (int j = 0; j < m_pWndNode->m_nCols; j++)
	{
		int iWidth;
		CString strW;
		GetColumnInfo(j, iWidth, minCx);
		strW.Format(_T("%d,"), iWidth);

		strWidth += strW;
	}

	m_pWndNode->put_Attribute(CComBSTR(TGM_HEIGHT), CComBSTR(strHeight));
	m_pWndNode->put_Attribute(CComBSTR(TGM_WIDTH), CComBSTR(strWidth));
}

void CSplitterNodeWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	if (point.x < m_Hmin && point.y < m_Vmin)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmin, m_Vmin));
	}

	else if (point.x < m_Hmin && point.y > m_Vmin && point.y < m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmin, point.y));
	}

	else if (point.x < m_Hmin && point.y > m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmin, m_Vmax));
	}

	else if (point.x > m_Hmax && point.y < m_Vmin)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmax, m_Vmin));
	}

	else if (point.x > m_Hmax && point.y > m_Vmin && point.y < m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmax, point.y));
	}

	else if (point.x > m_Hmax && point.y > m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmax, m_Vmax));
	}

	else if (point.x > m_Hmin && point.x < m_Hmax && point.y > m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(point.x, m_Vmax));
	}
	else if (point.x > m_Hmin && point.x < m_Hmax && point.y < m_Vmin)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(point.x, m_Vmin));
	}
	else
	{
		CSplitterWnd::OnMouseMove(nFlags, point);
	}

	//CDC *pDC = GetDC();
	//for (int col = 0; col < m_nCols - 1; col++)
	//{
	//	if(PtInRect( &ColRect.at(col),point) && bColMoving == 0)
	//	{
	//		pDC->FillSolidRect(&(ColRect.at(col)),rgbMiddle);
	//	}
	//}

	//for (int row = 0; row < m_nRows - 1; row++)
	//{
	//	if(PtInRect( &RowRect.at(row),point))
	//	{
	//		pDC->FillSolidRect(&(RowRect.at(row)), rgbMiddle);
	//	}
	//}
}

void CSplitterNodeWnd::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);
	if (m_pColInfo != nullptr)
		RecalcLayout();
}

void CSplitterNodeWnd::OnDestroy()
{
	m_pWndNode->Fire_Destroy();
	__super::OnDestroy();
}

