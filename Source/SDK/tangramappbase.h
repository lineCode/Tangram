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

#pragma once

#include <map>
#include "Tangram.h"
#include "metahost.h"
#include "TangramCommon.h"
#include "TangramXmlParse.h"
#include <atlenc.h>
#ifdef _WIN64
	#ifdef _DEBUG
		#ifdef _AFXDLL
			#pragma comment (lib, "libcpprest142_2_10_64_md_d.lib")
		#else
			#pragma comment (lib, "libcpprest142_2_10_64_d.lib")
		#endif
	#else
		#ifdef _AFXDLL
			#pragma comment (lib, "libcpprest142_2_10_64_md.lib")
		#else
			#pragma comment (lib, "libcpprest142_2_10_64.lib")
		#endif
	#endif
#else
	#ifdef _DEBUG
		#ifdef _AFXDLL
			#pragma comment (lib, "libcpprest142_2_10_md_d.lib")
		#else
			#pragma comment (lib, "libcpprest142_2_10_d.lib")
		#endif
	#else
		#ifdef _AFXDLL
			#pragma comment (lib, "libcpprest142_2_10_md.lib")
		#else
			#pragma comment (lib, "libcpprest142_2_10.lib")
		#endif
	#endif
#endif

//#ifdef _WIN64
//	#ifdef _DEBUG
//		#ifdef _AFXDLL
//			#pragma comment (lib, "libcpprest142D_2_10_64_md.lib")
//		#else
//			#pragma comment (lib, "libcpprest142_2_10_64_d.lib")
//		#endif
//	#else
//		#ifdef _AFXDLL
//			#pragma comment (lib, "libcpprest142_2_10_64_md.lib")
//		#else
//			#pragma comment (lib, "libcpprest142_2_10_64.lib")
//		#endif
//	#endif
//#else
//	#ifdef _DEBUG
//		#ifdef _AFXDLL
//			#pragma comment (lib, "libcpprest142D_2_10_md.lib")
//		#else
//			#pragma comment (lib, "libcpprest142D_2_10.lib")
//		#endif
//	#else
//		#ifdef _AFXDLL
//			#pragma comment (lib, "libcpprest142_2_10_md.lib")
//		#else
//			#pragma comment (lib, "libcpprest142_2_10.lib")
//		#endif
//	#endif
//#endif

using namespace std;

#include <ppl.h>
#include <ppltasks.h>
#include <codecvt>
#include <sstream>
#include <iostream>
#include <agents.h>
#include "cpprest/filestream.h"
#include <cpprest/http_client.h>
#include <cpprest/ws_client.h>
#include <cpprest/rawptrstream.h>
#include <cpprest/http_listener.h>
#include <cpprest/containerstream.h>
#include <cpprest/producerconsumerstream.h>

using namespace pplx;
using namespace utility;
using namespace web::http;
//using namespace web::experimental::web_sockets;
using namespace web::http::client;
using namespace concurrency;
using namespace concurrency::streams;
using namespace web::http::experimental::listener;

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

using namespace std;
using namespace ATL;

#pragma comment (lib, "wininet.lib")
#pragma comment (lib, "urlmon.lib")
#pragma comment (lib, "Winhttp.lib")
#pragma comment (lib, "httpapi.lib")
#pragma comment (lib, "bcrypt.lib")
#pragma comment (lib, "crypt32.lib")

#pragma comment(lib, "imagehlp.lib")

namespace TangramCommon
{
	class CTangramImpl;
	class CTangramAppProxy;
	class CTangramTabbedPane;
	class CTangramCLRProxyImpl;

	typedef struct tagMainFrameInfo
	{
		BOOL				m_bNewFrame;
		BOOL				m_bTabIcons;
		BOOL				m_bTabCloseButton;
		BOOL				m_bTabCustomTooltips;
		BOOL				m_bAutoColor;
		BOOL				m_bDocumentMenu;
		BOOL				m_bEnableTabSwap;
		BOOL				m_bFlatFrame;
		BOOL				m_bActiveTabCloseButton;
		BOOL				m_bReuseRemovedTabGroups;
		BOOL				m_bTabbedMDI;
		CString				m_strID;
		CString				m_strTitle;
		int					m_nResID;
		int					m_nTabMDIStyle;
		int					m_tabLocation;
		int					m_nTabBorderSize;
		void*				m_pTangramFrame;
		CTangramAppProxy*	m_pTangramAppProxy;
	}MainFrameInfo;

