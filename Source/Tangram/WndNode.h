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


// WndNode.h : Declaration of the CWndNode

#include "browser.h"
#include "CompositorManager.h"
#include "chromium/BrowserWnd.h"
#include "IPC/EndPoint.h"
#include "Object/RefCoreObject.h"

#pragma once

class CTangramNodeCommonData
{
public:
	CTangramNodeCommonData();
	~CTangramNodeCommonData();

	CCompositor*						m_pCompositor;
	CCompositor*						m_pOldCompositor;
	IDispatch*							m_pOfficeObj;
	CNodeWnd*							m_pHostClientView;
	CTangramXmlParse*					m_pTangramParse;
	CCompositorManager*					m_pCompositorManager;
	map<CString, CWndNode*>				m_mapLayoutNodes;
	map<CString, CWndNode*>				m_mapAxNodes;
	map<CString, CWndNode*>				m_mapCLRNodes;
	map<CString, CWndNode*>				m_mapCppNodes;
	CMapStringToPtr						m_PlugInDispDictionary;
};

// CWndNode 
class ATL_NO_VTABLE CWndNode : 
	public CComObjectRootBase,
	public IDispatchImpl<IWndNode, &IID_IWndNode>,
	public IConnectionPointContainerImpl<CWndNode>,
	public IConnectionPointImpl<CWndNode, &__uuidof(_IWndNodeEvents)>,
	public IPC::EndPoint,
	public Object::RefCoreObject
{
public:
	CWndNode();
	virtual ~CWndNode();

	BOOL								m_bTopObj;
	BOOL								m_bCreated;
	BOOL								m_bWebInit;
	BOOL								m_bNodeDocComplete;

	TangramViewType						m_nViewType;
	int									m_nID;
	int									m_nActivePage;
	int									m_nWidth;
	int									m_nHeigh;
	int									m_nRow;
	int									m_nCol;
	int									m_nRows;
	int									m_nCols;
	HWND								m_hHostWnd;
	HWND								m_hChildHostWnd;

	CString 							m_strID;
	CString 							m_strURL;
	CString								m_strKey;
	CString								m_strName;
	CString 							m_strCnnID;
	CString 							m_strCaption;
	CString 							m_strXmlFileFromVS;

	CString								m_strNodeName;
	CString 							m_strExtenderID;

	IDispatch*							m_pDisp;
	CWndNode* 							m_pRootObj;
	CWndNode* 							m_pParentObj;
	CWndNode*							m_pVisibleXMLObj;
	CTangramXmlParse*					m_pHostParse;
	CTangramXmlParse* 					m_pDocXmlParseNode;

	ITangramWindow*						m_pTangramWindow;
	CMDIChildFormInfo*					m_pChildFormsInfo;
	CTangramNodeCommonData*				m_pTangramNodeCommonData;
	ChromePlus::CBrowserWnd*			m_pWebBrowser;
	CWnd*								m_pHostWnd;
	CCompositor*						m_pHostCompositor;
	CRuntimeClass*						m_pObjClsInfo;

	CWndNodeEvents*						m_pCLREventConnector;

	VARIANT								m_varTag;
	IDispatch*							m_pExtender;
	IVSDocument*						m_pVSDocument;
	CTangramNodeVector					m_vChildNodes;
	CWndNode*							m_pCurrentExNode;
	map<CString, CCompositor*>			m_mapSubFrame;
	map<CWndNode*, CString>				m_mapExtendNode;
	CComObject<CWndNodeCollection>*		m_pChildNodeCollection;

	map<ITangramAppProxy*, CTangramWndNodeProxy*> m_mapWndNodeProxy;

	void	InitWndNode();
	BOOL	Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext);
	BOOL	PreTranslateMessage(MSG* pMsg);
	BOOL	AddChildNode(CWndNode* pNode);
	BOOL	RemoveChildNode(CWndNode* pNode);
	CString GetNames();
	ChromePlus::CHtmlWnd* GetHtmlWnd();

	// RefCoreObject
	CString GetRefCoreObjectName() override;

	// IPC message
	IPC::Broker* GetBroker() override;
	void OnIPCMessageReceived(CString strChannel, CString strData) override;

	HRESULT Fire_OpenComplete();
	HRESULT Fire_Destroy();
	HRESULT Fire_NodeAddInCreated(IDispatch * pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml);
	HRESULT Fire_NodeAddInsCreated();
	HRESULT Fire_NodeDocumentComplete(IDispatch * ExtenderDisp, BSTR bstrURL);
	HRESULT Fire_ControlNotify(IWndNode * sender, LONG NotifyCode, LONG CtrlID, LONGLONG CtrlHandle, BSTR CtrlClassName);
	HRESULT Fire_TabChange(LONG ActivePage, LONG OldPage);
	HRESULT Fire_IPCMessageReceived(BSTR bstrChannel, BSTR bstrData);

	void Lock(){}
	void Unlock(){}
