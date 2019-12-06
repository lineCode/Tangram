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
#include "../../Compositor.h"
#include "../../WndNode.h"
#include "Tangram.h"
#include "fm20.h"
#include "outlctl.h"
#include "OutLookAddin.h"
#include "OutLookplusEvents.cpp"
#include "OutLookCustomizeFormDlg.h"
#define SECURITY_WIN32
#include <Security.h>
#pragma comment(lib, "Secur32.lib") 
#include <winInet.h>

namespace OfficePlus
{
	namespace OutLookPlus
	{
		COutLookAddin::COutLookAddin()
		{
			m_strCurrentKey				= _T("");
			m_strDesignExplorerEntryID	= _T("");
			m_strDesignExplorerStoreID	= _T("");
			m_nGetClassDispID = -1;
			m_pCurOpenItem = nullptr;
			m_pTangramInspectorItems = nullptr;
			m_pOutLookAppObjEvents = nullptr;
			m_pOutLookAppObjEvents2 = nullptr;
			m_strDesignerToolBarCaption = _T("OutLook Designer");
		}

		COutLookAddin::~COutLookAddin()
		{
			if(m_pOutLookAppObjEvents)
				delete m_pOutLookAppObjEvents;
			if(m_pOutLookAppObjEvents2)
				delete m_pOutLookAppObjEvents2;
		}

		void COutLookAddin::OnQuit()
		{
			if (m_mapTangramEvent.size())
			{
				for (auto it : m_mapTangramEvent)
				{
					CTangramEventObj* pObj = it.second;
					delete pObj;
				}
				m_mapTangramEvent.clear();
			}
			if (m_hCBTHook)
				UnhookWindowsHookEx(m_hCBTHook);
			m_hCBTHook = nullptr;
			if (m_pCTPFactory)
				m_pCTPFactory.Detach();
			HRESULT hr = ((COutLookExplorersEvents*)this)->DispEventUnadvise(m_pExplorers);
			hr = ((COutLookInspectorsEvents*)this)->DispEventUnadvise(m_pInspectors);
			//HRESULT hr = ((COutLookApplicationEvents*)this)->DispEventUnadvise(m_pApplication);
			//hr = ((COutLookApplicationEvents_10*)this)->DispEventUnadvise(m_pApplication);
			hr = ((COutLookApplicationEvents_11*)this)->DispEventUnadvise(m_pApplication);
			if (m_pOutLookAppObjEvents)
				hr = m_pOutLookAppObjEvents->DispEventUnadvise(m_pApplication);
			if (m_pOutLookAppObjEvents2)
				hr = m_pOutLookAppObjEvents2->DispEventUnadvise(m_pApplication);
			//hr = ((COutLookStoresEvents_12*)this)->DispEventUnadvise(m_pStores);
			if (m_pTangramInspectorItems)
			{
				hr = m_pTangramInspectorItems->DispEventUnadvise(m_pTangramInspectorItems->m_pItems);
				m_pTangramInspectorItems->m_pItems->Release();
				delete m_pTangramInspectorItems;
			}

			if (g_pTangram->m_pExtender)
				g_pTangram->m_pExtender->Close();

			m_bCanClose = true;
			//m_nRef = 3;
		}

		void COutLookAddin::OnNewMailEx(BSTR EntryIDCollection)
		{
			int nIndex = 0x0000fab5;
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("NewMailEx"), nIndex, m_pApplication.p);

					CComVariant var1;
					var1.vt = VT_BSTR;
					var1.bstrVal = EntryIDCollection;
					pObj->m_mapVar[0] = var1;

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnAttachmentContextMenuDisplay(CommandBar* CommandBar, AttachmentSelection* Attachments) 
		{
			int nIndex = 0x0000fb3e;
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("AttachmentContextMenuDisplay"), nIndex, m_pApplication.p);

					pObj->m_mapDisp[0] = CommandBar;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = (_AttachmentSelection*)Attachments;
					pObj->m_mapDisp[1]->AddRef();

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnFolderContextMenuDisplay(CommandBar* CommandBar, OutLook::Folder* Folder) 
		{
			int nIndex = 0x0000fb42;
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("FolderContextMenuDisplay"), nIndex, m_pApplication.p);

					pObj->m_mapDisp[0] = CommandBar;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = (MAPIFolder*)Folder;
					pObj->m_mapDisp[1]->AddRef();

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnStoreContextMenuDisplay(CommandBar* CommandBar, Store* Store)
		{
			int nIndex = 0x0000fb43;
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("StoreContextMenuDisplay"), nIndex, m_pApplication.p);

