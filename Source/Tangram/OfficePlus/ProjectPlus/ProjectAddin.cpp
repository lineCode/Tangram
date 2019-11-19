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

#include "../../stdafx.h"
#include "../../TangramApp.h"
#include "ProjectAddin.h"
#include "ProjectPlusEvents.cpp"

namespace OfficePlus
{
	namespace ProjectPlus
	{
		CProjectAddin::CProjectAddin():COfficeAddin()
		{
		}

		CProjectAddin::~CProjectAddin()
		{
		}

		STDMETHODIMP CProjectAddin::TangramCommand(IDispatch* RibbonControl)
		{
			if (m_spRibbonUI)
				m_spRibbonUI->Invalidate();
			return S_OK;
		}

		HRESULT CProjectAddin::OnConnection(IDispatch* pHostApp, int ConnectMode)
		{
			COfficeAddin::OnConnection(pHostApp, ConnectMode);
			if (m_strRibbonXml == _T(""))
			{
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadXml(m_strConfigFile) || m_Parse.LoadFile(m_strConfigFile))
				{
					m_strRibbonXml = m_Parse[_T("RibbonUI")][_T("customUI")].xml();
				}
			}

			pHostApp->QueryInterface(__uuidof(IDispatch), (LPVOID*)&m_pApplication);
			return S_OK;
		}

		HRESULT CProjectAddin::OnDisconnection(int DisConnectMode)
		{
			m_pApplication.p->Release();
			m_pApplication.Detach();
			return S_OK;
		}

		STDMETHODIMP CProjectAddin::GetCustomUI(BSTR RibbonID, BSTR* RibbonXml)
		{
			if (!RibbonXml)
				return E_POINTER;
			*RibbonXml = m_strRibbonXml.AllocSysString();
			return (*RibbonXml ? S_OK : E_OUTOFMEMORY);
		}

		HRESULT CProjectAddin::CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv)
		{
			return CProjectAppCtrl::_CreatorClass::CreateInstance(pv, riid, ppv);
		}

		void CProjectAddin::WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd)
		{
		}

		CProjectAppCtrl::CProjectAppCtrl()
		{

		}

		void CProjectAppCtrl::OnFinalMessage(HWND hWnd)
		{
			__super::OnFinalMessage(hWnd);
		}

		STDMETHODIMP CProjectAppCtrl::put_AppCtrl(VARIANT_BOOL newVal)
		{
			g_pTangram->m_pTangramAppCtrl = this;

			return S_OK;
		}

		STDMETHODIMP CProjectAppCtrl::get_tag(VARIANT* pVal)
		{
			return S_OK;
		}


		STDMETHODIMP CProjectAppCtrl::put_tag(VARIANT newVal)
		{
			return S_OK;
		}

		STDMETHODIMP CProjectAppCtrl::get_HWND(LONGLONG* pVal)
		{
			*pVal = (long)m_hWnd;
			return S_OK;
		}

		STDMETHODIMP CProjectAppCtrl::get_Tangram(ITangram** pVal)
		{
			*pVal = g_pTangram;
			return S_OK;
		}
	}
}// namespace OfficePlus

