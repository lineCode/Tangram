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

// DocTemplateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TangramApp.h"
#include "TangramCore.h"
#include "DocTemplateDlg.h"


// CDocTemplateDlg dialog

IMPLEMENT_DYNAMIC(CDocTemplateDlg, CDialog)
CDocTemplateDlg::CDocTemplateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDocTemplateDlg::IDD, pParent)
{
	m_strFilter = _T(".xtml");
	m_strCaption = _T("");
	strCurTabText = _T("Normal");
	m_strTemplateDoc = _T("");
	m_strDir = _T("DocTemplate\\");
}

CDocTemplateDlg::~CDocTemplateDlg()
{
}

void CDocTemplateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TemplateTAB, m_tabCtrl);
	DDX_Control(pDX, IDC_TemplateLIST, m_TemplateList);
}


BEGIN_MESSAGE_MAP(CDocTemplateDlg, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_TemplateLIST, OnLvnItemchangedTemplatelist)
	ON_NOTIFY(NM_DBLCLK, IDC_TemplateLIST, OnNMDblclkTemplatelist)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TemplateTAB, OnTcnSelchangeTemplatetab)
END_MESSAGE_MAP()


// CDocTemplateDlg message handlers

BOOL CDocTemplateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	if (m_strCaption != _T(""))
		SetWindowText(m_strCaption);
	m_strFilter.MakeLower();
	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = _T("Normal");

	m_TemplateList.InsertColumn(0,_T("Template"),0,150);
	m_TemplateList.InsertColumn(1,_T("Template Script"),0,250);
	m_TemplateList.InsertColumn(2,_T("Create Date"),0,100);
	m_TemplateList.InsertColumn(3,_T("Author"),0,60);
	m_tabCtrl.InsertItem(0, &tcItem);
	
	CFileFind finder;
	CString strWildcard = _T("");
	if (::PathIsDirectory(m_strDir) == false)
	{
		m_strDocTemplatePath = g_pTangram->m_strAppPath + m_strDir;
		strWildcard = g_pTangram->m_strAppPath + m_strDir + _T("*.*");
	}
	else
	{
		m_strDocTemplatePath = m_strDir;
		strWildcard = m_strDir + _T("*.*");
	}

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);
	int nIndex = 0;
	int nIndex2 = 0;
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		CString strFileName = finder.GetFileName(); 
		CString strFileName2 = strFileName;
		strFileName2.MakeLower();
		int nPos = strFileName2.Find(m_strFilter);
		if(nPos!=-1)
		{
			strFileName=strFileName.Left(nPos);
			m_TemplateList.InsertItem(nIndex2,strFileName);
			CTime m_Time;
			finder.GetCreationTime(m_Time);
			CString s = m_Time.Format(_T("%B %d, %Y"));
			m_TemplateList.SetItemText(nIndex2, 2, s);
			nIndex2++;
		}

		if (finder.IsDots())
			continue;

		// if it's a directory, recursively search it

		if (finder.IsDirectory())
		{
			CString str = finder.GetFilePath();
			TCHAR t = '\\';
			nPos = str.ReverseFind(t);
			str = str.Mid(nPos+1);
			CString strWildcard = m_strDocTemplatePath;
			strWildcard += str;
			strWildcard += _T("\\*");
			strWildcard += m_strFilter;

			CFileFind finder2;
			// start working for files
			BOOL bWorking = finder2.FindFile(strWildcard);
			int nCount = 0;
			while (bWorking)
			{
				nCount++;
				break;
			}
			finder2.Close();
			if(nCount)
			{
#ifdef _UNICODE
				tcItem.pszText = LPWSTR(LPCWSTR(str));
#else
				tcItem.pszText = LPSTR(LPCTSTR(str));
#endif
				nIndex++;
				m_tabCtrl.InsertItem(nIndex, &tcItem);
			}
		}
	}

	finder.Close();
	RECT  rc;
	GetClientRect(&rc);
	if(::IsWindow(m_tabCtrl.m_hWnd)&&::IsWindow(m_TemplateList.m_hWnd))
	{
		m_tabCtrl.GetWindowRect(&rc);
		m_tabCtrl.AdjustRect(false,&rc);
		ScreenToClient(&rc);
		rc.top+=2;
		m_TemplateList.MoveWindow(&rc,true);
	}
	m_TemplateList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
		 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDocTemplateDlg::OnLvnItemchangedTemplatelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	POSITION pos = m_TemplateList.GetFirstSelectedItemPosition();
	if (pos == NULL)
		TRACE0("No items were selected!\n");
	else
	{
		while (pos)
		{
			int nItem = m_TemplateList.GetNextSelectedItem(pos);
			CString strItemText = m_TemplateList.GetItemText(nItem,0);
			m_strTemplateDoc = _T("");
			if(strCurTabText==_T("Normal"))
				m_strTemplateDoc = m_strDocTemplatePath + strItemText + m_strFilter;
			else
			{
				m_strTemplateDoc = m_strDocTemplatePath;
				m_strTemplateDoc += strCurTabText;
				m_strTemplateDoc += _T("\\");
				m_strTemplateDoc += strItemText;
				m_strTemplateDoc += m_strFilter;
			}
			TRACE("Item %d was selected!-%s\n", nItem,m_strTemplateDoc);
		}
	}	

	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CDocTemplateDlg::OnNMDblclkTemplatelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	POSITION pos = m_TemplateList.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		TRACE0("No items were selected!\n");
		return;
	}
	else
	{
		while (pos)
		{
			int nItem = m_TemplateList.GetNextSelectedItem(pos);
			CString strItemText = m_TemplateList.GetItemText(nItem,0);
			m_strTemplateDoc = _T("");
			if(strCurTabText==_T("Normal"))
				m_strTemplateDoc = m_strDocTemplatePath + strItemText + m_strFilter;
			else
			{
				m_strTemplateDoc = m_strDocTemplatePath;
				m_strTemplateDoc += strCurTabText;
				m_strTemplateDoc += _T("\\");
				m_strTemplateDoc += strItemText;
				m_strTemplateDoc += m_strFilter;
			}
			TRACE("Item %d was selected!-%s\n", nItem,m_strTemplateDoc);
		}
	}	
	OnBnClickedOk();
	*pResult = 0;
}

