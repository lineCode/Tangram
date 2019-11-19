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

#include "excel.h"
using namespace Office; 
using namespace Excel; 

namespace OfficePlus
{
	namespace ExcelPlus
	{
		namespace ExcelPlusEvent
		{
			extern _ATL_FUNC_INFO Open;
			extern _ATL_FUNC_INFO Activate;
			extern _ATL_FUNC_INFO Deactivate;
			extern _ATL_FUNC_INFO BeforeClose;
			extern _ATL_FUNC_INFO BeforeSave;
			extern _ATL_FUNC_INFO BeforePrint;
			extern _ATL_FUNC_INFO NewSheet;
			extern _ATL_FUNC_INFO AddinInstall;
			extern _ATL_FUNC_INFO AddinUninstall;
			extern _ATL_FUNC_INFO WindowResize2;
			extern _ATL_FUNC_INFO WindowActivate2;
			extern _ATL_FUNC_INFO WindowDeactivate2;
			extern _ATL_FUNC_INFO SheetSelectionChange2;
			extern _ATL_FUNC_INFO SheetBeforeDoubleClick2;
			extern _ATL_FUNC_INFO SheetBeforeRightClick2;
			extern _ATL_FUNC_INFO SheetActivate2;
			extern _ATL_FUNC_INFO SheetDeactivate2;
			extern _ATL_FUNC_INFO SheetCalculate2;
			extern _ATL_FUNC_INFO SheetChange2;
			extern _ATL_FUNC_INFO SheetFollowHyperlink2;
			extern _ATL_FUNC_INFO SheetPivotTableUpdate2;
			extern _ATL_FUNC_INFO PivotTableCloseConnection2;
			extern _ATL_FUNC_INFO PivotTableOpenConnection2;
			extern _ATL_FUNC_INFO Sync2;
			extern _ATL_FUNC_INFO BeforeXmlImport2;
			extern _ATL_FUNC_INFO AfterXmlImport2;
			extern _ATL_FUNC_INFO BeforeXmlExport2;
			extern _ATL_FUNC_INFO AfterXmlExport2;
			extern _ATL_FUNC_INFO RowsetComplete2;
			extern _ATL_FUNC_INFO SheetPivotTableAfterValueChange2;
			extern _ATL_FUNC_INFO SheetPivotTableBeforeAllocateChanges2;
			extern _ATL_FUNC_INFO SheetPivotTableBeforeCommitChanges2;
			extern _ATL_FUNC_INFO SheetPivotTableBeforeDiscardChanges2;
			extern _ATL_FUNC_INFO SheetPivotTableChangeSync2;
			extern _ATL_FUNC_INFO AfterSave2;
			extern _ATL_FUNC_INFO NewChart2;
			extern _ATL_FUNC_INFO SheetLensGalleryRenderComplete2;
			extern _ATL_FUNC_INFO SheetTableUpdate2;
			extern _ATL_FUNC_INFO ModelChange2;
			extern _ATL_FUNC_INFO SheetBeforeDelete2;