	class CTangramOleMessageFilter : public COleMessageFilter
	{
	public:
		CTangramOleMessageFilter()
		{
		}

		virtual ~CTangramOleMessageFilter()
		{
		}

		// Overridables
		virtual BOOL OnMessagePending(const MSG* pMsg);
	};

	class CTangramWPFObj
	{
	public:
		CTangramWPFObj()
		{
			m_pDisp = nullptr;
			m_hwndWPF = nullptr;
		};
		~CTangramWPFObj() {};
		HWND m_hwndWPF;
		IDispatch* m_pDisp;
		map<CString, IDispatch*> m_mapWPFObj;
		virtual BOOL IsVisible() { return false; };
		virtual void InvalidateVisual() {};
		virtual void ShowVisual(BOOL bShow) {};
		virtual void Focusable(BOOL bFocus) {};
	};

	class CTangramPackageProxy
	{
	public:
		CTangramPackageProxy()
		{
			m_hTangramToolWnd = nullptr;
			m_hVSGridView = nullptr;
			m_pCompositor = nullptr;
			m_pProxy = nullptr;
			m_pToolBoxFrame = nullptr;
			m_pClassViewFrame = nullptr;
			m_pPropertyFrame = nullptr;

			m_strOrgs = _T("");
			m_strRepo = _T("");
			m_strBranch = _T("");
			m_strToolBoxXML = _T("");
			m_strClassViewXML = _T("");
			m_strPropertiesXML = _T("");
			m_strTangramToolWndXML = _T("");
			m_strCurrentXtmlFilePath = _T("");
		};

		HWND								m_hTangramToolWnd;
		HWND								m_hVSGridView;
		HWND								m_hPropertyWnd;
		HWND								m_hPropertyPWnd;

		CString								m_strOrgs;
		CString								m_strRepo;
		CString								m_strBranch;
		CString								m_strToolBoxXML;
		CString								m_strClassViewXML;
		CString								m_strPropertiesXML;
		CString								m_strTangramToolWndXML;
		CString								m_strCurrentXtmlFilePath;

		ICompositor*						m_pCompositor;
		CTangramImpl*						m_pProxy;
		map<HWND, ICompositor*>				m_mapWinFormCompositor;

		ICompositor* m_pToolBoxFrame;
		ICompositor* m_pClassViewFrame;
		ICompositor* m_pPropertyFrame;

		virtual HWND CreateTangramToolWnd() { return nullptr; };
		virtual HWND CreateTangramHelpToolWnd(CString strXml) { return nullptr; };
		virtual void OnSelectedObjectsChanged(IDispatch* pObj, CString strType, LPARAM hObjWnd, int nType) {};
		virtual void ShowTangramToolWnd(BOOL bShowMainToolWnd, int nShow) {};
		virtual void TangramAction(CString strXml) {};
	};

	class CTangramImpl : public CTangramBase
	{
	public:
		CTangramImpl()
		{
			m_bExportComponent = false;
			m_hMainWnd = nullptr;
			m_hSmallIcon = nullptr;
			m_hLargeIcon = nullptr;
			m_pCurMDIChildFormInfo = nullptr;
			m_hHostWnd = nullptr;
			m_hFormNodeWnd = nullptr;
			m_hTangramWnd = nullptr;
			m_pCLRProxy = nullptr;
			m_hChildHostWnd = nullptr;
			m_pTangramPackageProxy = nullptr;
			m_strNtpXml = _T("");
			m_strNtpDataXml = _T("");
			m_strAppCurrentFormTemplatePath = _T("");
		};

		HWND						m_hVSToolBoxWnd;

		CMDIChildFormInfo* m_pCurMDIChildFormInfo;
		CTangramAppProxy* m_pActiveAppProxy;
		CTangramAppProxy* m_pTangramAppProxy;
		CTangramAppProxy* m_pTangramCLRAppProxy;
		CTangramPackageProxy* m_pTangramPackageProxy;
		CTangramCLRProxyImpl* m_pCLRProxy;
		ITaskbarList3* m_pTaskbarList3;

		map<CString, CTangramAppProxy*>			m_mapTangramAppProxy;

		virtual ITangramDoc* ConnectTangramDoc(CTangramAppProxy* AppProxy, LONGLONG docID, HWND hView, HWND hFrame, LPCTSTR strDocType) { return nullptr; };
	};

	class CTangramCLRProxyImpl
	{
	public:
		CTangramCLRProxyImpl()
		{
			m_pProxy = NULL;
			m_strObjTypeName = _T("");
		};

