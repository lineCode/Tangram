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

// TangramListView.cpp : implementation file
//

#include "stdafx.h"
#include "TangramListView.h"
#include "TangramApp.h"
#include "WndNode.h"
#include "Compositor.h"
#include "TangramTabCtrl.h"
#include <io.h>
#include <stdio.h>
#include "VisualStudioPlus/VSAddin.h"

// CTangramListView

IMPLEMENT_DYNCREATE(CTangramListView, CListView)

CTangramListView::CTangramListView()
{
	m_bCreated = FALSE;
	m_bFilling = FALSE;
	m_nStyle = 0;
	m_nActiveIndex = 0;
	m_pCompositor = nullptr;
	m_pWndNode = nullptr;
	m_pTangramTabCtrl = nullptr;
}

CTangramListView::~CTangramListView()
{
	if (m_pWndNode)
		delete m_pWndNode;
}

BEGIN_MESSAGE_MAP(CTangramListView, CListView)
	ON_WM_MOUSEACTIVATE()
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CTangramListView::OnLvnItemchanged)
	ON_MESSAGE(WM_TANGRAMACTIVEPAGE, OnActiveTangramPage)
END_MESSAGE_MAP()


// CTangramListView diagnostics

#ifdef _DEBUG
void CTangramListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CTangramListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG

void CTangramListView::FillListViewBySolution()
{
	if (g_pTangram->m_nAppID != 9)
	{
		return;
	}
	m_bFilling = true;
	if (m_pTangramTabCtrl)
	{
		m_pTangramTabCtrl->m_pTangramListView = this;
		m_pTangramTabCtrl->m_ListCtrl.DeleteAllItems();
		m_pTangramTabCtrl->DeleteAllItems();
		m_pTangramTabCtrl->m_strFilter = _T("");
		m_pTangramTabCtrl->RePosition();
	}
#ifndef _WIN64
	m_nActiveIndex = -1;
	VisualStudioPlus::CVSAddin* pVSAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;
	int nSize = pVSAddin->m_mapTangramProjectInfo.size();
	if (nSize)
	{
		for (auto it : pVSAddin->m_mapTangramProjectInfo)
		{
			delete it.second;
		}
		pVSAddin->m_mapTangramProjectInfo.erase(pVSAddin->m_mapTangramProjectInfo.begin(), pVSAddin->m_mapTangramProjectInfo.end());
	}
	//nSize = pVSAddin->m_PrjImageList.GetImageCount();
	//while (nSize)
	//{
	//	pVSAddin->m_PrjImageList.Remove(0);
	//	nSize = pVSAddin->m_PrjImageList.GetImageCount();
	//}

	//GetListCtrl().DeleteAllItems();

	//int nIndex = 0;
	//LVITEM item;
	//item.mask = LVFI_PARAM | LVIF_IMAGE | LVIF_TEXT;
	//for (auto it : pVSAddin->m_mapPrj)
	//{
	//	CString strFullName = it.first;
	//	SHFILEINFO sfi;
	//	SHGetFileInfo(it.first,	0,&sfi,	sizeof(SHFILEINFO),	SHGFI_ICON|SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
	//	item.iImage = GetListCtrl().GetImageList(LVSIL_NORMAL)->Add(sfi.hIcon);
	//	CComQIPtr<VxDTE::Project> pPrj(it.second);
	//	TangramProjectInfo* pTangramProjectInfo = new TangramProjectInfo;
	//	pTangramProjectInfo->m_nIndex = nIndex;
	//	pTangramProjectInfo->m_nImageIndex = item.iImage;
	//	pTangramProjectInfo->m_strFilter = _T("*.xml");
	//	pTangramProjectInfo->m_pPrjDisp = it.second;
	//	if (pPrj)
	//	{
	//		BSTR bstr = ::SysAllocString(L"");
	//		pPrj->get_FullName(&bstr);
	//		pTangramProjectInfo->m_strPrjFullPath = OLE2T(bstr);
	//		::SysFreeString(bstr);
	//	}
	//	pVSAddin->m_mapTangramProjectInfo[nIndex] = pTangramProjectInfo;
	//	BSTR bstrName = ::SysAllocString(L"");
	//	pPrj->get_Name(&bstrName);
	//	item.pszText = (LPTSTR)LPCTSTR(OLE2T(bstrName));
	//	::SysFreeString(bstrName);
	//	item.iItem = nIndex;
	//	item.iSubItem = 0;
	//	item.lParam = (LPARAM)pTangramProjectInfo;
	//	int nItem = GetListCtrl().InsertItem(&item);
	//	DestroyIcon(sfi.hIcon);
	//	nIndex++;
	//}
	//POSITION pos = GetListCtrl().GetFirstSelectedItemPosition();
	//nIndex = GetListCtrl().GetNextSelectedItem(pos);
	//m_bFilling = false;
	//InitTabCtrl(m_pTangramTabCtrl);
#endif
}

// CTangramListView message handlers

void CTangramListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
}