			class CExcelWorkbookEvents : public IDispEventSimpleImpl</*nID =*/ 1, CExcelWorkbookEvents, &__uuidof(WorkbookEvents)>
			{
			public:
				virtual void __stdcall OnOpen() {}
				virtual void __stdcall OnActivate() {}
				virtual void __stdcall OnDeactivate() {}
				virtual void __stdcall OnBeforeClose(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeSave(VARIANT_BOOL SaveAsUI, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforePrint(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnNewSheet(IDispatch* Sh) {}
				virtual void __stdcall OnAddinInstall() {}
				virtual void __stdcall OnAddinUninstall() {}
				virtual void __stdcall OnWindowResize(Excel::Window* Wn) {}
				virtual void __stdcall OnWindowActivate(Excel::Window* Wn) {}
				virtual void __stdcall OnWindowDeactivate(Excel::Window* Wn) {}
				virtual void __stdcall OnSheetSelectionChange(IDispatch* Sh, Excel::Range* Target) {}
				virtual void __stdcall OnSheetBeforeDoubleClick(IDispatch* Sh, Excel::Range* Target, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetBeforeRightClick(IDispatch* Sh, Excel::Range* Target, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetActivate(IDispatch* Sh) {}
				virtual void __stdcall OnSheetDeactivate(IDispatch* Sh) {}
				virtual void __stdcall OnSheetCalculate(IDispatch* Sh) {}
				virtual void __stdcall OnSheetChange(IDispatch* Sh, Excel::Range* Target) {}
				virtual void __stdcall OnSheetFollowHyperlink(IDispatch* Sh, Excel::Hyperlink* Target) {}
				virtual void __stdcall OnSheetPivotTableUpdate(IDispatch* Sh, PivotTable* Target) {}
				virtual void __stdcall OnPivotTableCloseConnection(PivotTable* Target) {}
				virtual void __stdcall OnPivotTableOpenConnection(PivotTable* Target) {}
				virtual void __stdcall OnSync(MsoSyncEventType SyncEvent) {}
				virtual void __stdcall OnBeforeXmlImport(XmlMap* Map, BSTR Url, VARIANT_BOOL IsRefresh, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnAfterXmlImport(XmlMap* Map, VARIANT_BOOL IsRefresh, XlXmlImportResult Result) {}
				virtual void __stdcall OnBeforeXmlExport(XmlMap* Map, BSTR Url, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnAfterXmlExport(XmlMap* Map, BSTR Url, XlXmlExportResult Result) {}
				virtual void __stdcall OnRowsetComplete(BSTR Description, BSTR Sheet, VARIANT_BOOL Success) {}
				virtual void __stdcall OnSheetPivotTableAfterValueChange(IDispatch* Sh, PivotTable* TargetPivotTable, Excel::Range* TargetRange) {}
				virtual void __stdcall OnSheetPivotTableBeforeAllocateChanges(IDispatch* Sh, PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetPivotTableBeforeCommitChanges(IDispatch* Sh, PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetPivotTableBeforeDiscardChanges(IDispatch* Sh, PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd) {}
				virtual void __stdcall OnSheetPivotTableChangeSync(IDispatch* Sh, PivotTable* Target) {}
				virtual void __stdcall OnAfterSave(VARIANT_BOOL Success) {}
				virtual void __stdcall OnNewChart(Excel::Chart* Ch) {}
				virtual void __stdcall OnSheetLensGalleryRenderComplete(IDispatch* Sh) {}
				virtual void __stdcall OnSheetTableUpdate(IDispatch* Sh, TableObject* Target) {}
				virtual void __stdcall OnModelChange(ModelChanges* Changes) {}
				virtual void __stdcall OnSheetBeforeDelete(IDispatch* Sh) {}

				BEGIN_SINK_MAP(CExcelWorkbookEvents)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000783, OnOpen, &Open)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000130, OnActivate, &Activate)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x000005fa, OnDeactivate, &Deactivate)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000060a, OnBeforeClose, &BeforeClose)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000060b, OnBeforeSave, &BeforeSave)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000060d, OnBeforePrint, &BeforePrint)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000060e, OnNewSheet, &NewSheet)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000610, OnAddinInstall, &AddinInstall)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000611, OnAddinUninstall, &AddinUninstall)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000612, OnWindowResize, &WindowResize2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000614, OnWindowActivate, &WindowActivate2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000615, OnWindowDeactivate, &WindowDeactivate2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000616, OnSheetSelectionChange, &SheetSelectionChange2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000617, OnSheetBeforeDoubleClick, &SheetBeforeDoubleClick2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000618, OnSheetBeforeRightClick, &SheetBeforeRightClick2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000619, OnSheetActivate, &SheetActivate2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000061a, OnSheetDeactivate, &SheetDeactivate2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000061b, OnSheetCalculate, &SheetCalculate2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000061c, OnSheetChange, &SheetChange2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000073e, OnSheetFollowHyperlink, &SheetFollowHyperlink2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000086d, OnSheetPivotTableUpdate, &SheetPivotTableUpdate2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000086e, OnPivotTableCloseConnection, &PivotTableCloseConnection2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x0000086f, OnPivotTableOpenConnection, &PivotTableOpenConnection2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x000008da, OnSync, &Sync2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x000008eb, OnBeforeXmlImport, &BeforeXmlImport2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x000008ed, OnAfterXmlImport, &AfterXmlImport2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x000008ef, OnBeforeXmlExport, &BeforeXmlExport2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x000008f0, OnAfterXmlExport, &AfterXmlExport2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000a32, OnRowsetComplete, &RowsetComplete2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000b4f, OnSheetPivotTableAfterValueChange, &SheetPivotTableAfterValueChange2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000b50, OnSheetPivotTableBeforeAllocateChanges, &SheetPivotTableBeforeAllocateChanges2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000b51, OnSheetPivotTableBeforeCommitChanges, &SheetPivotTableBeforeCommitChanges2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000b52, OnSheetPivotTableBeforeDiscardChanges, &SheetPivotTableBeforeDiscardChanges2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000b53, OnSheetPivotTableChangeSync, &SheetPivotTableChangeSync2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000b54, OnAfterSave, &AfterSave2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000b55, OnNewChart, &NewChart2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000c03, OnSheetLensGalleryRenderComplete, &SheetLensGalleryRenderComplete2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000c04, OnSheetTableUpdate, &SheetTableUpdate2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000c05, OnModelChange, &ModelChange2)
					SINK_ENTRY_INFO(1, __uuidof(WorkbookEvents), 0x00000c07, OnSheetBeforeDelete, &SheetBeforeDelete2)
				END_SINK_MAP()
			};