					pObj->m_mapDisp[0] = CommandBar;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = (_Store*)Store;
					pObj->m_mapDisp[1]->AddRef();

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnShortcutContextMenuDisplay(CommandBar* CommandBar, OutlookBarShortcut* Shortcut) 
		{
			int nIndex = 0x0000fb44;
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ShortcutContextMenuDisplay"), nIndex, m_pApplication.p);

					pObj->m_mapDisp[0] = CommandBar;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = Shortcut;
					pObj->m_mapDisp[1]->AddRef();

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnViewContextMenuDisplay(CommandBar* CommandBar, OutLook::View* View)
		{
			int nIndex = 0x0000fb40;
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ViewContextMenuDisplay"), nIndex, m_pApplication.p);

					pObj->m_mapDisp[0] = CommandBar;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = View;
					pObj->m_mapDisp[1]->AddRef();

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnItemContextMenuDisplay(CommandBar* CommandBar, OutLook::Selection* Selection)
		{
			int nIndex = 0x0000fb41;
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ItemContextMenuDisplay"), nIndex, m_pApplication.p);
					pObj->m_mapDisp[0] = CommandBar;
					pObj->m_mapDisp[0]->AddRef();
					pObj->m_mapDisp[1] = Selection;
					pObj->m_mapDisp[1]->AddRef();

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnContextMenuClose(OlContextMenu ContextMenu) 
		{
			int nIndex = 0x0000fba6;
			//IDispatch* pDisp = nullptr;
			//m_pApplication->QueryInterface(IID_IDispatch, (void**)pDisp);
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ContextMenuClose"), nIndex, m_pApplication.p);

					CComVariant var1;
					var1.vt = VT_I4;
					var1.lVal = ContextMenu;
					pObj->m_mapVar[0] = var1;

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnItemLoad(IDispatch* pDisp)
		{
			CInspectorItem* pTangramInspectorItem = new CInspectorItem();
			m_mapTangramInspectorItem[(long)pTangramInspectorItem] = pTangramInspectorItem;
			pTangramInspectorItem->m_pItem = pDisp;
			HRESULT hr = ((COutLookItemEvents*)pTangramInspectorItem)->DispEventAdvise(pDisp);
			if (hr == S_OK)
			{
				pDisp->AddRef();
				//hr = ((COutLookItemEvents_10*)pTangramInspectorItem)->DispEventAdvise(pDisp);
				::PostMessage(m_hHostWnd, WM_TANGRAMITEMLOAD, (WPARAM)pTangramInspectorItem, 0);
			}
			else
			{
				delete pTangramInspectorItem;
			}
			int nIndex = 0x0000fba7;
			//IDispatch* pDisp2 = nullptr;
			//m_pApplication->QueryInterface(IID_IDispatch, (void**)pDisp2);
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ItemLoad"), nIndex, m_pApplication.p);

					pObj->m_mapDisp[0] = pDisp;
					pObj->m_mapDisp[0]->AddRef();

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::OnBeforeFolderSharingDialog(MAPIFolder* FolderToShare, VARIANT_BOOL* Cancel) 
		{
			int nIndex = 0x0000fc01;
			//IDispatch* pDisp = nullptr;
			//m_pApplication->QueryInterface(IID_IDispatch, (void**)pDisp);
			auto it2 = g_pTangram->m_mapObjEventDic.find(m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("BeforeFolderSharingDialog"), nIndex, m_pApplication.p);

					pObj->m_mapDisp[0] = FolderToShare;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[0] = var1;

					FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAddin::AddTangramPropertyToInspector(_Inspector* pInspector, CString strPropertyName, CString strInfoXml)
		{
			CComPtr<IDispatch> pItem;
			pInspector->get_CurrentItem(&pItem);
			if (pItem)
			{
				BSTR szMember = L"ItemProperties";
				DISPID dispid = -1;
				HRESULT hr = pItem->GetIDsOfNames(IID_NULL, &szMember, 1, LOCALE_USER_DEFAULT, &dispid);
				if (hr == S_OK)
				{
					DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
					VARIANT result = { 0 };
					EXCEPINFO excepInfo;
					memset(&excepInfo, 0, sizeof excepInfo);
					UINT nArgErr = (UINT)-1;
					HRESULT hr = pItem->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
					if (S_OK == hr && VT_DISPATCH == result.vt)
					{
						CComQIPtr<ItemProperties> pProperties(result.pdispVal);
						if(pProperties)
						{
							CComPtr<ItemProperty> pProperty;
							hr = pProperties->Item(CComVariant(strPropertyName), &pProperty);
							if (pProperty == nullptr)
							{
								hr = pProperties->Add(CComBSTR(strPropertyName), OlUserPropertyType::olText, CComVariant(NULL), CComVariant(NULL), &pProperty);
							}
							if(pProperty)
							{
								CComVariant var(strInfoXml);
								pProperty->put_Value(var);
								::VariantClear(&var);
							}
						}
					}
					::VariantClear(&result);
				}
			}
		}

		CString COutLookAddin::GetTangramPropertyFromInspector(_Inspector* pInspector, CString strPropertyName)
		{
			CComPtr<IDispatch> pItem;
			pInspector->get_CurrentItem(&pItem);
			if (pItem)
			{
				return GetTangramPropertyFromItem(pItem, strPropertyName);
			}
			return _T("");
		}

		CString COutLookAddin::GetTangramPropertyFromItem(IDispatch* pItem, CString strPropertyName)
		{
			CString strRet = _T("");
			if (pItem)
			{
				CComQIPtr<IDispatch> pDisp(pItem);
				if (pDisp == NULL)
					return _T("");
				BSTR szMember = L"ItemProperties";
				DISPID dispid = -1;
				HRESULT hr = pItem->GetIDsOfNames(IID_NULL, &szMember, 1, LOCALE_USER_DEFAULT, &dispid);
				if (hr == S_OK)
				{
					DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
					VARIANT result = { 0 };
					EXCEPINFO excepInfo;
					memset(&excepInfo, 0, sizeof excepInfo);
					UINT nArgErr = (UINT)-1;
					HRESULT hr = pItem->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
					if (S_OK == hr && VT_DISPATCH == result.vt)
					{
						CComQIPtr<ItemProperties> pProperties(result.pdispVal);
						if(pProperties)
						{
							CComPtr<ItemProperty> pProperty;
							hr = pProperties->Item(CComVariant(strPropertyName), &pProperty);
							if (hr == S_OK&&pProperty)
							{
								CComVariant var;
								pProperty->get_Value(&var);
								if (var.vt == VT_BSTR)
									strRet = OLE2T(var.bstrVal);
								::VariantClear(&var);
							}
						}
					}
					::VariantClear(&result);
				}
			}
			return strRet;
		}

		_Inspector* COutLookAddin::GetInspector(IDispatch* pDisp)
		{
			if (pDisp)
			{
				BSTR szMember = L"GetInspector";
				DISPID dispid = -1;
				HRESULT hr = pDisp->GetIDsOfNames(IID_NULL, &szMember, 1, LOCALE_USER_DEFAULT, &dispid);
				if (hr == S_OK)
				{
					DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
					VARIANT result = { 0 };
					EXCEPINFO excepInfo;
					memset(&excepInfo, 0, sizeof excepInfo);
					UINT nArgErr = (UINT)-1;
					HRESULT hr = pDisp->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
					if (S_OK == hr && VT_DISPATCH == result.vt)
					{
						CComQIPtr<_Inspector> pInspector(result.pdispVal);
						_Inspector* _pInspector = pInspector.p;
						_pInspector->AddRef();
						return _pInspector;
					}
				}
			}
			return nullptr;
		}

		CString COutLookAddin::GetPropertyFromItem(IDispatch* pItem, CString strPropertyName)
		{
			CString strRet = _T("");
			if (pItem)
			{
				BSTR szMember = strPropertyName.AllocSysString();
				DISPID dispid = -1;
				HRESULT hr = pItem->GetIDsOfNames(IID_NULL, &szMember, 1, LOCALE_USER_DEFAULT, &dispid);
				if (hr == S_OK)
				{
					DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
					VARIANT result = { 0 };
					EXCEPINFO excepInfo;
					memset(&excepInfo, 0, sizeof excepInfo);
					UINT nArgErr = (UINT)-1;
					HRESULT hr = pItem->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
					if (S_OK == hr && VT_BSTR == result.vt)
					{
						strRet = OLE2T(result.bstrVal);
					}
					::VariantClear(&result);
				}
			}
			return strRet;
		}

		CString COutLookAddin::GetPropertyFromInspector(_Inspector* pInspector, CString strPropertyName)
		{
			CComPtr<IDispatch> pItem;
			pInspector->get_CurrentItem(&pItem);
			if (pItem)
			{
				return GetPropertyFromItem(pItem, strPropertyName);
			}
			return _T("");
		}

		void COutLookAddin::WriteFolderPropertyToStore(MAPIFolder* _pFolder,CString strSubject, CString strPropertyName, CString strData)
		{
			structured_task_group tasks;
			IStream* pStream = 0;
			HRESULT hr = ::CoMarshalInterThreadInterfaceInStream(IID_MAPIFolder, _pFolder, &pStream);
			auto task = make_task([&pStream, &strSubject, &strPropertyName, &strData]()
			{
				CoInitializeEx(NULL, COINIT_MULTITHREADED);
				if (pStream)
				{
					MAPIFolder* pFolder = nullptr;
					HRESULT hr = ::CoGetInterfaceAndReleaseStream(pStream, IID_MAPIFolder, (LPVOID *)&pFolder);
					if (hr == S_OK&&pFolder)
					{
						CComPtr<OutLook::_StorageItem> pStoreItem;
						hr = pFolder->GetStorage(CComBSTR(strSubject), olIdentifyBySubject, &pStoreItem);
						if (pStoreItem)
						{
							long nSize = 0;
							pStoreItem->get_Size(&nSize);
							CComPtr<OutLook::UserProperties> pUserProperties;
							pStoreItem->get_UserProperties(&pUserProperties);
							CComPtr<OutLook::UserProperty> pUserProperty;
							if (nSize == 0)
							{
								pUserProperties->Add(CComBSTR(strPropertyName), olText, CComVariant(false), CComVariant((int)OlFormatText::olFormatTextText), &pUserProperty);
							}
							else
							{
								pUserProperties->Item(CComVariant(strPropertyName), &pUserProperty);
							}
							if (pUserProperty)
							{
								pUserProperty->put_Value(CComVariant(strData));
								pStoreItem->Save();
							}
						}
					}
				}
				CoUninitialize();
			});
			tasks.run(task);
			//tasks.run_and_wait(task);

			//if (pFolder)
			//{
			//	CComPtr<OutLook::_StorageItem> pStoreItem;
			//	pFolder->GetStorage(CComBSTR(strSubject), olIdentifyBySubject, &pStoreItem);
			//	if (pStoreItem)
			//	{
			//		long nSize = 0;
			//		pStoreItem->get_Size(&nSize);
			//		CComPtr<OutLook::UserProperties> pUserProperties;
			//		pStoreItem->get_UserProperties(&pUserProperties);
			//		CComPtr<OutLook::UserProperty> pUserProperty;
			//		if (nSize == 0)
			//		{
			//			pUserProperties->Add(CComBSTR(strPropertyName), olText, CComVariant(false), CComVariant((int)OlFormatText::olFormatTextText), &pUserProperty);
			//		}
			//		else
			//		{
			//			pUserProperties->Item(CComVariant(strPropertyName), &pUserProperty);
			//		}
			//		if (pUserProperty)
			//		{
			//			pUserProperty->put_Value(CComVariant(strData));
			//			pStoreItem->Save();
			//		}
			//	}
			//}
		}

		CString COutLookAddin::GetFolderPropertyFromStore(MAPIFolder* _pFolder,CString strSubject, CString strPropertyName)
		{
			CString strRet = _T("");
			Concurrency::structured_task_group tasks;
			IStream* pStream = 0;
			HRESULT hr = ::CoMarshalInterThreadInterfaceInStream(IID_MAPIFolder, _pFolder, &pStream);
			auto task = make_task([&pStream, &strSubject, &strPropertyName, &strRet]()
			{
				//CoInitializeEx(NULL, COINIT_MULTITHREADED);
				if (pStream)
				{
					MAPIFolder* pFolder = nullptr;
					HRESULT hr = ::CoGetInterfaceAndReleaseStream(pStream, IID_MAPIFolder, (LPVOID *)&pFolder);
					if (hr == S_OK&&pFolder)
					{
						CComPtr<OutLook::_StorageItem> pStoreItem;
						hr = pFolder->GetStorage(CComBSTR(strSubject), olIdentifyBySubject, &pStoreItem);
						if (pStoreItem)
						{
							long nSize = 0;
							pStoreItem->get_Size(&nSize);
							CComPtr<OutLook::UserProperties> pUserProperties;
							pStoreItem->get_UserProperties(&pUserProperties);
							CComPtr<OutLook::UserProperty> pUserProperty;
							if (nSize)
							{
								pUserProperties->Item(CComVariant(strPropertyName), &pUserProperty);
							}
							if (pUserProperty)
							{
								CComVariant m_v;
								pUserProperty->get_Value(&m_v);
								USES_CONVERSION;
								strRet = OLE2T(m_v.bstrVal);
							}
						}
					}
				}
				//CoUninitialize();
			});

			tasks.run_and_wait(task);
			//CString strRet = _T("");
			//if (pFolder)
			//{
			//	CComPtr<OutLook::_StorageItem> pStoreItem;
			//	pFolder->GetStorage(CComBSTR(strSubject), olIdentifyBySubject, &pStoreItem);
			//	if (pStoreItem)
			//	{
			//		long nSize = 0;
			//		pStoreItem->get_Size(&nSize);
			//		CComPtr<OutLook::UserProperties> pUserProperties;
			//		pStoreItem->get_UserProperties(&pUserProperties);
			//		CComPtr<OutLook::UserProperty> pUserProperty;
			//		if (nSize == 0)
			//		{
			//			//return strRet;
			//		}
			//		else
			//		{
			//			pUserProperties->Item(CComVariant(strPropertyName), &pUserProperty);
			//		}
			//		if (pUserProperty)
			//		{
			//			CComVariant m_v;
			//			pUserProperty->get_Value(&m_v);
			//			strRet = OLE2T(m_v.bstrVal);
			//		}
			//	}
			//}
			return strRet;
		}

		void COutLookAddin::AddFormPageToInspector(_Inspector* pInspector, CString strPageName, CString strInfoXml, BOOL bShowInSpector, BOOL bSetCurrentPage)
		{
			if (strPageName == _T(""))
				strPageName = _T("Tangram");
			if (pInspector)
			{
				OutLook::Pages* pPages = nullptr;
				pInspector->get_ModifiedFormPages((IDispatch**)&pPages);
				if (pPages)
				{
					CComPtr<IDispatch> pCompositorManager;
					CComPtr<IDispatch> pItem;
					CComVariant vName(strPageName);
					pPages->Item(vName, &pItem);
					if (pItem == nullptr)
					{
						HRESULT hr = pPages->Add(vName, &pCompositorManager);
						if (pCompositorManager)
						{
							::VariantClear(&vName);
							BSTR bstrPageName = strPageName.AllocSysString();
							if(bShowInSpector)
								hr = pInspector->ShowFormPage(bstrPageName);
							if(bSetCurrentPage)
								hr = pInspector->SetCurrentFormPage(bstrPageName);

							AddTangramPropertyToInspector(pInspector, strPageName, strInfoXml);
						}
					}
				}
			}
		}

		STDMETHODIMP COutLookAddin::AttachObjEvent(IDispatch* pDisp, int nEventIndex)
		{
			CComQIPtr<OutLook::_Application> pApplication(pDisp);
			if (pApplication)
			{
				if (0x0000f002 <= nEventIndex&&nEventIndex <= 0x0000f007)
				{
					if (m_pOutLookAppObjEvents == nullptr)
					{
						m_pOutLookAppObjEvents = new COutLookAppObjEvents();
						m_pOutLookAppObjEvents->DispEventAdvise(m_pApplication);
					}
				}
				else if (0x0000fa6a <= nEventIndex&&nEventIndex <= 0x0000fa90)
				{
					if (m_pOutLookAppObjEvents2 == nullptr)
					{
						m_pOutLookAppObjEvents2 = new COutLookAppObjEvents2();
						m_pOutLookAppObjEvents2->DispEventAdvise(m_pApplication);
					}
				}
			}
			return CTangram::AttachObjEvent(pDisp, nEventIndex);
		}

		STDMETHODIMP COutLookAddin::TangramCommand(IDispatch* RibbonControl)
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
			HWND hWnd = ::GetActiveWindow();
			CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
			auto it = m_mapInspector.find(hWnd);
			if (it != m_mapInspector.end())
			{
				it->second->TangramCommand(nCmdIndex);
				pObj->Init(_T("OutLookInspector"), 0, it->second->m_pInspector);
			}
			else
			{
				auto it = m_mapOutLookPlusExplorerMap.find(hWnd);
				if (it != m_mapOutLookPlusExplorerMap.end())
				{
					it->second->TangramCommand(nCmdIndex);
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("OutLookExplorer"), 0, it->second->m_pExplorer.p);
				}
			}
			pObj->m_mapVar[0] = CComVariant(bstrID);
			pObj->m_mapVar[1] = CComVariant(bstrTag);
			FireTangramAppEvent(pObj);
			return S_OK;
		}

		HRESULT COutLookAddin::OnConnection(IDispatch* pHostApp, int ConnectMode)
		{
			if (m_pApplication)
				return S_OK;
			COfficeAddin::OnConnection(pHostApp, ConnectMode);
			pHostApp->QueryInterface(__uuidof(IDispatch), (LPVOID*)&m_pApplication);

			::PostMessage(m_hHostWnd, WM_INITOUTLOOK, 0, 0);

			return S_OK;
		}

		void COutLookAddin::InitOutLook()
		{
			CTangramXmlParse m_Parse;
			if (m_Parse.LoadXml(m_strConfigFile) || m_Parse.LoadFile(m_strConfigFile))
			{
				CTangramXmlParse* pUIParse = m_Parse.GetChild(_T("OutLookUI"));
				if (pUIParse)
				{
					int nCount = pUIParse->GetCount();
					for (int i = 0; i < nCount; i++)
					{
						CTangramXmlParse* pChild = pUIParse->GetChild(i);
						m_mapUIXML[pChild->name()] = pChild->xml();
					}
				}
				CString strItems = m_Parse.attr(_T("OutLookItems"), _T(""));
				if (strItems != _T(""))
				{
					int nPos = strItems.Find(_T(","));
					int nIndex = 1;
					while (nPos != -1)
					{
						m_mapItemName[nIndex] = strItems.Left(nPos);
						nIndex++;
						strItems = strItems.Mid(nPos + 1);
						nPos = strItems.Find(_T(","));
					}
				}
			}
			wchar_t user[256] = { 0 };
			ULONG size = _countof(user);
			if (!GetUserNameEx(NameDisplay, user, &size))
			{
				// GetUserNameEx may fail (for example on Home editions). use the login name
				size = _countof(user);
				GetUserName(user, &size);
			}
			m_strUser = user;
			CComPtr<OutLook::_NameSpace> pSession;
			m_pApplication->get_Session(&pSession);
			pSession->get_Stores(&m_pStores);
			long nCount;
			m_pStores->get_Count(&nCount);
			::PostMessage(m_hHostWnd, WM_TANGRAMMSG, 0, 0);
			//HRESULT hr = ((COutLookApplicationEvents*)this)->DispEventAdvise(m_pApplication);
			//hr = ((COutLookApplicationEvents_10*)this)->DispEventAdvise(m_pApplication);
			HRESULT hr = ((COutLookApplicationEvents_11*)this)->DispEventAdvise(m_pApplication);
			//hr = ((COutLookStoresEvents_12*)this)->DispEventAdvise(m_pStores);
			if (m_pOutLookAppObjEvents)
				m_pOutLookAppObjEvents->DispEventAdvise(m_pApplication);
			if (m_pOutLookAppObjEvents2)
				m_pOutLookAppObjEvents2->DispEventAdvise(m_pApplication);
			m_pApplication->get_Explorers(&m_pExplorers);
			if (m_pExplorers)
			{
				hr = ((COutLookExplorersEvents*)this)->DispEventAdvise(m_pExplorers);
				m_pApplication->get_Inspectors(&m_pInspectors);
				hr = ((COutLookInspectorsEvents*)this)->DispEventAdvise(m_pInspectors);
			}
			HWND hWnd = ::GetActiveWindow();
			HWND _hWnd = hWnd;
			hr = S_OK;
			CComPtr<IDispatch> pDisp;
			m_pApplication->ActiveWindow(&pDisp);
			if (pDisp)
			{
				CComQIPtr<_Explorer> pExplorer(pDisp);
				if (pExplorer)
				{
					m_strCurrentKey = _T("Microsoft.Outlook.Explorer");
					COutLookExplorer* pOutlookExplorer = new COutLookExplorer();
					pOutlookExplorer->m_strKey = m_strCurrentKey;
					m_mapOutLookPlusExplorerMap[hWnd] = pOutlookExplorer;
					pOutlookExplorer->m_pExplorer = pExplorer;
					pOutlookExplorer->m_hWnd = _hWnd;
					m_pActiveOutlookExplorer = pOutlookExplorer;
					if (pOutlookExplorer->m_pExplorer)
					{
						HRESULT hr = ((COutLookExplorerEvents*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pExplorer);
						hr = ((COutLookExplorerEvents_10*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pExplorer);
						if (m_nVer > 0x000f)
						{
							hr = pOutlookExplorer->m_pExplorer->get_AccountSelector(&pOutlookExplorer->m_pAccountSelector);
							if (hr == S_OK)
							{
								pOutlookExplorer->m_pAccountSelector->AddRef();
								hr = ((COutLookAccountSelectorEvents*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pAccountSelector);
							}
						}
						pOutlookExplorer->m_pExplorer->get_NavigationPane(&pOutlookExplorer->m_pNavigationPane);
						hr = ((COutLookNavigationPaneEvents_12*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pNavigationPane);
						hr = pOutlookExplorer->m_pNavigationPane->get_CurrentModule(&pOutlookExplorer->m_pCurrentModule);
						if (hr == S_OK)
						{
							pOutlookExplorer->m_pCurrentModule->AddRef();

							pOutlookExplorer->m_pCurrentModule->get_NavigationModuleType(&pOutlookExplorer->m_nNType);
							CComBSTR bstrName("");
							switch (pOutlookExplorer->m_nNType)
							{
							case olModuleMail:
							{
								CComQIPtr<_MailModule> _pModule(pOutlookExplorer->m_pCurrentModule);
								_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
							}
							break;
							case olModuleCalendar:
							{
								CComQIPtr<_CalendarModule> _pModule(pOutlookExplorer->m_pCurrentModule);
								_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
							}
							break;
							case olModuleContacts:
							{
								CComQIPtr<_ContactsModule> _pModule(pOutlookExplorer->m_pCurrentModule);
								_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
							}
							break;
							case olModuleTasks:
							{
								CComQIPtr<_TasksModule> _pModule(pOutlookExplorer->m_pCurrentModule);
								_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
							}
							break;
							case olModuleJournal:
							{
								CComQIPtr<_JournalModule> _pModule(pOutlookExplorer->m_pCurrentModule);
								_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
							}
							break;
							case olModuleNotes:
							{
								CComQIPtr<_NotesModule> _pModule(pOutlookExplorer->m_pCurrentModule);
								_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
							}
							break;
							case olModuleFolderList:
							case olModuleShortcuts:
							case olModuleSolutions:
								break;
							}
							if (pOutlookExplorer->m_pNavigationGroups)
							{
								pOutlookExplorer->m_pNavigationGroups->AddRef();
								hr = ((COutLookNavigationGroupsEvents_12*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pNavigationGroups);
							}
						}
					}
				}
				else
				{
					CComQIPtr<_Inspector> pInspector(pDisp);
					if (pInspector&&m_hWwbWnd)
					{
						IDispatch* pDisp;
						pInspector->get_CurrentItem(&pDisp);
						COutLookInspector* pOutLookPlusItemWindow = nullptr;
						CComQIPtr<_MailItem> m_pMailItem(pDisp);
						pOutLookPlusItemWindow = new COutLookInspector();
						pOutLookPlusItemWindow->m_strKey = m_strCurrentKey;
						m_pCurOpenItem = pOutLookPlusItemWindow;
						hr = ((COutLookInspectorEvents*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
						hr = ((COutLookInspectorEvents_10*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
						hr = ((COutLookItemEvents*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
						//hr = ((COutLookItemEvents_10*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
						pOutLookPlusItemWindow->m_pDisp = pDisp;
						pOutLookPlusItemWindow->m_hWnd = ::GetParent(::GetParent(::GetParent(m_hPWwbWnd)));
						pOutLookPlusItemWindow->m_hHostWnd = ::GetParent(pOutLookPlusItemWindow->m_hWnd);
						m_hWwbWnd = nullptr;
						m_hPWwbWnd = NULL;
						//hWnd = ::FindWindowEx(hWnd, NULL, _T("AfxWndW"), NULL);
						//if (hWnd)
						//{
						//	hWnd = ::FindWindowEx(hWnd, NULL, _T("AfxWndW"), NULL);
						//	CWindow m_Wnd;
						//	m_Wnd.Attach(hWnd);
						//	hWnd = m_Wnd.GetWindow(GW_CHILD).m_hWnd;
						//	m_Wnd.Detach();
						//	hWnd = ::GetDlgItem(hWnd, 0x0103f);
						//	m_hWwbWnd = ::FindWindowEx(hWnd, NULL, _T("_WwB"), NULL);
						//	//pOutLookPlusItemWindow->AddRef();

						//	m_hPWwbWnd = NULL;
						//}
					}
					//if (pInspector)
					//{
					//	IDispatch* pDisp;
					//	pInspector->get_CurrentItem(&pDisp);
					//	COutLookInspector* pOutLookPlusItemWindow = nullptr;
					//	CComQIPtr<_MailItem> m_pMailItem(pDisp);
					//	hWnd = ::FindWindowEx(hWnd, NULL, _T("AfxWndW"), NULL);
					//	if (hWnd)
					//	{
					//		hWnd = ::FindWindowEx(hWnd, NULL, _T("AfxWndW"), NULL);
					//		CWindow m_Wnd;
					//		m_Wnd.Attach(hWnd);
					//		hWnd = m_Wnd.GetWindow(GW_CHILD).m_hWnd;
					//		m_Wnd.Detach();
					//		hWnd = ::GetDlgItem(hWnd, 0x0103f);
					//		m_hWwbWnd = ::FindWindowEx(hWnd, NULL, _T("_WwB"), NULL);
					//		pOutLookPlusItemWindow = new COutLookInspector();
					//		pOutLookPlusItemWindow->m_strKey = m_strCurrentKey;
					//		m_pCurOpenItem = pOutLookPlusItemWindow;
					//		hr = ((COutLookInspectorEvents*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
					//		hr = ((COutLookInspectorEvents_10*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
					//		hr = ((COutLookItemEvents*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
					//		//hr = ((COutLookItemEvents_10*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
					//		pOutLookPlusItemWindow->m_pDisp = pDisp;
					//		//pOutLookPlusItemWindow->AddRef();

					//		m_hPWwbWnd = NULL;
					//	}
					//}
				}
			}
		}

		HRESULT COutLookAddin::OnDisconnection(int DisConnectMode)
		{
			//((COutLookExplorersEvents*)this)->DispEventUnadvise(m_pExplorers);
			//((COutLookInspectorsEvents*)this)->DispEventUnadvise(m_pInspectors);
			////HRESULT hr = ((COutLookApplicationEvents*)this)->DispEventUnadvise(m_pApplication);
			////hr = ((COutLookApplicationEvents_10*)this)->DispEventUnadvise(m_pApplication);
			//HRESULT hr = ((COutLookApplicationEvents_11*)this)->DispEventUnadvise(m_pApplication);
			//if (m_pOutLookAppObjEvents)
			//	m_pOutLookAppObjEvents->DispEventUnadvise(m_pApplication);
			//if (m_pOutLookAppObjEvents2)
			//	m_pOutLookAppObjEvents2->DispEventUnadvise(m_pApplication);
			////hr = ((COutLookStoresEvents_12*)this)->DispEventUnadvise(m_pStores);
			//if (m_pTangramInspectorItems)
			//{
			//	m_pTangramInspectorItems->DispEventUnadvise(m_pTangramInspectorItems->m_pItems);
			//	m_pTangramInspectorItems->m_pItems->Release();
			//	delete m_pTangramInspectorItems;
			//}
			//m_pApplication.p->Release();
			//m_pApplication.Detach();

			//if (theApp.m_pEventTypeInfo)
			//{
			//	ITypeInfo* pDisp = theApp.m_pEventTypeInfo.Detach();
			//	DWORD dw = pDisp->Release();
			//	theApp.m_pEventTypeInfo = nullptr;
			//}
			//if (theApp.m_pExtender)
			//	theApp.m_pExtender->Close();

			//m_bCanClose = true;
			//m_nRef = 6;
			//theApp.ExitInstance();
			return S_OK;
		}

		HRESULT COutLookAddin::CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv)
		{
			return COutLookAppCtrl::_CreatorClass::CreateInstance(pv, riid, ppv);
		}

		CString COutLookAddin::ExportTangramData()
		{
			CString strRet = _T("");
			CComPtr<OutLook::_NameSpace> pNameSpace;
			m_pApplication->get_Session(&pNameSpace);
			if (pNameSpace)
			{
				CComPtr<_Store> pDefaultStore;
				pNameSpace->get_DefaultStore(&pDefaultStore);
				CComPtr<_Stores> pStores;
				pNameSpace->get_Stores(&pStores);
				if (pStores)
				{
					long nCount = -1;
					pStores->get_Count(&nCount);
					if (nCount)
					{
						for (int i = 1; i <= nCount; i++)
						{
							CComVariant index(i);
							CComPtr<_Store> pStore;
							pStores->Item(index, &pStore);
							if (pStore)
							{
								CComPtr<MAPIFolder> pRootFolder;
								pStore->GetRootFolder(&pRootFolder);
								if (pRootFolder)
								{
									CComPtr<_Folders> pFolders;
									pRootFolder->get_Folders(&pFolders);
								}
							}
						}
					}
				}
			}
			return strRet;
		}

		CString COutLookAddin::GetDefaultFolderXml(_Store* pStore, OlDefaultFolders m_folderenum)
		{
			CString strData = _T("");
			CComPtr<MAPIFolder> pDefaultFolder;
			pStore->GetDefaultFolder(m_folderenum, &pDefaultFolder);
			if (pDefaultFolder)
			{
				CComBSTR bstrEntryID(L"");
				pDefaultFolder->get_EntryID(&bstrEntryID);
				CString strKey = OLE2T(bstrEntryID);
				strData.Format(_T("<Tangram%s><FolderType>%d</FolderType></Tangram%s>"), strKey, m_folderenum, strKey);
			}
			return strData;
		}

		STDMETHODIMP COutLookAddin::GetCustomUI(BSTR RibbonID, BSTR* RibbonXml)
		{
			/*
			Microsoft.Outlook.Explorer
			Microsoft.Outlook.Mail.Read
			Microsoft.Outlook.Mail.Compose
			Microsoft.Outlook.MeetingRequest.Read
			Microsoft.Outlook.MeetingRequest.Send
			Microsoft.Outlook.Appointment
			Microsoft.Outlook.Contact
			Microsoft.Outlook.Journal
			Microsoft.Outlook.Task
			Microsoft.Outlook.DistributionList
			Microsoft.Outlook.Report
			Microsoft.Outlook.Resend
			Microsoft.Outlook.Post.Read
			Microsoft.Outlook.Post.Compose
			Microsoft.Outlook.Sharing.Read
			Microsoft.Outlook.Sharing.Compose

			enum OlItemType
			{
			olMailItem = 0,
			olAppointmentItem = 1,
			olContactItem = 2,
			olTaskItem = 3,
			olJournalItem = 4,
			olNoteItem = 5,
			olPostItem = 6,
			olDistributionListItem = 7,
			olMobileItemSMS = 11,
			olMobileItemMMS = 12
			};
			*/
			CString strRet = _T("");
			m_strCurrentKey = OLE2T(RibbonID);
			auto it = m_mapUIXML.find(m_strCurrentKey);
			if (it != m_mapUIXML.end())
			{
				CString strXml = it->second;
				int nPos = strXml.Find(_T("<customUI"));
				if (nPos != -1)
				{
					strRet = strXml.Mid(nPos);
					nPos = strRet.Find(_T("</customUI>"));
					if (nPos != -1)
					{
						strRet = strRet.Left(nPos + 11);
					}
				}
			}

			if (strRet != _T(""))
			{
				*RibbonXml = strRet.AllocSysString();
				return S_OK;
			}

			return E_POINTER;
		}

		void COutLookAddin::WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd)
		{
			if (strClassName == _T("_WwB"))
			{
				if (::GetWindowLongPtr(hPWnd, GWLP_ID) == 0x00103f)
				{
					m_hWwbWnd = hWnd;
					m_hPWwbWnd = hPWnd;
					if (m_pCurOpenItem)
					{
						m_pCurOpenItem->m_hWnd = ::GetParent(::GetParent(::GetParent(m_hPWwbWnd)));
						m_pCurOpenItem->m_hHostWnd = ::GetParent(m_pCurOpenItem->m_hWnd);
						//auto it = m_mapOutLookPlusExplorerMap.find(m_pCurOpenItem->m_hHostWnd);
						//if (it == m_mapOutLookPlusExplorerMap.end())
						//{
						//	auto it2 = m_mapInspector.find(m_pCurOpenItem->m_hHostWnd);
						//	if (it2 == m_mapInspector.end())
						//	{
						//		m_mapInspector[m_pCurOpenItem->m_hHostWnd] = m_pCurOpenItem;
						//	}
						//}
					}
				}
				//::PostMessage(m_hHostWnd, WM_OFFICEOBJECTCREATED, (WPARAM)hWnd, 0);
			}
		}

		void COutLookAddin::WindowDestroy(HWND hWnd)
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
			//else
			//{
			//	//OnCloseOfficeObj(strClassName, hWnd);
			//}
		}

		//void COutLookAddin::OnBeforeStoreRemove(_Store* Store, VARIANT_BOOL* Cancel)
		//{
		//}

		//void COutLookAddin::OnStoreAdd(_Store* Store)
		//{
		//}

		//begin COutLookExplorersEvents:
		void COutLookAddin::OnNewExplorer(_Explorer* Explorer)
		{
			COutLookExplorer* pOutlookExplorer = new COutLookExplorer();
			pOutlookExplorer->m_pExplorer.Attach(Explorer);
			Explorer->AddRef();
			pOutlookExplorer->m_strKey = _T("Microsoft.Outlook.Explorer");
			m_pActiveOutlookExplorer = pOutlookExplorer;

			HRESULT hr = ((COutLookExplorerEvents*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pExplorer);
			hr = ((COutLookExplorerEvents_10*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pExplorer);
			pOutlookExplorer->m_pExplorer->get_NavigationPane(&pOutlookExplorer->m_pNavigationPane);
			if (pOutlookExplorer->m_pNavigationPane)
			{
				hr = ((COutLookNavigationPaneEvents_12*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pNavigationPane);
				hr = pOutlookExplorer->m_pNavigationPane->get_CurrentModule(&pOutlookExplorer->m_pCurrentModule);
				if (hr == S_OK)
				{
					pOutlookExplorer->m_pCurrentModule->AddRef();
					pOutlookExplorer->m_pCurrentModule->get_NavigationModuleType(&pOutlookExplorer->m_nNType);
					CComBSTR bstrName("");
					switch (pOutlookExplorer->m_nNType)
					{
					case olModuleMail:
					{
						CComQIPtr<_MailModule> _pModule(pOutlookExplorer->m_pCurrentModule);
						_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
					}
					break;
					case olModuleCalendar:
					{
						CComQIPtr<_CalendarModule> _pModule(pOutlookExplorer->m_pCurrentModule);
						_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
					}
					break;
					case olModuleContacts:
					{
						CComQIPtr<_ContactsModule> _pModule(pOutlookExplorer->m_pCurrentModule);
						_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
					}
					break;
					case olModuleTasks:
					{
						CComQIPtr<_TasksModule> _pModule(pOutlookExplorer->m_pCurrentModule);
						_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
					}
					break;
					case olModuleJournal:
					{
						CComQIPtr<_JournalModule> _pModule(pOutlookExplorer->m_pCurrentModule);
						_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
					}
					break;
					case olModuleNotes:
					{
						CComQIPtr<_NotesModule> _pModule(pOutlookExplorer->m_pCurrentModule);
						_pModule->get_NavigationGroups(&pOutlookExplorer->m_pNavigationGroups);
					}
					break;
					case olModuleFolderList:
					case olModuleShortcuts:
						break;
					case olModuleSolutions:
					{
						CComQIPtr<_SolutionsModule> _pModule(pOutlookExplorer->m_pCurrentModule);
						VARIANT_BOOL bVisible;
						_pModule->get_Visible(&bVisible);
						if (bVisible == false)
						{
							_pModule->put_Visible(true);
						}
						else
						{
						}
					}
					break;
					}
					if (pOutlookExplorer->m_nNType == olModuleSolutions)
					{
						//if (pOutlookExplorer->m_hNavWnd&&theApp.m_pSolutionFrame)
						//{
						//	if (theApp.m_pSolutionHelperWnd&&::IsWindow(theApp.m_pSolutionHelperWnd->m_hWnd))
						//		::ShowWindow(theApp.m_pSolutionHelperWnd->m_hWnd, SW_SHOW);
						//	if (pOutlookExplorer->m_hButton)
						//		::ShowWindow(pOutlookExplorer->m_hButton, SW_HIDE);
						//	theApp.m_pSolutionFrame->Attach();
						//}
					}
					else
					{
						//if (pOutlookExplorer->m_hNavWnd&&theApp.m_pSolutionFrame)
						//{
						//	if (theApp.m_pSolutionHelperWnd&&::IsWindow(theApp.m_pSolutionHelperWnd->m_hWnd))
						//		::ShowWindow(theApp.m_pSolutionHelperWnd->m_hWnd, SW_HIDE);
						//	if (pOutlookExplorer->m_hButton)
						//		::ShowWindow(pOutlookExplorer->m_hButton, SW_SHOW);
						//	theApp.m_pSolutionFrame->Deatch();
						//}
					}
					if (pOutlookExplorer->m_pNavigationGroups)
					{
						pOutlookExplorer->m_pNavigationGroups->AddRef();
						hr = ((COutLookNavigationGroupsEvents_12*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pNavigationGroups);
					}
				}
			}

			if (m_nVer>0x000f)
			{
				hr = pOutlookExplorer->m_pExplorer->get_AccountSelector(&pOutlookExplorer->m_pAccountSelector);
				if (hr == S_OK)
				{
					pOutlookExplorer->m_pAccountSelector->AddRef();
					hr = ((COutLookAccountSelectorEvents*)pOutlookExplorer)->DispEventAdvise(pOutlookExplorer->m_pAccountSelector);
				}
			}
			::PostMessage(m_hHostWnd, WM_TANGRAMNEWOUTLOOKOBJ, 1, (LPARAM)pOutlookExplorer);

			CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
			pObj->Init(_T("NewExplorer"), 0x0000f001, m_pApplication.p);
			pObj->m_mapDisp[0] = Explorer;
			pObj->m_mapDisp[0]->AddRef();

			FireTangramAppEvent(pObj);
		}
		//end COutLookExplorersEvents

		//begin COutLookInspectorsEvents:
		void COutLookAddin::OnNewInspector(_Inspector* Inspector)
		{
			IDispatch* pDisp;
			Inspector->get_CurrentItem(&pDisp);
			COutLookInspector* pOutLookPlusItemWindow = new COutLookInspector();
			BSTR szMember = ::SysAllocString(L"Class");
			HRESULT hr = S_OK;
			if (m_nGetClassDispID == -1)
			{
				hr = pDisp->GetIDsOfNames(IID_NULL, &szMember, 1, LOCALE_USER_DEFAULT, &m_nGetClassDispID);
			}
			if (pDisp&&m_nGetClassDispID!=-1)
			{
				DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
				VARIANT result = { 0 };
				EXCEPINFO excepInfo;
				memset(&excepInfo, 0, sizeof excepInfo);
				UINT nArgErr = (UINT)-1;
				hr = pDisp->Invoke(m_nGetClassDispID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
				if (S_OK == hr )
				{
					pOutLookPlusItemWindow->m_OlObjectClass = (OlObjectClass)result.intVal;
				}
				::VariantClear(&result);
			}
			::SysFreeString(szMember);

			m_pCurOpenItem = pOutLookPlusItemWindow;
			pOutLookPlusItemWindow->m_pInspector = Inspector;
			pOutLookPlusItemWindow->m_pInspector->AddRef();
			hr = ((COutLookItemEvents*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
			hr = ((COutLookInspectorEvents*)pOutLookPlusItemWindow)->DispEventAdvise(Inspector);
			hr = ((COutLookInspectorEvents_10*)pOutLookPlusItemWindow)->DispEventAdvise(Inspector);
			//hr = ((COutLookItemEvents_10*)pOutLookPlusItemWindow)->DispEventAdvise(pDisp);
			pOutLookPlusItemWindow->m_pDisp = pDisp;

			CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
			pObj->Init(_T("NewInspector"), 0x0000f001, m_pApplication.p);
			pObj->m_mapDisp[0] = Inspector;
			pObj->m_mapDisp[0]->AddRef();

			FireTangramAppEvent(pObj);
		}
		//end COutLookInspectorsEvents

		//New COutLookExplorer Object:
		COutLookExplorer::COutLookExplorer(void)
		{
			m_hWnd = NULL;
			m_strKey = _T("");
			m_hTaskPaneWnd				= NULL;
			m_hTaskPaneChildWnd			= NULL;
			m_hOutLookToday				= NULL;
			m_hTaskPane					= NULL;
			m_pTaskPane					= nullptr;
			m_pModuleDisp				= nullptr;
			m_pOnlineItem				= nullptr;
			m_pCurrentModule			= nullptr;
			m_pAccountSelector			= nullptr;
			m_pNavigationGroups			= nullptr;

			m_pCompositorManager						= nullptr;
			m_pCompositor					= nullptr;
			m_pNewFolder				= nullptr;
			m_pTaskPaneCompositorManager				= nullptr;
			m_pTaskPaneCompositor			= nullptr;
			m_pInspectorContainerWnd	= nullptr;
		}

		COutLookExplorer::~COutLookExplorer(void)
		{
		}

		void COutLookExplorer::TangramCommand(int nIndex)
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			switch (nIndex)
			{
			case 100:
			{
				pAddin->CreateCommonDesignerToolBar();
				CComPtr<MAPIFolder> pFolder;
				m_pExplorer->get_CurrentFolder(&pFolder);
				if (pFolder)
				{
					CComPtr<MAPIFolder> _pFolder;
					CComBSTR bstrEntryID(L"");
					CComBSTR bstrStoreID(L"");
					pFolder->get_EntryID(&bstrEntryID);
					pAddin->m_strDesignExplorerEntryID = OLE2T(bstrEntryID);
					pFolder->get_StoreID(&bstrStoreID);
					pAddin->m_strDesignExplorerStoreID = OLE2T(bstrStoreID);
					CComPtr<_NameSpace> pSession;
					HRESULT hr = pAddin->m_pApplication->get_Session(&pSession);
					pSession->GetFolderFromID(bstrEntryID, CComVariant(bstrStoreID), &_pFolder);
					CComPtr<_Explorer> pExplorer;
					hr = pAddin->m_pExplorers->Add(CComVariant(_pFolder), OlFolderDisplayMode::olFolderDisplayNoNavigation, &pExplorer);
					if (hr == S_OK)
					{
						pExplorer->Display();
						CString strKey = pAddin->m_strDesignExplorerEntryID;
						strKey += _T(",");
						strKey += pAddin->m_strDesignExplorerStoreID;
						pAddin->m_mapDesignExplorer[strKey] = pExplorer;
						::PostMessage(pAddin->m_hHostWnd, WM_TANGRAMMSG, 1963, 1222);
					}
				}
			}
			break;
			case 101:
			case 102:
			{
				CComVariant varView;
				m_pExplorer->get_CurrentView(&varView);
				if (varView.vt == VT_DISPATCH)
				{
					CComQIPtr<OutLook::View> pView(varView.pdispVal);
					if (pView)
					{
						OlViewType viewType;
						pView->get_ViewType(&viewType);
						switch (viewType)
						{
						case OlViewType::olBusinessCardView:
							break;
						case OlViewType::olCalendarView:
							break;
						case OlViewType::olCardView:
							break;
						case OlViewType::olDailyTaskListView:
							break;
						case OlViewType::olIconView:
							break;
						case OlViewType::olPeopleView:
							break;
						case OlViewType::olTableView:
							{
								CComPtr<OutLook::MAPIFolder> pFolder;
								m_pExplorer->get_CurrentFolder(&pFolder);
								if (pFolder)
								{
								}
							}
							break;
						case OlViewType::olTimelineView:
							{
								CComQIPtr<_TimelineView> _pTimelineView(pView);
								if (_pTimelineView)
								{
									//_pTimelineView->
								}
							}
							break;
						}
					}
				}
			}
			break;
			}
		}

		//begin COutLookExplorerEvents:
		void COutLookExplorer::OnActivate()
		{
			if (m_hWnd == NULL)
				m_hWnd = ::GetActiveWindow();
			CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
			pObj->Init(_T("ExplorerActivate"), 0x0000f001, m_pExplorer);
			if(g_pTangram)
				g_pTangram->FireTangramAppEvent(pObj);
		}

		void COutLookExplorer::OnFolderSwitch()
		{
			if (m_hWnd == NULL)
				m_hWnd = ::GetActiveWindow();
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			CComPtr<OutLook::MAPIFolder> _pFolder;
			m_pExplorer->get_CurrentFolder(&_pFolder);
			CString strXml = _T("");
			CString strPath = _T("");
			//IStream* pStream = 0;
			//HRESULT hr = ::CoMarshalInterThreadInterfaceInStream(IID_MAPIFolder, _pFolder.p, &pStream);
			//auto task = create_task([pStream,&strXml,&strPath]
			//{
			//	MAPIFolder* pFolder = NULL;
			//	HRESULT hr = ::CoGetInterfaceAndReleaseStream(pStream, IID_MAPIFolder, (LPVOID *)&pFolder);
			//	BSTR bstrID = L"";
			//	pFolder->get_FolderPath(&bstrID);
			//	CComPtr<OutLook::_StorageItem> pStoreItem;
			//	hr = pFolder->GetStorage(CComBSTR(_T("Tangram")), olIdentifyBySubject, &pStoreItem);
			//	if (pStoreItem)
			//	{
			//		long nSize = 0;
			//		pStoreItem->get_Size(&nSize);
			//		CComPtr<OutLook::UserProperties> pUserProperties;
			//		pStoreItem->get_UserProperties(&pUserProperties);
			//		CComPtr<OutLook::UserProperty> pUserProperty;
			//		if (nSize)
			//		{
			//			pUserProperties->Item(CComVariant(_T("TangramProperties")), &pUserProperty);
			//		}
			//		if (pUserProperty)
			//		{
			//			CComVariant m_v;
			//			pUserProperty->get_Value(&m_v);
			//			//strXml = OLE2T(m_v.bstrVal);
			//		}
			//	}
			//}).wait();

			HWND _hwnd = GetCurrentFolderFrameHandle();
			if (_pFolder)
			{
				CString strXml=pAddin->GetFolderPropertyFromStore(_pFolder, _T("Tangram"), _T("TangramProperties"));
				if (strXml != _T(""))
				{
					ICompositor* pCompositor = nullptr;
					g_pTangram->GetCompositor((LONGLONG)_hwnd, &pCompositor);
					if (pCompositor == nullptr)
					{
						ICompositorManager* pCompositorManager = nullptr;
						g_pTangram->CreateCompositorManager((LONGLONG)m_hOutLookToday, &pCompositorManager);
						if (::PathFileExists(g_pTangram->m_strAppPath+_T("outlooktoday.appxml")))
							strXml = _T("outlooktoday.appxml");
						if (pCompositorManager)
							pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)_hwnd), CComBSTR(L"OutLook"), &pCompositor);
					}
					if (pCompositor)
					{
						CComBSTR bstrName(L"");
						_pFolder->get_FolderPath(&bstrName);
						IWndNode* pNode = nullptr;
						pCompositor->Open(bstrName, strXml.AllocSysString(), &pNode);
					}
				}
			}
			
			if (m_pNewFolder)
			{
				CComBSTR bstrScript(L"");
				HRESULT hr;
				if (pAddin->m_pTangramInspectorItems)
				{
					hr = pAddin->m_pTangramInspectorItems->DispEventUnadvise(pAddin->m_pTangramInspectorItems->m_pItems);
					hr = pAddin->m_pTangramInspectorItems->m_pItems->Release();
				}

				CComQIPtr<OutLook::MAPIFolder> pFolder(m_pNewFolder);
				if (pFolder)
				{
					pFolder->get_Name(&bstrScript);
					CComPtr<_Items> pItems;
					pFolder->get_Items(&pItems);
					if (pAddin->m_pTangramInspectorItems == nullptr)
						pAddin->m_pTangramInspectorItems = new CInspectorItems;
					pAddin->m_pTangramInspectorItems->m_pItems = pItems.p;
					pAddin->m_pTangramInspectorItems->m_pItems->AddRef();
					hr = pAddin->m_pTangramInspectorItems->DispEventAdvise(pItems.p);
					long nCount = 0;
					pItems->get_Count(&nCount);
					if (nCount == 0 && m_pInspectorContainerWnd)
					{
						if (m_pInspectorContainerWnd->m_pCompositor)
						{
							HWND hwnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), L"", WS_CHILD, 0, 0, 0, 0, g_pTangram->m_hHostWnd, NULL, AfxGetInstanceHandle(), NULL);
							HWND hChildWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), L"", WS_CHILD, 0, 0, 0, 0, (HWND)hwnd, NULL, AfxGetInstanceHandle(), NULL);
							m_pInspectorContainerWnd->m_pCompositor->ModifyHost((long)hChildWnd);
							::DestroyWindow(hwnd);
							m_pInspectorContainerWnd->m_pCompositor = nullptr;
							m_pInspectorContainerWnd->m_pCompositorManager = nullptr;
						}
					}
				}
			}
		}

		void COutLookExplorer::OnBeforeFolderSwitch(IDispatch* NewFolder, VARIANT_BOOL* Cancel)
		{
			CComBSTR bstrScript(L"");
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			
			CComQIPtr<OutLook::MAPIFolder> pFolder(NewFolder);
			if (pFolder)
			{
				if (m_pNewFolder)
				{
					m_pNewFolder->Release();
				}
				m_pNewFolder = NewFolder;
				m_pNewFolder->AddRef();
			}
		}

		void COutLookExplorer::OnViewSwitch()
		{
			CComVariant varView;
			m_pExplorer->get_CurrentView(&varView);
			if (varView.vt == VT_DISPATCH)
			{
				CComQIPtr<OutLook::View> pView(varView.pdispVal);
				if (pView)
				{
					OlViewType viewType;
					pView->get_ViewType(&viewType);
					switch (viewType)
					{
					case OlViewType::olBusinessCardView:
						break;
					case OlViewType::olCalendarView:
						break;
					case OlViewType::olCardView:
						break;
					case OlViewType::olDailyTaskListView:
						break;
					case OlViewType::olIconView:
						break;
					case OlViewType::olPeopleView:
						break;
					case OlViewType::olTableView:
						break;
					case OlViewType::olTimelineView:
						{
							CComQIPtr<_TimelineView> _pTimelineView(pView);
							if (_pTimelineView)
							{
								//_pTimelineView->
							}
						}
						break;
					}
				}
			}
		}

		void COutLookExplorer::OnBeforeViewSwitch(VARIANT NewView, VARIANT_BOOL* Cancel)
		{
			CComBSTR bstrViewName = NewView.bstrVal;
		}

		void COutLookExplorer::OnDeactivate()
		{
		}

		void COutLookExplorer::OnSelectionChange()
		{
			//CComPtr<OutLook::Selection> pSelection;
			//m_pExplorer->get_Selection(&pSelection);
			//if (pSelection)
			//{
			//	long nCount = 0;
			//	pSelection->get_Count(&nCount);
			//	if (nCount)
			//	{
			//		CComPtr<IDispatch> pDisp;
			//		pSelection->Item(CComVariant(1), &pDisp);
			//		if (pDisp)
			//		{
			//			_Inspector* pIns = pAddin->GetInspector(pDisp);
			//			if (pIns)
			//			{
			//				CComBSTR bstrCap(L"");
			//				pIns->get_Caption(&bstrCap);
			//			}
			//		}
			//	}
			//}
		}

		void COutLookExplorer::OnClose()
		{
			if (m_pNewFolder)
			{
				m_pNewFolder->Release();
				m_pNewFolder = nullptr;
			}
			HRESULT hr = ((COutLookNavigationPaneEvents_12*)this)->DispEventUnadvise(m_pNavigationPane);
			hr = ((COutLookExplorerEvents*)this)->DispEventUnadvise(m_pExplorer);
			hr = ((COutLookExplorerEvents_10*)this)->DispEventUnadvise(m_pExplorer);
			//if (theApp.m_nVer>0x000f)
			hr = ((COutLookAccountSelectorEvents*)this)->DispEventUnadvise(m_pAccountSelector);

			if (m_pNavigationGroups)
				hr = ((COutLookNavigationGroupsEvents_12*)this)->DispEventUnadvise(m_pNavigationGroups);
			if (m_pCurrentModule)
				m_pCurrentModule->Release();
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it = pAddin->m_mapOutLookPlusExplorerMap.find(m_hWnd);
			if (it != pAddin->m_mapOutLookPlusExplorerMap.end())
			{
				pAddin->m_mapOutLookPlusExplorerMap.erase(it);
				delete this;
			}
		}
		//end COutLookExplorerEvents

		//begin COutLookAccountSelectorEvents:
		void COutLookExplorer::OnSelectedAccountChange(Account* SelectedAccount)
		{
		}
		//end COutLookAccountSelectorEvents

		//begin COutLookExplorerEvents_10:
		//void COutLookExplorer::OnBeforeMaximize(VARIANT_BOOL* Cancel)
		//{
		//}

		//void COutLookExplorer::OnBeforeMinimize(VARIANT_BOOL* Cancel)
		//{
		//}

		//void COutLookExplorer::OnBeforeMove(VARIANT_BOOL* Cancel)
		//{
		//}

		//void COutLookExplorer::OnBeforeSize(VARIANT_BOOL* Cancel)
		//{
		//}

		//void COutLookExplorer::OnBeforeItemCopy(VARIANT_BOOL* Cancel)
		//{
		//}

		//void COutLookExplorer::OnBeforeItemCut(VARIANT_BOOL* Cancel)
		//{
		//}

		//void COutLookExplorer::OnBeforeItemPaste(VARIANT_BOOL* Cancel)
		//{
		//}

		void COutLookExplorer::OnAttachmentSelectionChange()
		{
		}

		void COutLookExplorer::OnInlineResponse(IDispatch* Item)
		{
			//if (theApp.m_hPWwbWnd)
			//{
			//	CString m_strUIScript = _T("");
			//	map<int, CString>::iterator it = theApp.m_mapItemName.find(OutLookPlusMailItem);
			//	if (it != theApp.m_mapItemName.end())
			//	{
			//		CString strKey = it->second;
			//		if (strKey != _T(""))
			//		{
			//			map<CString, CString>::iterator it2 = theApp.m_mapUIScript.find(strKey);
			//			if (it2 == theApp.m_mapUIScript.end())
			//			{
			//				CTangramXmlParse m_Parse;
			//				if (m_Parse.LoadXml(theApp.m_strConfigFile))
			//				{
			//					CTangramXmlParse* pParse = m_Parse.GetChild(strKey);
			//					if (pParse)
			//					{
			//						CTangramXmlParse* pParse2 = pParse->GetChild(_T("UIScript"));
			//						if (pParse2)
			//						{
			//							m_strUIScript = pParse2->xml();
			//							theApp.m_mapUIScript[strKey] = m_strUIScript;
			//						}
			//					}
			//				}
			//			}
			//			else
			//			{
			//				m_strUIScript = it2->second;
			//			}
			//		}
			//	}
			//m_pOnlineItem = Item;
			//	m_pOnlineItem->AddRef();

			//	CComPtr<ITangramWindow> pWnd;
			//	CString strUrl = m_strUIScript;
			//	strUrl.Replace(_T("%s"), theApp.m_strUser);
			//	theApp.m_pTangramManager->AddToolBarForWnd((LONGLONG)theApp.m_hPWwbWnd, (LONGLONG)theApp.m_hWwbWnd, (IDispatch*)m_pOnlineItem, CComBSTR(strUrl), &m_pOnLineItemHostWindow);
			//	m_pOnLineItemHostWindow->AddRef();
			//	m_pOnLineItemHostWindow->put_Extender(m_pOnlineItem);
			//	theApp.m_hPWwbWnd = NULL;
			//}
		}

		void COutLookExplorer::OnInlineResponseClose()
		{
			//if (m_pOnLineItemHostWindow)
			//{
			//	if (m_pOnlineItem)
			//	{
			//		m_pOnlineItem->Release();
			//		m_pOnlineItem = NULL;
			//	}
			//	m_pOnLineItemHostWindow->CloseFrame();
			//}
		}
		//end dCOutLookExplorerEvents_10

		//begin COutLookNavigationPaneEvents_12:
		void COutLookExplorer::OnModuleSwitch(NavigationModule* pCurrentModule)
		{
			CComQIPtr<_NavigationModule> _pNavigationModule((_NavigationModule*)pCurrentModule);

			if (_pNavigationModule)
			{
				if (m_pNavigationGroups)
				{
					HRESULT hr = ((COutLookNavigationGroupsEvents_12*)this)->DispEventUnadvise(m_pNavigationGroups);
					m_pNavigationGroups->Release();
					m_pNavigationGroups = nullptr;
					m_pCurrentModule->Release();
					m_pCurrentModule = _pNavigationModule.p;
					m_pCurrentModule->AddRef();
				}
				HRESULT hr = _pNavigationModule->get_NavigationModuleType(&m_nNType);
				CComBSTR bstrName("");
				switch (m_nNType)
				{
				case olModuleMail:
				{
					CComQIPtr<_MailModule> _pModule(m_pCurrentModule);
					if (_pModule)
						_pModule->get_NavigationGroups(&m_pNavigationGroups);
				}
				break;
				case olModuleCalendar:
				{
					CComQIPtr<_CalendarModule> _pModule(m_pCurrentModule);
					if (_pModule)
						_pModule->get_NavigationGroups(&m_pNavigationGroups);
				}
				break;
				case olModuleContacts:
				{
					CComQIPtr<_ContactsModule> _pModule(m_pCurrentModule);
					if (_pModule)
						_pModule->get_NavigationGroups(&m_pNavigationGroups);
				}
				break;
				case olModuleTasks:
				{
					CComQIPtr<_TasksModule> _pModule(m_pCurrentModule);
					if (_pModule)
						_pModule->get_NavigationGroups(&m_pNavigationGroups);
				}
				break;
				case olModuleJournal:
				{
					CComQIPtr<_JournalModule> _pModule(m_pCurrentModule);
					if (_pModule)
						_pModule->get_NavigationGroups(&m_pNavigationGroups);
				}
				break;
				case olModuleNotes:
				{
					CComQIPtr<_NotesModule> _pModule(m_pCurrentModule);
					if (_pModule)
						_pModule->get_NavigationGroups(&m_pNavigationGroups);
				}
				break;
				case olModuleFolderList:
				case olModuleShortcuts:
				case olModuleSolutions:
					break;
				}
				if (m_nNType == olModuleSolutions)
				{
					//if (::IsChild(m_hWnd, theApp.m_pSolutionHelperWnd->m_hWnd) == false)
					//{
					//	::SetParent(theApp.m_pSolutionHelperWnd->m_hWnd, m_hWnd);
					//	theApp.m_pSolutionFrame->ModifyHost((LONGLONG)m_pTangramSolutionHostWnd->m_hWnd, (LONGLONG)m_hNavWnd);
					//}
					//if (m_hNavWnd&&theApp.m_pSolutionFrame)
					//{
					//	if (theApp.m_pSolutionHelperWnd&&::IsWindow(theApp.m_pSolutionHelperWnd->m_hWnd))
					//		::ShowWindow(theApp.m_pSolutionHelperWnd->m_hWnd, SW_SHOW);
					//	if (m_hButton)
					//		::ShowWindow(m_hButton, SW_HIDE);
					//	theApp.m_pSolutionFrame->Attach();
					//}
				}
				else
				{
					//if (m_hNavWnd&&theApp.m_pSolutionFrame)
					//{
					//	if (theApp.m_pSolutionHelperWnd&&::IsWindow(theApp.m_pSolutionHelperWnd->m_hWnd))
					//		::ShowWindow(theApp.m_pSolutionHelperWnd->m_hWnd, SW_HIDE);
					//	if (m_hButton)
					//		::ShowWindow(m_hButton, SW_SHOW);
					//	theApp.m_pSolutionFrame->Deatch();
					//}
				}
				if (m_pNavigationGroups)
				{
					m_pNavigationGroups->AddRef();
					hr = ((COutLookNavigationGroupsEvents_12*)this)->DispEventAdvise(m_pNavigationGroups);
				}
			}
		}
		//end COutLookNavigationPaneEvents_12

		//begin COutLookNavigationGroupsEvents_12:
		void COutLookExplorer::OnSelectedChange(NavigationFolder* NavigationFolder)
		{
			_NavigationFolder* _pNavigationFolder = nullptr;
		}

		void COutLookExplorer::OnNavigationFolderAdd(NavigationFolder* NavigationFolder)
		{
		}

		void COutLookExplorer::OnNavigationFolderRemove()
		{
		}
		//end COutLookNavigationGroupsEvents_12

		HWND COutLookExplorer::GetCurrentFolderFrameHandle()
		{
			CString strID = _T("Tangram");
			CComBSTR bstrEntryID(L"");
			CComPtr<MAPIFolder> pFolder;
			m_pExplorer->get_CurrentFolder(&pFolder);
			if (pFolder)
			{
				CComBSTR bstrName(L"");
				pFolder->get_Name(&bstrName);
				pFolder->get_EntryID(&bstrEntryID);
				strID += OLE2T(bstrEntryID);
				auto it = m_mapFolderWnd.find(strID);
				if (it != m_mapFolderWnd.end())
					return it->second;
			}

			HWND hRet = NULL;
			HWND hWnd = ::GetActiveWindow();
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			BOOL bHaveView = false;
				
			CComVariant m_v;
			m_pExplorer->get_CurrentView(&m_v);
			if (m_v.vt == VT_DISPATCH)
			{
				bHaveView = true;
				CComQIPtr<OutLook::View>pView(m_v.pdispVal);
				if (pView)
				{
					OlViewType viewType;
					pView->get_ViewType(&viewType);
					switch (viewType)
					{
					case OlViewType::olBusinessCardView:
						break;
					case OlViewType::olCalendarView:
						break;
					case OlViewType::olCardView:
						break;
					case OlViewType::olDailyTaskListView:
						break;
					case OlViewType::olIconView:
						break;
					case OlViewType::olPeopleView:
					case OlViewType::olTableView:
					{
						if (m_pInspectorContainerWnd == nullptr)
						{
							HWND _hWnd = ::FindWindowEx(hWnd, NULL, _T("rctrl_renwnd32"), NULL);
							HWND hWnd2 = _hWnd;
							if (_hWnd)
							{
								_hWnd = ::FindWindowEx(_hWnd, NULL, _T("AfxWndW"), NULL);
								if (_hWnd)
								{
									m_pInspectorContainerWnd = new CInspectorContainerWnd();
									m_pInspectorContainerWnd->SubclassWindow(_hWnd);
								}
							}
						}
						if (m_pInspectorContainerWnd)
						{
							return m_pInspectorContainerWnd->m_hWnd;
						}
					}
					break;
					case OlViewType::olTimelineView:
					{
						CComQIPtr<_TimelineView> _pTimelineView(pView);
						if (_pTimelineView)
						{
							//_pTimelineView->
						}
					}
					break;
					}
				}
			}
			else
			{
				m_hOutLookToday = ::FindWindowEx(m_hWnd, NULL, _T("Shell Embedding"), NULL);
				if (m_hOutLookToday)
				{
					hRet = ::FindWindowEx(m_hOutLookToday, NULL, _T("Shell DocObject View"), NULL);
				}
			}

			return hRet;
		}

		void COutLookExplorer::SetDesignState()
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			HWND hWnd = ::GetActiveWindow();
			HWND _hwnd = NULL;
			CInspectorContainerWnd* pWnd = nullptr;
			CComVariant varView;
			m_pExplorer->get_CurrentView(&varView);
			CComPtr<MAPIFolder> pFolder;
			m_pExplorer->get_CurrentFolder(&pFolder);
			CString strXml = pAddin->GetFolderPropertyFromStore(pFolder, _T("Tangram"), _T("TangramProperties"));

			if (varView.vt == VT_DISPATCH)
			{
				CComQIPtr<OutLook::View> pView(varView.pdispVal);
				if (pView)
				{
					OlViewType viewType;
					pView->get_ViewType(&viewType);
					switch (viewType)
					{
					case OlViewType::olBusinessCardView:
						break;
					case OlViewType::olCalendarView:
						break;
					case OlViewType::olCardView:
						break;
					case OlViewType::olDailyTaskListView:
						break;
					case OlViewType::olIconView:
						break;
					case OlViewType::olPeopleView:
					case OlViewType::olTableView:
					{
						_hwnd = ::FindWindowEx(hWnd, NULL, _T("rctrl_renwnd32"), NULL);
						if (m_pInspectorContainerWnd == NULL)
						{
							if (_hwnd)
							{
								_hwnd = ::FindWindowEx(_hwnd, NULL, _T("AfxWndW"), NULL);
								if (_hwnd)
								{
									m_pInspectorContainerWnd = new CInspectorContainerWnd();
									m_pInspectorContainerWnd->SubclassWindow(_hwnd);
								}
							}
						}
						pWnd = m_pInspectorContainerWnd;
					}
					break;
					case OlViewType::olTimelineView:
					{
						CComQIPtr<_TimelineView> _pTimelineView(pView);
						if (_pTimelineView)
						{
						}
					}
					break;
					}
				}
			}
			else
			{
				m_hOutLookToday = ::FindWindowEx(m_hWnd, NULL, _T("Shell Embedding"), NULL);
				if (m_hOutLookToday)
				{
					_hwnd = ::FindWindowEx(m_hOutLookToday, NULL, _T("Shell DocObject View"), NULL);
					pWnd = new CInspectorContainerWnd();
					pWnd->SubclassWindow(_hwnd);
				}
			}
			pWnd->m_pOutLookExplorer = this;
			ICompositor* pCompositor = nullptr;
			g_pTangram->GetCompositor((LONGLONG)pWnd->m_hWnd, &pWnd->m_pCompositor);
			if (pWnd->m_pCompositor == nullptr)
			{
				g_pTangram->CreateCompositorManager((LONGLONG)::GetParent(pWnd->m_hWnd), &pWnd->m_pCompositorManager);
				if (pWnd->m_pCompositorManager)
					pWnd->m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)pWnd->m_hWnd), CComBSTR(L""), &pWnd->m_pCompositor);
			}
			if (pWnd->m_pCompositor)
			{
				CComBSTR bstrName(L"");
				pFolder->get_FolderPath(&bstrName);
				IWndNode* pNode = nullptr;
				if(strXml==_T(""))
					strXml  = _T("<Tangram><window><node name=\"Start\" /></window></Tangram>");
				pWnd->m_pCompositor->Open(bstrName, strXml.AllocSysString(), &pNode);
				CCompositor* _pCompositor = (CCompositor*)pWnd->m_pCompositor;
				_pCompositor->HostPosChanged();
				_pCompositor->m_bDesignerState = true;
				pAddin->CreateCommonDesignerToolBar();
			}
		}

		CInspectorItem::CInspectorItem(void)
		{
			m_strXml					= _T("");
			m_pItem						= nullptr;
			m_pInspectorContainerWnd	= nullptr;
		}

		CInspectorItem::~CInspectorItem(void)
		{
		}

		void CInspectorItem::OnRead()
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			m_strXml = pAddin->GetTangramPropertyFromItem(m_pItem, _T("Tangram"));
		}

		void CInspectorItem::OnUnload()
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			long nKey = (long)this;
			auto it = pAddin->m_mapTangramInspectorItem.find(nKey);
			if (it != pAddin->m_mapTangramInspectorItem.end())
				pAddin->m_mapTangramInspectorItem.erase(it);
			HRESULT hr = ((COutLookItemEvents*)this)->DispEventUnadvise(m_pItem);
			//hr = ((COutLookItemEvents_10*)this)->DispEventUnadvise(m_pItem);
			ULONG dw = m_pItem->Release();
			while(dw)
				dw = m_pItem->Release();
			delete this;
		}

		CInspectorItems::CInspectorItems(void)
		{
			m_pItems = nullptr;
		}

		CInspectorItems::~CInspectorItems(void)
		{

		}

		void CInspectorItems::OnItemAdd(IDispatch* Item) 
		{
		}

		void CInspectorItems::OnItemChange(IDispatch* Item) 
		{
		}

		void CInspectorItems::OnItemRemove() 
		{
		}

		//New COutLookInspector Object:
		COutLookInspector::COutLookInspector(void)
		{
			m_bReadOnly				= false;
			m_strKey				= _T("");
			m_strUIScript			= _T("");
			m_hWnd					= nullptr;
			m_hHostWnd				= NULL;
			m_hTaskPaneWnd			= NULL;
			m_hTaskPaneChildWnd		= NULL;
			m_pTaskPane				= nullptr;
			m_pInspector			= nullptr;
			m_pTaskPaneCompositor		= nullptr;
			m_pTaskPaneCompositorManager			= nullptr;
			m_pActiveOutLookPage	= nullptr;
		}

		COutLookInspector::~COutLookInspector(void)
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			if (pAddin->m_pCurOpenItem == this)
				pAddin->m_pCurOpenItem = nullptr;
		}

		void COutLookInspector::OnPageChange(BSTR ActivePageName) 
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			m_strActivePageName = OLE2T(ActivePageName);
			m_strActivePageName.Trim();
			m_strActivePageName.Replace(_T(" "), _T("_"));
			::PostMessage(pAddin->m_hHostWnd, WM_TANGRAMACTIVEINSPECTORPAGE, (WPARAM)this, 0);
		}

		void COutLookInspector::OnActivate()
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			HWND hActive = ::GetActiveWindow();
			if (m_hHostWnd)
				hActive = m_hHostWnd;
			auto it = pAddin->m_mapOutLookPlusExplorerMap.find(hActive);
			if (it == pAddin->m_mapOutLookPlusExplorerMap.end())
			{
				auto it2 = pAddin->m_mapInspector.find(hActive);
				if (it2 == pAddin->m_mapInspector.end())
				{
					m_hHostWnd = hActive;
					pAddin->m_mapInspector[m_hHostWnd] = this;
				}

				if (m_pActiveOutLookPage)
				{
					m_pActiveOutLookPage->ActivePage();
				}
			}
		}

		void COutLookInspector::OnDeactivate() 
		{
		}

		void COutLookInspector::OnClose() 
		{
			if (m_hHostWnd)
			{
				HRESULT hr = S_FALSE;
				COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
				if (m_pTaskPaneCompositorManager)
				{
					HWND _hWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), L"", WS_CHILD, 0, 0, 0, 0, g_pTangram->m_hHostWnd, NULL, AfxGetInstanceHandle(), NULL);
					HWND _hChildWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), L"", WS_CHILD, 0, 0, 0, 0, (HWND)_hWnd, NULL, AfxGetInstanceHandle(), NULL);
					if (::IsWindow(m_hWnd))
					{
						m_pTaskPaneCompositor->ModifyHost((long)_hChildWnd);
						::DestroyWindow(m_hWnd);
					}
				}
				hr = ((COutLookInspectorEvents*)this)->DispEventUnadvise(m_pInspector);
				hr = ((COutLookInspectorEvents_10*)this)->DispEventUnadvise(m_pInspector);
				hr = ((COutLookItemEvents*)this)->DispEventUnadvise(m_pDisp);
				//hr = ((COutLookItemEvents_10*)this)->DispEventUnadvise(m_pDisp);
				ULONG dw = m_pDisp->Release();
				while(dw)
					dw = m_pDisp->Release();
				m_pDisp = nullptr;
				auto it = pAddin->m_mapInspector.find(m_hHostWnd);
				if (it != pAddin->m_mapInspector.end())
				{
					pAddin->m_mapInspector.erase(it);
				}
			}
			delete this;
		}

		void COutLookInspector::TangramCommand(int nIndex)
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			switch (nIndex)
			{
			case 100:
			{
				CString strXml = pAddin->GetTangramPropertyFromInspector(m_pInspector, _T("Tangram"));
				if (strXml == _T(""))
				{
					CString str = g_pTangram->m_strExeName;
					CString strCaption = _T("");
					str += _T("\\");
					switch (m_OlObjectClass)
					{
					case olMail:
						{
							str += _T("mail");
							strCaption = _T("Please select Mail Template:");
						}
						break;
					case olAppointment:
						{
							str += _T("Appointment");
							strCaption = _T("Please select Appointment Template:");
						}
						break;
					case olTask:
						{
							str += _T("Task");
							strCaption = _T("Please select Task Template:");
						}
						break;
					case olContact:
						{
							str += _T("Contact");
							strCaption = _T("Please select Contact Template:");
						}
						break;
					case olJournal:
						{
							str += _T("Journal");
							strCaption = _T("Please select Journal Template:");
						}
						break;
					case olPost:
						{
							str += _T("Post");
							strXml = pAddin->GetDocTemplateXml(_T("Please select Post Template:"), str, _T(".PostXml"));
						}
						break;
					case olDistributionList:
						{
							str += _T("DistributionList");
							strCaption = _T("Please select DistributionList Template:");
						}
						break;
					}
					strXml = pAddin->GetDocTemplateXml(strCaption, str, _T(""));
				}
				if (m_pActiveOutLookPage)
					m_pActiveOutLookPage->DesignPage();
			}
			break;
			case 101:
			case 102:
			{
				auto iter = pAddin->m_mapTaskPaneMap.find((LONG)m_hHostWnd);
				if (iter != pAddin->m_mapTaskPaneMap.end())
					pAddin->m_mapTaskPaneMap[(LONG)m_hHostWnd]->put_Visible(true);
				else
				{
					CString strKey = _T("taskpaneui");
					CString strXml = m_strUIScript;
					if(strXml==_T(""))
						strXml = _T("<taskpaneui><window><node name=\"Start\" /></window></taskpaneui>");
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						CTangramXmlParse* pParse = m_Parse.GetChild(strKey);
						if (pParse)
						{
							strXml = pParse->xml();
						}
						else
							strXml = _T("<taskpaneui><window><node name=\"Start\" /></window></taskpaneui>");
						if (strXml != _T(""))
						{
							{
								VARIANT vWindow;
								vWindow.vt = VT_DISPATCH;
								vWindow.pdispVal = nullptr;
								Office::_CustomTaskPane* _pCustomTaskPane;
								CString strCap = _T("");
								if (pParse)
								{
									CTangramXmlParse* pNodeParse = m_Parse.FindItem(_T("node"));
									if(pNodeParse)
										strCap = pNodeParse->attr(_T("caption"), _T(""));
								}
								if (strCap == _T(""))
									strCap = _T("Start");
								CComBSTR bstrCap(strCap);
								HRESULT hr = pAddin->m_pCTPFactory->CreateCTP(L"Tangram.Ctrl.1", bstrCap, vWindow, &_pCustomTaskPane);
								_pCustomTaskPane->AddRef();
								_pCustomTaskPane->put_Visible(true);
								pAddin->m_mapTaskPaneMap[(LONG)m_hHostWnd] = _pCustomTaskPane;
								CComPtr<ITangramCtrl> pCtrlDisp;
								_pCustomTaskPane->get_ContentControl((IDispatch**)&pCtrlDisp);
								if (pCtrlDisp)
								{
									LONGLONG hWnd = 0;
									pCtrlDisp->get_HWND(&hWnd);
									HWND hPWnd = ::GetParent((HWND)hWnd);
									m_hTaskPane = (HWND)hWnd;
									CWindow m_Wnd;
									m_Wnd.Attach(hPWnd);
									m_Wnd.ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
									m_Wnd.Detach();

									if (m_pTaskPaneCompositorManager == nullptr)
									{
										HRESULT hr = g_pTangram->CreateCompositorManager((LONGLONG)hPWnd, &m_pTaskPaneCompositorManager);
										if (m_pTaskPaneCompositorManager)
										{
											m_pTaskPaneCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)hWnd), CComBSTR(L"TaskPane"), &m_pTaskPaneCompositor);
											if (m_pTaskPaneCompositor)
											{
												IWndNode* pNode = nullptr;
												m_pTaskPaneCompositor->Open(CComBSTR("Default"), strXml.AllocSysString(), &pNode);
											}
										}
									}
									else
										m_pTaskPaneCompositor->ModifyHost(hWnd);
								}
							}
						}
					}
				}
				if (nIndex == 102)
				{
					
				}
			}
			break;
			case 103:
			{
				if (m_pInspector)
				{
					OutLook::Pages* pPages = nullptr;
					m_pInspector->get_ModifiedFormPages((IDispatch**)&pPages);
					long nCount = 0;
					pPages->get_Count(&nCount);
					if (nCount<5)
					{
						COutLookCustomizeFormDlg m_Dlg;
						m_Dlg.m_pOutLookInspector = this;
						m_Dlg.DoModal();
					}
					else
					{

					}
				}
			}
				break;
			case 104:
				break;
			}
		}

		//begin COutLookItemEvents:
		void COutLookInspector::ActivePage()
		{
			HWND hActive = ::GetActiveWindow();
			if (hActive == NULL)
				return;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			BOOL bInExplorer = false;
			auto it = pAddin->m_mapOutLookPlusExplorerMap.find(hActive);
			if (it != pAddin->m_mapOutLookPlusExplorerMap.end())
			{
				bInExplorer = true;
				if (m_hHostWnd == NULL)
				{
					m_hHostWnd = ::FindWindowEx(hActive, NULL, _T("rctrl_renwnd32"), NULL);
					if (m_hHostWnd == NULL)
						return;
				}
			}
			else
			{
				m_hHostWnd = hActive;
			}
			if (m_hWnd == NULL)
				m_hWnd = ::FindWindowEx(m_hHostWnd, NULL, _T("AfxWndW"), NULL);
			if (m_hWnd == NULL)
				return;
			HWND hwnd = NULL;
			if (bInExplorer == false)
				hwnd = ::FindWindowEx(m_hWnd, NULL, _T("AfxWndW"), NULL);
			else
			{
				hwnd = m_hWnd;
			}
			auto it2= m_mapOutLookPage.find(m_strActivePageName);
			if (it2 != m_mapOutLookPage.end())
			{
				m_pActiveOutLookPage = it2->second;
				if (m_pActiveOutLookPage->m_bDesignState)
				{
					pAddin->CreateCommonDesignerToolBar();
					CCompositor* pCompositor = (CCompositor*)m_pActiveOutLookPage->m_pCompositor;
					if (pAddin->m_pDesigningFrame != pCompositor)
					{
						pAddin->m_pDesigningFrame = pCompositor;
						pCompositor->UpdateDesignerTreeInfo();
					}
				}
			}
			else
			{
				CString strXml = pAddin->GetTangramPropertyFromItem(m_pDisp, _T("Tangram"));
				//if (strXml == _T(""))
				//{
				//	switch (m_OlObjectClass)
				//	{
				//		//olAppointment = 26,
				//		//	olMeetingRequest = 53,
				//		//	olMeetingCancellation = 54,
				//		//	olMeetingResponseNegative = 55,
				//		//	olMeetingResponsePositive = 56,
				//		//	olMeetingResponseTentative = 57,
				//			//olContact = 40,
				//		//	olDocument = 41,
				//		//	olJournal = 42,
				//		//	olMail = 43,
				//		//	olNote = 44,
				//		//	olPost = 45,
				//		//	olReport = 46,
				//		//	olRemote = 47,
				//		//	olTask = 48,
				//		//	olTaskRequest = 49,
				//		//	olTaskRequestUpdate = 50,
				//		//	olTaskRequestAccept = 51,
				//		//	olTaskRequestDecline = 52,
				//	case OlObjectClass::olMail:
				//	{
				//		//CString str = theApp.m_strExeName;
				//		//str += _T("\\Mail");
				//		//CString strTemplate = pAddin->GetDocTemplateXml(str);
				//		//CTangramXmlParse m_Parse;
				//		//bool bLoad = m_Parse.LoadXml(strTemplate);
				//		//if (bLoad == false)
				//		//	bLoad = m_Parse.LoadFile(strTemplate);
				//		//if (bLoad == false)
				//		//	return;
				//	}
				//		break;
				//	case OlObjectClass::olTask:
				//		break;
				//	}
				//}
				m_pActiveOutLookPage = new COutLookPageWnd();
				m_pActiveOutLookPage->m_pOutLookInspector = this;
				m_pActiveOutLookPage->m_strName = m_strActivePageName;
				m_pActiveOutLookPage->m_strXml = g_pTangram->GetXmlData(m_strActivePageName, strXml);
				OutLook::Pages* pPages = nullptr;
				m_pInspector->get_ModifiedFormPages((IDispatch**)&pPages);
				CComPtr<IDispatch> pItem;
				pPages->Item(CComVariant(m_strActivePageName), &pItem);
				if (pItem)
				{
					CComQIPtr<MSForm::_UserForm> pForm(pItem);
					CComQIPtr<IOleWindow> pOleWnd(pForm);
					if(pOleWnd)
					{
						pOleWnd->GetWindow(&hwnd);
						m_pActiveOutLookPage->m_hFrameWnd = ::GetParent(hwnd);
						m_pActiveOutLookPage->SubclassWindow(::GetParent(m_pActiveOutLookPage->m_hFrameWnd));
						m_pActiveOutLookPage->m_pForm = pForm.p;
						m_pActiveOutLookPage->m_pForm->AddRef();
					}
				}
				else
				{
					m_pActiveOutLookPage->SubclassWindow(hwnd);
					m_pActiveOutLookPage->m_hFrameWnd = GetWindow(hwnd, GW_CHILD);
				}
				m_mapOutLookPage[m_strActivePageName] = m_pActiveOutLookPage;
			}
			if (bInExplorer == false)
			{
				m_pActiveOutLookPage->ActivePage();
			}
		}

		void COutLookInspector::OnOpen(VARIANT_BOOL* Cancel)
		{
		};

		void COutLookInspector::OnCustomAction(IDispatch* Action, IDispatch* Response, VARIANT_BOOL* Cancel)
		{
			CComQIPtr<OutLook::Action> pItem(Action);
		};

		void COutLookInspector::OnCustomPropertyChange(BSTR Name)
		{
		};

		void COutLookInspector::OnForward(IDispatch* Forward, VARIANT_BOOL* Cancel)
		{
			//×ª·¢
			CComQIPtr<_MailItem> pItem(Forward);
			if (pItem)
			{
				//CComBSTR bstrSubject(L"");
				//pItem->get_Subject(&bstrSubject);
				//pItem->get_HTMLBody(&bstrSubject);
				//* Cancel = true;
			}
		};

		void COutLookInspector::OnClose(VARIANT_BOOL* Cancel)
		{
		};

		void COutLookInspector::OnPropertyChange(BSTR Name)
		{
		};

		void COutLookInspector::OnRead()
		{
		};

		void COutLookInspector::OnReply(IDispatch* Response, VARIANT_BOOL* Cancel)
		{
			CComQIPtr<_MailItem> pItem(Response);
			if (pItem)
			{
				//CComBSTR bstrSubject(L"");
				//pItem->get_Subject(&bstrSubject);
				//pItem->get_HTMLBody(&bstrSubject);
				//* Cancel = true;
			}
		};

		void COutLookInspector::OnReplyAll(IDispatch* Response, VARIANT_BOOL* Cancel)
		{
			CComQIPtr<_MailItem> pItem(Response);
			if (pItem)
			{
				//CComBSTR bstrSubject(L"");
				//pItem->get_Subject(&bstrSubject);
				//pItem->get_HTMLBody(&bstrSubject);
				//* Cancel = false;
			}
		};

		void COutLookInspector::OnSend(VARIANT_BOOL* Cancel)
		{
		};

		void COutLookInspector::OnWrite(VARIANT_BOOL* Cancel)
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			IStream* pStream = 0;
			HRESULT hr = ::CoMarshalInterThreadInterfaceInStream(IID__Inspector, m_pInspector, &pStream);

			auto task = create_task([pStream, pAddin, this]()
			{
				CoInitializeEx(NULL, COINIT_MULTITHREADED);
				_Inspector* pInspector = nullptr;
				HRESULT hr = ::CoGetInterfaceAndReleaseStream(pStream, IID__Inspector, (LPVOID *)&pInspector);
				if (pInspector)
				{
					CString strPageData = _T("");
					CString strKeys = _T(",");
					CString strXml = _T("");
					//theApp.Lock();
					for (auto it : m_mapOutLookPage)
					{
						CCompositor* pCompositor = (CCompositor*)it.second->m_pCompositor;
						if (pCompositor)
						{
							strKeys += it.first;
							strKeys += _T(",");
							CWndNode* pNode = pCompositor->m_pWorkNode;
							pAddin->UpdateWndNode(pNode);
							strPageData += pNode->m_pTangramNodeCommonData->m_pTangramParse->xml();
						}
					}
					strXml = pAddin->GetTangramPropertyFromInspector(pInspector, _T("Tangram"));
					//theApp.Unlock();
					CString strData = _T("");
					CString strPagesXml = g_pTangram->GetXmlData(_T("OutLookPages"), strXml);
					strData = _T("<OutLookPages>");
					if (strPagesXml != _T(""))
					{
						CString strKey = _T("<window>");
						CString _strKey = _T("");
						CString strName = _T("");
						int nPos = strPagesXml.Find(strKey);
						while (nPos != -1)
						{
							strName = strPagesXml.Left(nPos);
							nPos = strName.ReverseFind('<');
							strName = strName.Mid(nPos + 1);
							nPos = strName.ReverseFind('>');
							strName = strName.Left(nPos);
							strName.Trim();
							_strKey = _T(",");
							_strKey += strName;
							_strKey += _T(",");
							if (strKeys.Find(_strKey) == -1)
								strData += g_pTangram->GetXmlData(strName, strPagesXml);
							strKey = _T("</window>");
							nPos = strPagesXml.Find(strKey);
							strPagesXml = strPagesXml.Mid(nPos + 9);
							nPos = strPagesXml.Find(_T("<window>"));
						}
					}
					strData += strPageData;
					strData += _T("</OutLookPages>");
					if (strData != _T("<OutLookPages></OutLookPages>"))
					{
						pAddin->AddTangramPropertyToInspector(pInspector, _T("Tangram"), strData);
					}
				}
				CoUninitialize();
			});
		};

		void COutLookInspector::OnBeforeCheckNames(VARIANT_BOOL* Cancel)
		{
		};

		void COutLookInspector::OnAttachmentAdd(Attachment* Attachment)
		{
		};

		void COutLookInspector::OnAttachmentRead(Attachment* Attachment)
		{
		};

		void COutLookInspector::OnBeforeAttachmentSave(Attachment* Attachment, VARIANT_BOOL* Cancel)
		{
		};
		//end COutLookItemEvents

		//begin COutLookItemEvents_10:
		//void COutLookInspector::OnBeforeDelete(IDispatch* Item, VARIANT_BOOL* Cancel)
		//{
		//};

		//void COutLookInspector::OnAttachmentRemove(Attachment* Attachment)
		//{
		//};

		//void COutLookInspector::OnBeforeAttachmentAdd(Attachment* Attachment, VARIANT_BOOL* Cancel)
		//{
		//};

		//void COutLookInspector::OnBeforeAttachmentPreview(Attachment* Attachment, VARIANT_BOOL* Cancel)
		//{
		//};

		//void COutLookInspector::OnBeforeAttachmentRead(Attachment* Attachment, VARIANT_BOOL* Cancel)
		//{
		//};

		//void COutLookInspector::OnBeforeAttachmentWriteToTempFile(Attachment* Attachment, VARIANT_BOOL* Cancel)
		//{
		//};

		//void COutLookInspector::OnUnload()
		//{
		//};

		//void COutLookInspector::OnBeforeAutoSave(VARIANT_BOOL* Cancel)
		//{
		//};

		//void COutLookInspector::OnBeforeRead()
		//{
		//};

		//void COutLookInspector::OnAfterWrite()
		//{
		//};

		//void COutLookInspector::OnReadComplete(VARIANT_BOOL* Cancel)
		//{
		//};
		//end COutLookItemEvents_10

		COutLookPageWnd::COutLookPageWnd(void) 
		{
			m_strXml			= _T("");
			m_bDesignState		= false;
			m_pCompositorManager				= nullptr;
			m_pForm				= nullptr;
			m_pCompositor			= nullptr;
			m_pOutLookInspector = nullptr;
		}

		COutLookPageWnd::~COutLookPageWnd(void) 
		{
		}

		void COutLookPageWnd::OnFinalMessage(HWND hWnd)
		{
			CWindowImpl::OnFinalMessage(hWnd);
			delete this;
		}

		void COutLookPageWnd::ActivePage()
		{
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			HWND hActive = ::GetActiveWindow();
			auto it = pAddin->m_mapOutLookPlusExplorerMap.find(hActive);
			if (it == pAddin->m_mapOutLookPlusExplorerMap.end())
			{
				m_pOutLookInspector->m_hHostWnd = hActive;
				pAddin->m_mapInspector[hActive] = m_pOutLookInspector;
				m_pOutLookInspector->m_hWnd = ::FindWindowEx(hActive, NULL, _T("AfxWndW"), NULL);
				HWND hWnd = NULL;
				if (m_pOutLookInspector->m_hWnd)
				{
					hWnd = ::FindWindowEx(m_pOutLookInspector->m_hWnd, NULL, _T("AfxWndW"), NULL);
					BOOL bVisible = ::IsWindowVisible(hWnd);
					while (hWnd&&bVisible == false)
					{
						HWND _hWnd = ::FindWindowEx(m_pOutLookInspector->m_hWnd, hWnd, _T("AfxWndW"), NULL);
						if (_hWnd)
						{
							hWnd = _hWnd;
							bVisible = ::IsWindowVisible(hWnd);
						}
						else
							break;
					}
					if (hWnd != m_hWnd)
					{
						UnsubclassWindow(true);
						SubclassWindow(hWnd);
					}
					HWND hFrame = ::GetWindow(hWnd, GW_CHILD);
					if (m_hFrameWnd != hFrame)
					{
						m_hFrameWnd = hFrame;
						if (m_pCompositor)
						{
							m_pCompositor->ModifyHost((LONGLONG)hFrame);
						}
					}
				}
				if (m_strXml!=_T(""))
				{
					BSTR bstrName = m_strName.AllocSysString();
					if (m_pCompositorManager == nullptr)
					{
						g_pTangram->CreateCompositorManager((LONGLONG)m_hWnd, &m_pCompositorManager);
						if (m_pCompositorManager)
						{
							m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)m_hFrameWnd), bstrName, &m_pCompositor);
						}
					}
					if (m_pCompositor)
					{
						IWndNode* pNode = nullptr;
						m_pCompositor->Open(bstrName, m_strXml.AllocSysString(), &pNode);
						((CCompositor*)m_pCompositor)->HostPosChanged();
					}
					::SysFreeString(bstrName);
				}
			}
		}

		void COutLookPageWnd::DesignPage()
		{
			if (m_bDesignState == false)
			{
				m_bDesignState = true;
				if (m_pCompositorManager == nullptr)
				{
					g_pTangram->CreateCompositorManager((LONGLONG)m_hWnd, &m_pCompositorManager);
					if (m_pCompositorManager)
					{
						BSTR bstrName = m_strName.AllocSysString();
						m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)m_hFrameWnd), bstrName, &m_pCompositor);
						if (m_pCompositor)
						{
							m_pCompositor->put_DesignerState(true);
							g_pTangram->CreateCommonDesignerToolBar();
							IWndNode* pNode = nullptr;
							if (m_strXml == _T(""))
							{
								CString strName = m_strName;
								strName.Replace(_T(" "), _T("_"));
								m_strXml.Format(_T("<%s><window><node name=\"Start\" /></window></%s>"), strName, strName);
							}
							m_pCompositor->Open(bstrName, m_strXml.AllocSysString(), &pNode);
							g_pTangram->m_pDesigningFrame = (CCompositor*)m_pCompositor;
							g_pTangram->m_pDesigningFrame->m_bDesignerState = true;
							g_pTangram->m_pDesigningFrame->UpdateDesignerTreeInfo();
						}
						::SysFreeString(bstrName);
					}
				}
			}
		}

		LRESULT COutLookPageWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
		{
			if (m_pForm)
			{
				m_pForm->Release();
				m_pForm = nullptr;
			}

			return DefWindowProc(uMsg, wParam, lParam);
		}

		CInspectorContainerWnd::CInspectorContainerWnd()
		{
			m_strXml			= _T("");
			m_hFrameWnd			= NULL;
			m_pCompositorManager				= nullptr;
			m_pCompositor			= nullptr;
			m_pOutLookExplorer	= nullptr;
		}

		CInspectorContainerWnd::~CInspectorContainerWnd()
		{
		}

		LRESULT CInspectorContainerWnd::OnTangramSave(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
		{
			if (m_pOutLookExplorer)
			{
				CComPtr<MAPIFolder> pFolder;
				MAPIFolder* _pFolder = nullptr;
				m_pOutLookExplorer->m_pExplorer->get_CurrentFolder(&pFolder);
				if (pFolder)
				{
					CCompositor* pCompositor = (CCompositor*)m_pCompositor;
					CComBSTR bstrXml(L"");
					COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
					pAddin->UpdateWndNode(pCompositor->m_pWorkNode);
					pCompositor->GetXml(_T(""), &bstrXml);
					CString strXml = g_pTangram->GetXmlData(_T("Tangram"), OLE2T(bstrXml));
					pAddin->WriteFolderPropertyToStore(pFolder, _T("Tangram"), _T("TangramProperties"), strXml);
				}
			}
			return  DefWindowProc(uMsg, wParam, lParam);
		}

		LRESULT CInspectorContainerWnd::OnTangramMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
		{
			if (m_pCompositor&&wParam == 4096)
			{
				m_hFrameWnd = ::GetWindow(m_hWnd, GW_CHILD);
				m_pCompositor->ModifyHost((LONGLONG)m_hFrameWnd);
			}
			return  DefWindowProc(uMsg, wParam, lParam);
		}

		LRESULT CInspectorContainerWnd::OnItemLoad(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
		{
			if (m_pCompositor)
			{
				HWND hwnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_CHILD, 0, 0, 0, 0, g_pTangram->m_hHostWnd, NULL, AfxGetInstanceHandle(), NULL);
				m_pCompositor->ModifyHost((LONGLONG)::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_CHILD, 0, 0, 0, 0, (HWND)hwnd, NULL, AfxGetInstanceHandle(), NULL));
				::DestroyWindow(hwnd);
				m_pCompositor = nullptr;
				m_pCompositorManager = nullptr;
			}
			if (m_strXml != _T(""))
			{
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadXml(m_strXml))
				{
					m_hFrameWnd = ::GetWindow(m_hWnd, GW_CHILD);
					g_pTangram->CreateCompositorManager((LONGLONG)m_hWnd, &m_pCompositorManager);
					m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)m_hFrameWnd), CComBSTR(L"Default"), &m_pCompositor);
					if (m_pCompositor)
					{
						IWndNode* pNode = nullptr;
						CTangramXmlParse* pChild = m_Parse.GetChild(0);
						m_pCompositor->Open(CComBSTR(L""), CComBSTR(pChild->xml()), &pNode);
					}
				}
			}

			return 0;// DefWindowProc(uMsg, wParam, lParam);
		}

		void CInspectorContainerWnd::OnFinalMessage(HWND hWnd)
		{
			CWindowImpl::OnFinalMessage(hWnd);
			delete this;
		}

		COutLookAppCtrl::COutLookAppCtrl()
		{

		}

		STDMETHODIMP COutLookAppCtrl::put_AppCtrl(VARIANT_BOOL newVal)
		{
			g_pTangram->m_pTangramAppCtrl = this;

			return S_OK;
		}

		void COutLookAppCtrl::OnFinalMessage(HWND hWnd)
		{
			__super::OnFinalMessage(hWnd);
		}

		STDMETHODIMP COutLookAppCtrl::get_tag(VARIANT* pVal)
		{
			return S_OK;
		}


		STDMETHODIMP COutLookAppCtrl::put_tag(VARIANT newVal)
		{
			return S_OK;
		}

		STDMETHODIMP COutLookAppCtrl::get_HWND(LONGLONG* pVal)
		{
			*pVal = (LONGLONG)m_hWnd;
			return S_OK;
		}

		STDMETHODIMP COutLookAppCtrl::get_Tangram(ITangram** pVal)
		{
			*pVal = g_pTangram;
			return S_OK;
		}

		void COutLookAppObjEvents::OnItemSend(IDispatch* Item, VARIANT_BOOL* Cancel)
		{
			int nIndex = 0x0000f002;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("ItemSend"), nIndex, pAddin->m_pApplication.p);

					pObj->m_mapDisp[0] = Item;
					pObj->m_mapDisp[0]->AddRef();
					CComVariant var1;
					var1.vt = VT_BOOL | VT_BYREF;
					var1.pboolVal = Cancel;
					pObj->m_mapVar[0] = var1;

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAppObjEvents::OnNewMail()
		{
			int nIndex = 0x0000f003;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("NewMail"), nIndex, pAddin->m_pApplication.p);

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}
		void COutLookAppObjEvents::OnReminder(IDispatch* Item)
		{
			int nIndex = 0x0000f004;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("Reminder"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = Item;
					pObj->m_mapDisp[0]->AddRef();

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAppObjEvents::OnOptionsPagesAdd(PropertyPages* Pages)
		{
			int nIndex = 0x0000f005;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("OptionsPagesAdd"), nIndex, pAddin->m_pApplication.p);

					pObj->m_mapDisp[0] = Pages;
					pObj->m_mapDisp[0]->AddRef();

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAppObjEvents::OnStartup()
		{
			int nIndex = 0x0000f006;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("Startup"), nIndex, pAddin->m_pApplication.p);

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAppObjEvents::OnQuit()
		{
			int nIndex = 0x0000f007;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("Quit"), nIndex, pAddin->m_pApplication.p);

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAppObjEvents2::OnAdvancedSearchComplete(Search* SearchObject) 
		{
			int nIndex = 0x0000fa6a;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("AdvancedSearchComplete"), nIndex, pAddin->m_pApplication.p);
					pObj->m_mapDisp[0] = SearchObject;
					pObj->m_mapDisp[0]->AddRef();

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAppObjEvents2::OnAdvancedSearchStopped(Search* SearchObject)
		{
			int nIndex = 0x0000fa6b;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("AdvancedSearchStopped"), nIndex, pAddin->m_pApplication.p);

					pObj->m_mapDisp[0] = SearchObject;
					pObj->m_mapDisp[0]->AddRef();

					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}

		void COutLookAppObjEvents2::OnMAPILogonComplete() 
		{
			int nIndex = 0x0000fa90;
			COutLookAddin* pAddin = (COutLookAddin*)g_pTangram;
			auto it2 = g_pTangram->m_mapObjEventDic.find(pAddin->m_pApplication.p);
			if (it2 != g_pTangram->m_mapObjEventDic.end())
			{
				CString strEventIndexs = it2->second;
				CString strIndex = _T("");
				strIndex.Format(_T(",%d,"), nIndex);
				if (strEventIndexs.Find(strIndex) != -1)
				{
					CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
					pObj->Init(_T("MAPILogonComplete"), nIndex, pAddin->m_pApplication.p);
					g_pTangram->FireTangramAppEvent(pObj);
				}
			}
		}
	}
}
