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

#include "Tangram.c"
#include "TangramAppBase.h"
#include "TangramXmlParse.cpp"

#ifdef _AFXDLL
extern CFrameWnd* g_pTopLevelFrame = nullptr;
#endif

namespace TangramCommon
{
	ITangram* g_pTangram = nullptr;
	TangramCommon::CChromeBrowserCreatorImpl* g_pCreatorImpl = nullptr;

	IMPLEMENT_SERIAL(CTangramMFCToolBar, CMFCToolBar, VERSIONABLE_SCHEMA | 1)
	IMPLEMENT_SERIAL(CTangramTabbedPane, CTabbedPane, VERSIONABLE_SCHEMA | 2)
	IMPLEMENT_SERIAL(CTangramDockablePane, CDockablePane, VERSIONABLE_SCHEMA | 2)
	IMPLEMENT_DYNCREATE(CTangramMFCTabCtrl, CMFCTabCtrl)

	BEGIN_MESSAGE_MAP(CTangramTabbedPane, CTabbedPane)
	END_MESSAGE_MAP()

	BEGIN_MESSAGE_MAP(CTangramMFCTabCtrl, CMFCTabCtrl)
	END_MESSAGE_MAP()

	CTangramMFCTabCtrl::CTangramMFCTabCtrl()
	{
	}

	CTangramMFCTabCtrl::~CTangramMFCTabCtrl()
	{
	}

	BOOL CTangramMFCTabCtrl::FireChangingActiveTab(int nNewTab)
	{
		if(CTangramFrameWnd::m_pActiveTangramFrameWnd)
			AFXSetTopLevelFrame(CTangramFrameWnd::m_pActiveTangramFrameWnd);
		return CMFCTabCtrl::FireChangingActiveTab(nNewTab);
	}

	void CTangramMFCTabCtrl::FireChangeActiveTab(int nNewTab)
	{
		if (CTangramFrameWnd::m_pActiveTangramFrameWnd)
			AFXSetTopLevelFrame(CTangramFrameWnd::m_pActiveTangramFrameWnd);
		CMFCTabCtrl::FireChangeActiveTab(nNewTab);
	}

	CTangramMFCToolBar::CTangramMFCToolBar()
	{
	}

	CTangramMFCToolBar::~CTangramMFCToolBar()
	{
	}

	CTangramTabbedPane::CTangramTabbedPane()
	{
		m_pTabbedControlBarRTC = RUNTIME_CLASS(CTangramTabbedPane);
	}

	CTangramTabbedPane::~CTangramTabbedPane()
	{
	}

	CTabbedPane* CTangramTabbedPane::CreateTabbedPane()
	{
		m_pTabbedControlBarRTC = RUNTIME_CLASS(CTangramTabbedPane);
		return CTabbedPane::CreateTabbedPane();
	}

	void CTangramTabbedPane::ToggleAutoHide()
	{
		CDockablePane::ToggleAutoHide();
	}

	BOOL CTangramTabbedPane::CreateEx(DWORD dwStyleEx, LPCTSTR lpszCaption, CWnd* pParentWnd, const RECT& rect, BOOL bHasGripper,
		UINT nID, DWORD dwStyle, DWORD dwTabbedStyle, DWORD dwControlBarStyle, CCreateContext* pContext)
	{
		ASSERT_VALID(this);

		if (dwStyle & CBRS_FLOAT_MULTI)
		{
			m_pMiniFrameRTC = RUNTIME_CLASS(CMultiPaneFrameWnd);
		}

		if (dwTabbedStyle & AFX_CBRS_OUTLOOK_TABS)
		{
			m_pTabbedControlBarRTC = RUNTIME_CLASS(CMFCOutlookBar);
		}
		else if (dwTabbedStyle & AFX_CBRS_REGULAR_TABS)
		{
			m_pTabbedControlBarRTC = RUNTIME_CLASS(CTangramTabbedPane);
		}

		if (dwStyle & WS_CAPTION || bHasGripper)
		{
			m_bHasGripper = bHasGripper = TRUE;
			dwStyle &= ~WS_CAPTION;
		}

		if (!CPane::CreateEx(dwStyleEx, NULL, dwStyle, rect, pParentWnd, nID, dwControlBarStyle, pContext))
		{
			return FALSE;
		}

		m_rectRestored = rect;

		SetPaneAlignment(dwStyle & CBRS_ALIGN_ANY);
		EnableGripper(bHasGripper);

		if (m_sizeDialog != CSize(0, 0))
		{
			m_sizeDialog.cy += GetCaptionHeight();
			m_rectRestored.right = m_rectRestored.left + m_sizeDialog.cx;
			m_rectRestored.bottom = m_rectRestored.top + m_sizeDialog.cy;
		}

		if (lpszCaption != NULL)
		{
			SetWindowText(lpszCaption);
		}

		return TRUE;
	}

	CTangramDockablePane::CTangramDockablePane()
	{
		m_pTabbedControlBarRTC = RUNTIME_CLASS(CTangramTabbedPane);
	}

	CTangramDockablePane::~CTangramDockablePane()
	{
	}

	BOOL CTangramDockablePane::CreateEx(DWORD dwStyleEx, LPCTSTR lpszCaption, CWnd* pParentWnd, const RECT& rect, BOOL bHasGripper,
		UINT nID, DWORD dwStyle, DWORD dwTabbedStyle, DWORD dwControlBarStyle, CCreateContext* pContext)
	{
		ASSERT_VALID(this);

		if (dwStyle & CBRS_FLOAT_MULTI)
		{
			m_pMiniFrameRTC = RUNTIME_CLASS(CMultiPaneFrameWnd);
		}

		if (dwTabbedStyle & AFX_CBRS_OUTLOOK_TABS)
		{
			m_pTabbedControlBarRTC = RUNTIME_CLASS(CMFCOutlookBar);
		}
		else if (dwTabbedStyle & AFX_CBRS_REGULAR_TABS)
		{
			m_pTabbedControlBarRTC = RUNTIME_CLASS(CTangramTabbedPane);
		}

		if (dwStyle & WS_CAPTION || bHasGripper)
		{
			m_bHasGripper = bHasGripper = TRUE;
			dwStyle &= ~WS_CAPTION;
		}

		if (!CPane::CreateEx(dwStyleEx, NULL, dwStyle, rect, pParentWnd, nID, dwControlBarStyle, pContext))
		{
			return FALSE;
		}

		m_rectRestored = rect;

		SetPaneAlignment(dwStyle & CBRS_ALIGN_ANY);
		EnableGripper(bHasGripper);

		if (m_sizeDialog != CSize(0, 0))
		{
			m_sizeDialog.cy += GetCaptionHeight();
			m_rectRestored.right = m_rectRestored.left + m_sizeDialog.cx;
			m_rectRestored.bottom = m_rectRestored.top + m_sizeDialog.cy;
		}

		if (lpszCaption != NULL)
		{
			SetWindowText(lpszCaption);
		}

		return TRUE;
	}

	CTabbedPane* CTangramDockablePane::CreateTabbedPane()
	{
		m_pTabbedControlBarRTC = RUNTIME_CLASS(CTangramTabbedPane);
		return CDockablePane::CreateTabbedPane();
	}