		CString				m_strObjTypeName;
		CString				m_strCurrentWinFormTemplate;

		CTangramImpl* m_pProxy;
		virtual BSTR AttachObjEvent(IDispatch* EventObj, IDispatch* SourceObj, WindowEventType EventType, IDispatch* HTMLWindow) = 0;
		virtual HRESULT ActiveCLRMethod(BSTR bstrObjID, BSTR bstrMethod, BSTR bstrParam, BSTR bstrData) = 0;
		virtual HRESULT ActiveCLRMethod(IDispatch* obj, BSTR bstrMethod, BSTR bstrParam, BSTR bstrData) = 0;
		virtual IDispatch* CreateCLRObj(CString bstrObjID) = 0;
		virtual HRESULT ProcessCtrlMsg(HWND hCtrl, bool bShiftKey) = 0;
		virtual BOOL ProcessFormMsg(HWND hFormWnd, LPMSG lpMsg, int nMouseButton) = 0;
		virtual IDispatch* TangramCreateObject(BSTR bstrObjID, HWND hParent, IWndNode* pHostNode) = 0;
		virtual int IsWinForm(HWND hWnd) = 0;
		virtual int IsSpecifiedType(IUnknown* pUnknown, BSTR bstrName) = 0;
		virtual IDispatch* GetCLRControl(IDispatch* CtrlDisp, BSTR bstrNames) = 0;
		virtual BSTR GetCtrlName(IDispatch* pCtrl) = 0;
		virtual IDispatch* GetCtrlFromHandle(HWND hWnd) = 0;
		virtual HWND GetMDIClientHandle(IDispatch* pMDICtrl) = 0;
		virtual IDispatch* GetCtrlByName(IDispatch* CtrlDisp, BSTR bstrName, bool bFindInChild) = 0;
		virtual HWND GetCtrlHandle(IDispatch* pCtrl) = 0;
		virtual BSTR GetCtrlType(IDispatch* pCtrl) { return L""; };
		virtual HWND IsCtrlCanNavigate(IDispatch* ctrl) = 0;
		virtual void TangramAction(BSTR bstrXml, IWndNode* pNode) = 0;
		virtual BSTR GetCtrlValueByName(IDispatch* CtrlDisp, BSTR bstrName, bool bFindInChild) = 0;
		virtual void SetCtrlValueByName(IDispatch* CtrlDisp, BSTR bstrName, bool bFindInChild, BSTR strVal) = 0;
		virtual void SelectNode(IWndNode*) { };
		virtual void SelectObj(IDispatch*) { };
		virtual void ReleaseTangramObj(IDispatch*) { };
		virtual void AttachVSPropertyWnd(HWND) { };
		virtual void AttachCLRObjEvent(IDispatch* Sender, WindowEventType nType, HWND hNotifyWnd, VARIANT_BOOL bAttachEvent) { };
		virtual void WindowCreated(LPCTSTR strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd) {};
		virtual void WindowDestroy(HWND hWnd) {};
		virtual CTangramWPFObj* CreateWPFControl(IWndNode* pNode, HWND hPWnd, UINT nID) { return nullptr; };
		virtual HRESULT NavigateURL(IWndNode* pNode, CString strURL, IDispatch* dispObjforScript) { return S_FALSE; };
		virtual void OnCLRHostExit() {};
		virtual void OnDestroyChromeBrowser(IChromeWebBrowser*) {};
		virtual void ExportAllFormsInfo() {};
		virtual void SetObjectProperty(IDispatch* pObj, BSTR bstrPropertyName, BSTR bstrPropertyValue) {};
		virtual void* Extend(CString strKey, CString strData, CString strFeatures) { return nullptr; };
		virtual bool IsSupportDesigner() { return false; };
		virtual HICON GetAppIcon(int nIndex) = 0;
		virtual bool BindObjectToWindow(IDispatch* pDisp, HWND hWnd, CString strXml) = 0;
		virtual bool BindObjectToWindow(CString objID, CString AssemblyQualifiedName, HWND hWnd, CString strXml) = 0;
	};

	class CTangramMFCTabCtrl : public CMFCTabCtrl
	{
		DECLARE_DYNCREATE(CTangramMFCTabCtrl)

		// Construction
	public:
		CTangramMFCTabCtrl();
		// Implementation
	public:
		virtual ~CTangramMFCTabCtrl();

	protected:
		void FireChangeActiveTab(int nNewTab);
		BOOL FireChangingActiveTab(int nNewTab);
		DECLARE_MESSAGE_MAP()
	};

