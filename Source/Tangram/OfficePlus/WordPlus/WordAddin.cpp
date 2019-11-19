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
#include "../../NodeWnd.h"
#include "../../WndNode.h"
#include "../../Compositor.h"
#include "../../TangramHtmlTreeWnd.h"
#include "fm20.h"
#include "WordAddin.h"
#include "WordPlusDoc.h"

namespace OfficePlus
{
	namespace WordPlus
	{
		CWordAddin::CWordAddin() :COfficeAddin()
		{
			m_pActiveWordObject = nullptr;
			m_pWordAppObjEvents = nullptr;
			m_pWordAppObjEvents2 = nullptr;
			m_strDesignerToolBarCaption = _T("Word Document Designer");
		}

		CWordAddin::~CWordAddin()
		{
			if (m_pWordAppObjEvents)
				delete m_pWordAppObjEvents;
			if (m_pWordAppObjEvents2)
				delete m_pWordAppObjEvents2;
		}

		void CWordAddin::AddDocXml(IDispatch* pDocdisp, BSTR bstrXml, BSTR bstrKey)
		{
			CComQIPtr<Word::_Document> pDoc(pDocdisp);
			if (pDoc)
			{
				CComPtr<Office::_CustomXMLParts> pCustomXMLParts;
				pDoc->get_CustomXMLParts(&pCustomXMLParts);
				_AddDocXml(pCustomXMLParts.p, bstrXml, bstrKey);
			}
		}

		CString CWordAddin::GetDocXmlByKey(IDispatch* pDocdisp, BSTR bstrKey)
		{
			CComQIPtr<Word::_Document> pDoc(pDocdisp);
			CString strRet = _T("");
			if (pDoc)
			{
				CComPtr<Office::_CustomXMLParts> pCustomXMLParts;
				pDoc->get_CustomXMLParts(&pCustomXMLParts);
				if (pCustomXMLParts)
				{
					strRet = _GetDocXmlByKey(pCustomXMLParts.p, bstrKey);
				}
			}
			return strRet;
		}

