#pragma once
#include "mso.h"
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

#include "tangrambase.h"
//#include "cpprest\http_client.h"
#include "fm20.h"
#include "msoutl.h"
#include "../OfficeAddin.h"
#include "OutLookPlusEvents.h"
#include "..\tangram\officeplus\wordplus\msword.h"
#include "..\tangram\TangramCtrl.h"

using namespace Word;
using namespace Office;
using namespace OfficePlus::OutLookPlus::OutLookPlusEvent;

namespace OfficePlus
{
	namespace OutLookPlus
	{
		class CInspectorItem;
		class CInspectorItems;
		class CInspectorContainerWnd;
		class COutLookExplorer;
		class COutLookInspector;

		class COutLookAppObjEvents :
			public COutLookApplicationEvents
		{
		public:
			COutLookAppObjEvents(void) {};
			void __stdcall OnItemSend(IDispatch* Item, VARIANT_BOOL* Cancel);
			void __stdcall OnNewMail();
			void __stdcall OnReminder(IDispatch* Item);
			void __stdcall OnOptionsPagesAdd(PropertyPages* Pages);
			void __stdcall OnStartup();
			void __stdcall OnQuit();
		};

		class COutLookAppObjEvents2 :
			public COutLookApplicationEvents_10
		{
		public:
			COutLookAppObjEvents2(void) {};
			void __stdcall OnAdvancedSearchComplete(Search* SearchObject);
			void __stdcall OnAdvancedSearchStopped(Search* SearchObject);
			void __stdcall OnMAPILogonComplete();
		};

		class COutLookAddin :
			public COfficeAddin,
			public COutLookExplorersEvents,
			public COutLookInspectorsEvents,
			//public COutLookStoresEvents_12,
			//public COutLookApplicationEvents,
			//public COutLookApplicationEvents_10,
			public COutLookApplicationEvents_11
		{
		public:
			COutLookAddin();
			virtual ~COutLookAddin();

			int											m_nVer;
			DISPID										m_nGetClassDispID;
			HWND										m_hWwbWnd;
			HWND										m_hPWwbWnd;

			//CString										m_strCurrentKey;
			CString										m_strDesignExplorerEntryID;
			CString										m_strDesignExplorerStoreID;

			IDispatch*									m_pCurLoadItem;
			CComPtr<OutLook::_Application>				m_pApplication;

			CInspectorItems*							m_pTangramInspectorItems;
			COutLookExplorer*							m_pActiveOutlookExplorer;
			COutLookInspector*							m_pCurOpenItem;
			CComPtr<_Explorers>							m_pExplorers;

			map<int, CString>							m_mapItemName;
			map<long, CInspectorItem*>					m_mapTangramInspectorItem;
			map<CString, CString>						m_mapUIXML;
			map<CString, _Explorer*>					m_mapDesignExplorer;
			map<HWND, COutLookInspector*>				m_mapInspector;
			map<HWND, COutLookExplorer*>				m_mapOutLookPlusExplorerMap;

			void AddTangramPropertyToInspector(_Inspector* pInspector, CString strPropertyName, CString strInfoXml);
			void AddFormPageToInspector(_Inspector* pInspector, CString strPageName, CString strInfoXml, BOOL bShowInSpector, BOOL bSetCurrentPage);
			void WriteFolderPropertyToStore(MAPIFolder* pFolder, CString strSubject, CString strPropertyName, CString strData);

			CString GetTangramPropertyFromItem(IDispatch* pItem, CString strPropertyName);
			CString GetTangramPropertyFromInspector(_Inspector* pInspector, CString strPropertyName);
			CString GetPropertyFromItem(IDispatch* pItem, CString strPropertyName);
			CString GetPropertyFromInspector(_Inspector* pInspector, CString strPropertyName);
			CString GetFolderPropertyFromStore(MAPIFolder* pFolder, CString strSubject, CString strPropertyName);
			CString ExportTangramData();
			void InitOutLook();
			_Inspector* GetInspector(IDispatch*);

		private:
			CComPtr<_Stores>							m_pStores;
			CComPtr<_Inspectors >						m_pInspectors;

			COutLookAppObjEvents*						m_pOutLookAppObjEvents;
			COutLookAppObjEvents2*						m_pOutLookAppObjEvents2;
			//void __stdcall OnBeforeStoreRemove(_Store* Store, VARIANT_BOOL* Cancel);
			//void __stdcall OnStoreAdd(_Store* Store);

			//begin COutLookExplorersEvents:
			void __stdcall OnNewExplorer(_Explorer* Explorer);
			//end COutLookExplorersEvents

			//COutLookApplicationEvents_11
			void __stdcall OnQuit();
			void __stdcall OnNewMailEx(BSTR EntryIDCollection);
			void __stdcall OnAttachmentContextMenuDisplay(CommandBar* CommandBar, AttachmentSelection* Attachments);
			void __stdcall OnFolderContextMenuDisplay(CommandBar* CommandBar, OutLook::Folder* Folder);
			void __stdcall OnStoreContextMenuDisplay(CommandBar* CommandBar, Store* Store);
			void __stdcall OnShortcutContextMenuDisplay(CommandBar* CommandBar, OutlookBarShortcut* Shortcut);
			void __stdcall OnViewContextMenuDisplay(CommandBar* CommandBar, OutLook::View* View);
			void __stdcall OnItemContextMenuDisplay(CommandBar* CommandBar, OutLook::Selection* Selection);
			void __stdcall OnContextMenuClose(OlContextMenu ContextMenu);
			void __stdcall OnItemLoad(IDispatch* Item);
			void __stdcall OnBeforeFolderSharingDialog(MAPIFolder* FolderToShare, VARIANT_BOOL* Cancel);

			//begin COutLookInspectorsEvents:
			void __stdcall OnNewInspector(_Inspector* Inspector);
			//end COutLookInspectorsEvents

			//CTangram:
			void WindowDestroy(HWND hWnd);
			void WindowCreated(CString strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd);
			HRESULT OnConnection(IDispatch* pHostApp, int ConnectMode);
			HRESULT OnDisconnection(int DisConnectMode);
			CString GetDefaultFolderXml(_Store* pStore, OlDefaultFolders m_folderenum);
			HRESULT CreateTangramCtrl(void* pv, REFIID riid, LPVOID* ppv);
			STDMETHOD(AttachObjEvent)(IDispatch* pDisp, int nEventIndex);
			STDMETHOD(TangramCommand)(IDispatch* RibbonControl);
			STDMETHOD(GetCustomUI)(BSTR RibbonID, BSTR * RibbonXml);
		};

