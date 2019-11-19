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
#include "WordPlusEvents.h"
using namespace OfficePlus::WordPlus::WordPlusEvent;

namespace OfficePlus
{
	namespace WordPlus
	{
		class CWordObject;
		class CWordDocument;
		class CWordAppObjEvents;
		class CWordAppObjEvents2;
		class CWordAddin :
			public COfficeAddin,
			public CWordAppEvents2,
			public map<_Document*, CWordDocument*>
		{
		public:
			CWordAddin();
			virtual ~CWordAddin();

			CComPtr<_Application>		m_pApplication;
			CWordObject*				m_pActiveWordObject;
			CString GetDocXmlByKey(IDispatch* pDocdisp, BSTR bstrKey);
			void AddDocXml(IDispatch* pDocdisp, BSTR bstrXml, BSTR bstrKey);
		private:
			CWordAppObjEvents*				m_pWordAppObjEvents;
			CWordAppObjEvents2*				m_pWordAppObjEvents2;
			void __stdcall OnStartup();
			void __stdcall OnQuit();
			void __stdcall OnDocumentChange();
			void __stdcall OnDocumentOpen(_Document* Doc);
			void __stdcall OnDocumentBeforeClose(_Document* Doc, VARIANT_BOOL* Cancel);
			void __stdcall OnDocumentBeforePrint(_Document* Doc, VARIANT_BOOL* Cancel);
			void __stdcall OnDocumentBeforeSave(_Document* Doc, VARIANT_BOOL* SaveAsUI, VARIANT_BOOL* Cancel);
			void __stdcall OnNewDocument(_Document* Doc);
			void __stdcall OnWindowActivate(_Document* Doc, Word::Window* Wn);
			void __stdcall OnWindowDeactivate(_Document* Doc, Word::Window* Wn);
			void __stdcall OnWindowSelectionChange(Selection* Sel);
			void __stdcall OnWindowBeforeRightClick(Selection* Sel, VARIANT_BOOL* Cancel);
			void __stdcall OnWindowBeforeDoubleClick(Selection* Sel, VARIANT_BOOL* Cancel);

			CString GetFormXml(CString strFormName);
			void UpdateOfficeObj(IDispatch* pObj, CString strXml, CString strName);

			STDMETHOD(put_AppKeyValue)(BSTR bstrKey, VARIANT newVal);
			STDMETHOD(AttachObjEvent)(IDispatch* pDisp, int nEventIndex);
			STDMETHOD(ExportOfficeObjXml)(IDispatch* OfficeObject, BSTR* bstrXml);
			STDMETHOD(GetCustomUI)(BSTR RibbonID, BSTR * RibbonXml);
			STDMETHOD(TangramCommand)(IDispatch* RibbonControl);
			STDMETHOD(StartApplication)(BSTR bstrAppID, BSTR bstrXml);

			HRESULT OnConnection(IDispatch* pHostApp, int ConnectMode);
			HRESULT OnDisconnection(int DisConnectMode);
			void WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd);
			void WindowDestroy(HWND hWnd);

			void OnOpenDoc(WPARAM);
			void ConnectOfficeObj(HWND hWnd);
			bool OnActiveOfficeObj(HWND hWnd);
			void OnDocActivate(CWordObject*);
			HRESULT CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv);
		};

		class CWordAppObjEvents :
			public CWordAppEvents3
		{
		public:
			CWordAppObjEvents() {};

		private:
			void __stdcall OnEPostagePropertyDialog(_Document* Doc);
			void __stdcall OnEPostageInsert(_Document* Doc);
			void __stdcall OnMailMergeAfterMerge(_Document* Doc, Word::Document* DocResult);
			void __stdcall OnMailMergeAfterRecordMerge(_Document* Doc);
			void __stdcall OnMailMergeBeforeMerge(_Document* Doc, long StartRecord, long EndRecord, VARIANT_BOOL* Cancel);
			void __stdcall OnMailMergeBeforeRecordMerge(_Document* Doc, VARIANT_BOOL* Cancel);
			void __stdcall OnMailMergeDataSourceLoad(_Document* Doc);
			void __stdcall OnMailMergeDataSourceValidate(_Document* Doc, VARIANT_BOOL* Handled);
			void __stdcall OnMailMergeWizardSendToCustom(_Document* Doc);
			void __stdcall OnMailMergeWizardStateChange(_Document* Doc, int* FromState, int* ToState, VARIANT_BOOL* Handled);
			void __stdcall OnWindowSize(_Document* Doc, Word::Window* Wn);
		};

		class CWordAppObjEvents2 :
			public CWordAppEvents4
		{
		public:
			CWordAppObjEvents2() {};

		private:
			void __stdcall OnXMLSelectionChange(Word::Selection* Sel, XMLNode* OldXMLNode, XMLNode* NewXMLNode, long* Reason);
			void __stdcall OnXMLValidationError(XMLNode* XMLNode);
			void __stdcall OnDocumentSync(_Document* Doc, MsoSyncEventType SyncEvent);
			void __stdcall OnMailMergeDataSourceValidate2(_Document* Doc, VARIANT_BOOL* Handled);
			void __stdcall OnProtectedViewWindowOpen(ProtectedViewWindow* PvWindow);
			void __stdcall OnProtectedViewWindowBeforeEdit(ProtectedViewWindow* PvWindow, VARIANT_BOOL* Cancel);
			void __stdcall OnProtectedViewWindowBeforeClose(ProtectedViewWindow* PvWindow, int CloseReason, VARIANT_BOOL* Cancel);
			void __stdcall OnProtectedViewWindowSize(ProtectedViewWindow* PvWindow);
			void __stdcall OnProtectedViewWindowActivate(ProtectedViewWindow* PvWindow);
			void __stdcall OnProtectedViewWindowDeactivate(ProtectedViewWindow* PvWindow);
		};

		// CWordAppCtrl
		class ATL_NO_VTABLE CWordAppCtrl :
			public CTangramAppCtrl,
			public IOleObjectImpl<CWordAppCtrl>,
			public IPersistStorageImpl<CWordAppCtrl>,
			public IPersistStreamInitImpl<CWordAppCtrl>,
			public CComCoClass<CWordAppCtrl, &CLSID_TangramCtrl>,
			public IDispatchImpl<ITangramAppCtrl, &IID_ITangramAppCtrl, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
		{
		public:
			CWordAppCtrl();

			BEGIN_COM_MAP(CWordAppCtrl)
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
}

