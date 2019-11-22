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

// TangramCore.h : Declaration of the CTangram

#include "tangram.h"
#include "ObjSafe.h"
#include "wpfview.h"

#include "chromium\BrowserWnd.h"
#include "Object\ObjectFactory.h"
#include "IPC\Broker.h"
#include "IPC\EndPoint.h"

#pragma once
//https://github.com/eclipse/rt.equinox.framework/tree/master/features/org.eclipse.equinox.executable.feature/library/win32

using namespace ChromePlus;
using namespace TangramCommon;
class CTangramWinFormWnd;
struct TangramThreadInfo
{
	HHOOK						m_hGetMessageHook;
	map<HWND, CCompositor*>		m_mapCompositor;
};

struct TangramWndClsInfo
{
public:
	TangramWndClsInfo(void) {};

	CRuntimeClass* m_pTabWndClsInfo;
};

struct TangramWndInfo
{
	HWND m_hBindWnd;
	CString m_strInfo;
};

struct TangramFrameInfo
{
	CString m_strKey;
	CString m_strXml;
};

class ATL_NO_VTABLE CTangramEventObj :
	public CComObjectRootBase,
	public IDispatchImpl<ITangramEventObj, &IID_ITangramEventObj, &LIBID_Tangram, 1, 0>
{
public:
	CTangramEventObj();
	virtual ~CTangramEventObj();

	BEGIN_COM_MAP(CTangramEventObj)
		COM_INTERFACE_ENTRY(ITangramEventObj)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	void Lock() {}
	void Unlock() {}

	void Init(CString strEventName, int nEventIndex, IDispatch* pSourceDisp)
	{
		m_nEventIndex = nEventIndex;
		m_strEventName = strEventName;
		if (pSourceDisp)
		{
			m_pSourceObj = pSourceDisp;
			m_pSourceObj->AddRef();
		}
	}
	BOOL m_bNotFired;
	int m_nEventIndex;
	CString m_strEventName;
	IDispatch*	m_pSourceObj;
	map<int, IDispatch*> m_mapDisp;
	map<int, VARIANT> m_mapVar;
protected:
	ULONG InternalAddRef() { return 1; }
	ULONG InternalRelease() { return 1; }
public:
	STDMETHOD(get_EventName)(BSTR* pVal);
	STDMETHOD(put_EventName)(BSTR newVal);
	STDMETHOD(get_Object)(int nIndex, IDispatch** pVal);
	STDMETHOD(put_Object)(int nIndex, IDispatch* newVal);
	STDMETHOD(get_Value)(int nIndex, VARIANT* pVal);
	STDMETHOD(put_Value)(int nIndex, VARIANT newVal);
	STDMETHOD(get_eventSource)(IDispatch** pVal);
	STDMETHOD(put_eventSource)(IDispatch* pSource);
	STDMETHOD(get_Index)(int* nVal);
	STDMETHOD(put_Index)(int newVal);
};

class ATL_NO_VTABLE CTangramDoc :
	public CComObjectRootBase,
	public IDispatchImpl<ITangramDoc, &IID_ITangramDoc, &LIBID_Tangram, 1, 0>
{
public:
	CTangramDoc();
	virtual ~CTangramDoc();
	BEGIN_COM_MAP(CTangramDoc)
		COM_INTERFACE_ENTRY(ITangramDoc)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	int								m_nState;

	LONGLONG						m_llDocID;
	CString							m_strDocID;
	CString							m_strCurrentWndID;
	CString							m_strTemplateXml;
	CString							m_strMainFrameID;
	CString							m_strPath;

	ITangramAppProxy*				m_pAppProxy;
	CTangramDocWnd*					m_pActiveWnd;
	CTangramDocProxy*				m_pDocProxy;
	map<CString, CString>			m_mapWndScript;
	map<CString, CTangramDocFrame*> m_mapCompositor;

	void Lock() {}
	void Unlock() {}

protected:
	ULONG InternalAddRef() { return 1; }
	ULONG InternalRelease() { return 1; }

private:
	STDMETHOD(get_TemplateXml)(BSTR* bstrDocData);
	STDMETHOD(put_TemplateXml)(BSTR newVal);
	STDMETHOD(put_DocType)(BSTR newVal);
	STDMETHOD(get_DocID)(LONGLONG* pVal);
	STDMETHOD(put_DocID)(LONGLONG newVal);
	STDMETHOD(GetFrameWndXml)(BSTR bstrWndID, BSTR* bstrWndScriptVal);
};