void CDocTemplateDlg::OnBnClickedOk()
{
	m_strDocTemplatePath = m_strTemplateDoc;
	OnOK();
}

void CDocTemplateDlg::OnTcnSelchangeTemplatetab(NMHDR *pNMHDR, LRESULT *pResult)
{
	m_TemplateList.DeleteAllItems();
	*pResult = 0;
	TCITEM TabCtrlItem ;
	TabCtrlItem.pszText = g_pTangram->m_szBuffer;;
	TabCtrlItem.mask|=TCIF_TEXT;
	TabCtrlItem.cchTextMax = 256;
	int index = m_tabCtrl.GetCurSel();
	m_tabCtrl.GetItem(index,&TabCtrlItem);
	CString strItem = TabCtrlItem.pszText;
	strCurTabText = strItem;
	CString strWildcard = m_strDocTemplatePath;
	if(strItem==_T("Normal"))
	{
		strWildcard += _T("*");
		strWildcard += m_strFilter;
	}
	else
	{
		strWildcard+=strItem;;
		strWildcard += _T("\\*");
		strWildcard += m_strFilter;
	}

	CFileFind finder;

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);
	int nIndex = 0;
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		CString strFileName = finder.GetFileName();
		CString strFileName2 = strFileName;
		strFileName2.MakeLower();
		int nPos = strFileName2.Find(m_strFilter);
		if(nPos!=-1)
		{
			strFileName=strFileName.Left(nPos);
			m_TemplateList.InsertItem(nIndex,strFileName);
			CTime m_Time;
			finder.GetCreationTime(m_Time);
			CString s = m_Time.Format(_T("%B %d, %Y"));
			m_TemplateList.SetItemText(nIndex, 2, s);
			nIndex++;
		}
	}

	finder.Close();
}
