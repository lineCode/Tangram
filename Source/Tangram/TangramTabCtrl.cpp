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
********************************************************************************/

// TangramTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "TangramApp.h"
#include "WndNode.h"
#include "Compositor.h"
#include "TangramTabCtrl.h"
#include "TangramListView.h"
#include "VisualStudioPlus/VSAddin.h"

#include <io.h>
#include <stdio.h>

// CTangramListCtrl

IMPLEMENT_DYNAMIC(CTangramListCtrl, CListCtrl)

CTangramListCtrl::CTangramListCtrl()
{
	m_nListViewIndex = 0;
	m_nListViewSelectedIndex = 0;
	m_strDir = _T("");
	m_strSubDir = _T("");
	if (g_pTangram->m_strExeName.CompareNoCase(_T("excel")) == 0)
	{
		auto it = g_pTangram->m_mapValInfo.find(_T("exceldesignstate"));
		if (it == g_pTangram->m_mapValInfo.end())
			g_pTangram->m_mapValInfo[_T("exceldesignstate")] = CComVariant((VARIANT_BOOL)true);
	}
}

CTangramListCtrl::~CTangramListCtrl()
{
}


BEGIN_MESSAGE_MAP(CTangramListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CTangramListCtrl::OnNMDblclk)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CTangramListCtrl::OnLvnItemchanged)
END_MESSAGE_MAP()


// CTangramListCtrl message handlers

void CTangramListCtrl::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (m_pTangramTabCtrl->m_pCompositor == nullptr)
	{
		ICompositor* pCompositor = nullptr;
		ICompositorManager* _pCompositorManager = nullptr;
		g_pTangram->CreateCompositorManager((__int64)m_hWnd, &_pCompositorManager);
		CCompositorManager* pCompositorManager = (CCompositorManager*)_pCompositorManager;
		if (pCompositorManager)
		{
			auto it = pCompositorManager->m_mapCompositor.find(m_pTangramTabCtrl->m_ListCtrl.m_hWnd);
			if (it == pCompositorManager->m_mapCompositor.end())
			{
				pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((__int64)m_pTangramTabCtrl->m_ListCtrl.m_hWnd), CComBSTR("HostListView"), &pCompositor);
				if (pCompositor)
					m_pTangramTabCtrl->m_pCompositor = (CCompositor*)pCompositor;
			}
		}
	}
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	if (g_pTangram->m_pTangramPackageProxy&&m_pTangramTabCtrl->m_pTangramListView)
	{
		CString strFile = m_strDir + m_strSubDir + _T("\\") + GetItemText(pNMLV->iItem, 0) + _T(".xml");
		if(pNMLV->uNewState)
			g_pTangram->m_pTangramPackageProxy->CreateTangramHelpToolWnd(strFile);
		*pResult = 0;
		return;
	}
	CString strText = GetItemText(pNMLV->iItem, 0);
	CString strFile = m_strDir + m_strSubDir + _T("\\") + strText + _T(".html");
	CString strPath = g_pTangram->m_strAppCommonDocPath;
	IWndNode* pNode = nullptr;
	if (::PathFileExists(strFile))
	{
		strPath += _T("templatedetail.xml");
		m_pTangramTabCtrl->m_pCompositor->Open(CComBSTR("HostListView"), CComBSTR(strPath), &pNode);
		if (m_pTangramTabCtrl->m_pWebBrowser2 == nullptr)
		{
			IWndNode* pWebNode = nullptr;
			pNode->GetNode(0, 1, &pWebNode);
			if (pWebNode)
			{
				CWndNode* _pNode = (CWndNode*)pWebNode;
				CComQIPtr<IWebBrowser2> pWebCtrl(_pNode->m_pDisp);
				if (pWebCtrl)
					m_pTangramTabCtrl->m_pWebBrowser2 = pWebCtrl.Detach();
			}
		}
		if(m_pTangramTabCtrl->m_pWebBrowser2)
			m_pTangramTabCtrl->m_pWebBrowser2->Navigate2(&CComVariant(strFile), &CComVariant(navNoReadFromCache | navNoWriteToCache), NULL, NULL, NULL);
	}
	else if (strText.CompareNoCase(_T("new Template"))==0)
	{
		strPath += _T("newtemplate.xml");
		m_pTangramTabCtrl->m_pCompositor->Open(CComBSTR("newtemplate"), CComBSTR(strPath), &pNode);
	}
	else
	{
		CString strXml = _T("<tangram><window><node name=\"start\" id=\"hostview\" /></window></tangram>"); 
		//_T("<tangram><window><node name=\"listviewhost\", id=\"hostview\"></node></window></tangram>");
		m_pTangramTabCtrl->m_pCompositor->Open(CComBSTR("defaultListView"), CComBSTR(strXml), &pNode);
	}

	*pResult = 0;
}

