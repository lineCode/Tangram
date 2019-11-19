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

// TangramCtrl.cpp : Implementation of CTangramCtrl
#include "stdafx.h"
#include "TangramApp.h"
#include "WndNode.h"
#include "Compositor.h"
#include "TangramCtrl.h"
#include "OfficePlus\OfficeAddin.h"

HRESULT WINAPI CTangramCtrl::CreateInstance(void* pv, REFIID riid, LPVOID* ppv)
{
	if (g_pTangram->m_strCurrentAppID == _T(""))
	{
		if(g_pTangram->m_pTangramDelegate->m_pJVM)
		{
			return CEclipseCtrl::_CreatorClass::CreateInstance(pv, riid, ppv);
		}
		if (g_pTangram->m_nAppID != -1)
		{
			OfficePlus::COfficeAddin* pAddin = (OfficePlus::COfficeAddin*)g_pTangram;
			HRESULT hr = pAddin->CreateTangramCtrl(pv, riid, ppv);
			if (hr == S_OK)
				return hr;
		}
		if (g_pTangram->m_pTangramAppProxy)
		{
			HRESULT hr = g_pTangram->m_pTangramAppProxy->CreateTangramCtrl(pv, riid, ppv);
			if (hr == S_OK)
				return hr;
		}
		return CTangramCtrl::_CreatorClass::CreateInstance(pv, riid, ppv);
	}
	else
	{
		ITangramCtrl* pCtrl = nullptr;
		HRESULT hr = g_pTangram->CreateTangramCtrl(g_pTangram->m_strCurrentAppID.AllocSysString(), &pCtrl);
		if (hr == S_OK)
		{
			*ppv = pCtrl;
			return hr;
		}
		g_pTangram->m_strCurrentAppID = _T("");
		return S_FALSE;
	}
};

// CTangramCtrl
CTangramCtrlBase::CTangramCtrlBase()
{
	m_bWindowOnly = true;
	m_hWnd = NULL;
#ifdef _DEBUG
	g_pTangram->m_nTangramCtrl++;
#endif
}

CTangramCtrlBase::~CTangramCtrlBase()
{
#ifdef _DEBUG
	g_pTangram->m_nTangramCtrl--;
#endif
}

void CTangramCtrlBase::OnFinalMessage(HWND hWnd)
{
	if (g_pTangram->m_pCLRProxy)
	{
		g_pTangram->m_pCLRProxy->ReleaseTangramObj((ITangramCtrl*)this);
	}
	__super::OnFinalMessage(hWnd);
}

STDMETHODIMP CTangramCtrl::get_HWND(LONGLONG* pVal)
{
	*pVal = (LONGLONG)m_hWnd;
	return S_OK;
}

STDMETHODIMP CTangramCtrl::get_Tangram(ITangram** pVal)
{
	*pVal = g_pTangram;
	return S_OK;
}

CTangramAppCtrl::CTangramAppCtrl()
{
}

CTangramAppCtrl::~CTangramAppCtrl()
{
	if (g_pTangram->m_pTangramAppCtrl == (CTangramAppCtrl*)this)
		g_pTangram->m_pTangramAppCtrl = nullptr;
}

HRESULT CTangramAppCtrl::Fire_TangramEvent(ITangramEventObj* pEventObj)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[1];
		avarParams[0] = pEventObj;
		avarParams[0].vt = VT_DISPATCH;
		DISPPARAMS params = { avarParams, NULL, 1, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}
	return hr;
}

STDMETHODIMP CTangramCtrl::get_tag(VARIANT* pVal)
{
	return S_OK;
}


STDMETHODIMP CTangramCtrl::put_tag(VARIANT newVal)
{
	return S_OK;
}
