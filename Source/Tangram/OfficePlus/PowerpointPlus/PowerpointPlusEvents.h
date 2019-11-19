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
using namespace Office; 
using namespace PowerPoint;

namespace OfficePlus
{
	namespace PowerPointPlus
	{
		namespace PowerPointPlusEvent
		{
			extern _ATL_FUNC_INFO WindowSelectionChange;
			extern _ATL_FUNC_INFO WindowBeforeRightClick;
			extern _ATL_FUNC_INFO WindowBeforeDoubleClick;
			extern _ATL_FUNC_INFO PresentationClose;
			extern _ATL_FUNC_INFO PresentationSave;
			extern _ATL_FUNC_INFO PresentationOpen;
			extern _ATL_FUNC_INFO NewPresentation;
			extern _ATL_FUNC_INFO PresentationNewSlide;
			extern _ATL_FUNC_INFO WindowActivate;
			extern _ATL_FUNC_INFO WindowDeactivate;
			extern _ATL_FUNC_INFO SlideShowBegin;
			extern _ATL_FUNC_INFO SlideShowNextBuild;
			extern _ATL_FUNC_INFO SlideShowNextSlide;
			extern _ATL_FUNC_INFO SlideShowEnd;
			extern _ATL_FUNC_INFO PresentationPrint;
			extern _ATL_FUNC_INFO SlideSelectionChanged;
			extern _ATL_FUNC_INFO ColorSchemeChanged;
			extern _ATL_FUNC_INFO PresentationBeforeSave;
			extern _ATL_FUNC_INFO SlideShowNextClick;
			extern _ATL_FUNC_INFO AfterNewPresentation;
			extern _ATL_FUNC_INFO AfterPresentationOpen;
			extern _ATL_FUNC_INFO PresentationSync;
			extern _ATL_FUNC_INFO SlideShowOnNext;
			extern _ATL_FUNC_INFO SlideShowOnPrevious;
			extern _ATL_FUNC_INFO PresentationBeforeClose;
			extern _ATL_FUNC_INFO ProtectedViewWindowOpen;
			extern _ATL_FUNC_INFO ProtectedViewWindowBeforeEdit;
			extern _ATL_FUNC_INFO ProtectedViewWindowBeforeClose;
			extern _ATL_FUNC_INFO ProtectedViewWindowActivate;
			extern _ATL_FUNC_INFO ProtectedViewWindowDeactivate;
			extern _ATL_FUNC_INFO PresentationCloseFinal;
			extern _ATL_FUNC_INFO AfterDragDropOnSlide;
			extern _ATL_FUNC_INFO AfterShapeSizeChange;