void CTangramListCtrl::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	if (g_pTangram->m_pMDIMainWnd == nullptr&&g_pTangram->m_pActiveMDIChildWnd)
	{
		if (::IsChild(g_pTangram->m_pActiveMDIChildWnd->m_hWnd, g_pTangram->m_hTemplateWnd))
		{
			RECT rc;
			::GetWindowRect(g_pTangram->m_pDocTemplateFrame->m_pWorkNode->m_pHostWnd->m_hWnd, &rc);
			g_pTangram->m_pActiveMDIChildWnd->ScreenToClient(&rc);

			::ShowWindow(g_pTangram->m_hTemplateWnd, SW_HIDE);
			::SetParent(g_pTangram->m_hTemplateWnd, g_pTangram->m_hHostWnd);
			::ShowWindow(g_pTangram->m_pActiveMDIChildWnd->m_pCompositor->m_pWorkNode->m_pHostWnd->m_hWnd, SW_SHOW);
			::SetWindowLongPtr(g_pTangram->m_pActiveMDIChildWnd->m_hChild,GWLP_ID, AFX_IDW_PANE_FIRST);

			::SetWindowPos(g_pTangram->m_pActiveMDIChildWnd->m_hChild, HWND_TOP, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, SWP_FRAMECHANGED);
		}
		int nItem = pNMItemActivate->iItem;
		if (nItem == -1)
		{
			return;
		}

		switch (m_nListViewIndex)
		{
		case 0:
			{
				auto it = g_pTangram->m_mapTangramDocTemplateInfo.find(m_nListViewSelectedIndex);
				if (it != g_pTangram->m_mapTangramDocTemplateInfo.end())
				{
					CString strTemplateFile = m_strDir + m_strSubDir + _T("\\") + GetItemText(nItem, 0);// +it->second->m_strFilter.Mid(1);
					if(it->second->m_strFilter!=_T("*.*"))
						strTemplateFile += it->second->m_strFilter.Mid(1);;
					if (it->second->m_bCOMObj)
					{
						g_pTangram->StartApplication(it->second->m_strProxyID.AllocSysString(), strTemplateFile.AllocSysString());
					}
					else
					{
						ITangramAppProxy* pProxy = nullptr;
						CString strLib = it->second->m_strProxyID;
						strLib.Trim();
						strLib.MakeLower();
						BOOL bOK = FALSE;
						if (strLib == _T("") || strLib.CompareNoCase(_T("default")) == 0)
						{
							pProxy = g_pTangram->m_pTangramAppProxy;
						}
						auto it2 = g_pTangram->m_mapTangramAppProxy.find(it->second->m_strProxyID);
						if (it2 == g_pTangram->m_mapTangramAppProxy.end())
						{
							if (::LoadLibrary(it->second->m_strLib))
							{
								if (g_pTangram->m_hForegroundIdleHook == NULL)
									g_pTangram->m_hForegroundIdleHook = SetWindowsHookEx(WH_FOREGROUNDIDLE, CTangramApp::ForegroundIdleProc, NULL, ::GetCurrentThreadId());
								it2 = g_pTangram->m_mapTangramAppProxy.find(it->second->m_strProxyID);
								if (it2 != g_pTangram->m_mapTangramAppProxy.end())
								{
									pProxy = (ITangramAppProxy*)it2->second;
								}
							}
						}
						else
						{
							pProxy = it2->second;
						}
						if (it->second->m_strLib == _T(""))
							pProxy = g_pTangram->m_pTangramAppProxy;

						if (pProxy&&it->second->m_strLib != _T(""))
						{
							auto it2 = g_pTangram->m_mapTemplateInfo.find(it->second->m_strExt);
							if (it2 != g_pTangram->m_mapTemplateInfo.end())
							{
								CTangramXmlParse m_Parse;
								if (m_Parse.LoadFile(strTemplateFile))
								{
									g_pTangram->m_pActiveMDIChildWnd = nullptr;
									g_pTangram->m_strCurrentFrameID = m_Parse.attr(_T("mainframeid"), _T("default"));
									CString strAppTitle = m_Parse.attr(_T("apptitle"), g_pTangram->m_strCurrentFrameID);
									g_pTangram->m_strCurrentFrameID.MakeLower();
									g_pTangram->m_strCurrentDocTemplateXml = m_Parse.xml();
									pProxy->m_strCreatingFrameTitle = strAppTitle;
									pProxy->CreateNewDocument(g_pTangram->m_strCurrentFrameID, strAppTitle, it2->second, false);
								}
							}
						}
						else
						{
							auto it2 = g_pTangram->m_mapValInfo.find(_T("exceldesignstate"));
							if (it2 != g_pTangram->m_mapValInfo.end())
							{
								return;
							}
							IWndNode* pNode = nullptr;
							CCompositor* pCompositor = m_pTangramTabCtrl->m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
							pCompositor->Open(pCompositor->m_strLastKey.AllocSysString(), CComBSTR(_T("")), &pNode);
							TangramDocTemplateInfo* pTangramDocTemplateInfo = it->second;
							g_pTangram->m_pTangramDocTemplateInfo = pTangramDocTemplateInfo;
							g_pTangram->m_strTemplatePath = strTemplateFile;
							CTangramXmlParse m_Parse;
							if (m_Parse.LoadFile(g_pTangram->m_strTemplatePath))
							{
								g_pTangram->m_strStartupCLRObj = strTemplateFile;
								g_pTangram->m_strTemplatePath = m_Parse.xml();
								//fix at 20170715
								::SendMessage(g_pTangram->m_pActiveMDIChildWnd->m_hWnd, WM_TANGRAMMSG, (WPARAM)pTangramDocTemplateInfo->m_pDocTemplate, TANGRAM_CONST_NEWDOC);
								if (g_pTangram->m_nAppType != 1965)
								{
									g_pTangram->m_pActiveMDIChildWnd->OnCreateDoc(g_pTangram->m_strTemplatePath);
									g_pTangram->m_strTemplatePath = _T("");
								}
							}
						}
						g_pTangram->m_bNewFile = FALSE;
					}
				}
			}
			break;
		}
		return;
	}
	IWndNode* pNode = nullptr;
	CCompositor* pCompositor = m_pTangramTabCtrl->m_pWndNode->m_pTangramNodeCommonData->m_pCompositor;
	int nItem = pNMItemActivate->iItem;
	if (nItem == -1)
	{
		::GetClassName(pCompositor->m_hWnd, g_pTangram->m_szBuffer, MAX_PATH);
		CString strName = g_pTangram->m_szBuffer;
		pCompositor->m_bChromeFrame = strName == _T("Chrome Extended Window Class");
		CString strKey = pCompositor->m_strLastKey;
		if (pCompositor->m_pWebWnd)
		{
			if (strKey == _T(""))
			{
				strKey = _T("__default__key__for__chrome__");
			}
			pCompositor->Open(strKey.AllocSysString(), CComBSTR(g_pTangram->m_strDefaultXml), &pNode);
		}
		else
		{
			pCompositor->Open(strKey.AllocSysString(), CComBSTR(_T("")), &pNode);
		}
		return;
	}

	switch (m_nListViewIndex)
	{
	case 0:
	{
		HWND hWnd = pCompositor->GetParent().m_hWnd;
		if (hWnd != g_pTangram->m_hHostWnd)
		{
			::GetClassName(pCompositor->m_hWnd, g_pTangram->m_szBuffer, MAX_PATH);
			CString strName = g_pTangram->m_szBuffer;
			pCompositor->m_bChromeFrame = strName == _T("Chrome Extended Window Class");
			CString strKey = pCompositor->m_strLastKey;
			if (pCompositor->m_bChromeFrame)
			{
				if (strKey == _T(""))
				{
					strKey = _T("__default__key__for__chrome__");
				}
				pCompositor->Open(strKey.AllocSysString(), CComBSTR(g_pTangram->m_strDefaultXml), &pNode);
			}
			else
			{
				if (g_pTangram->m_strExeName.CompareNoCase(_T("excel")))
					pCompositor->Open(strKey.AllocSysString(), CComBSTR(_T("")), &pNode);
			}
		}

		auto it = g_pTangram->m_mapTangramDocTemplateInfo.find(m_nListViewSelectedIndex);
		if (it != g_pTangram->m_mapTangramDocTemplateInfo.end())
		{
			CString strTemplateFile = m_strDir + m_strSubDir + _T("\\") + GetItemText(nItem, 0);
			if (it->second->m_strFilter != _T("*.*"))
				strTemplateFile += it->second->m_strFilter.Mid(1);
			if (it->second->m_bCOMObj)
			{
				if (g_pTangram->m_bEclipse)
				{

				}
				else
					g_pTangram->StartApplication(it->second->m_strProxyID.AllocSysString(), strTemplateFile.AllocSysString());
			}
			else
			{
				ITangramAppProxy* pProxy = nullptr;
				CString strLib = it->second->m_strProxyID;
				strLib.Trim();
				strLib.MakeLower();
				BOOL bOK = FALSE;
				if (strLib == _T("") || strLib.CompareNoCase(_T("default")) == 0)
				{
					pProxy = g_pTangram->m_pTangramAppProxy;
				}
				auto it2 = g_pTangram->m_mapTangramAppProxy.find(it->second->m_strProxyID);
				if (it2 == g_pTangram->m_mapTangramAppProxy.end())
				{
					if (::LoadLibrary(it->second->m_strLib))
					{
						if (g_pTangram->m_hForegroundIdleHook == NULL)
							g_pTangram->m_hForegroundIdleHook = SetWindowsHookEx(WH_FOREGROUNDIDLE, CTangramApp::ForegroundIdleProc, NULL, ::GetCurrentThreadId());
						it2 = g_pTangram->m_mapTangramAppProxy.find(it->second->m_strProxyID);
						if (it2 != g_pTangram->m_mapTangramAppProxy.end())
						{
							pProxy = (ITangramAppProxy*)it2->second;
						}
					}
				}
				else
				{
					pProxy = it2->second;
				}
				if (it->second->m_strLib == _T(""))
					pProxy = g_pTangram->m_pTangramAppProxy;

				if (pProxy&&it->second->m_pDocTemplate==nullptr/*it->second->m_strLib != _T("")*/)
				{
					bool bCreateDoc = false;
					auto it2 = g_pTangram->m_mapTemplateInfo.find(it->second->m_strExt);
					if (it2 != g_pTangram->m_mapTemplateInfo.end())
					{
						CTangramXmlParse m_Parse;
						if (m_Parse.LoadFile(strTemplateFile))
						{
							g_pTangram->m_pActiveMDIChildWnd = nullptr;
							g_pTangram->m_strCurrentFrameID = m_Parse.attr(_T("mainframeid"), _T("default"));
							CString strAppTitle = m_Parse.attr(_T("apptitle"), g_pTangram->m_strCurrentFrameID);
							g_pTangram->m_strCurrentFrameID.MakeLower();
							g_pTangram->m_strCurrentDocTemplateXml = m_Parse.xml();
							pProxy->m_strCreatingFrameTitle = strAppTitle;
							bCreateDoc = true;
							pProxy->CreateNewDocument(g_pTangram->m_strCurrentFrameID, strAppTitle, it2->second, false);
						}
					}
					if (bCreateDoc == false)
					{
						if (it->second->m_pDocTemplate == nullptr)
						{
							CString strID = it->second->m_strProxyID;
							strID.Replace(_T("tangram"), _T(""));
							it->second->m_pDocTemplate = (void*)_wtoi64(strID);
						}
						if (it->second->m_pDocTemplate)
						{
							pProxy->OpenDocument(it->second->m_pDocTemplate, _T(""), true);
						}
					}
					//else
					//{
					//	TangramDocTemplateInfo* pTangramDocTemplateInfo = it->second;
					//	g_pTangram->m_pTangramDocTemplateInfo = pTangramDocTemplateInfo;
					//	g_pTangram->m_strTemplatePath = strTemplateFile;
					//	CTangramXmlParse m_Parse;
					//	if (m_Parse.LoadFile(g_pTangram->m_strTemplatePath))
					//	{
					//		if (g_pTangram->m_pMDIMainWnd)
					//		{
					//			::SendMessage(g_pTangram->m_pMDIMainWnd->m_hWnd, WM_QUERYAPPPROXY, (WPARAM)pTangramDocTemplateInfo->m_pDocTemplate, TANGRAM_CONST_NEWDOC);
					//			if (g_pTangram->m_strDefaultTemplate2 == _T(""))
					//				g_pTangram->m_pMDIMainWnd->OnCreateDoc(_T(""));
					//		}
					//	}
					//}
				}
				else
				{
					TangramDocTemplateInfo* pTangramDocTemplateInfo = it->second;
					g_pTangram->m_pTangramDocTemplateInfo = pTangramDocTemplateInfo;
					g_pTangram->m_strTemplatePath = strTemplateFile;
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadFile(g_pTangram->m_strTemplatePath))
					{
						if (g_pTangram->m_pMDIMainWnd)
						{
							::SendMessage(g_pTangram->m_pMDIMainWnd->m_hWnd, WM_QUERYAPPPROXY, (WPARAM)pTangramDocTemplateInfo->m_pDocTemplate, TANGRAM_CONST_NEWDOC);
							if(g_pTangram->m_strDefaultTemplate2==_T(""))
								g_pTangram->m_pMDIMainWnd->OnCreateDoc(_T(""));
						}
					}
				}
			}
			g_pTangram->m_bNewFile = FALSE;
		}
		else
		{
			CTangramWinFormWnd* pWnd = nullptr;
			map<CString, TangramDocTemplateInfo*>*	m_pMapTangramFormsTemplateInfo = &g_pTangram->m_mapTangramFormsTemplateInfo;
			map<int, TangramDocTemplateInfo*>*		m_pMapTangramFormsTemplateInfo2 = &g_pTangram->m_mapTangramFormsTemplateInfo2;
			CString strFormsInfoPath = _T("");
			HWND hParent = NULL;
			if (m_pTangramTabCtrl)
			{
				hParent = m_pTangramTabCtrl->m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->m_pCompositorManager->m_hWnd;
				if (hParent)
				{
					pWnd = (CTangramWinFormWnd*)::SendMessage(hWnd, WM_TANGRAMDATA, 0, 20190214);
					if (pWnd)
					{
						strFormsInfoPath = pWnd->m_strChildFormPath;
						m_pMapTangramFormsTemplateInfo = &pWnd->m_mapTangramFormsTemplateInfo;
						m_pMapTangramFormsTemplateInfo2 = &pWnd->m_mapTangramFormsTemplateInfo2;
					}
				}
			}

			CString strItem = m_pTangramTabCtrl->m_pTangramListView->GetListCtrl().GetItemText(m_nListViewSelectedIndex, 0);
			CString strTemplateFile = _T("");
			if (strFormsInfoPath == _T(""))
				strTemplateFile = m_strDir + m_strSubDir + _T("\\") + GetItemText(nItem, 0);
			else
				strTemplateFile = strFormsInfoPath + strItem + _T("\\") + m_strSubDir + _T("\\") + GetItemText(nItem, 0);
			auto it = m_pMapTangramFormsTemplateInfo->find(strItem);
			if (it != m_pMapTangramFormsTemplateInfo->end())
			{
				if (g_pTangram->m_pCLRProxy == nullptr)
					g_pTangram->LoadCLR();
				if (g_pTangram->m_pCLRProxy)
				{
					g_pTangram->m_strAppCurrentFormTemplatePath = strTemplateFile + it->second->m_strExt;
					g_pTangram->m_bCreatingForm = true;
					if(strFormsInfoPath==_T(""))
						g_pTangram->m_pCLRProxy->Extend(strItem, strTemplateFile, _T("tangram:creatingform"));
					else
						g_pTangram->m_pCLRProxy->Extend(strItem, strTemplateFile, _T("tangram:creatingmdichildform"));
				}
			}
			else
			{
				auto it = m_pMapTangramFormsTemplateInfo2->find(m_nListViewSelectedIndex);
				if (it != m_pMapTangramFormsTemplateInfo2->end())
				{
					if (g_pTangram->m_pCLRProxy == nullptr)
						g_pTangram->LoadCLR();
					if (g_pTangram->m_pCLRProxy)
					{
						g_pTangram->m_strAppCurrentFormTemplatePath = strTemplateFile + it->second->m_strExt;
						g_pTangram->m_bCreatingForm = true;
						if (::IsChild(g_pTangram->m_hHostWnd, m_hWnd))
						{
							if (pNMItemActivate->iItem == 0)
							{
								CTangramWinFormWnd* pWnd = (CTangramWinFormWnd*)g_pTangram->m_pCLRProxy->Extend(it->second->m_strProxyID, m_strDir, L"tangram:creatingform:design:new");
								if (pWnd)
								{
									CString strFile = pWnd->m_strPath;
									int nPos = strFile.ReverseFind('\\');
									CString strDir = strFile.Left(nPos + 1);
									CString strText = strFile.Mid(nPos + 1);
									nPos = strText.ReverseFind('\\');
									strText = strText.Mid(nPos + 1);
									::SHCreateDirectory(nullptr, strDir);
									CString strXml = _T("<winform></winform>");
									CTangramXmlParse m_Parse;
									m_Parse.LoadXml(strXml);
									m_Parse.SaveFile(strFile);
									int nItem = pNMItemActivate->iItem;
									LVITEM item;
									item.mask = LVFI_PARAM | LVIF_IMAGE | LVIF_TEXT;
									item.iSubItem = 0;
									item.iImage = 0;
									item.iItem = 0;
									this->GetItem(&item);
									int nImage = item.iImage;
									//InsertItem(&item);
									item.iItem = this->GetItemCount();
									item.pszText = strText.GetBuffer();
									item.iImage = nItem;
									InsertItem(&item);
								}
							}
							else
							{
								g_pTangram->m_pCLRProxy->Extend(it->second->m_strProxyID, strTemplateFile + it->second->m_strExt, L"tangram:creatingform:design");
							}
						}
						else
						{
							if(strFormsInfoPath==_T(""))
								g_pTangram->m_pCLRProxy->Extend(it->second->m_strProxyID, strTemplateFile + it->second->m_strExt, L"tangram:creatingform");
							else
							{
								CString str = _T(""); 
								str.Format(_T("%s:%d"),it->second->m_strProxyID, hParent);
								CString strFeatures = _T("tangram:creatingmdichildform");
								if (pWnd&&pWnd->m_nState == 1)
								{
									strFeatures = _T("tangram:creatingmdichildform:design");
								}

								g_pTangram->m_pCLRProxy->Extend(str, strTemplateFile + it->second->m_strExt, strFeatures);
							}
						}
					}
				}
			}
		}
	}
	break;
	case 1:
	{
	}
	break;
	}
	*pResult = 0;
}

