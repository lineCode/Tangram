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

// CSplitterNodeWnd

class CSplitterNodeWnd : public CSplitterWnd
{
	DECLARE_DYNCREATE(CSplitterNodeWnd)
public:
	void Save();
	void RecalcLayout();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CWndNode* m_pHostNode;
	bool bInited;
	int m_nHostWidth, m_nHostHeight;
	int m_Vmin,m_Vmax,m_Hmin,m_Hmax;
	int m_nNeedRefreshCol;
	COLORREF		rgbLeftTop;
	COLORREF		rgbMiddle;
	COLORREF		rgbRightBottom;
protected:
	CSplitterNodeWnd();           // protected constructor used by dynamic creation
	virtual ~CSplitterNodeWnd();

	BOOL			m_bCreated;
	
	//vector<RECT>	ColRect;
	//vector<RECT>	RowRect;

	//bool			bColMoving ;
	//bool			bRowMoving ;
	bool			m_bNeedRefreh;
	CWndNode*		m_pWndNode;

	BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	void StartTracking(int ht);
	void StopTracking(BOOL bAccept);
	void TrackRowSize(int y, int row);
	void TrackColumnSize(int x, int col);
	void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
	void PostNcDestroy();
	void DrawAllSplitBars(CDC* pDC, int cxInside, int cyInside);
	CWnd* GetActivePane(int* pRow = NULL, int* pCol = NULL);
	//void RefreshNode(IWndNode*);

	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg LRESULT OnActivePage(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnSplitterNodeAdd(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnActiveTangramObj(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnGetTangramObj(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnSplitterCreated(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	void _RecalcLayout();
	void TangramLayoutRowCol(CSplitterWnd::CRowColInfo* pInfoArray, int nMax, int nSize, int nSizeSplitter, CWndNode* pHostNode, bool bCol);
	void TangramDeferClientPos(AFX_SIZEPARENTPARAMS* lpLayout, CWnd* pWnd, int x, int y, int cx, int cy, BOOL bScrollBar);
};
