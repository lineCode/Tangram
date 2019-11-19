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
*
********************************************************************************/

#include "../stdafx.h"
#include "../TangramApp.h"
#include "../WndNode.h"
#include "../Compositor.h"
#include "../TangramListView.h"
#include "../TangramHtmlTreeWnd.h"
#include "VSAddin.h"
#include "dte.h"
#include "VsProject.h"
#include "VcProject2.h"

#ifndef _WIN64
namespace VisualStudioPlus
{
	CVSClassObjectInfo::CVSClassObjectInfo()
	{
		m_dwATLInfo = 0x10000000;
		m_bVCClass = false;
		m_pCodeType = nullptr;
		m_pVCClass = nullptr;
		m_strBaseClassName = _T("");
	}

	CVSClassObjectInfo::~CVSClassObjectInfo()
	{
		m_pCodeType = nullptr;
		m_strBaseClassName = _T("");
	}

	CString CVSClassObjectInfo::GetName()
	{
		CString strName = _T("");
		if (m_pCodeType)
		{
			BSTR bstrName = ::SysAllocString(L"");
			m_pCodeType->get_Name(&bstrName);
			strName = OLE2T(bstrName);
			::SysFreeString(bstrName);
		}
		return strName;
	}

	CString CVSClassObjectInfo::GetFullName()
	{
		CString strName = _T("");
		if (m_pCodeType)
		{
			BSTR bstrName = ::SysAllocString(L"");
			m_pCodeType->get_FullName(&bstrName);
			strName = OLE2T(bstrName);
			::SysFreeString(bstrName);
		}
		return strName;
	}

	CVSToolPaneWnd::CVSToolPaneWnd()
	{
		m_pTabCtrl = nullptr;
	}

	LRESULT CVSToolPaneWnd::OnTcnSelchangeTab(int /*idCtrl*/, LPNMHDR pNMHDR, BOOL& bHandled)
	{
		TCITEM TabCtrlItem;
		TabCtrlItem.pszText = g_pTangram->m_szBuffer;
		TabCtrlItem.mask |= TCIF_TEXT | TCIF_PARAM;
		TabCtrlItem.cchTextMax = 256;
		int index = m_pTabCtrl->GetCurSel();
		m_pTabCtrl->GetItem(index, &TabCtrlItem);
		CVSAddin* pAddin = (CVSAddin*)g_pTangram;
		CString strItem = TabCtrlItem.pszText;
		CVSClassObjectInfo* pInfo = (CVSClassObjectInfo*)TabCtrlItem.lParam;
		CodeType* pCodeType = pInfo->m_pCodeType;
		if (pCodeType)
		{
			if (pInfo->m_strBaseClassName == _T(""))
			{
				pInfo->m_strBaseClassName = pAddin->GetBaseClassInfo(pCodeType, pAddin->m_strBaseClasses, _T(""));
				pAddin->GetAtlObjInfo(pInfo);
				if (pInfo)
				{
				}
			}
			if (pInfo->m_dwATLInfo& 0x00000010)
			{
			}

			//BSTR bstrName = ::SysAllocString(L"");
			//pCodeType->get_FullName(&bstrName);
			//CString strName = OLE2T(bstrName);
			//strName.Replace(_T("::"), _T("."));
			//CComPtr<ProjectItem> pItem;
			//pCodeType->get_ProjectItem(&pItem);
			//CComPtr<VxDTE::Project> pPrj;
			//pItem->get_ContainingProject(&pPrj);
			//pPrj->get_FullName(&bstrName);
			//CString strPath = OLE2T(bstrName);
			//int nPos = strPath.ReverseFind('\\');
			//strPath = strPath.Left(nPos + 1) + _T("tangramclassinfo\\");
			//if (::PathIsDirectory(strPath) == false)
			//{
			//	::CreateDirectory(strPath, nullptr);
			//}
			//strPath += strName + _T(".classxml");
			//if (::PathFileExists(strPath))
			//{

			//}
//#ifdef _DEBUG
//			CComPtr<CodeElements> pCodeElements;
//			pCodeType->get_Members(&pCodeElements);
//			long nCount = 0;
//			pCodeElements->get_Count(&nCount);
//			for (int i = 1; i <= nCount; i++)
//			{
//				CComPtr<CodeElement> pCodeElement;
//				pCodeElements->Item(CComVariant(i), &pCodeElement);
//				pCodeElement->get_FullName(&bstrName);
//				VxDTE::vsCMElement elemkind;
//				pCodeElement->get_Kind(&elemkind);
//				if (elemkind == VxDTE::vsCMElement::vsCMElementFunction)
//				{
//					CComQIPtr<VxDTE::CodeFunction> pFunc(pCodeElement);
//					if (pFunc)
//					{
//						pFunc->get_FullName(&bstrName);
//						ATLTRACE(_T("====Class Member:%s=======\n"), OLE2T(bstrName));
//						CComPtr<CodeElements> pCodeElements;
//						pFunc->get_Parameters(&pCodeElements);
//						long nCount = 0;
//						pCodeElements->get_Count(&nCount);
//						for (int i = 1; i <= nCount; i++)
//						{
//							CComPtr<CodeElement> pCodeElement;
//							pCodeElements->Item(CComVariant(i), &pCodeElement);
//							pCodeElement->get_FullName(&bstrName);
//							ATLTRACE(_T("====Parameter:%s=======\n"), OLE2T(bstrName));
//							CComQIPtr<CodeParameter>pCodeParameter(pCodeElement);
//							if (pCodeParameter)
//							{
//								CComPtr<CodeTypeRef> pRef;
//								pCodeParameter->get_Type(&pRef);
//								pRef->get_AsString(&bstrName);
//								pCodeParameter->get_FullName(&bstrName);
//							}
//						}
//					}
//				}
//			}
//#endif
			//::SysFreeString(bstrName);
		}
		bHandled = false;
		return 1;
	}

	void CVSToolPaneWnd::OnFinalMessage(HWND hWnd)
	{
		CVSAddin* pAddin = (CVSAddin*)g_pTangram;
		CWindowImpl::OnFinalMessage(hWnd);
		delete this;
	}