class CTangramMDIChildWnd;
class ATL_NO_VTABLE CTangramDocTemplate :
	public CComObjectRootBase,
	public IDispatchImpl<ITangramDocTemplate, &IID_ITangramDocTemplate, &LIBID_Tangram, 1, 0>
{
public:
	CTangramDocTemplate();
	virtual ~CTangramDocTemplate();
	BEGIN_COM_MAP(CTangramDocTemplate)
		COM_INTERFACE_ENTRY(ITangramDocTemplate)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	CString							m_strKey;
	CString							m_strClientKey;
	CString							m_strDocTemplatePath;
	map<CString, CString>			m_mapXml;
	map<HWND, CWndNode*>			m_mapMainPageNode;
	map<HWND, CCompositor*>		m_mapConnectedFrame;
	map<HWND, CTangramMDIChildWnd*> m_mapTangramMDIChildWnd;

	void InitXmlData();
	bool SaveXmlData();

	void Lock() {}
	void Unlock() {}

protected:
	ULONG InternalAddRef() { return 1; }
	ULONG InternalRelease() { return 1; }

private:
	STDMETHOD(get_TemplateXml)(BSTR* bstrDocData);
	STDMETHOD(put_TemplateXml)(BSTR newVal);
	STDMETHOD(put_DocType)(BSTR newVal);
	STDMETHOD(get_DocID)(LONGLONG* pVal);
	STDMETHOD(put_DocID)(LONGLONG newVal);
	STDMETHOD(GetFrameWndXml)(BSTR bstrWndID, BSTR* bstrWndScriptVal);
};

class CTangramDocFrame
{
public:
	CTangramDocFrame();
	~CTangramDocFrame();

	CString							m_strWndID;
	CTangramDoc*					m_pTangramDoc;
	CTangramDocWnd*					m_pCurrentWnd;
	CCompositor*					m_pHostCompositor;

	map<HWND, CTangramDocWnd*>		m_mapWnd;
};