	void CTangramDockablePane::ToggleAutoHide()
	{
		CDockablePane::ToggleAutoHide();
	}

	LRESULT CTangramDockablePane::OnShowCtrlBar(WPARAM wp, LPARAM lp)
	{
		if (lp == 19650601)
		{
			CWnd* pWnd = CWnd::FromHandlePermanent(::GetParent(m_hWnd));
			if (pWnd->IsKindOf(RUNTIME_CLASS(CPaneFrameWnd)))
			{
				CPaneFrameWnd* pFrame = (CPaneFrameWnd*)pWnd;
				pFrame->OnPaneRecalcLayout();
			}
			AdjustLayout();
		}
		return 0;
	}

	BEGIN_MESSAGE_MAP(CTangramDockablePane, CDockablePane)
		ON_MESSAGE(WM_QUERYAPPPROXY, OnShowCtrlBar)
	END_MESSAGE_MAP()

	BOOL CTangramOleMessageFilter::OnMessagePending(const MSG* pMsg)
	{
		//if (theAppImpl.m_pJVM)
		//	return false;
		return COleMessageFilter::OnMessagePending(pMsg);
	}

	IMPLEMENT_DYNCREATE(CTangramFrameWnd, CFrameWndEx)

	CTangramFrameWnd*  CTangramFrameWnd::m_pActiveTangramFrameWnd = nullptr;

	CTangramFrameWnd::CTangramFrameWnd()
	{
		m_pDoc = nullptr;
		m_hClient = nullptr;
		m_hwndLastTopLevelFrame = nullptr;
		m_strRegKey = _T("WorkSpace");
		theAppImpl.m_pTangramAppProxy->m_nFrameIndex++;
		m_nFrameIndex = theAppImpl.m_pTangramAppProxy->m_nFrameIndex;
		CString strFrameKey = _T("");
		strFrameKey.Format(_T("%d"), m_nFrameIndex);
		theAppImpl.m_pTangramAppProxy->m_mapMainFrame[strFrameKey] = this;
		g_pTangram->put_AppKeyValue(CComBSTR(L"newmdtframe"), CComVariant(strFrameKey));
		CTabbedPane::m_pTabWndRTC = RUNTIME_CLASS(CTangramMFCTabCtrl);
	}

	CTangramFrameWnd::~CTangramFrameWnd()
	{
	}

	BEGIN_MESSAGE_MAP(CTangramFrameWnd, CFrameWndEx)
		ON_WM_CLOSE()
		ON_WM_ACTIVATE()
		ON_WM_DESTROY()
		ON_WM_SETFOCUS()
		ON_WM_NCLBUTTONDOWN()
		ON_WM_WINDOWPOSCHANGED()
		ON_MESSAGE(WM_QUERYAPPPROXY, OnQueryAppProxy)
		ON_MESSAGE(WM_TANGRAMSETAPPTITLE, OnSetAppTitle)
	END_MESSAGE_MAP()

	BOOL CTangramFrameWnd::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
	{
		if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
		{
			return FALSE;
		}

		if (m_hClient)
		{
			POSITION nPos = m_dockManager.GetMiniFrames().GetHeadPosition();
			while (nPos != nullptr)
			{
				const CObject* pObj = m_dockManager.GetMiniFrames().GetNext(nPos);
				((CPaneFrameWnd*)pObj)->SetDockingManager(&m_dockManager);
			}
		}
		return TRUE;
	}

