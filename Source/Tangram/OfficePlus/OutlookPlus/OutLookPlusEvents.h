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

#include "outlctl.h"
#include "msoutl.h"
using namespace Office;
using namespace OutLook;

namespace OfficePlus
{
	namespace OutLookPlus
	{
		namespace OutLookPlusEvent
		{
			extern _ATL_FUNC_INFO ViewAdd;
			extern _ATL_FUNC_INFO ViewRemove;
			extern _ATL_FUNC_INFO AfterUpdate;
			extern _ATL_FUNC_INFO Activate;
			extern _ATL_FUNC_INFO BeforeUpdate;
			extern _ATL_FUNC_INFO GroupAdd;
			extern _ATL_FUNC_INFO BeforeShortcutAdd;
			extern _ATL_FUNC_INFO BeforeShortcutRemove;
			extern _ATL_FUNC_INFO BeforeReminderShow;
			extern _ATL_FUNC_INFO BeforeGroupAdd;
			extern _ATL_FUNC_INFO BeforeGroupRemove;
			extern _ATL_FUNC_INFO BeforeNavigate;
			extern _ATL_FUNC_INFO BeforeGroupSwitch;
			extern _ATL_FUNC_INFO BeforeMaximize;
			extern _ATL_FUNC_INFO BeforeMinimize;
			extern _ATL_FUNC_INFO BeforeMove;
			extern _ATL_FUNC_INFO BeforeStoreRemove;
			extern _ATL_FUNC_INFO BeforeSize;
			extern _ATL_FUNC_INFO BeforeItemCopy;
			extern _ATL_FUNC_INFO BeforeItemCut;
			extern _ATL_FUNC_INFO BeforeItemPaste;
			extern _ATL_FUNC_INFO BeforeFolderSharingDialog;
			extern _ATL_FUNC_INFO Click;
			extern _ATL_FUNC_INFO Change;
			extern _ATL_FUNC_INFO DropButtonClick;
			extern _ATL_FUNC_INFO ShortcutAdd;
			extern _ATL_FUNC_INFO ReminderAdd;
			extern _ATL_FUNC_INFO ReminderChange;
			extern _ATL_FUNC_INFO ReminderFire;
			extern _ATL_FUNC_INFO ReminderRemove;
			extern _ATL_FUNC_INFO Snooze;
			extern _ATL_FUNC_INFO StoreAdd;
			extern _ATL_FUNC_INFO SyncStart;
			extern _ATL_FUNC_INFO Progress;
			extern _ATL_FUNC_INFO OnError;
			extern _ATL_FUNC_INFO SyncEnd;
			extern _ATL_FUNC_INFO BeforeViewSwitch2;
			extern _ATL_FUNC_INFO SelectionChange;
			extern _ATL_FUNC_INFO SelectedAccountChange;
			extern _ATL_FUNC_INFO AutoDiscoverComplete;
			extern _ATL_FUNC_INFO Reminder;
			extern _ATL_FUNC_INFO OptionsPagesAdd;
			extern _ATL_FUNC_INFO Startup;
			extern _ATL_FUNC_INFO Quit;
			extern _ATL_FUNC_INFO NewMail;
			extern _ATL_FUNC_INFO NewMailEx;
			extern _ATL_FUNC_INFO AttachmentContextMenuDisplay;
			extern _ATL_FUNC_INFO FolderContextMenuDisplay;
			extern _ATL_FUNC_INFO StoreContextMenuDisplay;
			extern _ATL_FUNC_INFO ShortcutContextMenuDisplay;
			extern _ATL_FUNC_INFO ViewContextMenuDisplay;
			extern _ATL_FUNC_INFO ItemClose;
			extern _ATL_FUNC_INFO ItemAdd;
			extern _ATL_FUNC_INFO ItemChange;
			extern _ATL_FUNC_INFO ItemRemove;
			extern _ATL_FUNC_INFO ItemSend;
			extern _ATL_FUNC_INFO ItemLoad;
			extern _ATL_FUNC_INFO ItemContextMenuDisplay;
			extern _ATL_FUNC_INFO ContextMenuClose;
			extern _ATL_FUNC_INFO AdvancedSearchComplete;
			extern _ATL_FUNC_INFO AdvancedSearchStopped;
			extern _ATL_FUNC_INFO MAPILogonComplete;
			extern _ATL_FUNC_INFO FolderSwitch;
			extern _ATL_FUNC_INFO BeforeFolderSwitch;
			extern _ATL_FUNC_INFO ViewSwitch;
			extern _ATL_FUNC_INFO BeforeViewSwitch;
			extern _ATL_FUNC_INFO Deactivate;
			extern _ATL_FUNC_INFO SelectionChange;
			extern _ATL_FUNC_INFO AttachmentSelectionChange;
			extern _ATL_FUNC_INFO InlineResponse;
			extern _ATL_FUNC_INFO InlineResponseClose;
			extern _ATL_FUNC_INFO NewExplorer;
			extern _ATL_FUNC_INFO FolderAdd;
			extern _ATL_FUNC_INFO FolderChange;
			extern _ATL_FUNC_INFO FolderRemove;
			extern _ATL_FUNC_INFO Expanded;
			extern _ATL_FUNC_INFO Activate;
			extern _ATL_FUNC_INFO Deactivate;
			extern _ATL_FUNC_INFO Close;
			extern _ATL_FUNC_INFO PageChange;
			extern _ATL_FUNC_INFO AttachmentSelectionChange;
			extern _ATL_FUNC_INFO Open;
			extern _ATL_FUNC_INFO CustomAction;
			extern _ATL_FUNC_INFO CustomPropertyChange;
			extern _ATL_FUNC_INFO Forward;
			extern _ATL_FUNC_INFO PropertyChange;
			extern _ATL_FUNC_INFO Read;
			extern _ATL_FUNC_INFO Reply;
			extern _ATL_FUNC_INFO ReplyAll;
			extern _ATL_FUNC_INFO Send;
			extern _ATL_FUNC_INFO Write;
			extern _ATL_FUNC_INFO BeforeCheckNames;
			extern _ATL_FUNC_INFO AttachmentAdd;
			extern _ATL_FUNC_INFO AttachmentRead;
			extern _ATL_FUNC_INFO BeforeAttachmentSave;
			extern _ATL_FUNC_INFO NewInspector;
			extern _ATL_FUNC_INFO BeforeDelete;
			extern _ATL_FUNC_INFO AttachmentRemove;
			extern _ATL_FUNC_INFO BeforeAttachmentAdd;
			extern _ATL_FUNC_INFO BeforeAttachmentPreview;
			extern _ATL_FUNC_INFO BeforeAttachmentRead;
			extern _ATL_FUNC_INFO BeforeAttachmentWriteToTempFile;
			extern _ATL_FUNC_INFO BeforeAutoSave;
			extern _ATL_FUNC_INFO BeforeRead;
			extern _ATL_FUNC_INFO AfterWrite;
			extern _ATL_FUNC_INFO ReadComplete;
			extern _ATL_FUNC_INFO BeforeFolderMove;
			extern _ATL_FUNC_INFO BeforeItemMove;
			extern _ATL_FUNC_INFO NameSpaceOptionsPagesAdd;
			extern _ATL_FUNC_INFO NameSpaceAutoDiscoverComplete;
			extern _ATL_FUNC_INFO SelectedChange;
			extern _ATL_FUNC_INFO NavigationFolderAdd;
			extern _ATL_FUNC_INFO NavigationFolderRemove;
			extern _ATL_FUNC_INFO ModuleSwitch;
			extern _ATL_FUNC_INFO DoubleClick;
			extern _ATL_FUNC_INFO MouseDown;
			extern _ATL_FUNC_INFO MouseMove;
			extern _ATL_FUNC_INFO MouseUp;
			extern _ATL_FUNC_INFO Enter;
			extern _ATL_FUNC_INFO Exit;
			extern _ATL_FUNC_INFO KeyDown;
			extern _ATL_FUNC_INFO KeyPress;
			extern _ATL_FUNC_INFO KeyUp;
			extern _ATL_FUNC_INFO Unload;

