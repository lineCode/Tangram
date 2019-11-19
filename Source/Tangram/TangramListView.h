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

// CTangramListView view
class CTangramTabCtrl;
class CTangramListView : public CListView
{
	DECLARE_DYNCREATE(CTangramListView)

protected:
	CTangramListView();           // protected constructor used by dynamic creation
	virtual ~CTangramListView();

public:
	ICompositor* m_pCompositor;
	CTangramTabCtrl* m_pTangramTabCtrl;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL			m_bCreated;
	BOOL			m_bFilling;
	int				m_nStyle;
	int				m_nActiveIndex;
	CWndNode*		m_pWndNode;
	CImageList		m_ImageList;
	DECLARE_MESSAGE_MAP()
public:
	void FillListViewBySolution();
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg LRESULT OnActiveTangramPage(WPARAM wParam, LPARAM lParam);

	void InitTabCtrl(CTangramTabCtrl* pTabCtrl);
	void ChangeTemplate(int nItem);
};


