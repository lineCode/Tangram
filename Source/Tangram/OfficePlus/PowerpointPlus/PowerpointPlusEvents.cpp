/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2006-2013 by Tangram Team.   All Rights Reserved.				*
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
#include "PowerPointPlusEvents.h"

namespace OfficePlus
{
	namespace PowerPointPlus
	{
		namespace PowerPointPlusEvent
		{
			_ATL_FUNC_INFO WindowSelectionChange = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO WindowBeforeRightClick = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO WindowBeforeDoubleClick = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO PresentationClose = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationSave = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationOpen = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO NewPresentation = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationNewSlide = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO WindowActivate = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO WindowDeactivate = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO SlideShowBegin = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO SlideShowNextBuild = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO SlideShowNextSlide = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO SlideShowEnd = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationPrint = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO SlideSelectionChanged = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ColorSchemeChanged = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationBeforeSave = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO SlideShowNextClick = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO AfterNewPresentation = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO AfterPresentationOpen = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationSync = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_I2 };
			_ATL_FUNC_INFO SlideShowOnNext = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO SlideShowOnPrevious = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationBeforeClose = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProtectedViewWindowOpen = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProtectedViewWindowBeforeEdit = { CC_STDCALL,VT_EMPTY,2,VT_I4 | VT_BYREF,VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProtectedViewWindowBeforeClose = { CC_STDCALL,VT_EMPTY,3,VT_I4 | VT_BYREF, VT_I2, VT_BOOL | VT_BYREF };
			_ATL_FUNC_INFO ProtectedViewWindowActivate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ProtectedViewWindowDeactivate = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO PresentationCloseFinal = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO AfterDragDropOnSlide = { CC_STDCALL,VT_EMPTY,3,VT_I4 | VT_BYREF,VT_DECIMAL,VT_DECIMAL };
			_ATL_FUNC_INFO AfterShapeSizeChange = { CC_STDCALL,VT_EMPTY,1,VT_I4 | VT_BYREF };
		}
	}
}
