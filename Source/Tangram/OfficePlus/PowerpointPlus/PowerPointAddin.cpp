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
#include "../../WndNode.h"
#include "../../Compositor.h"
#include "../../CompositorManager.h"
#include "../../TangramHtmlTreeWnd.h"
#include "fm20.h"
#include "PowerPointAddin.h"
#include "PowerpointPlusEvents.cpp"

using namespace OfficePlus::PowerPointPlus;

namespace OfficePlus
{
	namespace PowerPointPlus
	{
		CPowerPntObject::CPowerPntObject(void)
		{
			m_hTaskPane = NULL;
			m_hTaskPaneWnd = NULL;
			m_hTaskPaneChildWnd = NULL;
			m_pPresentation = nullptr;
		}

		CPowerPntObject::~CPowerPntObject(void)
		{
		}

		void CPowerPntObject::OnObjDestory()
		{
			CPowerPntAddin* pAddin = ((CPowerPntAddin*)g_pTangram);

			if (pAddin->m_pActivePowerPntObject == this)
			{
				pAddin->m_pActivePowerPntObject = nullptr;
				pAddin->m_pActiveNode = nullptr;
			}
			if (m_pPresentation)
			{
				CString strKey = m_pPresentation->m_strKey;
				auto it2 = m_pPresentation->find(m_hChildClient);
				if (it2 != m_pPresentation->end())
				{
					m_pPresentation->erase(it2);
				}
				size_t nCount = m_pPresentation->size();
				if (nCount > 0 && m_pPresentation->m_pCompositor)
				{
					auto it2 = m_pPresentation->begin();
					m_pPresentation->m_pCompositor->ModifyHost((LONGLONG)it2->second->m_hClient);
					if (m_hTaskPane)
					{
						m_hTaskPane = NULL;
						m_pPresentation->m_pTaskPaneCompositor->ModifyHost((LONGLONG)it2->second->m_hTaskPaneChildWnd);
						::DestroyWindow(m_hTaskPaneWnd);
					}
				}
				if (nCount == 0)
				{
					CCloudAddinPresentation* pTangramPresentation = NULL;
					auto it = ((CPowerPntAddin*)g_pTangram)->m_mapTangramPres.find(strKey);
					if (it != ((CPowerPntAddin*)g_pTangram)->m_mapTangramPres.end())
						((CPowerPntAddin*)g_pTangram)->m_mapTangramPres.erase(it);
					delete m_pPresentation;
				}
			}

			auto it = pAddin->m_mapTaskPaneMap.find((long)m_hForm);
			if (it != pAddin->m_mapTaskPaneMap.end())
			{
				it->second->Delete();
				pAddin->m_mapTaskPaneMap.erase(it);
			}
			auto it3 = pAddin->m_mapOfficeObjects2.find(m_hForm);
			if (it3 != pAddin->m_mapOfficeObjects2.end())
				pAddin->m_mapOfficeObjects2.erase(it3);
		}

		CCloudAddinPresentation::CCloudAddinPresentation()
		{
			m_bDesignState = false;
			m_strKey = _T("");
			m_strTaskPaneXml = _T("");
			m_pDocCompositorManager = nullptr;
			m_pCompositor = nullptr;
			m_pTaskPaneCompositorManager = nullptr;
			m_pTaskPaneCompositor = nullptr;
		}

		CCloudAddinPresentation::~CCloudAddinPresentation()
		{

		}

		CPowerPntAddin::CPowerPntAddin()
		{
			m_pActivePowerPntObject = nullptr;
			m_pCurrentSavingPresentation = nullptr;
			m_strDesignerToolBarCaption = _T("PowerPoint Designer");
		}

		void CPowerPntAddin::AddDocXml(IDispatch* pDocdisp, BSTR bstrXml, BSTR bstrKey)
		{
			CComQIPtr<PowerPoint::_Presentation> pDoc(pDocdisp);
			if (pDoc)
			{
				CComPtr<Office::_CustomXMLParts> pCustomXMLParts;
				pDoc->get_CustomXMLParts(&pCustomXMLParts);
				_AddDocXml(pCustomXMLParts.p, bstrXml, bstrKey);
			}
		}