	// CTangramVSTabCtrl
	BEGIN_MESSAGE_MAP(CTangramVSTabCtrl, CTabCtrl)
		ON_WM_WINDOWPOSCHANGED()
	END_MESSAGE_MAP()

	CTangramVSTabCtrl::CTangramVSTabCtrl()
	{
		m_pVSListCtrl = nullptr;
	}

	CTangramVSTabCtrl::~CTangramVSTabCtrl()
	{
	}

	void CTangramVSTabCtrl::PostNcDestroy()
	{
		CTabCtrl::PostNcDestroy();
		delete this;
	}

	void CTangramVSTabCtrl::RePosition()
	{
		if (m_pVSListCtrl&&::IsWindow(m_pVSListCtrl->m_hWnd))
		{
			RECT  rc;
			GetWindowRect(&rc);
			AdjustRect(false, &rc);
			ScreenToClient(&rc);
			rc.left += 4;
			rc.top += 4;
			::SetWindowPos(m_pVSListCtrl->m_hWnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left - 1, rc.bottom - rc.top - 1, SWP_NOACTIVATE | SWP_NOREDRAW/**/);
		}
	}

	int CTangramVSTabCtrl::RefreshTabCtrl(CVSDocument* pDoc)
	{
		int nIndex = 0;
		DeleteAllItems();
		if (pDoc)
		{
			int nSize = pDoc->m_mapClass.size();
			if (nSize)
			{
				CComBSTR bstrName(L"");
				for (auto it : pDoc->m_mapClass)
				{
					it.second->m_pCodeType->get_Name(&bstrName);
					TCITEM tcItem;
					tcItem.mask = TCIF_TEXT | TCIF_PARAM;
					tcItem.pszText = OLE2T(bstrName);
					tcItem.lParam = (LPARAM)it.second;
					InsertItem(nIndex, &tcItem);
					nIndex++;
				}
				if (m_pVSListCtrl&&::IsWindow(m_pVSListCtrl->m_hWnd))
				{
					RECT  rc;
					GetWindowRect(&rc);
					AdjustRect(false, &rc);
					ScreenToClient(&rc);
					rc.left += 4;
					rc.top += 4;
					::SetWindowPos(m_pVSListCtrl->m_hWnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left - 1, rc.bottom - rc.top - 1, SWP_FRAMECHANGED);
				}
				CVSAddin* pAddin = (CVSAddin*)g_pTangram;
				TCITEM TabCtrlItem;
				TabCtrlItem.pszText = g_pTangram->m_szBuffer;
				TabCtrlItem.mask |= TCIF_TEXT | TCIF_PARAM;
				TabCtrlItem.cchTextMax = 256;
				GetItem(0, &TabCtrlItem);
				CString strItem = TabCtrlItem.pszText;
				CVSClassObjectInfo* pInfo = (CVSClassObjectInfo*)TabCtrlItem.lParam;
				CodeType* pCodeType = pInfo->m_pCodeType;
				if (pCodeType)
				{
					if (pInfo->m_strBaseClassName == _T(""))
					{
						pInfo->m_strBaseClassName = pAddin->GetBaseClassInfo(pCodeType, pAddin->m_strBaseClasses, _T(""));
						pAddin->GetAtlObjInfo(pInfo);
					}
					//BSTR bstrName = ::SysAllocString(L"");
					//pCodeType->get_FullName(&bstrName);
					//CString strName = OLE2T(bstrName);
					//ATLTRACE(_T("===================Current Class Info: class name:%s, Base name:%s===================\n"), strName, pInfo->m_strBaseClassName);
					//strName.Replace(_T("::"), _T("."));
					//CComPtr<ProjectItem> pItem;
					//pCodeType->get_ProjectItem(&pItem);
					//CComPtr<VxDTE::Project> pPrj;
					//pItem->get_ContainingProject(&pPrj);
					//pPrj->get_FullName(&bstrName);
					//CString strPath = OLE2T(bstrName);
					//int nPos = strPath.ReverseFind('\\');
					//strPath = strPath.Left(nPos + 1) + _T("tangramclassinfo\\");
					//if (::PathIsDirectory(strPath) == false)
					//{
					//	::CreateDirectory(strPath, nullptr);
					//}
					//strPath += strName + _T(".classxml");
					//if (::PathFileExists(strPath))
					//{

					//}
//#ifdef _DEBUG
//					CComPtr<CodeElements> pCodeElements;
//					pCodeType->get_Members(&pCodeElements);
//					long nCount = 0;
//					pCodeElements->get_Count(&nCount);
//					for (int i = 1; i <= nCount; i++)
//					{
//						CComPtr<CodeElement> pCodeElement;
//						pCodeElements->Item(CComVariant(i), &pCodeElement);
//						pCodeElement->get_FullName(&bstrName);
//						VxDTE::vsCMElement elemkind;
//						pCodeElement->get_Kind(&elemkind);
//						if (elemkind == VxDTE::vsCMElement::vsCMElementFunction)
//						{
//							CComQIPtr<VxDTE::CodeFunction> pFunc(pCodeElement);
//							if (pFunc)
//							{
//								pFunc->get_FullName(&bstrName);
//								ATLTRACE(_T("====Class Member:%s=======\n"), OLE2T(bstrName));
//								CComPtr<CodeElements> pCodeElements;
//								pFunc->get_Parameters(&pCodeElements);
//								long nCount = 0;
//								pCodeElements->get_Count(&nCount);
//								for (int i = 1; i <= nCount; i++)
//								{
//									CComPtr<CodeElement> pCodeElement;
//									pCodeElements->Item(CComVariant(i), &pCodeElement);
//									pCodeElement->get_FullName(&bstrName);
//									ATLTRACE(_T("====Parameter:%s=======\n"), OLE2T(bstrName));
//									CComQIPtr<CodeParameter>pCodeParameter(pCodeElement);
//									if (pCodeParameter)
//									{
//										CComPtr<CodeTypeRef> pRef;
//										pCodeParameter->get_Type(&pRef);
//										pRef->get_AsString(&bstrName);
//										pCodeParameter->get_FullName(&bstrName);
//									}
//								}
//							}
//						}
//					}
//#endif
					//::SysFreeString(bstrName);
				}
			}
		}
		return nIndex;
	}