// CTangramTabCtrl

IMPLEMENT_DYNCREATE(CTangramTabCtrl, CTabCtrl)

CTangramTabCtrl::CTangramTabCtrl()
{
	m_nImageIndex = 0;
	m_strFilter = _T("*.xml");
	m_pCompositor = nullptr;
	m_pWndNode = nullptr;
	m_pWebBrowser2 = nullptr;
	m_pTangramListView = nullptr;
}

CTangramTabCtrl::~CTangramTabCtrl()
{
}

BEGIN_MESSAGE_MAP(CTangramTabCtrl, CTabCtrl)
	ON_WM_MOUSEACTIVATE()
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnTcnSelchange)
	ON_MESSAGE(WM_INITIALUPDATE, OnInitialUpdate)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()

// CTangramTabCtrl message handlers

BOOL CTangramTabCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	m_pWndNode = g_pTangram->m_pActiveNode;
	m_pWndNode->m_pHostWnd = this;
	m_pWndNode->m_nViewType = TabCtrl;
	m_pWndNode->m_nID = nID;
	BOOL bRet = CTabCtrl::Create(dwStyle| TCS_MULTILINE|WS_CLIPCHILDREN, rect, pParentWnd, nID);
	m_ListCtrl.Create(WS_CHILD | WS_VISIBLE| LVS_AUTOARRANGE | LVS_SINGLESEL | LVS_SHAREIMAGELISTS | LVS_SHOWSELALWAYS, CRect(0, 0, 0, 0), this, 0);
	m_ListCtrl.m_pTangramTabCtrl = this;
	::GetModuleFileName(theApp.m_hInstance, g_pTangram->m_szBuffer, MAX_PATH);

	int width=320, heigh=90, clines=3;
	CComBSTR bstrVal("");
	m_pWndNode->get_Attribute(CComBSTR("sizeandclines"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("SizeandcLines(%d,%d,%d)"), &width, &heigh, &clines);
	}

	SIZE size = { width, heigh};
	LVTILEVIEWINFO tileViewInfo = { 0 };

	tileViewInfo.cbSize = sizeof(tileViewInfo);
	tileViewInfo.dwFlags = LVTVIF_FIXEDSIZE;
	tileViewInfo.dwMask = LVTVIM_COLUMNS | LVTVIM_TILESIZE;
	tileViewInfo.cLines = clines;
	tileViewInfo.sizeTile = size;

	ListView_SetTileViewInfo(m_ListCtrl.m_hWnd, &tileViewInfo);
	ListView_SetView(m_ListCtrl.m_hWnd, LV_VIEW_TILE);
	CString strPath = g_pTangram->m_szBuffer;
	int nPos = strPath.ReverseFind('\\');
	strPath = strPath.Left(nPos + 1) + _T("TangramInit.dll");
	if (::PathFileExists(strPath))
	{
		CString strURL = _T("res://");
		strURL += strPath;
		strURL += _T("/images/tangrambk.png");
		m_ListCtrl.SetBkImage(LPTSTR(LPCTSTR(strURL)), TRUE);
	}

	PostMessage(WM_INITIALUPDATE);
	return bRet;
}