	class CTangramMFCToolBar : public CMFCToolBar
	{
		DECLARE_SERIAL(CTangramMFCToolBar);
	public:
		CTangramMFCToolBar();
		virtual ~CTangramMFCToolBar();
	};

	class CTangramDockablePane : public CDockablePane
	{
		DECLARE_SERIAL(CTangramDockablePane);
	public:
		CTangramDockablePane();
		virtual ~CTangramDockablePane();
	protected:
		afx_msg LRESULT OnShowCtrlBar(WPARAM, LPARAM);
		DECLARE_MESSAGE_MAP()
		CTabbedPane* CreateTabbedPane();
		void ToggleAutoHide();
		BOOL CreateEx(DWORD dwStyleEx, LPCTSTR lpszCaption, CWnd* pParentWnd, const RECT& rect, BOOL bHasGripper,
			UINT nID, DWORD dwStyle, DWORD dwTabbedStyle, DWORD dwControlBarStyle, CCreateContext* pContext);
	};

	class CTangramTabbedPane : public CTabbedPane
	{
		DECLARE_SERIAL(CTangramTabbedPane);
	public:
		CTangramTabbedPane();
		virtual ~CTangramTabbedPane();
	protected:
		DECLARE_MESSAGE_MAP()
		CTabbedPane* CreateTabbedPane();
		void ToggleAutoHide();
		BOOL CreateEx(DWORD dwStyleEx, LPCTSTR lpszCaption, CWnd* pParentWnd, const RECT& rect, BOOL bHasGripper,
			UINT nID, DWORD dwStyle, DWORD dwTabbedStyle, DWORD dwControlBarStyle, CCreateContext* pContext);
	};

	class CTangramFrameWnd : public CFrameWndEx
	{
	public:
		CTangramFrameWnd();
		virtual ~CTangramFrameWnd();

		DECLARE_DYNCREATE(CTangramFrameWnd)

		int m_nFrameIndex;
		HWND m_hClient;
		HWND  m_hwndLastTopLevelFrame;
		CString	m_strRegKey;
		CDocument* m_pDoc;