void CTangramListView::InitTabCtrl(CTangramTabCtrl* pTabCtrl)
{
	m_pTangramTabCtrl = pTabCtrl;
	CComBSTR bstrStyle(L"");
	m_pWndNode->get_Attribute(CComBSTR(L"style"), &bstrStyle);
	m_nStyle = _wtoi(OLE2T(bstrStyle));
	CImageList* pImageList = GetListCtrl().GetImageList(LVSIL_NORMAL);
	if (pImageList)
	{
	}
	else
	{
		LVITEM item;
		item.mask = LVFI_PARAM | LVIF_IMAGE | LVIF_TEXT;
		switch (m_nStyle)
		{
		case 0:
		{
			map<CString, TangramDocTemplateInfo*>*	m_pMapTangramFormsTemplateInfo = &g_pTangram->m_mapTangramFormsTemplateInfo;
			map<int, TangramDocTemplateInfo*>*		m_pMapTangramFormsTemplateInfo2 = &g_pTangram->m_mapTangramFormsTemplateInfo2;
			CTangramWinFormWnd* pWnd = nullptr;
			CString strFormsInfoPath = g_pTangram->m_strAppFormsInfoPath;
			if (m_pTangramTabCtrl)
			{
				HWND hWnd = m_pTangramTabCtrl->m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->m_pCompositorManager->m_hWnd;
				if (hWnd)
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
			if (g_pTangram->m_mapTangramDocTemplateInfo.size() == 0)
				g_pTangram->InitTangramDocManager();

			GetListCtrl().SetImageList(&g_pTangram->m_DocImageList, LVSIL_NORMAL);
			int nCount = g_pTangram->m_mapTangramDocTemplateInfo.size();
			for (auto it = g_pTangram->m_mapTangramDocTemplateInfo.begin(); it != g_pTangram->m_mapTangramDocTemplateInfo.end(); it++)
			{
				item.iImage = it->second->m_nImageIndex;
				item.iItem = it->second->m_nImageIndex;
				item.iSubItem = 0;
				CString s = it->second->m_strDocTemplateKey;
				if (g_pTangram->m_bUsingDefaultAppDocTemplate&&it->second->m_strTemplatePath.Find(g_pTangram->m_strAppCommonDocPath + _T("CommonMFCAppTemplate")) == 0)
				{
					s = _T("Common DocTemplate");
				}
				s.Replace(_T("."), _T(" "));
				item.pszText = (LPTSTR)LPCTSTR(s);
				int nItem = GetListCtrl().InsertItem(&item);
			}
			_wfinddata64_t fd;
			intptr_t fp = _wfindfirst64(strFormsInfoPath + L"*.ico", &fd);
			if (g_pTangram->m_bCLRObjTemplateInit == false||pWnd!=nullptr)
			{
				while (fp != -1)
				{
					if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0)
					{
						HICON hIcon = (HICON)::LoadImage(NULL, strFormsInfoPath + fd.name, IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_DEFAULTCOLOR);
						item.iImage = g_pTangram->m_DocImageList.Add(hIcon);;
						g_pTangram->m_DocTemplateImageList.Add(hIcon);
						item.iItem = item.iImage;
						CString s = fd.name;
						int nPos = s.Replace(_T(".ico"), _T(""));
						CString strType = s;
						nPos = s.Find(_T(","));
						CString strText = s.Left(nPos);
						s = s.Mid(nPos + 1);
						nPos = s.Find(_T(","));
						strText += s.Left(nPos);
						item.pszText = (LPTSTR)LPCTSTR(strText);
						TangramDocTemplateInfo* pInfo = nullptr;
						auto it = m_pMapTangramFormsTemplateInfo->find(strType);
						if (it == m_pMapTangramFormsTemplateInfo->end())
						{
							pInfo = new TangramDocTemplateInfo();
							pInfo->m_nImageIndex = item.iImage;// item.iItem;
							pInfo->m_strExt = _T(".formxml");
							pInfo->m_strFilter = _T("*.formxml");
							pInfo->m_strProxyID = strType;
							(*m_pMapTangramFormsTemplateInfo)[strType] = pInfo;
						}
						(*m_pMapTangramFormsTemplateInfo2)[GetListCtrl().InsertItem(&item)] = pInfo;
					}
					if (_wfindnext64(fp, &fd) == -1)
					{
						break;
					}
				}
				if(pWnd==nullptr)
					g_pTangram->m_bCLRObjTemplateInit = true;
			}
			else
			{
				while (fp != -1)
				{
					if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0)
					{
						CString s = fd.name;
						int nPos = s.Replace(_T(".ico"), _T(""));
						CString strType = s;
						nPos = s.Find(_T(","));
						CString strText = s.Left(nPos);
						s = s.Mid(nPos + 1);
						nPos = s.Find(_T(","));
						strText += s.Left(nPos);
						item.pszText = (LPTSTR)LPCTSTR(strText);
						auto it = m_pMapTangramFormsTemplateInfo->find(strType);
						if (it != m_pMapTangramFormsTemplateInfo->end())
						{
							item.iItem = item.iImage = it->second->m_nImageIndex;
							GetListCtrl().InsertItem(&item);
						}
						else
						{
							HICON hIcon = (HICON)::LoadImage(NULL, strFormsInfoPath + fd.name, IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_DEFAULTCOLOR);
							item.iImage = g_pTangram->m_DocImageList.Add(hIcon);;
							g_pTangram->m_DocTemplateImageList.Add(hIcon);
							TangramDocTemplateInfo* pInfo = nullptr;
							pInfo = new TangramDocTemplateInfo();
							pInfo->m_nImageIndex = item.iImage;// item.iItem;
							pInfo->m_strExt = _T(".formxml");
							pInfo->m_strFilter = _T("*.formxml");
							pInfo->m_strProxyID = strType;
							(*m_pMapTangramFormsTemplateInfo)[strType] = pInfo;
							(*m_pMapTangramFormsTemplateInfo2)[GetListCtrl().InsertItem(&item)] = pInfo;
						}
					}
					if (_wfindnext64(fp, &fd) == -1)
					{
						break;
					}
				}
			}
		}
		break;
		case 1:
		{
			if (g_pTangram->m_nAppID != 9)
			{
				break;
			}
#ifndef _WIN64
			VisualStudioPlus::CVSAddin* pVSAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;
			pVSAddin->m_pTangramListView = this;
			GetListCtrl().SetImageList(&pVSAddin->m_PrjImageList, LVSIL_NORMAL);
#endif
			//FillListViewBySolution();
		}
		break;
		default:
			break;
		}
		m_bCreated = TRUE;
	}
	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	int nIndex = 0;
	switch (m_nStyle)
	{
	case 0:
		{
			GetListCtrl().SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
			TCHAR	szBuffer[MAX_PATH];
			::GetModuleFileName(nullptr, szBuffer, MAX_PATH);
			CString strPath = CString(szBuffer);

			auto it = g_pTangram->m_mapTangramDocTemplateInfo.find(0);
			if (it != g_pTangram->m_mapTangramDocTemplateInfo.end())
			{
				m_pTangramTabCtrl->m_nImageIndex = it->second->m_nImageIndex;
				m_pTangramTabCtrl->m_ListCtrl.m_strDir = it->second->m_strTemplatePath;
				CString m_strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir;
				CString strKey = it->second->m_strDocTemplateKey;
				if (::PathIsDirectory(m_strDocTemplatePath) == false)
				{
					if (::SHCreateDirectoryEx(NULL, m_strDocTemplatePath, NULL))
					{
						ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
						break;
					}
					int nPos = strKey.ReverseFind('.');
					CString strTitle = strKey.Left(nPos);
					CString strPath = m_strDocTemplatePath + strTitle;
					if (::SHCreateDirectoryEx(NULL, strPath, NULL))
					{
						ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
						break;
					}
					else
					{
						CString strXml = _T("");
						strXml.Format(_T("<%s mainframeid='defaultmainframe' apptitle='%s' />"), strKey, strTitle);
						CTangramXmlParse m_Parse;
						m_Parse.LoadXml(strXml);
						m_Parse.SaveFile(strPath + _T("\\default.xml"));
					}
				}
				m_strDocTemplatePath += _T("*.*");

				CString strCaption = _T("");
				CWndNode* pNode = m_pTangramTabCtrl->m_pWndNode;
				if (pNode)
				{
					strCaption = _T("Current Selected Document Template: ");
					strCaption += it->second->m_strDocTemplateKey;
					pNode->put_Caption(strCaption.AllocSysString());
				}
				strCaption = _T("Create New Tangram Document");
				m_pWndNode->put_Caption(strCaption.AllocSysString());
				_wfinddata_t fd;
				fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
				intptr_t pf = _wfindfirst(m_strDocTemplatePath, &fd);
				while (!_wfindnext(pf, &fd))
				{
					if (fd.attrib&FILE_ATTRIBUTE_DIRECTORY)
					{
						CString str = fd.name;
						if (str != _T(".."))
						{
							tcItem.pszText = LPWSTR(LPCWSTR(str));
							CString strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir + str + _T("\\") + it->second->m_strFilter;

							_wfinddata_t fd;
							fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
							int nItem = 0;
							intptr_t pf = _wfindfirst(strDocTemplatePath, &fd);
							while (pf != -1)
							{
								if ((fd.attrib&FILE_ATTRIBUTE_DIRECTORY) == 0)
								{
									CString str = fd.name;
									if (str != _T(".."))
									{
										nItem++;
										break;
									}
								}
								int nVal = _wfindnext(pf, &fd);
								ATLTRACE(_T("_wfindnext:%d\n"), nVal);
								if (nVal == -1)
									break;
							}

							if (nItem)
								m_pTangramTabCtrl->InsertItem(nIndex, &tcItem);

							nIndex++;
						}
					}
				}
				_findclose(pf);
				m_pTangramTabCtrl->m_strFilter = it->second->m_strFilter;
				m_pTangramTabCtrl->FillListCtrl();
			}
		}
		break;
	case 1:
		{
			if (g_pTangram->m_nAppID != 9)
			{
				break;
			}
#ifndef _WIN64
			if (m_pTangramTabCtrl == nullptr)
				break;
			m_pTangramTabCtrl->m_pTangramListView = this;
			//GetListCtrl().SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
			VisualStudioPlus::CVSAddin* pVSAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;

			auto it = pVSAddin->m_mapTangramProjectInfo.find(0);
			if (it != pVSAddin->m_mapTangramProjectInfo.end())
			{
				CString strPath = it->second->m_strPrjFullPath;
				int nPos = strPath.ReverseFind('\\');
				strPath = strPath.Left(nPos + 1) + _T("tangramtool\\");
				m_pTangramTabCtrl->m_nImageIndex = it->second->m_nImageIndex;
				m_pTangramTabCtrl->m_ListCtrl.m_strDir = strPath;

				CString m_strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir;
				if (::SHCreateDirectoryEx(NULL, m_strDocTemplatePath, NULL))
				{
					ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
					break;
				}
				//CString strKey = it->second->m_strDocTemplateKey;
				//if (::PathIsDirectory(m_strDocTemplatePath) == false)
				//{
				//	int nPos = strKey.ReverseFind('.');
				//	CString strTitle = strKey.Left(nPos);
				//	CString strPath = m_strDocTemplatePath + strTitle;
				//	if (::SHCreateDirectoryEx(NULL, strPath, NULL))
				//	{
				//		ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
				//		break;
				//	}
				//}
				m_strDocTemplatePath += _T("*.*");

				CString strCaption = _T("");
				CWndNode* pNode = m_pTangramTabCtrl->m_pWndNode;
				if (pNode)
				{
					strCaption = _T("Current Selected Document Template: ");
					//strCaption += it->second->m_strDocTemplateKey;
					pNode->put_Caption(strCaption.AllocSysString());
				}
				strCaption = _T("Create New Tangram Document");
				m_pWndNode->put_Caption(strCaption.AllocSysString());
				_wfinddata_t fd;
				fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
				intptr_t pf = _wfindfirst(m_strDocTemplatePath, &fd);
				while (!_wfindnext(pf, &fd))
				{
					if (fd.attrib&FILE_ATTRIBUTE_DIRECTORY)
					{
						CString str = fd.name;
						if (str != _T(".."))
						{
							tcItem.pszText = LPWSTR(LPCWSTR(str));
							CString strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir + str + _T("\\") + it->second->m_strFilter;

							_wfinddata_t fd;
							fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
							int nItem = 0;
							intptr_t pf = _wfindfirst(strDocTemplatePath, &fd);
							while (pf != -1)
							{
								if ((fd.attrib&FILE_ATTRIBUTE_DIRECTORY) == 0)
								{
									CString str = fd.name;
									if (str != _T(".."))
									{
										nItem++;
										break;
									}
								}
								int nVal = _wfindnext(pf, &fd);
								ATLTRACE(_T("_wfindnext:%d\n"), nVal);
								if (nVal == -1)
									break;
							}

							if (nItem)
								m_pTangramTabCtrl->InsertItem(nIndex, &tcItem);

							nIndex++;
						}
					}
				}
				_findclose(pf);
				m_pTangramTabCtrl->m_strFilter = it->second->m_strFilter;
				m_pTangramTabCtrl->FillListCtrl();
			}
#endif
		}
		break;
	}
}

