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

#include "msprj.h"
using namespace Office; 
using namespace MSProject; 

namespace OfficePlus
{
	namespace ProjectPlus
	{
		namespace ProjectPlusEvent
		{
			extern _ATL_FUNC_INFO NewProject;
			extern _ATL_FUNC_INFO ProjectBeforeTaskDelete;
			extern _ATL_FUNC_INFO ProjectBeforeResourceDelete;
			extern _ATL_FUNC_INFO ProjectBeforeAssignmentDelete;
			extern _ATL_FUNC_INFO ProjectBeforeTaskChange;
			extern _ATL_FUNC_INFO ProjectBeforeResourceChange;
			extern _ATL_FUNC_INFO ProjectBeforeAssignmentChange;
			extern _ATL_FUNC_INFO ProjectBeforeTaskNew;
			extern _ATL_FUNC_INFO ProjectBeforeResourceNew;
			extern _ATL_FUNC_INFO ProjectBeforeAssignmentNew;
			extern _ATL_FUNC_INFO ProjectBeforeClose;
			extern _ATL_FUNC_INFO ProjectBeforePrint;
			extern _ATL_FUNC_INFO ProjectBeforeSave;
			extern _ATL_FUNC_INFO ProjectCalculate;
			class CTangramEProjectAppEvents : public IDispEventSimpleImpl</*nID =*/ 1, CTangramEProjectAppEvents, &__uuidof(_EProjectApp)>
			{
			public:
				virtual void __stdcall OnNewProject(_IProjectDoc * pj)
				{
				}