		static CTangramFrameWnd* m_pActiveTangramFrameWnd;
		virtual BOOL OnShowPopupMenu(CMFCPopupMenu* /*pMenuPopup*/);
		virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle = WS_OVERLAPPEDWINDOW, const RECT& rect = rectDefault, CWnd* pParentWnd = NULL, LPCTSTR lpszMenuName = NULL, DWORD dwExStyle = 0, CCreateContext* pContext = NULL);
		virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	protected:
		afx_msg LRESULT OnSetAppTitle(WPARAM wp, LPARAM lp);
		afx_msg LRESULT OnQueryAppProxy(WPARAM wp, LPARAM lp);
		afx_msg void OnClose();
		afx_msg void OnSetFocus(CWnd* pOldWnd);
		afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
		afx_msg void OnDestroy();
		afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
		afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
		DECLARE_MESSAGE_MAP()
	};

	class CTangramMainFrameWnd : public CFrameWndEx
	{
	public:
		CTangramFrameWnd* m_pHostFrame;
		CTangramMainFrameWnd();
		virtual ~CTangramMainFrameWnd();
	protected:
		virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
		DECLARE_MESSAGE_MAP()
		afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	};

	class CTangramMainWnd : public CWnd
	{
	public:
		CTangramMainWnd();
		virtual ~CTangramMainWnd();
	protected:
		virtual void PostNcDestroy();
		DECLARE_MESSAGE_MAP()
	};

	class CTangramAppProxy
	{
	public:
		CTangramAppProxy();
		virtual ~CTangramAppProxy() 
		{
			m_pTangramImpl = nullptr;
		};

		BOOL								m_bAutoDelete;
		HWND								m_hMainWnd;
		HWND								m_hCreatingView;
		HINSTANCE							m_hInstance;
		LPCTSTR								m_strProxyName;
		LPCTSTR								m_strProxyID;
		LPCTSTR								m_strCreatingFrameTitle;
		LPCTSTR								m_strClosingFrameID;
		void*								m_pvoid;
		CTangramDocProxy*					m_pCurDocProxy;
		CTangramImpl*						m_pTangramImpl;

		BOOL								m_bCreatingNewFrame;
		int									m_nFrameIndex;
		HWND								m_hClosingFrame;
		CString								m_strAppKey;
		map<CString, void*>					m_mapMainFrame;
		map<LONGLONG, ITangramDoc*>			m_mapTangramDoc;
		map<void*, LONG>					m_mapTangramDocTemplateID;
		CTangramMainWnd*					m_pTangramWnd;
		BOOL InitTangram(void* pVoid);
		void RegistWndRunTimeClass(void* clsInfo);

		virtual void OnActiveMainFrame(HWND);
		virtual int OnDestroyMainFrame(CString strID, int nMainFrameCount, int nWndType);
		virtual LRESULT OnForegroundIdleProc();
		virtual BOOL TangramPreTranslateMessage(MSG* pMsg);
		virtual void OnTangramClose() {};
		virtual void OnOpenComplete(HWND hWnd, CString bstrUrl, IWndNode* pRootNode) {};
		virtual void OnTangramEvent(ITangramEventObj* NotifyObj) {};
		virtual void RegistWndClassToTangram() {};
		virtual void OnActiveDocument(ITangramDoc* ActiveDoc, IWndNode* pNodeInDoc, IWndNode* pNodeInCtrlBar, HWND hCtrlBar);
		virtual HWND CreateWindowObj(LPCTSTR strClsName, IWndNode* pNode, HWND hParent);
		virtual HWND CreateNewFrame(CString strFrameKey);
		virtual HWND GetActivePopupMenu(HWND hwnd);
		virtual HRESULT CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv) { return S_FALSE; };
		virtual ITangramDoc* CreateNewDocument(LPCTSTR lpszFrameID, LPCTSTR lpszAppTitle, void* pDocTemplate, BOOL bNewFrame);
		virtual ITangramDoc* OpenDocument(void* pDocTemplate, CString strFile, BOOL bNewFrame);
		virtual CTangramWndNodeProxy* OnTangramNodeInit(IWndNode* pNewNode) { return nullptr; };
		virtual CCompositorProxy* OnCompositorCreated(ICompositor* pNewFrame) { return nullptr; };
		virtual CCompositorManagerProxy* OnCompositorManagerCreated(ICompositorManager* pNewCompositorManager) { return nullptr; };
		virtual void MouseMoveProxy(HWND hWnd);
		virtual void AddDoc(LONGLONG llDocID, ITangramDoc* pDoc);
		virtual void RemoveDoc(LONGLONG llDocID);
		virtual ITangramDoc* GetDoc(LONGLONG llDocID);
		virtual ITangramDoc* NewDoc();
		virtual HWND InitTangramApp() { return NULL; };

	private:
		map<CString, void*>					m_mapRuntimeClass;
	};

	#define TGM_NAME				_T("name")
	#define TGM_CAPTION				_T("caption")
	#define TGM_NODE_TYPE			_T("id")
	#define TGM_CNN_ID				_T("cnnid")
	#define TGM_HEIGHT				_T("height")
	#define TGM_WIDTH				_T("width")
	#define TGM_STYLE				_T("style")
	#define TGM_ACTIVE_PAGE			_T("activepage")
	#define TGM_TAG					_T("tag")
	#define TGM_NODE				_T("node")

	#define TGM_ROWS				_T("rows")
	#define TGM_COLS				_T("cols")


	#define TGM_SPLITTER			_T("splitter")
	#define TGM_TABBED				_T("tab")

	#define TGM_SETTING_HEAD		_T("#$^&TANGRAM")
	#define TGM_SETTING_FOMRAT		_T("#$^&TANGRAM[%ld][%ld]")

	#define TGM_S_EXCEL_INPUT		1

	class CTangramDocHelper : public CTangramDocProxy
	{
	public:
		CTangramDocHelper();
		virtual ~CTangramDocHelper();
		CDocument*	m_pDocument;

		CMapStringToString m_mapDataMap;

		virtual void SaveDoc()
		{
			if (m_pDocument)
			{
				m_pDocument->DoFileSave();
			}
		};
		virtual void TangramDocEvent(ITangramEventObj* pEventObj) {};
		virtual void TangramSerialize(CDocument* _pDoc, CArchive* pAr);
	};

	class CTangramViewHelper
	{
	public:
		CTangramViewHelper();
		virtual ~CTangramViewHelper();

		CString m_strDocID;
		ITangramDoc* m_pDoc;

		BOOL CreateView(CCreateContext* pContext, HWND hView, HWND hParent);
	};

	extern ITangram* g_pTangram;
	extern 	CChromeBrowserCreatorImpl* g_pCreatorImpl;
};

using namespace TangramCommon;