void CTangramListView::ChangeTemplate(int nItem)
{
	if (m_bCreated == FALSE)
		return;
	if (m_pTangramTabCtrl == nullptr)
		return;
	if (m_pTangramTabCtrl->m_ListCtrl.m_strDir == _T(""))
		return;
	switch (m_nStyle)
	{
	case 0:
		{
			auto it = g_pTangram->m_mapTangramDocTemplateInfo.find(nItem);
			if (it != g_pTangram->m_mapTangramDocTemplateInfo.end())
			{
				CString strDir = g_pTangram->m_strAppCommonDocPath + it->second->m_strProxyID + _T("\\");
				if (m_nActiveIndex != nItem|| m_pTangramTabCtrl->m_ListCtrl.m_strDir != strDir)
				{
					m_pTangramTabCtrl->m_ListCtrl.m_nListViewSelectedIndex = nItem;
					m_pTangramTabCtrl->DeleteAllItems();
					m_pTangramTabCtrl->m_strFilter = it->second->m_strFilter;
					m_pTangramTabCtrl->m_nImageIndex = it->second->m_nImageIndex;
					CString strKey = it->second->m_strDocTemplateKey;
					CString strCaption = _T("");
					CWndNode* pNode = m_pTangramTabCtrl->m_pWndNode;
					if (pNode)
					{
						strCaption = _T("Current Selected Document Template: ");
						strCaption += it->second->m_strDocTemplateKey;
						pNode->put_Caption(strCaption.AllocSysString());
					}
					strCaption = _T("Create New Tangram Document");
					TCITEM tcItem;
					tcItem.mask = TCIF_TEXT;
					int nIndex = 0;
					m_pTangramTabCtrl->m_ListCtrl.m_strDir = it->second->m_strTemplatePath;
					CString m_strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir;
					if (::PathIsDirectory(m_strDocTemplatePath) == false)
					{
						if (::SHCreateDirectoryEx(NULL, m_strDocTemplatePath, NULL))
						{
							ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
							break;
						}
						int nPos = strKey.ReverseFind('.');
						CString strTitle = strKey.Left(nPos);
						CString strPath = m_strDocTemplatePath + strTitle;
						if (::SHCreateDirectoryEx(NULL, strPath, NULL))
						{
							ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
							break;
						}
						else
						{
							CString strXml = _T("");
							strXml.Format(_T("<%s mainframeid='defaultmainframe' apptitle='%s' />"), strKey, strTitle);
							CTangramXmlParse m_Parse;
							m_Parse.LoadXml(strXml);
							m_Parse.SaveFile(strPath+_T("\\default.xml"));
						}
					}
					m_strDocTemplatePath += _T("*.*");
					_wfinddata_t fd;
					fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
					intptr_t pf = _wfindfirst(m_strDocTemplatePath, &fd);
					if (pf != -1)
					{
						while (!_wfindnext(pf, &fd))
						{
							if (fd.attrib&FILE_ATTRIBUTE_DIRECTORY)
							{
								CString str = fd.name;
								if (str != _T(".."))
								{
									tcItem.pszText = LPWSTR(LPCWSTR(str));
									CString strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir + str + _T("\\") + it->second->m_strFilter;

									_wfinddata_t fd;
									fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
									int nItem = 0;
									intptr_t pf = _wfindfirst(strDocTemplatePath, &fd);
									while (pf != -1)
									{
										if ((fd.attrib&FILE_ATTRIBUTE_DIRECTORY) == 0)
										{
											CString str = fd.name;
											if (str != _T(".."))
											{
												nItem++;
												break;
											}
										}
										int nVal = _wfindnext(pf, &fd);
										ATLTRACE(_T("_wfindnext:%d\n"), nVal);
										if (nVal == -1)
											break;
									}

									if(nItem)
										m_pTangramTabCtrl->InsertItem(nIndex, &tcItem);
									nIndex++;
								}
							}
						}
						_findclose(pf);
						m_nActiveIndex = nItem;
						m_pTangramTabCtrl->FillListCtrl();
					}
				}
			}
			else
			{
				map<CString, TangramDocTemplateInfo*>*	m_pMapTangramFormsTemplateInfo = &g_pTangram->m_mapTangramFormsTemplateInfo;
				map<int, TangramDocTemplateInfo*>*		m_pMapTangramFormsTemplateInfo2 = &g_pTangram->m_mapTangramFormsTemplateInfo2;
				CTangramWinFormWnd* pWnd = nullptr;
				if (m_pTangramTabCtrl)
				{
					HWND hWnd = m_pTangramTabCtrl->m_pWndNode->m_pTangramNodeCommonData->m_pCompositor->m_pCompositorManager->m_hWnd;
					if (hWnd)
					{
						pWnd = (CTangramWinFormWnd*)::SendMessage(hWnd, WM_TANGRAMDATA, 0, 20190214);
						if (pWnd)
						{
							m_pMapTangramFormsTemplateInfo = &pWnd->m_mapTangramFormsTemplateInfo;
							m_pMapTangramFormsTemplateInfo2 = &pWnd->m_mapTangramFormsTemplateInfo2;
						}
					}
				}
				CString strText = GetListCtrl().GetItemText(nItem, 0);
				auto it2 = m_pMapTangramFormsTemplateInfo2->find(nItem);
				if (it2 != m_pMapTangramFormsTemplateInfo2->end())
				{
					CString strDir = g_pTangram->m_strAppFormsTemplatePath;
					if (pWnd)
					{
						strDir = pWnd->m_strChildFormPath;
					}

					if (m_nActiveIndex != nItem || m_pTangramTabCtrl->m_ListCtrl.m_strDir != strDir)
					{
						m_pTangramTabCtrl->m_ListCtrl.m_nListViewSelectedIndex = nItem;
						m_pTangramTabCtrl->DeleteAllItems();
						m_pTangramTabCtrl->m_strFilter = it2->second->m_strFilter;
						m_pTangramTabCtrl->m_nImageIndex = it2->second->m_nImageIndex;
						TCITEM tcItem;
						tcItem.mask = TCIF_TEXT;
						int nIndex = 0;
						m_pTangramTabCtrl->m_ListCtrl.m_strDir = strDir + strText + _T("\\");
						CString m_strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir;
						CString strKey = it2->second->m_strDocTemplateKey;
						CString strCaption = _T("");
						CWndNode* pNode = m_pTangramTabCtrl->m_pWndNode;
						if (pNode)
						{
							strCaption = _T("Current Selected Document Template: ");
							strCaption += it2->second->m_strDocTemplateKey;
							pNode->put_Caption(strCaption.AllocSysString());
						}
						strCaption = _T("Create New Tangram Document");
						tcItem.mask = TCIF_TEXT;
						//m_pTangramTabCtrl->m_ListCtrl.m_strDir = it2->second->m_strTemplatePath;
						if (::PathIsDirectory(m_strDocTemplatePath) == false)
						{
							if (::SHCreateDirectoryEx(NULL, m_strDocTemplatePath, NULL))
							{
								ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
								break;
							}
							int nPos = strKey.ReverseFind('.');
							CString strTitle = strKey.Left(nPos);
							CString strPath = m_strDocTemplatePath + strTitle;
							if (::SHCreateDirectoryEx(NULL, strPath, NULL))
							{
								ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
								break;
							}
							else
							{
								CString strXml = _T("");
								strXml.Format(_T("<%s mainframeid='defaultmainframe' apptitle='%s' />"), strKey, strTitle);
								CTangramXmlParse m_Parse;
								m_Parse.LoadXml(strXml);
								m_Parse.SaveFile(strPath + _T("\\default.xml"));
							}
						}
						m_strDocTemplatePath += _T("*.*");
						_wfinddata_t fd;
						fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
						intptr_t pf = _wfindfirst(m_strDocTemplatePath, &fd);
						if (pf != -1)
						{
							while (!_wfindnext(pf, &fd))
							{
								if (fd.attrib&FILE_ATTRIBUTE_DIRECTORY)
								{
									CString str = fd.name;
									if (str != _T(".."))
									{
										tcItem.pszText = LPWSTR(LPCWSTR(str));
										CString strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir + str + _T("\\") + it2->second->m_strFilter;

										_wfinddata_t fd;
										fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
										int nItem = 0;
										intptr_t pf = _wfindfirst(strDocTemplatePath, &fd);
										while (pf != -1)
										{
											if ((fd.attrib&FILE_ATTRIBUTE_DIRECTORY) == 0)
											{
												CString str = fd.name;
												if (str != _T(".."))
												{
													nItem++;
													break;
												}
											}
											int nVal = _wfindnext(pf, &fd);
											ATLTRACE(_T("_wfindnext:%d\n"), nVal);
											if (nVal == -1)
												break;
										}

										if (nItem)
											m_pTangramTabCtrl->InsertItem(nIndex, &tcItem);
										nIndex++;
									}
								}
							}
							_findclose(pf);
							m_nActiveIndex = nItem;
							m_pTangramTabCtrl->m_pTangramListView = this;
							m_pTangramTabCtrl->FillListCtrl();
						}
					}
				}
			}
			m_pTangramTabCtrl->RePosition();
		}
		break;
	case 1:
		{
			if (g_pTangram->m_nAppID != 9)
			{
				break;
			}
#ifndef _WIN64
			VisualStudioPlus::CVSAddin* pVSAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;
			auto it = pVSAddin->m_mapTangramProjectInfo.find(nItem);
			if (it != pVSAddin->m_mapTangramProjectInfo.end())
			{
				TangramProjectInfo* pTangramProjectInfo = (TangramProjectInfo*)it->second;
				CString strPath = it->second->m_strPrjFullPath;
				int nPos = strPath.ReverseFind('\\');
				strPath = strPath.Left(nPos + 1) + _T("tangramtool\\");
				CString strFilter = it->second->m_strFilter;
				if (m_nActiveIndex != nItem || m_pTangramTabCtrl->m_ListCtrl.m_strDir != strPath)
				{
					m_nActiveIndex = nItem;
					m_pTangramTabCtrl->m_ListCtrl.m_nListViewSelectedIndex = nItem;
					m_pTangramTabCtrl->DeleteAllItems();
					m_pTangramTabCtrl->m_strFilter = it->second->m_strFilter;
					m_pTangramTabCtrl->m_nImageIndex = it->second->m_nImageIndex;
					TCITEM tcItem;
					tcItem.mask = TCIF_TEXT;
					int nIndex = 0;
					m_pTangramTabCtrl->m_ListCtrl.m_strDir = strPath;
					CString m_strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir;
					if (::PathIsDirectory(m_strDocTemplatePath) == false)
					{
						if (::SHCreateDirectoryEx(NULL, m_strDocTemplatePath, NULL))
						{
							ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
							break;
						}
					}
					m_strDocTemplatePath += _T("*.*");
					_wfinddata_t fd;
					fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
					intptr_t pf = _wfindfirst(m_strDocTemplatePath, &fd);
					if (pf != -1)
					{
						while (!_wfindnext(pf, &fd))
						{
							if (fd.attrib&FILE_ATTRIBUTE_DIRECTORY)
							{
								CString str = fd.name;
								if (str != _T(".."))
								{
									tcItem.pszText = LPWSTR(LPCWSTR(str));
									CString strDocTemplatePath = m_pTangramTabCtrl->m_ListCtrl.m_strDir + str + _T("\\") + it->second->m_strFilter;

									_wfinddata_t fd;
									fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
									int nItem = 0;
									intptr_t pf = _wfindfirst(strDocTemplatePath, &fd);
									while (pf != -1)
									{
										if ((fd.attrib&FILE_ATTRIBUTE_DIRECTORY) == 0)
										{
											CString str = fd.name;
											if (str != _T(".."))
											{
												nItem++;
												break;
											}
										}
										int nVal = _wfindnext(pf, &fd);
										ATLTRACE(_T("_wfindnext:%d\n"), nVal);
										if (nVal == -1)
											break;
									}

									if (nItem)
										m_pTangramTabCtrl->InsertItem(nIndex, &tcItem);
									nIndex++;
								}
							}
						}
						_findclose(pf);
						m_pTangramTabCtrl->FillListCtrl();
					}
					if (nIndex == 0)
					{
						pVSAddin->m_pTangramPackageProxy->ShowTangramToolWnd(FALSE, 0);
					}
				}
			}
			m_pTangramTabCtrl->RePosition();
#endif
		}
		break;
	}
}

