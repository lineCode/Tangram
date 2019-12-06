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

#include "TangramAppDelegate.h"
#include "TangramXmlParse.cpp"
#include "TangramCommon.cpp"
#include "Tangram.c"

#ifdef _AFXDLL
extern CFrameWnd* g_pTopLevelFrame = nullptr;
#endif

typedef ITangram* (__stdcall* GetTangram)();
typedef CTangramImpl* (__stdcall* GetTangramImpl)(ITangram**);

typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
typedef bool(__stdcall* _IsBrowserModel)(bool bSupportCrashReporting, void*);
_InitApp FuncInitApp;
_IsBrowserModel FuncIsBrowserModel;

CWinApp* g_pAppBase = nullptr;
CTangramWinApp* g_pApp = nullptr;
CTangramWinAppEx* g_pAppEx = nullptr;
ITangramAppProxy* g_pAppProxy = nullptr;
ITangram* g_pTangram = nullptr;

namespace TangramCommon
{
	CTangramBrowserFactory* g_pBrowserFactory = nullptr;

	class CTangramHelperWnd : public CWnd
	{
	public:
		CTangramHelperWnd() {}
		virtual ~CTangramHelperWnd() {}
		void PostNcDestroy()
		{
			CWnd::PostNcDestroy();
			delete this;
		}
		BEGIN_MSG_MAP(CTangramHelperWnd)
		END_MSG_MAP()
	};

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