protected:
	ULONG InternalAddRef(){ return 1; }
	ULONG InternalRelease(){ return 1; }

public:
	STDMETHOD(get_XObject)(VARIANT* pVar);
	STDMETHOD(get_Tag)(VARIANT* pVar);
	STDMETHOD(put_Tag)(VARIANT var);
	STDMETHOD(get_AxPlugIn)(BSTR bstrName, IDispatch** pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(put_Name)(BSTR bstrName);
	STDMETHOD(get_Caption)(BSTR* pVal);
	STDMETHOD(put_Caption)(BSTR bstrCaption);
	STDMETHOD(get_Attribute)(BSTR bstrKey, BSTR* pVal);
	STDMETHOD(put_Attribute)(BSTR bstrKey, BSTR bstrVal);
	STDMETHOD(get_Handle)(LONGLONG* hWnd);
	STDMETHOD(get_XML)(BSTR* pVal);
	STDMETHOD(get_ChildNodes)(IWndNodeCollection** );
	STDMETHOD(get_Row)(long* nRow);
	STDMETHOD(get_Col)(long* nCol);
	STDMETHOD(get_Objects)(long nType, IWndNodeCollection** );
	STDMETHOD(get_NodeType)(TangramViewType* nType);
	STDMETHOD(get_ParentNode)(IWndNode** ppNode);
	STDMETHOD(get_RootNode)(IWndNode** ppNode);
	STDMETHOD(get_OuterXml)(BSTR* pVal);
	STDMETHOD(get_Key)(BSTR* pVal);
	STDMETHOD(get_Compositor)(ICompositor** pVal);
	STDMETHOD(get_HostCompositor)(ICompositor** pVal);
	STDMETHOD(get_Height)(LONG* pVal);
	STDMETHOD(get_Width)(LONG* pVal);
	STDMETHOD(get_Extender)(IDispatch** pVal);
	STDMETHOD(put_Extender)(IDispatch* newVal);
	STDMETHOD(get_VSDocument)(IVSDocument** pVal);
	//STDMETHOD(put_VSDocument)(IVSDocument* newVal);
	STDMETHOD(get_CompositorManager)(ICompositorManager** pVal);
	STDMETHOD(get_NameAtWindowPage)(BSTR* pVal);
	STDMETHOD(get_DocXml)(BSTR* pVal);
	STDMETHOD(get_HostNode)(IWndNode** pVal);
	STDMETHOD(put_HostNode)(IWndNode* newVal);
	STDMETHOD(get_ActivePage)(int* pVal);
	STDMETHOD(put_ActivePage)(int newVal);
	STDMETHOD(get_OfficeObj)(IDispatch** pVal);

	STDMETHOD(get_Rows)(long* nRows);
	STDMETHOD(get_Cols)(long* nCols);
	STDMETHOD(get_Hmin)(int* pVal);
	STDMETHOD(put_Hmin)(int newVal);
	STDMETHOD(get_Hmax)(int* pVal);
	STDMETHOD(put_Hmax)(int newVal);
	STDMETHOD(get_Vmin)(int* pVal);
	STDMETHOD(put_Vmin)(int newVal);
	STDMETHOD(get_Vmax)(int* pVal);
	STDMETHOD(put_Vmax)(int newVal);
	STDMETHOD(get_rgbMiddle)(OLE_COLOR* pVal);
	STDMETHOD(put_rgbMiddle)(OLE_COLOR newVal);
	STDMETHOD(get_rgbRightBottom)(OLE_COLOR* pVal);
	STDMETHOD(put_rgbRightBottom)(OLE_COLOR newVal);
	STDMETHOD(get_rgbLeftTop)(OLE_COLOR* pVal);
	STDMETHOD(put_rgbLeftTop)(OLE_COLOR newVal);
	STDMETHOD(get_MasterRow)(int* pVal);
	STDMETHOD(put_MasterRow)(int newVal);
	STDMETHOD(get_MasterCol)(int* pVal);
	STDMETHOD(put_MasterCol)(int newVal);
	STDMETHOD(put_SaveToConfigFile)(VARIANT_BOOL newVal);

	STDMETHOD(Open)(BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode);
	STDMETHOD(OpenEx)(int nRow, int nCol, BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode);
	STDMETHOD(ActiveTabPage)(IWndNode* pNode);
	STDMETHOD(GetNode)(long nRow, long nCol,IWndNode** ppTangramNode);
	STDMETHOD(GetNodes)(BSTR bstrName, IWndNode** ppNode, IWndNodeCollection** ppNodes, long* pCount);
	STDMETHOD(GetCtrlByName)(BSTR bstrName, VARIANT_BOOL bFindInChild, IDispatch** ppRetDisp);
	STDMETHOD(GetCtrlValueByName)(BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR* bstrVal);
	STDMETHOD(SetCtrlValueByName)(BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR bstrVal);
	STDMETHOD(Refresh)(void);
	STDMETHOD(LoadXML)(int nType, BSTR bstrXML);
	STDMETHOD(Show)();
	STDMETHOD(GetNodeByName)(BSTR bstrName, IWndNodeCollection** pVal);
	STDMETHOD(get_DockObj)(BSTR bstrName, LONGLONG* pVal);
	STDMETHOD(put_DockObj)(BSTR bstrName, LONGLONG newVal);
	STDMETHOD(NavigateURL)(BSTR bstrURL, IDispatch* dispObjforScript);
	STDMETHOD(get_URL)(BSTR* pVal);
	STDMETHOD(put_URL)(BSTR newVal);

	STDMETHOD(AddChannel)(BSTR bstrChannel);
	STDMETHOD(SendIPCMessage)(BSTR bstrChannel, BSTR bstrData);

	BEGIN_COM_MAP(CWndNode)
		COM_INTERFACE_ENTRY(IWndNode)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CWndNode)
		CONNECTION_POINT_ENTRY(__uuidof(_IWndNodeEvents))
	END_CONNECTION_POINT_MAP()

	HWND CreateView(HWND hParentWnd, CString strTag);

private:
	CString _GetNames(CWndNode* pNode);
	void _get_Objects(CWndNode* pNode, UINT32& nType, CWndNodeCollection* pNodeColletion);
	int _getNodes(CWndNode* pNode, CString& strName, CWndNode**ppRetNode, CWndNodeCollection* pNodes);
};

// CWndNodeCollection

class ATL_NO_VTABLE CWndNodeCollection :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IWndNodeCollection, &IID_IWndNodeCollection, &LIBID_Tangram, 1, 0>
{
public:
	CWndNodeCollection();
	~CWndNodeCollection();

	BEGIN_COM_MAP(CWndNodeCollection)
		COM_INTERFACE_ENTRY(IWndNodeCollection)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	STDMETHOD(get_NodeCount)(long* pCount);
	STDMETHOD(get_Item)(long iIndex, IWndNode **ppTangramNode);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	CTangramNodeVector*	m_pNodes;

private:
	CTangramNodeVector	m_vNodes;
};