			class CPowerpointPlusEApplication : public IDispEventSimpleImpl</*nID =*/ 1, CPowerpointPlusEApplication, &__uuidof(EApplication)>
			{
			public:
				virtual void __stdcall OnWindowSelectionChange(PowerPoint::Selection* Sel) {}
				virtual void __stdcall OnWindowBeforeRightClick(PowerPoint::Selection* Sel, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnWindowBeforeDoubleClick(/*[in]*/ PowerPoint::Selection * Sel,	/*[in,out]*/ VARIANT_BOOL * Cancel) {};
				virtual void __stdcall OnPresentationClose(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnPresentationSave(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnPresentationOpen(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnNewPresentation(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnPresentationNewSlide(/*[in]*/ _Slide * Sld) {};
				virtual void __stdcall OnWindowActivate(/*[in]*/ _Presentation * Pres,/*[in]*/ DocumentWindow * Wn) {};
				virtual void __stdcall OnWindowDeactivate(/*[in]*/ _Presentation * Pres,/*[in]*/ DocumentWindow * Wn) {};
				virtual void __stdcall OnSlideShowBegin(/*[in]*/ SlideShowWindow * Wn) {};
				virtual void __stdcall OnSlideShowNextBuild(/*[in]*/ SlideShowWindow * Wn) {};
				virtual void __stdcall OnSlideShowNextSlide(/*[in]*/ SlideShowWindow * Wn) {};
				virtual void __stdcall OnSlideShowEnd(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnPresentationPrint(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnSlideSelectionChanged(/*[in]*/ SlideRange * SldRange) {};
				virtual void __stdcall OnColorSchemeChanged(/*[in]*/ SlideRange * SldRange) {};
				virtual void __stdcall OnPresentationBeforeSave(/*[in]*/ _Presentation * Pres,	/*[in,out]*/ VARIANT_BOOL * Cancel) {};
				virtual void __stdcall OnSlideShowNextClick(/*[in]*/ SlideShowWindow * Wn,/*[in]*/ Effect * nEffect) {};
				virtual void __stdcall OnAfterNewPresentation(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnAfterPresentationOpen(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnPresentationSync(/*[in]*/ _Presentation * Pres,/*[in]*/ enum Office::MsoSyncEventType SyncEventType) {};
				virtual void __stdcall OnSlideShowOnNext(/*[in]*/ SlideShowWindow * Wn) {};
				virtual void __stdcall OnSlideShowOnPrevious(/*[in]*/ SlideShowWindow * Wn) {};
				virtual void __stdcall OnPresentationBeforeClose(/*[in]*/ _Presentation * Pres,	/*[in,out]*/ VARIANT_BOOL * Cancel) {};
				virtual void __stdcall OnProtectedViewWindowOpen(/*[in]*/ PowerPoint::ProtectedViewWindow * ProtViewWindow) {};
				virtual void __stdcall OnProtectedViewWindowBeforeEdit(/*[in]*/ PowerPoint::ProtectedViewWindow * ProtViewWindow,	/*[in,out]*/ VARIANT_BOOL * Cancel) {};
				virtual void __stdcall OnProtectedViewWindowBeforeClose(/*[in]*/ PowerPoint::ProtectedViewWindow * ProtViewWindow,/*[in]*/ enum PpProtectedViewCloseReason ProtectedViewCloseReason,	/*[in,out]*/ VARIANT_BOOL * Cancel) {};
				virtual void __stdcall OnProtectedViewWindowActivate(/*[in]*/ PowerPoint::ProtectedViewWindow * ProtViewWindow) {};
				virtual void __stdcall OnProtectedViewWindowDeactivate(/*[in]*/ PowerPoint::ProtectedViewWindow * ProtViewWindow) {};
				virtual void __stdcall OnPresentationCloseFinal(/*[in]*/ _Presentation * Pres) {};
				virtual void __stdcall OnAfterDragDropOnSlide(/*[in]*/ _Slide * Sld,	/*[in]*/ float X,	/*[in]*/ float Y) {};
				virtual void __stdcall OnAfterShapeSizeChange(/*[in]*/ PowerPoint::Shape * shp) {};

				BEGIN_SINK_MAP(CPowerpointPlusEApplication)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =3251*/ 2001, OnWindowSelectionChange, &WindowSelectionChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2002, OnWindowBeforeRightClick, &WindowBeforeRightClick)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2003, OnWindowBeforeDoubleClick, &WindowBeforeDoubleClick)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2004, OnPresentationClose, &PresentationClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2005, OnPresentationSave, &PresentationSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2006, OnPresentationOpen, &PresentationOpen)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2007, OnNewPresentation, &NewPresentation)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2008, OnPresentationNewSlide, &PresentationNewSlide)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2009, OnWindowActivate, &WindowActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2010, OnWindowDeactivate, &WindowDeactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2011, OnSlideShowBegin, &SlideShowBegin)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2012, OnSlideShowNextBuild, &SlideShowNextBuild)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2013, OnSlideShowNextSlide, &SlideShowNextSlide)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2014, OnSlideShowEnd, &SlideShowEnd)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2015, OnPresentationPrint, &PresentationPrint)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2016, OnSlideSelectionChanged, &SlideSelectionChanged)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2017, OnColorSchemeChanged, &ColorSchemeChanged)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2018, OnPresentationBeforeSave, &PresentationBeforeSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2019, OnSlideShowNextClick, &SlideShowNextClick)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2020, OnAfterNewPresentation, &AfterNewPresentation)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2021, OnAfterPresentationOpen, &AfterPresentationOpen)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2022, OnPresentationSync, &PresentationSync)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2023, OnSlideShowOnNext, &SlideShowOnNext)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2024, OnSlideShowOnPrevious, &SlideShowOnPrevious)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2025, OnPresentationBeforeClose, &PresentationBeforeClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2026, OnProtectedViewWindowOpen, &ProtectedViewWindowOpen)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2027, OnProtectedViewWindowBeforeEdit, &ProtectedViewWindowBeforeEdit)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2028, OnProtectedViewWindowBeforeClose, &ProtectedViewWindowBeforeClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2029, OnProtectedViewWindowActivate, &ProtectedViewWindowActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2030, OnProtectedViewWindowDeactivate, &ProtectedViewWindowDeactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2031, OnPresentationCloseFinal, &PresentationCloseFinal)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid =*/ 2032, OnAfterDragDropOnSlide, &AfterDragDropOnSlide)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(EApplication), /*dispid = 3283*/ 2033, OnAfterShapeSizeChange, &AfterShapeSizeChange)
				END_SINK_MAP()
			};
		}
	}
}