		class CInspectorContainerWnd :
			public CWindowImpl<CInspectorContainerWnd, CWindow>
		{
		public:
			CInspectorContainerWnd(void);
			~CInspectorContainerWnd(void);

			HWND				m_hFrameWnd;
			CString				m_strXml;
			ICompositorManager*			m_pCompositorManager;
			ICompositor*			m_pCompositor;
			COutLookExplorer*	m_pOutLookExplorer;
		private:
			LRESULT OnTangramSave(UINT, WPARAM, LPARAM, BOOL&);
			LRESULT OnTangramMsg(UINT, WPARAM, LPARAM, BOOL&);
			LRESULT OnItemLoad(UINT, WPARAM, LPARAM, BOOL&);
			void OnFinalMessage(HWND hWnd);
			BEGIN_MSG_MAP(CInspectorContainerWnd)
				MESSAGE_HANDLER(WM_TANGRAMSAVE, OnTangramSave)
				MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
				MESSAGE_HANDLER(WM_TANGRAMITEMLOAD, OnItemLoad)
			END_MSG_MAP()
		};

		class COutLookPageWnd :
			public CWindowImpl<COutLookPageWnd, CWindow>
		{
		public:
			COutLookPageWnd(void);
			~COutLookPageWnd(void);

			BOOL				m_bDesignState;
			HWND				m_hFrameWnd;
			CString				m_strName;
			CString				m_strXml;

			ICompositorManager*			m_pCompositorManager;
			ICompositor*			m_pCompositor;

			MSForm::_UserForm*	m_pForm;
			COutLookInspector*	m_pOutLookInspector;

			void ActivePage();
			void DesignPage();
			BEGIN_MSG_MAP(COutLookPageWnd)
				MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
			END_MSG_MAP()
		private:
			void OnFinalMessage(HWND hWnd);
			LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
		};

