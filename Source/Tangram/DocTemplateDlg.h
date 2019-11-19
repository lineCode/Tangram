/********************************************************************************
*					Tangram Library - version 1.0								*
*********************************************************************************
* Copyright (C) 2006 by Tangram Team.   All Rights Reserved.					*
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
* http://www.webaddin.com
* http://www.tangramworld.com
*
********************************************************************************/
#pragma once


// CDocTemplateDlg dialog

class CDocTemplateDlg : public CDialog
{
	DECLARE_DYNAMIC(CDocTemplateDlg)
public:
	CDocTemplateDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDocTemplateDlg();

// Dialog Data
	enum { IDD = IDD_DOCTEMPLATE };

	CString m_strDir;
	CString m_strFilter;
	CString m_strCaption;
	CString strCurTabText;
	CString m_strTemplateDoc;
	CString m_strDocTemplatePath;
	CTabCtrl m_tabCtrl;
	CListCtrl m_TemplateList;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

public:
	afx_msg void OnLvnItemchangedTemplatelist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTemplatelist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnTcnSelchangeTemplatetab(NMHDR *pNMHDR, LRESULT *pResult);
	DECLARE_MESSAGE_MAP()
};