// CTangram
class ATL_NO_VTABLE CTangram :
	public CTangramImpl,
	public CComObjectRootBase,
	public IConnectionPointContainerImpl<CTangram>,
	public IConnectionPointImpl<CTangram, &__uuidof(_ITangram)>,
	public IDispatchImpl<ITangram, &IID_ITangram, &LIBID_Tangram, 1, 0>,
	public IPC::Broker,
	public IPC::EndPoint
{
	friend class CCompositor;
	friend class CEclipseWnd;
	friend class CTangramApp;
public:
	CTangram();
	virtual ~CTangram();

	int										m_nRef;
	int										m_nAppID;
	int 									launchMode;
	int 									m_nJVMVersion;

	int										m_nTangramObj;

#ifdef _DEBUG
	int										m_nJsObj;
	int										m_nTangram;
	int										m_nTangramCtrl;
	int										m_nTangramFrame;
	int										m_nOfficeDocs;
	int										m_nOfficeDocsSheet;
	int										m_nTangramNodeCommonData;
#endif
	HHOOK									m_hCBTHook;
	HHOOK									m_hForegroundIdleHook;
	TCHAR									m_szBuffer[MAX_PATH];

	LPCTSTR									m_lpszSplitterClass;

	CImageList								m_DocImageList;
	CImageList								m_DocTemplateImageList;

	//.NET Version 4: 
	ICLRRuntimeHost*						m_pClrHost;

	ChromePlus::CHtmlWnd*					m_pHtmlWndCreated;
	ChromePlus::CHtmlWnd*					m_pActiveHtmlWnd;

	CCompositor*							m_pDocTemplateFrame;
	CTangramDocWnd*							m_pActiveDocWnd;
	CTangramMDIMainWnd*						m_pMDIMainWnd;
	CTangramDocTemplate*					m_pActiveTemplate;
	CTangramMDIChildWnd*					m_pActiveMDIChildWnd;
	TangramDocTemplateInfo*					m_pTangramDocTemplateInfo;

	CWndNode*								m_pActiveNode;
	CWndNode*								m_pDesignRootNode;
	CWndNode*								m_pDesignWindowNode;
	CWndNode*								m_pHostDesignUINode;
	CCompositor*							m_pCompositor;
	CCompositor*							m_pDesignerFrame;
	CCompositor*							m_pDesigningFrame;
	CCompositorManager*						m_pCompositorManager;
	CCompositorManager*						m_pDesignerCompositorManager;

	CTangramAppCtrl*						m_pTangramAppCtrl;

	CTangramHtmlTreeWnd*					m_pDocDOMTree;
	CEclipseWnd*							m_pActiveEclipseWnd;

	Object::ObjectFactory*					m_pObjectFactory;

	map<HWND, ChromePlus::CHtmlWnd*>		m_mapHtmlWnd;
	map<HWND, ChromePlus::CBrowserWnd*>		m_mapBrowserWnd;
	map<CString, CString>					m_mapJavaNativeInfo;
	map<CString, CTangramDoc*>				m_mapOpenDoc;
	map<void*, IUnknown*>					m_mapObjects;
	map<HWND, CCompositor*>					m_mapBKFrame;
	map<HWND, CTangramDocWnd*>				m_mapMDTFrame;
	map<HWND, CCompositorManager*>			m_mapFramePage;
	map<HWND, CCompositorManager*>			m_mapWindowPage;
	map<IDispatch*, CString>				m_mapObjEventDic;
	map<HWND, CEclipseWnd*>					m_mapWorkBenchWnd;
	map<CString, CString>					m_mapCreatingWorkBenchInfo;

	map<LONGLONG, CTangramEventObj*>		m_mapTangramEvent;
	map<HWND, CTangramCommonCtrl*>			m_mapTangramCommonCtrl;
	vector<HWND>							m_vecEclipseHideTopWnd;
	map<HWND, CTangramMDIChildWnd*>			m_mapTangramMDIChildWnd;
	map<HWND, CTangramAFXHelperWnd*>		m_mapTangramAFXHelperWnd;
	map<CString, CRuntimeClass*>			m_TabWndClassInfoDictionary;
	map<CString, CHelperWnd*>				m_mapRemoteTangramHelperWnd;
	map<__int64, CWndNodeCollection*>		m_mapWndNodeCollection;
	//map<__int64, ChromePlus::IPCMsg*>		m_mapIPCCollection;
	BEGIN_COM_MAP(CTangram)
		COM_INTERFACE_ENTRY(ITangram)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CTangram)
		CONNECTION_POINT_ENTRY(__uuidof(_ITangram))
	END_CONNECTION_POINT_MAP()

	BEGIN_CATEGORY_MAP(CTangram)
		IMPLEMENTED_CATEGORY(CATID_SafeForInitializing)
		IMPLEMENTED_CATEGORY(CATID_SafeForScripting)
	END_CATEGORY_MAP()

	STDMETHOD(get_Application)(IDispatch** pVal);
	STDMETHOD(put_Application)(IDispatch* newVal);
	STDMETHOD(get_RootNodes)(IWndNodeCollection** pNodeColletion);
	STDMETHOD(get_CurrentActiveNode)(IWndNode** pVal);
	STDMETHOD(get_CreatingNode)(IWndNode** pVal);
	STDMETHOD(get_DesignNode)(IWndNode** pVal);
	STDMETHOD(get_AppExtender)(BSTR bstrKey, IDispatch** pVal);
	STDMETHOD(put_AppExtender)(BSTR bstrKey, IDispatch* newVal);
	STDMETHOD(get_AppKeyValue)(BSTR bstrKey, VARIANT* pVal);
	STDMETHOD(put_AppKeyValue)(BSTR bstrKey, VARIANT newVal);
	STDMETHOD(get_RemoteHelperHWND)(LONGLONG* pVal);
	STDMETHOD(put_RemoteHelperHWND)(LONGLONG newVal) { m_hHostWnd = (HWND)newVal; return S_OK; };
	STDMETHOD(get_TangramDoc)(LONGLONG AppProxy, LONGLONG nDocID, ITangramDoc** pVal);
	STDMETHOD(get_HostWnd)(LONGLONG* pVal);
	STDMETHOD(get_RemoteTangram)(BSTR bstrID, ITangram** pVal);
	STDMETHOD(get_Extender)(ITangramExtender** pVal);
	STDMETHOD(put_Extender)(ITangramExtender* newVal);
	STDMETHOD(get_DocTemplate)(BSTR bstrKey, LONGLONG* pVal);
	STDMETHOD(get_ActiveChromeBrowserWnd)(IChromeWebBrowser** ppChromeWebBrowser);
	STDMETHOD(get_HostChromeBrowserWnd)(IChromeWebBrowser** ppChromeWebBrowser);

	STDMETHOD(NavigateNode)(IWndNode* pNode, BSTR bstrObjID, BSTR bstrXnl);
	STDMETHOD(ActiveCLRMethod)(BSTR bstrObjID, BSTR bstrMethod, BSTR bstrParam, BSTR bstrData);
	STDMETHOD(AttachObjEvent)(IDispatch* pDisp, int nEventIndex);
	STDMETHOD(CreateOfficeDocument)(BSTR bstrXml);// { return S_OK; };
	STDMETHOD(CreateCLRObj)(BSTR bstrObjID, IDispatch** ppDisp);
	STDMETHOD(CreateCompositorManager)(LONGLONG hWnd, ICompositorManager** ppTangram);
	STDMETHOD(CreateTangramCtrl)(BSTR bstrAppID, ITangramCtrl** ppRetCtrl);
	STDMETHOD(CreateTangramEventObj)(ITangramEventObj** ppTangramEventObj);
	STDMETHOD(DownLoadFile)(BSTR strFileURL, BSTR bstrTargetFile, BSTR bstrActionXml);
	STDMETHOD(Encode)(BSTR bstrSRC, VARIANT_BOOL bEncode, BSTR* bstrRet);
	STDMETHOD(ExportOfficeObjXml)(IDispatch* OfficeObject, BSTR* bstrXml) { return S_OK; };
	STDMETHOD(FireTangramEventObj)(ITangramEventObj* pTangramEventObj);
	STDMETHOD(GetCompositor)(LONGLONG hHostWnd, ICompositor** ppCompositor);
	STDMETHOD(GetNodeFromHandle)(LONGLONG hWnd, IWndNode** ppRetNode);
	STDMETHOD(GetCtrlByName)(IDispatch* pCtrl, BSTR bstrName, VARIANT_BOOL bFindInChild, IDispatch** ppRetDisp);
	STDMETHOD(GetCtrlValueByName)(IDispatch* pCtrl, BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR* bstrVal);
	STDMETHOD(GetDocTemplateXml)(BSTR bstrCaption, BSTR bstrPath, BSTR bstrFilter, BSTR* bstrTemplatePath);
	STDMETHOD(GetWindowClientDefaultNode)(IDispatch* pAddDisp, LONGLONG hParent, BSTR bstrWndClsName, BSTR bstrCompositorManagerName, IWndNode** ppNode);
	STDMETHOD(GetItemText)(IWndNode* pNode, long nCtrlID, LONG nMaxLengeh, BSTR* bstrRet);
	STDMETHOD(GetCLRControl)(IDispatch* CtrlDisp, BSTR bstrNames, IDispatch** ppRetDisp);
	STDMETHOD(MessageBox)(LONGLONG hWnd, BSTR bstrContext, BSTR bstrCaption, long nStyle, int* nRet);
	STDMETHOD(NewGUID)(BSTR* retVal);
	STDMETHOD(StartApplication)(BSTR bstrAppID, BSTR bstrXml);
	STDMETHOD(SetCtrlValueByName)(IDispatch* pCtrl, BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR bstrVal);
	STDMETHOD(SetItemText)(IWndNode* pNode, long nCtrlID, BSTR bstrRet);
	STDMETHOD(SetHostFocus)(void);
	STDMETHOD(UpdateWndNode)(IWndNode* pNode);
	STDMETHOD(TangramGetObject)(IDispatch* SourceDisp, IDispatch** ResultDisp);
	STDMETHOD(TangramCommand)(IDispatch* RibbonControl) { return S_OK; };
	STDMETHOD(TangramGetImage)(BSTR strValue, IPictureDisp ** ppDispImage) { return S_OK; };
	STDMETHOD(TangramGetVisible)(IDispatch* RibbonControl, VARIANT* varVisible) { return S_OK; };
	STDMETHOD(TangramOnLoad)(IDispatch* RibbonControl) { return S_OK; };
	STDMETHOD(TangramGetItemCount)(IDispatch* RibbonControl, long* nCount) { return S_OK; };
	STDMETHOD(TangramGetItemLabel)(IDispatch* RibbonControl, long nIndex, BSTR* bstrLabel) { return S_OK; };
	STDMETHOD(TangramGetItemID)(IDispatch* RibbonControl, long nIndex, BSTR* bstrID) { return S_OK; };
	STDMETHOD(OpenCompositors)(LONGLONG hWnd, BSTR bstrFrames, BSTR bstrKey, BSTR bstrXml, VARIANT_BOOL bSave);
	STDMETHOD(DeletePage)(LONGLONG PageHandle);
	STDMETHOD(LoadDocComponent)(BSTR bstrLib, LONGLONG* llAppProxy);
	STDMETHOD(OpenTangramFile)(ITangramDoc** ppDoc);
	STDMETHOD(OpenTangramDocFile)(BSTR bstrFilePath, ITangramDoc** ppDoc);
	STDMETHOD(NewWorkBench)(BSTR bstrTangramDoc, IWorkBenchWindow** ppWorkBenchWindow);
	STDMETHOD(CreateOutLookObj)(BSTR bstrObjType, int nType, BSTR bstrURL, IDispatch** ppRetDisp);
	STDMETHOD(ClearHeader)();
	STDMETHOD(InitEclipseApp)();
	STDMETHOD(ReadTextFromWeb)(BSTR bstrURL, BSTR bstrOrg, BSTR bstrRepo, BSTR bstrBranch, BSTR bstrFile, BSTR bstrTarget, LONGLONG hNotify);
	STDMETHOD(DeleteFrame)(ICompositor* pCompositor);
	STDMETHOD(InitCLRApp)(BSTR strInitXml, LONGLONG* llHandle);

	void Init();
	void Lock() {}
	void Unlock() {}
	void TangramInit();
	void EclipseInit();
	void ExitInstance();
	void InitTangramDocManager();
	void InitDesignerTreeCtrl(CString strXml);
	void FireTangramAppEvent(CTangramEventObj*);
	void ExportComponentInfo();
	void CreateEclipseApp(CString strKey, CString strXml);
	int	 LoadCLR();
	bool ImportTangramDocTemplate(CString strFile);
	BOOL CopyFolder(CString strSrcPath, CString strDesPath);
	BOOL IsUserAdministrator();
	BOOL LoadImageFromResource(ATL::CImage *pImage, HMODULE hMod, CString strResID, LPCTSTR lpTyp);
	BOOL LoadImageFromResource(ATL::CImage *pImage, HMODULE hMod, UINT nResID, LPCTSTR lpTyp);
	BOOL InitJNIForTangram();
	CString ConfigJavaVMInfo(CString strOption);
	CString EncodeFileToBase64(CString strSRC);
	CString InitEclipse(_TCHAR* jarFile);
	CString ComputeHash(CString source);
	CString GetDesignerInfo(CString);
	CString GetXmlData(CString strName, CString strXml);
	CString GetDesignerData(CWndNode* pNode);
	CString GetDocTemplateXml(CString strCaption, CString strPath, CString strFilter);
	CString GetPropertyFromObject(IDispatch* pObj, CString strPropertyName);
	CString	BuildSipURICodeStr(CString strURI, CString strPrev, CString strFix, CString strData, int n1);
	CString	GetDataFromStr(CString strCoded, CString& strTime, CString strPrev, CString strFix, int n1);
	CString tangram_for_eclipse(CString strKey, CString strData, CString strFeatures);
	CString GetOfficePath();
	LRESULT Close(void);
	CWndNode* OpenEx(long hHostMainWnd, CString strExXml, CString strXTMLFile);
	TangramThreadInfo* GetThreadInfo(DWORD dwInfo = 0);

	// IPC message
	void DispatchToOtherBrokers(CString strChannel, CString strData) override;
	IPC::Broker* GetBroker() override;
	void OnIPCMessageReceived(CString strChannel, CString strData) override;

	virtual void CreateCommonDesignerToolBar();
	virtual void ProcessMsg(LPMSG lpMsg);
	virtual void OnOpenDoc(WPARAM) {};
	virtual void UpdateOfficeObj(IDispatch* pObj, CString strXml, CString strName) {};
	virtual void WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd) {};
	virtual void WindowDestroy(HWND hWnd) {};
	virtual HRESULT COMObjCreated(REFCLSID rclsid, LPVOID pv) { return 0; };
	virtual HRESULT RemoteObjCreated(CString strID, void** ppvObject) { return 0; };
	virtual void ConnectDocTemplate(LPCTSTR strType, LPCTSTR strExt, void* pTemplate);
	virtual ITangramDoc* ConnectTangramDoc(ITangramAppProxy* AppProxy, LONGLONG docID, HWND hView, HWND hFrame, LPCTSTR strDocType);
	void Log(CString strMessage) override;
	void SetOverlayIcon(HWND hwnd, HICON hIcon, CString alt_text);
	ICompositor* ConnectCompositorManager(HWND, CString, ICompositorManager* pCompositorManager, CompositorInfo*);

	void _addObject(void* pThis, IUnknown* pUnknown)
	{
		m_mapObjects.insert(make_pair(pThis, pUnknown));
	}

	void _removeObject(void* pThis)
	{
		auto it = m_mapObjects.find(pThis);
		if (it != m_mapObjects.end())
		{
			m_mapObjects.erase(it);
		}
	}

	void _clearObjects()
	{
		map<void*, IUnknown*>::iterator it;
		while ((it = m_mapObjects.begin()) != m_mapObjects.end())
		{
			IUnknown* pUnknown = it->second;
			CCommonFunction::ClearObject<IUnknown>(pUnknown);
			m_mapObjects.erase(it);
		}
	}

	CString GetNewGUID();