BOOL CTangramListView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_pWndNode = g_pTangram->m_pActiveNode;
	m_pWndNode->m_pHostWnd = this;
	m_pWndNode->m_nViewType = TangramListView;
	m_pWndNode->m_nID = nID;
	CString strURL = _T("");
	BOOL bRet = CListView::Create(lpszClassName, lpszWindowName, dwStyle| LVS_ICON| LVS_AUTOARRANGE| LVS_SINGLESEL| LVS_SHAREIMAGELISTS| LVS_SHOWSELALWAYS, rect, pParentWnd, nID, pContext);
	if (::FindResource(NULL, _T("TANGRAMBK.PNG"), _T("IMAGES")) == nullptr)
	{
		::GetModuleFileName(theApp.m_hInstance, g_pTangram->m_szBuffer, MAX_PATH);
		CString strPath = g_pTangram->m_szBuffer;
		int nPos = strPath.ReverseFind('\\');
		strPath = strPath.Left(nPos + 1) + _T("TangramInit.dll");
		//CString strPath = g_pTangram->m_strProgramFilePath;
		//strPath += _T("\\tangram\\TangramInit.dll");
		if (::PathFileExists(strPath))
		{
			strURL = _T("res://");
			strURL += strPath;
			strURL += _T("/images/tangrambk.png");
		}
	}
	else
	{
		::GetModuleFileName(NULL, g_pTangram->m_szBuffer, MAX_PATH);
		strURL = _T("res://") + CString(g_pTangram->m_szBuffer) + _T("/images/tangrambk.png");
	}
	SendMessage(WM_INITIALUPDATE);
	if(strURL!=_T(""))
		GetListCtrl().SetBkImage(LPTSTR(LPCTSTR(strURL)), TRUE);

	int width = 320, heigh = 90, clines = 3;
	CComBSTR bstrVal("");
	m_pWndNode->get_Attribute(CComBSTR("sizeandclines"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("SizeandcLines(%d,%d,%d)"), &width, &heigh, &clines);
	}
	SIZE size = { width, heigh };
	LVTILEVIEWINFO tileViewInfo = { 0 };

	tileViewInfo.cbSize = sizeof(tileViewInfo);
	tileViewInfo.dwFlags = LVTVIF_FIXEDSIZE;
	tileViewInfo.dwMask = LVTVIM_COLUMNS | LVTVIM_TILESIZE;
	tileViewInfo.cLines = clines;
	tileViewInfo.sizeTile = size;

	ListView_SetTileViewInfo(GetListCtrl().m_hWnd, &tileViewInfo);
	ListView_SetView(GetListCtrl().m_hWnd, LV_VIEW_TILE);
	return bRet;
}

