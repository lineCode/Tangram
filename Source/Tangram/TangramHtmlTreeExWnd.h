/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2018 by Tangram Team.   All Rights Reserved.				*
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
* mailto:sunhuizlz@yeah.net
* http://www.cloudaddin.com
*
********************************************************************************/
#pragma once
#include "TangramHtmlTreeWnd.h"

// CTangramHtmlTreeExWnd

class CTangramHtmlTreeExWnd : public CTangramHtmlTreeWnd
{
public:
	CTangramHtmlTreeExWnd();
	virtual ~CTangramHtmlTreeExWnd();

	void RefreshSubItems(HTREEITEM hParent);
	void SetWaitMessage(LPCTSTR pszText, HICON hIcon = NULL);
	void ShowWaitMessage()
	{
		m_bShowWaitMsg = TRUE;
	};
protected:
	// animation functions (with timer)
	void SetAnimationDelay(UINT nMilliseconds);

	// animation functions (with or without timer)
	virtual void PreAnimation(HTREEITEM hItemMsg);
	virtual void DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep);
	virtual void PostAnimation();
	BOOL GetItemImageRect(HTREEITEM hItem, LPRECT pRect);

	// tree content functions
	void PopulateRoot();
	virtual BOOL WantsRefresh(HTREEITEM hItem);
	virtual BOOL PopulateItem(HTREEITEM hParent) = 0;	// must be implemented

	// tree content functions (for animations without timer)
	int GetPopulationCount(int *piMaxSubItems = NULL);
	void SetPopulationCount(int iMaxSubItems, int iFirstSubItem = 0);
	void IncreasePopulation(int iSubItemsToAdd = 1);
	void UpdatePopulation(int iSubItems);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnItemExpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemExpanded(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
private:
	void DestroySnapshot();
	void DrawSnapshot(CDC* pDC);
	void TakeSnapshot();
	HANDLE m_hThread;				// secondary thread for animations
	HANDLE m_hTimerEvent;			// signaled at each timer period
	HANDLE m_hRedrawEvent;			// signaled at each population update
	volatile BOOL m_bAbortAnimation;	// request to terminate secondary thread
	BOOL m_bDrawSnapshot;			// whether to draw background during populating
	CBitmap m_bmpSnapshot;			// snapshot bitmap
	UINT m_nTimerID;				// animation timer id
	UINT m_nTimerDelay;				// animation timer period (ms)
	CString m_sWaitMsg;				// text for the wait message
	HICON m_hIconMsg;				// icon for the wait message
	BOOL m_bShowWaitMsg;			// wether to show the wait message
	int m_iItemIndex;				// population progress index
	int m_iItemCount;				// population progress max index
	HTREEITEM m_hItemMsg;			// wait message item
	HTREEITEM m_hItemToPopulate;	// item being populated

	// secondary thread entry point
	static DWORD WINAPI AnimationThreadProc(LPVOID pThis);
	
	void StartAnimation();		// set up animation thread
	void StopAnimation();		// animation clean up
	
	void PreExpandItem(HTREEITEM hItem);	// before expanding
	void ExpandItem(HTREEITEM hItem);		// after expanded

	BOOL NeedsChildren(HTREEITEM hParent);	// true if no child items
	void DeleteChildren(HTREEITEM hParent);

	void DrawUserIcon();	// draw wait message icon
};


#pragma once


// CTangramHtmlTreeEx2Wnd

class CTangramHtmlTreeEx2Wnd : public CTangramHtmlTreeExWnd
{
public:
	BOOL m_bEndless;
	void SetProgressType(BOOL bEndless);
	CTangramHtmlTreeEx2Wnd();
	virtual ~CTangramHtmlTreeEx2Wnd();

protected:
	virtual void PreSubclassWindow();
	virtual BOOL PopulateItem(HTREEITEM hParent);
	DECLARE_MESSAGE_MAP()
};


