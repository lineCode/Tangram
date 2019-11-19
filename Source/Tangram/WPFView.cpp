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
* OUTLINED IN THE TANGRAM LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
********************************************************************************/
// WPFView.cpp : implementation file
//

#include "stdafx.h"
#include "TangramApp.h"
#include "WPFView.h"
#include "WndNode.h"
#include "Compositor.h"
#include "SplitterWnd.h"


// CWPFView

IMPLEMENT_DYNCREATE(CWPFView, CView)

CWPFView::CWPFView()
{
	m_RespondMouseActive = false;
	m_pWndNode = nullptr;
	m_pTangramWPFObj = nullptr;
}

CWPFView::~CWPFView()
{
	if (m_pWndNode)
		delete m_pWndNode;
}

BEGIN_MESSAGE_MAP(CWPFView, CView)
	ON_WM_MOUSEACTIVATE()
	ON_WM_DESTROY()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CWPFView drawing

void CWPFView::OnDraw(CDC* pDC)
{
}

// CWPFView diagnostics

#ifdef _DEBUG
void CWPFView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CWPFView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CWPFView message handlers

BOOL CWPFView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_pWndNode = g_pTangram->m_pActiveNode;
	m_pWndNode->m_pHostWnd = this;
	m_pWndNode->m_nViewType = TangramWPFCtrl;
	m_pWndNode->m_nID = nID;

	g_pTangram->LoadCLR();
	m_pTangramWPFObj = g_pTangram->m_pCLRProxy->CreateWPFControl(m_pWndNode, pParentWnd->m_hWnd, nID);
	if (m_pTangramWPFObj&&::IsWindow(m_pTangramWPFObj->m_hwndWPF))
	{
		BOOL bSubclass =  SubclassWindow(m_pTangramWPFObj->m_hwndWPF);
		if (bSubclass)
		{
			m_pWndNode->m_pDisp = m_pTangramWPFObj->m_pDisp;
			m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->m_mapWPFView[m_hWnd] = this;
			UINT nIndex = ::GetWindowLongPtr(::GetParent(m_hWnd), GWLP_USERDATA);
			if (nIndex == 1992)
				m_RespondMouseActive = true;
		}
		return bSubclass;
	}
	return false;
}

int CWPFView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (g_pTangram->m_pTangramAppProxy)
	{
		HWND hMenuWnd = g_pTangram->m_pTangramAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
	g_pTangram->m_pActiveNode = m_pWndNode;
	::SetFocus(m_hWnd);
	g_pTangram->m_bWinFormActived = false;

	g_pTangram->m_pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
	g_pTangram->m_pCompositor->HostPosChanged();
	g_pTangram->m_pCompositor->UpdateVisualWPFMap(::GetParent(m_hWnd),false);

	long nIndex = (long)::GetWindowLongPtr(m_hWnd, GWLP_USERDATA);
	if (m_RespondMouseActive||nIndex == 1963||m_pTangramWPFObj->IsVisible()==false)
	{
		::SetWindowLongPtr(m_hWnd, GWLP_USERDATA, 0);
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		CWnd* pParent = this->GetParent();
		pParent->ScreenToClient(&rc);
		::SetWindowPos(m_hWnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top + 1, SWP_DRAWFRAME);
		::SetWindowPos(m_hWnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, SWP_DRAWFRAME);
	}

	return MA_ACTIVATE;
}

void CWPFView::OnDestroy()
{
	CCompositor* pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
	auto it = pCompositor->m_mapWPFView.find(m_hWnd);
	if (it != pCompositor->m_mapWPFView.end())
		pCompositor->m_mapWPFView.erase(it);
	it = pCompositor->m_mapVisibleWPFView.find(m_hWnd);
	if (it != pCompositor->m_mapVisibleWPFView.end())
		pCompositor->m_mapVisibleWPFView.erase(it);

	g_pTangram->m_pCLRProxy->WindowDestroy(m_hWnd);
	CView::OnDestroy();
}

BOOL CWPFView::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_TAB)
		{
			//CView::PreTranslateMessage(pMsg);
			return true;
		}
	}

	return CView::PreTranslateMessage(pMsg);
}

void CWPFView::OnMouseMove(UINT nFlags, CPoint point)
{
	long nIndex = (long)::GetWindowLongPtr(m_hWnd, GWLP_USERDATA);
	if (nIndex == 1963)
	{
		g_pTangram->m_pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
		g_pTangram->m_pCompositor->HostPosChanged();
		g_pTangram->m_pCompositor->UpdateVisualWPFMap(::GetParent(m_hWnd), false);
		::SetWindowLongPtr(m_hWnd, GWLP_USERDATA, 0);

		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		CWnd* pParent = this->GetParent();
		pParent->ScreenToClient(&rc);
		::SetWindowPos(m_hWnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top + 1, SWP_DRAWFRAME);
		::SetWindowPos(m_hWnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, SWP_DRAWFRAME);
	}

	CView::OnMouseMove(nFlags, point);
}


BOOL CWPFView::OnEraseBkgnd(CDC* pDC)
{
	long nIndex = (long)::GetWindowLongPtr(m_hWnd, GWLP_USERDATA);
	if (nIndex!=1963)
	{
		CCompositor* pCompositor = m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
		pCompositor->UpdateVisualWPFMap(::GetParent(pCompositor->m_hWnd), false);
	}
	//pCompositor->HostPosChanged();

	return true;
	//return CView::OnEraseBkgnd(pDC);
}