	BOOL CTangramFrameWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, LPCTSTR lpszMenuName, DWORD dwExStyle, CCreateContext* pContext)
	{
		BOOL bCreated = FALSE;
		AFXSetTopLevelFrame(this);
		CTangramFrameWnd::m_pActiveTangramFrameWnd = this;
		if (theAppImpl.m_pTangramAppProxy->m_hCreatingView)
		{
			m_pDoc = pContext->m_pCurrentDoc;
			m_hClient = theAppImpl.m_pTangramAppProxy->m_hCreatingView;
			SubclassWindow(::GetParent(m_hClient));
			if (afxContextIsDLL)
				::PostMessage(m_hWnd, WM_QUERYAPPPROXY, 0, 19891989);
			TCHAR m_szBuffer[MAX_PATH];
			::GetWindowText(m_hClient, m_szBuffer, MAX_PATH);
			CTangramMainFrameWnd* pFrame = new CTangramMainFrameWnd();
			pFrame->m_pHostFrame = this;
			pFrame->SubclassWindow(::GetAncestor(m_hWnd, GA_ROOT));
			m_strRegKey = CString(GetRuntimeClass()->m_lpszClassName);
			m_strRegKey += _T("@");
			m_strRegKey += AfxGetApp()->m_pszExeName;
			//if (theAppImpl.m_pJVM)
			//	m_strRegKey += _T("@eclipse");
			m_strRegKey += _T("@");
			m_strRegKey += CString(m_szBuffer);
			if (pContext&&pContext->m_pNewViewClass)
			{
				CView* pView = (CView*)pContext->m_pNewViewClass->CreateObject();
				pView->Create(nullptr, _T(""), WS_CHILD, CRect(0, 0, 0, 0), this, 0, pContext);
				pContext->m_pCurrentDoc->AddView(pView);
			}
			::SendMessage(m_hWnd, WM_CREATE, 0, 0);
			theAppImpl.m_pTangramAppProxy->m_hCreatingView = nullptr;
			((CWinAppEx*)AfxGetApp())->SetRegistryBase(m_strRegKey);
			AfxGetApp()->m_pMainWnd = this;
			theAppImpl.m_pTangramAppProxy->m_hMainWnd = m_hWnd;
			return TRUE;
		}
		((CWinAppEx*)AfxGetApp())->SetRegistryBase(m_strRegKey);
		return CFrameWndEx::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, lpszMenuName, dwExStyle, pContext);
	}

	void CTangramFrameWnd::OnWindowPosChanged(WINDOWPOS* lpwndpos)
	{
		if (m_hClient)
		{
			lpwndpos->flags |= SWP_NOSENDCHANGING;
			m_dockManager.RecalcLayout(false);
			AdjustClientArea();
			return;
		}
		CFrameWndEx::OnWindowPosChanged(lpwndpos);
	}

	BOOL CTangramFrameWnd::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		if (m_hClient == nullptr)
		{
			AFXSetTopLevelFrame(this);
		}
		//return CFrameWndEx::OnCommand(wParam, lParam);
		HWND hWndCtrl = (HWND)lParam;
		UINT nID = LOWORD(wParam);
		AFXSetTopLevelFrame(this);
		CFrameWnd* pFrameWnd = this;
		ENSURE_VALID(pFrameWnd);
		if (pFrameWnd->m_bHelpMode && hWndCtrl == NULL &&
			nID != ID_HELP && nID != ID_DEFAULT_HELP && nID != ID_CONTEXT_HELP)
		{
			// route as help
			if (!SendMessage(WM_COMMANDHELP, 0, HID_BASE_COMMAND + nID))
				SendMessage(WM_COMMAND, ID_DEFAULT_HELP);
			return TRUE;
		}

		// route as normal command
		return CWnd::OnCommand(wParam, lParam);
	}

	void CTangramFrameWnd::OnNcLButtonDown(UINT nHitTest, CPoint point)
	{
		if (m_hClient)
			return;
		CFrameWndEx::OnNcLButtonDown(nHitTest, point);
	}

	LRESULT CTangramFrameWnd::OnSetAppTitle(WPARAM wp, LPARAM lp)
	{
		if (m_hClient == nullptr)
		{
			CString strText = _T("");
			GetWindowText(strText);
			CString strTitle = (LPCTSTR)wp;
			int nPos = strText.ReverseFind('-');
			if (nPos != -1)
			{
				strText = strText.Left(nPos + 2);
				strText += strTitle;
				SetWindowText(strText);
			}
			else
				SetWindowText(strTitle);
			m_strTitle = strTitle;
		}
		return 0;
	}

	BOOL CTangramFrameWnd::OnShowPopupMenu(CMFCPopupMenu* pMenuPopup)
	{
		if (pMenuPopup == nullptr || ::IsWindow(pMenuPopup->m_hWnd) == false)
			return false;
		return CFrameWndEx::OnShowPopupMenu(pMenuPopup);
	}

	void CTangramFrameWnd::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
	{
		CFrameWndEx::OnActivate(nState, pWndOther, bMinimized);
		if (m_hClient)
		{
			switch (nState)
			{
			case WA_CLICKACTIVE:
				UpdateWindow();
				break;

			case WA_INACTIVE:
				if (!CMFCToolBar::IsCustomizeMode())
				{
					//m_Impl.DeactivateMenu();
				}

				if (CMFCPopupMenu::GetActiveMenu() != NULL)
				{
					CMFCPopupMenu::GetActiveMenu()->SendMessage(WM_CLOSE);
				}

				break;
			}

			if (nState == WA_INACTIVE)
			{
				if (g_pTopLevelFrame == this)
				{
					CFrameWnd* pTopLevelFrame = DYNAMIC_DOWNCAST(CFrameWnd, CWnd::FromHandlePermanent(m_hwndLastTopLevelFrame));

					AFXSetTopLevelFrame(pTopLevelFrame);
				}
			}
			else
			{
				CTangramFrameWnd::m_pActiveTangramFrameWnd = this;
				m_hwndLastTopLevelFrame = g_pTopLevelFrame->GetSafeHwnd();
				g_pTopLevelFrame = this;
			}
		}
	}

	void CTangramFrameWnd::OnClose()
	{
		if (m_hClient)
		{
			::SendMessage(::GetAncestor(m_hWnd, GA_ROOT), WM_CLOSE, 0, 0);
			return;
		}
		((CWinAppEx*)AfxGetApp())->SetRegistryBase(m_strRegKey);
		CFrameWndEx::OnClose();
		if (theAppImpl.m_pTangramAppProxy->m_mapMainFrame.size() == 0&& afxContextIsDLL)
		{
			AfxOleUnlockApp();
			if (AfxOleCanExitApp())
				AfxOleSetUserCtrl(true);
		}
	}

	void CTangramFrameWnd::OnSetFocus(CWnd* pOldWnd)
	{
		if (m_pViewActive != NULL)
		{
			if (m_hClient)
				::SetFocus(m_pViewActive->m_hWnd);
			else
				m_pViewActive->SetFocus();
		}
		else
			CWnd::OnSetFocus(pOldWnd);
		//CTangramFrameWnd::OnSetFocus(pOldWnd);
	}

	void CTangramFrameWnd::OnDestroy()
	{
		if (m_hClient)
		{
			if (CMFCPopupMenu::GetActiveMenu() != NULL)
			{
				if(::IsWindow(CMFCPopupMenu::GetActiveMenu()->m_hWnd))
					CMFCPopupMenu::GetActiveMenu()->SendMessage(WM_CLOSE);
			}

			if (g_pTopLevelFrame == this)
			{
				CFrameWnd* pTopLevelFrame = DYNAMIC_DOWNCAST(CFrameWnd, CWnd::FromHandlePermanent(m_hwndLastTopLevelFrame));
				g_pTopLevelFrame = pTopLevelFrame;
			}

			//m_Impl.DeactivateMenu();

			if (m_hAccelTable != NULL)
			{
				::DestroyAcceleratorTable(m_hAccelTable);
				m_hAccelTable = NULL;
			}

			m_dockManager.m_bEnableAdjustLayout = FALSE;

			//CList<HWND, HWND> lstChildren;
			//CWnd* pNextWnd = GetTopWindow();

			//while (pNextWnd != NULL)
			//{
			//	lstChildren.AddTail(pNextWnd->m_hWnd);
			//	pNextWnd = pNextWnd->GetNextWindow();
			//}

			//for (POSITION pos = lstChildren.GetHeadPosition(); pos != NULL;)
			//{
			//	HWND hwndNext = lstChildren.GetNext(pos);
			//	if (IsWindow(hwndNext) && ::GetParent(hwndNext) == m_hWnd)
			//	{
			//		::DestroyWindow(hwndNext);
			//	}
			//}

			theAppImpl.m_pTangramAppProxy->m_hClosingFrame = m_hWnd;
			((CWinAppEx*)AfxGetApp())->SetRegistryBase(m_strRegKey);
			AfxGetApp()->m_pMainWnd = this;
			CFrameWndEx::OnClose();
			POSITION nPos = m_dockManager.GetMiniFrames().GetHeadPosition();
			while (nPos != nullptr)
			{
				const CObject* pObj = m_dockManager.GetMiniFrames().GetNext(nPos);
				((CPaneFrameWnd*)pObj)->SetDockingManager(&m_dockManager);
				((CPaneFrameWnd*)pObj)->DestroyWindow();
			}
		}

		CFrameWndEx::OnDestroy();
		if (AFXGetTopLevelFrame(this) == this)
		{
			AFXSetTopLevelFrame(nullptr);
		}
		theAppImpl.m_pTangramAppProxy->m_hClosingFrame = nullptr;
	}

	LRESULT CTangramFrameWnd::OnQueryAppProxy(WPARAM wp, LPARAM lp)
	{
		if (lp)
		{
			switch (lp)
			{
			case 19651965:
				this->RecalcLayout();
				break;
			case 19631965:
				return (LRESULT)this;
				break;
			case 19891989:
				if (::IsWindowVisible(::GetParent(m_hWnd)))
					ShowWindow(SW_SHOW);
				break;
			case 19631222:
				{
					if (m_pDoc&&m_hClient==NULL)
						m_pDoc->DoSave(m_pDoc->GetPathName(), true);

					((CWinAppEx*)AfxGetApp())->SetRegistryBase(m_strRegKey);
					if (m_hClient)
					{
						((CWinAppEx*)AfxGetApp())->SaveState(this, 0);
					}
					return 0;
				}
				break;
			case 19631992:
				AfxGetApp()->m_pMainWnd = this;
				break;
			case 19650601:
			{
				CWnd* pWnd = CWnd::FromHandlePermanent((HWND)wp);
				if (pWnd->IsKindOf(RUNTIME_CLASS(CDockablePane)))
				{
					CDockablePane* pDockablePane = (CDockablePane*)pWnd;
					pDockablePane->RecalcLayout();
				}
			};
			break;
			case 19921992://
			{
				CView* pView = (CView*)wp;
				HWND hWnd = ::GetWindow(m_hWnd, GW_CHILD);
				pView->SubclassWindow(hWnd);
				return 0;
			}
			break;
			case 10000://
			{
				//HWND hWnd = (HWND)wp;
				AFXSetTopLevelFrame(this);
				//CWnd * pWnd = CWnd::FromHandlePermanent(hWnd);
				//if (pWnd)
				//{
				//	CString strName = CString(pWnd->GetRuntimeClass()->m_lpszClassName);
				//	ATLTRACE(_T("bar wnd:%s\n"), strName);
				//	if (pWnd->IsKindOf(RUNTIME_CLASS(CMFCRibbonPanelMenu)))
				//	{
				//		CMFCRibbonPanelMenu* pFrame = (CMFCRibbonPanelMenu*)pWnd;
				//		pFrame->SendMessage(WM_IDLEUPDATECMDUI);
				//	}
				//}
				return 0;
			}
			break;
			case 19921989:
				if (wp)
				{
					CWnd* pChildWnd = GetDlgItem(AFX_IDW_PANE_FIRST);
					if (pChildWnd != NULL)
					{
						CRect rectClientAreaBounds = m_dockManager.GetClientAreaBounds();

						rectClientAreaBounds.left += m_rectBorder.left;
						rectClientAreaBounds.top += m_rectBorder.top;
						rectClientAreaBounds.right -= m_rectBorder.right;
						rectClientAreaBounds.bottom -= m_rectBorder.bottom;

						pChildWnd->CalcWindowRect(rectClientAreaBounds);
						LPRECT lpRC = (LPRECT)wp;
						lpRC->left = rectClientAreaBounds.left;
						lpRC->right = rectClientAreaBounds.right;
						lpRC->top = rectClientAreaBounds.top;
						lpRC->bottom = rectClientAreaBounds.bottom;
						return lp;
					}
					return 0;
				}
				break;
			default:
				CString strKey = (LPCTSTR)lp;
				if (strKey != _T("") && strKey != _T("default"))
				{
					auto it = theAppImpl.m_pTangramAppProxy->m_mapMainFrame.find(_T("default"));
					if (it != theAppImpl.m_pTangramAppProxy->m_mapMainFrame.end() && it->second == this)
					{
						theAppImpl.m_pTangramAppProxy->m_mapMainFrame.erase(it);
						theAppImpl.m_pTangramAppProxy->m_mapMainFrame[strKey] = this;
					}
				}
				break;
			}
		}
		return (LRESULT)(static_cast<ITangramAppProxy*>(theAppImpl.m_pTangramAppProxy));
	}

	CTangramMainFrameWnd::CTangramMainFrameWnd()
	{
		m_pHostFrame = nullptr;
	}

	CTangramMainFrameWnd::~CTangramMainFrameWnd()
	{
		ATLTRACE(_T("Delete CTangramMainFrameWnd:%x\n"), this);
	}

	BEGIN_MESSAGE_MAP(CTangramMainFrameWnd, CWnd)
		ON_WM_ACTIVATE()
	END_MESSAGE_MAP()

	void CTangramMainFrameWnd::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
	{
		CFrameWndEx::OnActivate(nState, pWndOther, bMinimized);
		if (m_pHostFrame)
		{
			switch (nState)
			{
			case WA_CLICKACTIVE:
				m_pHostFrame->UpdateWindow();
				break;

			case WA_INACTIVE:
				if (!CMFCToolBar::IsCustomizeMode())
				{
					//m_pHostFrame->GetFrameImpl();
					//m_pHostFrame->GetFrameImpl()->DeactivateMenu();
				}

				if (CMFCPopupMenu::GetActiveMenu() != NULL&&::IsWindow(CMFCPopupMenu::GetActiveMenu()->m_hWnd))
				{
					if(::IsWindow(CMFCPopupMenu::GetActiveMenu()->m_hWnd))
						CMFCPopupMenu::GetActiveMenu()->SendMessage(WM_CLOSE);
					else
					{
						m_pHostFrame->OnClosePopupMenu(CMFCPopupMenu::GetActiveMenu());
					}
				}

				break;
			}

			if (nState == WA_INACTIVE)
			{
				if (g_pTopLevelFrame == this)
				{
					//CFrameWndEx* pTopLevelFrame = DYNAMIC_DOWNCAST(CFrameWndEx, CWnd::FromHandlePermanent(m_hwndLastTopLevelFrame));

					AFXSetTopLevelFrame(m_pHostFrame);
				}
			}
			else
			{
				CTangramFrameWnd::m_pActiveTangramFrameWnd = m_pHostFrame;
				m_pHostFrame->m_hwndLastTopLevelFrame = g_pTopLevelFrame->GetSafeHwnd();
				g_pTopLevelFrame = m_pHostFrame;
			}
		}
	}

	BOOL CTangramMainFrameWnd::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
	{
		// let the view have first crack at the command
		if (m_pHostFrame&&m_pHostFrame->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		{
			return TRUE;
		}

		// otherwise, do default handling
		return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
	}

	BOOL CTangramMainFrameWnd::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		// TODO: Add your specialized code here and/or call the base class
		if(m_pHostFrame&&m_pHostFrame->OnCommand(wParam, lParam))
			return true;
		return CFrameWnd::OnCommand(wParam, lParam);
	}

	// CTangramMainWnd message handlers

	CTangramMainWnd::CTangramMainWnd()
	{
	}

	CTangramMainWnd::~CTangramMainWnd()
	{
		ATLTRACE(_T("Delete CTangramMainWnd:%x\n"), this);
	}

	BEGIN_MESSAGE_MAP(CTangramMainWnd, CWnd)
	END_MESSAGE_MAP()

	// CTangramMainWnd message handlers

	void CTangramMainWnd::PostNcDestroy()
	{
		CWnd::PostNcDestroy();
		delete this;
	}

	CTangramDocProxy::CTangramDocProxy()
	{
		m_bCanDestroyFrame = true;
		m_strTangramID = _T("19631222199206121965060119820911");
		m_strAppProxyID = theAppImpl.m_pTangramAppProxy->m_strProxyID;
		m_strMainFrameID = _T("");
		m_strDocID = _T("");
		m_strTangramData = _T("");
		m_bDocLoaded = false;

		theAppImpl.m_pTangramAppProxy->m_pCurDocProxy = this;
	};

	CTangramDocProxy::~CTangramDocProxy()
	{
		m_pDoc				= nullptr;
		m_strTangramData	= _T("");
	};

	CTangramDocHelper::CTangramDocHelper()
	{
		m_pDoc				= nullptr;
		m_pDocument			= nullptr;
		m_strTangramData	= _T("");
	}

	CTangramDocHelper::~CTangramDocHelper()
	{
	}

	void CTangramDocHelper::TangramSerialize(CDocument* _pDoc, CArchive* pAr)
	{
		ITangramAppProxy* pProxy = (ITangramAppProxy*)theAppImpl.m_pTangramAppProxy;
		if (m_pDocument == nullptr&&_pDoc)
		{
			m_pDoc = nullptr;
			m_strTangramData = _T("");
			m_pDocument = _pDoc;

			auto it = pProxy->m_mapTangramDoc.find((LONGLONG)_pDoc);
			if (it != pProxy->m_mapTangramDoc.end())
				m_pDoc = it->second;
			if (m_pDoc == nullptr)
				return;
			if (pAr == nullptr)
			{
				m_bDocLoaded = true;
				m_mapDataMap.RemoveAll();
				m_pDoc->put_TemplateXml(CComBSTR(L""));
			}
		}
		if (m_pDoc&&pAr)
		{
			if (pAr->IsStoring())
			{
				CComBSTR bstrUIData(_pDoc->GetPathName());
				m_pDoc->get_TemplateXml(&bstrUIData);
				m_strTangramData = OLE2T(bstrUIData);
				(*pAr) << m_strTangramID;
				(*pAr) << m_strAppProxyID;
				(*pAr) << m_strAppName;
				(*pAr) << m_strMainFrameID;
				(*pAr) << m_strDocID;
				(*pAr) << m_strTangramData;
				m_mapDataMap.Serialize(*pAr);
			}
			else
			{
				(*pAr) >> m_strTangramID;
				(*pAr) >> m_strAppProxyID;
				(*pAr) >> m_strAppName;
				(*pAr) >> m_strMainFrameID;
				(*pAr) >> m_strDocID;
				(*pAr) >> m_strTangramData;
				m_mapDataMap.Serialize(*pAr);
				m_bDocLoaded = true;
				m_pDoc->put_TemplateXml(m_strTangramData.AllocSysString());
			}
		}
	}

	CTangramViewHelper::CTangramViewHelper()
	{
		m_pDoc		= nullptr;
		m_strDocID	= _T("");
	}

	CTangramViewHelper::~CTangramViewHelper()
	{

	}

	BOOL CTangramViewHelper::CreateView(CCreateContext* pContext, HWND hView, HWND hParent)
	{
		if (::IsWindow(hView) && g_pTangram)
		{
			pContext->m_pNewDocTemplate->GetDocString(m_strDocID, CDocTemplate::regFileTypeId);
			auto it = theAppImpl.m_pTangramAppProxy->m_mapTangramDoc.find((LONGLONG)pContext->m_pCurrentDoc);
			if (it != theAppImpl.m_pTangramAppProxy->m_mapTangramDoc.end())
			{
				m_pDoc = (ITangramDoc*)it->second;
			}
			else
			{
				m_pDoc = (ITangramDoc*)theAppImpl.m_pTangramAppProxy->m_pTangramImpl->ConnectTangramDoc((ITangramAppProxy*)theAppImpl.m_pTangramAppProxy, (LONGLONG)pContext->m_pCurrentDoc, hView, hParent, m_strDocID);
				theAppImpl.m_pTangramAppProxy->m_mapTangramDoc[(LONGLONG)pContext->m_pCurrentDoc] = m_pDoc;
			}
			if (m_pDoc)
				return TRUE;
		}
		return FALSE;
	}

	ITangramAppProxy::ITangramAppProxy()
	{
		m_bAutoDelete = TRUE;
		m_hMainWnd = nullptr;
		m_hClosingFrame = m_hCreatingView = nullptr;
		m_pvoid = nullptr;
		m_pCurDocProxy = nullptr;
		m_strProxyName = _T("");
		m_strProxyID = _T("");
		m_strClosingFrameID = _T("");
		m_strCreatingFrameTitle = _T("");

		m_bCreatingNewFrame = FALSE;
		m_mapTangramDoc.clear();
		m_pTangramWnd = nullptr;

		m_nFrameIndex = 0;
		m_strAppKey = _T("");
		if (afxContextIsDLL)
		{
#ifndef _AFXDLL
			CDocManager::bStaticInit = false;
#endif
		}
	}

	BOOL ITangramAppProxy::InitTangram(void* pVoid)
	{
		if (g_pTangram)
			return S_OK;

		CWinThread* pThread = AfxGetThread();
		if (pThread != NULL)
		{
			// destroy message filter (may be derived class)
			delete pThread->m_pMessageFilter;
			pThread->m_pMessageFilter = NULL;
		}
		// allocate and initialize default message filter
		if (!afxContextIsDLL&&pThread->m_pMessageFilter == NULL)
		{
			pThread->m_pMessageFilter = new CTangramOleMessageFilter;
			ASSERT(AfxOleGetMessageFilter() != NULL);
			pThread->m_pMessageFilter->EnableNotRespondingDialog(false);
			pThread->m_pMessageFilter->SetMessagePendingDelay(20000);
			AfxOleGetMessageFilter()->Register();
		}

		HMODULE hModule = ::LoadLibrary(L"tangramcore.dll");
		if (hModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			HRESULT hr =
				SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer);
			if (hr == S_OK) {
				CString m_strProgramFilePath = CString(m_szBuffer);
				m_strProgramFilePath += _T("\\Tangram\\Tangramcore.dll");
				if (::PathFileExists(m_strProgramFilePath)) {
					hModule = ::LoadLibrary(m_strProgramFilePath);
				}
			}
		}
		if (hModule) {
			typedef ITangram*(__stdcall * GetTangram)();
			GetTangram _pTangramFunction;
			_pTangramFunction = (GetTangram)GetProcAddress(hModule, "GetTangram");
			if (_pTangramFunction != NULL) {
				g_pTangram = _pTangramFunction();
			}
			typedef CTangramImpl*(__stdcall * GetTangramImpl)();
			GetTangramImpl _pTangramFunction2;
			_pTangramFunction2 = (GetTangramImpl)GetProcAddress(hModule, "GetTangramImpl");
			if (_pTangramFunction2 != NULL) {
				m_pTangramImpl = _pTangramFunction2();
			}
		}

		if (g_pTangram)
		{
			//theAppImpl.m_pTangram = g_pTangram;
			theAppImpl.m_pTangramAppProxy = (ITangramAppProxy*)this; 
			m_pvoid = pVoid;
			m_mapTangramDoc.clear();
			m_strCreatingFrameTitle = _T("");
			CWinApp* pApp = AfxGetApp();
			CString strXml = _T("<template>");
			if (pApp)
			{
				m_hInstance = pApp->m_hInstance;
				m_strProxyName = pApp->m_pszExeName;
				m_strProxyID = pApp->m_pszAppID;
				CString s1 = m_strProxyID;
				POSITION nPos = pApp->GetFirstDocTemplatePosition();
				while (nPos)
				{
					CString strExt = _T("");
					CDocTemplate* pTemplate = pApp->GetNextDocTemplate(nPos);
					pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
					strExt.MakeLower();
					if (strExt != _T(""))
					{
						CString strFileTypeID = _T("");
						pTemplate->GetDocString(strFileTypeID, CDocTemplate::regFileTypeId);
						strFileTypeID.MakeLower();
						CString strfilterName = _T("");
						pTemplate->GetDocString(strfilterName, CDocTemplate::filterName);
						auto it = m_mapTangramDocTemplateID.find(pTemplate);
						if (it != m_mapTangramDocTemplateID.end())
						{
							int nResID = -1;
							nResID = it->second;
							if (pVoid)
							{
								CString s = _T("");
								s1.MakeLower();
								s.Format(_T("<%s%s ResID=\"%d\">%s|%s|*%s|%s|</%s%s>"), s1, strExt, nResID,strFileTypeID, strfilterName,strExt, m_strProxyName, s1, strExt);
								strXml += s;
								g_pTangram->put_AppKeyValue(CComBSTR(L"defaulttemplate"), CComVariant(strXml));
								//m_pTangramProxyBase->m_mapValInfo[_T("defaulttemplate")] = CComVariant(strXml);
							}
							CString strProxyID = m_strProxyID;
							if (strFileTypeID != _T("") && strExt != _T("") && pTemplate)
							{
								strFileTypeID.MakeLower();
								strProxyID.MakeLower();
								strExt.MakeLower();
								m_pTangramImpl->ConnectDocTemplate(strFileTypeID, strExt, pTemplate);

								CString strXml = m_pTangramImpl->m_strDefaultTemplate;
								CString _strKey = strProxyID + strExt;
								if (m_pTangramImpl->m_bExportComponent&&strXml.Find(_strKey) == -1)
								{

									CString strPath = m_pTangramImpl->m_strAppCommonDocPath + _T("Tangramdoctemplate.xml");
									if (::PathFileExists(strPath))
									{
										DocTemplateInfo* pDocTemplateInfo = new DocTemplateInfo;
										pDocTemplateInfo->bDll = true;
										pDocTemplateInfo->nResID = nResID;
										pDocTemplateInfo->strExt = strExt;
										pDocTemplateInfo->strFileTypeID = strFileTypeID;
										pDocTemplateInfo->strfilterName = strfilterName;
										pDocTemplateInfo->strProxyID = strProxyID;
										pDocTemplateInfo->strProxyName = m_strProxyName;
										CTangramXmlParse m_Parse;
										m_Parse.LoadFile(strPath);
										CString _strKey = pDocTemplateInfo->strProxyID + pDocTemplateInfo->strExt;
										if (m_Parse.GetChild(_strKey) == nullptr)
										{
											CTangramXmlParse* pParse = m_Parse.AddNode(_strKey);
											CString strVal = _T("");
											strVal += pDocTemplateInfo->strFileTypeID;
											strVal += _T("|");
											strVal += pDocTemplateInfo->strfilterName;
											strVal += _T("|");
											strVal += _T("*") + pDocTemplateInfo->strExt;
											strVal += _T("|");
											strVal += pDocTemplateInfo->strProxyName;
											strVal += _T("|");
											if (pDocTemplateInfo->nResID != -1)
											{
												CString strID = _T("");
												strID.Format(_T("%d"), pDocTemplateInfo->nResID);
												pParse->put_attr(_T("ResID"), strID);
											}
											pParse->put_text(strVal);
											m_Parse.SaveFile(strPath);
											if (pDocTemplateInfo->bDll)
											{
												TCHAR	m_szBuffer[MAX_PATH];
												HRESULT hr = SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, m_szBuffer);
												CString strPath = CString(m_szBuffer);
												strPath += _T("\\TangramCommonDocTemplate\\TangramReg.xml");
												CTangramXmlParse m_Parse2;
												if (::PathFileExists(strPath) == FALSE)
												{
													m_Parse2.LoadXml(_T("<TangramDocReg />"));
													m_Parse2.SaveFile(strPath);
												}
												else
												{
													m_Parse2.LoadFile(strPath);
												}
												if (m_Parse2.GetChild(pDocTemplateInfo->strProxyID) == false)
												{
													m_Parse2.AddNode(pDocTemplateInfo->strProxyID);
													m_Parse2.SaveFile(strPath);
												}
											}
										}
										delete pDocTemplateInfo;
									}
								}
							}
						}
					}
				}
				if (pVoid)
				{
					strXml += _T("</template>");
					g_pTangram->put_AppKeyValue(CComBSTR(L"defaulttemplate"), CComVariant(strXml));
				}
			}
			m_bAutoDelete = FALSE;
			HRESULT hr = S_OK;