			class COutLook_ViewsEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLook_ViewsEvents, &__uuidof(_ViewsEvents)>
			{
			public:
				virtual void __stdcall OnViewAdd(OutLook::View* View) {}
				virtual void __stdcall OnViewRemove(OutLook::View* View) {}

				BEGIN_SINK_MAP(COutLook_ViewsEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_ViewsEvents), /*dispid =*/ 0x00000190, OnViewAdd, &ViewAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_ViewsEvents), /*dispid =*/ 0x0000fa47, OnViewRemove, &ViewRemove)
				END_SINK_MAP()
			};

			class COutLookAccountSelectorEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookAccountSelectorEvents, &__uuidof(AccountSelectorEvents)>
			{
			public:
				virtual void __stdcall OnSelectedAccountChange(Account* SelectedAccount) {}

				BEGIN_SINK_MAP(COutLookAccountSelectorEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AccountSelectorEvents), /*dispid =*/ 0x0000fc73, OnSelectedAccountChange, &SelectedAccountChange)
				END_SINK_MAP()
			};

			class COutLookAccountsEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookAccountsEvents, &__uuidof(AccountsEvents)>
			{
			public:
				virtual void __stdcall OnAutoDiscoverComplete(Account* Account) {}

				BEGIN_SINK_MAP(COutLookAccountsEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AccountsEvents), /*dispid =*/ 0x0000fc6c, OnAutoDiscoverComplete, &AutoDiscoverComplete)
				END_SINK_MAP()
			};

			class COutLookApplicationEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookApplicationEvents, &__uuidof(OutLook::ApplicationEvents)>
			{
			public:
				virtual void __stdcall OnItemSend(IDispatch* Item, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnNewMail() {}
				virtual void __stdcall OnReminder(IDispatch* Item) {}
				virtual void __stdcall OnOptionsPagesAdd(PropertyPages* Pages) {}
				virtual void __stdcall OnStartup() {}
				virtual void __stdcall OnQuit() {}

				BEGIN_SINK_MAP(COutLookApplicationEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutLook::ApplicationEvents), /*dispid =*/ 0x0000f002, OnItemSend, &ItemSend)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutLook::ApplicationEvents), /*dispid =*/ 0x0000f003, OnNewMail, &NewMail)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutLook::ApplicationEvents), /*dispid =*/ 0x0000f004, OnReminder, &Reminder)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutLook::ApplicationEvents), /*dispid =*/ 0x0000f005, OnOptionsPagesAdd, &OptionsPagesAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutLook::ApplicationEvents), /*dispid =*/ 0x0000f006, OnStartup, &Startup)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutLook::ApplicationEvents), /*dispid =*/ 0x0000f007, OnQuit, &Quit)
				END_SINK_MAP()
			};

			class COutLookApplicationEvents_10 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookApplicationEvents_10, &__uuidof(ApplicationEvents_10)>
			{
			public:
				virtual void __stdcall OnAdvancedSearchComplete(Search* SearchObject) {}
				virtual void __stdcall OnAdvancedSearchStopped(Search* SearchObject) {}
				virtual void __stdcall OnMAPILogonComplete() {}

				BEGIN_SINK_MAP(COutLookApplicationEvents_10)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_10), /*dispid =*/ 0x0000fa6a, OnAdvancedSearchComplete, &AdvancedSearchComplete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_10), /*dispid =*/ 0x0000fa6b, OnAdvancedSearchStopped, &AdvancedSearchStopped)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_10), /*dispid =*/ 0x0000fa90, OnMAPILogonComplete, &MAPILogonComplete)
				END_SINK_MAP()
			};

			class COutLookApplicationEvents_11 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookApplicationEvents_11, &__uuidof(ApplicationEvents_11)>
			{
			public:
				virtual void __stdcall OnQuit() {}
				virtual void __stdcall OnNewMailEx(BSTR EntryIDCollection) {}
				virtual void __stdcall OnAttachmentContextMenuDisplay(CommandBar* CommandBar, AttachmentSelection* Attachments) {}
				virtual void __stdcall OnFolderContextMenuDisplay(CommandBar* CommandBar, OutLook::Folder* Folder) {}
				virtual void __stdcall OnStoreContextMenuDisplay(CommandBar* CommandBar, Store* Store) {}
				virtual void __stdcall OnShortcutContextMenuDisplay(CommandBar* CommandBar, OutlookBarShortcut* Shortcut) {}
				virtual void __stdcall OnViewContextMenuDisplay(CommandBar* CommandBar, OutLook::View* View) {}
				virtual void __stdcall OnItemContextMenuDisplay(CommandBar* CommandBar, OutLook::Selection* Selection) {}
				virtual void __stdcall OnContextMenuClose(OlContextMenu ContextMenu) {}
				virtual void __stdcall OnItemLoad(IDispatch* Item) {}
				virtual void __stdcall OnBeforeFolderSharingDialog(MAPIFolder* FolderToShare, VARIANT_BOOL* Cancel) {}

				BEGIN_SINK_MAP(COutLookApplicationEvents_11)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000f007, OnQuit, &Quit)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fab5, OnNewMailEx, &NewMailEx)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fb3e, OnAttachmentContextMenuDisplay, &AttachmentContextMenuDisplay)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fb42, OnFolderContextMenuDisplay, &FolderContextMenuDisplay)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fb43, OnStoreContextMenuDisplay, &StoreContextMenuDisplay)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fb44, OnShortcutContextMenuDisplay, &ShortcutContextMenuDisplay)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fb40, OnViewContextMenuDisplay, &ViewContextMenuDisplay)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fb41, OnItemContextMenuDisplay, &ItemContextMenuDisplay)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fba6, OnContextMenuClose, &ContextMenuClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fba7, OnItemLoad, &ItemLoad)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ApplicationEvents_11), /*dispid =*/ 0x0000fc01, OnBeforeFolderSharingDialog, &BeforeFolderSharingDialog)
				END_SINK_MAP()
			};

			class COutLookExplorerEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookExplorerEvents, &__uuidof(ExplorerEvents)>
			{
			public:
				virtual void __stdcall OnActivate() {}
				virtual void __stdcall OnFolderSwitch() {}
				virtual void __stdcall OnBeforeFolderSwitch(IDispatch* NewFolder, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnViewSwitch() {}
				virtual void __stdcall OnBeforeViewSwitch(VARIANT NewView, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnDeactivate() {}
				virtual void __stdcall OnSelectionChange() {}
				virtual void __stdcall OnClose() {}

				BEGIN_SINK_MAP(COutLookExplorerEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f001, OnActivate, &Activate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f002, OnFolderSwitch, &FolderSwitch)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f003, OnBeforeFolderSwitch, &BeforeFolderSwitch)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f004, OnViewSwitch, &ViewSwitch)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f005, OnBeforeViewSwitch, &BeforeViewSwitch)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f006, OnDeactivate, &Deactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f007, OnSelectionChange, &SelectionChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents), /*dispid =*/ 0x0000f008, OnClose, &Close)
				END_SINK_MAP()
			};

			class COutLookExplorerEvents_10 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookExplorerEvents_10, &__uuidof(ExplorerEvents_10)>
			{
			public:
				virtual void __stdcall OnBeforeMaximize(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeMinimize(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeMove(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeSize(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeItemCopy(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeItemCut(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeItemPaste(VARIANT* ClipboardContent, MAPIFolder* Target, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnAttachmentSelectionChange() {}
				virtual void __stdcall OnInlineResponse(IDispatch* Item) {}
				virtual void __stdcall OnInlineResponseClose() {}

				BEGIN_SINK_MAP(COutLookExplorerEvents_10)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fa11, OnBeforeMaximize, &BeforeMaximize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fa12, OnBeforeMinimize, &BeforeMinimize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fa13, OnBeforeMove, &BeforeMove)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fa14, OnBeforeSize, &BeforeSize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fa0e, OnBeforeItemCopy, &BeforeItemCopy)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fa0f, OnBeforeItemCut, &BeforeItemCut)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fa10, OnBeforeItemPaste, &BeforeItemPaste)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fc79, OnAttachmentSelectionChange, &AttachmentSelectionChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fc92, OnInlineResponse, &InlineResponse)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorerEvents_10), /*dispid =*/ 0x0000fc96, OnInlineResponseClose, &InlineResponseClose)
				END_SINK_MAP()
			};

			class COutLookExplorersEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookExplorersEvents, &__uuidof(ExplorersEvents)>
			{
			public:
				virtual void __stdcall OnNewExplorer(_Explorer* Explorer) {}

				BEGIN_SINK_MAP(COutLookExplorersEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ExplorersEvents), /*dispid =*/ 0x0000f001, OnNewExplorer, &NewExplorer)
				END_SINK_MAP()
			};

			class COutLookFoldersEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookFoldersEvents, &__uuidof(FoldersEvents)>
			{
			public:
				virtual void __stdcall OnFolderAdd(MAPIFolder* Folder) {}
				virtual void __stdcall OnFolderChange(MAPIFolder* Folder) {}
				virtual void __stdcall OnFolderRemove() {}

				BEGIN_SINK_MAP(COutLookFoldersEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(FoldersEvents), /*dispid =*/ 0x0000f001, OnFolderAdd, &FolderAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(FoldersEvents), /*dispid =*/ 0x0000f002, OnFolderChange, &FolderChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(FoldersEvents), /*dispid =*/ 0x0000f003, OnFolderRemove, &FolderRemove)
				END_SINK_MAP()
			};

			class COutLookFormRegionEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookFormRegionEvents, &__uuidof(FormRegionEvents)>
			{
			public:
				virtual void __stdcall OnExpanded(VARIANT_BOOL Expand) {}
				virtual void __stdcall OnClose() {}

				BEGIN_SINK_MAP(COutLookFormRegionEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(FormRegionEvents), /*dispid =*/ 0x0000fb38, OnExpanded, &Expanded)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(FormRegionEvents), /*dispid =*/ 0x0000f004, OnClose, &Close)
				END_SINK_MAP()
			};

			class COutLookInspectorEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookInspectorEvents, &__uuidof(InspectorEvents)>
			{
			public:
				virtual void __stdcall OnActivate() {}
				virtual void __stdcall OnDeactivate() {}
				virtual void __stdcall OnClose() {}

				BEGIN_SINK_MAP(COutLookInspectorEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents), /*dispid =*/ 0x0000f001, OnActivate, &Activate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents), /*dispid =*/ 0x0000f006, OnDeactivate, &Deactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents), /*dispid =*/ 0x0000f008, OnClose, &Close)
				END_SINK_MAP()
			};

			class COutLookInspectorEvents_10 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookInspectorEvents_10, &__uuidof(InspectorEvents_10)>
			{
			public:
				virtual void __stdcall OnBeforeMaximize(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeMinimize(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeMove(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeSize(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnPageChange(BSTR ActivePageName) {}
				virtual void __stdcall OnAttachmentSelectionChange() {}

				BEGIN_SINK_MAP(COutLookInspectorEvents_10)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents_10), /*dispid =*/ 0x0000fa11, OnBeforeMaximize, &BeforeMaximize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents_10), /*dispid =*/ 0x0000fa12, OnBeforeMinimize, &BeforeMinimize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents_10), /*dispid =*/ 0x0000fa13, OnBeforeMove, &BeforeMove)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents_10), /*dispid =*/ 0x0000fa14, OnBeforeSize, &BeforeSize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents_10), /*dispid =*/ 0x0000fbf4, OnPageChange, &PageChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorEvents_10), /*dispid =*/ 0x0000fc79, OnAttachmentSelectionChange, &AttachmentSelectionChange)
				END_SINK_MAP()
			};

			class COutLookInspectorsEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookInspectorsEvents, &__uuidof(InspectorsEvents)>
			{
			public:
				virtual void __stdcall OnNewInspector(_Inspector* Inspector) {}

				BEGIN_SINK_MAP(COutLookInspectorsEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(InspectorsEvents), /*dispid =*/ 0x0000f001, OnNewInspector, &NewInspector)
				END_SINK_MAP()
			};

			class COutLookItemEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookItemEvents, &__uuidof(ItemEvents)>
			{
			public:
				virtual void __stdcall OnOpen(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnCustomAction(IDispatch* Action, IDispatch* Response, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnCustomPropertyChange(BSTR Name) {}
				virtual void __stdcall OnForward(IDispatch* Forward, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnClose(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnPropertyChange(BSTR Name) {}
				virtual void __stdcall OnRead() {}
				virtual void __stdcall OnReply(IDispatch* Response, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnReplyAll(IDispatch* Response, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSend(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnWrite(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeCheckNames(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnAttachmentAdd(OutLook::Attachment* Attachment) {}
				virtual void __stdcall OnAttachmentRead(OutLook::Attachment* Attachment) {}
				virtual void __stdcall OnBeforeAttachmentSave(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel) {}

				BEGIN_SINK_MAP(COutLookItemEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f003, OnOpen, &Open)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f006, OnCustomAction, &CustomAction)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f008, OnCustomPropertyChange, &CustomPropertyChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f468, OnForward, &Forward)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f004, OnClose, &ItemClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f009, OnPropertyChange, &PropertyChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f001, OnRead, &Read)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f466, OnReply, &Reply)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f467, OnReplyAll, &ReplyAll)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f005, OnSend, &Send)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f002, OnWrite, &Write)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f00a, OnBeforeCheckNames, &BeforeCheckNames)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f00b, OnAttachmentAdd, &AttachmentAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f00c, OnAttachmentRead, &AttachmentRead)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents), /*dispid =*/ 0x0000f00d, OnBeforeAttachmentSave, &BeforeAttachmentSave)
				END_SINK_MAP()
			};

			class COutLookItemEvents_10 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookItemEvents_10, &__uuidof(ItemEvents_10)>
			{
			public:
				virtual void __stdcall OnBeforeDelete(IDispatch* Item, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnAttachmentRemove(OutLook::Attachment* Attachment) {}
				virtual void __stdcall OnBeforeAttachmentAdd(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeAttachmentPreview(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeAttachmentRead(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeAttachmentWriteToTempFile(OutLook::Attachment* Attachment, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnUnload() {}
				virtual void __stdcall OnBeforeAutoSave(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeRead() {}
				virtual void __stdcall OnAfterWrite() {}
				virtual void __stdcall OnReadComplete(VARIANT_BOOL* Cancel) {}

				BEGIN_SINK_MAP(COutLookItemEvents_10)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fa75, OnBeforeDelete, &BeforeDelete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fbae, OnAttachmentRemove, &AttachmentRemove)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fbb0, OnBeforeAttachmentAdd, &BeforeAttachmentAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fbaf, OnBeforeAttachmentPreview, &BeforeAttachmentPreview)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fbab, OnBeforeAttachmentRead, &BeforeAttachmentRead)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fbb2, OnBeforeAttachmentWriteToTempFile, &BeforeAttachmentWriteToTempFile)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fbad, OnUnload, &Unload)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fc02, OnBeforeAutoSave, &BeforeAutoSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fc8c, OnBeforeRead, &BeforeRead)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fc8d, OnAfterWrite, &AfterWrite)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemEvents_10), /*dispid =*/ 0x0000fc8f, OnReadComplete, &ReadComplete)
				END_SINK_MAP()
			};

			class COutLookItemsEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookItemsEvents, &__uuidof(ItemsEvents)>
			{
			public:
				virtual void __stdcall OnItemAdd(IDispatch* Item) {}
				virtual void __stdcall OnItemChange(IDispatch* Item) {}
				virtual void __stdcall OnItemRemove() {}

				BEGIN_SINK_MAP(COutLookItemsEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemsEvents), /*dispid =*/ 0x0000f001, OnItemAdd, &ItemAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemsEvents), /*dispid =*/ 0x0000f002, OnItemChange, &ItemChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ItemsEvents), /*dispid =*/ 0x0000f003, OnItemRemove, &ItemRemove)
				END_SINK_MAP()
			};

			class COutLookMAPIFolderEvents_12 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookMAPIFolderEvents_12, &__uuidof(MAPIFolderEvents_12)>
			{
			public:
				virtual void __stdcall OnBeforeFolderMove(MAPIFolder* MoveTo, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeItemMove(IDispatch* Item, MAPIFolder* MoveTo, VARIANT_BOOL* Cancel) {}

				BEGIN_SINK_MAP(COutLookMAPIFolderEvents_12)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(MAPIFolderEvents_12), /*dispid =*/ 0x0000fba8, OnBeforeFolderMove, &BeforeFolderMove)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(MAPIFolderEvents_12), /*dispid =*/ 0x0000fba9, OnBeforeItemMove, &BeforeItemMove)
				END_SINK_MAP()
			};

			class COutLookNameSpaceEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookNameSpaceEvents, &__uuidof(NameSpaceEvents)>
			{
			public:
				virtual void __stdcall OnOptionsPagesAdd(PropertyPages* Pages, MAPIFolder* Folder) {}
				virtual void __stdcall OnAutoDiscoverComplete() {}

				BEGIN_SINK_MAP(COutLookNameSpaceEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(NameSpaceEvents), /*dispid =*/ 0x0000f005, OnOptionsPagesAdd, &NameSpaceOptionsPagesAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(NameSpaceEvents), /*dispid =*/ 0x0000fc2d, OnAutoDiscoverComplete, &NameSpaceAutoDiscoverComplete)
				END_SINK_MAP()
			};

			class COutLookNavigationGroupsEvents_12 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookNavigationGroupsEvents_12, &__uuidof(NavigationGroupsEvents_12)>
			{
			public:
				virtual void __stdcall OnSelectedChange(NavigationFolder* NavigationFolder) {}
				virtual void __stdcall OnNavigationFolderAdd(NavigationFolder* NavigationFolder) {}
				virtual void __stdcall OnNavigationFolderRemove() {}

				BEGIN_SINK_MAP(COutLookNavigationGroupsEvents_12)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(NavigationGroupsEvents_12), /*dispid =*/ 0x0000fbca, OnSelectedChange, &SelectedChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(NavigationGroupsEvents_12), /*dispid =*/ 0x0000fbcb, OnNavigationFolderAdd, &NavigationFolderAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(NavigationGroupsEvents_12), /*dispid =*/ 0x0000fbcc, OnNavigationFolderRemove, &NavigationFolderRemove)
				END_SINK_MAP()
			};

			class COutLookNavigationPaneEvents_12 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookNavigationPaneEvents_12, &__uuidof(NavigationPaneEvents_12)>
			{
			public:
				virtual void __stdcall OnModuleSwitch(NavigationModule* CurrentModule) {}

				BEGIN_SINK_MAP(COutLookNavigationPaneEvents_12)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(NavigationPaneEvents_12), /*dispid =*/ 0x0000fbc9, OnModuleSwitch, &ModuleSwitch)
				END_SINK_MAP()
			};

			//class COutLookOlkBusinessCardControlEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookOlkBusinessCardControlEvents, &__uuidof(OlkBusinessCardControlEvents)>
			//{
			//public:
			//	virtual void __stdcall OnClick() {}
			//	virtual void __stdcall OnDoubleClick() {}
			//	virtual void __stdcall OnMouseDown(OlMouseButton Button, OlShiftState Shift, OLE_XPOS_CONTAINER X, OLE_YPOS_CONTAINER Y) {}
			//	virtual void __stdcall OnMouseMove(OlMouseButton Button, OlShiftState Shift, OLE_XPOS_CONTAINER X, OLE_YPOS_CONTAINER Y) {}
			//	virtual void __stdcall OnMouseUp(OlMouseButton Button, OlShiftState Shift, OLE_XPOS_CONTAINER X, OLE_YPOS_CONTAINER Y) {}

			//	BEGIN_SINK_MAP(COutLookOlkBusinessCardControlEvents)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkBusinessCardControlEvents), /*dispid =*/ 0xfffffda8, OnClick, &Click)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkBusinessCardControlEvents), /*dispid =*/ 0xfffffda7, OnDoubleClick, &DoubleClick)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkBusinessCardControlEvents), /*dispid =*/ 0xfffffda3, OnMouseDown, &MouseDown)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkBusinessCardControlEvents), /*dispid =*/ 0xfffffda2, OnMouseMove, &MouseMove)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkBusinessCardControlEvents), /*dispid =*/ 0xfffffda1, OnMouseUp, &MouseUp)
			//	END_SINK_MAP()
			//};

			//class COutLookOlkCategoryEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookOlkCategoryEvents, &__uuidof(OlkCategoryEvents)>
			//{
			//public:
			//	virtual void __stdcall OnClick() {}
			//	virtual void __stdcall OnDoubleClick() {}
			//	virtual void __stdcall OnMouseDown(OlMouseButton Button, OlShiftState Shift, OLE_XPOS_CONTAINER X, OLE_YPOS_CONTAINER Y) {}
			//	virtual void __stdcall OnMouseMove(OlMouseButton Button, OlShiftState Shift, OLE_XPOS_CONTAINER X, OLE_YPOS_CONTAINER Y) {}
			//	virtual void __stdcall OnMouseUp(OlMouseButton Button, OlShiftState Shift, OLE_XPOS_CONTAINER X, OLE_YPOS_CONTAINER Y) {}
			//	virtual void __stdcall OnEnter() {}
			//	virtual void __stdcall OnExit(VARIANT_BOOL* Cancel) {}
			//	virtual void __stdcall OnKeyDown(long* KeyCode, OlShiftState Shift) {}
			//	virtual void __stdcall OnKeyPress(long* KeyAscii) {}
			//	virtual void __stdcall OnKeyUp(long* KeyCode, OlShiftState Shift) {}
			//	virtual void __stdcall OnChange() {}

			//	BEGIN_SINK_MAP(COutLookOlkCategoryEvents)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda8, OnClick, &Click)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda7, OnDoubleClick, &DoubleClick)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda3, OnMouseDown, &MouseDown)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda2, OnMouseMove, &MouseMove)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda1, OnMouseUp, &MouseUp)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0x80018202, OnEnter, &Enter)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0x80018203, OnExit, &Exit)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda6, OnKeyDown, &KeyDown)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda5, OnKeyPress, &KeyPress)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0xfffffda4, OnKeyUp, &KeyUp)
			//		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OlkCategoryEvents), /*dispid =*/ 0x00000002, OnChange, &Change)
			//	END_SINK_MAP()
			//};

			class COutLookBarGroupsEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookBarGroupsEvents, &__uuidof(OutlookBarGroupsEvents)>
			{
			public:
				virtual void __stdcall OnGroupAdd(OutlookBarGroup* NewGroup) {}
				virtual void __stdcall OnBeforeGroupAdd(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeGroupRemove(OutlookBarGroup* Group, VARIANT_BOOL* Cancel) {}

				BEGIN_SINK_MAP(COutLookBarGroupsEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarGroupsEvents), /*dispid =*/ 0x0000f001, OnGroupAdd, &GroupAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarGroupsEvents), /*dispid =*/ 0x0000f002, OnBeforeGroupAdd, &BeforeGroupAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarGroupsEvents), /*dispid =*/ 0x0000f003, OnBeforeGroupRemove, &BeforeGroupRemove)
				END_SINK_MAP()
			};

			class COutLookBarPaneEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookBarPaneEvents, &__uuidof(OutlookBarPaneEvents)>
			{
			public:
				virtual void __stdcall OnBeforeNavigate(OutlookBarShortcut* Shortcut, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeGroupSwitch(OutlookBarGroup* ToGroup, VARIANT_BOOL* Cancel) {}

				BEGIN_SINK_MAP(COutLookBarPaneEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarPaneEvents), /*dispid =*/ 0x0000f001, OnBeforeNavigate, &BeforeNavigate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarPaneEvents), /*dispid =*/ 0x0000f002, OnBeforeGroupSwitch, &BeforeGroupSwitch)
				END_SINK_MAP()
			};

			class COutLookBarShortcutsEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookBarShortcutsEvents, &__uuidof(OutlookBarShortcutsEvents)>
			{
			public:
				virtual void __stdcall OnShortcutAdd(OutlookBarShortcut* NewShortcut) {}
				virtual void __stdcall OnBeforeShortcutAdd(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeShortcutRemove(OutlookBarShortcut* Shortcut, VARIANT_BOOL* Cancel) {}

				BEGIN_SINK_MAP(COutLookBarShortcutsEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarShortcutsEvents), /*dispid =*/ 0x0000f001, OnShortcutAdd, &ShortcutAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarShortcutsEvents), /*dispid =*/ 0x0000f002, OnBeforeShortcutAdd, &BeforeShortcutAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(OutlookBarShortcutsEvents), /*dispid =*/ 0x0000f003, OnBeforeShortcutRemove, &BeforeShortcutRemove)
				END_SINK_MAP()
			};

			class COutLookReminderCollectionEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookReminderCollectionEvents, &__uuidof(ReminderCollectionEvents)>
			{
			public:
				virtual void __stdcall OnBeforeReminderShow(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnReminderAdd(_Reminder* ReminderObject) {}
				virtual void __stdcall OnReminderChange(_Reminder* ReminderObject) {}
				virtual void __stdcall OnReminderFire(_Reminder* ReminderObject) {}
				virtual void __stdcall OnReminderRemove() {}
				virtual void __stdcall OnSnooze(_Reminder* ReminderObject) {}

				BEGIN_SINK_MAP(COutLookReminderCollectionEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ReminderCollectionEvents), /*dispid =*/ 0x0000fa93, OnBeforeReminderShow, &BeforeReminderShow)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ReminderCollectionEvents), /*dispid =*/ 0x0000fa94, OnReminderAdd, &ReminderAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ReminderCollectionEvents), /*dispid =*/ 0x0000fa95, OnReminderChange, &ReminderChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ReminderCollectionEvents), /*dispid =*/ 0x0000fa96, OnReminderFire, &ReminderFire)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ReminderCollectionEvents), /*dispid =*/ 0x0000fa97, OnReminderRemove, &ReminderRemove)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ReminderCollectionEvents), /*dispid =*/ 0x0000fa98, OnSnooze, &Snooze)
				END_SINK_MAP()
			};

			class COutLookResultsEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookResultsEvents, &__uuidof(ResultsEvents)>
			{
			public:
				virtual void __stdcall OnItemAdd(IDispatch* Item) {}
				virtual void __stdcall OnItemChange(IDispatch* Item) {}
				virtual void __stdcall OnItemRemove() {}

				BEGIN_SINK_MAP(COutLookResultsEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ResultsEvents), /*dispid =*/ 0x0000f001, OnItemAdd, &ItemAdd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ResultsEvents), /*dispid =*/ 0x0000f002, OnItemChange, &ItemChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ResultsEvents), /*dispid =*/ 0x0000f003, OnItemRemove, &ItemRemove)
				END_SINK_MAP()
			};

			class COutLookStoresEvents_12 : public IDispEventSimpleImpl</*nID =*/ 1, COutLookStoresEvents_12, &__uuidof(StoresEvents_12)>
			{
			public:
				virtual void __stdcall OnBeforeStoreRemove(_Store* Store, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnStoreAdd(_Store* Store) {}

				BEGIN_SINK_MAP(COutLookStoresEvents_12)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(StoresEvents_12), /*dispid =*/ 0x0000fbb1, OnBeforeStoreRemove, &BeforeStoreRemove)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(StoresEvents_12), /*dispid =*/ 0x0000f001, OnStoreAdd, &StoreAdd)
				END_SINK_MAP()
			};

			class COutLookSyncObjectEvents : public IDispEventSimpleImpl</*nID =*/ 1, COutLookSyncObjectEvents, &__uuidof(SyncObjectEvents)>
			{
			public:
				virtual void __stdcall OnSyncStart() {}
				virtual void __stdcall OnProgress(OlSyncState State, BSTR Description, long Value, long Max) {}
				virtual void __stdcall OnOnError(long Code, BSTR Description) {}
				virtual void __stdcall OnSyncEnd() {}

				BEGIN_SINK_MAP(COutLookSyncObjectEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(SyncObjectEvents), /*dispid =*/ 0x0000f001, OnSyncStart, &SyncStart)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(SyncObjectEvents), /*dispid =*/ 0x0000f002, OnProgress, &Progress)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(SyncObjectEvents), /*dispid =*/ 0x0000f003, OnOnError, &OnError)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(SyncObjectEvents), /*dispid =*/ 0x0000f004, OnSyncEnd, &SyncEnd)
				END_SINK_MAP()
			};

			class COUTLCTL_ViewCtlEvents : public IDispEventSimpleImpl</*nID =*/ 1, COUTLCTL_ViewCtlEvents, &__uuidof(ViewCtlEvents)>
			{
			public:
				virtual void __stdcall OnBeforeViewSwitch(BSTR newView, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnViewSwitch() {}
				virtual void __stdcall OnActivate() {}
				virtual void __stdcall OnSelectionChange() {}

				BEGIN_SINK_MAP(COUTLCTL_ViewCtlEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ViewCtlEvents), /*dispid =*/ 0x00000004, OnBeforeViewSwitch, &BeforeViewSwitch2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ViewCtlEvents), /*dispid =*/ 0x00000005, OnViewSwitch, &ViewSwitch)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ViewCtlEvents), /*dispid =*/ 0x00000414, OnActivate, &Activate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ViewCtlEvents), /*dispid =*/ 0x0000040d, OnSelectionChange, &SelectionChange)
				END_SINK_MAP()
			};
		}
	}
}