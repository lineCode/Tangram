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
// TangramTabCtrlWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "TangramTabCtrlWnd.h"

// CTangramTabCtrlWnd

IMPLEMENT_DYNAMIC(CTangramTabCtrlWnd, CMFCTabCtrl)

CTangramTabCtrlWnd::CTangramTabCtrlWnd()
{
	m_nCurSelTab = -1;
}

CTangramTabCtrlWnd::~CTangramTabCtrlWnd()
{
	ATLTRACE(_T("delete CTangramTabCtrlWnd:%x\n"), this);
}

void CTangramTabCtrlWnd::Save()
{
	CString str = _T("");
	str.Format(_T("%d"), GetActiveTab());
	m_pWndNode->put_Attribute(L"activepage", CComBSTR(str));
}

BEGIN_MESSAGE_MAP(CTangramTabCtrlWnd, CMFCTabCtrl)
	ON_MESSAGE(WM_CREATETABPAGE, OnCreatePage)
	ON_MESSAGE(WM_TABCHANGE, OnActivePage)
	ON_MESSAGE(WM_MODIFYTABPAGE, OnModifyPage)
	ON_MESSAGE(WM_TGM_SETACTIVEPAGE, OnActiveTangramObj)
	ON_MESSAGE(WM_TGM_SET_CAPTION, OnTgmSetCaption)
END_MESSAGE_MAP()


BOOL CTangramTabCtrlWnd::SetActiveTab(int iTab)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int nOldIndex = m_nCurSelTab;
	m_nCurSelTab = iTab;
	BOOL bRet = CMFCTabCtrl::SetActiveTab(iTab);
	CWnd* pWnd = GetActiveWnd();
	if (pWnd)
	{
		CRect rc;
		pWnd->GetWindowRect(rc);
		CWnd* pPWnd = pWnd->GetParent();
		pPWnd->ScreenToClient(rc);
		::SetWindowPos(pWnd->m_hWnd, NULL, rc.left, rc.top, rc.Width(), rc.Height(), SWP_FRAMECHANGED | SWP_SHOWWINDOW | SWP_NOACTIVATE);
		Invalidate();
		::SendMessage(m_hWnd, WM_TABCHANGE, m_nCurSelTab, nOldIndex);
	}
	return bRet;
}

// CTangramTabCtrlWnd Message Handler


LRESULT CTangramTabCtrlWnd::OnActiveTangramObj(WPARAM wParam, LPARAM lParam)
{
	if (lParam == 1965)
	{
		::PostMessage(m_hWnd, WM_TGM_SETACTIVEPAGE, wParam, 0);
	}
	else
		SetActiveTab((int)wParam);
	return 0;
}

LRESULT CTangramTabCtrlWnd::OnTgmSetCaption(WPARAM wParam, LPARAM lParam)
{
	int iIndex = (int)wParam;
	int iCount = GetTabsNum();
	CString strCaption = (LPCTSTR)lParam;
	this->SetTabLabel(iIndex, strCaption);
	return 0;
}

LRESULT CTangramTabCtrlWnd::OnCreatePage(WPARAM wParam, LPARAM lParam)
{
	HWND hPageWnd = (HWND)wParam;
	//CWnd* pWnd = FromHandlePermanent(hPageWnd);
	//if (pWnd == NULL)
	//{
	//	pWnd = new CTabPageWnd();
	//	pWnd->SubclassWindow(hPageWnd);
	//}
	AddTab(FromHandle(hPageWnd), (LPCTSTR)lParam, (UINT)GetTabsNum()-1);

	InvalidateRect(NULL);
	return 0;
}

LRESULT CTangramTabCtrlWnd::OnActivePage(WPARAM wParam, LPARAM lParam)
{
	int nOldIndex = m_nCurSelTab;
	int iIndex = (int)wParam;
	IWndNode* pActiveNode = NULL;
	if (m_pWndNode)
	{
		//this->SetActiveTab(iIndex);
		CComPtr<IWndNodeCollection> pCol;
		m_pWndNode->get_ChildNodes(&pCol);
		CComPtr<IWndNode> pNode;
		pCol->get_Item(iIndex, &pNode);
		if (pNode)
		{
			m_nCurSelTab = iIndex;
			CString str = _T("");
			str.Format(_T("%d"), iIndex);
			m_pWndNode->put_Attribute(CComBSTR(L"activepage"), str.AllocSysString());
			pNode->ActiveTabPage(pNode);
		}
	}
	return 0;//CWnd::DefWindowProc(WM_TABCHANGE,wParam,lParam);;
}

LRESULT CTangramTabCtrlWnd::OnModifyPage(WPARAM wParam, LPARAM lParam)
{
	////AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//HWND hPageWnd = (HWND)wParam;
	//int nViewID = (int)lParam;
	//CWnd* pOldWnd = CWnd::FromHandlePermanent(hPageWnd);
	//if (pOldWnd || true)
	//{
	//	///////////////////////Begin Dont Delete!////////////////////
	//	CXTPTabManagerItem* pItem = GetItem(nViewID);
	//	CString strCap = pItem->GetCaption();
	//	pItem->Remove();
	//	pItem = InsertItem(nViewID, (LPCTSTR)strCap, hPageWnd, 0);
	//	///////////////////////End Dont Delete!//////////////////////
	//}
	//else
	//{

	//	CWnd* pWnd = CWnd::FromHandle(GetItem(nViewID)->GetHandle());
	//	//CWnd* pWnd = GetPage(nViewID);
	//	pWnd->UnsubclassWindow();
	//	pWnd->SubclassWindow(hPageWnd);
	//	GetItem(nViewID)->SetHandle(hPageWnd);
	//}
	//SendMessage(WM_TGM_SETACTIVEPAGE);
	return 0;
}

void CTangramTabCtrlWnd::PostNcDestroy()
{
	CMFCTabCtrl::PostNcDestroy();
	delete this;
}