LRESULT CTangramTabCtrl::OnInitialUpdate(WPARAM wParam, LPARAM lParam)
{
	CComBSTR bstrKey(L"relationnode");
	m_pWndNode->get_Attribute(bstrKey, &bstrKey);
	CString strKey = OLE2T(bstrKey);
	if (strKey == _T("TangramList"))
	{
		if (g_pTangram->m_DocTemplateImageList.m_hImageList == 0)
			g_pTangram->m_DocTemplateImageList.Create(32, 32, ILC_COLOR32, 0, 4);
		m_ListCtrl.SetImageList(&g_pTangram->m_DocTemplateImageList, LVSIL_NORMAL);
	}
	if (strKey == _T("TangramListCLR"))
	{
#ifndef _WIN64
		if (g_pTangram->m_nAppID == 9)
		{
			m_ListCtrl.m_nListViewIndex = 1;
			VisualStudioPlus::CVSAddin* pVSAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;
			m_ListCtrl.SetImageList(&pVSAddin->m_PrjImageList, LVSIL_NORMAL);
		}
#endif
	}
	CComPtr<IWndNodeCollection> pColl;
	CWndNode* pNode = m_pWndNode->m_pRootObj;
	IWndNode* _pNode = nullptr;
	long nCount = 0;
	pNode->GetNodes(bstrKey, &_pNode, &pColl, &nCount);
	if (_pNode)
	{
		CWndNodeCollection* pWndNodeCollection = (CWndNodeCollection*)pColl.p;

		for (auto it : *pWndNodeCollection->m_pNodes)
		{
			CTangramListView* pWnd = (CTangramListView*)(it)->m_pHostWnd;
			pWnd->m_pTangramTabCtrl = this;
			pWnd->InitTabCtrl(this);
			if(m_ListCtrl.m_nListViewIndex == 1)
				pWnd->FillListViewBySolution();
		}
	}

	return CWnd::DefWindowProc(WM_INITIALUPDATE, wParam, lParam);
}