	void CTangramVSTabCtrl::OnWindowPosChanged(WINDOWPOS* lpwndpos)
	{
		CTabCtrl::OnWindowPosChanged(lpwndpos);
		RePosition();
	}

	// CTangramVSListCtrl
	CTangramVSListCtrl::CTangramVSListCtrl()
	{
	}

	CTangramVSListCtrl::~CTangramVSListCtrl()
	{
	}

	void CTangramVSListCtrl::PostNcDestroy()
	{
		CListCtrl::PostNcDestroy();
		delete this;
	}

	BEGIN_MESSAGE_MAP(CTangramVSListCtrl, CListCtrl)
	END_MESSAGE_MAP()

	CVSDocument::CVSDocument()
	{
		m_strName = _T("");
		m_strPath = _T("");
		m_strPath2 = _T("");
		m_pTextDoc = nullptr;
		m_pDocument = nullptr;
		m_pDocEvent = nullptr;
		m_pTextDocumentKeyPressEvents = nullptr;
	}

	CVSDocument::~CVSDocument()
	{
		for (auto it : m_mapClass)
		{
			delete it.second;
		}
		CVSAddin* pAddin = (CVSAddin*)g_pTangram;
		auto itDoc = pAddin->m_mapVSDoc.find(m_strPath);
		if (itDoc != pAddin->m_mapVSDoc.end())
		{
			pAddin->m_mapVSDoc.erase(itDoc);
		}
		if (m_pDocEvent)
		{
			HRESULT hr = S_FALSE;
			if(m_pTextDocumentKeyPressEvents)
				hr = ((CDTETextDocumentKeyPressEvents*)this)->DispEventUnadvise((_TextDocumentKeyPressEvents*)m_pTextDocumentKeyPressEvents);
			hr = ((CDTEDocumentEvents*)this)->DispEventUnadvise((_DocumentEvents*)m_pDocEvent);
		}
	}

	STDMETHODIMP CVSDocument::get_Count(long* pCount)
	{
		*pCount = (long)m_mapClass.size();
		return S_OK;
	}

	STDMETHODIMP CVSDocument::get_VSClass(VARIANT vIndex, IDispatch **ppCodeType)
	{
		if (vIndex.vt == VT_I4)
		{
			long lCount = m_mapClass.size();
			int iIndex = vIndex.lVal;
			if (iIndex < 0 || iIndex >= lCount) return E_INVALIDARG;

			auto it = m_mapClass.begin();
			int iPos = 0;
			while (it != m_mapClass.end())
			{
				if (iPos == iIndex) break;
				iPos++;
				it++;
			}

			CodeType* pNode = it->second->m_pCodeType;
			*ppCodeType = pNode;
			return S_OK;
		}

		if (vIndex.vt == VT_BSTR)
		{
			CString strKey = OLE2T(vIndex.bstrVal);
			auto it = m_mapClass.find(strKey);
			if (it != m_mapClass.end())
			{
				*ppCodeType = it->second->m_pCodeType;
				return S_OK;
			}
			return E_INVALIDARG;
		}

		return S_OK;
	}

	STDMETHODIMP CVSDocument::get__NewEnum(IUnknown** ppVal)
	{
		typedef CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT>>
			CComEnumVariant;

		CComObject<CComEnumVariant> *pe = 0;
		HRESULT hr = pe->CreateInstance(&pe);

		if (SUCCEEDED(hr))
		{
			pe->AddRef();
			long nLen = (long)m_mapClass.size();
			VARIANT* rgvar = new VARIANT[nLen];
			ZeroMemory(rgvar, sizeof(VARIANT)*nLen);
			VARIANT* pItem = rgvar;
			for (auto it : m_mapClass)
			{
				IUnknown* pDisp = nullptr;
				CodeType* pObj = it.second->m_pCodeType;
				hr = pObj->QueryInterface(IID_IUnknown, (void**)&pDisp);
				pItem->vt = VT_UNKNOWN;
				pItem->punkVal = pDisp;
				if (pItem->punkVal != nullptr)
					pItem->punkVal->AddRef();
				pItem++;
				pDisp->Release();
			}

			hr = pe->Init(rgvar, &rgvar[nLen], 0, AtlFlagTakeOwnership);
			if (SUCCEEDED(hr))
				hr = pe->QueryInterface(IID_IUnknown, (void**)ppVal);
			pe->Release();
		}
		return S_OK;
	}

	//void CVSDocument::OnAfterKeyPress(BSTR Keypress, VxDTE::TextSelection * Selection, VARIANT_BOOL InStatementCompletion)
	//{
	//	CVSAddin* pAddin = (CVSAddin*)g_pTangram;
	//	CodeElement* pElem = nullptr;
	//	VxDTE::VirtualPoint* pPoint = nullptr;
	//	Selection->get_ActivePoint(&pPoint);
	//	if (pPoint)
	//	{
	//		pPoint->get_CodeElement(VxDTE::vsCMElement::vsCMElementClass, &pElem);
	//		if (pElem)
	//		{
	//			CComQIPtr<VCCodeClass> pClass(pElem);
	//			if (pClass)
	//			{
	//				CComBSTR bstrName(L"");
	//				pClass->get_FullName(&bstrName);
	//				CString strName = OLE2T(bstrName);
	//				CString strInfo = _T("");
	//				strInfo.Format(_T("*********************************Current Edit Class Obj:%s*********************************\n"), OLE2T(bstrName));
	//				pAddin->PutTextToOutputPane(strInfo.AllocSysString());
	//				pClass->get_BodyText(&bstrName);
	//				strName = OLE2T(bstrName);
	//				strInfo = _T("");
	//				strInfo.Format(_T("*********************************\nCurrent Edit Class Obj Body: \n%s\n*********************************\n"), OLE2T(bstrName));
	//				pAddin->PutTextToOutputPane(strInfo.AllocSysString());
	//			}
	//		}
	//		pElem = nullptr;
	//		pPoint->get_CodeElement(VxDTE::vsCMElement::vsCMElementFunction, &pElem);
	//		if (pElem)
	//		{
	//			CComQIPtr<VCCodeFunction> pFunc(pElem);
	//			if (pFunc)
	//			{
	//				CComBSTR bstrName(L"");
	//				pFunc->get_FullName(&bstrName);
	//				CString strName = OLE2T(bstrName);
	//				CString strInfo = _T("");
	//				strInfo.Format(_T("*********************************Current Edit Code Obj:%s*********************************\n"), OLE2T(bstrName));
	//				pAddin->PutTextToOutputPane(strInfo.AllocSysString());
	//				pFunc->get_BodyText(&bstrName);
	//				strName = OLE2T(bstrName);
	//				strInfo = _T("");
	//				strInfo.Format(_T("*********************************\nCurrent Edit Code Obj Body:\n%s\n*********************************\n"), OLE2T(bstrName));
	//				pAddin->PutTextToOutputPane(strInfo.AllocSysString());
	//			}
	//		}
	//	}
	//}