		m_nFrameIndex = 0;
		m_strAppKey = _T("");
	}

	BOOL ITangramAppProxy::InitTangram(void* pVoid)
	{
		return TRUE;
	}

	HWND ITangramAppProxy::CreateNewFrame(CString strFrameKey)
	{
		return nullptr;
	};

	void ITangramAppProxy::OnActiveMainFrame(HWND hWnd)
	{
	}

	BOOL ITangramAppProxy::TangramSaveAllModified()
	{
		return TRUE;
	}

	int ITangramAppProxy::OnDestroyMainFrame(CString strID, int nMainFrameCount, int nWndType)
	{
		return -1;
	}

	LRESULT ITangramAppProxy::OnForegroundIdleProc()
	{
		return 0;
	}

	BOOL ITangramAppProxy::TangramPreTranslateMessage(MSG* pMsg)
	{
		return TRUE;
	}

	void ITangramAppProxy::MouseMoveProxy(HWND hWnd)
	{
	}

	HWND ITangramAppProxy::GetActivePopupMenu(HWND hWnd)
	{
		return nullptr;
	}

	ITangramDoc* ITangramAppProxy::OpenDocument(void* pDocTemplate, CString strFile, BOOL bNewFrame)
	{
		return nullptr;
	}

	ITangramDoc* ITangramAppProxy::CreateNewDocument(LPCTSTR lpszFrameID, LPCTSTR lpszAppTitle, void* pDocTemplate, BOOL bNewFrame)
	{
		return nullptr;
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
		if (CTangramFrameWndEx::m_pActiveTangramFrameWnd)
			AFXSetTopLevelFrame(CTangramFrameWndEx::m_pActiveTangramFrameWnd);
		return CMFCTabCtrl::FireChangingActiveTab(nNewTab);
	}

	void CTangramMFCTabCtrl::FireChangeActiveTab(int nNewTab)
	{
		if (CTangramFrameWndEx::m_pActiveTangramFrameWnd)
			AFXSetTopLevelFrame(CTangramFrameWndEx::m_pActiveTangramFrameWnd);
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


	// CTangramMultiDocTemplate construction/destruction

	CTangramMultiDocTemplate::CTangramMultiDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)
		: CMultiDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
	{
		g_pAppProxy->m_mapTangramDocTemplateID[this] = nIDResource;
		g_pAppProxy->m_pTangramImpl->m_nAppType = 1992;
	}

	// CTangramMDTDocTemplate construction/destruction

	CTangramMDTDocTemplate::CTangramMDTDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)
		: CMultiDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
	{
		g_pAppProxy->m_mapTangramDocTemplateID[this] = nIDResource;
		g_pAppProxy->m_pTangramImpl->m_nAppType = 1963;
	}

	// CTangramDocTemplate construction/destruction

	CTangramDocTemplate::CTangramDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)
		: CSingleDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
	{
		g_pAppProxy->m_mapTangramDocTemplateID[this] = nIDResource;
		g_pAppProxy->m_pTangramImpl->m_nAppType = 1965;
	}

	IMPLEMENT_DYNAMIC(CTangramDocTemplate, CSingleDocTemplate)
	IMPLEMENT_DYNAMIC(CTangramMDTDocTemplate, CMultiDocTemplate)
	IMPLEMENT_DYNAMIC(CTangramMultiDocTemplate, CMultiDocTemplate)

	CTangramAppDelegate::CTangramAppDelegate()
	{
		m_strProviderID = _T("");
		g_pAppProxy = this;
	}

	CTangramAppDelegate::~CTangramAppDelegate()
	{
		if (m_pTangramImpl)
		{
			m_pTangramImpl->InsertTangramDataMap(0, m_strProviderID, nullptr);
			m_pTangramImpl->InsertTangramDataMap(1, m_strProviderID, nullptr);
		}
	}

	BOOL CTangramAppDelegate::OnAppIdle(BOOL& bIdle, LONG lCount)
	{
		_AFX_THREAD_STATE* pState = AfxGetThreadState();
		while (bIdle &&
			!::PeekMessage(&(pState->m_msgCur), NULL, NULL, NULL, PM_NOREMOVE)) {
			if (!AfxGetApp()->OnIdle(lCount++))
				bIdle = FALSE;  // assume "no idle" state
		}
		return true;
	}

	void CTangramAppDelegate::ForegroundIdleProc()
	{
		// send WM_IDLEUPDATECMDUI to the main window
		CWnd* pMainWnd = AfxGetApp()->m_pMainWnd;
		if (pMainWnd != NULL && pMainWnd->m_hWnd != NULL &&
			pMainWnd->IsWindowVisible())
		{
			AfxCallWndProc(pMainWnd, pMainWnd->m_hWnd, WM_IDLEUPDATECMDUI, (WPARAM)TRUE, 0);
			pMainWnd->SendMessageToDescendants(WM_IDLEUPDATECMDUI,
				(WPARAM)TRUE, 0, TRUE, TRUE);
		}
	}

	bool CTangramAppDelegate::OnTangramPreTranslateMessage(MSG* pMsg)
	{
		if (pMsg->message == WM_CHAR || pMsg->hwnd == nullptr)
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
			//if (::GetAncestor(hwnd, GA_ROOTOWNER) == ::GetAncestor(pApp->m_pMainWnd->m_hWnd, GA_ROOTOWNER))
			//	AFXSetTopLevelFrame((CFrameWnd*)pApp->m_pMainWnd);
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

	HWND CTangramAppDelegate::GetMainWnd()
	{
		if (AfxGetApp()->m_pMainWnd)
			return AfxGetApp()->m_pMainWnd->m_hWnd;
		return nullptr;
	}
	
	void CTangramAppDelegate::BeginBrowserSession()
	{

	}
	
	void CTangramAppDelegate::EndBrowserSession()
	{

	}

	bool CTangramAppDelegate::HookAppDocTemplateInfo()
	{
		CString m_strDocTemplateScript = _T("<template>");
		if (m_pTangramImpl->m_strDefaultTemplate == _T(""))
		{
			BOOL bCanHaveDocTemplateScript = true;
			POSITION nPos = g_pAppBase->GetFirstDocTemplatePosition();
			while (nPos)
			{
				CDocTemplate* pTemplate = g_pAppBase->GetNextDocTemplate(nPos);
				CString strExt = _T("");
				pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
				strExt.MakeLower();
				if (strExt == _T(""))
					strExt = _T("tangramdefault");
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
						CString s = _T("");
						s.Format(_T("<tangram%I64d%s ResID=\"%d\">%s|%s|*%s|%s|</tangram%I64d%s>"), (__int64)pTemplate, strExt, it->second, strFileTypeID, strfilterName, strExt, g_pAppBase->m_pszExeName, (__int64)pTemplate, strExt);
						m_strDocTemplateScript += s;
					}
				}
				else
				{
					bCanHaveDocTemplateScript = false;
					break;
				}
			}
			if (bCanHaveDocTemplateScript)
			{
				m_strDocTemplateScript += _T("</template>");
				m_pTangramImpl->m_strDefaultTemplate = m_strDocTemplateScript;
			}
			else
				m_strDocTemplateScript = _T("");
		}
		return (m_strDocTemplateScript == _T("")) ? false : true;
	}

	bool CTangramAppDelegate::BrowserAppStart()
	{
		bool bRet = false;
		return bRet;
	}

	BOOL CTangramAppDelegate::IsAppIdleMessage()
	{
		_AFX_THREAD_STATE* pState = AfxGetThreadState();
		if (AfxGetApp()->IsIdleMessage(&(pState->m_msgCur))) {
			return true;
		}
		return false;
	}

	void CTangramAppDelegate::ProcessMsg(MSG* msg)
	{
		if (msg->message != WM_KICKIDLE && !AfxPreTranslateMessage(msg)) {
			if (msg->hwnd == 0 && msg->message == WM_TANGRAMMSG)
			{
				//switch (msg->lParam)
				//{
				////case 20190422:
				////{
				////}
				////break;
				//default:
				//	break;
				//}
			}
			::TranslateMessage(msg);
			::DispatchMessage(msg);
		}
	}

	HWND CTangramAppDelegate::QueryCanClose(HWND hWnd)
	{
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		if (pWnd && pWnd == g_pAppBase->m_pMainWnd)
		{
			POSITION nPos = g_pAppBase->GetFirstDocTemplatePosition();
			while (nPos)
			{
				CDocTemplate* pTemplate = g_pAppBase->GetNextDocTemplate(nPos);
				POSITION pos = pTemplate->GetFirstDocPosition();
				while (pos != NULL)
				{
					CDocument* pDoc = pTemplate->GetNextDoc(pos);
					POSITION pos2 = pDoc->GetFirstViewPosition();
					while (pos2 != NULL)
					{
						CView* pView = pDoc->GetNextView(pos2);
						ASSERT_VALID(pView);
						CFrameWnd* pFrame = pView->GetParentFrame();
						if (g_pAppBase->m_pMainWnd != pFrame)
						{
							g_pAppBase->m_pMainWnd = pFrame;
							m_pTangramImpl->m_hMainWnd = g_pAppBase->m_pMainWnd->m_hWnd;
							return pFrame->m_hWnd;
						}
					}
				}
			}
		}
		return NULL;
	};

	CString CTangramAppDelegate::GetNTPXml()
	{
		CString s = _T("<tangram>")
			_T("<window>")
			_T("<node id = 'splitter' name = 'container' rows = '1' cols = '2' height = '100,100,' width = '300,500,' borderwidth = '0' splitterwidth = '4' middlecolor = 'RGB(240,240,240)'>")
			_T("<node name = 'launcher' id = 'ClrCtrl' cnnid = 'hostapp.hostctrl,hostapp' caption = '' borderwidth = '0' />")
			_T("<node name = 'host' caption = 'host' id = 'hostview' borderwidth = '0' />")
			_T("</node>")
			_T("</window>")
			_T("</tangram>");
		return s;
	}

	bool CTangramAppDelegate::TangramInit(CString strID)
	{
		if (!afxContextIsDLL&&IsBrowserModel(false))
			return false;
		TCHAR m_szBuffer[MAX_PATH];
		HMODULE hModule = ::GetModuleHandle(_T("TangramCore.dll"));
		if (hModule == nullptr)
		{
			TCHAR szDriver[MAX_PATH] = { 0 };
			TCHAR szDir[MAX_PATH] = { 0 };
			TCHAR szExt[MAX_PATH] = { 0 };
			TCHAR szFile2[MAX_PATH] = { 0 };
			::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
			_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
			CString strTangramDll = szDriver;
			strTangramDll += szDir;
			strTangramDll += _T("tangramcore.dll");
			hModule = ::LoadLibrary(strTangramDll);
		}
		if (hModule == nullptr && SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer) == S_OK)
		{
			CString m_strProgramFilePath = CString(m_szBuffer);
			m_strProgramFilePath += _T("\\Tangram\\Tangramcore.dll");
			if (::PathFileExists(m_strProgramFilePath)) {
				hModule = ::LoadLibrary(m_strProgramFilePath);
			}
		}

		if(hModule)
		{
			if (m_strTangramContainer != _T(""))
			{
				m_strTangramContainer = _T(",") + m_strTangramContainer + _T(",");
				m_strTangramContainer.Replace(_T(",,"), _T(","));
			}
			GetTangramImpl _pTangramImplFunction;
			_pTangramImplFunction = (GetTangramImpl)GetProcAddress(hModule, "GetTangramImpl");
			g_pTangramImpl = m_pTangramImpl = _pTangramImplFunction(&m_pTangram);
			g_pTangram = m_pTangram;

			if (!afxContextIsDLL)
			{
				m_strProviderID = AfxGetApp()->m_pszAppName;
				m_strProviderID += _T(".host");
				m_strProviderID.MakeLower();
				
				m_pTangramImpl->m_pTangramDelegate = static_cast<ITangramDelegate*>(this);
				g_pTangramImpl->InsertTangramDataMap(0, m_strProviderID, static_cast<ITangramAppProxy*>(this));
				g_pTangramImpl->InsertTangramDataMap(1, m_strProviderID, static_cast<ITangramWindowProvider*>(this));

				if (m_pTangramImpl->m_strNtpXml == _T(""))
				{
					m_pTangramImpl->m_strNtpXml = GetNTPXml();
				}
				if (m_pTangramImpl->m_strNtpDataXml == _T(""))
				{
					m_pTangramImpl->m_strNtpDataXml = GetNTPData();
				}
				if(g_pTangramImpl->m_nAppType!=TANGRAM_APP_BROWSER&&
					g_pTangramImpl->m_nAppType != TANGRAM_APP_BROWSER_ECLIPSE)
				::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT, (WPARAM)m_pTangramImpl->m_pTangramDelegate, g_pTangramImpl->m_nAppType);
				m_pTangramImpl->m_pTangramAppProxy = this;
			}
			else 
			{
				strID.Trim();
				if (strID == _T(""))
					strID = _T("component");
				if (m_strProviderID == _T(""))
				{
					CString strName = AfxGetApp()->m_pszAppName;
					m_strProviderID = strName + _T(".") + strID;
				}
				if (m_strProviderID != _T(""))
				{
					m_strProviderID.MakeLower();
					g_pTangramImpl->InsertTangramDataMap(0, m_strProviderID, static_cast<ITangramAppProxy*>(this));
					g_pTangramImpl->InsertTangramDataMap(1, m_strProviderID, static_cast<ITangramWindowProvider*>(this));
				}
			}
		}
		return true;
	}

	bool CTangramAppDelegate::ProcessAppType(bool bCrashReporting)
	{
		if (m_pTangramImpl)
		{
			switch (m_pTangramImpl->m_nAppType)
			{
			case TANGRAM_APP_WIN32:
				return true;
				break;
			case TANGRAM_APP_BROWSER:
			case TANGRAM_APP_BROWSER_ECLIPSE:
			{
				if (m_pTangramImpl->m_nAppType == TANGRAM_APP_BROWSER_ECLIPSE)
				{
#ifdef _AFXDLL
#ifdef _DEBUG
					::MessageBox(NULL,_T("Chrome-Eclipse Model is not support MFC Share Dll"),_T("Warnning"),MB_OK);
#endif 
					TRACE(_T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support MFC Share Dll********\r\n\r\n"));
#endif
				}
				m_pTangramImpl->m_hMainWnd = NULL;
				HMODULE hModule = ::GetModuleHandle(L"tangram_chrome_rt.dll");
				if (hModule == nullptr)
					hModule = ::LoadLibrary(L"tangram_chrome_rt.dll");
				if (hModule) {
					typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
					_InitApp _pInitAppFunction;
					_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
					if (_pInitAppFunction != NULL) {
						BeginBrowserSession();
						_pInitAppFunction(bCrashReporting, m_pTangramImpl->m_pTangramDelegate);
						EndBrowserSession();
						return false;
					}
				}
			}
			break;
			case TANGRAM_APP_ECLIPSE:
				if (m_pTangram && !m_pTangramImpl->m_bIsEclipseInit)
				{
					m_pTangram->InitEclipseApp();
					return false;
				}
				break;
			}
		}
		return true;
	}

	bool CTangramAppDelegate::DoIdleWork()
	{
		if (m_pTangramImpl->m_hMainWnd && ::IsWindow(m_pTangramImpl->m_hMainWnd) == false)
			m_pTangramImpl->m_hMainWnd = NULL;
		return false;
	}

	BOOL CTangramAppDelegate::IsBrowserModel(bool bCrashReporting)
	{
		HMODULE hModule = ::GetModuleHandle(L"tangram_chrome_rt.dll");
		if (hModule == nullptr)
			hModule = ::LoadLibrary(L"tangram_chrome_rt.dll");
		if (hModule) {
			m_bCrashReporting = bCrashReporting;
			FuncIsBrowserModel = (_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
			if (FuncIsBrowserModel != NULL) {
				return FuncIsBrowserModel(bCrashReporting, this);
			}
		}

		return false;
	};

	bool CTangramAppDelegate::EclipseAppInit()
	{
		return false;
	}
	
	void CTangramAppDelegate::TangramIPCMsg(HWND hWnd, CString strType, CString strParam1, CString strParam2)
	{

	}
	
	void CTangramAppDelegate::TangramRenderHTMLElement(HWND hWnd, CString strRuleName, CString strHTML)
	{

	}

	void CTangramAppDelegate::OnOpenComplete(HWND hCompositorWnd, CString strUrl, IWndNode* pRootNode)
	{
	}

	void CTangramAppDelegate::OnTangramEvent(ITangramEventObj* NotifyObj)
	{
	}

	CTangramWndNodeProxy* CTangramAppDelegate::OnTangramNodeInit(IWndNode* pNewNode)
	{
		CComBSTR bstrName("");
		pNewNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pNewNode->get_NameAtWindowPage(&bstrName2);
		return nullptr;
	}

	CCompositorProxy* CTangramAppDelegate::OnCompositorCreated(ICompositor* pNewFrame)
	{
		__int64 h = 0;
		pNewFrame->get_HWND(&h);
		CComBSTR bstrName("");
		pNewFrame->get_Name(&bstrName);
		return nullptr;
	}

	CCompositorManagerProxy* CTangramAppDelegate::OnCompositorManagerCreated(ICompositorManager* pNewCompositorManager)
	{
		CCompositorManagerProxy* pTangramCompositorManagerProxy = nullptr;
		__int64 h = 0;
		pNewCompositorManager->get_Handle(&h);
		if (h)
		{
			CWnd* pWnd = CWnd::FromHandlePermanent((HWND)h);
			if (pWnd == NULL)
				return NULL;
			if (pWnd->IsKindOf(RUNTIME_CLASS(CTangramMDIFrameWndEx)))
			{
				pTangramCompositorManagerProxy = (CCompositorManagerProxy*)(CTangramMDIFrameWndEx*)pWnd;
			}
			else if (pWnd->IsKindOf(RUNTIME_CLASS(CTangramMDIChildWndEx)))
			{
				pTangramCompositorManagerProxy = (CCompositorManagerProxy*)(CTangramMDIChildWndEx*)pWnd;
			}
			else if (pWnd->IsKindOf(RUNTIME_CLASS(CTangramMDIChildWnd)))
			{
				pTangramCompositorManagerProxy = (CCompositorManagerProxy*)(CTangramMDIChildWnd*)pWnd;
			}
			else if (pWnd->IsKindOf(RUNTIME_CLASS(CTangramMDIFrameWnd)))
			{
				pTangramCompositorManagerProxy = (CCompositorManagerProxy*)(CTangramMDIFrameWnd*)pWnd;
			}
			else if (pWnd->IsKindOf(RUNTIME_CLASS(CTangramFrameWndEx)))
			{
				pTangramCompositorManagerProxy = (CCompositorManagerProxy*)(CTangramFrameWndEx*)pWnd;
			}
			else if (pWnd->IsKindOf(RUNTIME_CLASS(CTangramFrameWnd)))
			{
				pTangramCompositorManagerProxy = (CCompositorManagerProxy*)(CTangramFrameWnd*)pWnd;
			}
			if (pTangramCompositorManagerProxy)
				pTangramCompositorManagerProxy->m_bAutoDelete = false;
		}
		return pTangramCompositorManagerProxy;
	}

	ITangramDoc* CTangramAppDelegate::OpenDocument(void* pDocTemplate, CString strFile, BOOL bNewFrame)
	{
		CDocTemplate* pTemplate = (CDocTemplate*)pDocTemplate;
		if (pTemplate == nullptr)
			return nullptr;
		if (::PathFileExists(strFile))
		{
			pTemplate->OpenDocumentFile(strFile);
		}
		else
		{
			pTemplate->OpenDocumentFile(nullptr);
		}
		return nullptr;
	}

	//ITangramWindowProvider:
	CString CTangramAppDelegate::GetNames()
	{
		if (m_mapInnerObjInfo.size())
		{
			CString strNames = _T("");
			for (auto it = m_mapInnerObjInfo.begin(); it != m_mapInnerObjInfo.end(); it++)
			{
				strNames += it->first;
				strNames += _T(",");
			}
			return strNames.MakeLower();
		}
		return _T("");
	}

	CString CTangramAppDelegate::GetTags(CString strName)
	{
		strName.Trim().MakeLower();
		if (strName != _T(""))
		{
			auto it = m_mapInnerObjStyle.find(strName);
			if (it != m_mapInnerObjStyle.end())
			{
				return it->second;
			}
		}
		return _T("");
	}

	CTangramComponentApp::CTangramComponentApp()
	{
		g_pAppBase = this;
	}

	CTangramComponentApp::~CTangramComponentApp()
	{
	}

	bool CTangramComponentApp::TangramInit(CString strID)
	{
		HMODULE hModule = ::GetModuleHandle(_T("TangramCore.dll"));;
		if (hModule)
		{
			if (m_strTangramContainer != _T(""))
			{
				m_strTangramContainer = _T(",") + m_strTangramContainer + _T(",");
				m_strTangramContainer.Replace(_T(",,"), _T(","));
			}
			GetTangramImpl _pTangramImplFunction;
			_pTangramImplFunction = (GetTangramImpl)GetProcAddress(hModule, "GetTangramImpl");
			g_pTangramImpl = _pTangramImplFunction(&m_pTangram);
			g_pTangram = m_pTangram;
			if (g_pTangramImpl->m_nAppType == TANGRAM_APP_BROWSER_ECLIPSE)
			{
#ifdef _AFXDLL
#ifdef _DEBUG
				::MessageBox(NULL, _T("Chrome-Eclipse Model is not support MFC Share Dll"), _T("Warnning"), MB_OK);
#endif 
				TRACE(_T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support MFC Share Dll********\r\n\r\n"));
#endif
			}
			strID.Trim();
			if (strID == _T(""))
				strID = _T("ui");
			if (m_strProviderID == _T(""))
			{
				CString strName = g_pAppBase->m_pszAppName;
				m_strProviderID = strName + _T(".") + strID;
			}
			if (m_strProviderID != _T(""))
			{
				m_strProviderID.MakeLower();
				g_pTangramImpl->InsertTangramDataMap(1, m_strProviderID, this);
				//g_pTangramImpl->m_pTangramImplData->m_mapTangramWindowProvider[m_strProviderID] = this;
			}
		}
		return true;
	}

	CString CTangramComponentApp::GetNames()
	{
		if (m_mapInnerObjInfo.size())
		{
			CString strNames = _T("");
			for (auto it = m_mapInnerObjInfo.begin(); it != m_mapInnerObjInfo.end(); it++)
			{
				strNames += it->first;
				strNames += _T(",");
			}
			return strNames.MakeLower();
		}
		return _T("");
	}

	CString CTangramComponentApp::GetTags(CString strName)
	{
		strName.Trim().MakeLower();
		if (strName != _T(""))
		{
			auto it = m_mapInnerObjStyle.find(strName);
			if (it != m_mapInnerObjStyle.end())
			{
				return it->second;
			}
		}
		return _T("");
	}

	int CTangramComponentApp::ExitInstance()
	{
		CMFCVisualManager* pVisualManager = CMFCVisualManager::GetInstance();
		if (pVisualManager != NULL)
		{
			delete pVisualManager;
		}
		return CWinApp::ExitInstance();
	}

	HWND CTangramComponentApp::Create(HWND hParentWnd, IWndNode* pNode)
	{
		CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
		if (pParent == nullptr)
		{
			pParent = new CTangramHelperWnd();
			if (!pParent->SubclassWindow(hParentWnd))
			{
				TRACE(_T("\n**********************Error**********************\n"));
				return NULL;
			}
		}
		BSTR bstrTag = L"";
		pNode->get_Attribute(L"id", &bstrTag);
		USES_CONVERSION;
		CString m_strTag = OLE2T(bstrTag);
		::SysFreeString(bstrTag);
		m_strTag.Trim().MakeLower();
		if (m_strTag != _T(""))
		{
			auto it = m_mapInnerObjInfo.find(m_strTag);
			if (it != m_mapInnerObjInfo.end())
			{
				CRuntimeClass* pCls = (CRuntimeClass*)it->second;
				CWnd* pWnd = (CWnd*)pCls->CreateObject();
				if (pWnd)
				{
					if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView)))
					{
						AfxSetResourceHandle(CWinApp::m_hInstance);
					}
					pNode->get_Attribute(L"style", &bstrTag);
					CString strStyle = OLE2T(bstrTag);
					strStyle.Trim();
					if (strStyle == _T(""))
					{
						::SysFreeString(bstrTag);
						pNode->get_Attribute(L"tabstyle", &bstrTag);
						strStyle = OLE2T(bstrTag);
						::SysFreeString(bstrTag);
						strStyle.Trim();
					}
					if (pWnd->Create(nullptr, strStyle, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), pParent, 0, nullptr))
					{
						::PostMessage(pWnd->m_hWnd, WM_TANGRAMMSG, (WPARAM)pNode, 20191031);
						pNode->get_Attribute(L"activepage", &bstrTag);
						CString m_strTag = OLE2T(bstrTag);
						::SysFreeString(bstrTag);
						int nActivePage = _wtoi(m_strTag);
						::PostMessage(pWnd->m_hWnd, WM_TABCHANGE, nActivePage, 0);
						return pWnd->m_hWnd;
					}
				}
			}
		}
		return NULL;
	}

	CTangramWinApp::CTangramWinApp()
	{
		g_pAppBase = g_pApp = this;
	}

	CTangramWinApp::~CTangramWinApp()
	{
	}

	BOOL CTangramWinApp::InitApplication()
	{
		return TangramInit(_T("")) ? CWinApp::InitApplication() : false;
	}

	BOOL CTangramWinApp::InitInstance()
	{
		InitTangramInstance();
		CWinApp::InitInstance();
		if (ProcessAppType(m_bCrashReporting) == false)
			return false;
		return true;
	}

	HWND CTangramWinApp::Create(HWND hParentWnd, IWndNode* pNode)
	{
		CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
		if (pParent == nullptr)
		{
			pParent = new CTangramHelperWnd();
			if (!pParent->SubclassWindow(hParentWnd))
			{
				TRACE(_T("\n**********************Error**********************\n"));
				return NULL;
			}
		}
		BSTR bstrTag = L"";
		pNode->get_Attribute(L"id", &bstrTag);
		USES_CONVERSION;
		CString m_strTag = OLE2T(bstrTag);
		::SysFreeString(bstrTag);
		m_strTag.Trim().MakeLower();
		if (m_strTag != _T(""))
		{
			auto it = m_mapInnerObjInfo.find(m_strTag);
			if (it != m_mapInnerObjInfo.end())
			{
				CRuntimeClass* pCls = (CRuntimeClass*)it->second;
				CWnd* pWnd = (CWnd*)pCls->CreateObject();
				if (pWnd)
				{
					if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView)))
					{
						AfxSetResourceHandle(CWinApp::m_hInstance);
					}
					pNode->get_Attribute(L"style", &bstrTag);
					CString strStyle = OLE2T(bstrTag);
					strStyle.Trim();
					if (strStyle == _T(""))
					{
						::SysFreeString(bstrTag);
						pNode->get_Attribute(L"tabstyle", &bstrTag);
						strStyle = OLE2T(bstrTag);
						::SysFreeString(bstrTag);
						strStyle.Trim();
					}

					if (pWnd->Create(nullptr, strStyle, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), pParent, 0, nullptr))
					{
						::PostMessage(pWnd->m_hWnd, WM_TANGRAMMSG, (WPARAM)pNode, 20191031);
						pNode->get_Attribute(L"activepage", &bstrTag);
						CString m_strTag = OLE2T(bstrTag);
						::SysFreeString(bstrTag);
						int nActivePage = _wtoi(m_strTag);
						::PostMessage(pWnd->m_hWnd, WM_TABCHANGE, nActivePage, 0);
						return pWnd->m_hWnd;
					}
				}
			}
		}
		return NULL;
	}

	void CTangramWinApp::OnFileNew()
	{
		CWinApp::OnFileNew();
	}

	CTangramWinAppEx::CTangramWinAppEx()
	{
		g_pAppBase = g_pAppEx = this;
	}

	CTangramWinAppEx::~CTangramWinAppEx()
	{
	}

	BOOL CTangramWinAppEx::InitApplication()
	{
		return TangramInit(_T("")) ? CWinAppEx::InitApplication() : false;
	}

	HWND CTangramWinAppEx::Create(HWND hParentWnd, IWndNode* pNode)
	{
		CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
		if (pParent == nullptr)
		{
			pParent = new CTangramHelperWnd();
			if (!pParent->SubclassWindow(hParentWnd))
			{
				TRACE(_T("\n**********************Error**********************\n"));
				return NULL;
			}
		}
		BSTR bstrTag = L"";
		pNode->get_Attribute(L"id", &bstrTag);
		USES_CONVERSION;
		CString m_strTag = OLE2T(bstrTag);
		::SysFreeString(bstrTag);
		m_strTag.Trim().MakeLower();
		if (m_strTag != _T(""))
		{
			auto it = m_mapInnerObjInfo.find(m_strTag);
			if (it != m_mapInnerObjInfo.end())
			{
				CRuntimeClass* pCls = (CRuntimeClass*)it->second;
				CWnd* pWnd = (CWnd*)pCls->CreateObject();
				if (pWnd)
				{
					if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView)))
					{
						AfxSetResourceHandle(CWinApp::m_hInstance);
					}
					if (pWnd->Create(nullptr, _T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), pParent, 0, nullptr))
					{
						::PostMessage(pWnd->m_hWnd, WM_TANGRAMMSG, (WPARAM)pNode, 20191031);
						pNode->get_Attribute(L"activepage", &bstrTag);
						CString m_strTag = OLE2T(bstrTag);
						::SysFreeString(bstrTag);
						int nActivePage = _wtoi(m_strTag);
						::PostMessage(pWnd->m_hWnd, WM_TABCHANGE, nActivePage, 0);
						return pWnd->m_hWnd;
					}
				}
			}
		}
		return NULL;
	}

	void CTangramWinAppEx::OnFileNew()
	{
		CWinAppEx::OnFileNew();
	}

	BOOL CTangramWinAppEx::InitInstance()
	{
		InitTangramInstance();
		CWinAppEx::InitInstance();
		if (ProcessAppType(m_bCrashReporting) == false)
			return false;
		return true;
	}

	bool CTangramWinAppEx::GetClientAreaBounds(HWND hWnd, RECT& rc) {
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CTangramMDIFrameWndEx)))
		{
			CTangramMDIFrameWndEx* pMDIFrameWndEx = static_cast<CTangramMDIFrameWndEx*>(pWnd);
			rc = pMDIFrameWndEx->GetClientAreaBounds();
		}
		return false;
	}

	IMPLEMENT_DYNCREATE(CTangramFrameWnd, CFrameWnd)

	BEGIN_MESSAGE_MAP(CTangramFrameWnd, CFrameWnd)
		ON_WM_CLOSE()
	END_MESSAGE_MAP()

	CTangramFrameWnd::CTangramFrameWnd()
	{
	}

	CTangramFrameWnd::~CTangramFrameWnd()
	{
	}

	BOOL CTangramFrameWnd::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
	{
		if (!CFrameWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
		{
			return FALSE;
		}
		return TRUE;
	}

	BOOL CTangramFrameWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, LPCTSTR lpszMenuName, DWORD dwExStyle, CCreateContext* pContext)
	{
		BOOL bCreate = CFrameWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, lpszMenuName, dwExStyle, pContext);
		return bCreate;
	}

	void CTangramFrameWnd::OnClose()
	{
		g_pApp->QueryCanClose(m_hWnd);
		CFrameWnd::OnClose();
	}

	BOOL CTangramFrameWnd::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		//if (m_hClient == nullptr)
		//{
		//	AFXSetTopLevelFrame(this);
		//}
		//return CFrameWndEx::OnCommand(wParam, lParam);
		HWND hWndCtrl = (HWND)lParam;
		UINT nID = LOWORD(wParam);
		//AFXSetTopLevelFrame(this);
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

	void CTangramFrameWnd::OnTabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
	{
		__int64 h = 0;
		sender->get_Handle(&h);
		IWndNode* pActiveNode = nullptr;
		sender->GetNode(0, ActivePage, &pActiveNode);
		CComBSTR bstrName("");
		pActiveNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pActiveNode->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramFrameWnd::OnClrControlCreated(IWndNode* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle)
	{
		CComBSTR bstrName("");
		Node->get_Name(&bstrName);
		CComBSTR bstrName2("");
		Node->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramFrameWnd::OnEvent(IDispatch* sender, IDispatch* EventArg)
	{
	}

	void CTangramFrameWnd::OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName)
	{
	}

	void CTangramFrameWnd::OnTangramEvent(ITangramEventObj* NotifyObj)
	{
	}

	IMPLEMENT_DYNCREATE(CTangramFrameWndEx, CFrameWndEx)

	BEGIN_MESSAGE_MAP(CTangramFrameWndEx, CFrameWndEx)
		ON_WM_CLOSE()
	END_MESSAGE_MAP()

	CTangramFrameWndEx* CTangramFrameWndEx::m_pActiveTangramFrameWnd = nullptr;

	CTangramFrameWndEx::CTangramFrameWndEx()
	{
	}

	CTangramFrameWndEx::~CTangramFrameWndEx()
	{
	}

	BOOL CTangramFrameWndEx::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
	{
		if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
		{
			return FALSE;
		}
		return TRUE;
	}

	BOOL CTangramFrameWndEx::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, LPCTSTR lpszMenuName, DWORD dwExStyle, CCreateContext* pContext)
	{
		BOOL bCreate = CFrameWndEx::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, lpszMenuName, dwExStyle, pContext);
		return bCreate;
	}

	void CTangramFrameWndEx::OnClose()
	{
		g_pAppEx->QueryCanClose(m_hWnd);
		CFrameWndEx::OnClose();
	}

	BOOL CTangramFrameWndEx::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		//if (m_hClient == nullptr)
		//{
		//	AFXSetTopLevelFrame(this);
		//}
		//return CFrameWndEx::OnCommand(wParam, lParam);
		HWND hWndCtrl = (HWND)lParam;
		UINT nID = LOWORD(wParam);
		//AFXSetTopLevelFrame(this);
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

	BOOL CTangramFrameWndEx::OnShowPopupMenu(CMFCPopupMenu* pMenuPopup)
	{
		if (pMenuPopup == nullptr || ::IsWindow(pMenuPopup->m_hWnd) == false)
			return false;
		return CFrameWndEx::OnShowPopupMenu(pMenuPopup);
	}

	void CTangramFrameWndEx::OnTabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
	{
		__int64 h = 0;
		sender->get_Handle(&h);
		IWndNode* pActiveNode = nullptr;
		sender->GetNode(0, ActivePage, &pActiveNode);
		CComBSTR bstrName("");
		pActiveNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pActiveNode->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramFrameWndEx::OnClrControlCreated(IWndNode* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle)
	{
		CComBSTR bstrName("");
		Node->get_Name(&bstrName);
		CComBSTR bstrName2("");
		Node->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramFrameWndEx::OnEvent(IDispatch* sender, IDispatch* EventArg)
	{
	}

	void CTangramFrameWndEx::OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName)
	{
	}

	void CTangramFrameWndEx::OnTangramEvent(ITangramEventObj* NotifyObj)
	{
	}

	IMPLEMENT_DYNCREATE(CTangramMDIFrameWnd, CMDIFrameWnd)

	BEGIN_MESSAGE_MAP(CTangramMDIFrameWnd, CMDIFrameWnd)
		ON_MESSAGE(WM_QUERYAPPPROXY, OnQueryAppProxy)
	END_MESSAGE_MAP()


	CTangramMDIFrameWnd::CTangramMDIFrameWnd()
	{
	}

	CTangramMDIFrameWnd::~CTangramMDIFrameWnd()
	{
	}

	BOOL CTangramMDIFrameWnd::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
	{
		if (!CMDIFrameWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
		{
			return FALSE;
		}
		return TRUE;
	}

	BOOL CTangramMDIFrameWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, LPCTSTR lpszMenuName, DWORD dwExStyle, CCreateContext* pContext)
	{
		BOOL bCreate = CMDIFrameWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, lpszMenuName, dwExStyle, pContext);
		return bCreate;
	}

	BOOL CTangramMDIFrameWnd::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		//if (m_hClient == nullptr)
		//{
		//	AFXSetTopLevelFrame(this);
		//}
		HWND hWndCtrl = (HWND)lParam;
		UINT nID = LOWORD(wParam);
		//AFXSetTopLevelFrame(this);
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
		return CMDIFrameWnd::OnCommand(wParam, lParam);
	}

	LRESULT CTangramMDIFrameWnd::OnQueryAppProxy(WPARAM wp, LPARAM lp)
	{
		if (lp)
		{
			switch (lp)
			{
			case 1:
				break;
			case 19651965:
				RecalcLayout();
				break;
			case 19631965:
				return (LRESULT)this;
				break;
			case 19631992:
				AfxGetApp()->m_pMainWnd = this;
				break;
			case 19650601:
			{
				CWnd* pWnd = CWnd::FromHandlePermanent((HWND)wp);
				if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CDockablePane)))
				{
					CDockablePane* pDockablePane = (CDockablePane*)pWnd;
					pDockablePane->RecalcLayout();
				}
			};
			break;
			case TANGRAM_CONST_NEWDOC://for new doc
			{
				((CTangramWinApp*)AfxGetApp())->OnFileNew();
			};
			break;
			case TANGRAM_CONST_PANE_FIRST://for mdiclient
			{
				return 1992;
			};
			break;
			case TANGRAM_CONST_OPENFILE://open doc
			{
				if (wp)
				{
					AfxGetApp()->OpenDocumentFile((LPCTSTR)wp);
				}
			};
			break;
			}
		}
		return  0;
	}

	void CTangramMDIFrameWnd::OnTabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
	{
		__int64 h = 0;
		sender->get_Handle(&h);
		IWndNode* pActiveNode = nullptr;
		sender->GetNode(0, ActivePage, &pActiveNode);
		CComBSTR bstrName("");
		pActiveNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pActiveNode->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIFrameWnd::OnClrControlCreated(IWndNode* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle)
	{
		CComBSTR bstrName("");
		Node->get_Name(&bstrName);
		CComBSTR bstrName2("");
		Node->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIFrameWnd::OnEvent(IDispatch* sender, IDispatch* EventArg)
	{
	}

	void CTangramMDIFrameWnd::OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName)
	{
	}

	void CTangramMDIFrameWnd::OnTangramEvent(ITangramEventObj* NotifyObj)
	{
	}

	IMPLEMENT_DYNCREATE(CTangramMDIFrameWndEx, CMDIFrameWndEx)

	BEGIN_MESSAGE_MAP(CTangramMDIFrameWndEx, CMDIFrameWndEx)
		ON_MESSAGE(WM_QUERYAPPPROXY, OnQueryAppProxy)
	END_MESSAGE_MAP()


	CTangramMDIFrameWndEx::CTangramMDIFrameWndEx()
	{
	}

	CTangramMDIFrameWndEx::~CTangramMDIFrameWndEx()
	{
	}

	BOOL CTangramMDIFrameWndEx::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
	{
		if (!CMDIFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
		{
			return FALSE;
		}
		return TRUE;
	}

	BOOL CTangramMDIFrameWndEx::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, LPCTSTR lpszMenuName, DWORD dwExStyle, CCreateContext* pContext)
	{
		BOOL bCreate = CMDIFrameWndEx::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, lpszMenuName, dwExStyle, pContext);
		return bCreate;
	}

	BOOL CTangramMDIFrameWndEx::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		//if (m_hClient == nullptr)
		//{
		//	AFXSetTopLevelFrame(this);
		//}
		//return CFrameWndEx::OnCommand(wParam, lParam);
		HWND hWndCtrl = (HWND)lParam;
		UINT nID = LOWORD(wParam);
		//AFXSetTopLevelFrame(this);
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
		return CMDIFrameWndEx::OnCommand(wParam, lParam);
	}

	CRect CTangramMDIFrameWndEx::GetClientAreaBounds()
	{
		return m_dockManager.GetClientAreaBounds();
	}

	void CTangramMDIFrameWndEx::AdjustClientArea()
	{
		CRect rc = m_dockManager.GetClientAreaBounds();
		::SendMessage(m_hWndMDIClient, WM_QUERYAPPPROXY, (WPARAM)(LPRECT)rc, 19651965);
		m_wndClientArea.CalcWindowRectForMDITabbedGroups(rc, 0);
	}

	LRESULT CTangramMDIFrameWndEx::OnQueryAppProxy(WPARAM wp, LPARAM lp)
	{
		if (lp)
		{
			switch (lp)
			{
			case 1:
				break;
			case 19651965:
				RecalcLayout();
				break;
			case 19631965:
				return (LRESULT)this;
				break;
			case 19631992:
				AfxGetApp()->m_pMainWnd = this;
				break;
			case 19650601:
			{
				CWnd* pWnd = CWnd::FromHandlePermanent((HWND)wp);
				if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CDockablePane)))
				{
					CDockablePane* pDockablePane = (CDockablePane*)pWnd;
					pDockablePane->RecalcLayout();
				}
			};
			break;
			case TANGRAM_CONST_NEWDOC://for new doc
			{
				((CTangramWinAppEx*)AfxGetApp())->OnFileNew();
			};
			break;
			case TANGRAM_CONST_PANE_FIRST://for mdiclient
			{
				return 1992;
			};
			break;
			case TANGRAM_CONST_OPENFILE://open doc
			{
				if (wp)
				{
					AfxGetApp()->OpenDocumentFile((LPCTSTR)wp);
				}
			};
			break;
			case 19921989:
				if (wp)
				{
					LPRECT lpRC = (LPRECT)wp;
					*lpRC = m_dockManager.GetClientAreaBounds();
					return lp;
				}
				break;
			}
		}
		return 0;// (LRESULT)(ITangramAppProxy*)&theApp;
	}

	void CTangramMDIFrameWndEx::OnTabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
	{
		__int64 h = 0;
		sender->get_Handle(&h);
		IWndNode* pActiveNode = nullptr;
		sender->GetNode(0, ActivePage, &pActiveNode);
		CComBSTR bstrName("");
		pActiveNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pActiveNode->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIFrameWndEx::OnClrControlCreated(IWndNode* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle)
	{
		CComBSTR bstrName("");
		Node->get_Name(&bstrName);
		CComBSTR bstrName2("");
		Node->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIFrameWndEx::OnEvent(IDispatch* sender, IDispatch* EventArg)
	{
	}

	void CTangramMDIFrameWndEx::OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName)
	{
	}

	void CTangramMDIFrameWndEx::OnTangramEvent(ITangramEventObj* NotifyObj)
	{
	}

	BOOL CTangramMDIFrameWndEx::OnShowPopupMenu(CMFCPopupMenu* pMenuPopup)
	{
		if (pMenuPopup == nullptr || ::IsWindow(pMenuPopup->m_hWnd) == false)
			return false;
		return CMDIFrameWndEx::OnShowPopupMenu(pMenuPopup);
	}

	// CTangramXDoc

	IMPLEMENT_DYNCREATE(CTangramXDoc, CDocument)

	BEGIN_MESSAGE_MAP(CTangramXDoc, CDocument)
	END_MESSAGE_MAP()


	// CTangramXDoc construction/destruction

	CTangramXDoc::CTangramXDoc()
	{
		m_bDocLoaded = false;
		m_strXmlData = _T("");
		m_pTangramTemplate = nullptr;
	}

	CTangramXDoc::~CTangramXDoc()
	{
	}

	BOOL CTangramXDoc::OnNewDocument()
	{
		if (!CDocument::OnNewDocument())
			return FALSE;
		m_strXmlData = _T("");
		m_mapDataMap.RemoveAll();
		m_bDocLoaded = true;
		return TRUE;
	}

	// CTangramXDoc serialization

	void CTangramXDoc::Serialize(CArchive& ar)
	{
		ITangram* pTangram = nullptr;
		CView* pView = nullptr;
		CFrameWnd* pFrame = nullptr;
		POSITION posView = GetFirstViewPosition();
		while (posView != NULL)
		{
			pView = GetNextView(posView);
			pFrame = pView->GetParentFrame();
			if (pFrame)
			{
				ICompositor* _pCompositor = nullptr;
				if (pFrame->GetRuntimeClass()->IsDerivedFrom(RUNTIME_CLASS(CFrameWndEx)))
				{
					pTangram = ((CTangramWinAppEx*)AfxGetApp())->m_pTangram;
				}
				else
				{
					pTangram = ((CTangramWinApp*)AfxGetApp())->m_pTangram;
				}
				break;
			}
		}
		if (ar.IsStoring())
		{
			if (pFrame)
			{
				ICompositor* _pCompositor = nullptr;
				pTangram->GetCompositor((__int64)pView->m_hWnd, &_pCompositor);
				if (_pCompositor != nullptr)
				{
					ICompositorManager* pCompositorManager = nullptr;
					_pCompositor->get_CompositorManager(&pCompositorManager);
					CComBSTR bstrXml(L"");
					pCompositorManager->get_CompositorManagerXML(&bstrXml);
					m_strXmlData = OLE2T(bstrXml);
				}
			}
			ar << m_strXmlData;
			m_mapDataMap.Serialize(ar);
		}
		else
		{
			m_strXmlData = _T("");
			m_mapDataMap.RemoveAll();
			ar >> m_strXmlData;
			m_mapDataMap.Serialize(ar);
			pTangram->put_AppKeyValue(CComBSTR(L"currentdocdata"), CComVariant(m_strXmlData));
			m_bDocLoaded = true;
		}
	}

	// CTangramMDIChildWnd
	IMPLEMENT_DYNCREATE(CTangramMDIChildWnd, CMDIChildWnd)

	BEGIN_MESSAGE_MAP(CTangramMDIChildWnd, CMDIChildWnd)
		ON_MESSAGE(WM_TANGRAMMSG, OnTangramMsg)
	END_MESSAGE_MAP()

	// CTangramMDIChildWnd construction/destruction

	CTangramMDIChildWnd::CTangramMDIChildWnd()
	{
		m_pDoc = nullptr;
		m_bAutoDelete = false;
	}

	CTangramMDIChildWnd::~CTangramMDIChildWnd()
	{
	}

	// CTangramMDIChildWnd message handlers

	void CTangramMDIChildWnd::OnTabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
	{
		__int64 h = 0;
		sender->get_Handle(&h);
		IWndNode* pActiveNode = nullptr;
		sender->GetNode(0, ActivePage, &pActiveNode);
		CComBSTR bstrName("");
		pActiveNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pActiveNode->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIChildWnd::OnClrControlCreated(IWndNode* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle)
	{
		CComBSTR bstrName("");
		Node->get_Name(&bstrName);
		CComBSTR bstrName2("");
		Node->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIChildWnd::OnEvent(IDispatch* sender, IDispatch* EventArg)
	{
	}

	void CTangramMDIChildWnd::OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName)
	{
	}

	void CTangramMDIChildWnd::OnTangramEvent(ITangramEventObj* NotifyObj)
	{
	}

	BOOL CTangramMDIChildWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CMDIFrameWnd* pParentWnd, CCreateContext* pContext)
	{
		if (pContext)
			m_pDoc = static_cast<CTangramXDoc*>(pContext->m_pCurrentDoc);
		return __super::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, pContext);
	}

	LRESULT CTangramMDIChildWnd::OnTangramMsg(WPARAM wp, LPARAM lp)
	{
		switch (lp)
		{
		case TANGRAM_CONST_OPENFILE:
		{
			ITangramDocTemplate* pDisp = (ITangramDocTemplate*)wp;
			if (m_pDoc)
			{
				((CTangramXDoc*)m_pDoc)->m_pTangramTemplate = pDisp;
			}
		}
		break;
		case TANGRAM_CONST_PANE_FIRST:
		{
			if (m_pDoc == nullptr)
			{
				CCreateContext* pContext = (CCreateContext*)wp;
				m_pDoc = static_cast<CTangramXDoc*>(pContext->m_pCurrentDoc);
				CDocTemplate* pTemplate = pContext->m_pNewDocTemplate;
				CString m_strDocID = _T("");
				pTemplate->GetDocString(m_strDocID, CDocTemplate::regFileTypeId);
			}
			return 1992;
		}
		break;
		}
		return __super::DefWindowProc(WM_TANGRAMMSG, wp, lp);
	}

	// CTangramMDIChildWndEx
	IMPLEMENT_DYNCREATE(CTangramMDIChildWndEx, CMDIChildWndEx)

	BEGIN_MESSAGE_MAP(CTangramMDIChildWndEx, CMDIChildWndEx)
		ON_MESSAGE(WM_TANGRAMMSG, OnTangramMsg)
	END_MESSAGE_MAP()

	// CTangramMDIChildWndEx construction/destruction

	CTangramMDIChildWndEx::CTangramMDIChildWndEx()
	{
		m_pDoc = nullptr;
		m_bAutoDelete = false;
	}

	CTangramMDIChildWndEx::~CTangramMDIChildWndEx()
	{
	}

	// CTangramMDIChildWndEx message handlers

	void CTangramMDIChildWndEx::OnTabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
	{
		__int64 h = 0;
		sender->get_Handle(&h);
		IWndNode* pActiveNode = nullptr;
		sender->GetNode(0, ActivePage, &pActiveNode);
		CComBSTR bstrName("");
		pActiveNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pActiveNode->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIChildWndEx::OnClrControlCreated(IWndNode* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle)
	{
		CComBSTR bstrName("");
		Node->get_Name(&bstrName);
		CComBSTR bstrName2("");
		Node->get_NameAtWindowPage(&bstrName2);
	}

	void CTangramMDIChildWndEx::OnEvent(IDispatch* sender, IDispatch* EventArg)
	{
	}

	void CTangramMDIChildWndEx::OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName)
	{
	}

	void CTangramMDIChildWndEx::OnTangramEvent(ITangramEventObj* NotifyObj)
	{
	}

	BOOL CTangramMDIChildWndEx::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CMDIFrameWnd* pParentWnd, CCreateContext* pContext)
	{
		if (pContext)
			m_pDoc = static_cast<CTangramXDoc*>(pContext->m_pCurrentDoc);
		return __super::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, pContext);
	}

	LRESULT CTangramMDIChildWndEx::OnTangramMsg(WPARAM wp, LPARAM lp)
	{
		switch (lp)
		{
		case TANGRAM_CONST_OPENFILE:
		{
			ITangramDocTemplate* pDisp = (ITangramDocTemplate*)wp;
			if (m_pDoc)
			{
				((CTangramXDoc*)m_pDoc)->m_pTangramTemplate = pDisp;
			}
		}
		break;
		case TANGRAM_CONST_PANE_FIRST:
		{
			if (m_pDoc == nullptr)
			{
				CCreateContext* pContext = (CCreateContext*)wp;
				m_pDoc = static_cast<CTangramXDoc*>(pContext->m_pCurrentDoc);
				CDocTemplate* pTemplate = pContext->m_pNewDocTemplate;
				CString m_strDocID = _T("");
				pTemplate->GetDocString(m_strDocID, CDocTemplate::regFileTypeId);
			}
			return 1992;
		}
		break;
		}
		return __super::DefWindowProc(WM_TANGRAMMSG, wp, lp);
	}
}