		void CWordAddin::OnOpenDoc(WPARAM wParam)
		{
			CWordDocument* pWordDoc = (CWordDocument*)wParam;
			CWordObject* pWordWnd = pWordDoc->begin()->second;

			auto it = m_mapWindowPage.find(pWordWnd->m_hChildClient);
			if (it != m_mapWindowPage.end())
				pWordDoc->m_pDocCompositorManager = it->second;
			else
			{
				pWordDoc->m_pDocCompositorManager = new CComObject<CCompositorManager>();
				pWordDoc->m_pDocCompositorManager->m_hWnd = pWordWnd->m_hChildClient;
				m_mapWindowPage[pWordWnd->m_hChildClient] = pWordWnd->m_pCompositorManager;
			}

			if (pWordDoc->m_pDocCompositorManager)
			{
				ICompositor* pCompositor = NULL;
				pWordDoc->m_pDocCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)pWordWnd->m_hChildClient), CComBSTR(L"Document"), &pCompositor);
				pWordDoc->m_pCompositor = (CCompositor*)pCompositor;
				if (pWordDoc->m_pCompositor)
				{
					auto it = pWordDoc->m_mapDocUIInfo.find(_T("documentui"));
					CString strXml = _T("");
					if (it != pWordDoc->m_mapDocUIInfo.end())
						strXml = it->second;
					else
						strXml = _T("<Document><window><node name=\"Start\" id=\"HostView\"/></window></Document>");
					IWndNode* pNode = nullptr;
					pWordDoc->m_pCompositor->Open(CComBSTR(L"Default"), strXml.AllocSysString(), &pNode);
					CWndNode* _pNode = (CWndNode*)pNode;
					if (_pNode->m_pTangramNodeCommonData->m_pOfficeObj == nullptr)
					{
						_pNode->m_pTangramNodeCommonData->m_pOfficeObj = pWordDoc->m_pDoc;
						_pNode->m_pTangramNodeCommonData->m_pOfficeObj->AddRef();
					}

					CString strKey = _T("taskpaneui");
					
					it = pWordDoc->m_mapDocUIInfo.find(strKey);
					strXml = _T("");
					if (it != pWordDoc->m_mapDocUIInfo.end())
						strXml = it->second;

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
							CTangramXmlParse* pNodeParse = m_Parse.FindItem(_T("node"));
							strCap = pNodeParse->attr(_T("caption"), _T(""));
							if (strCap == _T(""))
								strCap = pNodeParse->attr(_T("name"), _T(""));;
							CComBSTR bstrCap(strCap);
							HRESULT hr = m_pCTPFactory->CreateCTP(L"Tangram.Ctrl.1", bstrCap, vWindow, &_pCustomTaskPane);
							_pCustomTaskPane->AddRef();
							_pCustomTaskPane->put_Visible(true);
							m_mapTaskPaneMap[(long)m_pActiveWordObject->m_hForm] = _pCustomTaskPane;
							CComPtr<ITangramCtrl> pCtrlDisp;
							_pCustomTaskPane->get_ContentControl((IDispatch**)&pCtrlDisp);
							if (pCtrlDisp)
							{
								LONGLONG hWnd = 0;
								pCtrlDisp->get_HWND(&hWnd);
								HWND hPWnd = ::GetParent((HWND)hWnd);
								pWordWnd->m_hTaskPane = (HWND)hWnd;
								CWindow m_Wnd;
								m_Wnd.Attach(hPWnd);
								m_Wnd.ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
								m_Wnd.Detach();
								CWordDocument* m_pDoc = pWordWnd->m_pWordPlusDoc;
								if (m_pDoc->m_pTaskPaneCompositorManager == nullptr)
								{
									auto it = m_mapWindowPage.find(hPWnd);
									if (it != m_mapWindowPage.end())
										m_pDoc->m_pTaskPaneCompositorManager = it->second;
									else
									{
										m_pDoc->m_pTaskPaneCompositorManager = new CComObject<CCompositorManager>();
										m_pDoc->m_pTaskPaneCompositorManager->m_hWnd = hPWnd;
										m_mapWindowPage[hPWnd] = m_pDoc->m_pTaskPaneCompositorManager;
									}

									if (m_pDoc->m_pTaskPaneCompositorManager)
									{
										ICompositor* pTaskPaneFrame = nullptr;
										m_pDoc->m_pTaskPaneCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)hWnd), CComBSTR(L"TaskPane"), &pTaskPaneFrame);
										m_pDoc->m_pTaskPaneCompositor = (CCompositor*)pTaskPaneFrame;
										if (m_pDoc->m_pTaskPaneCompositor)
										{
											IWndNode* pNode = nullptr;
											m_pDoc->m_pTaskPaneCompositor->Open(CComBSTR("Default"), strXml.AllocSysString(), &pNode);
											CWndNode* _pNode = (CWndNode*)pNode;
											if (_pNode->m_pTangramNodeCommonData->m_pOfficeObj == nullptr)
											{
												_pNode->m_pTangramNodeCommonData->m_pOfficeObj = pWordDoc->m_pDoc;
												_pNode->m_pTangramNodeCommonData->m_pOfficeObj->AddRef();
											}
										}
									}
								}
								else
									m_pDoc->m_pTaskPaneCompositor->ModifyHost(hWnd);
							}
						}
					}
				}
			}
		}

		void CWordAddin::OnStartup()
		{
			if (m_pApplication == nullptr)
				return;
			int nIndex = 0x00000001;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>();
					pObj->Init(_T("Startup"), nIndex, m_pApplication.p);
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnQuit()
		{
			int nIndex = 0x00000002;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("Quit"), nIndex, m_pApplication.p);
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnDocumentChange()
		{
			int nIndex = 0x00000003;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("DocumentChange"), nIndex, m_pApplication.p);
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnDocumentOpen(_Document* Doc) 
		{
			int nIndex = 0x00000004;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("DocumentBeforeSave"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnDocumentBeforeClose(_Document* Doc, VARIANT_BOOL* Cancel) 
		{
			int nIndex = 0x00000006;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("DocumentBeforeClose"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[0] = var1;
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnDocumentBeforePrint(_Document* Doc, VARIANT_BOOL* Cancel)
		{
			int nIndex = 0x00000007;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("DocumentBeforePrint"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[0] = var1;
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnNewDocument(_Document* Doc) 
		{
			int nIndex = 0x00000009;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("NewDocument"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnWindowActivate(_Document* Doc, Word::Window* Wn)
		{
			int nIndex = 0x0000000a;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("WindowActivate"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = Wn;
					pObj->m_mapDisp[1]->AddRef();
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnWindowDeactivate(_Document* Doc, Word::Window* Wn)
		{
			int nIndex = 0x0000000b;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("WindowDeactivate"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = Wn;
					pObj->m_mapDisp[1]->AddRef();
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnWindowSelectionChange(Selection* Sel)
		{
			int nIndex = 0x0000000c;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("WindowSelectionChange"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Sel;
					pObj->m_mapDisp[0]->AddRef();
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnWindowBeforeRightClick(Selection* Sel, VARIANT_BOOL* Cancel) 
		{
			int nIndex = 0x0000000d;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("WindowBeforeRightClick"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Sel;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[0] = var1;
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnWindowBeforeDoubleClick(Selection* Sel, VARIANT_BOOL* Cancel)
		{
			int nIndex = 0x0000000e;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("WindowBeforeDoubleClick"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Sel;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[0] = var1;
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::OnDocumentBeforeSave(_Document* Doc, VARIANT_BOOL* SaveAsUI, VARIANT_BOOL* Cancel)
		{
			auto it = find(Doc);
			if (it != end())
			{
				CCompositor* pCompositor = it->second->m_pCompositor;
				if (pCompositor)
					pCompositor->UpdateWndNode();
				pCompositor = it->second->m_pTaskPaneCompositor;
				if (pCompositor)
					pCompositor->UpdateWndNode();
			}
			int nIndex = 0x00000008;
			auto it2 = m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("DocumentBeforeSave"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var;
					var.vt = VT_BOOL | VT_BYREF;
					var.pboolVal = SaveAsUI;
					pObj->m_mapVar[0] = var;
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[1] = var1;
					FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAddin::WindowDestroy(HWND hWnd)
		{
			::GetClassName(hWnd, m_szBuffer, MAX_PATH);
			CString strClassName = CString(m_szBuffer);
			if (strClassName == _T("ThunderDFrame"))
			{
				auto it = m_mapVBAForm.find(hWnd);
				if (it != m_mapVBAForm.end())
					m_mapVBAForm.erase(it);
			}
			else if (strClassName == _T("_WwB"))
			{
				OnCloseOfficeObj(strClassName, hWnd);
			}
		}

		void CWordAddin::WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd)
		{
			if (strClassName == _T("_WwB"))
			{
				::PostMessage(m_hHostWnd, WM_OFFICEOBJECTCREATED, (WPARAM)hWnd, 0);
			}
		}

		STDMETHODIMP CWordAddin::StartApplication(BSTR bstrAppID, BSTR bstrXml)
		{
			CString strID = OLE2T(bstrAppID);
			strID.MakeLower();
			if (strID.Find(_T("word.application")) == 0)
				return put_AppKeyValue(CComBSTR(L"doctemplate"), CComVariant(bstrXml));
			return CTangram::StartApplication(bstrAppID, bstrXml);
		}

		STDMETHODIMP CWordAddin::TangramCommand(IDispatch* RibbonControl)
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
			if (m_pActiveWordObject == nullptr)
				return S_OK;
			CString strTag = OLE2T(bstrTag);
			int nPos = strTag.Find(_T("TangramButton.Cmd"));
			strTag.Replace(_T("TangramButton.Cmd."), _T(""));
			int nCmdIndex = _wtoi(strTag);

			CWordObject* pWnd = m_pActiveWordObject;
			CWordDocument* pWordDoc = m_pActiveWordObject->m_pWordPlusDoc;

			switch (nCmdIndex)
			{
			case 100:
			{
				if (pWnd)
				{
					CCompositor* pCompositor = pWnd->m_pWordPlusDoc->m_pCompositor;
					if (pCompositor == nullptr)
						break;
					if (pWnd->m_bDesignState == false)
					{
						pCompositor->m_bDesignerState = true;
						pWnd->m_bDesignState = true;
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
						pWnd->m_bDesignState = false;
					}
				}
			}
			break;
			case 101:
			case 102:
			{
				auto iter = m_mapTaskPaneMap.find((long)m_pActiveWordObject->m_hForm);
				if (iter != m_mapTaskPaneMap.end())
					iter->second->put_Visible(true);
				else
				{
					CString strKey = _T("taskpaneui");
					auto it = pWnd->m_pWordPlusDoc->m_mapDocUIInfo.find(strKey);
					CString strXml = _T("");
					if (it != pWnd->m_pWordPlusDoc->m_mapDocUIInfo.end())
						strXml = it->second;
					else
						strXml = _T("<taskpaneui><window><node name=\"Start\" /></window></taskpaneui>");
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
							CTangramXmlParse* pNodeParse = m_Parse.FindItem(_T("node"));
							strCap = pNodeParse->attr(_T("caption"), _T(""));
							if (strCap == _T(""))
								strCap = pNodeParse->attr(_T("name"), _T(""));;
							CComBSTR bstrCap(strCap);
							HRESULT hr = m_pCTPFactory->CreateCTP(L"Tangram.Ctrl.1", bstrCap, vWindow, &_pCustomTaskPane);
							_pCustomTaskPane->AddRef();
							_pCustomTaskPane->put_Visible(true);
							m_mapTaskPaneMap[(long)m_pActiveWordObject->m_hForm] = _pCustomTaskPane;
							CComPtr<ITangramCtrl> pCtrlDisp;
							_pCustomTaskPane->get_ContentControl((IDispatch**)&pCtrlDisp);
							if (pCtrlDisp)
							{
								LONGLONG hWnd = 0;
								pCtrlDisp->get_HWND(&hWnd);
								HWND hPWnd = ::GetParent((HWND)hWnd);
								pWnd->m_hTaskPane = (HWND)hWnd;
								CWindow m_Wnd;
								m_Wnd.Attach(hPWnd);
								m_Wnd.ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
								m_Wnd.Detach();
								CWordDocument* m_pDoc = pWnd->m_pWordPlusDoc;
								if (m_pDoc->m_pTaskPaneCompositorManager == nullptr)
								{
									auto it = m_mapWindowPage.find(hPWnd);
									if (it != m_mapWindowPage.end())
										m_pDoc->m_pTaskPaneCompositorManager = it->second;
									else
									{
										m_pDoc->m_pTaskPaneCompositorManager = new CComObject<CCompositorManager>();
										m_pDoc->m_pTaskPaneCompositorManager->m_hWnd = hPWnd;
										m_mapWindowPage[hPWnd] = m_pDoc->m_pTaskPaneCompositorManager;
									}

									if (m_pDoc->m_pTaskPaneCompositorManager)
									{
										ICompositor* pTaskPaneFrame = nullptr;
										m_pDoc->m_pTaskPaneCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)hWnd), CComBSTR(L"TaskPane"), &pTaskPaneFrame);
										m_pDoc->m_pTaskPaneCompositor = (CCompositor*)pTaskPaneFrame;
										if (m_pDoc->m_pTaskPaneCompositor)
										{
											IWndNode* pNode = nullptr;
											m_pDoc->m_pTaskPaneCompositor->Open(CComBSTR("Default"), strXml.AllocSysString(), &pNode);
											CWndNode* _pNode = (CWndNode*)pNode;
											if (_pNode->m_pTangramNodeCommonData->m_pOfficeObj == nullptr)
											{
												_pNode->m_pTangramNodeCommonData->m_pOfficeObj = pWordDoc->m_pDoc;
												_pNode->m_pTangramNodeCommonData->m_pOfficeObj->AddRef();
											}
										}
									}
								}
								else
									m_pDoc->m_pTaskPaneCompositor->ModifyHost(hWnd);
							}
						}
					}
				}
				if (nCmdIndex == 102 && pWnd)
				{
					CreateCommonDesignerToolBar();
					CCompositor* pCompositor = pWnd->m_pWordPlusDoc->m_pTaskPaneCompositor;
					if (pWnd->m_bDesignTaskPane == false)
					{
						pCompositor->m_bDesignerState = true;
						if (m_pDesigningFrame != pCompositor)
						{
							m_pDesigningFrame = pCompositor;
							pCompositor->UpdateDesignerTreeInfo();
						}
					}
					else
					{
						pCompositor->m_bDesignerState = false;
						if (m_pDesigningFrame == pCompositor)
						{
							m_pDesigningFrame = nullptr;
							pCompositor->UpdateDesignerTreeInfo();
						}
					}
				}
			}
			break;
			}

			CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
			pObj->Init(_T("WordPlus"), 0, pWordDoc->m_pDoc);
			pObj->m_mapVar[0] = CComVariant(bstrID);
			pObj->m_mapVar[1] = CComVariant(bstrTag);

			g_pTangram->FireTangramAppEvent(pObj);

			return S_OK;
		}

		HRESULT CWordAddin::OnConnection(IDispatch* pHostApp, int ConnectMode)
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
			BSTR bstrCap = ::SysAllocString(L"");
			m_pApplication->get_Caption(&bstrCap);
			CString strCaption = OLE2T(bstrCap);
			strCaption += _T(" Plus");
			m_pApplication->put_Caption(strCaption.AllocSysString());
			::SysFreeString(bstrCap);
			HRESULT hr = ((CWordAppEvents2*)this)->DispEventAdvise(m_pApplication);
			if (m_pWordAppObjEvents)
			{
				hr = m_pWordAppObjEvents->DispEventAdvise(m_pApplication);
			}
			if (m_pWordAppObjEvents2)
			{
				hr = m_pWordAppObjEvents2->DispEventAdvise(m_pApplication);
			}
			//hr = ((CWordAppEvents3*)this)->DispEventAdvise(m_pApplication);
			//hr = ((CWordAppEvents4*)this)->DispEventAdvise(m_pApplication);
			if (::IsWindow(m_hHostWnd))
			{
				WNDCLASSEX wcex;
				wcex.cbSize = sizeof(WNDCLASSEX);
				wcex.style = CS_HREDRAW | CS_VREDRAW;
				wcex.lpfnWndProc = ::DefWindowProc;
				wcex.cbClsExtra = 0;
				wcex.cbWndExtra = 0;
				wcex.hInstance = theApp.m_hInstance;
				wcex.hIcon = NULL;
				wcex.hCursor = NULL;
				wcex.hbrBackground = NULL;
				wcex.lpszMenuName = NULL;
				wcex.lpszClassName = L"Tangram Word Helper Window";
				wcex.hIconSm = NULL;
				RegisterClassEx(&wcex);
			}
			return S_OK;
		}

		HRESULT CWordAddin::OnDisconnection(int DisConnectMode)
		{
			HRESULT hr = ((CWordAppEvents2*)this)->DispEventUnadvise(m_pApplication);
			if (m_pWordAppObjEvents)
			{
				hr = m_pWordAppObjEvents->DispEventUnadvise(m_pApplication);
			}
			if (m_pWordAppObjEvents2)
			{
				hr = m_pWordAppObjEvents2->DispEventUnadvise(m_pApplication);
			}

			m_pApplication = nullptr;
			return S_OK;
		}

		STDMETHODIMP CWordAddin::GetCustomUI(BSTR RibbonID, BSTR* RibbonXml)
		{
			if (!RibbonXml || m_strRibbonXml == _T(""))
				return E_POINTER;
			*RibbonXml = CComBSTR(m_strRibbonXml);
			return (*RibbonXml ? S_OK : E_OUTOFMEMORY);
		}

		CString CWordAddin::GetFormXml(CString strFormName)
		{
			CWordDocument* pWordDoc = m_pActiveWordObject->m_pWordPlusDoc;
			auto it = pWordDoc->m_mapUserFormScript.find(strFormName);
			if (it != pWordDoc->m_mapUserFormScript.end())
				return it->second;

			return _T("");
		}

		STDMETHODIMP CWordAddin::ExportOfficeObjXml(IDispatch* OfficeObject, BSTR* bstrXml)
		{
			return S_OK;
		}

		void CWordAddin::UpdateOfficeObj(IDispatch* pObj, CString strXml, CString _strName)
		{
			CComQIPtr<MSForm::_UserForm> pForm(pObj);
			if (pForm)
			{
				CComPtr<_Document> pDoc;
				m_pApplication->get_ActiveDocument(&pDoc);
				if (pDoc)
				{
					CComPtr<Office::_CustomXMLParts> pCustomXMLParts;
					pDoc->get_CustomXMLParts(&pCustomXMLParts);
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(_GetDocXmlByKey(pCustomXMLParts.p, CComBSTR(L"tangram"))))
					{
						CString strName = _T("");
						DISPID dispID = 0x80010000;
						DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
						VARIANT result = { 0 };
						EXCEPINFO excepInfo;
						memset(&excepInfo, 0, sizeof excepInfo);
						UINT nArgErr = (UINT)-1;
						HRESULT hr = pObj->Invoke(dispID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
						if (S_OK == hr && VT_BSTR == result.vt)
						{
							CComBSTR bstrName = result.bstrVal;
							strName = OLE2T(bstrName);
							::VariantClear(&result);
						}

						CTangramXmlParse* pParse = m_Parse.GetChild(_T("userforms"));
						if (pParse)
						{
							CTangramXmlParse* pParse2 = pParse->GetChild(strName);
							CString strXml2 = _T("");
							if (pParse2)
							{
								CTangramXmlParse* pParse3 = pParse2->GetChild(_T("window"));
								CString strGUID = GetNewGUID();
								pParse2->RemoveNode(pParse3);
								pParse2->put_text(strGUID);
								strXml2 = m_Parse.xml();
								strXml2.Replace(strGUID, strXml);
							}
							else
							{
								strXml2.Format(_T("<%s>%s</%s>"), strName, strXml, strName);
								CTangramXmlParse m_Parse2;
								m_Parse2.LoadXml(strXml2);
								pParse->AddNode(&m_Parse2, _T(""));
								strXml2 = m_Parse.xml();
							}
							AddDocXml(pDoc, CComBSTR(strXml2), CComBSTR(L"tangram"));
						}
					}
				}
				return;
			}
			CComQIPtr<_Document> pDoc(pObj);
			if (pDoc)
			{
				CComPtr<Office::_CustomXMLParts> pCustomXMLParts;
				pDoc->get_CustomXMLParts(&pCustomXMLParts);
				CString _strXml = _GetDocXmlByKey(pCustomXMLParts.p, CComBSTR(L"tangram"));
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadXml(_strXml))
				{
					CTangramXmlParse* pParse = m_Parse.GetChild(_strName);
					if (pParse)
					{
						CTangramXmlParse* pParse3 = pParse->GetChild(_T("window"));
						CString strGUID = GetNewGUID();
						pParse->RemoveNode(pParse3);
						pParse->put_text(strGUID);
						CString str = m_Parse.xml();
						str.Replace(strGUID, strXml);
						AddDocXml(pDoc, CComBSTR(str), CComBSTR(L"tangram"));
					}
				}

				//CComBSTR bstrXml(L"");
				//it1->second->get_Title(&bstrXml);
				//strXml = OLE2T(bstrXml);
				//m_Parse.put_attr(_T(""), strXml);
				//int nValue = 0;
				//it1->second->get_Width(&nValue);
				//m_Parse.put_attr(_T("width"), nValue);
				//it1->second->get_Height(&nValue);
				//m_Parse.put_attr(_T("height"), nValue);
				//Office::MsoCTPDockPosition m_Pos;
				//it1->second->get_DockPosition(&m_Pos);
				//m_Parse.put_attr(_T("dockposition"), m_Pos);
				//Office::MsoCTPDockPositionRestrict m_MsoCTPDockPositionRestrict;
				//it1->second->get_DockPositionRestrict(&m_MsoCTPDockPositionRestrict);
				//m_Parse.put_attr(_T("dockpositionrestrict"), m_MsoCTPDockPositionRestrict);
				//pAddin->AddDocXml(m_pWorkBook, CComBSTR(m_Parse.xml()), CComBSTR(L"tangram"));
			}
		}

		STDMETHODIMP CWordAddin::AttachObjEvent(IDispatch* pDisp, int nEventIndex)
		{
			if (0x000f <= nEventIndex&&nEventIndex <= 0x0019)
			{
				if (m_pWordAppObjEvents == nullptr)
				{
					m_pWordAppObjEvents = new CWordAppObjEvents();
					m_pWordAppObjEvents->DispEventAdvise(m_pApplication);
				}
			}
			else if (nEventIndex > 0x0019)
			{
				if (m_pWordAppObjEvents2 == nullptr)
				{
					m_pWordAppObjEvents2 = new CWordAppObjEvents2();
					m_pWordAppObjEvents2->DispEventAdvise(m_pApplication);
				}
			}
			return CTangram::AttachObjEvent(pDisp, nEventIndex);
		}

		STDMETHODIMP CWordAddin::put_AppKeyValue(BSTR bstrKey, VARIANT newVal)
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
				CComPtr<Documents> pDocsDisp2;
				m_pApplication->get_Documents(&pDocsDisp2);
				if (pDocsDisp2)
				{
					CComPtr<_Document> pDoc;
					CComVariant varVisible(true);
					CComVariant varNew(false);
					CComVariant varTemplate(L"");
					CComVariant varTypr(WdDocumentType::wdTypeDocument);
					//pDocsDisp2->Add(CComVariant(nullptr), &CComVariant(nullptr), &CComVariant(nullptr), &varVisible, &pDoc);d:\\tangram.docx
					return pDocsDisp2->Add(&varTemplate, &varNew, &varTypr, &varVisible, &pDoc);
				}
			}
			return CTangram::put_AppKeyValue(bstrKey, newVal);
		}

		bool CWordAddin::OnActiveOfficeObj(HWND hWnd)
		{
			auto it = m_mapOfficeObjects2.find(hWnd);
			if (it != m_mapOfficeObjects2.end())
			{
				if (m_pActiveWordObject != it->second)
				{
					m_pActiveWordObject = (CWordObject*)it->second;
				}
				OnDocActivate(m_pActiveWordObject);
				return true;
			}
			return false;
		}

		void CWordAddin::OnDocActivate(CWordObject* pWnd)
		{
			if (m_pActiveWordObject)
			{
				if (m_pActiveWordObject->m_bDesignState)
				{
					CreateCommonDesignerToolBar();
				}
				CWordDocument* pWordPlusDoc = m_pActiveWordObject->m_pWordPlusDoc;
				if (pWordPlusDoc)
				{
					if (pWordPlusDoc->m_pCompositor)
						pWordPlusDoc->m_pCompositor->ModifyHost((LONGLONG)m_pActiveWordObject->m_hChildClient);
					if (pWordPlusDoc->m_pTaskPaneCompositor)
						pWordPlusDoc->m_pTaskPaneCompositor->ModifyHost(m_pActiveWordObject->m_hTaskPane?(LONGLONG)m_pActiveWordObject->m_hTaskPane:(LONGLONG)m_pActiveWordObject->m_hTaskPaneChildWnd);
				}
			}
		}

		HRESULT CWordAddin::CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv)
		{
			return CWordAppCtrl::_CreatorClass::CreateInstance(pv, riid, ppv);
		}

		void CWordAddin::ConnectOfficeObj(HWND hWnd)
		{
			if (m_pApplication == nullptr)
				return;
			::GetWindowText(hWnd, m_szBuffer, 255);
			CString strCaption = CString(m_szBuffer);
			if (strCaption == _T(""))
				return;

			m_pActiveWordObject = new CComObject<CWordObject>;
			m_pActiveWordObject->m_hClient = ::GetParent(hWnd);
			m_pActiveWordObject->m_hChildClient = hWnd;
			m_pActiveWordObject->m_hForm = ::GetParent(m_pActiveWordObject->m_hClient);
			m_mapOfficeObjects2[m_pActiveWordObject->m_hForm] = m_pActiveWordObject;
			m_mapOfficeObjects[hWnd] = m_pActiveWordObject;

			CWindow m_wnd;
			m_wnd.Attach(m_pActiveWordObject->m_hChildClient);
			m_wnd.ModifyStyle(WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, 0);

			bool bNewWindow = false;
			_Document* pDoc = nullptr;
			m_pApplication->get_ActiveDocument(&pDoc);
			CWordDocument* pWordDoc = nullptr;
			auto it1 = find(pDoc);
			if (it1 != end())
			{
				pWordDoc = it1->second;
				bNewWindow = true;
			}
			else
			{
				pWordDoc = new CWordDocument();
				(*this)[pDoc] = pWordDoc;
				HRESULT hr = pWordDoc->DispEventAdvise(pDoc);
				pWordDoc->m_pDoc = pDoc;
				pWordDoc->m_pDoc->AddRef();
			}
			m_pActiveWordObject->m_pOfficeObj = pDoc;
			m_pActiveWordObject->m_pOfficeObj->AddRef();
			m_pActiveWordObject->m_pWordPlusDoc = pWordDoc;
			(*pWordDoc)[hWnd] = m_pActiveWordObject;
			if (bNewWindow)
				return;

			RECT rc;
			::GetClientRect(m_pActiveWordObject->m_hClient, &rc);
			::SetWindowPos(m_pActiveWordObject->m_hChildClient, HWND_TOP, 0, 0, rc.right, rc.bottom, SWP_NOREDRAW | SWP_NOACTIVATE);
			CComBSTR bstrPath(L"");
			pDoc->get_Path(&bstrPath);
			CString strPath = OLE2T(bstrPath);
			if (strPath == _T(""))
			{
				CString strTemplate = GetDocTemplateXml(_T("Please select Word Document Template:"), m_strExeName, _T(""));

				CTangramXmlParse m_Parse;
				bool bLoad = m_Parse.LoadXml(strTemplate);
				if (bLoad == false)
					bLoad = m_Parse.LoadFile(strTemplate);
				if (bLoad == false)
					return;
				VARIANT_BOOL bRet = false;
				CComBSTR bstrRet(L"");
				CString strNewDocInfo = _T("");
				pWordDoc->m_strTaskPaneTitle = m_Parse.attr(_T("title"), _T("TaskPane"));
				pWordDoc->m_nWidth = m_Parse.attrInt(_T("width"), 200);
				pWordDoc->m_nHeight = m_Parse.attrInt(_T("height"), 300);
				pWordDoc->m_nMsoCTPDockPosition = (MsoCTPDockPosition)m_Parse.attrInt(_T("dockposition"), 4);
				pWordDoc->m_nMsoCTPDockPositionRestrict = (MsoCTPDockPositionRestrict)m_Parse.attrInt(_T("dockpositionrestrict"), 3);
				pWordDoc->m_strDocXml = m_Parse.xml();
			}
			else
			{
				auto it = m_mapTaskPaneMap.find((LONG)m_pActiveWordObject->m_hForm);
				if (it != m_mapTaskPaneMap.end())
				{
					it->second->put_Visible(false);
					m_mapTaskPaneMap.erase(it);
				}
			}
			m_pActiveWordObject->m_pWordPlusDoc->InitDocument();
		}

		void CWordAppObjEvents::OnEPostagePropertyDialog(_Document* Doc)
		{
			int nIndex = 0x0000000f;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("EPostagePropertyDialog"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnEPostageInsert(_Document* Doc)
		{
			int nIndex = 0x00000010;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("EPostageInsert"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeAfterMerge(_Document* Doc, Word::Document* DocResult)
		{
			int nIndex = 0x00000011;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeAfterMerge"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = (_Document*)DocResult;
					pObj->m_mapDisp[1]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeAfterRecordMerge(_Document* Doc)
		{
			int nIndex = 0x00000012;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeAfterRecordMerge"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeBeforeMerge(_Document* Doc, long StartRecord, long EndRecord, VARIANT_BOOL* Cancel)
		{
			int nIndex = 0x00000013;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeWizardStateChange"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_I4;
					var1.lVal = StartRecord;
					pObj->m_mapVar[0] = var1;
					CComVariant var2;
					var2.vt = VT_I4;
					var2.lVal = EndRecord;
					pObj->m_mapVar[1] = var2;
					CComVariant var3;
					var3.vt = VT_BOOL | VT_BYREF;
					var3.pboolVal = Cancel;
					pObj->m_mapVar[2] = var3;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeBeforeRecordMerge(_Document* Doc, VARIANT_BOOL* Cancel)
		{
			int nIndex = 0x00000014;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeBeforeRecordMerge"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var3;
					var3.vt = VT_BOOL | VT_BYREF;
					var3.pboolVal = Cancel;
					pObj->m_mapVar[0] = var3;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeDataSourceLoad(_Document* Doc) 
		{
			int nIndex = 0x00000015;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeDataSourceLoad"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeDataSourceValidate(_Document* Doc, VARIANT_BOOL* Handled) 
		{
			int nIndex = 0x00000016;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeDataSourceValidate"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var3;
					var3.vt = VT_BOOL | VT_BYREF;
					var3.pboolVal = Handled;
					pObj->m_mapVar[0] = var3;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeWizardSendToCustom(_Document* Doc)
		{
			int nIndex = 0x00000017;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeWizardSendToCustom"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnMailMergeWizardStateChange(_Document* Doc, int* FromState, int* ToState, VARIANT_BOOL* Handled) 
		{
			int nIndex = 0x00000018;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeWizardStateChange"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_INT|VT_BYREF;
					var1.pintVal = FromState;
					pObj->m_mapVar[0] = var1;
					CComVariant var2;
					var2.vt = VT_INT|VT_BYREF;
					var2.pintVal = ToState;
					pObj->m_mapVar[1] = var2;
					CComVariant var3;
					var3.vt = VT_BOOL | VT_BYREF;
					var3.pboolVal = Handled;
					pObj->m_mapVar[2] = var3;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents::OnWindowSize(_Document* Doc, Word::Window* Wn)
		{
			int nIndex = 0x00000019;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("WindowSize"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = Wn;
					pObj->m_mapDisp[1]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnXMLSelectionChange(Word::Selection* Sel, XMLNode* OldXMLNode, XMLNode* NewXMLNode, long* Reason)
		{
			int nIndex = 0x0000001a;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("XMLSelectionChange"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Sel;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = OldXMLNode;
					pObj->m_mapDisp[1]->AddRef();
					pObj->m_mapDisp[2] = NewXMLNode;
					pObj->m_mapDisp[2]->AddRef();
					CComVariant var1;
					var1.vt = VT_I4|VT_BYREF;
					var1.plVal = Reason;
					pObj->m_mapVar[0] = var1;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnXMLValidationError(XMLNode* XMLNode)
		{
			int nIndex = 0x0000001b;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("XMLValidationError"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = XMLNode;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnDocumentSync(_Document* Doc, MsoSyncEventType SyncEvent) 
		{
			int nIndex = 0x0000001c;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("DocumentSync"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_I4;
					var1.intVal = SyncEvent;
					pObj->m_mapVar[0] = var1;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnMailMergeDataSourceValidate2(_Document* Doc, VARIANT_BOOL* Handled)
		{
			int nIndex = 0x0000001e;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MailMergeDataSourceValidate2"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Doc;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Handled;
					pObj->m_mapVar[0] = var1;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnProtectedViewWindowOpen(ProtectedViewWindow* PvWindow) 
		{
			int nIndex = 0x0000001f;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ProtectedViewWindowOpen"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = PvWindow;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnProtectedViewWindowBeforeEdit(ProtectedViewWindow* PvWindow, VARIANT_BOOL* Cancel)
		{
			int nIndex = 0x00000020;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ProtectedViewWindowBeforeEdit"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = PvWindow;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[0] = var1;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnProtectedViewWindowBeforeClose(ProtectedViewWindow* PvWindow, int CloseReason, VARIANT_BOOL* Cancel)
		{
			int nIndex = 0x00000021;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ProtectedViewWindowBeforeClose"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = PvWindow;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var;
					var.vt = VT_INT;
					var.intVal = CloseReason;
					pObj->m_mapVar[0] = var;
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[1] = var1;
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnProtectedViewWindowSize(ProtectedViewWindow* PvWindow) 
		{
			int nIndex = 0x00000022;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ProtectedViewWindowSize"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = PvWindow;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnProtectedViewWindowActivate(ProtectedViewWindow* PvWindow) 
		{
			int nIndex = 0x00000023;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ProtectedViewWindowActivate"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = PvWindow;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void CWordAppObjEvents2::OnProtectedViewWindowDeactivate(ProtectedViewWindow* PvWindow)
		{
			int nIndex = 0x00000024;
			CWordAddin* pAddin = (CWordAddin*)g_pTangram;
			auto it2 = pAddin->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != pAddin->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ProtectedViewWindowDeactivate"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = PvWindow;
					pObj->m_mapDisp[0]->AddRef();
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		CWordAppCtrl::CWordAppCtrl()
		{

		}

		void CWordAppCtrl::OnFinalMessage(HWND hWnd)
		{
			__super::OnFinalMessage(hWnd);
		}

		STDMETHODIMP CWordAppCtrl::get_tag(VARIANT* pVal)
		{
			return S_OK;
		}


		STDMETHODIMP CWordAppCtrl::put_tag(VARIANT newVal)
		{
			return S_OK;
		}

		STDMETHODIMP CWordAppCtrl::put_AppCtrl(VARIANT_BOOL newVal)
		{
			g_pTangram->m_pTangramAppCtrl = this;

			return S_OK;
		}

		STDMETHODIMP CWordAppCtrl::get_HWND(LONGLONG* pVal)
		{
			*pVal = (LONGLONG)m_hWnd;
			return S_OK;
		}

		STDMETHODIMP CWordAppCtrl::get_Tangram(ITangram** pVal)
		{
			*pVal = g_pTangram;
			return S_OK;
		}
	}
}