void CTangramTabCtrl::PostNcDestroy()
{
	if (m_pWndNode)
		delete m_pWndNode;

	CTabCtrl::PostNcDestroy();
	delete this;
}

int CTangramTabCtrl::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (g_pTangram->m_pTangramAppProxy)
	{
		HWND hMenuWnd = g_pTangram->m_pTangramAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
	g_pTangram->m_pActiveNode = m_pWndNode;
	g_pTangram->m_bWinFormActived = false;
	return MA_ACTIVATE;
}

void CTangramTabCtrl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	FillListCtrl();
	*pResult = 0;
}

void CTangramTabCtrl::RePosition()
{
	if (::IsWindow(m_ListCtrl.m_hWnd))
	{
		RECT  rc;
		GetWindowRect(&rc);
		AdjustRect(false, &rc);
		ScreenToClient(&rc);
		rc.top += 2;
		::SetWindowPos(m_ListCtrl.m_hWnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, SWP_NOACTIVATE| SWP_NOREDRAW);
	}
}

void CTangramTabCtrl::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CTabCtrl::OnWindowPosChanged(lpwndpos);
	RePosition();
}

void CTangramTabCtrl::FillListCtrl()
{
	m_ListCtrl.DeleteAllItems();
	TCITEM TabCtrlItem;
	TabCtrlItem.pszText = g_pTangram->m_szBuffer;
	TabCtrlItem.mask |= TCIF_TEXT;
	TabCtrlItem.cchTextMax = 256;
	int index = GetCurSel();
	GetItem(index, &TabCtrlItem);
	CString strItem = TabCtrlItem.pszText;
	m_ListCtrl.m_strSubDir = strItem;
	CString m_strDocTemplatePath = m_ListCtrl.m_strDir + strItem + _T("\\") + m_strFilter;

	LVITEM item;
	item.mask = LVFI_PARAM | LVIF_IMAGE | LVIF_TEXT;
	item.iSubItem = 0;
	item.iImage = m_nImageIndex;
	int nItem = 0;

	// Create `New Template` icon when tab control belong to designer window.
	if (::IsChild(g_pTangram->m_hHostWnd, m_hWnd))
	{
		item.iItem = nItem;
		item.pszText = L"New Template";
		item.lParam = nItem;
		m_ListCtrl.InsertItem(&item);
		nItem++;
	}

	_wfinddata_t fd;
	fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
	intptr_t pf = _wfindfirst(m_strDocTemplatePath, &fd);
	while (pf!=-1)
	{
		if ((fd.attrib&FILE_ATTRIBUTE_DIRECTORY)==0)
		{
			CString str = fd.name;
			if (str != _T(".."))
			{
				item.iItem = nItem;
				if(m_strFilter!=_T("*.*"))
					str = str.Left(str.ReverseFind('.'));
				item.pszText = str.GetBuffer();
				item.lParam = nItem;
				m_ListCtrl.InsertItem(&item);
				nItem++;
			}
		}
		if (_wfindnext(pf, &fd) == -1)
			break;
	}
	if (nItem)
	{
		m_ListCtrl.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
	}

	_findclose(pf);
	RePosition();
	::InvalidateRect(m_hWnd, nullptr, true);
	CString strPath = g_pTangram->m_strAppCommonDocPath + _T("templatedetail.xml");
	if (::PathFileExists(strPath))
	{
		IWndNode* pNode = nullptr;
		CString strTemplateFile = m_ListCtrl.m_strDir + m_ListCtrl.m_strSubDir + _T("\\") + m_ListCtrl.GetItemText(0, 0)+ _T(".html");
		if (::PathFileExists(strTemplateFile))
		{
			m_pCompositor->Open(CComBSTR("HostListView"), CComBSTR(strPath), &pNode);
			if (m_pWebBrowser2 == nullptr)
			{
				CWndNode* _pNode = (CWndNode*)pNode;
				IWndNode* pWebNode = nullptr;
				_pNode->GetNode(0, 1, &pWebNode);
				if (pWebNode)
				{
					CWndNode* _pNode = (CWndNode*)pWebNode;
					CComQIPtr<IWebBrowser2> pWebCtrl(_pNode->m_pDisp);
					if (pWebCtrl)
						m_pWebBrowser2 = pWebCtrl.Detach();
				}
			}
			if (m_pWebBrowser2)
				m_pWebBrowser2->Navigate2(&CComVariant(strTemplateFile), &CComVariant(navNoReadFromCache | navNoWriteToCache), NULL, NULL, NULL);
		}
		else
		{
			strPath = g_pTangram->m_strAppCommonDocPath + _T("default.xml");
			if(m_pCompositor)
				m_pCompositor->Open(CComBSTR("default"), CComBSTR(strPath), &pNode);
		}
	}
}