#ifndef _WIN64
			//hr = g_pTangram->put_AppKeyValue(CComBSTR(_T("TangramApplicationImpl")), CComVariant((long)(static_cast<CTangramApplicationImpl*>(&theAppImpl))));
#else
			//hr = g_pTangram->put_AppKeyValue(CComBSTR(_T("TangramApplicationImpl")), CComVariant((__int64)(static_cast<CTangramApplicationImpl*>(&theAppImpl))));
#endif
			if (afxContextIsDLL&&hr == S_OK)
				return true;

			return !(hr == S_OK);
		}
		return TRUE;
	}

	HWND ITangramAppProxy::CreateNewFrame(CString strFrameKey)
	{
		if (m_pvoid)
		{
			if (AfxGetApp()->ProcessShellCommand(*(CCommandLineInfo*)(m_pvoid)))
				m_pvoid = nullptr;
		}
		return nullptr;
	};

	void ITangramAppProxy::OnActiveMainFrame(HWND hWnd)
	{
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		if (pWnd)
		{
			AfxGetApp()->m_pMainWnd = pWnd;
			AFXSetTopLevelFrame((CFrameWnd*)pWnd);
		}
	}

	int ITangramAppProxy::OnDestroyMainFrame(CString strID, int nMainFrameCount, int nWndType)
	{
		CWinApp* pApp = AfxGetApp();
		switch (nWndType)
		{
		case 0:
		{
			auto it = m_mapMainFrame.find(strID.MakeLower());
			if (it != m_mapMainFrame.end())
			{
				m_mapMainFrame.erase(it);
				if (m_mapMainFrame.size())
				{
					CWnd* pWnd = (CWnd*)m_mapMainFrame.begin()->second;
					pApp->m_pMainWnd = pWnd;
					return m_mapMainFrame.size();
				}
				else if (!afxContextIsDLL)
				{
					if (nMainFrameCount == 0)
						return 0;
					if (m_pTangramWnd == nullptr)
					{
						CComVariant var;
						g_pTangram->get_AppKeyValue(CComBSTR(_T("tangrammsgwnd")), &var);
						HWND hWnd = (HWND)var.llVal;
						m_pTangramWnd = new CTangramMainWnd();
						m_pTangramWnd->SubclassWindow(hWnd);
						::VariantClear(&var);
					}
					pApp->m_pMainWnd = m_pTangramWnd;
				}
				return m_mapMainFrame.size();
			}
		}
		break;
		case 1:
		{
			int nPos = strID.Find(_T("-ondestroy"));
			if (nPos == -1)
			{
				auto it = m_mapMainFrame.find(strID.MakeLower());
				if (it != m_mapMainFrame.end())
				{
					CWnd* pWnd = (CWnd*)it->second;
					int nSize = m_mapMainFrame.size();
					if (pApp->m_pMainWnd&&pApp->m_pMainWnd->m_hWnd == pWnd->m_hWnd&&nSize > 1)
					{
						for (auto it : m_mapMainFrame)
						{
							if (it.second != pWnd)
							{
								pApp->m_pMainWnd = (CWnd*)it.second;
								break;
							}
						}
					}
					else
					{
						if (nSize == 1 && nMainFrameCount > 1)
						{
							if (!afxContextIsDLL)
							{
								if (m_pTangramWnd == nullptr)
								{
									CComVariant var;
									g_pTangram->get_AppKeyValue(CComBSTR(_T("tangrammsgwnd")), &var);
									HWND hWnd = (HWND)var.llVal;
									m_pTangramWnd = new CTangramMainWnd();
									m_pTangramWnd->SubclassWindow(hWnd);
									::VariantClear(&var);
								}
								pApp->m_pMainWnd = m_pTangramWnd;
							}
						}
					}
				}
			}
			else
			{
				strID.Replace(_T("-ondestroy"), _T(""));
				auto it = m_mapMainFrame.find(strID.MakeLower());
				if (it != m_mapMainFrame.end())
				{
					m_mapMainFrame.erase(it);
					if (m_mapMainFrame.size())
					{
						CWnd* pWnd = (CWnd*)m_mapMainFrame.begin()->second;
						pApp->m_pMainWnd = pWnd;
						return m_mapMainFrame.size();
					}
					else if (!afxContextIsDLL)
					{
						if (nMainFrameCount == 0)
							return 0;
						if (m_pTangramWnd == nullptr)
						{
							CComVariant var;
							g_pTangram->get_AppKeyValue(CComBSTR(_T("tangrammsgwnd")), &var);
							HWND hWnd = (HWND)var.llVal;
							m_pTangramWnd = new CTangramMainWnd();
							m_pTangramWnd->SubclassWindow(hWnd);
							::VariantClear(&var);
						}
						pApp->m_pMainWnd = m_pTangramWnd;
					}
					else
					{
						AfxOleLockApp();
					}
					return m_mapMainFrame.size();
				}
			}
		}
		break;
		}
		if (nMainFrameCount == 0 && m_pTangramWnd)
		{
			::SendMessage(m_pTangramWnd->m_hWnd, WM_DESTROY, 0, 0);
			pApp->m_pMainWnd = nullptr;
			::PostAppMessage(::GetCurrentThreadId(), WM_QUIT, 0, 0);
		}
		return -1;
	}

	LRESULT ITangramAppProxy::OnForegroundIdleProc()
	{
		if (::IsWindow(m_hMainWnd) == FALSE)
			return 0;
		// send WM_IDLEUPDATECMDUI to the main window
		CWnd* pMainWnd = AfxGetApp()-> m_pMainWnd;
		if (pMainWnd != NULL && pMainWnd->m_hWnd != NULL &&
			pMainWnd->IsWindowVisible())
		{
			AfxCallWndProc(pMainWnd, pMainWnd->m_hWnd, WM_IDLEUPDATECMDUI, (WPARAM)TRUE, 0);
			pMainWnd->SendMessageToDescendants(WM_IDLEUPDATECMDUI,
				(WPARAM)TRUE, 0, TRUE, TRUE);
		}
		return 0;
		// send WM_IDLEUPDATECMDUI to all frame windows
		AFX_MODULE_THREAD_STATE* pState = AfxGetModuleState()->m_thread;
		CFrameWnd* pFrameWnd = pState->m_frameList;
		while (pFrameWnd != NULL)
		{
			if (pFrameWnd->m_hWnd != NULL && pFrameWnd != pMainWnd)
			{
				if (pFrameWnd->m_nShowDelay == SW_HIDE)
					pFrameWnd->ShowWindow(pFrameWnd->m_nShowDelay);
				if (pFrameWnd->IsWindowVisible() ||
					pFrameWnd->m_nShowDelay >= 0)
				{
					CFrameWnd* pP = nullptr;
					if (pFrameWnd->IsKindOf(RUNTIME_CLASS(CMFCRibbonPanelMenu)))
					{
						pP = AFXGetTopLevelFrame(pFrameWnd);
						AFXSetTopLevelFrame(pFrameWnd);
						ATLTRACE(_T("\n"));
					}
					AfxCallWndProc(pFrameWnd, pFrameWnd->m_hWnd,
						WM_IDLEUPDATECMDUI, (WPARAM)TRUE, 0);
					pFrameWnd->SendMessageToDescendants(WM_IDLEUPDATECMDUI,
						(WPARAM)TRUE, 0, TRUE, TRUE);
					if (pFrameWnd->IsKindOf(RUNTIME_CLASS(CMFCPopupMenu)))
					{
						pMainWnd->SendMessageToDescendants(WM_IDLEUPDATECMDUI,
							(WPARAM)TRUE, 0, TRUE, TRUE);
					}
					if(pP)
						AFXSetTopLevelFrame(pP);
				}
				if (pFrameWnd->m_nShowDelay > SW_HIDE)
					pFrameWnd->ShowWindow(pFrameWnd->m_nShowDelay);
				pFrameWnd->m_nShowDelay = -1;
			}
			pFrameWnd = pFrameWnd->m_pNextFrameWnd;
		}
		return 0;
	}

	BOOL ITangramAppProxy::TangramPreTranslateMessage(MSG* pMsg)
	{
		if (pMsg->message == WM_CHAR|| pMsg->hwnd==nullptr)
			return TRUE;
		HWND hwnd = pMsg->hwnd;
		CWinApp* pApp = AfxGetApp();
		CWnd* pWnd = CWnd::FromHandlePermanent(hwnd);
		if (pWnd)
		{
			if (CMFCPopupMenu::GetActiveMenu() && !::IsWindow(CMFCPopupMenu::GetActiveMenu()->m_hWnd))
			{
				return true;
			}
			if(::GetAncestor(hwnd,GA_ROOTOWNER) == ::GetAncestor(pApp->m_pMainWnd->m_hWnd,GA_ROOTOWNER))
				AFXSetTopLevelFrame((CFrameWnd*)pApp->m_pMainWnd);
			if (pMsg->message == WM_LBUTTONDOWN)
			{
				pApp->m_pMainWnd->PreTranslateMessage(pMsg);
				return true;
			}
			return pWnd->PreTranslateMessage(pMsg);
		}
		else
			return TRUE;
		return pApp->PreTranslateMessage(pMsg);
	}

	void ITangramAppProxy::MouseMoveProxy(HWND hWnd)
	{
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		if (pWnd)
		{
			if (pWnd->IsKindOf(RUNTIME_CLASS(CPaneFrameWnd))|| pWnd->IsKindOf(RUNTIME_CLASS(CMFCToolBar)))
			{
				CFrameWnd* pWnd2 = pWnd->GetParentFrame();
				if (pWnd2)
					AFXSetTopLevelFrame(pWnd2);
				else
				{
					HWND hParent = ::GetParent(hWnd);
					pWnd2 = (CFrameWnd*)::SendMessage(hParent, WM_TANGRAMMSG, 0, 19631965);
					if (pWnd2 == nullptr)
					{
						CWnd* _pWnd = CWnd::FromHandlePermanent(hParent);
						if (_pWnd&&_pWnd->IsKindOf(RUNTIME_CLASS(CPaneFrameWnd)))
						{
							pWnd = _pWnd;
							pWnd2 = (CFrameWnd*)::SendMessage(::GetParent(hParent), WM_TANGRAMMSG, 0, 19631965);
						}
						else
						{
							pWnd2 = (CFrameWnd*)AfxGetApp()->m_pMainWnd;
						}
					}
					if(pWnd2)
						AFXSetTopLevelFrame(pWnd2);
				}
				if(pWnd->IsKindOf(RUNTIME_CLASS(CPaneFrameWnd)))
				{
					CPaneFrameWnd* pPaneFrameWnd = (CPaneFrameWnd*)pWnd;
					if (pPaneFrameWnd->GetDockingManager() == nullptr)
					{
						CFrameWndEx* pWnd3 = (CFrameWndEx*)pWnd2;
						pPaneFrameWnd->SetDockingManager(pWnd3->GetDockingManager());
					}
				}
			}
		}
	}

	HWND ITangramAppProxy::GetActivePopupMenu(HWND hWnd)
	{
		CMFCPopupMenu* pActivePopupMenu = CMFCPopupMenu::GetSafeActivePopupMenu();
		if (pActivePopupMenu)
		{
			ATLTRACE(_T("pActivePopupMenu:%x\n"), pActivePopupMenu->m_hWnd);
			return pActivePopupMenu->m_hWnd;
		}
		return nullptr;
	}

	ITangramDoc* ITangramAppProxy::OpenDocument(void* pDocTemplate, CString strFile, BOOL bNewFrame)
	{
		CDocument* pDoc = nullptr;
		ITangramDoc* _pDoc = nullptr;
		if (pDocTemplate)
		{
			CDocTemplate* pTemplate = (CDocTemplate*)pDocTemplate;
			if (strFile != _T(""))
				m_pvoid = nullptr;
			pDoc = pTemplate->OpenDocumentFile(strFile);
			if (pDoc)
				g_pTangram->get_TangramDoc((LONGLONG)theAppImpl.m_pTangramAppProxy, (LONGLONG)pDoc, &_pDoc);
		}
		return _pDoc;
	}

	ITangramDoc* ITangramAppProxy::CreateNewDocument(LPCTSTR lpszFrameID, LPCTSTR lpszAppTitle, void* pDocTemplate, BOOL bNewFrame)
	{
		CWnd* pFrame = nullptr;
		CString strMainFrameID = lpszFrameID;
		auto it = m_mapMainFrame.find(strMainFrameID);
		if (it != m_mapMainFrame.end())
		{
			pFrame = (CWnd*)it->second;
		}
		else
		{
			m_bCreatingNewFrame = bNewFrame;
			m_strCreatingFrameTitle = lpszAppTitle;
			CreateNewFrame(strMainFrameID);
			it = m_mapMainFrame.find(strMainFrameID);
			if (it != m_mapMainFrame.end())
			{
				pFrame = (CWnd*)it->second;
			}
		}

		if (pFrame)
		{
			AfxGetApp()->m_pMainWnd = pFrame;
		}
		CDocument* pDoc = nullptr;
		ITangramDoc* _pDoc = nullptr;
		if (pDocTemplate)
		{
			CDocTemplate* pTemplate = (CDocTemplate*)pDocTemplate;
			if (bNewFrame == FALSE)
			{
				if (pDocTemplate)
				{
					pDoc = pTemplate->OpenDocumentFile(nullptr);
				}
			}
			else
			{
				CFrameWnd* pFrame = NULL;

				// Create a new instance of the document referenced
				// by the m_pDocTemplate member.
				pDoc = pTemplate->CreateNewDocument();

				if (pDoc != NULL)
				{
					// If creation worked, use create a new frame for
					// that document.
					pFrame = pTemplate->CreateNewFrame(pDoc, NULL);
					if (pFrame != NULL)
					{
						// Set the title, and initialize the document.
						// If document initialization fails, clean-up
						// the frame window and document.

						pTemplate->SetDefaultTitle(pDoc);
						if (!pDoc->OnNewDocument())
						{
							pFrame->DestroyWindow();
							pFrame = NULL;
						}
						else
						{
							// Otherwise, update the frame
							pTemplate->InitialUpdateFrame(pFrame, pDoc, TRUE);
						}
					}
				}

				// If we failed, clean up the document and show a
				// message to the user.

				if (pFrame == NULL || pDoc == NULL)
				{
					delete pDoc;
					AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
				}
			}
		}

		if (pDoc)
			g_pTangram->get_TangramDoc((LONGLONG)theAppImpl.m_pTangramAppProxy,(LONGLONG)pDoc, &_pDoc);

		return _pDoc;
	};

	void ITangramAppProxy::OnActiveDocument(ITangramDoc* ActiveDoc, IWndNode* pNodeInDoc, IWndNode* pNodeInCtrlBar, HWND hCtrlBar)
	{
	}

	void ITangramAppProxy::RemoveDoc(LONGLONG llDocID)
	{
		auto it = m_mapTangramDoc.find(llDocID);
		if (it != m_mapTangramDoc.end())
			m_mapTangramDoc.erase(it);
	}

	void ITangramAppProxy::AddDoc(LONGLONG llDocID, ITangramDoc* pDoc)
	{
		m_mapTangramDoc[llDocID] = pDoc;
	}

	ITangramDoc* ITangramAppProxy::GetDoc(LONGLONG llDocID)
	{
		auto it = m_mapTangramDoc.find(llDocID);
		if (it != m_mapTangramDoc.end())
			return it->second;
		return nullptr; 
	}

	ITangramDoc* ITangramAppProxy::NewDoc()
	{
		CDocument* pDoc = NULL;
		CDocTemplate* pTemplate = nullptr;
		POSITION nPos = AfxGetApp()->GetFirstDocTemplatePosition();
		while (nPos)
		{
			CString strExt = _T("");
			pTemplate = AfxGetApp()->GetNextDocTemplate(nPos);
			break;
		}
		if (pTemplate)
		{
			CFrameWnd* pFrame = NULL;
			pDoc = pTemplate->CreateNewDocument();

			if (pDoc != NULL)
			{
				// If creation worked, use create a new frame for
				// that document.
				pFrame = pTemplate->CreateNewFrame(pDoc, NULL);
				if (pFrame != NULL)
				{
					// Set the title, and initialize the document.
					// If document initialization fails, clean-up
					// the frame window and document.

					pTemplate->SetDefaultTitle(pDoc);
					if (!pDoc->OnNewDocument())
					{
						pFrame->DestroyWindow();
						pFrame = NULL;
					}
					else
					{
						// Otherwise, update the frame
						pTemplate->InitialUpdateFrame(pFrame, pDoc, TRUE);
					}
				}
			}

			// If we failed, clean up the document and show a
			// message to the user.

			if (pFrame == NULL || pDoc == NULL)
			{
				delete pDoc;
				AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
				pDoc = nullptr;
			}
		}
		ITangramDoc* _pDoc = nullptr;
		if (pDoc)
		{
			g_pTangram->get_TangramDoc((LONGLONG)theAppImpl.m_pTangramAppProxy, (LONGLONG)pDoc, &_pDoc);
			pDoc->SetModifiedFlag(false);
		}

		return _pDoc;
	}
}