				virtual void __stdcall OnProjectBeforeTaskDelete(MSProject::Task * tsk, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeResourceDelete(Resource * res, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeAssignmentDelete(Assignment * asg, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeTaskChange(MSProject::Task * tsk, PjField Field, VARIANT NewVal, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeResourceChange(Resource * res, PjField Field, VARIANT NewVal, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeAssignmentChange(Assignment * asg, PjAssignmentField Field, VARIANT NewVal, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeTaskNew(_IProjectDoc * pj, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeResourceNew(_IProjectDoc * pj, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeAssignmentNew(_IProjectDoc * pj, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeClose(_IProjectDoc * pj, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforePrint(_IProjectDoc * pj, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectBeforeSave(_IProjectDoc * pj, VARIANT_BOOL SaveAsUi, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnProjectCalculate(_IProjectDoc * pj)
				{
				}
				BEGIN_SINK_MAP(CTangramEProjectAppEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000001, OnNewProject, &NewProject)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000006, OnProjectBeforeTaskDelete, &ProjectBeforeTaskDelete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000007, OnProjectBeforeResourceDelete, &ProjectBeforeResourceDelete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000008, OnProjectBeforeAssignmentDelete, &ProjectBeforeAssignmentDelete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000009, OnProjectBeforeTaskChange, &ProjectBeforeTaskChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x00000a, OnProjectBeforeResourceChange, &ProjectBeforeResourceChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x00000b, OnProjectBeforeAssignmentChange, &ProjectBeforeAssignmentChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x00000c, OnProjectBeforeTaskNew, &ProjectBeforeTaskNew)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x00000d, OnProjectBeforeResourceNew, &ProjectBeforeResourceNew)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x00000e, OnProjectBeforeAssignmentNew, &ProjectBeforeAssignmentNew)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000002, OnProjectBeforeClose, &ProjectBeforeClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000004, OnProjectBeforePrint, &ProjectBeforePrint)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000003, OnProjectBeforeSave, &ProjectBeforeSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp), /*dispid =*/ 0x000005, OnProjectCalculate, &ProjectCalculate)
				END_SINK_MAP()
			};

			extern _ATL_FUNC_INFO WindowGoalAreaChange;
			extern _ATL_FUNC_INFO WindowSelectionChange;
			extern _ATL_FUNC_INFO WindowBeforeViewChange;
			extern _ATL_FUNC_INFO WindowViewChange;
			extern _ATL_FUNC_INFO WindowActivate;
			extern _ATL_FUNC_INFO WindowDeactivate;
			extern _ATL_FUNC_INFO WindowSidepaneDisplayChange;
			extern _ATL_FUNC_INFO WindowSidepaneTaskChange;
			extern _ATL_FUNC_INFO WorkpaneDisplayChange;
			extern _ATL_FUNC_INFO LoadWebPage;
			extern _ATL_FUNC_INFO ProjectAfterSave;
			extern _ATL_FUNC_INFO ProjectTaskNew;
			extern _ATL_FUNC_INFO ProjectResourceNew;
			extern _ATL_FUNC_INFO ProjectAssignmentNew;
			//extern _ATL_FUNC_INFO ProjectBeforeSaveBaseline;
			extern _ATL_FUNC_INFO ProjectBeforeClearBaseline;
			extern _ATL_FUNC_INFO ProjectBeforeClose2;
			extern _ATL_FUNC_INFO ProjectBeforePrint2;
			extern _ATL_FUNC_INFO ProjectBeforeSave2;
			extern _ATL_FUNC_INFO ProjectBeforeTaskDelete2;
			extern _ATL_FUNC_INFO ProjectBeforeResourceDelete2;
			extern _ATL_FUNC_INFO ProjectBeforeAssignmentDelete2;
			extern _ATL_FUNC_INFO ProjectBeforeTaskChange2;
			extern _ATL_FUNC_INFO ProjectBeforeResourceChange2;
			extern _ATL_FUNC_INFO ProjectBeforeAssignmentChange2;
			extern _ATL_FUNC_INFO ProjectBeforeTaskNew2;
			extern _ATL_FUNC_INFO ProjectBeforeResourceNew2;
			extern _ATL_FUNC_INFO ProjectBeforeAssignmentNew2;
			extern _ATL_FUNC_INFO ApplicationBeforeClose;
			extern _ATL_FUNC_INFO OnUndoOrRedo;
			extern _ATL_FUNC_INFO AfterCubeBuilt;
			extern _ATL_FUNC_INFO LoadWebPane;
			extern _ATL_FUNC_INFO JobStart;
			extern _ATL_FUNC_INFO JobCompleted;
			extern _ATL_FUNC_INFO SaveStartingToServer;
			extern _ATL_FUNC_INFO SaveCompletedToServer;
			extern _ATL_FUNC_INFO ProjectBeforePublish;
			extern _ATL_FUNC_INFO PaneActivate;
			extern _ATL_FUNC_INFO SecondaryViewChange;
			extern _ATL_FUNC_INFO IsFunctionalitySupported;
			extern _ATL_FUNC_INFO ConnectionStatusChanged;
			class CTangramEProjectAppEvents2 : public IDispEventSimpleImpl</*nID =*/ 1, CTangramEProjectAppEvents2, &__uuidof(_EProjectApp2)>
			{
			public:
				virtual void __stdcall OnWindowGoalAreaChange(MSProject::Window * Window, long goalArea)
				{
				}

				virtual void __stdcall OnWindowSelectionChange(MSProject::Window * Window, MSProject::Selection * sel, VARIANT selType)
				{
				}

				virtual void __stdcall OnWindowBeforeViewChange(MSProject::Window * Window, MSProject::View * prevView, MSProject::View * newView, VARIANT_BOOL projectHasViewWindow, EventInfo * Info)
				{
				}

				virtual void __stdcall OnWindowViewChange(MSProject::Window * Window, MSProject::View * prevView, MSProject::View * newView, VARIANT_BOOL success)
				{
				}

				virtual void __stdcall OnWindowActivate(MSProject::Window * activatedWindow)
				{
				}

				virtual void __stdcall OnWindowDeactivate(MSProject::Window * deactivatedWindow)
				{
				}

				virtual void __stdcall OnWindowSidepaneDisplayChange(MSProject::Window * Window, VARIANT_BOOL Close)
				{
				}

				virtual void __stdcall OnWindowSidepaneTaskChange(MSProject::Window * Window, long ID, VARIANT_BOOL IsGoalArea)
				{
				}

				virtual void __stdcall OnWorkpaneDisplayChange(VARIANT_BOOL DisplayState)
				{
				}

				virtual void __stdcall OnLoadWebPage(MSProject::Window * Window, BSTR * TargetPage)
				{
				}

				virtual void __stdcall OnProjectAfterSave()
				{
				}

				virtual void __stdcall OnProjectTaskNew(_IProjectDoc * pj, long ID)
				{
				}

				virtual void __stdcall OnProjectResourceNew(_IProjectDoc * pj, long ID)
				{
				}

				virtual void __stdcall OnProjectAssignmentNew(_IProjectDoc * pj, long ID)
				{
				}

				//virtual void __stdcall OnProjectBeforeSaveBaseline (_IProjectDoc * pj, VARIANT_BOOL Interim, PjBaselines bl,PjSaveBaselineFrom InterimCopy,PjSaveBaselineTo InterimInto, VARIANT_BOOL AllTasks, VARIANT_BOOL RollupToSummaryTasks, VARIANT_BOOL RollupFromSubtasks,EventInfo * Info ) 
				//{
				//}

				virtual void __stdcall OnProjectBeforeClearBaseline(_IProjectDoc * pj, VARIANT_BOOL Interim, PjBaselines bl, PjSaveBaselineTo InterimFrom, VARIANT_BOOL AllTasks, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeClose2(_IProjectDoc * pj, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforePrint2(_IProjectDoc * pj, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeSave2(_IProjectDoc * pj, VARIANT_BOOL SaveAsUi, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeTaskDelete2(MSProject::Task * tsk, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeResourceDelete2(Resource * res, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeAssignmentDelete2(MSProject::Assignment * asg, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeTaskChange2(MSProject::Task * tsk, PjField Field, VARIANT NewVal, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeResourceChange2(Resource * res, PjField Field, VARIANT NewVal, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeAssignmentChange2(Assignment * asg, PjAssignmentField Field, VARIANT NewVal, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeTaskNew2(_IProjectDoc * pj, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeResourceNew2(_IProjectDoc * pj, EventInfo * Info)
				{
				}

				virtual void __stdcall OnProjectBeforeAssignmentNew2(_IProjectDoc * pj, EventInfo * Info)
				{
				}

				virtual void __stdcall OnApplicationBeforeClose(EventInfo * Info)
				{
				}

				virtual void __stdcall OnOnUndoOrRedo(BSTR bstrLabel, BSTR bstrGUID, VARIANT_BOOL fUndo)
				{
				}

				virtual void __stdcall OnAfterCubeBuilt(BSTR * CubeFileName)
				{
				}

				virtual void __stdcall OnLoadWebPane(MSProject::Window * Window, BSTR * TargetPage)
				{
				}

				virtual void __stdcall OnJobStart(BSTR bstrName, BSTR bstrprojGuid, BSTR bstrjobGuid, long jobType, long lResult)
				{
				}

				virtual void __stdcall OnJobCompleted(BSTR bstrName, BSTR bstrprojGuid, BSTR bstrjobGuid, long jobType, long lResult)
				{
				}

				virtual void __stdcall OnSaveStartingToServer(BSTR bstrName, BSTR bstrprojGuid)
				{
				}

				virtual void __stdcall OnSaveCompletedToServer(BSTR bstrName, BSTR bstrprojGuid)
				{
				}

				virtual void __stdcall OnProjectBeforePublish(_IProjectDoc * pj, VARIANT_BOOL * Cancel)
				{
				}

				virtual void __stdcall OnPaneActivate()
				{
				}

				virtual void __stdcall OnSecondaryViewChange(MSProject::Window * Window, MSProject::View * prevView, MSProject::View * newView, VARIANT_BOOL success)
				{
				}

				virtual void __stdcall OnIsFunctionalitySupported(BSTR bstrFunctionality, EventInfo * Info)
				{
				}

				virtual void __stdcall OnConnectionStatusChanged(VARIANT_BOOL online)
				{
				}
				BEGIN_SINK_MAP(CTangramEProjectAppEvents2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00000f, OnWindowGoalAreaChange, &WindowGoalAreaChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000010, OnWindowSelectionChange, &WindowSelectionChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000011, OnWindowBeforeViewChange, &WindowBeforeViewChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000012, OnWindowViewChange, &WindowViewChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000013, OnWindowActivate, &WindowActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000014, OnWindowDeactivate, &WindowDeactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000015, OnWindowSidepaneDisplayChange, &WindowSidepaneDisplayChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000016, OnWindowSidepaneTaskChange, &WindowSidepaneTaskChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000017, OnWorkpaneDisplayChange, &WorkpaneDisplayChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000018, OnLoadWebPage, &LoadWebPage)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000019, OnProjectAfterSave, &ProjectAfterSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00001a, OnProjectTaskNew, &ProjectTaskNew)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00001b, OnProjectResourceNew, &ProjectResourceNew)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00001c, OnProjectAssignmentNew, &ProjectAssignmentNew)
					//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00001d, OnProjectBeforeSaveBaseline, &ProjectBeforeSaveBaseline)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00001e, OnProjectBeforeClearBaseline, &ProjectBeforeClearBaseline)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x40000002, OnProjectBeforeClose2, &ProjectBeforeClose2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x40000004, OnProjectBeforePrint2, &ProjectBeforePrint2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x40000003, OnProjectBeforeSave2, &ProjectBeforeSave2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x40000006, OnProjectBeforeTaskDelete2, &ProjectBeforeTaskDelete2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x40000007, OnProjectBeforeResourceDelete2, &ProjectBeforeResourceDelete2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x40000008, OnProjectBeforeAssignmentDelete2, &ProjectBeforeAssignmentDelete2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x40000009, OnProjectBeforeTaskChange2, &ProjectBeforeTaskChange2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x4000000a, OnProjectBeforeResourceChange2, &ProjectBeforeResourceChange2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x4000000b, OnProjectBeforeAssignmentChange2, &ProjectBeforeAssignmentChange2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x4000000c, OnProjectBeforeTaskNew2, &ProjectBeforeTaskNew2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x4000000d, OnProjectBeforeResourceNew2, &ProjectBeforeResourceNew2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x4000000e, OnProjectBeforeAssignmentNew2, &ProjectBeforeAssignmentNew2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00001f, OnApplicationBeforeClose, &ApplicationBeforeClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000020, OnOnUndoOrRedo, &OnUndoOrRedo)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000021, OnAfterCubeBuilt, &AfterCubeBuilt)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000022, OnLoadWebPane, &LoadWebPane)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000023, OnJobStart, &JobStart)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000024, OnJobCompleted, &JobCompleted)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000025, OnSaveStartingToServer, &SaveStartingToServer)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000026, OnSaveCompletedToServer, &SaveCompletedToServer)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000027, OnProjectBeforePublish, &ProjectBeforePublish)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000028, OnPaneActivate, &PaneActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x000029, OnSecondaryViewChange, &SecondaryViewChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00002a, OnIsFunctionalitySupported, &IsFunctionalitySupported)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectApp2), /*dispid =*/ 0x00002b, OnConnectionStatusChanged, &ConnectionStatusChanged)
				END_SINK_MAP()
			};

			extern _ATL_FUNC_INFO Open;
			extern _ATL_FUNC_INFO BeforeClose;
			extern _ATL_FUNC_INFO BeforeSave;
			extern _ATL_FUNC_INFO BeforePrint;
			extern _ATL_FUNC_INFO Calculate;
			extern _ATL_FUNC_INFO Change;
			extern _ATL_FUNC_INFO Activate;
			extern _ATL_FUNC_INFO Deactivate;
			class CTangramEProjectDocEvents : public IDispEventSimpleImpl</*nID =*/ 1, CTangramEProjectDocEvents, &__uuidof(_EProjectDoc)>
			{
			public:
				virtual void __stdcall OnOpen(_IProjectDoc * pj) {}
				virtual void __stdcall OnBeforeClose(_IProjectDoc * pj) {}
				virtual void __stdcall OnBeforeSave(_IProjectDoc * pj) {}
				virtual void __stdcall OnBeforePrint(_IProjectDoc * pj) {}
				virtual void __stdcall OnCalculate(_IProjectDoc * pj) {}
				virtual void __stdcall OnChange(_IProjectDoc * pj) {}
				virtual void __stdcall OnActivate(_IProjectDoc * pj) {}
				virtual void __stdcall OnDeactivate(_IProjectDoc * pj) {}

				BEGIN_SINK_MAP(CTangramEProjectDocEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000001, OnOpen, &Open)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000002, OnBeforeClose, &BeforeClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000003, OnBeforeSave, &BeforeSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000004, OnBeforePrint, &BeforePrint)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000005, OnCalculate, &Calculate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000006, OnChange, &Change)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000007, OnActivate, &Activate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_EProjectDoc), /*dispid =*/ 0x000008, OnDeactivate, &Deactivate)
				END_SINK_MAP()
			};
		}
	}
}
