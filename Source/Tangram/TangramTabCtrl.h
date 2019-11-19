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

#pragma once

// CTangramListCtrl

class CTangramListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CTangramListCtrl)

public:
	CTangramListCtrl();
	virtual ~CTangramListCtrl();
	int		m_nListViewIndex;
	int		m_nListViewSelectedIndex;
	CString				m_strDir;
	CString				m_strSubDir;
	CTangramTabCtrl*	m_pTangramTabCtrl;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
};

// CTangramTabCtrl

class CTangramTabCtrl : public CTabCtrl
{
	DECLARE_DYNCREATE(CTangramTabCtrl)

public:
	CTangramTabCtrl();
	virtual ~CTangramTabCtrl();
	int					m_nImageIndex;
	CString				m_strFilter;
	CWndNode*			m_pWndNode;
	CCompositor*			m_pCompositor;
	CTangramListView*	m_pTangramListView;
	CTangramListCtrl	m_ListCtrl;
	IWebBrowser2*		m_pWebBrowser2;
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual void PostNcDestroy();
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg LRESULT OnInitialUpdate(WPARAM wParam, LPARAM lParam);

	void RePosition();
	void FillListCtrl();
};


