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
#include <jni.h>
#include "../TangramCore.h"
#include "../TangramCtrl.h"
#include "tangrambase.h"

class CEclipseWnd;
class CEclipseCtrl;

class ATL_NO_VTABLE CEclipseExtender :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IEclipseExtender, &IID_IEclipseExtender, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEclipseExtender(void);
	virtual ~CEclipseExtender(void);

	BEGIN_COM_MAP(CEclipseExtender)
		COM_INTERFACE_ENTRY(IEclipseExtender)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	STDMETHOD(Close)();
	STDMETHOD(get_ActiveWorkBenchWindow)(BSTR bstrID, IWorkBenchWindow** pVal);
};

class ATL_NO_VTABLE CEclipseWnd :
	public CWindowImpl<CEclipseWnd, CWindow>,
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IWorkBenchWindow, &IID_IWorkBenchWindow, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEclipseWnd(void);
	virtual ~CEclipseWnd(void);
	BOOL							m_bInit;
	int								m_nNewWinCmdID;
	HWND							m_hClient;
	CString							m_strAppProxyID;
	CString							m_strDocKey;
	CString							m_strXml;
	CString							m_strPath;
	CString							m_strFrameID;
	CString							m_strNodeName;
	CCompositorManager*			m_pCompositorManager;
	CWndNode*						m_pCurNode;
	CWndNode*						m_pHostNode;
	CCompositor*					m_pCompositor;
	map<HWND, CEclipseCtrl*>		m_mapCtrl;
	CTangramDoc*					m_pDoc;
	ITangramAppProxy*				m_pAppProxy;
	void Show(CString strID);
	BEGIN_COM_MAP(CEclipseWnd)
		COM_INTERFACE_ENTRY(IWorkBenchWindow)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	BEGIN_MSG_MAP(CEclipseWnd)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
		MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
		MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
		MESSAGE_HANDLER(WM_QUERYAPPPROXY, OnQueryAppProxy)
		MESSAGE_HANDLER(WM_TANGRAMGETXML, OnTangramGetXml)
	END_MSG_MAP()
