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
#include "AccessAddin.h"
//#include "AccessEvents.cpp"

namespace OfficePlus
{
	namespace AccessPlus
	{
		CAccessAddin::CAccessAddin()
		{
		}

		CAccessAddin::~CAccessAddin()
		{
		}

		STDMETHODIMP CAccessAddin::TangramCommand(IDispatch* RibbonControl)
		{
			if (m_spRibbonUI)
				m_spRibbonUI->Invalidate();
			return S_OK;
		}

		HRESULT CAccessAddin::OnConnection(IDispatch* pHostApp, int ConnectMode)
		{
			COfficeAddin::OnConnection(pHostApp, ConnectMode);
			pHostApp->QueryInterface(__uuidof(IDispatch), (LPVOID*)&m_pApplication);
			int nHandle = 0;
			m_pApplication->hWndAccessApp(&nHandle);
			HWND h = (HWND)nHandle;
			m_bEnableProcessFormTabKey = true;
			return S_OK;
		}

		HRESULT CAccessAddin::OnDisconnection(int DisConnectMode)
		{
			m_pApplication.Detach();
			return S_OK;
		}

		STDMETHODIMP CAccessAddin::GetCustomUI(BSTR RibbonID, BSTR* RibbonXml)
		{
			if (!RibbonXml)
				return E_POINTER;
			*RibbonXml = m_strRibbonXml.AllocSysString();
			return (*RibbonXml ? S_OK : E_OUTOFMEMORY);
		}

		STDMETHODIMP CAccessAddin::GetObjectFromWnd(LONG hWnd, IDispatch** ppObjFromWnd)
		{
			HWND h = (HWND)hWnd;
			auto it = m_mapOfficeObjects.find(h);
			if (it != m_mapOfficeObjects.end())
			{
				*ppObjFromWnd = it->second;
			}
			return S_OK;
		}

		void CAccessAddin::WindowDestroy(HWND hWnd)
		{
			::GetClassName(hWnd, m_szBuffer, MAX_PATH);
			CString strClassName = CString(m_szBuffer);
			if (strClassName == _T("OForm") || strClassName == _T("OFormPopup"))
			{
				OnCloseOfficeObj(strClassName, hWnd);
			}
		}

		void CAccessAddin::WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd)
		{
			if (strClassName == _T("OForm")|| strClassName == _T("OFormPopup"))
			{
				CAccessForm* pWnd = new CComObject<CAccessForm>;
				pWnd->m_hForm = hWnd;
				m_mapOfficeObjects[hWnd] = pWnd;
				::PostMessage(m_hHostWnd, WM_OFFICEOBJECTCREATED, (WPARAM)hWnd, 0);
				return;
			}
		}

		void CAccessAddin::ConnectOfficeObj(HWND hWnd)
		{
			CComPtr<MSAccess::Forms> m_pForms;
			if (m_pApplication)
			{
				m_pApplication->get_Forms(&m_pForms);
				if (m_pForms)
				{
					long nCount = 0;
					m_pForms->get_Count(&nCount);
					if (nCount)
					{
						for (int i = 0; i < nCount;i++)
						{
							CComPtr<MSAccess::_Form3> pForm;
							m_pForms->get_Item(CComVariant(i), &pForm);
							if (pForm)
							{
								long h = 0;
								pForm->get_Hwnd(&h);
								if (h == (LONGLONG)hWnd)
								{
									auto it = m_mapOfficeObjects.find(hWnd);
									if (it != m_mapOfficeObjects.end())
									{
										it->second->m_pOfficeObj = pForm.p;
										it->second->m_pOfficeObj->AddRef();
										CAccessForm* pAccessForm = (CAccessForm*)it->second;
										HRESULT hr = pAccessForm->DispEventAdvise(it->second->m_pOfficeObj);
									}
									break;
								}
							}
						}
					}
				}
			}
		}

		CAccessForm::CAccessForm(void)
		{

		}

		CAccessForm::~CAccessForm(void) 
		{
		}

		void CAccessForm::OnObjDestory()
		{
			if (m_pOfficeObj != nullptr)
			{
				HRESULT hr = this->DispEventUnadvise(m_pOfficeObj);
			}
		}

		//void CAccessForm::Load()
		//{
		//}

		//void CAccessForm::Current() 
		//{
		//}

		//void CAccessForm::BeforeInsert(short* Cancel) 
		//{
		//}

		//void CAccessForm::AfterInsert()
		//{
		//}

		//void CAccessForm::BeforeUpdate(short* Cancel)
		//{
		//}

		//void CAccessForm::AfterUpdate()
		//{
		//}

		//void CAccessForm::Delete(short* Cancel)
		//{
		//}

		//void CAccessForm::BeforeDelConfirm(short* Cancel, short* Response)
		//{
		//}

		//void CAccessForm::AfterDelConfirm(short* Status) 
		//{
		//}

		//void CAccessForm::Open(short* Cancel)
		//{
		//}
		//
		//void CAccessForm::Resize() 
		//{
		//}
		//
		//void CAccessForm::Unload(short* Cancel)
		//{
		//}
		//
		//void CAccessForm::Close()
		//{
		//}
		//
		//void CAccessForm::Activate()
		//{
		//}
		//
		//void CAccessForm::Deactivate()
		//{
		//}
		//
		//void CAccessForm::GotFocus() {
		//}

		//void CAccessForm::LostFocus() 
		//{
		//}
	}
}

