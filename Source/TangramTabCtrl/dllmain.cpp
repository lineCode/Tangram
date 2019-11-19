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
// dllmain.cpp : DllMain 

#include "stdafx.h"
#include "dllmain.h"
#include "TangramTabCtrlWnd.h"

CTangramApp theApp;

CTangramApp::CTangramApp()
{
}

CTangramApp::~CTangramApp()
{
	ATLTRACE(_T("Release CTangramTabCtrlApp:%x\n"), this);
}

BOOL CTangramApp::InitInstance()
{
	m_strTangramContainer = _T("tangramtabctrl");
	TangramInit(_T("connector.1"));
	return __super::InitInstance();
}

HWND CTangramApp::Create(HWND hParent, IWndNode* pNode)
{
	BSTR bstrTag = L"";
	BSTR bstrStyle = L"";

	USES_CONVERSION;

	pNode->get_Attribute(L"activepage", &bstrTag);
	CString m_strTag = OLE2T(bstrTag);
	int nActivePage = _wtoi(m_strTag);
	pNode->get_Attribute(L"id", &bstrTag);
	pNode->get_Attribute(L"style", &bstrStyle);
	CString strStyle = OLE2T(bstrStyle);
	strStyle.Trim();
	if (strStyle == _T(""))
	{
		pNode->get_Attribute(L"tabstyle", &bstrStyle);
		strStyle = OLE2T(bstrStyle);
		strStyle.Trim();
	}

	m_strTag = OLE2T(bstrTag);
	::SysFreeString(bstrTag);

	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_strTag.Trim();
	if (::IsWindow(hParent))
	{
		if (m_strTag.CompareNoCase(_T("tangramtabctrl")) == 0)
		{
			BSTR bstrLocation = L"";
			pNode->get_Attribute(L"Location", &bstrLocation);
			CMFCTabCtrl::Location loc = (CMFCTabCtrl::Location)_ttoi(strStyle);
			CTangramTabCtrlWnd* pTangramTabCtrlWnd = new CTangramTabCtrlWnd();
			pTangramTabCtrlWnd->m_pWndNode = pNode;
			if (pTangramTabCtrlWnd)
			{
				CRect rectDummy;
				rectDummy.SetRectEmpty();
				CMFCTabCtrl::Style nStyle = (CMFCTabCtrl::Style)_ttoi(OLE2T(bstrStyle));
				pTangramTabCtrlWnd->EnableAutoColor();
				pTangramTabCtrlWnd->EnableTabSwap(false);
				pTangramTabCtrlWnd->SetLocation(loc);
				if (!pTangramTabCtrlWnd->Create(nStyle, rectDummy, CWnd::FromHandle(hParent), 1))
				{
					return NULL;
				}
				::PostMessage(pTangramTabCtrlWnd->m_hWnd, WM_TGM_SETACTIVEPAGE, nActivePage, 1965);
			}

			return pTangramTabCtrlWnd->m_hWnd;
		}

		return NULL;
	}
	return NULL;
}


CString CTangramApp::GetNames()
{
	return _T("tangramtabctrl");
}

CString CTangramApp::GetTags(CString strName)
{
	return _T("0,1,2,3,4,5,6,7,");
}
