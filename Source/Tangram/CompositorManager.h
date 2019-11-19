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

// CompositorManager.h : CCompositorManager implementation file

#pragma once

#include <assert.h>
#include <wininet.h>

#include "EclipsePlus\EclipseAddin.h"
#include "IPC\Broker.h"
#include "IPC\EndPoint.h"

// CCompositorManager
class ATL_NO_VTABLE CCompositorManager : 
	public CComObjectRootBase,
	public IDispatchImpl<ICompositorManager, &IID_ICompositorManager>,
	public IConnectionPointContainerImpl <CCompositorManager>,
	public IConnectionPointImpl<CCompositorManager, &__uuidof(_ITangramObjEvents)>,
	public IPC::Broker
{
	friend CTangram;
public:
	CCompositorManager();
	virtual ~CCompositorManager();

	BOOL										m_bDoc;
	BOOL										m_bNewVersion;
	BOOL										m_bPageDataLoaded;
	HWND										m_hWnd;

	CString										m_strPageFilePath;
	CString										m_strPageFileName;
	CString										m_strConfigFileNodeName;
	CString										m_strXmlHeader;
	CString										m_strXmlBottom;

	CCompositor*								m_pBKFrame;
	CTangramDoc*								m_pActiveDoc;
	ITangramAppProxy*							m_pTangramAppProxy;
	CTangramDocTemplate*						m_pTangramDocTemplate;
	map<CString, CString>						m_strMapKey;
	map<HWND, CCompositor*>						m_mapCtrlBarCompositor;
	map<CString, HWND>							m_mapWnd;
	map<HWND, CCompositor*>						m_mapCompositor;
	map<HWND, CCompositor*>						m_mapNeedSaveCompositor;
	map<CString, CWndNode*>						m_mapNode;
	map<CString, IDispatch*>					m_mapExternalObj;
	map<HWND, CEclipseCtrl*>					m_mapNotifyCtrl;
	map<CString, CString>						m_mapXtml;
	map<__int64, CTangramEventObj*>				m_mapEventObj;
	map<ITangramAppProxy*, CCompositorManagerProxy*> m_mapCompositorManagerProxy;

	BEGIN_COM_MAP(CCompositorManager)
		COM_INTERFACE_ENTRY(ICompositorManager)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CCompositorManager)
		CONNECTION_POINT_ENTRY(__uuidof(_ITangramObjEvents))
	END_CONNECTION_POINT_MAP()

	void Lock(){}
	void Unlock(){}
	void BeforeDestory();
	void UpdateMapKey(CString);
	HRESULT Fire_CompositorManagerLoaded(IDispatch* sender, BSTR url);
	HRESULT Fire_NodeCreated(IWndNode * pNodeCreated);
	HRESULT Fire_AddInCreated(IWndNode * pRootNode, IDispatch * pAddIn, BSTR bstrID, BSTR bstrAddInXml);
	HRESULT Fire_BeforeOpenXml(BSTR bstrXml, LONGLONG hWnd);
	HRESULT Fire_OpenXmlComplete(BSTR bstrXml, LONGLONG hWnd, IWndNode * pRetRootNode);
	HRESULT Fire_Destroy();
	HRESULT Fire_NodeMouseActivate(IWndNode * pActiveNode);
	HRESULT Fire_ClrControlCreated(IWndNode * Node, IDispatch * Ctrl, BSTR CtrlName, LONGLONG CtrlHandle);
	HRESULT Fire_TabChange(IWndNode* sender, LONG ActivePage, LONG OldPage);
	HRESULT Fire_TangramEvent(ITangramEventObj* pEventObj);
	HRESULT Fire_IPCMsg(ICompositor* pSender, BSTR bstrType, BSTR bstrContent, BSTR bstrFeature);

	void OnNodeDocComplete(WPARAM);

	// IPC message
	void DispatchToOtherBrokers(CString strChannel, CString strData) override;

protected:
	ULONG InternalAddRef(){ return 1; }
	ULONG InternalRelease(){ return 1; }

public:
	STDMETHOD(get_Count)(long* pCount);
	STDMETHOD(get_Compositor)(VARIANT vIndex, ICompositor ** ppCompositor);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	STDMETHOD(get_Handle)(LONGLONG* pVal);
	STDMETHOD(get_Extender)(BSTR bstrExtenderName, IDispatch** pVal);
	STDMETHOD(put_Extender)(BSTR bstrExtenderName, IDispatch* newVal);
	STDMETHOD(get_CompositorName)(LONGLONG hHwnd, BSTR* pVal);
	STDMETHOD(get_Node)(BSTR bstrNodeName, IWndNode** pVal);
	STDMETHOD(get_NodeNames)(BSTR* pVal);
	STDMETHOD(get_XObject)(BSTR bstrName, IDispatch** pVal);
	STDMETHOD(get_Parent)(ICompositorManager** pVal);
	STDMETHOD(get_Width)(long* pVal);
	STDMETHOD(put_Width)(long newVal);
	STDMETHOD(get_Height)(long* pVal);
	STDMETHOD(put_Height)(long newVal);
	STDMETHOD(get_xtml)(BSTR strKey, BSTR* pVal);
	STDMETHOD(put_xtml)(BSTR strKey, BSTR newVal);
	STDMETHOD(get_CompositorManagerXML)(BSTR* pVal);
	STDMETHOD(put_ConfigName)(BSTR newVal);
	STDMETHOD(get_NewVersion)(VARIANT_BOOL* bNewVersion);
	STDMETHOD(put_NewVersion)(VARIANT_BOOL bNewVersion);

	STDMETHOD(CreateCompositor)(VARIANT ParentObj, VARIANT HostWnd, BSTR bstrFrameName, ICompositor** pRetFrame);
	STDMETHOD(GetWndNode)(BSTR bstrFrameName, BSTR bstrNodeName, IWndNode** pRetNode);
	STDMETHOD(GetCompositorFromCtrl)(IDispatch* ctrl, ICompositor** ppCompositor);
	STDMETHOD(GetCtrlInNode)(BSTR NodeName, BSTR CtrlName, IDispatch** ppCtrl);
	STDMETHOD(Open)(IDispatch* Parent, BSTR CtrlName, BSTR FrameName, BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode);
	STDMETHOD(OpenCtrl)(VARIANT MdiForm, BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode);
	STDMETHOD(ConnectTangramCtrl)(ITangramCtrl* eventSource);
	STDMETHOD(CreateCompositorWithDefaultNode)(ULONGLONG hFrameWnd, BSTR bstrFrameName, BSTR bstrDefaultNodeKey, BSTR bstrXml, VARIANT_BOOL bSaveToConfig, IWndNode** ppNode);
	STDMETHOD(OpenCompositors)(BSTR bstrFrames, BSTR bstrKey, BSTR bstrXml, VARIANT_BOOL bSaveToConfigFile);
	STDMETHOD(get_CurrentDesignCompositorType)(CompositorType* pVal);
	STDMETHOD(get_CurrentDesignNode)(IWndNode** pVal);

private:
	bool										m_bIsBlank;
	bool										m_bIsDestory;
	bool										m_bDocComplete;
};

