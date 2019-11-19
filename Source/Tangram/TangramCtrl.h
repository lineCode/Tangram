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

// TangramCtrl.h : Declaration of the CTangramCtrl
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "Tangram.h"

// CTangramCtrl
class ATL_NO_VTABLE CTangramCtrlBase :
	public CComControl<CTangramCtrlBase>,
	public CComObjectRootEx<CComSingleThreadModel>,
	public IViewObjectExImpl<CTangramCtrlBase>,
	public IOleInPlaceActiveObjectImpl<CTangramCtrlBase>,
	public IOleInPlaceObjectWindowlessImpl<CTangramCtrlBase>
{
public:
#pragma warning(push)
#pragma warning(disable: 4355) // 'this' : used in base member initializer list

	CTangramCtrlBase();
	virtual ~CTangramCtrlBase();

#pragma warning(pop)

	DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |OLEMISC_CANTLINKINSIDE |OLEMISC_INSIDEOUT)

	DECLARE_WND_CLASS(_T("Tangram Control Class"))

	BEGIN_COM_MAP(CTangramCtrlBase)
		COM_INTERFACE_ENTRY(IOleInPlaceObject)
	END_COM_MAP()

	BEGIN_PROP_MAP(CTangramCtrlBase)
	END_PROP_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	
	virtual void OnFinalMessage(HWND hWnd);
};

// CTangramAppCtrl
class ATL_NO_VTABLE CTangramAppCtrl :
	public CTangramCtrlBase,
	public IConnectionPointContainerImpl<CTangramAppCtrl>,
	public IConnectionPointImpl<CTangramAppCtrl, &DIID__ITangramAppEvents>
{
public:
	CTangramAppCtrl();
	virtual ~CTangramAppCtrl();

	BEGIN_COM_MAP(CTangramAppCtrl)
		COM_INTERFACE_ENTRY(IOleInPlaceObject)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CTangramAppCtrl)
		CONNECTION_POINT_ENTRY(DIID__ITangramAppEvents)
	END_CONNECTION_POINT_MAP()

public:
	BEGIN_MSG_MAP(CTangramAppCtrl)
	END_MSG_MAP()

	HRESULT Fire_TangramEvent(ITangramEventObj* pEventObj);

private:
	HWND m_hHostWnd;
};

// CTangramCtrl
class ATL_NO_VTABLE CTangramCtrl : 
	public CTangramCtrlBase,
	public IOleObjectImpl<CTangramCtrl>,
	public CComCoClass<CTangramCtrl, &CLSID_TangramCtrl>,
	public IDispatchImpl<ITangramCtrl, &IID_ITangramCtrl, &LIBID_Tangram, 1, 0>
{
public:
	DECLARE_REGISTRY_RESOURCEID(IDR_TANGRAMCTRL)

	BEGIN_COM_MAP(CTangramCtrl)
		COM_INTERFACE_ENTRY(ITangramCtrl)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IOleObject)
		COM_INTERFACE_ENTRY(IViewObject2)
		COM_INTERFACE_ENTRY(IViewObject)
		COM_INTERFACE_ENTRY(IOleInPlaceObject)
		COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	END_COM_MAP()

	BEGIN_CATEGORY_MAP(CTangramCtrlHelper)
		IMPLEMENTED_CATEGORY(CATID_SafeForInitializing)
		IMPLEMENTED_CATEGORY(CATID_SafeForScripting)
	END_CATEGORY_MAP()

public:
	STDMETHOD(get_HWND)(LONGLONG* pVal);
	STDMETHOD(get_Tangram)(ITangram** pVal);
	STDMETHOD(get_tag)(VARIANT* pVal);
	STDMETHOD(put_tag)(VARIANT newVal);

	static HRESULT WINAPI CreateInstance(void* pv, REFIID riid, LPVOID* ppv);
};

OBJECT_ENTRY_AUTO_EX(__uuidof(TangramCtrl), CTangramCtrl)