		class COutLookExplorer :
			public COutLookExplorerEvents,
			public COutLookExplorerEvents_10,
			public COutLookAccountSelectorEvents,
			public COutLookNavigationPaneEvents_12,
			public COutLookNavigationGroupsEvents_12
		{
		public:
			COutLookExplorer(void);
			~COutLookExplorer(void);

			HWND									m_hWnd;
			HWND									m_hTaskPane;
			HWND									m_hTaskPaneWnd;
			HWND									m_hOutLookToday;
			HWND									m_hTaskPaneChildWnd;

			CString									m_strKey;

			OlNavigationModuleType					m_nNType;
			CComPtr<_Explorer>						m_pExplorer;
			CComPtr<OutLook::_NavigationPane>		m_pNavigationPane;
			_AccountSelector*						m_pAccountSelector;
			_NavigationModule*						m_pCurrentModule;
			_NavigationGroups*						m_pNavigationGroups;

			ICompositorManager*								m_pCompositorManager;
			ICompositor*								m_pCompositor;
			ICompositorManager*								m_pTaskPaneCompositorManager;
			ICompositor*								m_pTaskPaneCompositor;
			IDispatch*								m_pModuleDisp;
			
			IDispatch*								m_pNewFolder;
			_CustomTaskPane*						m_pTaskPane;

			CInspectorContainerWnd*					m_pInspectorContainerWnd;
			map<CString, CString>					m_mapUIScript;
			map<CString, HWND>						m_mapFolderWnd;
			IDispatch*								m_pOnlineItem;

			void TangramCommand(int nIndex);

			void SetDesignState();

		private:
			//begin COutLookExplorerEvents:
			void __stdcall OnActivate();
			void __stdcall OnFolderSwitch();
			void __stdcall OnBeforeFolderSwitch(IDispatch*, VARIANT_BOOL* Cancel);
			void __stdcall OnViewSwitch();
			void __stdcall OnBeforeViewSwitch(VARIANT NewView, VARIANT_BOOL* Cancel);
			void __stdcall OnDeactivate();
			void __stdcall OnSelectionChange();
			void __stdcall OnClose();
			//end COutLookExplorerEvents

			//begin COutLookExplorerEvents_10:
			//void __stdcall OnBeforeMaximize(VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeMinimize(VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeMove(VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeSize(VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeItemCopy(VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeItemCut(VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeItemPaste(VARIANT_BOOL* Cancel);
			void __stdcall OnAttachmentSelectionChange();
			void __stdcall OnInlineResponse(IDispatch* Item);
			void __stdcall OnInlineResponseClose();
			//end COutLookExplorerEvents_10

			//begin COutLookAccountSelectorEvents:
			void __stdcall OnSelectedAccountChange(Account* SelectedAccount);
			//end COutLookAccountSelectorEvents

			//begin COutLookNavigationPaneEvents_12:
			void __stdcall OnModuleSwitch(NavigationModule* CurrentModule);
			//begin COutLookNavigationPaneEvents_12

			//begin COutLookNavigationGroupsEvents_12:
			void __stdcall OnSelectedChange(NavigationFolder* NavigationFolder);
			void __stdcall OnNavigationFolderAdd(NavigationFolder* NavigationFolder);
			void __stdcall OnNavigationFolderRemove();
			//end COutLookNavigationGroupsEvents_12

			HWND GetCurrentFolderFrameHandle();
		};

		class CInspectorItem :
			public COutLookItemEvents,
			public COutLookItemEvents_10
		{
		public:
			CInspectorItem(void);
			~CInspectorItem(void);

			CString					m_strXml;
			IDispatch*				m_pItem;
			CInspectorContainerWnd* m_pInspectorContainerWnd;
			void __stdcall OnRead();
			void __stdcall OnUnload();
		};

		class CInspectorItems :
			public COutLookItemsEvents
		{
		public:
			CInspectorItems(void);
			~CInspectorItems(void);

			void __stdcall OnItemAdd(IDispatch* Item);
			void __stdcall OnItemChange(IDispatch* Item);
			void __stdcall OnItemRemove();

			IDispatch* m_pItems;
		};

