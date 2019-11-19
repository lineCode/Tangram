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
#include <ppl.h>
#include <ppltasks.h>
#include <agents.h>
#include <shlobj.h>
#include <atlctl.h>

using namespace concurrency;
using namespace std;
using namespace ATL;

#pragma comment(lib, "imagehlp.lib")

namespace TangramCommon
{
	class CTangramAppProxy;
	class CTangramImpl;
	class CTangramWPFObj;

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

	class CTangramWindow : public CWindowImpl<CTangramWindow, CWindow>
	{
	public:
		CTangramWindow();
		virtual ~CTangramWindow();

		BEGIN_MSG_MAP(CTangramWindow)
			MESSAGE_HANDLER(WM_CREATE, OnCreate)
			MESSAGE_HANDLER(WM_CLOSE, OnClose)
			MESSAGE_HANDLER(WM_COMMAND, OnCommand)
			MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
			MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanging)
		END_MSG_MAP()
		CTangramWindow* m_pChild;
		void OnFinalMessage(HWND hWnd);
		LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
		LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
		LRESULT OnCommand(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
		LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
		LRESULT OnWindowPosChanging(UINT, WPARAM, LPARAM, BOOL&);
	};

	class CTangramApplicationImpl
	{
	public:
		CTangramApplicationImpl();
		virtual ~CTangramApplicationImpl();

		virtual void OnTangramCtrlCreated(ITangramCtrl* pITangramCtrl) {};

		bool				m_bUsingDefaultUI;
		CTangramAppProxy*	m_pTangramAppProxy;

		HRESULT InitTangram(BOOL bUsingDefaultUI, CTangramAppProxy* pProxy);
	};

	class CTangramPackageProxy
	{
	public:
		CTangramPackageProxy()
		{
			m_hTangramToolWnd = nullptr;
			m_hVSGridView = nullptr;
			m_pFrame = nullptr;
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

		ICompositor*						m_pFrame;
		CTangramImpl*						m_pProxy;
		map<HWND, ICompositor*>				m_mapWinFormFrame;

		ICompositor*						m_pToolBoxFrame;
		ICompositor*						m_pClassViewFrame;
		ICompositor*						m_pPropertyFrame;

		virtual HWND CreateTangramToolWnd() { return nullptr; };
		virtual HWND CreateTangramHelpToolWnd(CString strXml) { return nullptr; };
		virtual void OnSelectedObjectsChanged(IDispatch* pObj, CString strType, LPARAM hObjWnd, int nType) {};
		virtual void ShowTangramToolWnd(BOOL bShowMainToolWnd, int nShow) {};
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

		CTangramImpl*	m_pProxy;
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
		virtual BSTR GetCtrlType(IDispatch* pCtrl) = 0;
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
		virtual void* Extend(CString strKey, CString strData, CString strFeatures) = 0;
		virtual bool IsSupportDesigner() { return false; };
		virtual HICON GetAppIcon(int nIndex) = 0;
		virtual bool BindObjectToWindow(IDispatch* pDisp, HWND hWnd, CString strXml) = 0;
		virtual bool BindObjectToWindow(CString objID, CString AssemblyQualifiedName, HWND hWnd, CString strXml) = 0;
	};

	class CTangramImpl : public TangramCommon::CTangramBase
	{
	public:
		CTangramImpl()
		{
			m_bExportComponent = false;
			m_hHostWnd = nullptr;
			m_hFormNodeWnd = nullptr;
			m_hMainWnd = nullptr;
			m_hTangramWnd = nullptr;
			m_pCLRProxy = nullptr;
			m_hChildHostWnd = nullptr;
			m_pTangramPackageProxy = nullptr;
			m_pJVM = nullptr;
			m_pJVMenv = nullptr;
			systemClass = nullptr;
			exitMethod = nullptr;
			loadMethod = nullptr;
			m_strAppCurrentFormTemplatePath = _T("");
		};

		HWND						m_hVSToolBoxWnd;

		CMDIChildFormInfo*			m_pCurMDIChildFormInfo;
		CTangramAppProxy*			m_pActiveAppProxy;
		CTangramAppProxy*			m_pTangramAppProxy;
		CTangramAppProxy*			m_pTangramCLRAppProxy;
		CTangramPackageProxy*		m_pTangramPackageProxy;
		CTangramCLRProxyImpl*		m_pCLRProxy;
		ITaskbarList3*				m_pTaskbarList3;

		map<CString, CTangramAppProxy*> m_mapTangramAppProxy;

		virtual ITangramDoc* ConnectTangramDoc(CTangramAppProxy* AppProxy, LONGLONG docID, HWND hView, HWND hFrame, LPCTSTR strDocType) { return nullptr; };
	};

	class CTangramAppProxy
	{
	public:
		CTangramAppProxy();
		virtual ~CTangramAppProxy() {};


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

		BOOL InitTangram(void* pVoid);
		BOOL TangramSaveAllModified();
		void RegistWndRunTimeClass(void* clsInfo);

		virtual void OnActiveMainFrame(HWND);
		virtual int OnDestroyMainFrame(CString strID, int nMainFrameCount, int nWndType);
		virtual LRESULT OnForegroundIdleProc();
		virtual BOOL TangramPreTranslateMessage(MSG* pMsg);
		virtual void OnTangramClose() {};
		virtual void OnExtendComplete(HWND hWnd, CString bstrUrl, IWndNode* pRootNode) {};
		virtual void OnTangramEvent(ITangramEventObj* NotifyObj) {};
		virtual void RegistWndClassToTangram() {};
		virtual void OnActiveDocument(ITangramDoc* ActiveDoc, IWndNode* pNodeInDoc, IWndNode* pNodeInCtrlBar, HWND hCtrlBar);
		virtual HWND CreateWindowObj(LPCTSTR strClsName, IWndNode* pNode, HWND hParent);
		virtual HWND CreateNewFrame(CString strFrameKey) /*{ return nullptr; }*/;
		virtual HWND GetActivePopupMenu(HWND);
		virtual HRESULT CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv) { return S_FALSE; };
		virtual ITangramDoc* CreateNewDocument(LPCTSTR lpszFrameID, LPCTSTR lpszAppTitle, void* pDocTemplate, BOOL bNewFrame);
		virtual ITangramDoc* OpenDocument(void* pDocTemplate, CString strFile, BOOL bNewFrame);
		virtual CTangramWndNodeProxy* OnTangramNodeInit(IWndNode* pNewNode) { return nullptr; };
		virtual CCompositorProxy* OnCompositorCreated(ICompositor* pNewCompositor) { return nullptr; };
		virtual CCompositorManagerProxy* OnCompositorManagerCreated(ICompositorManager* pNewWndPage) { return nullptr; };
		virtual void MouseMoveProxy(HWND hWnd);
		virtual void AddDoc(LONGLONG llDocID, ITangramDoc* pDoc);
		virtual void RemoveDoc(LONGLONG llDocID);
		virtual ITangramDoc* GetDoc(LONGLONG llDocID);
		virtual ITangramDoc* NewDoc() { return nullptr; };
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

	extern ITangram* g_pTangram;
	extern 	CTangramApplicationImpl theAppImpl;
	extern 	TangramCommon::CChromeBrowserCreatorImpl* g_pCreatorImpl;
};

using namespace TangramCommon;