int CTangramListView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
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

void CTangramListView::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (m_bCreated == FALSE)
		return;
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	int nItem = pNMLV->iItem;
	//pNMLV->
	if (m_bFilling == false)
	{
		if (m_nStyle == 1&& pNMLV->uNewState)
		{
#ifndef _WIN64
			if (g_pTangram->m_nAppID != 9)
			{
				return;
			}
			VisualStudioPlus::CVSAddin* pVSAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;
			auto it = pVSAddin->m_mapTangramProjectInfo.find(nItem);
			if (it != pVSAddin->m_mapTangramProjectInfo.end())
			{
				TangramProjectInfo* pTangramProjectInfo = (TangramProjectInfo*)it->second;
				CString strPath = it->second->m_strPrjFullPath;
				int nPos = strPath.ReverseFind('\\');
				strPath = strPath.Left(nPos + 1) + _T("tangramtool\\");
				m_pTangramTabCtrl->m_ListCtrl.m_strDir = strPath;
				IWndNode* pNode = nullptr;
				CCompositorManager* pCompositorManager = nullptr;
				if (m_pCompositor == nullptr)
				{
					HWND hWnd = ::GetParent(m_pTangramTabCtrl->m_hWnd);
					pCompositorManager = m_pWndNode->m_pTangramNodeCommonData->m_pCompositorManager;
					pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((__int64)hWnd), CComBSTR(L"CLRFrame"), &m_pCompositor);
					CString strXml = _T("<Tangram><window><node name='node' id='hostview'/></window></Tangram>");
					m_pCompositor->Open(CComBSTR("default"), CComBSTR(strXml), &pNode);
				}
				//if (m_pCompositor)
				//{
				//	pCompositorManager = ((CCompositor*)m_pCompositor)->m_pCompositorManager;
				//	int nPrjType = pVSAddin->IsTangramProject(it->second->m_strPrjFullPath);
				//	if (nPrjType == 1)
				//	{
				//		pVSAddin->m_strSelectedPrj = it->second->m_strPrjFullPath;
				//		CString strURL = _T("res://") + g_pTangram->m_strProgramFilePath + _T("\\Tangram\\TangramInit.dll/UPDATEPRJ.htm");
				//		CString strXml = _T("<Tangram><window><node id='splitter' name='node' rows='2' cols='1' width='30,' height='168,157,'><node id='tangramtabctrl' name='tabctrl' cnnid='tangramtabbedwnd.tabbedcomponent.1' tabstyle='18' activepage='0'><node name='Page0' id='activex' caption='Update Current Project for Tangram Support'/></node><node name='Splitter01' id='hostview'/></node></window></Tangram>");
				//		CTangramXmlParse m_Parse;
				//		if (m_Parse.LoadXml(strXml))
				//		{
				//			CTangramXmlParse* pParse = m_Parse.FindItemByName(_T("Page0"));
				//			if (pParse)
				//			{
				//				pParse->put_attr(_T("cnnid"), strURL);
				//				strXml = m_Parse.xml();
				//			}
				//		}
				//		m_pCompositor->Open(CComBSTR("updatefortangram"), CComBSTR(strXml), &pNode);
				//		CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
				//		pObj->Init(_T("TangramListView::OnLvnItemchanged"), 12, m_pCompositor);
				//		pObj->m_mapDisp[0] = m_pCompositor;
				//		pObj->m_mapDisp[0]->AddRef();
				//		pObj->m_mapDisp[1] = it->second->m_pPrjDisp;
				//		pObj->m_mapDisp[1]->AddRef();
				//		pCompositorManager->Fire_TangramEvent(pObj);
				//		((CCompositor*)m_pCompositor)->m_pInitEventObj = pObj;
				//		//delete pObj;
				//	}
				//	else
				//	{
				//		pVSAddin->m_strSelectedPrj = _T("");
				//		//CString strXml = _T("<Tangram><window><node name='node' id='hostview'/></window></Tangram>");
				//		m_pCompositor->Open(CComBSTR("default"), CComBSTR(""), &pNode);
				//	}
				//}
			}
			ChangeTemplate(nItem);
			*pResult = 0;
			return;
#endif
		}
	}
	ChangeTemplate(nItem);
	*pResult = 0;
}