			extern _ATL_FUNC_INFO SelectionChange;
			extern _ATL_FUNC_INFO BeforeDoubleClick2;
			extern _ATL_FUNC_INFO BeforeRightClick;
			extern _ATL_FUNC_INFO Activate;
			extern _ATL_FUNC_INFO Deactivate;
			extern _ATL_FUNC_INFO Calculate;
			extern _ATL_FUNC_INFO Change;
			extern _ATL_FUNC_INFO FollowHyperlink;
			extern _ATL_FUNC_INFO PivotTableUpdate;
			extern _ATL_FUNC_INFO PivotTableAfterValueChange;
			extern _ATL_FUNC_INFO PivotTableBeforeAllocateChanges;
			extern _ATL_FUNC_INFO PivotTableBeforeCommitChanges;
			extern _ATL_FUNC_INFO PivotTableBeforeDiscardChanges;
			extern _ATL_FUNC_INFO PivotTableChangeSync;
			extern _ATL_FUNC_INFO LensGalleryRenderComplete;
			extern _ATL_FUNC_INFO TableUpdate;
			extern _ATL_FUNC_INFO BeforeDelete;

			class CExcelDocEvents : public IDispEventSimpleImpl</*nID =*/ 1, CExcelDocEvents, &__uuidof(DocEvents)>
			{
			public:
				virtual void __stdcall OnSelectionChange(Excel::Range* Target) {}
				virtual void __stdcall OnBeforeDoubleClick(Excel::Range* Target, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnBeforeRightClick(Excel::Range* Target, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnActivate() {}
				virtual void __stdcall OnDeactivate() {}
				virtual void __stdcall OnCalculate() {}
				virtual void __stdcall OnChange(Excel::Range* Target) {}
				virtual void __stdcall OnFollowHyperlink(Excel::Hyperlink* Target) {}
				virtual void __stdcall OnPivotTableUpdate(PivotTable* Target) {}
				virtual void __stdcall OnPivotTableAfterValueChange(PivotTable* TargetPivotTable, Excel::Range* TargetRange) {}
				virtual void __stdcall OnPivotTableBeforeAllocateChanges(PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnPivotTableBeforeCommitChanges(PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnPivotTableBeforeDiscardChanges(PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd) {}
				virtual void __stdcall OnPivotTableChangeSync(PivotTable* Target) {}
				virtual void __stdcall OnLensGalleryRenderComplete() {}
				virtual void __stdcall OnTableUpdate(TableObject* Target) {}
				virtual void __stdcall OnBeforeDelete() {}

				BEGIN_SINK_MAP(CExcelDocEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000607, OnSelectionChange, &SelectionChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000601, OnBeforeDoubleClick, &BeforeDoubleClick2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x000005fe, OnBeforeRightClick, &BeforeRightClick)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000130, OnActivate, &Activate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x000005fa, OnDeactivate, &Deactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000117, OnCalculate, &Calculate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000609, OnChange, &Change)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x000005be, OnFollowHyperlink, &FollowHyperlink)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x0000086c, OnPivotTableUpdate, &PivotTableUpdate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000b46, OnPivotTableAfterValueChange, &PivotTableAfterValueChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000b49, OnPivotTableBeforeAllocateChanges, &PivotTableBeforeAllocateChanges)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000b4c, OnPivotTableBeforeCommitChanges, &PivotTableBeforeCommitChanges)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000b4d, OnPivotTableBeforeDiscardChanges, &PivotTableBeforeDiscardChanges)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000b4e, OnPivotTableChangeSync, &PivotTableChangeSync)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000c00, OnLensGalleryRenderComplete, &LensGalleryRenderComplete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000c01, OnTableUpdate, &TableUpdate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DocEvents), /*dispid =*/ 0x00000c02, OnBeforeDelete, &BeforeDelete)
				END_SINK_MAP()
			};

			extern _ATL_FUNC_INFO Activate;
			extern _ATL_FUNC_INFO Deactivate;
			extern _ATL_FUNC_INFO Resize;
			extern _ATL_FUNC_INFO MouseDown;
			extern _ATL_FUNC_INFO MouseUp;
			extern _ATL_FUNC_INFO MouseMove;
			extern _ATL_FUNC_INFO BeforeRightClick2;
			extern _ATL_FUNC_INFO DragPlot;
			extern _ATL_FUNC_INFO DragOver;
			extern _ATL_FUNC_INFO BeforeDoubleClick;
			extern _ATL_FUNC_INFO Select;
			extern _ATL_FUNC_INFO SeriesChange;
			extern _ATL_FUNC_INFO Calculate;

			class CExcelChartEvents : public IDispEventSimpleImpl</*nID =*/ 1, CExcelChartEvents, &__uuidof(ChartEvents)>
			{
			public:
				virtual void __stdcall OnActivate() {}
				virtual void __stdcall OnDeactivate() {}
				virtual void __stdcall OnResize() {}
				virtual void __stdcall OnMouseDown(long Button, long Shift, long x, long y) {}
				virtual void __stdcall OnMouseUp(long Button, long Shift, long x, long y) {}
				virtual void __stdcall OnMouseMove(long Button, long Shift, long x, long y) {}
				virtual void __stdcall OnBeforeRightClick(VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnDragPlot() {}
				virtual void __stdcall OnDragOver() {}
				virtual void __stdcall OnBeforeDoubleClick(long ElementID, long Arg1, long Arg2, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSelect(long ElementID, long Arg1, long Arg2) {}
				virtual void __stdcall OnSeriesChange(long SeriesIndex, long PointIndex) {}
				virtual void __stdcall OnCalculate() {}

				BEGIN_SINK_MAP(CExcelChartEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x00000130, OnActivate, &Activate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x000005fa, OnDeactivate, &Deactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x00000100, OnResize, &Resize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x000005fb, OnMouseDown, &MouseDown)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x000005fc, OnMouseUp, &MouseUp)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x000005fd, OnMouseMove, &MouseMove)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x000005fe, OnBeforeRightClick, &BeforeRightClick2)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x000005ff, OnDragPlot, &DragPlot)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x00000600, OnDragOver, &DragOver)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x00000601, OnBeforeDoubleClick, &BeforeDoubleClick)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x000000eb, OnSelect, &Select)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x00000602, OnSeriesChange, &SeriesChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(ChartEvents), /*dispid =*/ 0x00000117, OnCalculate, &Calculate)
				END_SINK_MAP()
			};

			extern _ATL_FUNC_INFO NewWorkbook;
			extern _ATL_FUNC_INFO SheetSelectionChange;
			extern _ATL_FUNC_INFO SheetBeforeDoubleClick;
			extern _ATL_FUNC_INFO SheetBeforeRightClick;
			extern _ATL_FUNC_INFO SheetActivate;
			extern _ATL_FUNC_INFO SheetDeactivate;
			extern _ATL_FUNC_INFO SheetCalculate;
			extern _ATL_FUNC_INFO SheetChange;
			extern _ATL_FUNC_INFO WorkbookOpen;
			extern _ATL_FUNC_INFO WorkbookActivate;
			extern _ATL_FUNC_INFO WorkbookDeactivate;
			extern _ATL_FUNC_INFO WorkbookBeforeClose;
			extern _ATL_FUNC_INFO WorkbookBeforeSave;
			extern _ATL_FUNC_INFO WorkbookBeforePrint;
			extern _ATL_FUNC_INFO WorkbookNewSheet;
			extern _ATL_FUNC_INFO WorkbookAddinInstall;
			extern _ATL_FUNC_INFO WorkbookAddinUninstall;
			extern _ATL_FUNC_INFO WindowResize;
			extern _ATL_FUNC_INFO WindowActivate;
			extern _ATL_FUNC_INFO WindowDeactivate;
			extern _ATL_FUNC_INFO SheetFollowHyperlink;
			extern _ATL_FUNC_INFO SheetPivotTableUpdate;
			extern _ATL_FUNC_INFO WorkbookPivotTableCloseConnection;
			extern _ATL_FUNC_INFO WorkbookPivotTableOpenConnection;
			extern _ATL_FUNC_INFO WorkbookSync;
			extern _ATL_FUNC_INFO WorkbookBeforeXmlImport;
			extern _ATL_FUNC_INFO WorkbookAfterXmlImport;
			extern _ATL_FUNC_INFO WorkbookBeforeXmlExport;
			extern _ATL_FUNC_INFO WorkbookAfterXmlExport;
			extern _ATL_FUNC_INFO WorkbookRowsetComplete;
			extern _ATL_FUNC_INFO AfterCalculate;
			extern _ATL_FUNC_INFO SheetPivotTableAfterValueChange;
			extern _ATL_FUNC_INFO SheetPivotTableBeforeAllocateChanges;
			extern _ATL_FUNC_INFO SheetPivotTableBeforeCommitChanges;
			extern _ATL_FUNC_INFO SheetPivotTableBeforeDiscardChanges;
			extern _ATL_FUNC_INFO ProtectedViewWindowOpen;
			extern _ATL_FUNC_INFO ProtectedViewWindowBeforeEdit;
			extern _ATL_FUNC_INFO ProtectedViewWindowBeforeClose;
			extern _ATL_FUNC_INFO ProtectedViewWindowResize;
			extern _ATL_FUNC_INFO ProtectedViewWindowActivate;
			extern _ATL_FUNC_INFO ProtectedViewWindowDeactivate;
			extern _ATL_FUNC_INFO WorkbookAfterSave;
			extern _ATL_FUNC_INFO WorkbookNewChart;
			extern _ATL_FUNC_INFO SheetLensGalleryRenderComplete;
			extern _ATL_FUNC_INFO SheetTableUpdate;
			extern _ATL_FUNC_INFO WorkbookModelChange;
			extern _ATL_FUNC_INFO SheetBeforeDelete;

			class CExcelAppEvents : public IDispEventSimpleImpl</*nID =*/ 1, CExcelAppEvents, &__uuidof(AppEvents)>
			{
			public:
				virtual void __stdcall OnNewWorkbook(_Workbook* Wb) {}
				virtual void __stdcall OnSheetSelectionChange(IDispatch* Sh, Excel::Range* Target) {}
				virtual void __stdcall OnSheetBeforeDoubleClick(IDispatch* Sh, Excel::Range* Target, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetBeforeRightClick(IDispatch* Sh, Excel::Range* Target, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetActivate(IDispatch* Sh) {}
				virtual void __stdcall OnSheetDeactivate(IDispatch* Sh) {}
				virtual void __stdcall OnSheetCalculate(IDispatch* Sh) {}
				virtual void __stdcall OnSheetChange(IDispatch* Sh, Excel::Range* Target) {}
				virtual void __stdcall OnWorkbookOpen(_Workbook* Wb) {}
				virtual void __stdcall OnWorkbookActivate(_Workbook* Wb) {}
				virtual void __stdcall OnWorkbookDeactivate(_Workbook* Wb) {}
				virtual void __stdcall OnWorkbookBeforeClose(_Workbook* Wb, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnWorkbookBeforeSave(_Workbook* Wb, VARIANT_BOOL SaveAsUI, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnWorkbookBeforePrint(_Workbook* Wb, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnWorkbookNewSheet(_Workbook* Wb, IDispatch* Sh) {}
				virtual void __stdcall OnWorkbookAddinInstall(_Workbook* Wb) {}
				virtual void __stdcall OnWorkbookAddinUninstall(_Workbook* Wb) {}
				virtual void __stdcall OnWindowResize(_Workbook* Wb, Excel::Window* Wn) {}
				virtual void __stdcall OnWindowActivate(_Workbook* Wb, Excel::Window* Wn) {}
				virtual void __stdcall OnWindowDeactivate(_Workbook* Wb, Excel::Window* Wn) {}
				virtual void __stdcall OnSheetFollowHyperlink(IDispatch* Sh, Excel::Hyperlink* Target) {}
				virtual void __stdcall OnSheetPivotTableUpdate(IDispatch* Sh, PivotTable* Target) {}
				virtual void __stdcall OnWorkbookPivotTableCloseConnection(_Workbook* Wb, PivotTable* Target) {}
				virtual void __stdcall OnWorkbookPivotTableOpenConnection(_Workbook* Wb, PivotTable* Target) {}
				virtual void __stdcall OnWorkbookSync(_Workbook* Wb, MsoSyncEventType SyncEvent) {}
				virtual void __stdcall OnWorkbookBeforeXmlImport(_Workbook* Wb, XmlMap* Map, BSTR Url, VARIANT_BOOL IsRefresh, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnWorkbookAfterXmlImport(_Workbook* Wb, XmlMap* Map, VARIANT_BOOL IsRefresh, XlXmlImportResult Result) {}
				virtual void __stdcall OnWorkbookBeforeXmlExport(_Workbook* Wb, XmlMap* Map, BSTR Url, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnWorkbookAfterXmlExport(_Workbook* Wb, XmlMap* Map, BSTR Url, XlXmlExportResult Result) {}
				virtual void __stdcall OnWorkbookRowsetComplete(_Workbook* Wb, BSTR Description, BSTR Sheet, VARIANT_BOOL Success) {}
				virtual void __stdcall OnAfterCalculate() {}
				virtual void __stdcall OnSheetPivotTableAfterValueChange(IDispatch* Sh, PivotTable* TargetPivotTable, Excel::Range* TargetRange) {}
				virtual void __stdcall OnSheetPivotTableBeforeAllocateChanges(IDispatch* Sh, PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetPivotTableBeforeCommitChanges(IDispatch* Sh, PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnSheetPivotTableBeforeDiscardChanges(IDispatch* Sh, PivotTable* TargetPivotTable, long ValueChangeStart, long ValueChangeEnd) {}
				virtual void __stdcall OnProtectedViewWindowOpen(Excel::ProtectedViewWindow* Pvw) {}
				virtual void __stdcall OnProtectedViewWindowBeforeEdit(Excel::ProtectedViewWindow* Pvw, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnProtectedViewWindowBeforeClose(Excel::ProtectedViewWindow* Pvw, XlProtectedViewCloseReason Reason, VARIANT_BOOL* Cancel) {}
				virtual void __stdcall OnProtectedViewWindowResize(Excel::ProtectedViewWindow* Pvw) {}
				virtual void __stdcall OnProtectedViewWindowActivate(Excel::ProtectedViewWindow* Pvw) {}
				virtual void __stdcall OnProtectedViewWindowDeactivate(Excel::ProtectedViewWindow* Pvw) {}
				virtual void __stdcall OnWorkbookAfterSave(_Workbook* Wb, VARIANT_BOOL Success) {}
				virtual void __stdcall OnWorkbookNewChart(_Workbook* Wb, Excel::Chart* Ch) {}
				virtual void __stdcall OnSheetLensGalleryRenderComplete(IDispatch* Sh) {}
				virtual void __stdcall OnSheetTableUpdate(IDispatch* Sh, TableObject* Target) {}
				virtual void __stdcall OnWorkbookModelChange(_Workbook* Wb, ModelChanges* Changes) {}
				virtual void __stdcall OnSheetBeforeDelete(IDispatch* Sh) {}

				BEGIN_SINK_MAP(CExcelAppEvents)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x0000061d, OnNewWorkbook, &NewWorkbook)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000616, OnSheetSelectionChange, &SheetSelectionChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000617, OnSheetBeforeDoubleClick, &SheetBeforeDoubleClick)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000618, OnSheetBeforeRightClick, &SheetBeforeRightClick)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000619, OnSheetActivate, &SheetActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x0000061a, OnSheetDeactivate, &SheetDeactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x0000061b, OnSheetCalculate, &SheetCalculate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x0000061c, OnSheetChange, &SheetChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x0000061f, OnWorkbookOpen, &WorkbookOpen)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000620, OnWorkbookActivate, &WorkbookActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000621, OnWorkbookDeactivate, &WorkbookDeactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000622, OnWorkbookBeforeClose, &WorkbookBeforeClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000623, OnWorkbookBeforeSave, &WorkbookBeforeSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000624, OnWorkbookBeforePrint, &WorkbookBeforePrint)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000625, OnWorkbookNewSheet, &WorkbookNewSheet)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000626, OnWorkbookAddinInstall, &WorkbookAddinInstall)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000627, OnWorkbookAddinUninstall, &WorkbookAddinUninstall)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000612, OnWindowResize, &WindowResize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000614, OnWindowActivate, &WindowActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000615, OnWindowDeactivate, &WindowDeactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x0000073e, OnSheetFollowHyperlink, &SheetFollowHyperlink)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x0000086d, OnSheetPivotTableUpdate, &SheetPivotTableUpdate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000870, OnWorkbookPivotTableCloseConnection, &WorkbookPivotTableCloseConnection)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000871, OnWorkbookPivotTableOpenConnection, &WorkbookPivotTableOpenConnection)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x000008f1, OnWorkbookSync, &WorkbookSync)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x000008f2, OnWorkbookBeforeXmlImport, &WorkbookBeforeXmlImport)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x000008f3, OnWorkbookAfterXmlImport, &WorkbookAfterXmlImport)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x000008f4, OnWorkbookBeforeXmlExport, &WorkbookBeforeXmlExport)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x000008f5, OnWorkbookAfterXmlExport, &WorkbookAfterXmlExport)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000a33, OnWorkbookRowsetComplete, &WorkbookRowsetComplete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000a34, OnAfterCalculate, &AfterCalculate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b4f, OnSheetPivotTableAfterValueChange, &SheetPivotTableAfterValueChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b50, OnSheetPivotTableBeforeAllocateChanges, &SheetPivotTableBeforeAllocateChanges)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b51, OnSheetPivotTableBeforeCommitChanges, &SheetPivotTableBeforeCommitChanges)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b52, OnSheetPivotTableBeforeDiscardChanges, &SheetPivotTableBeforeDiscardChanges)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b57, OnProtectedViewWindowOpen, &ProtectedViewWindowOpen)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b59, OnProtectedViewWindowBeforeEdit, &ProtectedViewWindowBeforeEdit)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b5a, OnProtectedViewWindowBeforeClose, &ProtectedViewWindowBeforeClose)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b5c, OnProtectedViewWindowResize, &ProtectedViewWindowResize)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b5d, OnProtectedViewWindowActivate, &ProtectedViewWindowActivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b5e, OnProtectedViewWindowDeactivate, &ProtectedViewWindowDeactivate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b5f, OnWorkbookAfterSave, &WorkbookAfterSave)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000b60, OnWorkbookNewChart, &WorkbookNewChart)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000c03, OnSheetLensGalleryRenderComplete, &SheetLensGalleryRenderComplete)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000c04, OnSheetTableUpdate, &SheetTableUpdate)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000c08, OnWorkbookModelChange, &WorkbookModelChange)
					SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(AppEvents), /*dispid =*/ 0x00000c07, OnSheetBeforeDelete, &SheetBeforeDelete)
				END_SINK_MAP()
			};
		}
	}
}