	//void CVSDocument::OnLineChanged(VxDTE::TextPoint* StartPoint, VxDTE::TextPoint* EndPoint, long Hint) 
	//{ 
	//	if (StartPoint)
	//	{
	//		CodeElement* pElem = nullptr;
	//		StartPoint->get_CodeElement(VxDTE::vsCMElement::vsCMElementClass, &pElem);
	//		if (pElem)
	//		{
	//			CComBSTR bstrName(L"");
	//			pElem->get_FullName(&bstrName);
	//			CString strName = OLE2T(bstrName);
	//		}
	//	}
	//}

	void CVSDocument::OnDocumentClosing(VxDTE::Document* Document)
	{
		CVSAddin* pAddin = (CVSAddin*)g_pTangram;
		if (::PathFileExists(m_strPath2))
			pAddin->m_pTangramPackageProxy->ShowTangramToolWnd(false, 2);
		delete this;
	}

	CVSAddin::CVSAddin()
	{
		m_bFrameDefaultState				= true;
		m_pToolBoxWnd						= nullptr;
		m_pDTE								= nullptr;
		m_pOutputWindowPane					= nullptr;
		m_pTangramVSTabCtrl					= nullptr;
		CVSExtender* pExtender				= new CComObject<CVSExtender>;
		pExtender->m_pAddin					= this;
		m_pTangramListView					= nullptr;
		m_pExtender							= pExtender;
		m_strBaseClasses					= _T("");
	}

	CVSAddin::~CVSAddin()
	{
	}

	void CVSAddin::TangramToolTabCtrlCreated(HWND hTabCtrl) 
	{
		CTangramVSTabCtrl* pTabCtrl = new CTangramVSTabCtrl();
		CVSToolPaneWnd* pVSToolPaneWnd = new CVSToolPaneWnd();
		pVSToolPaneWnd->m_pTabCtrl = pTabCtrl;
		pVSToolPaneWnd->SubclassWindow(::GetParent(hTabCtrl));
		HWND hListCtrl = ::GetDlgItem(pVSToolPaneWnd->m_hWnd, 1001);
		pTabCtrl->SubclassWindow(hTabCtrl);
		if (::IsWindow(hListCtrl))
		{
			if (::GetWindowLongPtr(hTabCtrl, GWLP_USERDATA) == 2)
			{
				m_pTangramVSTabCtrl = pTabCtrl;
			}
			pTabCtrl->ModifyStyle(0, TCS_MULTILINE);
			pVSToolPaneWnd->ModifyStyle(0, WS_CLIPCHILDREN);
			pTabCtrl->m_pVSListCtrl = new CTangramVSListCtrl();
			pTabCtrl->m_pVSListCtrl->SubclassWindow(hListCtrl);
		}
	}

	void CVSAddin::CreateCommonDesignerToolBar()
	{
		if (m_pToolBoxWnd == nullptr)
		{
			CComQIPtr<DTE2> pDTE2(m_pDTE);
			CComPtr<ToolWindows> pToolWindows;
			pDTE2->get_ToolWindows(&pToolWindows);
			VxDTE::ToolBox* pToolBox = nullptr;
			pToolWindows->get_ToolBox(&pToolBox);
			if (pToolBox)
			{
				pToolBox->get_Parent(&m_pToolBoxWnd);
			}
		}
		if(m_pToolBoxWnd)
			m_pToolBoxWnd->put_Visible(true);
		if (m_pTangramPackageProxy&&::IsWindow(m_hVSToolBoxWnd)==false)
		{
			m_hVSToolBoxWnd = ::GetParent(m_pTangramPackageProxy->CreateTangramToolWnd());
		}
		if (::IsWindow(m_hVSToolBoxWnd))
		{
			if (m_pTangramPackageProxy->m_pToolBoxFrame)
			{
				auto it = m_mapValInfo.find(_T("tangramtoolbox"));
				if (it != m_mapValInfo.end())
				{
					IWndNode* pNode = nullptr;
					m_pTangramPackageProxy->m_pToolBoxFrame->Open(CComBSTR("tangramtoolbox"), it->second.bstrVal, &pNode);
				}
				//m_pTangramPackageProxy->m_pToolBoxFrame->ExtendFromWeb(CComBSTR(""), CComBSTR("tangramdesigner"), CComBSTR("TangramTeam"), CComBSTR("TangramDesigner"), CComBSTR("master"), CComBSTR("vsdesigner/tangramtoolbox.xml"));
			}
		}
	}

	void CVSAddin::PutTextToOutputPane(BSTR bstrMsg)
	{
		if (m_pOutputWindowPane)
		{
			m_pOutputWindowPane->Activate();
			m_pOutputWindowPane->OutputString(bstrMsg);
		}
	}

	CString CVSAddin::FillClassInfo(CTangramXmlParse* pParse)
	{
		CString strRet = _T("");
		CString strName = pParse->name();
		int nCount = pParse->GetCount();
		for (int i = 0; i < nCount; i++)
		{
			CTangramXmlParse* _pChild = pParse->GetChild(i);
			strRet += _pChild->name() + _T(",");
			FillClassInfo(_pChild);
		}
		if (strRet != _T(""))
		{
			m_mapClassInfo[strName] = strRet;
		}
		return strRet;
	}

