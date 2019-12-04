/********************************************************************************
 *					Tangram Library - version 10.0.0
 **
 *********************************************************************************
 * Copyright (C) 2002-2019 by Tangram Team.   All Rights Reserved.
 **
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

#include <map>
#include <atlstr.h>
#include <string>
#include "jniforchrome.h"
#include "Tangram.h"
#include <ShlObj.h>

#define TANGRAM_CONST_OPENFILE			19920612
#define TANGRAM_CONST_NEWDOC			19631222
#define TANGRAM_CONST_PANE_FIRST		20022017
#define TANGRAM_CHROME_APP_INIT			20190501

#define TANGRAM_APP_WIN32				500
#define TANGRAM_APP_BROWSER				1000
#define TANGRAM_APP_ECLIPSE				2000
#define TANGRAM_APP_BROWSER_ECLIPSE		3000
#define TANGRAM_APP_BROWSERAPP			4000

#define TANGRAM_APP_WILLCLOSE			2019
#define TANGRAM_APP_OTHER				0
#define TANGRAM_APP_SDI					1965
#define TANGRAM_APP_MDI					1992
#define TANGRAM_APP_MDT					1963

#define WM_TANGRAM_WEBNODEDOCCOMPLETE	(WM_USER + 0x00004001)
#define WM_OPENDOCUMENT					(WM_USER + 0x00004002)
#define WM_SPLITTERREPOSITION			(WM_USER + 0x00004003)
#define WM_ECLIPSEWORKBENCHCREATED		(WM_USER + 0x00004004)
#define WM_TABCHANGE					(WM_USER + 0x00004005)
#define WM_TANGRAMMSG					(WM_USER + 0x00004006)
#define WM_NAVIXTML						(WM_USER + 0x00004007)
#define WM_OFFICEOBJECTCREATED			(WM_USER + 0x00004008)
#define WM_MDICHILDMIN					(WM_USER + 0x00004009)
#define WM_TANGRAMAPPINIT				(WM_USER + 0x0000400a)
#define WM_TANGRAMAPPQUIT				(WM_USER + 0x0000400b)
#define WM_TANGRAMDATA					(WM_USER + 0x0000400c)
#define WM_DOWNLOAD_MSG					(WM_USER + 0x0000400d)
#define WM_TANGRAMNEWOUTLOOKOBJ			(WM_USER + 0x0000400e)
#define WM_TANGRAMACTIVEINSPECTORPAGE	(WM_USER + 0x0000400f)
#define WM_USER_TANGRAMTASK				(WM_USER + 0x00004010)
#define WM_SETWNDFOCUSE					(WM_USER + 0x00004011)
#define WM_UPLOADFILE					(WM_USER + 0x00004012)
#define WM_TANGRAMDESIGNMSG				(WM_USER + 0x00004013)
#define WM_INSERTTREENODE				(WM_USER + 0x00004014)
#define WM_REFRESHDATA					(WM_USER + 0x00004015)
#define WM_GETSELECTEDNODEINFO			(WM_USER + 0x00004016)
#define WM_TANGRAMDESIGNERCMD			(WM_USER + 0x00004017)
#define WM_TANGRAMGETTREEINFO			(WM_USER + 0x00004018)
#define WM_TANGRAMGETNODE				(WM_USER + 0x00004019)
#define WM_TANGRAMUPDATENODE			(WM_USER + 0x0000401a)
#define WM_TANGRAMSAVE					(WM_USER + 0x0000401b)
#define WM_MDICLIENTCREATED				(WM_USER + 0x0000401c)
#define WM_TGM_SETACTIVEPAGE			(WM_USER + 0x0000401d)
#define WM_TGM_SET_CAPTION				(WM_USER + 0x0000401e)	
#define WM_GETNODEINFO					(WM_USER + 0x0000401f)
#define WM_CREATETABPAGE				(WM_USER + 0x00004020)
#define WM_ACTIVETABPAGE				(WM_USER + 0x00004021)
#define WM_MODIFYTABPAGE				(WM_USER + 0x00004022)
#define WM_ADDTABPAGE					(WM_USER + 0x00004023)
#define WM_TANGRAMITEMLOAD				(WM_USER + 0x00003024)
#define WM_INITOUTLOOK					(WM_USER + 0x00004026)
#define WM_CONTROLBARCREATED			(WM_USER + 0x00004027)
#define WM_QUERYAPPPROXY				(WM_USER + 0x00004028)
#define WM_TANGRAMACTIVEPAGE			(WM_USER + 0x00004029)
#define WM_TANGRAMSETAPPTITLE			(WM_USER + 0x0000402a)
#define WM_LYNCIMWNDCREATED				(WM_USER + 0x0000402b)
#define WM_STOPTRACKING					(WM_USER + 0x0000402c)
#define WM_TANGRAMINIT					(WM_USER + 0x0000402d)
#define WM_VSSHOWPROPERTYGRID			(WM_USER + 0x0000402e)
#define WM_REMOVERESTKEY				(WM_USER + 0x0000402f)
#define WM_TANGRAMGETXML				(WM_USER + 0x00004030)
#define WM_CHROMEWEBCLIENTCREATED		(WM_USER + 0x00004031)
#define WM_CHROMERENDERERFRAMEHOSTINIT	(WM_USER + 0x00004032)
#define WM_CHROMEOPENWINDOWMSG			(WM_USER + 0x00004033)
#define WM_BROWSERLAYOUT                (WM_USER + 0x00004034)
#define WM_CHROMEMSG	                (WM_USER + 0x00004035)
#define WM_CHROMEWNDPARENTCHANGED       (WM_USER + 0x00004035)
#define WM_DEVICESCALEFACTORCHANGED     (WM_USER + 0x00004036)
#define WM_CHROMEDEVTOOLMSG	            (WM_USER + 0x00004037)
#define WM_BACKGROUNDWEBPROXY_MSG       (WM_USER + 0x00004039)
#define WM_CHROMEWNDNODEMSG             (WM_USER + 0x00004040)
#define WM_DOTNETCONTROLCREATED         (WM_USER + 0x00004041)
#define WM_DOCUMENTONLOADCOMPLETED      (WM_USER + 0x00004043)
#define WM_DOCUMENTFAILLOADWITHERROR    (WM_USER + 0x00004044)
#define WM_CHROMEHELPWND                (WM_USER + 0x00004045)
#define WM_CHROMEOMNIBOXPOPUPVISIBLE    (WM_USER + 0x00004046)
#define WM_HOSTNODEFORSPLITTERCREATED   (WM_USER + 0x00004047)
#define WM_CHROMEOPENURLMSG				(WM_USER + 0x00004048)
#define WM_LBUTTONDOWNEX			    (WM_USER + 0x00004049)
#define WM_WINFORMCREATED				(WM_USER + 0x0000404a)
#define WM_CHROMEIPCMSG					(WM_USER + 0x00004052)
#define WM_CHROMEAPPINIT				(WM_USER + 0x00004053)
#define WM_CREATETANGRAMVIEW			(WM_USER + 0x00004054)

#define TANGRAM_OBJECT_ENTRY_AUTO(clsid, class) \
    __declspec(selectany) ATL::_ATL_OBJMAP_CACHE __objCache__##class = { NULL, 0 }; \
	const ATL::_ATL_OBJMAP_ENTRY_EX __objMap_##class = {&clsid, class::UpdateRegistry, class::_ClassFactoryCreatorClass::CreateInstance, class::CreateInstance, &__objCache__##class, class::GetObjectDescription, class::GetCategoryMap, class::ObjectMain }; \
	extern "C" __declspec(allocate("ATL$__m")) __declspec(selectany) const ATL::_ATL_OBJMAP_ENTRY_EX* const __pobjMap_##class = &__objMap_##class; \
	OBJECT_ENTRY_PRAGMA(class)

#define OBJECT_ENTRY_AUTO_EX(clsid, class) \
    __declspec(selectany) ATL::_ATL_OBJMAP_CACHE __objCache__##class = { NULL, 0 }; \
	const ATL::_ATL_OBJMAP_ENTRY_EX __objMap_##class = {&clsid, class::UpdateRegistry, class::_ClassFactoryCreatorClass::CreateInstance, class::CreateInstance, &__objCache__##class, class::GetObjectDescription, class::GetCategoryMap, class::ObjectMain }; \
	extern "C" __declspec(allocate("ATL$__m")) __declspec(selectany) const ATL::_ATL_OBJMAP_ENTRY_EX* const __pobjMap_##class = &__objMap_##class; \
	OBJECT_ENTRY_PRAGMA(class)

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

namespace TangramCommon {
	using namespace std;
	using namespace ATL;

	class CChromeTab;
	class CTangramImpl;
	class ITangramWindow;
	class CChromeTabProxy;
	class ITangramDelegate;
	class CChromeBrowserBase;
	class CChromeBrowserProxy;
	class CChromeRenderProcess;
	class CChromeWebContentBase;
	class CTangramMainDllLoader;
	class OmniboxViewViewsProxy;
	class CTangramBrowserFactory;
	class CChromeRenderProcessProxy;
	class CChromeWebContentProxyBase;
	class CChromeRenderFrameHostBase;
	class CChromeChildProcessHostImpl;
	class CChromeRenderFrameHostProxyBase;
	class CChromeChildProcessHostImplProxy;

	class ITangramCLRImpl;
	class ITangramAppProxy;

	typedef struct {
		CString m_strType;
		CString m_strKey;
		CString m_strData;
	} IPCMsg;

	typedef struct
	{
		HWND			m_hCtrlHandle;
		IDispatch* m_pDisp;
		IDispatch* m_pParentDisp;
		CString			m_strCtrlName;
		CString			m_strCompositorName;
		CString			m_strNodeXml;
		CString			m_strParentCtrlName;
	}CompositorInfo;

	typedef struct
	{
		int			m_nType;
		CString		m_strMessage;
		CString		m_strMessageData;
	} TangramIPCMessageData;

	typedef struct 
	{
		bool bDll;
		int nResID;
		CString strProxyName;
		CString strProxyID;
		CString strFileTypeID;
		CString strExt;
		CString strfilterName;
	} DocTemplateInfo;

	typedef struct
	{
		BOOL			m_bCOMObj;
		int				m_nImageIndex;
		HWND			m_hWnd;
		CString			m_strLib;
		CString			m_strExt;
		CString			m_strFilter;
		CString			m_strProxyID;
		CString			m_strDocTemplateKey;
		CString			m_strTemplatePath;
		void* m_pDocTemplate;
	}TangramDocTemplateInfo;

	typedef struct
	{
		BOOL			m_bTangramSupport;
		int				m_nPrjType;
		int				m_nImageIndex;
		int				m_nIndex;
		CString			m_strPrjFullPath;
		CString			m_strExt;
		CString			m_strFilter;
		IDispatch* m_pPrjDisp;
	}TangramProjectInfo;

	typedef struct
	{
		CString		m_strTangramID;
		CString		m_strAppProxyID;
		CString		m_strAppName;
		CString		m_strMainFrameID;
		CString		m_strDocID;
		CString		m_strTangramData;
	}TangramDocInfo;

	typedef struct 
	{
		HWND				m_hWnd;
		CString				m_strName;
		ICompositorManager* m_pCompositorManager;
		IWndNode* m_pNode;
		IDispatch* m_pCtrlDisp;
	}CtrlInfo;

	class CMDIChildFormInfo
	{
	public:
		CMDIChildFormInfo() {}
		~CMDIChildFormInfo() {}
		map<CString, CString>	m_mapFormsInfo;
	};

	typedef TangramCommon::CTangramImpl* (__stdcall* GetTangramImplFunction)(ITangram** ppTangram);

	class CTangramWPFObj
	{
	public:
		CTangramWPFObj()
		{
			m_pDisp = nullptr;
			m_hwndWPF = nullptr;
		}
		~CTangramWPFObj() {}
		HWND m_hwndWPF;
		IDispatch* m_pDisp;
		map<CString, IDispatch*> m_mapWPFObj;
		virtual BOOL IsVisible() { return false; }
		virtual void InvalidateVisual() {}
		virtual void ShowVisual(BOOL bShow) {}
		virtual void Focusable(BOOL bFocus) {}
	};

	class ITangramWindowProvider
	{
	public:
		ITangramWindowProvider() {}
		virtual ~ITangramWindowProvider() {}

		CString		m_strProviderID = _T("");
		CString		m_strTangramContainer = _T("");
		ITangram* m_pTangram = nullptr;
		IWndNode* m_pCreatingNode = nullptr;
		map<CString, CString> m_mapInnerObjStyle;
		map<CString, void*> m_mapInnerObjInfo;

		virtual bool TangramInit(CString strID) = 0;
		virtual CString GetNames() = 0;
		virtual CString GetTags(CString strName) = 0;
		virtual HWND Create(HWND hParentWnd, IWndNode* pNode) = 0;
	};

	class ITangramWindow
	{
	public:
		ITangramWindow() {}
		virtual ~ITangramWindow() {}

		virtual void Save() = 0;
	};

	class CTangramWndNodeProxy
	{
	public:
		CTangramWndNodeProxy() { }
		virtual ~CTangramWndNodeProxy() {}

		bool	m_bAutoDelete;

		virtual void OnOpenComplete() {}
		virtual void OnDestroy() {}
		virtual void OnNodeAddInCreated(IDispatch* pAddIndisp, CString bstrAddInID, CString bstrAddInXml) {}
		virtual void OnNodeAddInsCreated() {}
		virtual void OnNodeDocumentComplete(IDispatch* ExtenderDisp, CString bstrURL) {}
		virtual void OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName) {}
		virtual void OnTabChange(LONG ActivePage, LONG OldPage) {}
		virtual void OnTangramDocEvent(ITangramEventObj* pEventObj) {}
	};

	class CCompositorManagerProxy
	{
	public:
		CCompositorManagerProxy() { }
		virtual ~CCompositorManagerProxy() {}

		bool	m_bAutoDelete;

		virtual void OnCompositorManagerLoaded(IDispatch* sender, CString url) {}
		virtual void OnNodeCreated(IWndNode* pNodeCreated) {}
		virtual void OnAddInCreated(IWndNode* pRootNode, IDispatch* pAddIn, CString bstrID, CString bstrAddInXml) {}
		virtual void OnBeforeOpenXml(CString bstrXml, HWND hWnd) {}
		virtual void OnOpenXmlComplete(CString bstrXml, HWND hWnd, IWndNode* pRetRootNode) {}
		virtual void OnDestroy() {}
		virtual void OnNodeMouseActivate(IWndNode* pActiveNode) {}
		virtual void OnClrControlCreated(IWndNode* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle) {}
		virtual void OnTabChange(IWndNode* sender, LONG ActivePage, LONG OldPage) {}
		virtual void OnEvent(IDispatch* sender, IDispatch* EventArg) {}
		virtual void OnControlNotify(IWndNode* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName) {}
		virtual void OnTangramEvent(ITangramEventObj* NotifyObj) {}
	};

	class CCompositorProxy
	{
	public:
		CCompositorProxy() { }
		virtual ~CCompositorProxy() {}

		bool	m_bAutoDelete;
		virtual void OnExtend(IWndNode* pRetNode, CString bstrKey, CString bstrXml) {}
	};

	class CTangramDocProxy
	{
	public:
		CTangramDocProxy() {}
		virtual ~CTangramDocProxy()
		{
			m_bDocLoaded = false;
			m_bCanDestroyFrame = true;
			m_strTangramData = _T("");
			m_pDoc = nullptr;
		}

		BOOL		m_bDocLoaded;
		BOOL		m_bCanDestroyFrame;
		CString		m_strTangramID;
		CString		m_strAppProxyID;
		CString		m_strAppName;
		CString		m_strMainFrameID;
		CString		m_strDocID;
		CString		m_strTangramData;

		ITangramDoc* m_pDoc;
		virtual void SaveDoc() {}
		virtual void TangramDocEvent(ITangramEventObj* pEventObj) {}
	};

	class ITangramAppProxy
	{
	public:
		ITangramAppProxy() {}
		virtual ~ITangramAppProxy() {}

		BOOL								m_bAutoDelete;
		HWND								m_hMainWnd;
		HWND								m_hCreatingView;
		LPCTSTR								m_strProxyName;
		LPCTSTR								m_strProxyID;
		LPCTSTR								m_strCreatingFrameTitle;
		LPCTSTR								m_strClosingFrameID;
		void* m_pvoid;
		CTangramDocProxy* m_pCurDocProxy;
		CTangramImpl* m_pTangramImpl;

		BOOL								m_bCreatingNewFrame;
		int									m_nFrameIndex;
		HWND								m_hClosingFrame;
		CString								m_strAppKey;
		map<CString, void*>					m_mapMainFrame;
		map<LONGLONG, ITangramDoc*>			m_mapTangramDoc;
		map<void*, LONG>					m_mapTangramDocTemplateID;

		virtual BOOL InitTangram(void* pVoid) { return false; }
		virtual BOOL TangramSaveAllModified() { return false; }

		virtual void OnActiveMainFrame(HWND) {}
		virtual int OnDestroyMainFrame(CString strID, int nMainFrameCount, int nWndType) { return 0; }
		virtual LRESULT OnForegroundIdleProc() { return 0; }
		virtual BOOL TangramPreTranslateMessage(MSG* pMsg) { return false; }
		virtual void OnTangramClose() {}
		virtual void OnOpenComplete(HWND hWnd, CString bstrUrl, IWndNode* pRootNode) {}
		virtual void OnTangramEvent(ITangramEventObj* NotifyObj) {}
		virtual void RegistWndClassToTangram() {}
		virtual void OnActiveDocument(ITangramDoc* ActiveDoc, IWndNode* pNodeInDoc, IWndNode* pNodeInCtrlBar, HWND hCtrlBar) {}
		virtual HWND CreateNewFrame(CString strFrameKey) { return NULL; }
		virtual HWND GetActivePopupMenu(HWND) { return NULL; }
		virtual HRESULT CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv) { return S_OK; }
		virtual ITangramDoc* CreateNewDocument(LPCTSTR lpszFrameID, LPCTSTR lpszAppTitle, void* pDocTemplate, BOOL bNewFrame) { return NULL; }
		virtual ITangramDoc* OpenDocument(void* pDocTemplate, CString strFile, BOOL bNewFrame) { return NULL; }
		virtual CTangramWndNodeProxy* OnTangramNodeInit(IWndNode* pNewNode) { return nullptr; }
		virtual CCompositorProxy* OnCompositorCreated(ICompositor* pNewCompositor) { return nullptr; }
		virtual CCompositorManagerProxy* OnCompositorManagerCreated(ICompositorManager* pNewWndPage) { return nullptr; }
		virtual void MouseMoveProxy(HWND hWnd) {}
		virtual void AddDoc(LONGLONG llDocID, ITangramDoc* pDoc) {}
		virtual void RemoveDoc(LONGLONG llDocID) {}
		virtual ITangramDoc* GetDoc(LONGLONG llDocID) { return nullptr; }
		virtual ITangramDoc* NewDoc() { return nullptr; }
		virtual HWND InitTangramApp() { return NULL; }
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
		}

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

		ICompositor* m_pCompositor;
		CTangramImpl* m_pProxy;
		map<HWND, ICompositor*>				m_mapWinFormCompositor;

		ICompositor* m_pToolBoxFrame;
		ICompositor* m_pClassViewFrame;
		ICompositor* m_pPropertyFrame;

		virtual HWND CreateTangramToolWnd() { return nullptr; }
		virtual HWND CreateTangramHelpToolWnd(CString strXml) { return nullptr; }
		virtual void OnSelectedObjectsChanged(IDispatch* pObj, CString strType, LPARAM hObjWnd, int nType) {}
		virtual void ShowTangramToolWnd(BOOL bShowMainToolWnd, int nShow) {}
		virtual void TangramAction(CString strXml) {}
	};

	class ITangramCLRImpl
	{
	public:
		ITangramCLRImpl()
		{
			m_strObjTypeName = _T("");
		}

		CString				m_strObjTypeName;
		CString				m_strCurrentWinFormTemplate;

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
		virtual void SelectNode(IWndNode*) {}
		virtual void SelectObj(IDispatch*) {}
		virtual void ReleaseTangramObj(IDispatch*) {}
		virtual void AttachVSPropertyWnd(HWND) {}
		virtual void WindowCreated(LPCTSTR strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd) {}
		virtual void WindowDestroy(HWND hWnd) {}
		virtual CTangramWPFObj* CreateWPFControl(IWndNode* pNode, HWND hPWnd, UINT nID) { return nullptr; }
		virtual HRESULT NavigateURL(IWndNode* pNode, CString strURL, IDispatch* dispObjforScript) { return S_FALSE; }
		virtual void OnCLRHostExit() {}
		virtual void OnDestroyChromeBrowser(IChromeWebBrowser*) {}
		virtual void ExportAllFormsInfo() {}
		virtual void SetObjectProperty(IDispatch* pObj, BSTR bstrPropertyName, BSTR bstrPropertyValue) {}
		virtual void* Extend(CString strKey, CString strData, CString strFeatures) { return nullptr; }
		virtual bool IsSupportDesigner() { return false; }
		virtual HICON GetAppIcon(int nIndex) = 0;
	};

	class CTangramImpl {
	public:
		CTangramImpl() {
			m_bClose = false;
			m_bInit = false;
			m_hParent = NULL;
			m_hSmallIcon = nullptr;
			m_hLargeIcon = nullptr;
			m_pBrowserFactory = nullptr;
			m_pActiveBrowser = nullptr;
			m_bExportComponent = false;
			m_hHostWnd = nullptr;
			m_hFormNodeWnd = nullptr;
			m_hMainWnd = nullptr;
			m_hTangramWnd = nullptr;
			m_pCLRProxy = nullptr;
			m_hChildHostWnd = nullptr;
			m_pActiveAppProxy = nullptr;
			m_pTangramCLRAppProxy = nullptr;
			m_pTangramAppProxy = nullptr;
			m_pTangramDelegate = nullptr;
			m_pCurMDIChildFormInfo = nullptr;
			m_strNtpXml = _T("");
			m_strNtpDataXml = _T("");
			m_pTangramPackageProxy = nullptr;
			m_strAppCurrentFormTemplatePath = _T("");
			m_pCreatingTangramWindow = nullptr;
			m_pCreatingOmniboxViewViews = nullptr;
			m_pCreatingChromeRenderFrameHostBase = nullptr;
		}

		virtual ~CTangramImpl() {}

		bool									m_bClose;
		bool									m_bInit;
		bool									m_bChromeNeedClosed;
		bool									m_bCreatingDevTool;
		bool									m_bOMNIBOXPOPUPVISIBLE;
		bool									m_b64bitSystem = false;
		bool									m_bX86App = false;
		bool									m_bOfficeApp = false;
		bool									m_bEclipse = false;
		bool									m_bLoadEclipseDelay = false;
		bool									m_bTangramInit = false;
		bool									m_bAdmin;
		bool									m_bCanClose;
		bool									m_bFrameDefaultState;
		bool									m_bOfficeAddinUnLoad;
		bool									m_bWinFormActived;
		bool									m_bEnableProcessFormTabKey;
		bool									m_bDeleteCompositorManager;
		bool									m_bNewFile;
		bool									m_bFirstDocCreated;
		bool									m_bUsingDefaultAppDocTemplate;
		bool									m_bCreatingForm;
		bool									m_bCLRObjTemplateInit;
		bool									m_bTangramJniInit;
		bool									m_bExportComponent;
		bool									m_bIsSupportCrashReporting = false;
		bool									m_bIsAppInit = false;
		bool									m_bIsEclipseInit = false;
		bool									m_bIsChromeRunning = false;

		DWORD									m_dwThreadID;
		DWORD									m_nAppType;
		HWND									m_hTemplateWnd;
		HWND									m_hTemplateChildWnd;
		HWND									m_hActiveWnd;
		HWND									m_hEclipseHideWnd;
		HWND									m_hMainWnd;
		HWND									m_hHostWnd;
		HWND									m_hChildHostWnd;
		HWND									m_hTangramWnd;
		HWND									m_hFormNodeWnd;
		HWND									m_hParent;
		HWND									m_hHostBrowserWnd;
		HWND									m_hVSToolBoxWnd;
		HICON									m_hLargeIcon;
		HICON									m_hSmallIcon;

		CString									m_strAppKey;
		CString									m_strAppName;
		CString									m_strExeName;
		CString									m_strAppPath;
		CString									m_strTempPath;
		CString 								m_strConfigDataFile;
		CString									m_strAppDataPath;
		CString									m_strCurrentAppID;
		CString									m_strProgramFilePath;
		CString									m_strTangramURLBase;
		CString									m_strAppCommonDocPath;
		CString									m_strAppCommonDocPath2;
		CString									m_strAppCommonFormsPath;
		CString									m_strAppCommonFormsInfoPath;
		CString									m_strAppCommonFormsTemplatePath;
		CString									m_strAppFormsPath;
		CString									m_strAppFormsInfoPath;
		CString									m_strAppWPFObjsInfoPath;
		CString									m_strAppControlsInfoPath;
		CString									m_strAppFormsTemplatePath;
		CString									m_strAppCurrentFormTemplatePath;
		CString									m_strNodeSelectedText;
		CString									m_strDesignerTip1;
		CString									m_strDesignerTip2;
		CString									m_strDesignerXml;
		CString									m_strDesignerToolBarCaption;
		CString									m_strStartView;
		CString									m_strNewDocXml;
		CString									m_strStartXml;
		CString									m_strNtpXml;
		CString									m_strNtpDataXml;

		CString 								m_strConfigFile;
		CString									m_strWinAppConfigFile;
		CString									m_strDocFilters;
		CString									m_strDesignerInfo;
		CString									m_strTemplatePath;
		CString									m_strCurrentFrameID;
		CString									m_strDocTemplateStrs;
		CString									m_strDefaultTemplate;
		CString									m_strDefaultTemplate2;
		CString									m_strCurrentDocTemplateXml;
		CString									m_strCurrentKey;
		CString									m_strWorkBenchStrs;
		CString									m_strStartupURL = _T("");
		CString									m_strStartupCLRObj;
		CString									m_strCurrentEclipsePagePath;
		CString									m_strDefaultXml;
		CString									m_strLibs;

		CStringA								m_strBridgeJavaClass;
		CString									m_strStartJarPath;

		ITangramCLRImpl*						m_pCLRProxy;
		ITangramAppProxy*						m_pActiveAppProxy;
		ITangramAppProxy*						m_pTangramAppProxy;
		ITangramAppProxy*						m_pTangramCLRAppProxy;
		CMDIChildFormInfo*						m_pCurMDIChildFormInfo;
		CTangramPackageProxy*					m_pTangramPackageProxy;

		IDispatch*								m_pMainFormDisp;
		IDispatch*								m_pAppDisp;
		IWndNode*								m_pHostViewDesignerNode;
		ITangramExtender*						m_pExtender;

		ITangramDelegate*						m_pTangramDelegate;
		CChromeBrowserBase*						m_pActiveBrowser;
		CTangramBrowserFactory*					m_pBrowserFactory;
		ITangramWindow*							m_pCreatingTangramWindow = nullptr;
		OmniboxViewViewsProxy*					m_pCreatingOmniboxViewViews;
		CChromeRenderFrameHostBase*				m_pCreatingChromeRenderFrameHostBase;

		map<CString, IDispatch*>				m_mapObjDic;
		map<HWND, ICompositorManager*>			m_mapFramePage;
		map<HWND, ICompositorManager*>			m_mapWindowPage;
		map<CString, IDispatch*>				m_mapAppDispDic;
		map<CString, CComVariant>				m_mapValInfo;
		map<CString, void*>						m_mapTemplateInfo;
		map<CString, ITangram*>					m_mapRemoteTangramCore;
		map<IWndNode*, CString>					m_mapControlScript;
		map<CString, void*>						m_mapExcludedObjects;
		map<CString, HWND>						m_mapTangramDesignedWindows;
		map<CString, ITangramAppProxy*>			m_mapTangramAppProxy;
		map<CString, ITangramWindowProvider*>	m_mapTangramWindowProvider;
		map<int, TangramDocTemplateInfo*>		m_mapTangramDocTemplateInfo;
		map<CString, TangramDocTemplateInfo*>	m_mapTangramDocTemplateInfo2;
		map<CString, TangramDocTemplateInfo*>	m_mapTangramFormsTemplateInfo;
		map<int, TangramDocTemplateInfo*>		m_mapTangramFormsTemplateInfo2;
		map<HWND, IChromeWebContent*>			m_mapHtmlWnd;
		map<HWND, IChromeWebBrowser*>			m_mapBrowserWnd;
		map<HWND, IWorkBenchWindow*>			m_mapWorkBenchWnd;
		map<void*, IUnknown*>					m_mapObjects;
		map<IDispatch*, CString>				m_mapObjEventDic;
		map<CString, CString>					m_mapJavaNativeInfo;
		map<CString, CString>					m_mapCreatingWorkBenchInfo;
		map<CString, CString>					m_mapFormsInfo;
		map<CString, CString>					m_mapAtlMFCsInfo;
		map<CString, CString>					m_mapStartupsInfo;
		map<CString, CString>					m_mapeclipsesInfo;
		map<CString, CString>					m_mapWorkBenchInfo;
		map<CString, CString>					m_mapUserControlsInfo;
		map<CString, CMDIChildFormInfo*>		m_mapChildFormsInfo;

		virtual void BrowserAppStart() = 0;
		virtual ICompositor* ConnectCompositorManager(HWND, CString, ICompositorManager* pCompositorManager, CompositorInfo*) { return nullptr; }
		virtual void OnSubBrowserWndCreated(HWND hParent, HWND hBrowser) = 0;
		virtual void OnRenderProcessCreated(CChromeRenderProcess* pProcess) = 0;
		virtual void OnDocumentOnLoadCompleted(CChromeRenderFrameHostBase*,	HWND hHtmlWnd, void*) = 0;
		virtual void ChromeTabCreated(CChromeTab* pTab) = 0;
		virtual CString GetProcessPath(const char* _ver, CString process_type) = 0;
		virtual CString GetSchemeBaseName() = 0;
		virtual HICON GetAppIcon(int nIndex) = 0;
		virtual CChromeBrowserBase* GetChromeBrowserBase(HWND) = 0;
		virtual void AttachNode(void* pNodeEvents) {}
		virtual void TangramInit() {}
		virtual ITangramDoc* ConnectTangramDoc(ITangramAppProxy* AppProxy, LONGLONG docID, HWND hView, HWND hFrame, LPCTSTR strDocType) { return nullptr; }
		virtual CString GetNewLayoutNodeName(BSTR strCnnID, IWndNode* pDesignNode) { return _T(""); }
		virtual ICompositorManager* Open(HWND, CString strName, CString strKey) { return nullptr; }
		virtual IWndNode* OpenCtrl(__int64 handle, CString name, CString NodeTag) { return nullptr; }
		virtual bool IsMDIClientCompositorNode(IWndNode*) { return false; }
		virtual BOOL UpdateProjectforTangram(CString strPrjFullName) { return false; }
		virtual void TangramToolTabCtrlCreated(HWND hTabCtrl) {}
		virtual void DotNetControlCreated(MSG* lpMsg) {}
		virtual void ExportComponentInfo() {}
		virtual void ConnectDocTemplate(LPCTSTR strType, LPCTSTR strExt, void* pTemplate) {}
	};

	class ITangramDelegate {
	public:
		ITangramDelegate() {
			m_bBrowserWndCreated = false;
			m_pJVM = nullptr;
			m_pJVMenv = nullptr;
			systemClass = nullptr;
			exitMethod = nullptr;
			loadMethod = nullptr;
		}

		virtual ~ITangramDelegate() {}

		BOOL				m_bBrowserWndCreated;
		JavaVM* m_pJVM;
		JNIEnv* m_pJVMenv;
		jclass				systemClass;
		jmethodID			exitMethod;
		jmethodID			loadMethod;

		virtual void ProcessMsg(MSG* msg) = 0;
		virtual void ForegroundIdleProc() = 0;
		virtual bool DoIdleWork() = 0;
		virtual BOOL OnAppIdle(BOOL& bIdle, LONG lCount) = 0;
		virtual BOOL IsAppIdleMessage() = 0;
		virtual bool OnTangramPreTranslateMessage(MSG* pMsg) = 0;
		virtual CString GetNTPXml() = 0;
		virtual CString GetNTPData() = 0;
		virtual HWND GetMainWnd() = 0;
		virtual bool BrowserAppStart() = 0;
		virtual HWND QueryCanClose(HWND hWnd) = 0;
		virtual bool GetClientAreaBounds(HWND hWnd, RECT& rc) = 0;
		virtual bool HookAppDocTemplateInfo() = 0;
		virtual void BeginBrowserSession() = 0;
		virtual void EndBrowserSession() = 0;
		virtual bool EclipseAppInit() = 0;
		virtual void TangramIPCMsg(HWND hWnd, CString strType, CString strParam1, CString strParam2) = 0;
		virtual void TangramRenderHTMLElement(HWND hWnd, CString strRuleName, CString strHTML) = 0;
	};

	class CTangramMainDllLoader {
	public:
		CTangramMainDllLoader() {}
		virtual ~CTangramMainDllLoader() {}
		virtual void LaunchEx(CTangramImpl*) {}
	};

	class CTangramBrowserFactory {
	public:
		CTangramBrowserFactory() {}
		virtual ~CTangramBrowserFactory() {}

		virtual HWND CreateBrowser(HWND hParent, CString strXml) = 0;
	};

	class CChromeChildProcessHostImpl {
	public:
		CChromeChildProcessHostImpl() { m_pChildProcessHostProxy = nullptr; }
		virtual ~CChromeChildProcessHostImpl() {}

		CChromeChildProcessHostImplProxy* m_pChildProcessHostProxy;
	};

	class CChromeChildProcessHostImplProxy {
	public:
		CChromeChildProcessHostImplProxy() {}

		virtual ~CChromeChildProcessHostImplProxy() {}

		virtual void OnRenderProcessCreated() = 0;
	};

	class CChromeRenderProcess {
	public:
		CChromeRenderProcess() { m_pRenderProcessProxy = nullptr; }
		virtual ~CChromeRenderProcess() {}

		CChromeRenderProcessProxy* m_pRenderProcessProxy;
	};

	class CChromeRenderProcessProxy {
	public:
		CChromeRenderProcessProxy() {}

		virtual ~CChromeRenderProcessProxy() {}

		virtual CString ProcessPath() = 0;
		virtual void OnRenderProcessCreated() = 0;
	};

	class CChromeTab {
	public:
		CChromeTab() {
			m_pTabProxy = nullptr;
			HMODULE hModule = ::GetModuleHandle(L"TangramCore.dll");
			if (hModule != nullptr) {
				TangramCommon::GetTangramImplFunction GetTangramImplFunction =
					(TangramCommon::GetTangramImplFunction)GetProcAddress(
						hModule, "GetTangramImpl");
				if (GetTangramImplFunction != NULL) {
					ITangram* pTangram = nullptr;
					TangramCommon::CTangramImpl* _pImpl = GetTangramImplFunction(&pTangram);
					if (_pImpl) {
						_pImpl->ChromeTabCreated(this);
					}
				}
			}
		}
		virtual ~CChromeTab() {
		}

		CChromeTabProxy* m_pTabProxy;
	};

	class CChromeTabProxy {
	public:
		CChromeTabProxy() {
			m_pTab = nullptr;
		}
		virtual ~CChromeTabProxy() {
		}
		CChromeTab* m_pTab;
	};

	class OmniboxViewViewsProxy {
	public:
		OmniboxViewViewsProxy() {
			HMODULE hModule = ::GetModuleHandle(L"TangramCore.dll");
			if (hModule != nullptr) {
				TangramCommon::GetTangramImplFunction GetTangramImplFunction =
					(TangramCommon::GetTangramImplFunction)GetProcAddress(
						hModule, "GetTangramImpl");
				if (GetTangramImplFunction != NULL) {
					ITangram* pTangram = nullptr;
					TangramCommon::CTangramImpl* _pImpl = GetTangramImplFunction(&pTangram);
					if (_pImpl) {
						_pImpl->m_pCreatingOmniboxViewViews = this;
					}
				}
			}
		}
		virtual ~OmniboxViewViewsProxy() {}

		virtual void Blur() = 0;
		virtual bool IsFocused() = 0;
	};

	class CChromeBrowserBase {
	public:
		CChromeBrowserBase() {
			HMODULE hModule = ::GetModuleHandle(L"TangramCore.dll");
			if (hModule != nullptr) {
				TangramCommon::GetTangramImplFunction GetTangramImplFunction =
					(TangramCommon::GetTangramImplFunction)GetProcAddress(
						hModule, "GetTangramImpl");
				if (GetTangramImplFunction != NULL) {
					ITangram* pTangram = nullptr;
					TangramCommon::CTangramImpl* _pImpl = GetTangramImplFunction(&pTangram);
					if (_pImpl) {
						m_pProxy = nullptr;
						_pImpl->m_pActiveBrowser = this;
					}
				}
			}
		}
		virtual ~CChromeBrowserBase() {}

		CChromeBrowserProxy* m_pProxy;

		virtual int GetType() = 0;
		virtual void LayoutBrowser() = 0;
		virtual void OpenURL(std::wstring strURL,
			BrowserWndOpenDisposition nPos,
			void* pVoid) = 0;
		virtual HWND GetActiveWebContentWnd() = 0;
		virtual bool IsActiveWebContentWnd(HWND hWebWnd) = 0;
	};

	class CChromeBrowserProxy {
	public:
		CChromeBrowserProxy() {}
		virtual ~CChromeBrowserProxy() {}

		CChromeBrowserBase* m_pBrowser;
		OmniboxViewViewsProxy* m_pOmniboxViewViews;

		virtual void UpdateContentRect(RECT& rc, int nTopFix) = 0;
		virtual void ActiveChromeTab(HWND hActive, HWND hOldWnd) = 0;
	};

	class CChromeWebContentBase {
	public:
		CChromeWebContentBase() { m_pProxy = nullptr; }

		virtual ~CChromeWebContentBase() {}

		CChromeWebContentProxyBase* m_pProxy;

		virtual CChromeRenderFrameHostBase* GetMainRenderFrameHost() = 0;
	};

	class CChromeWebContentProxyBase {
	public:
		CChromeWebContentProxyBase() { m_pWebContent = nullptr; }

		virtual ~CChromeWebContentProxyBase() {}

		CChromeWebContentBase* m_pWebContent;
	};

	class CChromeRenderFrameHostBase {
	public:
		CChromeRenderFrameHostBase() {
			m_pProxy = nullptr;
		}

		virtual ~CChromeRenderFrameHostBase() {}

		CChromeRenderFrameHostProxyBase* m_pProxy;

		virtual void SendTangramMessage(IPCMsg*) = 0;
	};

	class CChromeRenderFrameHostProxyBase {
	public:
		CChromeRenderFrameHostProxyBase() { m_pChromeRenderFrameHost = nullptr; }

		virtual ~CChromeRenderFrameHostProxyBase() {}

		CChromeRenderFrameHostBase* m_pChromeRenderFrameHost;
		virtual void OnChromeIPCMessageReceived(std::wstring strType, std::wstring strParam1, std::wstring strParam2) {}
		virtual CChromeBrowserBase* GetChromeBrowserBase(HWND) = 0;
	};

	class CChromeRendererFrameBase {
	public:
		CChromeRendererFrameBase() {}

		virtual ~CChromeRendererFrameBase() {}
	};

}  // namespace TangramCommon
