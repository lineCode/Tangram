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
#include "../OfficeAddin.h"
#include "..\tangram\TangramCtrl.h"

namespace OfficePlus
{
	namespace VisioPlus
	{
		class CVisioAddin :
			public COfficeAddin
		{
		public:
			CVisioAddin();
			virtual ~CVisioAddin();
			//CTangramApp:
			STDMETHOD(TangramCommand)(IDispatch* RibbonControl);
			STDMETHOD(GetCustomUI)(BSTR RibbonID, BSTR * RibbonXml);
			HRESULT OnConnection(IDispatch* pHostApp, int ConnectMode);
			HRESULT OnDisconnection(int DisConnectMode);
			void WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd);
			HRESULT CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv);
		};

		// CVisioAppCtrl
		class ATL_NO_VTABLE CVisioAppCtrl :
			public CTangramAppCtrl,
			public IOleObjectImpl<CVisioAppCtrl>,
			public IPersistStorageImpl<CVisioAppCtrl>,
			public IPersistStreamInitImpl<CVisioAppCtrl>,
			public CComCoClass<CVisioAppCtrl, &CLSID_TangramCtrl>,
			public IDispatchImpl<ITangramAppCtrl, &IID_ITangramAppCtrl, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
		{
		public:
			CVisioAppCtrl();

			BEGIN_COM_MAP(CVisioAppCtrl)
				COM_INTERFACE_ENTRY(ITangramAppCtrl)
				COM_INTERFACE_ENTRY(IDispatch)
				COM_INTERFACE_ENTRY(IOleObject)
				COM_INTERFACE_ENTRY(IViewObject)
				COM_INTERFACE_ENTRY(IViewObject2)
				COM_INTERFACE_ENTRY(IOleInPlaceObject)
				//COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
				COM_INTERFACE_ENTRY(IPersistStorage)
				COM_INTERFACE_ENTRY(IPersistStreamInit)
				COM_INTERFACE_ENTRY(IConnectionPointContainer)
			END_COM_MAP()

			//HRESULT FinalConstruct();
			void OnFinalMessage(HWND hWnd);

		public:
			// ITangramAppCtrl
			STDMETHOD(get_tag)(VARIANT* pVal);
			STDMETHOD(put_tag)(VARIANT newVal);
			STDMETHOD(get_HWND)(LONGLONG* pVal);
			STDMETHOD(get_Tangram)(ITangram** pVal);
			STDMETHOD(put_AppCtrl)(VARIANT_BOOL newVal);
		};
	}
}// namespace OfficePlus