	void CVSAddin::GetAtlObjInfo(CVSClassObjectInfo* pInfo)
	{
		if (pInfo&&pInfo->m_dwATLInfo == 0x10000000/* && pInfo->m_strBaseClassName != _T("")*/)
		{
			pInfo->m_dwATLInfo = 0x00000000;
			//Cpp:		{B5E9BD32-6D3E-4B5D-925E-8A43B79820B4}
			//CLR:		{B5E9BD33-6D3E-4B5D-925E-8A43B79820B4}vsCMLanguageVB
			//CLRCore:	{B5E9BD34-6D3E-4B5D-925E-8A43B79820B4}vsCMLanguageCSharp
			BSTR bstrName = ::SysAllocString(L"");
			pInfo->m_pCodeType->get_Language(&bstrName);
			CString strName = OLE2T(bstrName);
			if (strName == CString(vsCMLanguageVC))
			{
				VxDTE::CodeElements *pCodeElements = nullptr;
				//pInfo->m_pCodeType->get_Kind()
				pInfo->m_pCodeType->get_Bases(&pCodeElements);
				if (pCodeElements)
				{
					long nCount = 0;
					pCodeElements->get_Count(&nCount);
					for (int i = 1; i <= nCount; i++)
					{
						VxDTE::CodeElement *pCodeElement = nullptr;
						pCodeElements->Item(CComVariant((int)i), &pCodeElement);

						pCodeElement->get_Name(&bstrName);
						strName = OLE2T(bstrName);
						if (strName == _T("CComObjectRootEx"))
						{
							pInfo->m_dwATLInfo |= VCCLASS_ComObjectRootEx;
						}
						else if (strName == _T("CComObjectRootBase"))
						{
							pInfo->m_dwATLInfo |= VCCLASS_ComObjectRootBase;
						}
						else if (strName == _T("CComControl"))
						{
							pInfo->m_dwATLInfo |= VCCLASS_ComControl;
						}
						else if (strName == _T("IDispEventSimpleImpl"))
						{
							pInfo->m_dwATLInfo |= VCCLASS_IDispEventSimpleImpl;
						}
						else if (strName == _T("CWindowImpl"))
						{
							pInfo->m_dwATLInfo |= VCCLASS_WindowImpl;
						}
						VxDTE::vsCMElement element;
						pCodeElement->get_Kind(&element);
						_GetAtlObjInfo(pInfo, pCodeElement);
					}
				}
			}
			::SysFreeString(bstrName);
		}
	}

	void CVSAddin::_GetAtlObjInfo(CVSClassObjectInfo* pInfo, CodeElement* pCodeElement)
	{
		VxDTE::CodeElements *pCodeElements = nullptr;
		pCodeElement->get_Children(&pCodeElements);
		if (pCodeElements)
		{
			long nCount = 0;
			pCodeElements->get_Count(&nCount);
			for (int i = 1; i <= nCount; i++)
			{
				VxDTE::CodeElement *pCodeElement = nullptr;
				pCodeElements->Item(CComVariant((int)i), &pCodeElement);
				BSTR bstrName = ::SysAllocString(L"");

				pCodeElement->get_Name(&bstrName);

				CString strName = OLE2T(bstrName);
				if (strName == _T("CComObjectRootEx"))
				{
					pInfo->m_dwATLInfo |= VCCLASS_ComObjectRootEx;
				}
				else if (strName == _T("CComObjectRootBase"))
				{
					pInfo->m_dwATLInfo |= VCCLASS_ComObjectRootBase;
				}
				else if (strName == _T("CComControl"))
				{
					pInfo->m_dwATLInfo |= VCCLASS_ComControl;
				}
				else if (strName == _T("IDispEventSimpleImpl"))
				{
					pInfo->m_dwATLInfo |= VCCLASS_IDispEventSimpleImpl;
				}
				else if (strName == _T("CWindowImpl"))
				{
					pInfo->m_dwATLInfo |= VCCLASS_WindowImpl;
				}
				::SysFreeString(bstrName);

				_GetAtlObjInfo(pInfo, pCodeElement);
			}
		}
	}

	CString CVSAddin::GetBaseClassInfo(CodeType* pCodeType, CString _strBaseClasses, CString strLastBaseName)
	{
		CString strRet = strLastBaseName;
		CString strBaseClasses = _strBaseClasses;
		int nPos = strBaseClasses.Find(_T(","));
		VARIANT_BOOL bIsBase = false;
		while (nPos != -1)
		{
			CString strClass = strBaseClasses.Left(nPos);
			pCodeType->get_IsDerivedFrom(CComBSTR(strClass), &bIsBase);
			if (bIsBase)
			{
				auto it = m_mapClassInfo.find(strClass);
				if (it != m_mapClassInfo.end())
				{
					strRet = GetBaseClassInfo(pCodeType, it->second, strClass);
					auto it2 = m_mapClassInfo.find(strRet);
					if (it2 == m_mapClassInfo.end())
						break;
				}
				else
				{
					return strClass;
				}
			}
			strBaseClasses = strBaseClasses.Mid(nPos + 1);
			nPos = strBaseClasses.Find(_T(","));
			if (nPos == -1 && strBaseClasses == _T(""))
			{
				if (strRet != _T(""))
					return strRet;
				strRet = strLastBaseName;
				break;
			}
		}
		return strRet;
	}

