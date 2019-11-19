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
#include "msppt.h"
#include "../OfficeAddin.h"
#include "PowerpointPlusEvents.h"

using namespace PowerPoint;
using namespace OfficePlus::PowerPointPlus;
using namespace OfficePlus::PowerPointPlus::PowerPointPlusEvent;

namespace OfficePlus
{
	namespace PowerPointPlus
	{
		class CCloudAddinPresentation;
		class CPowerPntObject : public COfficeObject
		{
		public:
			CPowerPntObject(void);
			~CPowerPntObject(void);

			CCloudAddinPresentation*	m_pPresentation;
			void OnObjDestory();
		};

		class CCloudAddinPresentation : 
			public COfficeDocument,
			public map<HWND, CPowerPntObject*>
		{
		public:
			CCloudAddinPresentation();
			~CCloudAddinPresentation();
			bool						m_bDesignState;
			CString						m_strKey;
		};

		class CPowerPntAddin : 
			public COfficeAddin,
			public CPowerpointPlusEApplication
		{
		public:
			CPowerPntAddin();
			CPowerPntObject*						m_pActivePowerPntObject;
			CCloudAddinPresentation*				m_pCurrentSavingPresentation;
			map<CString, CCloudAddinPresentation*>	m_mapTangramPres;

		private:
			CComPtr<PowerPoint::_Application>		m_pApplication;

			STDMETHOD(put_AppKeyValue)(BSTR bstrKey, VARIANT newVal);
			STDMETHOD(TangramCommand)(IDispatch* RibbonControl);
			STDMETHOD(GetCustomUI)(BSTR RibbonID, BSTR * RibbonXml);
			STDMETHOD(StartApplication)(BSTR bstrAppID, BSTR bstrXml);

			HRESULT OnConnection(IDispatch* pHostApp, int ConnectMode);
			HRESULT OnDisconnection(int DisConnectMode);

			void __stdcall OnPresentationSave(/*[in]*/ _Presentation * Pres);
			void __stdcall OnPresentationBeforeSave(/*[in]*/ _Presentation * Pres,	/*[in,out]*/ VARIANT_BOOL * Cancel);

			void AddDocXml(IDispatch* pDocdisp, BSTR bstrXml, BSTR bstrKey);
			CString GetDocXmlByKey(IDispatch* pDocdisp, BSTR bstrKey);

			//void UpdateOfficeObj(IDispatch* pObj, CString strXml, CString strName);
			void WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd);
			void WindowDestroy(HWND hWnd);
			void ConnectOfficeObj(HWND hWnd);
			bool OnActiveOfficeObj(HWND hWnd);
			HRESULT CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv);
		};

		// CPowerPntAppCtrl
		class ATL_NO_VTABLE CPowerPntAppCtrl :
			public CTangramAppCtrl,
			public IOleObjectImpl<CPowerPntAppCtrl>,
			public IPersistStorageImpl<CPowerPntAppCtrl>,
			public IPersistStreamInitImpl<CPowerPntAppCtrl>,
			public CComCoClass<CPowerPntAppCtrl, &CLSID_TangramCtrl>,
			public IDispatchImpl<ITangramAppCtrl, &IID_ITangramAppCtrl, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
		{
		public:
			CPowerPntAppCtrl();

			BEGIN_COM_MAP(CPowerPntAppCtrl)
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