protected:
	ULONG InternalAddRef() { return 1; }
	ULONG InternalRelease() { return 1; }

	LRESULT OnCommand(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnClose(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnQueryAppProxy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnActivate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnShowWindow(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnTangramMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnTangramGetXml(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );

	void OnFinalMessage(HWND hWnd);

	STDMETHOD(get_Count)(long* pCount);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	STDMETHOD(get_Handle)(LONGLONG* pVal);
	STDMETHOD(get_TangramCtrl)(LONGLONG hWnd, IEclipseCtrl** pVal);
	STDMETHOD(get_CompositorManager)(ICompositorManager** pVal);
	STDMETHOD(get_Compositor)(ICompositor** pVal);
	STDMETHOD(Active)();
	STDMETHOD(CloseTangramUI)();
	STDMETHOD(OpenEx)(BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode);
	STDMETHOD(OpenInView)(int nIndex, BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode);

public:
	STDMETHOD(get_Ctrl)(VARIANT vIndex, IEclipseCtrl **ppCtrl);
	STDMETHOD(Open)(BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode);
	void CreatePage(BOOL bSaveToConfigFile);
};
//
//class CEclipseClient :
//	public CWindowImpl<CEclipseClient, CWindow>
//{
//public:
//	CEclipseClient(void);
//	virtual ~CEclipseClient(void);
//	BOOL m_bInit;
//	CEclipseWnd* m_pParent;
//	BEGIN_MSG_MAP(CEclipseClient)
//		//MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanging)
//	END_MSG_MAP()
//
//private:
//	void OnFinalMessage(HWND hWnd);
//	//LRESULT OnWindowPosChanging(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
//};

// CEclipseCtrl
class ATL_NO_VTABLE CEclipseCtrl :
	public CTangramCtrlBase,
	public IOleObjectImpl<CEclipseCtrl>,
	public IPersistStorageImpl<CEclipseCtrl>,
	public IPersistStreamInitImpl<CEclipseCtrl>,
	public IConnectionPointContainerImpl<CEclipseCtrl>,
	public CComCoClass<CEclipseCtrl, &CLSID_TangramCtrl>,
	public IConnectionPointImpl<CEclipseCtrl, &DIID__ITangramObjEvents>,
	public IDispatchImpl<IEclipseCtrl, &IID_IEclipseCtrl, &LIBID_Tangram, 1, 0>
{
public:
	HWND						m_hEclipseViewWnd;
	VARIANT						m_varTag;
	CWndNode*					m_pCurNode;
	map<CString, CString>		m_mapTangramInfo;
	map<CString, HWND>			m_mapTangramHandle;
	map<CString, CCompositor*>	m_mapCompositor;

	CEclipseWnd*				m_pEclipseWnd;
	CCompositorManagerProxy*	m_pCompositorManagerProxy;

	CEclipseCtrl();

	BEGIN_COM_MAP(CEclipseCtrl)
		COM_INTERFACE_ENTRY(IEclipseCtrl)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IOleObject)
		COM_INTERFACE_ENTRY(IViewObject)
		COM_INTERFACE_ENTRY(IViewObject2)
		COM_INTERFACE_ENTRY(IOleInPlaceObject)
		COM_INTERFACE_ENTRY(IPersistStorage)
		COM_INTERFACE_ENTRY(IPersistStreamInit)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CEclipseCtrl)
		CONNECTION_POINT_ENTRY(DIID__ITangramObjEvents)
	END_CONNECTION_POINT_MAP()

	HRESULT FinalConstruct();
	void OnFinalMessage(HWND hWnd);

public:
	BEGIN_MSG_MAP(CEclipseCtrl)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
	END_MSG_MAP()

	HRESULT Fire_CompositorManagerLoaded(IDispatch* sender, BSTR url);
	HRESULT Fire_NodeCreated(IWndNode * pNodeCreated);
	HRESULT Fire_AddInCreated(IWndNode * pRootNode, IDispatch * pAddIn, BSTR bstrID, BSTR bstrAddInXml);
	HRESULT Fire_BeforeOpenXml(BSTR bstrXml, LONGLONG hWnd);
	HRESULT Fire_OpenXmlComplete(BSTR bstrXml, LONGLONG hWnd, IWndNode * pRetRootNode);
	HRESULT Fire_Destroy();
	HRESULT Fire_NodeMouseActivate(IWndNode * pActiveNode);
	HRESULT Fire_ClrControlCreated(IWndNode * Node, IDispatch * Ctrl, BSTR CtrlName, LONGLONG CtrlHandle);
	HRESULT Fire_TabChange(IWndNode* sender, LONG ActivePage, LONG OldPage);
	HRESULT Fire_Event(IWndNode* sender, IDispatch* EventArg);
	HRESULT Fire_ControlNotify(IWndNode * sender, LONG NotifyCode, LONG CtrlID, LONGLONG CtrlHandle, BSTR CtrlClassName);
	HRESULT Fire_TangramEvent(ITangramEventObj* pEventObj);

	// IEclipseCtrl
	STDMETHOD(get_tag)(VARIANT* pVal);
	STDMETHOD(put_tag)(VARIANT newVal);
	STDMETHOD(get_HWND)(LONGLONG* pVal);
	STDMETHOD(put_TangramHandle)(BSTR bstrHandleName, LONGLONG newVal);
	STDMETHOD(get_Tangram)(ITangram** pVal);
	STDMETHOD(get_EclipseViewHandle)(LONGLONG* pVal);
	STDMETHOD(get_CompositorManager)(ICompositorManager** pVal);
	STDMETHOD(get_WorkBenchWindow)(IWorkBenchWindow** pVal);
	STDMETHOD(get_TopCompositor)(ICompositor** pVal);
	STDMETHOD(get_TopCompositorManager)(ICompositorManager** pVal);
	STDMETHOD(get_ActiveTopNode)(IWndNode** pVal);
	STDMETHOD(get_AppKeyValue)(BSTR bstrKey, VARIANT* pVal);
	STDMETHOD(put_AppKeyValue)(BSTR bstrKey, VARIANT newVal);

	STDMETHOD(Open)(BSTR bstrFrameName, BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode);
	STDMETHOD(OpenEx)(BSTR bstrFrameName, BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode);
	STDMETHOD(InitCtrl)(BSTR bstrXml);

private:
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
	LRESULT OnTangramMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& );
};