	void CVSAddin::OnInitInstance()
	{
		if (m_pDTE)
		{
			long nCount = 0;
			LoadCLR();
			HRESULT hr = S_FALSE;
			m_PrjImageList.Create(48, 48, ILC_COLOR32, 0, 4);

			//CComQIPtr<DTE2> pDTE2(m_pDTE);
			//CComPtr<ToolWindows> pToolWindows;
			//pDTE2->get_ToolWindows(&pToolWindows);
			//CComPtr<OutputWindow> pOutWnd;
			//pToolWindows->get_OutputWindow(&pOutWnd);
			//if (pOutWnd)
			//{
			//	CComPtr<OutputWindowPane> pPane;
			//	CComPtr<OutputWindowPanes> pPanes;
			//	pOutWnd->get_OutputWindowPanes(&pPanes);
			//	pPanes->Item(CComVariant(L"Tangram"), &pPane);
			//	if (pPane == nullptr)
			//	{
			//		pPanes->Add(CComBSTR(L"Tangram"), &pPane);
			//		pPane->OutputString(CComBSTR(L"Welcome to Tangram for Visual Studio!\r\n"));
			//	}
			//	m_pOutputWindowPane = pPane.Detach();
			//	m_pOutputWindowPane->AddRef();
			//}
			if (::IsWindow(m_hHostWnd) == false)
			{
				m_hHostWnd = ::CreateWindowEx(WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW, _T("Tangram Window Class"), m_strDesignerToolBarCaption, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, 0, 0, NULL, NULL, theApp.m_hInstance, NULL);
				m_hChildHostWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, m_hHostWnd, NULL, theApp.m_hInstance, NULL);
				m_mapValInfo[_T("hostwnd")] = CComVariant((long)m_hHostWnd);
				m_mapValInfo[_T("hostchildwnd")] = CComVariant((long)m_hChildHostWnd);
			}
		}
	}

	void CVSAddin::DotNetControlCreated(MSG* lpMsg) 
	{
		// We get the DotNet Control object (System.Windows.Forms.PropertyGrid) contained in the Properties window in Visual Studio.
		// In order to monitor Visual Studio by hooking its OnSelectedObjectsChanged event.
		// Visual Studio lazy load Tangram extension. Therefore, there are two situations here.
		// 1. The Properties window has been opened if Visual Studio was last closed. Visual Studio will remember it. The Properties
		// window will be automatically opened the next time you open Visual Studio. In this case, the Tangram extension can not capture
		// the creation message of the Properties window via CBTProc. You need to read the CTangramApp::InitPropertyWnd function to learn
		// about another way to handle it.
		// 2. The Properties window has not been created if the Tangram extension is loaded. Tangram will programmatically trigger 
		// Visual Studio to create it (explained below). At this point, the following steps can be used to filter out the win32 window 
		// corresponding to the PropertyGrid.
		// 1) Filter all Microsoft.Net controls by checking the window class name starting with "WindowsForms10."
		// 2) Call the Control::FromHandle method to get the control object corresponding to the window handle, and check if the type
		// name is "Microsoft.VisualStudio.PropertyBrowser.PropertyGridHolder". It is a derived class of PropertyGrid.
		// 3) Make sure its parent window is "Microsoft.VisualStudio.PropertyBrowser.PropertyBrowser"
		// 4) Make sure its grandfather window is "GenericPane"
		//
		// Properties window hierarchy
		//
		// - "Properties" GenericPane
		//   - "Property Browser" Microsoft.VisualStudio.PropertyBrowser.PropertyBrowser
		//     - "" System.Windows.Forms.ComboBox
		//     - "PropertyGrid" Microsoft.VisualStudio.PropertyBrowser.PropertyGridHolder
		//
		// If you try to get the corresponding VxDTE::Window of the Properties window by calling the VxDTE interface, Visual Studio 
		// creates the Properties window and places it in a hidden window queue. At this point, although the window has been created,
		// it can not receive events normally. It needs to be visible.
		if (m_pTangramPackageProxy->m_hVSGridView == nullptr) {
			HWND hWnd = (HWND)lpMsg->wParam;
			CComPtr<IDispatch> pCtrl = m_pCLRProxy->GetCtrlFromHandle(hWnd);
			if (pCtrl != nullptr && m_pCLRProxy->IsSpecifiedType(pCtrl, CComBSTR("Microsoft.VisualStudio.PropertyBrowser.PropertyGridHolder"))) {
				HWND hPWnd = (HWND)lpMsg->lParam;
				if (::IsWindow(hPWnd)) {
					CComPtr<IDispatch> ppCtrl = m_pCLRProxy->GetCtrlFromHandle(hPWnd);
					if (ppCtrl != nullptr && m_pCLRProxy->IsSpecifiedType(ppCtrl, CComBSTR("Microsoft.VisualStudio.PropertyBrowser.PropertyBrowser"))) 
					{
						m_pTangramPackageProxy->m_hPropertyPWnd = ::GetParent(hPWnd);
						m_pTangramPackageProxy->m_hPropertyWnd = hPWnd;
						m_pTangramPackageProxy->m_hVSGridView = hWnd;
						m_pCLRProxy->AttachVSPropertyWnd(hWnd);
					}
				}
			}
		}
	}

	void CVSAddin::GetClassesFromNameSpace(VCCodeNamespace* pVCCodeNamespace, CVSDocument* pVSDocument)
	{
		long nCount = 0;
		VxDTE::CodeElements* pCodeElements = nullptr;
		pVCCodeNamespace->get_Classes(&pCodeElements);
		if (pCodeElements)
		{
			pCodeElements->get_Count(&nCount);
			for (int i = 1; i <= nCount; i++)
			{
				VxDTE::CodeElement* pCodeElement = nullptr;
				pCodeElements->Item(CComVariant(i), &pCodeElement);
				CComQIPtr<CodeType> pCodeType(pCodeElement);
				if (pCodeType)
				{
					if (pVSDocument)
					{
						CComBSTR bstrName(L"");
						pCodeElement->get_FullName(&bstrName);
						CString strName = OLE2T(bstrName);
						CVSClassObjectInfo* pInfo = new CVSClassObjectInfo();
						pInfo->m_pCodeType = pCodeType.p;
						CComQIPtr<VCCodeClass> pVCCodeClass(pCodeType.p);
						if (pVCCodeClass)
						{
							pInfo->m_pVCClass = pVCCodeClass.p;
							pInfo->m_bVCClass = true;
						}
						pVSDocument->m_mapClass[strName] = pInfo;
					}
				}
			}
		}

		VxDTE::CodeElements *pCodeNameSpaces = nullptr;
		pVCCodeNamespace->get_Namespaces(&pCodeNameSpaces);
		if(pCodeNameSpaces)
		{
			pCodeNameSpaces->get_Count(&nCount);
			for (int i = 1; i <= nCount; i++)
			{
				VxDTE::CodeElement* pCodeElement = nullptr;
				pCodeNameSpaces->Item(CComVariant(i), &pCodeElement);
				CComQIPtr<VCCodeNamespace> pVCCodeNamespace(pCodeElement);
				GetClassesFromNameSpace(pVCCodeNamespace, pVSDocument);
			}
		}
	}

	void CVSAddin::ProcessCodeInfo(VxDTE::CodeElement *pCodeElement, CVSDocument* pVSDocument)
	{
		if (pCodeElement)
		{
			CComBSTR bstrName(L"");
			pCodeElement->get_FullName(&bstrName);
			CString strName = OLE2T(bstrName);
			vsCMElement m_vsCMElement;
			pCodeElement->get_Kind(&m_vsCMElement);
			ATLTRACE(_T("====================VxDTE::CodeElement FullName : %s CodeElement Type:%d==================\n"), OLE2T(bstrName), m_vsCMElement);
			switch (m_vsCMElement)
			{
				case vsCMElement::vsCMElementClass:
					{
						//Cpp:		{B5E9BD32-6D3E-4B5D-925E-8A43B79820B4}
						//CLR:		{B5E9BD33-6D3E-4B5D-925E-8A43B79820B4}
						//CLRCore:	{B5E9BD34-6D3E-4B5D-925E-8A43B79820B4}
						pCodeElement->get_Language(&bstrName);
						CString str = OLE2T(bstrName);
						str = str.Left(9);
						str = str.Mid(7);
						int nIndex = _wtoi(str);
						VARIANT_BOOL bCodeType = false;
						pCodeElement->get_IsCodeType(&bCodeType);

						if (bCodeType)
						{
							CComQIPtr<CodeType> pCodeType(pCodeElement);
							if (pCodeType)
							{
								if (pVSDocument)
								{
									CVSClassObjectInfo* pInfo = new CVSClassObjectInfo();
									pInfo->m_pCodeType = pCodeType.p;
									CComQIPtr<VCCodeClass> pVCCodeClass(pCodeType.p);
									if (pVCCodeClass)
									{
										pInfo->m_pVCClass = pVCCodeClass.p;
										pInfo->m_bVCClass = true;
									}
									pVSDocument->m_mapClass[strName] = pInfo;
								}
							}
						}
					}
					break;
				default:
					break;
			}
			VxDTE::CodeElements *pCodeElements = nullptr;
			pCodeElement->get_Children(&pCodeElements);
			if (pCodeElements)
			{
				long nCount = 0;
				pCodeElements->get_Count(&nCount);
				for (int i = 1; i <= nCount; i++)
				{
					VxDTE::CodeElement *pCodeElement = nullptr;
					pCodeElements->Item(CComVariant((int)i), &pCodeElement);
					ProcessCodeInfo(pCodeElement, pVSDocument);
				}
			}
		}
	}

	STDMETHODIMP CVSAddin::get_AppKeyValue(BSTR bstrKey, VARIANT* pVal)
	{
		CString strKey = OLE2T(bstrKey);
		if (pVal&&strKey != _T(""))
		{
			strKey.Trim();
			strKey.MakeLower();
			if (strKey == _T("mainwnd"))
			{
				long hMainWnd = 0;
				CComPtr<VxDTE::Window> pMainWnd;
				m_pDTE->get_MainWindow(&pMainWnd);
				if (pMainWnd)
				{
					pMainWnd->get_HWnd(&hMainWnd);
					if (hMainWnd)
					{
						pVal->vt = VT_I4;
						pVal->llVal = hMainWnd;
					}
				}
				return S_OK;
			}
		}
		return CTangram::get_AppKeyValue(bstrKey, pVal);
	}

	STDMETHODIMP CVSAddin::put_AppKeyValue(BSTR bstrKey, VARIANT newVal)
	{
		CString strKey = OLE2T(bstrKey);
		if (strKey == _T(""))
			return S_OK;
		strKey.Trim();
		strKey.MakeLower();
		if (strKey.CompareNoCase(_T("VSTabCtrl")) == 0 && newVal.llVal)
		{
			TangramToolTabCtrlCreated((HWND)newVal.llVal);
			return S_OK;
		}
		if (strKey.CompareNoCase(_T("TangramPackageProxy")) == 0)
		{
			if (newVal.llVal)
			{
				m_mapValInfo[strKey] = newVal;
				m_pTangramPackageProxy = (CTangramPackageProxy*)newVal.llVal;
				m_pTangramPackageProxy->m_pProxy = (CTangramImpl*)this;
				m_bEnableProcessFormTabKey = false;
				return S_OK;
			}
		}
		if (strKey.CompareNoCase(_T("TangramDesignerXml")) == 0)
		{
			m_mapValInfo[strKey] = newVal;
			CString strXml = OLE2T(newVal.bstrVal);
			if (m_pDocDOMTree)
			{
				m_pDocDOMTree->DeleteItem(m_pDocDOMTree->m_hFirstRoot);
				if (m_pDocDOMTree->m_pHostXmlParse)
				{
					delete m_pDocDOMTree->m_pHostXmlParse;
				}
				InitDesignerTreeCtrl(strXml);
			}

			return S_OK;
		}
		return CTangram::put_AppKeyValue(bstrKey, newVal);
	}

	void CVSAddin::TangramInit()
	{
		if (::IsWindow(m_hTangramWnd))
			return;
		ATLTRACE(_T("begin CVSAddin::TangramInit:%x\n"), this);
		m_hTangramWnd = ::CreateWindowEx(WS_EX_NOACTIVATE, _T("Tangram Message Window Class"), _T(""), WS_VISIBLE | WS_POPUP, 0, 0, 0, 0, nullptr, nullptr, theApp.m_hInstance, nullptr);
		CTangram::TangramInit();
		if (m_pTangramPackageProxy&&::IsWindow(m_pTangramPackageProxy->m_hTangramToolWnd))
		{
			ATLTRACE(_T("end CVSAddin::TangramInit:%x\n"), this);
			auto it = m_mapWindowPage.find(::GetParent(m_pTangramPackageProxy->m_hTangramToolWnd));
			if (it != m_mapWindowPage.end())
			{
				m_pCompositorManager = it->second;
				ICompositor* pCompositor = nullptr;
				m_pCompositorManager->CreateCompositor(CComVariant((LONGLONG)::GetParent(m_pTangramPackageProxy->m_hTangramToolWnd)), CComVariant((LONGLONG)m_pTangramPackageProxy->m_hTangramToolWnd), CComBSTR("TangramToolBar"), &pCompositor);
				CString strDataPath = m_strProgramFilePath + _T("\\Tangram\\vsdesigner\\toolwnd.xml");
				CString strURL = _T("https://tangramdesigner.com/");
				CString strKey = _T("default");
				CString strOrg = _T("tangramdesigner");
				CString strRepo = _T("");
				CString strBranch = _T("");
				CString strPath = _T("vstoolwindow.xml");
				if (::PathFileExists(strDataPath))
				{
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadFile(strDataPath))
					{
						strURL = m_Parse.attr(_T("url"), _T("https://tangramdesigner.com/"));
						strKey = m_Parse.attr(_T("key"), _T("default"));
						strOrg = m_Parse.attr(_T("org"), _T("tangramdesigner"));
						strRepo = m_Parse.attr(_T("repo"), _T(""));
						strBranch = m_Parse.attr(_T("branch"), _T(""));
						strPath = m_Parse.attr(_T("path"), _T("vstoolwindow.xml"));
					}
					pCompositor->OpenFromWeb(CComBSTR(strURL), CComBSTR(strKey), CComBSTR(strOrg), CComBSTR(strRepo), CComBSTR(strBranch), CComBSTR(strPath));
				}
				else
				{
					auto it = m_mapValInfo.find(_T("tangramtoolwnd"));
					if (it != m_mapValInfo.end())
					{
						IWndNode* pNode = nullptr;
						pCompositor->Open(CComBSTR("default"), it->second.bstrVal, &pNode);
					}
				}
			}
		}
	}

	void CVSAddin::ClearOutputPane()
	{
		if (m_pOutputWindowPane)
		{
			m_pOutputWindowPane->Clear();
		}
	}

	CVSExtender::CVSExtender()
	{

	}

	CVSExtender::~CVSExtender()
	{

	}

	STDMETHODIMP CVSExtender::Close()
	{
		delete this;
		return S_OK;
	}

	STDMETHODIMP CVSExtender::get_ActiveWorkBenchWindow(BSTR bstrID, IWorkBenchWindow** pVal)
	{
		CString strID = OLE2T(bstrID);
		strID.Trim();
		if (strID != _T(""))
		{
			ITangram* pTangram = nullptr;
			m_pAddin->get_RemoteTangram(bstrID, &pTangram);
			if (pTangram)
			{
				IWorkBenchWindow* pRet = nullptr;
				ITangramExtender* pExtender = nullptr;
				pTangram->get_Extender(&pExtender);
				if (pExtender)
				{
					CComQIPtr<IEclipseExtender> pEclipse(pExtender);
					if (pEclipse)
						pEclipse->get_ActiveWorkBenchWindow(bstrID, &pRet);
					if (pRet)
					{
						*pVal = pRet;
						(*pVal)->AddRef();
					}
				}
			}
		}

		return S_OK;
	}

	STDMETHODIMP CVSExtender::get_DesignRootNode(IWndNode** ppRetVal)
	{
		if (g_pTangram->m_pDesignRootNode)
			*ppRetVal = g_pTangram->m_pDesignRootNode;
		return S_OK;
	}

	STDMETHODIMP CVSExtender::put_DesignRootNode(IWndNode* newVal)
	{
		if (newVal == nullptr)
		{
			g_pTangram->m_pDesignRootNode = nullptr;
			return S_OK;
		}

		g_pTangram->m_pDesignRootNode = (CWndNode*)newVal;
		return S_OK;
	}

	STDMETHODIMP CVSExtender::get_DesignNode(IWndNode** pVal)
	{
		if (g_pTangram->m_pDesignWindowNode)
			(*pVal) = (IWndNode*)g_pTangram->m_pDesignWindowNode;
		return S_OK;
	}

	STDMETHODIMP CVSExtender::get_CurrentDesignNode(IWndNode** ppRetVal)
	{
		if (g_pTangram->m_pHostDesignUINode)
			*ppRetVal = g_pTangram->m_pHostDesignUINode;
		return S_OK;
	}

	STDMETHODIMP CVSExtender::put_CurrentDesignNode(IWndNode* newVal)
	{
		if (newVal == nullptr)
		{
			g_pTangram->m_pHostDesignUINode = nullptr;
			return S_OK;
		}
		if (m_pAddin->m_hChildHostWnd == nullptr&&m_pAddin->m_pTangramPackageProxy == nullptr)
			m_pAddin->CreateCommonDesignerToolBar();
		g_pTangram->m_pHostDesignUINode = (CWndNode*)newVal;
		return S_OK;
	}


	STDMETHODIMP CVSExtender::get_TangramCLRProject(BSTR bstrPrjPath, VARIANT_BOOL* pVal)
	{
		CString strPath = OLE2T(bstrPrjPath);
		CVSAddin* pVSAddin = (CVSAddin*)g_pTangram;
		//int nType = pVSAddin->IsTangramProject(strPath);
		//if(nType==2)
		//{ 
		//	*pVal = true;
		//}
		return S_OK;
	}

	STDMETHODIMP CVSExtender::put_TangramCLRProject(BSTR bstrPrjPath, VARIANT_BOOL newVal)
	{
		CString strPath = OLE2T(bstrPrjPath);
		CVSAddin* pVSAddin = (CVSAddin*)g_pTangram;
		pVSAddin->UpdateProjectforTangram(strPath);

		return S_OK;
	}

	STDMETHODIMP CVSExtender::get_CurrentSelectedPrj(BSTR* pVal)
	{
		return S_OK;
	}

	STDMETHODIMP CVSExtender::ExtendXmlUI(BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode)
	{
		CVSAddin* pVSAddin = (CVSAddin*)g_pTangram;
		CString strXml = OLE2T(bstrXml);
		CTangramXmlParse m_Parse;
		if(pVSAddin->m_pTangramPackageProxy->m_pCompositor&&(m_Parse.LoadFile(strXml)|| m_Parse.LoadXml(strXml)))
		{
			if (m_Parse.GetChild(_T("window")))
			{
				pVSAddin->m_pTangramPackageProxy->m_pCompositor->Open(bstrKey, bstrXml, ppNode);
			}
		}

		return S_OK;
	}
}
#endif