		CString CPowerPntAddin::GetDocXmlByKey(IDispatch* pDocdisp, BSTR bstrKey)
		{
			CComQIPtr<PowerPoint::_Presentation> pDoc(pDocdisp);
			if (pDoc)
			{
				CComPtr<Office::_CustomXMLParts> pCustomXMLParts;
				pDoc->get_CustomXMLParts(&pCustomXMLParts);
				CString strRet = _GetDocXmlByKey(pCustomXMLParts.p, bstrKey);
				return strRet;
			}
			return _T("");
		}

		void CPowerPntAddin::OnPresentationBeforeSave(/*[in]*/ _Presentation * Pres,	/*[in,out]*/ VARIANT_BOOL * Cancel) 
		{
			CComBSTR bstrName(L"");
			Pres->get_FullName(&bstrName);
			CString strKey = OLE2T(bstrName);
			m_pCurrentSavingPresentation = nullptr;
			auto it = m_mapTangramPres.find(strKey);
			if (it != m_mapTangramPres.end())
				m_pCurrentSavingPresentation = it->second;
			CString strXml = _T("");
			CTangramXmlParse* pParse = nullptr;
			CTangramXmlParse* pParse2 = nullptr;
			if (m_pCurrentSavingPresentation)
			{
				CComPtr<Office::_CustomXMLParts> pCustomXMLParts;
				Pres->get_CustomXMLParts(&pCustomXMLParts);
				CString strGUID = GetNewGUID();
				CCompositor* pCompositor = m_pCurrentSavingPresentation->m_pCompositor;
				if (pCompositor)
				{
					pParse = pCompositor->UpdateWndNode();
					strXml = _GetDocXmlByKey(pCustomXMLParts.p, CComBSTR(L"tangram"));
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						pParse2 = m_Parse.GetChild(pParse->name());
						if (pParse2)
						{
							CTangramXmlParse* pParse3 = pParse2->GetChild(_T("window"));
							pParse2->RemoveNode(pParse3);
							pParse2->put_text(strGUID);
							strXml = m_Parse.xml();
							strXml.Replace(strGUID, pParse->GetChild(_T("window"))->xml());
							AddDocXml(Pres, CComBSTR(strXml), CComBSTR(L"tangram"));
						}
					}
				}
				pCompositor = m_pCurrentSavingPresentation->m_pTaskPaneCompositor;
				if (pCompositor)
				{
					pParse = pCompositor->UpdateWndNode();
					strXml = _GetDocXmlByKey(pCustomXMLParts.p, CComBSTR(L"tangram"));
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						pParse2 = m_Parse.GetChild(pParse->name());
						if (pParse2)
						{
							CTangramXmlParse* pParse3 = pParse2->GetChild(_T("window"));
							pParse2->RemoveNode(pParse3);
							pParse2->put_text(strGUID);
							strXml = m_Parse.xml();
							strXml.Replace(strGUID, pParse->GetChild(_T("window"))->xml());
							AddDocXml(Pres, CComBSTR(strXml), CComBSTR(L"tangram"));
						}
					}
				}
			}
		}

		void CPowerPntAddin::OnPresentationSave(/*[in]*/ _Presentation * Pres)
		{
			CComBSTR bstrName(L"");
			Pres->get_FullName(&bstrName);
			CString strNewKey = OLE2T(bstrName);
			if (m_pCurrentSavingPresentation&&m_pCurrentSavingPresentation->m_strKey != strNewKey)
			{
				auto it = m_mapTangramPres.find(strNewKey);
				if (it != m_mapTangramPres.end())
				{
					m_mapTangramPres.erase(it);
					m_mapTangramPres[strNewKey] = m_pCurrentSavingPresentation;
					m_pCurrentSavingPresentation->m_strKey = strNewKey;
					m_pCurrentSavingPresentation = nullptr;
				}
			}
		}

		STDMETHODIMP CPowerPntAddin::StartApplication(BSTR bstrAppID, BSTR bstrXml)
		{
			CString strID = OLE2T(bstrAppID);
			strID.MakeLower();
			if (strID.Find(_T("powerpoint.application")) == 0)
				return put_AppKeyValue(CComBSTR(L"doctemplate"), CComVariant(bstrXml));
			return CTangram::StartApplication(bstrAppID, bstrXml);
		}

		STDMETHODIMP CPowerPntAddin::put_AppKeyValue(BSTR bstrKey, VARIANT newVal)
		{
			CString strKey = OLE2T(bstrKey);

			if (strKey == _T(""))
				return S_OK;
			strKey.Trim();
			strKey.MakeLower();
			if (strKey == _T("doctemplate"))
			{
				auto it = m_mapValInfo.find(_T("doctemplate"));
				if (it != m_mapValInfo.end())
				{
					::VariantClear(&it->second);
					m_mapValInfo.erase(it);
				}
				m_mapValInfo[strKey] = newVal;
				CComPtr<_Presentation> pDoc;
				CComVariant varTemplate(L"");
				CComPtr<PowerPoint::Presentations> pPresentations;
				m_pApplication->get_Presentations(&pPresentations);
				pPresentations->Add(Office::MsoTriState::msoTrue, &pDoc);
			}
			return CTangram::put_AppKeyValue(bstrKey, newVal);
		}

		STDMETHODIMP CPowerPntAddin::TangramCommand(IDispatch* RibbonControl)
		{
			if (m_spRibbonUI)
				m_spRibbonUI->Invalidate();
			CComBSTR bstrTag(L"");
			CComBSTR bstrID(L"");
			CComQIPtr<IRibbonControl> pIRibbonControl(RibbonControl);
			if (pIRibbonControl)
			{
				pIRibbonControl->get_Id(&bstrID);
				pIRibbonControl->get_Tag(&bstrTag);
				CString strTag = OLE2T(bstrTag);
				if (strTag.CompareNoCase(_T("opentangramfile")) == 0)
				{
					CComPtr<ITangramDoc> pDoc;
					return this->OpenTangramFile(&pDoc);
				}
				int nPos = strTag.Find(_T("@"));
				CString strPath = m_strAppCommonDocPath + strTag;
				if (::PathFileExists(strPath))
				{
					CComPtr<ITangramDoc> pDoc;
					return this->OpenTangramDocFile(strPath.AllocSysString(), &pDoc);
				}
			}
			CString strTag = OLE2T(bstrTag);
			int nPos = strTag.Find(_T("TangramButton.Cmd"));
			strTag.Replace(_T("TangramButton.Cmd."), _T(""));
			int nCmdIndex = _wtoi(strTag);
			CComPtr<DocumentWindow> pWindow;
			m_pApplication->get_ActiveWindow(&pWindow);
			CPowerPntObject* pPntObject = nullptr;
			LONG hMainWnd = 0;
			pWindow->get_HWND(&hMainWnd);
			HWND hWnd = (HWND)hMainWnd;
			auto it = m_mapOfficeObjects.find(hWnd);
			if (it != m_mapOfficeObjects.end())
			{
				pPntObject = (CPowerPntObject*)it->second;
			}
			else
				return S_FALSE;
			CCloudAddinPresentation* pTangramPresentation = pPntObject->m_pPresentation;
			switch (nCmdIndex)
			{
			case 100:
			{
				CCompositor* pCompositor = pTangramPresentation->m_pCompositor;
				if (pCompositor == nullptr)
					break;
				if (pTangramPresentation->m_bDesignState == false)
				{
					pCompositor->m_bDesignerState = true;
					pTangramPresentation->m_bDesignState = true;
					CreateCommonDesignerToolBar();
					CWndNode* pNode = pCompositor->m_pWorkNode;
					if (pNode->m_strID.CompareNoCase(_T("hostView")) == 0)
					{
						CString strXml = _T("<documentui><window><node name=\"Start\" /></window></documentui>");
						IWndNode* pDesignNode = nullptr;
						pCompositor->Open(CComBSTR(L"default-inDesigning"), CComBSTR(strXml), &pDesignNode);
					}

					m_pDesigningFrame = pCompositor;
					m_pDesigningFrame->UpdateDesignerTreeInfo();
					break;
				}
				else
				{
					pCompositor->m_bDesignerState = false;
					pTangramPresentation->m_bDesignState = false;
				}
			}
			break;
			case 101:
			{
				auto iter = m_mapTaskPaneMap.find((LONG)pPntObject->m_hForm);
				if (iter != m_mapTaskPaneMap.end())
				{
					iter->second->put_Visible(true);
				}
				else
				{
					CString strXml = pTangramPresentation->m_strTaskPaneXml;
					if (strXml != _T(""))
					{
						CTangramXmlParse m_Parse;
						if (m_Parse.LoadXml(strXml))
						{
							VARIANT vWindow;
							vWindow.vt = VT_DISPATCH;
							vWindow.pdispVal = nullptr;
							Office::_CustomTaskPane* _pCustomTaskPane;
							CString strCap = _T("");
							strCap = m_Parse.attr(_T("Title"), _T(""));
							if (strCap == _T(""))
								strCap = _T("Tangram for PowerPoint");
							CComBSTR bstrCap(strCap);
							HRESULT hr = m_pCTPFactory->CreateCTP(L"Tangram.Ctrl.1", bstrCap, vWindow, &_pCustomTaskPane);
							_pCustomTaskPane->AddRef();
							_pCustomTaskPane->put_Visible(true);
							m_mapTaskPaneMap[(LONG)pPntObject->m_hForm] = _pCustomTaskPane;
							CComPtr<ITangramCtrl> pCtrlDisp;
							_pCustomTaskPane->get_ContentControl((IDispatch**)&pCtrlDisp);
							if (pCtrlDisp)
							{
								LONGLONG hWnd = 0;
								pCtrlDisp->get_HWND(&hWnd);
								HWND hPWnd = ::GetParent((HWND)hWnd);
								pPntObject->m_hTaskPane = (HWND)hWnd;
								if (pTangramPresentation->m_pTaskPaneCompositorManager == nullptr)
								{
									auto it = g_pTangram->m_mapWindowPage.find(hPWnd);
									if (it != g_pTangram->m_mapWindowPage.end())
										pTangramPresentation->m_pTaskPaneCompositorManager = it->second;
									else
									{
										pTangramPresentation->m_pTaskPaneCompositorManager = new CComObject<CCompositorManager>();
										pTangramPresentation->m_pTaskPaneCompositorManager->m_hWnd = hPWnd;
										g_pTangram->m_mapWindowPage[hPWnd] = pTangramPresentation->m_pTaskPaneCompositorManager;
									}

									if (pTangramPresentation->m_pTaskPaneCompositorManager)
									{
										ICompositor* pCompositor = nullptr;
										pTangramPresentation->m_pTaskPaneCompositorManager->CreateCompositor(CComVariant(0), CComVariant(hWnd), CComBSTR(L"TaskPane"), &pCompositor);
										pTangramPresentation->m_pTaskPaneCompositor = (CCompositor*)pCompositor;
										if (pTangramPresentation->m_pTaskPaneCompositor)
										{
											IWndNode* pNode = nullptr;
											pTangramPresentation->m_pTaskPaneCompositor->Open(CComBSTR("Default"), strXml.AllocSysString(), &pNode);
										}
									}
								}
								else
									pTangramPresentation->m_pTaskPaneCompositor->ModifyHost(hWnd);
							}
						}
					}
				}
			}
			break;
			case 102:
			{
			}
			break;
			}

			CComPtr<PowerPoint::_Presentation> pPres;
			m_pApplication->get_ActivePresentation(&pPres);
			CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
			pObj->Init(_T("PowerpntPlus"), 0, pPres.p);
			pObj->m_mapVar[0] = CComVariant(bstrID);
			pObj->m_mapVar[1] = CComVariant(bstrTag);

			FireTangramAppEvent(pObj);
			return S_OK;
		}

		HRESULT CPowerPntAddin::OnConnection(IDispatch* pHostApp, int ConnectMode)
		{
			COfficeAddin::OnConnection(pHostApp, ConnectMode);
			if (m_strRibbonXml == _T(""))
			{
				//CTangramXmlParse m_Parse;
				//if (m_Parse.LoadXml(m_strConfigFile) || m_Parse.LoadFile(m_strConfigFile))
				//{
				//	m_strRibbonXml = m_Parse[_T("RibbonUI")][_T("customUI")].xml();
				//}
			}
			pHostApp->QueryInterface(__uuidof(IDispatch), (LPVOID*)&m_pApplication);
			BSTR bstrCap = ::SysAllocString(L"");
			m_pApplication->get_Caption(&bstrCap);
			CString strCaption = OLE2T(bstrCap);
			strCaption += _T(" Plus");
			m_pApplication->put_Caption(strCaption.AllocSysString());
			::SysFreeString(bstrCap);
			HRESULT hr = ((CPowerpointPlusEApplication*)this)->DispEventAdvise(m_pApplication);
			return S_OK;
		}

		HRESULT CPowerPntAddin::OnDisconnection(int DisConnectMode)
		{
			HRESULT hr = ((CPowerpointPlusEApplication*)this)->DispEventUnadvise(m_pApplication);
			m_pApplication.Detach();
			return S_OK;
		}

		STDMETHODIMP CPowerPntAddin::GetCustomUI(BSTR RibbonID, BSTR* RibbonXml)
		{
			if (!RibbonXml)
				return E_POINTER;
			*RibbonXml = m_strRibbonXml.AllocSysString();
			return (*RibbonXml ? S_OK : E_OUTOFMEMORY);
		}

		bool CPowerPntAddin::OnActiveOfficeObj(HWND hWnd)
		{
			auto it = m_mapOfficeObjects2.find(hWnd);
			if (it != m_mapOfficeObjects2.end())
			{
				if (m_pActivePowerPntObject != it->second)
				{
					m_pActivePowerPntObject = (CPowerPntObject*)it->second;

					CCloudAddinPresentation* pTangramPresentation = m_pActivePowerPntObject->m_pPresentation;

					if (pTangramPresentation->m_pCompositor)
						pTangramPresentation->m_pCompositor->ModifyHost((LONGLONG)m_pActivePowerPntObject->m_hClient);

					if (pTangramPresentation->m_pTaskPaneCompositor)
					{
						if (::IsWindow(m_pActivePowerPntObject->m_hTaskPane))
							pTangramPresentation->m_pTaskPaneCompositor->ModifyHost((LONGLONG)m_pActivePowerPntObject->m_hTaskPane);
						else
							pTangramPresentation->m_pTaskPaneCompositor->ModifyHost((LONGLONG)m_pActivePowerPntObject->m_hTaskPaneChildWnd);
					}
					CCompositor* pCompositor = m_pActivePowerPntObject->m_pPresentation->m_pCompositor;
					if (pCompositor)
					{
						if (pCompositor->m_bDesignerState&&m_pDesignerFrame&&m_pDesigningFrame != pCompositor)
						{
							m_pDesigningFrame = pCompositor;
							pCompositor->UpdateDesignerTreeInfo();
						}
					}
				}
				return true;
			}
			return false;
		}

		void CPowerPntAddin::WindowDestroy(HWND hWnd)
		{
			::GetClassName(hWnd, m_szBuffer, MAX_PATH);
			CString strClassName = CString(m_szBuffer);
			if (strClassName == _T("ThunderDFrame"))
			{
				//OnDestroyVbaForm(hWnd);
				auto it = m_mapVBAForm.find(hWnd);
				if (it != m_mapVBAForm.end())
					m_mapVBAForm.erase(it);
			}
			else if (strClassName == _T("mdiClass"))
			{
				OnCloseOfficeObj(strClassName, hWnd);
			}
		}

		void CPowerPntAddin::WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd)
		{
			if (strClassName == _T("mdiClass"))
			{
				m_pActivePowerPntObject = new CComObject<CPowerPntObject>;
				m_pActivePowerPntObject->m_hForm = ::GetParent(hPWnd);
				m_pActivePowerPntObject->m_hClient = hPWnd;
				m_pActivePowerPntObject->m_hChildClient = hWnd;
				m_mapOfficeObjects2[m_pActivePowerPntObject->m_hForm] = m_pActivePowerPntObject;
				m_mapOfficeObjects[hWnd] = m_pActivePowerPntObject;
				::PostMessage(m_hHostWnd, WM_OFFICEOBJECTCREATED, (WPARAM)hWnd, 0);
			}
		}

		void CPowerPntAddin::ConnectOfficeObj(HWND hWnd)
		{
			if (m_pApplication == nullptr)
				return;
			auto it = m_mapOfficeObjects.find(hWnd);
			CPowerPntObject* pPowerPntWndObj = (CPowerPntObject*)it->second;
			CComPtr<_Presentation> pDoc;
			m_pApplication->get_ActivePresentation(&pDoc);
			if (pDoc)
			{
				CComBSTR bstrName(L"");
				pDoc->get_Path(&bstrName);
				CString strPath = OLE2T(bstrName);
				pDoc->get_FullName(&bstrName);
				CString strKey = OLE2T(bstrName);

				bool bNewWindow = false;
				CCloudAddinPresentation* pTangramPresentation = nullptr;// 
				auto it = m_mapTangramPres.find(strKey);
				if (it != m_mapTangramPres.end())
				{
					pTangramPresentation = it->second;
					bNewWindow = true;
				}
				else
				{
					pTangramPresentation = new CCloudAddinPresentation();
					m_mapTangramPres[strKey] = pTangramPresentation;
				}
				pTangramPresentation->m_strKey = strKey;
				(*pTangramPresentation)[hWnd] = pPowerPntWndObj;
				pPowerPntWndObj->m_pPresentation = pTangramPresentation;
				if (bNewWindow)
					return;

				if (strPath == _T(""))
				{
					CString strTemplate = GetDocTemplateXml(_T("Please select Slild Template:"), m_strExeName, _T(""));
					CTangramXmlParse m_Parse;
					bool bLoad = m_Parse.LoadXml(strTemplate);
					if (bLoad == false)
						bLoad = m_Parse.LoadFile(strTemplate);
					if (bLoad == false)
						return;
					CString strNewDocInfo = _T("");
					pTangramPresentation->m_strTaskPaneTitle = m_Parse.attr(_T("title"), _T("TaskPane"));
					pTangramPresentation->m_nWidth = m_Parse.attrInt(_T("width"), 200);
					pTangramPresentation->m_nHeight = m_Parse.attrInt(_T("height"), 300);
					pTangramPresentation->m_nMsoCTPDockPosition = (MsoCTPDockPosition)m_Parse.attrInt(_T("dockposition"), 4);
					pTangramPresentation->m_nMsoCTPDockPositionRestrict = (MsoCTPDockPositionRestrict)m_Parse.attrInt(_T("dockpositionrestrict"), 3);
					pPowerPntWndObj->m_pPresentation->m_strDocXml = m_Parse.xml();
					AddDocXml(pDoc, CComBSTR(pPowerPntWndObj->m_pPresentation->m_strDocXml), CComBSTR(L"tangram"));
					CTangramXmlParse* pParse = m_Parse.GetChild(_T("taskpaneui"));
					if (pParse)
					{
						CString strXml = pParse->xml();
						if (strXml != _T(""))
						{
							pPowerPntWndObj->m_pPresentation->m_strTaskPaneXml = strXml;
							auto it = m_mapTaskPaneMap.find((LONG)pPowerPntWndObj->m_hForm);
							if (it != m_mapTaskPaneMap.end())
							{
								it->second->put_Visible(false);
								m_mapTaskPaneMap.erase(it);
							}
							VARIANT vWindow;
							vWindow.vt = VT_DISPATCH;
							vWindow.pdispVal = nullptr;
							Office::_CustomTaskPane* _pCustomTaskPane;
							CString strCap = _T("");
							strCap = pParse->attr(_T("Title"), _T(""));
							if (strCap == _T(""))
								strCap = _T("Tangram for PowerPoint");
							CComBSTR bstrCap(strCap);
							HRESULT hr = m_pCTPFactory->CreateCTP(L"Tangram.Ctrl.1", bstrCap, vWindow, &_pCustomTaskPane);
							_pCustomTaskPane->AddRef();
							_pCustomTaskPane->put_Visible(true);
							m_mapTaskPaneMap[(LONG)pPowerPntWndObj->m_hForm] = _pCustomTaskPane;
							CComPtr<ITangramCtrl> pCtrlDisp;
							_pCustomTaskPane->get_ContentControl((IDispatch**)&pCtrlDisp);
							if (pCtrlDisp)
							{
								LONGLONG hWnd = 0;
								pCtrlDisp->get_HWND(&hWnd);
								HWND hPWnd = ::GetParent((HWND)hWnd);
								pPowerPntWndObj->m_hTaskPane = (HWND)hWnd;
								if (pTangramPresentation->m_pTaskPaneCompositorManager == nullptr)
								{
									auto it = m_mapWindowPage.find(hPWnd);
									if (it != m_mapWindowPage.end())
										pTangramPresentation->m_pTaskPaneCompositorManager = it->second;
									else
									{
										pTangramPresentation->m_pTaskPaneCompositorManager = new CComObject<CCompositorManager>();
										pTangramPresentation->m_pTaskPaneCompositorManager->m_hWnd = hPWnd;
										m_mapWindowPage[hPWnd] = pTangramPresentation->m_pTaskPaneCompositorManager;
									}

									if (pTangramPresentation->m_pTaskPaneCompositorManager)
									{
										ICompositor* pCompositor = nullptr;
										pTangramPresentation->m_pTaskPaneCompositorManager->CreateCompositor(CComVariant(0), CComVariant(hWnd), CComBSTR(L"TaskPane"), &pCompositor);
										pTangramPresentation->m_pTaskPaneCompositor = (CCompositor*)pCompositor;
										if (pTangramPresentation->m_pTaskPaneCompositor)
										{
											IWndNode* pNode = nullptr;
											pTangramPresentation->m_pTaskPaneCompositor->Open(CComBSTR("Default"), strXml.AllocSysString(), &pNode);
										}
									}
								}
								else
									pTangramPresentation->m_pTaskPaneCompositor->ModifyHost(hWnd);
							}
						}
					}
					pParse = m_Parse.GetChild(_T("documentui"));
					if (pParse)
					{
						ICompositorManager* pCompositorManager = nullptr;
						CreateCompositorManager((LONGLONG)pPowerPntWndObj->m_hForm, &pCompositorManager);
						pPowerPntWndObj->m_pPresentation->m_pDocCompositorManager = (CCompositorManager*)pCompositorManager;
						ICompositor* pCompositor = nullptr;
						pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)pPowerPntWndObj->m_hClient), CComBSTR(L"Document"), &pCompositor);
						pPowerPntWndObj->m_pPresentation->m_pCompositor = (CCompositor*)pCompositor;
						IWndNode* pNode = nullptr;
						pCompositor->Open(CComBSTR(L"Default"), CComBSTR(pParse->xml()), &pNode);
					}
				}
				else
				{
					CString strXML = GetDocXmlByKey(pDoc, CComBSTR(L"tangram"));
					pPowerPntWndObj->m_pPresentation->m_strDocXml = strXML;

					if (strXML != _T(""))
					{
						CTangramXmlParse m_Parse;
						if (m_Parse.LoadXml(strXML) || m_Parse.LoadFile(strXML))
						{
							CTangramXmlParse* pParse = m_Parse.GetChild(_T("taskpaneui"));
							if (pParse)
							{
								CString strXml = pParse->xml();
								if (pPowerPntWndObj != nullptr)
								{
									pPowerPntWndObj->m_pPresentation->m_strTaskPaneXml = strXml;
									auto it = m_mapTaskPaneMap.find((LONG)pPowerPntWndObj->m_hForm);
									if (it != m_mapTaskPaneMap.end())
									{
										it->second->put_Visible(false);
										m_mapTaskPaneMap.erase(it);
									}
									VARIANT vWindow;
									vWindow.vt = VT_DISPATCH;
									vWindow.pdispVal = nullptr;
									Office::_CustomTaskPane* _pCustomTaskPane;
									CString strCap = _T("");
									strCap = pParse->attr(_T("Title"), _T(""));
									if (strCap == _T(""))
										strCap = _T("Tangram for PowerPoint");
									CComBSTR bstrCap(strCap);
									HRESULT hr = m_pCTPFactory->CreateCTP(L"Tangram.Ctrl.1", bstrCap, vWindow, &_pCustomTaskPane);
									_pCustomTaskPane->AddRef();
									_pCustomTaskPane->put_Visible(true);
									m_mapTaskPaneMap[(LONG)pPowerPntWndObj->m_hForm] = _pCustomTaskPane;
									CComPtr<ITangramCtrl> pCtrlDisp;
									_pCustomTaskPane->get_ContentControl((IDispatch**)&pCtrlDisp);
									if (pCtrlDisp)
									{
										LONGLONG hWnd = 0;
										pCtrlDisp->get_HWND(&hWnd);
										HWND hPWnd = ::GetParent((HWND)hWnd);
										pPowerPntWndObj->m_hTaskPane = (HWND)hWnd;
										if (pTangramPresentation->m_pTaskPaneCompositorManager == nullptr)
										{
											auto it = m_mapWindowPage.find(hPWnd);
											if (it != m_mapWindowPage.end())
												pTangramPresentation->m_pTaskPaneCompositorManager = it->second;
											else
											{
												pTangramPresentation->m_pTaskPaneCompositorManager = new CComObject<CCompositorManager>();
												pTangramPresentation->m_pTaskPaneCompositorManager->m_hWnd = hPWnd;
												m_mapWindowPage[hPWnd] = pTangramPresentation->m_pTaskPaneCompositorManager;
											}

											if (pTangramPresentation->m_pTaskPaneCompositorManager)
											{
												ICompositor* pCompositor = nullptr;
												pTangramPresentation->m_pTaskPaneCompositorManager->CreateCompositor(CComVariant(0), CComVariant(hWnd), CComBSTR(L"TaskPane"), &pCompositor);
												pTangramPresentation->m_pTaskPaneCompositor = (CCompositor*)pCompositor;
												if (pTangramPresentation->m_pTaskPaneCompositor)
												{
													IWndNode* pNode = nullptr;
													pTangramPresentation->m_pTaskPaneCompositor->Open(CComBSTR("Default"), strXml.AllocSysString(), &pNode);
												}
											}
										}
										else
											pTangramPresentation->m_pTaskPaneCompositor->ModifyHost(hWnd);
									}
								}
							}
							pParse = m_Parse.GetChild(_T("documentui"));
							if (pParse)
							{
								ICompositorManager* pCompositorManager = nullptr;
								CreateCompositorManager((LONGLONG)pPowerPntWndObj->m_hForm, &pCompositorManager);
								pPowerPntWndObj->m_pPresentation->m_pDocCompositorManager = (CCompositorManager*)pCompositorManager;
								ICompositor* pCompositor = nullptr;
								pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)pPowerPntWndObj->m_hClient), CComBSTR(L"Document"), &pCompositor);
								pPowerPntWndObj->m_pPresentation->m_pCompositor = (CCompositor*)pCompositor;
								IWndNode* pNode = nullptr;
								pCompositor->Open(CComBSTR(L"Default"), CComBSTR(pParse->xml()), &pNode);
							}
						}
					}
				}
			}
		}

		HRESULT CPowerPntAddin::CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv)
		{
			return CPowerPntAppCtrl::_CreatorClass::CreateInstance(pv, riid, ppv);
		}

		CPowerPntAppCtrl::CPowerPntAppCtrl()
		{

		}

		STDMETHODIMP CPowerPntAppCtrl::put_AppCtrl(VARIANT_BOOL newVal)
		{
			g_pTangram->m_pTangramAppCtrl = this;
			return S_OK;
		}
		void CPowerPntAppCtrl::OnFinalMessage(HWND hWnd)
		{
			__super::OnFinalMessage(hWnd);
		}

		STDMETHODIMP CPowerPntAppCtrl::get_tag(VARIANT* pVal)
		{
			return S_OK;
		}


		STDMETHODIMP CPowerPntAppCtrl::put_tag(VARIANT newVal)
		{
			return S_OK;
		}

		STDMETHODIMP CPowerPntAppCtrl::get_HWND(LONGLONG* pVal)
		{
			*pVal = (long)m_hWnd;
			return S_OK;
		}

		STDMETHODIMP CPowerPntAppCtrl::get_Tangram(ITangram** pVal)
		{
			*pVal = g_pTangram;
			return S_OK;
		}
	}
}// namespace OfficePlus

