/********************************************************************************
*					Tangram Library - version 8.1								*
*********************************************************************************
* Copyright (C) 2006-2013 by Tangram Team.   All Rights Reserved.					*
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
* mailto:sunhuizlz@yeah.net
* http://www.cloudaddin.com
*
********************************************************************************/
#include "../../stdafx.h"
#include "ProjectPlusEvents.h"

namespace OfficePlus
{
	namespace ProjectPlus
	{
		namespace ProjectPlusEvent
		{
			_ATL_FUNC_INFO NewProject = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeTaskDelete = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeResourceDelete = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeAssignmentDelete = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeTaskChange = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4,VT_VARIANT,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeResourceChange = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4,VT_VARIANT,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeAssignmentChange = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4,VT_VARIANT,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeTaskNew = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeResourceNew = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeAssignmentNew = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeClose = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforePrint = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeSave = { CC_STDCALL,VT_EMPTY,3,VT_I4 | VT_BYREF,VT_BOOL,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProjectCalculate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };

			_ATL_FUNC_INFO WindowGoalAreaChange = { CC_STDCALL,VT_EMPTY,1,VT_I4 };
			_ATL_FUNC_INFO WindowSelectionChange = { CC_STDCALL,VT_EMPTY,3,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF,VT_VARIANT };
			_ATL_FUNC_INFO WindowBeforeViewChange = { CC_STDCALL,VT_EMPTY,5,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF,VT_BOOL,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO WindowViewChange = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF,VT_BOOL };
			_ATL_FUNC_INFO WindowActivate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO WindowDeactivate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO WindowSidepaneDisplayChange = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL };
			_ATL_FUNC_INFO WindowSidepaneTaskChange = { CC_STDCALL,VT_EMPTY,3,VT_I4 | VT_BYREF,VT_I4,VT_BOOL };
			_ATL_FUNC_INFO WorkpaneDisplayChange = { CC_STDCALL,VT_EMPTY,1,VT_BOOL };
			_ATL_FUNC_INFO LoadWebPage = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BSTR | VT_BYREF };
			_ATL_FUNC_INFO ProjectAfterSave = { CC_STDCALL,VT_EMPTY,0,NULL };
			_ATL_FUNC_INFO ProjectTaskNew = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 };
			_ATL_FUNC_INFO ProjectResourceNew = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 };
			_ATL_FUNC_INFO ProjectAssignmentNew = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 };
			//_ATL_FUNC_INFO ProjectBeforeSaveBaseline = {CC_STDCALL,VT_EMPTY,9,
			//	VT_I4|VT_BYREF,
			//	VT_BOOL,
			//	VT_I2,
			//	VT_I2,
			//	VT_I2,
			//	VT_BOOL,
			//	VT_BOOL,
			//	VT_BOOL,
			//	VT_I4|VT_BYREF};
			_ATL_FUNC_INFO ProjectBeforeClearBaseline = { CC_STDCALL,VT_EMPTY,6,VT_I4 | VT_BYREF,VT_BOOL,VT_I4,VT_I4,VT_BOOL,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeClose2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforePrint2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeSave2 = { CC_STDCALL,VT_EMPTY,3,VT_I4 | VT_BYREF,VT_BOOL,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeTaskDelete2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeResourceDelete2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeAssignmentDelete2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeTaskChange2 = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4,VT_VARIANT,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeResourceChange2 = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4,VT_VARIANT,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeAssignmentChange2 = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4,VT_VARIANT,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeTaskNew2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeResourceNew2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProjectBeforeAssignmentNew2 = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ApplicationBeforeClose = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO OnUndoOrRedo = { CC_STDCALL,VT_EMPTY,3,VT_BSTR, VT_BSTR,VT_BOOL };
			_ATL_FUNC_INFO AfterCubeBuilt = { CC_STDCALL,VT_EMPTY,1,VT_BSTR | VT_BYREF };
			_ATL_FUNC_INFO LoadWebPane = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BSTR | VT_BYREF };
			_ATL_FUNC_INFO JobStart = { CC_STDCALL,VT_EMPTY,5,VT_BSTR, VT_BSTR,VT_BSTR,VT_I4,VT_I4 };
			_ATL_FUNC_INFO JobCompleted = { CC_STDCALL,VT_EMPTY,5,VT_BSTR, VT_BSTR,VT_BSTR,VT_I4,VT_I4 };
			_ATL_FUNC_INFO SaveStartingToServer = { CC_STDCALL,VT_EMPTY,2,VT_BSTR, VT_BSTR };
			_ATL_FUNC_INFO SaveCompletedToServer = { CC_STDCALL,VT_EMPTY,2,VT_BSTR, VT_BSTR };
			_ATL_FUNC_INFO ProjectBeforePublish = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO PaneActivate = { CC_STDCALL,VT_EMPTY,0,NULL };
			_ATL_FUNC_INFO SecondaryViewChange = { CC_STDCALL,VT_EMPTY,4,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF,VT_BOOL };
			_ATL_FUNC_INFO IsFunctionalitySupported = { CC_STDCALL,VT_EMPTY,2,VT_BSTR, VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ConnectionStatusChanged = { CC_STDCALL,VT_EMPTY,1,VT_BOOL };

			_ATL_FUNC_INFO Open = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO BeforeClose = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO BeforeSave = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO BeforePrint = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO Calculate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO Change = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO Activate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO Deactivate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
		}
	}
}