LRESULT CTangramListView::OnActiveTangramPage(WPARAM wParam, LPARAM lParam)
{
	if (m_pTangramTabCtrl)
	{
		int nCount = GetListCtrl().GetSelectedCount();
		POSITION nPos = GetListCtrl().GetFirstSelectedItemPosition();
		int nIndex = GetListCtrl().GetNextSelectedItem(nPos);
		GetListCtrl().SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
		m_pTangramTabCtrl->m_ListCtrl.m_nListViewIndex = wParam;
		switch (wParam)
		{
		case 0:
			{
				int width = 320, heigh = 90, clines = 3;
				CComBSTR bstrVal("");
				m_pTangramTabCtrl->m_pWndNode->get_Attribute(CComBSTR("sizeandclines"), &bstrVal);
				if (!CString(bstrVal).IsEmpty())
				{
					_stscanf_s(CString(bstrVal), _T("SizeandcLines(%d,%d,%d)"), &width, &heigh, &clines);
				}
				m_pTangramTabCtrl->m_ListCtrl.SetImageList(&g_pTangram->m_DocTemplateImageList, LVSIL_NORMAL);
				SIZE size = { width, heigh };
				LVTILEVIEWINFO tileViewInfo = { 0 };

				tileViewInfo.cbSize = sizeof(tileViewInfo);
				tileViewInfo.dwFlags = LVTVIF_FIXEDSIZE;
				tileViewInfo.dwMask = LVTVIM_COLUMNS | LVTVIM_TILESIZE;
				tileViewInfo.cLines = clines;
				tileViewInfo.sizeTile = size;

				ListView_SetTileViewInfo(m_pTangramTabCtrl->m_ListCtrl.m_hWnd, &tileViewInfo);
				ListView_SetView(m_pTangramTabCtrl->m_ListCtrl.m_hWnd, LV_VIEW_TILE);
				auto it = g_pTangram->m_mapTangramDocTemplateInfo.find(nIndex);
				if (it != g_pTangram->m_mapTangramDocTemplateInfo.end())
				{
					ChangeTemplate(nIndex);
				}
			}
			break;
		case 1:
			{
				if (g_pTangram->m_nAppID != 9)
				{
					break;
				}
#ifndef _WIN64
				int width = 320, heigh = 90, clines = 3;
				CComBSTR bstrVal("");
				m_pTangramTabCtrl->m_pWndNode->get_Attribute(CComBSTR("sizeandclines"), &bstrVal);
				if (!CString(bstrVal).IsEmpty())
				{
					_stscanf_s(CString(bstrVal), _T("SizeandcLines(%d,%d,%d)"), &width, &heigh, &clines);
				}
				VisualStudioPlus::CVSAddin* pVSAddin = (VisualStudioPlus::CVSAddin*)g_pTangram;
				m_pTangramTabCtrl->m_ListCtrl.SetImageList(&pVSAddin->m_PrjImageList, LVSIL_NORMAL);
				SIZE size = { width, heigh };
				LVTILEVIEWINFO tileViewInfo = { 0 };

				tileViewInfo.cbSize = sizeof(tileViewInfo);
				tileViewInfo.dwFlags = LVTVIF_FIXEDSIZE;
				tileViewInfo.dwMask = LVTVIM_COLUMNS | LVTVIM_TILESIZE;
				tileViewInfo.cLines = clines;
				tileViewInfo.sizeTile = size;

				ListView_SetTileViewInfo(m_pTangramTabCtrl->m_ListCtrl.m_hWnd, &tileViewInfo);
				ListView_SetView(m_pTangramTabCtrl->m_ListCtrl.m_hWnd, LV_VIEW_TILE);
				auto it = g_pTangram->m_mapTangramDocTemplateInfo.find(nIndex);
				if (it != g_pTangram->m_mapTangramDocTemplateInfo.end())
				{
					ChangeTemplate(nIndex);
				}
#endif
			}
			break;
		default:
			break;
		}
	}

	return CWnd::DefWindowProc(WM_TABCHANGE, wParam, lParam);
}
