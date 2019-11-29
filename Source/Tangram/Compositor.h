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
#include "chromium/BrowserWnd.h"
#include "chromium/HtmlWnd.h"
#include "IPC/Broker.h"

using namespace ChromePlus;

#define WM_TANGRAMNOTIFY WM_NOTIFY+WM_REFLECT_BASE
class CTangramCommonCtrl :
	public CWindowImpl<CTangramCommonCtrl, CWindow>
{
public:
	CTangramCommonCtrl(void);
	virtual ~CTangramCommonCtrl(void);
	BEGIN_MSG_MAP(CTangramCommonCtrl)
		MESSAGE_HANDLER(WM_NOTIFY, OnNotify)
	END_MSG_MAP()
	virtual void OnFinalMessage(HWND hWnd);
	LRESULT OnNotify(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};

class CTangramAFXHelperWnd :
	public CWindowImpl<CTangramAFXHelperWnd, CWindow>
{
public:
	CTangramAFXHelperWnd(void);
	virtual ~CTangramAFXHelperWnd(void);
	HWND m_hFrame;
	HWND m_hParent;
	BEGIN_MSG_MAP(CTangramAFXHelperWnd)
		MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
		MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMg)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGED, OnWindowPosChanging)
	END_MSG_MAP()

private:
	void OnFinalMessage(HWND hWnd);
	LRESULT OnShowWindow(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnTangramMg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWindowPosChanging(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};

class CTangramDocTemplate;
class CTangramMDIChildWnd;
class CTangramMDIMainWnd :
	public CWindowImpl<CTangramMDIMainWnd, CWindow>
{
public:
	CTangramMDIMainWnd(void);
	virtual ~CTangramMDIMainWnd(void);

	HWND									m_hMDIClient;
	CCompositorManager*								m_pCompositorManager;
	CTangramDocTemplate*					m_pDocTemplate;
	map<HWND, CString>						m_mapDesignableWnd;
	map<CString, CTangramDocTemplate*>		m_mapTangramDocTemplate;
	BEGIN_MSG_MAP(CTangramMDIMainWnd)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_CONTROLBARCREATED, OnControlBarCreated)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanging)
	END_MSG_MAP()
	
	void OnFinalMessage(HWND hWnd);

	void OnCreateDoc(CString strDocData);
	void NavigateKey(CString strKey);
	LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnCommand(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	LRESULT OnControlBarCreated(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	LRESULT OnWindowPosChanging(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};

class CTangramMDIChildWnd :
	public CWindowImpl<CTangramMDIChildWnd, CWindow>
{
public:
	CTangramMDIChildWnd(void);
	virtual ~CTangramMDIChildWnd(void);
	BOOL				m_bNoDocView;
	HWND				m_hChild;

	CString				m_strCaption;
	CString				m_strTemplatePath;
	CString				m_strXml;
	CCompositor*			m_pCompositor;
	map<HWND, CString> m_mapDesignableWnd;

	CTangramDocTemplate* m_pDocTemplate;
	BEGIN_MSG_MAP(CTangramMDIChildWnd)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
		MESSAGE_HANDLER(WM_DPICHANGED, OnDpiChanged)
		MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
		MESSAGE_HANDLER(WM_MDIACTIVATE, OnMDIActivate)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanged)
		MESSAGE_HANDLER(WM_CONTROLBARCREATED, OnControlBarCreated)
	END_MSG_MAP()

	void OnCreateDoc(CString strDocData);
private:
	LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnCommand(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnActivate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnMDIActivate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnDpiChanged(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	LRESULT OnTangramMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnWindowPosChanged(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	LRESULT OnControlBarCreated(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	void OnFinalMessage(HWND hWnd);
};

class CTangramWinFormWnd :
	public CWindowImpl<CTangramWinFormWnd, CWindow>
{
public:
	CTangramWinFormWnd(void);
	virtual ~CTangramWinFormWnd(void);
	int										m_nState;
	BOOL									m_bMdiForm;
	CString									m_strKey;
	CString									m_strXml;
	CString									m_strPath;
	CString									m_strChildFormPath;
	
	CMDIChildFormInfo*						m_pChildFormsInfo;

	map<CString, CString>					m_mapKey;
	map<CString, TangramDocTemplateInfo*>	m_mapTangramFormsTemplateInfo;
	map<int, TangramDocTemplateInfo*>		m_mapTangramFormsTemplateInfo2;
	BEGIN_MSG_MAP(CTangramWinFormWnd)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
		MESSAGE_HANDLER(WM_TANGRAMDATA, OnGetMe)
		MESSAGE_HANDLER(WM_WINFORMCREATED, OnFormCreated)
		MESSAGE_HANDLER(WM_TANGRAMGETXML, OnTangramGetXml)
	END_MSG_MAP()

	void OnFinalMessage(HWND hWnd);

private:
	LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnGetMe(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnFormCreated(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnTangramMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
	LRESULT OnTangramGetXml(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL&);
};

class CTangramDocWnd :
	public CWindowImpl<CTangramDocWnd, CWindow>
{
public:
	CTangramDocWnd(void);
	virtual ~CTangramDocWnd(void);

	HWND m_hView;
	CString	m_strKey;
	CString m_strWndID;
	CCompositor* m_pCompositor;
	CCompositorManager* m_pParentPage;
	CTangramDocFrame* m_pDocFrame;

	map<CString, HWND> m_mapCtrlBar;
	BEGIN_MSG_MAP(CTangramDocWnd)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
		MESSAGE_HANDLER(WM_TANGRAMGETXML, OnTangramGetXml)
		MESSAGE_HANDLER(WM_CONTROLBARCREATED, OnCtrlBarCreated)
	END_MSG_MAP()

	void OnFinalMessage(HWND hWnd);

private:
	void CtrlBarDocActiveNotify(ITangramDoc* pDoc, IWndNode* pNodeInDoc, IWndNode* pNodeInCtrlBar, HWND hCtrlBar);
	LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnCommand(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnTangramMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnTangramGetXml(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnCtrlBarCreated(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
};

class ATL_NO_VTABLE CCompositor : 
	public CComObjectRootBase,	
	public CWindowImpl<CCompositor, CWindow>,
	public IDispatchImpl<ICompositor, &IID_ICompositor>,
	public IPC::Broker
{
public:
	CCompositor();           
	virtual ~CCompositor();           

	BOOL											m_bTabbedMDIClient;
	BOOL											m_bDetached;
	BOOL											m_bDesignerState;
	BOOL											m_bMDIChild;
	BOOL											m_bChromeFrame;
	CompositorType									m_nCompositorType;

	HWND											m_hPWnd;
	HWND											m_hHostWnd;
	CString											m_strLastKey;
	CString											m_strAsynKeys;
	CString											m_strCompositorName;
	CString											m_strCurrentKey;
	CString											m_strCurrentXml;
	CEclipseWnd*									m_pWorkBenchFrame;
	CTangramDocTemplate*							m_pTangramDocTemplate;
	map<ITangramAppProxy*, CCompositorProxy*>		m_mapCompositorProxy;

	ChromePlus::CHtmlWnd*							m_pWebWnd;
	CBKWnd*											m_pBKWnd;
	CCompositorManager*								m_pCompositorManager;
	CWndNode*										m_pParentNode;
	CWndNode*										m_pWorkNode;
	CWndNode*										m_pContainerNode;
	CWndNode*										m_pBindingNode;
	CCompositor*									m_pSubCompositor;
	CompositorInfo*									m_pCompositorInfo;
	CTangramEventObj*								m_pInitEventObj;
	CTangramDoc*									m_pDoc;
	map<CString, CWndNode*>							m_mapNode;
	map<CString, CWndNode*>							m_mapNeedSaveToConfigNode;
	map<CString, VARIANT>							m_mapVal;
	map<HWND, CWPFView*>							m_mapWPFView;
	map<HWND, CWPFView*>							m_mapVisibleWPFView;
	map<CString, CWndNode*>							m_mapNodeScript;
	CComObject<CWndNodeCollection>*					m_pRootNodes;

	void Lock(){}
	void Unlock(){}
	void Destroy();
	void HostPosChanged();
	void UpdateDesignerTreeInfo();
	void CreateBKWnd();
	void UpdateVisualWPFMap(HWND, BOOL);

	CTangramXmlParse* UpdateWndNode();
	BOOL CreateCompositorManager();
	CWndNode* OpenXtmlDocument(CTangramXmlParse* pParse, CString strKey, CString	strFile);

	void DispatchToOtherBrokers(CString strChannel, CString strData) override;

	STDMETHOD(get_CompositorXML)(BSTR* pVal);
	STDMETHOD(ModifyHost)(LONGLONG hHostWnd);
	STDMETHOD(Open)(BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode);
	STDMETHOD(GetXml)(BSTR bstrRootName, BSTR* bstrRet);

	BEGIN_COM_MAP(CCompositor)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ICompositor)
	END_COM_MAP()

	BEGIN_MSG_MAP(CCompositor)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_HSCROLL, OnHScroll)
		MESSAGE_HANDLER(WM_VSCROLL, OnHScroll)
		MESSAGE_HANDLER(WM_TANGRAMDATA, OnGetMe)
		MESSAGE_HANDLER(WM_NCDESTROY, OnNcDestroy)
		MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
		MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
		MESSAGE_HANDLER(WM_PARENTNOTIFY, OnParentNotify)
		MESSAGE_HANDLER(WM_MOUSEACTIVATE, OnMouseActivate)
		MESSAGE_HANDLER(WM_QUERYAPPPROXY, OnQueryAppProxy)
		MESSAGE_HANDLER(WM_TANGRAMACTIVEPAGE, OnTabChanged)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanging)
	END_MSG_MAP()

protected:
	ULONG InternalAddRef(){ return 1; }
	ULONG InternalRelease(){ return 1; }

private:
	LRESULT OnGetMe(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnHScroll(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnNcDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnTabChanged(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnTangramMsg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnShowWindow(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnParentNotify(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnMouseActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnQueryAppProxy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWindowPosChanging(UINT, WPARAM, LPARAM, BOOL&);

	STDMETHOD(get_Count)(long* pCount);
	STDMETHOD(get_WndNode)(VARIANT vIndex, IWndNode **ppNode);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	STDMETHOD(get_HWND)(LONGLONG* pVal);
	STDMETHOD(get_CompositorManager)(ICompositorManager** pVal);
	STDMETHOD(get_CurrentNavigateKey)(BSTR* pVal);
	STDMETHOD(get_VisibleNode)(IWndNode** pVal);
	STDMETHOD(get_RootNodes)(IWndNodeCollection** pNodeColletion);
	STDMETHOD(get_CompositorData)(BSTR bstrKey, VARIANT* pVal);
	STDMETHOD(put_CompositorData)(BSTR bstrKey, VARIANT newVal);
	STDMETHOD(get_DesignerState)(VARIANT_BOOL* pVal);
	STDMETHOD(put_DesignerState)(VARIANT_BOOL newVal);
	STDMETHOD(get_TangramDoc)(ITangramDoc** pVal);
	STDMETHOD(get_CompositorType)(CompositorType* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_HostBrowser)(IChromeWebBrowser** ppChromeWebBrowser);

	STDMETHOD(Attach)(void);
	STDMETHOD(Detach)(void);
	STDMETHOD(OpenFromWeb)(BSTR bstrURLBase, BSTR bstrKey, BSTR bstrOrg, BSTR bstrRepo, BSTR bstrBranch, BSTR bstrPath);
	STDMETHOD(SendIPCMessage)(int MessageType, BSTR bstrMessage, BSTR bstrMessageData);

	void OnFinalMessage(HWND hWnd);
};