		class COutLookInspector :
			public COutLookItemEvents,
			public COutLookInspectorEvents,
			public COutLookInspectorEvents_10
		{
		public:
			COutLookInspector(void);
			~COutLookInspector(void);

			BOOL							m_bReadOnly;
			OlObjectClass					m_OlObjectClass;
			HWND 							m_hWnd;
			HWND							m_hHostWnd;
			HWND							m_hTaskPane;
			HWND							m_hTaskPaneWnd;
			HWND							m_hTaskPaneChildWnd;

			CString							m_strKey;
			CString							m_strUIScript;
			CString							m_strActivePageName;

			IDispatch*						m_pDisp;
			_CustomTaskPane*				m_pTaskPane;
			_Inspector*						m_pInspector;
			
			ICompositorManager*						m_pTaskPaneCompositorManager;
			ICompositor*						m_pTaskPaneCompositor;

			COutLookPageWnd*				m_pActiveOutLookPage;
			map<CString, COutLookPageWnd*>	m_mapOutLookPage;

			void ActivePage();
			void TangramCommand(int nIndex);

		private:
			void __stdcall OnActivate();
			void __stdcall OnDeactivate();
			void __stdcall OnClose();

			void __stdcall OnPageChange(BSTR ActivePageName);

			//begin COutLookItemEvents:
			void __stdcall OnOpen(VARIANT_BOOL* Cancel);
			void __stdcall OnCustomAction(IDispatch* Action, IDispatch* Response, VARIANT_BOOL* Cancel);
			void __stdcall OnCustomPropertyChange(BSTR Name);
			void __stdcall OnForward(IDispatch* Forward, VARIANT_BOOL* Cancel);
			void __stdcall OnClose(VARIANT_BOOL* Cancel);
			void __stdcall OnPropertyChange(BSTR Name);
			void __stdcall OnRead();
			void __stdcall OnReply(IDispatch* Response, VARIANT_BOOL* Cancel);
			void __stdcall OnReplyAll(IDispatch* Response, VARIANT_BOOL* Cancel);
			void __stdcall OnSend(VARIANT_BOOL* Cancel);
			void __stdcall OnWrite(VARIANT_BOOL* Cancel);
			void __stdcall OnBeforeCheckNames(VARIANT_BOOL* Cancel);
			void __stdcall OnAttachmentAdd(OutLook::Attachment* Attachment);
			void __stdcall OnAttachmentRead(OutLook::Attachment* Attachment);
			void __stdcall OnBeforeAttachmentSave(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel);
			//end COutLookItemEvents

			//begin COutLookItemEvents_10:
			//void __stdcall OnBeforeDelete(IDispatch* Item, VARIANT_BOOL* Cancel);
			//void __stdcall OnAttachmentRemove(OutLook::Attachment* Attachment);
			//void __stdcall OnBeforeAttachmentAdd(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeAttachmentPreview(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeAttachmentRead(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeAttachmentWriteToTempFile(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel);
			//void __stdcall OnUnload();
			//void __stdcall OnBeforeAutoSave(VARIANT_BOOL* Cancel);
			//void __stdcall OnBeforeRead();
			//void __stdcall OnAfterWrite();
			//New for OutLook2013:
			//void __stdcall OnReadComplete(VARIANT_BOOL* Cancel);
			//end COutLookItemEvents_10
		};

		// COutLookAppCtrl
		class ATL_NO_VTABLE COutLookAppCtrl :
			public CTangramAppCtrl,
			public IOleObjectImpl<COutLookAppCtrl>,
			public IPersistStorageImpl<COutLookAppCtrl>,
			public IPersistStreamInitImpl<COutLookAppCtrl>,
			public CComCoClass<COutLookAppCtrl, &CLSID_TangramCtrl>,
			public IDispatchImpl<ITangramAppCtrl, &IID_ITangramAppCtrl, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
		{
		public:
			COutLookAppCtrl();

			BEGIN_COM_MAP(COutLookAppCtrl)
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
}