protected:
	CString	m_strDefaultTemplateXml;
	ULONG InternalAddRef() { return 1; }
	ULONG InternalRelease();

private:
	CString								m_strOfficeAppIDs;
	CString								m_strExcludeAppExtenderIDs;
	CWindow								m_HelperWnd;
	CComObject<CWndNodeCollection>*		m_pRootNodes;
	map<DWORD, TangramThreadInfo*>		m_mapThreadInfo;

	void TangramLoad();
	bool CheckUrl(CString&   url);
	void AttachNode(void* pNodeEvents);
	CString Encode(CString strSRC, BOOL bEnCode);
	CString GetNewLayoutNodeName(BSTR strCnnID, IWndNode* pDesignNode);
	ICompositorManager* Open(HWND, CString strName, CString strKey);
	IWndNode* OpenCtrl(__int64 handle, CString name, CString NodeTag);
	void BrowserAppStart();
	bool IsMDIClientCompositorNode(IWndNode*);
	void BindObjectToWindow(IDispatch* pDisp, HWND hWnd, CString strXml);
	void BindObjectToWindow(CString objID, CString AssemblyQualifiedName, HWND hWnd, CString strXml);
	int CalculateByteMD5(BYTE* pBuffer, int BufferSize, CString &MD5);
	void FireNodeEvent(int nIndex, CWndNode* pNode, CTangramEventObj* pObj);
	void GetTangramInfo(CString strFile, TangramDocInfo*);

	CString RemoveUTF8BOM(CString strUTF8);

	void OnUpdateBookmarkBarState();
	void ChromeTabCreated(CChromeTab* pTab);
	void OnRenderProcessCreated(CChromeRenderProcess* pProcess);
	void OnDocumentOnLoadCompleted(CChromeRenderFrameHostBase*, HWND hHtmlWnd, void*);
	void ChromeChildProcessCreated(CChromeChildProcessHostImpl*	pChromeChildProcessHostImpl);
	void OnSubBrowserWndCreated(HWND hParent, HWND hBrowser);
	CString GetProcessPath(const char* _ver, CString process_type);
	CString GetSchemeBaseName();
	HICON GetAppIcon(int nIndex);
	CChromeBrowserBase* GetChromeBrowserBase(HWND);
};
