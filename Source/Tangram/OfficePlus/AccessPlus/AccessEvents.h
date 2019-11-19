#include "msacc.h"
using namespace Office;
using namespace MSAccess;
using namespace ADODB;

namespace OfficePlus
{
	namespace AccessPlus
	{
		namespace AccessPlusEvent
		{
			extern _ATL_FUNC_INFO UpdatedType;
			extern _ATL_FUNC_INFO AfterUpdateType;
			extern _ATL_FUNC_INFO EnterType;
			extern _ATL_FUNC_INFO ExitType;
			extern _ATL_FUNC_INFO ClickType;
			extern _ATL_FUNC_INFO DblClickType;
			extern _ATL_FUNC_INFO MouseDownType;
			extern _ATL_FUNC_INFO MouseMoveType;
			extern _ATL_FUNC_INFO MouseUpType;
			extern _ATL_FUNC_INFO KeyDownType;
			extern _ATL_FUNC_INFO KeyPressType;
			extern _ATL_FUNC_INFO KeyUpType;
			extern _ATL_FUNC_INFO BeforeUpdateType;
			extern _ATL_FUNC_INFO GotFocusType;
			extern _ATL_FUNC_INFO LostFocusType;
			extern _ATL_FUNC_INFO NoDataType;
			extern _ATL_FUNC_INFO PageType;
			extern _ATL_FUNC_INFO ChangeType;
			extern _ATL_FUNC_INFO NotInListType;
			extern _ATL_FUNC_INFO DirtyType;
			extern _ATL_FUNC_INFO UndoType;
			extern _ATL_FUNC_INFO WillChangeFieldType;
			extern _ATL_FUNC_INFO FieldChangeCompleteType;
			extern _ATL_FUNC_INFO WillChangeRecordType;
			extern _ATL_FUNC_INFO RecordChangeCompleteType;
			extern _ATL_FUNC_INFO WillChangeRecordsetType;
			extern _ATL_FUNC_INFO RecordsetChangeCompleteType;
			extern _ATL_FUNC_INFO WillMoveType;
			extern _ATL_FUNC_INFO MoveCompleteType;
			extern _ATL_FUNC_INFO EndOfRecordsetType;
			extern _ATL_FUNC_INFO FetchProgressType;
			extern _ATL_FUNC_INFO FetchCompleteType;
			extern _ATL_FUNC_INFO InitializeType;
			extern _ATL_FUNC_INFO TerminateType;
			extern _ATL_FUNC_INFO LoadType;
			extern _ATL_FUNC_INFO CurrentType;
			extern _ATL_FUNC_INFO BeforeInsertType;
			extern _ATL_FUNC_INFO AfterInsertType;
			extern _ATL_FUNC_INFO DeleteType;
			extern _ATL_FUNC_INFO BeforeDelConfirmType;
			extern _ATL_FUNC_INFO AfterDelConfirmType;
			extern _ATL_FUNC_INFO OpenType;
			extern _ATL_FUNC_INFO ResizeType;
			extern _ATL_FUNC_INFO UnloadType;
			extern _ATL_FUNC_INFO CloseType;
			extern _ATL_FUNC_INFO ActivateType;
			extern _ATL_FUNC_INFO DeactivateType;
			extern _ATL_FUNC_INFO ErrorType;
			extern _ATL_FUNC_INFO TimerType;
			extern _ATL_FUNC_INFO FilterType;
			extern _ATL_FUNC_INFO ApplyFilterType;
			extern _ATL_FUNC_INFO RecordExitType;
			extern _ATL_FUNC_INFO BeginBatchEditType;
			extern _ATL_FUNC_INFO UndoBatchEditType;
			extern _ATL_FUNC_INFO OnConnectType;
			extern _ATL_FUNC_INFO OnDisconnectType;
			extern _ATL_FUNC_INFO PivotTableChangeType;
			extern _ATL_FUNC_INFO QueryType;
			extern _ATL_FUNC_INFO BeforeQueryType;
			extern _ATL_FUNC_INFO SelectionChangeType;
			extern _ATL_FUNC_INFO CommandBeforeExecuteType;
			extern _ATL_FUNC_INFO CommandCheckedType;
			extern _ATL_FUNC_INFO CommandEnabledType;
			extern _ATL_FUNC_INFO CommandExecuteType;
			extern _ATL_FUNC_INFO DataSetChangeType;
			extern _ATL_FUNC_INFO BeforeScreenTipType;
			extern _ATL_FUNC_INFO BeforeRenderType;
			extern _ATL_FUNC_INFO AfterRenderType;
			extern _ATL_FUNC_INFO AfterFinalRenderType;
			extern _ATL_FUNC_INFO AfterLayoutType;
			extern _ATL_FUNC_INFO MouseWheelType;
			extern _ATL_FUNC_INFO ViewChangeType;
			extern _ATL_FUNC_INFO DataChangeType;
			extern _ATL_FUNC_INFO FormatType;
			extern _ATL_FUNC_INFO PrintType;
			extern _ATL_FUNC_INFO RetreatType;
			extern _ATL_FUNC_INFO PaintType;
			extern _ATL_FUNC_INFO FormatType;
			extern _ATL_FUNC_INFO PrintType;
			extern _ATL_FUNC_INFO ItemAddedType;
			extern _ATL_FUNC_INFO ItemRemovedType;
			extern _ATL_FUNC_INFO CurrentType;
			extern _ATL_FUNC_INFO LoadType;
			extern _ATL_FUNC_INFO ResizeType;
			extern _ATL_FUNC_INFO UnloadType;
			extern _ATL_FUNC_INFO TimerType;
			extern _ATL_FUNC_INFO FilterType;
			extern _ATL_FUNC_INFO ApplyFilterType;
			extern _ATL_FUNC_INFO MouseWheelType;
			extern _ATL_FUNC_INFO AttachmentCurrentType;

			class CMSAccessBoundObjectFrameEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessBoundObjectFrameEvents, &__uuidof(_BoundObjectFrameEvents)>
			{
			public:
				virtual void __stdcall Updated(short* Code) {}
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessBoundObjectFrameEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0x0000081c, Updated, &UpdatedType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_BoundObjectFrameEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessCheckBoxEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessCheckBoxEvents, &__uuidof(DispCheckBoxEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessCheckBoxEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessCheckBoxInOptionEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessCheckBoxInOptionEvents, &__uuidof(DispCheckBoxEvents)>
			{
			public:
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessCheckBoxInOptionEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCheckBoxEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessComboBoxEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessComboBoxEvents, &__uuidof(DispComboBoxEvents)>
			{
			public:
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Change() {}
				virtual void __stdcall NotInList(BSTR*NewData, short* Response) {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}
				virtual void __stdcall Dirty(short* Cancel) {}
				virtual void __stdcall Undo(short* Cancel) {}

				BEGIN_SINK_MAP(CMSAccessComboBoxEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x0000081d, Change, &ChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x0000081e, NotInList, &NotInListType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x0000089d, Dirty, &DirtyType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispComboBoxEvents),(DISPID)0x00000860, Undo, &UndoType)
				END_SINK_MAP()
			};

			class CMSAccessCommandButtonEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessCommandButtonEvents, &__uuidof(DispCommandButtonEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessCommandButtonEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCommandButtonEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};
			
			class CMSAccessCustomControlEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessCustomControlEvents, &__uuidof(DispCustomControlEvents)>
			{
			public:
				virtual void __stdcall Updated(short* Code) {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}

				BEGIN_SINK_MAP(CMSAccessCustomControlEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCustomControlEvents),(DISPID)0x0000081c, Updated, &UpdatedType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCustomControlEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCustomControlEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCustomControlEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispCustomControlEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
				END_SINK_MAP()
			};

			class CMSAccessDummyEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessDummyEvents, &__uuidof(_DummyEvents)>
			{
			public:
				virtual void __stdcall Initialize() {}
				virtual void __stdcall Terminate() {}

				BEGIN_SINK_MAP(CMSAccessDummyEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_DummyEvents),(DISPID)0xfffffffa, Initialize, &InitializeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_DummyEvents),(DISPID)0xfffffff9, Terminate, &TerminateType)
				END_SINK_MAP()
			};

			class CMSAccessFormEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessFormEvents, &__uuidof(_FormEvents2)>
			{
			public:
				virtual void __stdcall Load() 
				{
				}
				virtual void __stdcall Current() {}
				virtual void __stdcall BeforeInsert(short* Cancel) {}
				virtual void __stdcall AfterInsert() {}
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Delete(short* Cancel) {}
				virtual void __stdcall BeforeDelConfirm(short* Cancel, short* Response) {}
				virtual void __stdcall AfterDelConfirm(short* Status) {}
				virtual void __stdcall Open(short* Cancel) 
				{
				}
				virtual void __stdcall Resize() {}
				virtual void __stdcall Unload(short* Cancel)
				{
				}
				virtual void __stdcall Close() 
				{
				}
				virtual void __stdcall Activate() 
				{
				}
				virtual void __stdcall Deactivate() 
				{
				}
				virtual void __stdcall GotFocus() {
				}
				virtual void __stdcall LostFocus() {
				}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {
				}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {
				}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}
				virtual void __stdcall Error(short* DataErr, short* Response) {}
				virtual void __stdcall Timer() {}
				virtual void __stdcall Filter(short* Cancel, short* FilterType) { }
				virtual void __stdcall ApplyFilter(short* Cancel, short* ApplyType) {}
				virtual void __stdcall Dirty(short* Cancel) {}
				virtual void __stdcall Undo(short* Cancel) {}
				virtual void __stdcall RecordExit(short* Cancel) {}
				virtual void __stdcall BeginBatchEdit(short* Cancel) {}
				virtual void __stdcall UndoBatchEdit(short* Cancel) {}
				virtual void __stdcall OnConnect() {}
				virtual void __stdcall OnDisconnect() {}
				virtual void __stdcall PivotTableChange(long Reason) {}
				virtual void __stdcall Query() {}
				virtual void __stdcall BeforeQuery() {}
				virtual void __stdcall SelectionChange() {}
				virtual void __stdcall CommandBeforeExecute(VARIANT Command, IDispatch*Cancel) {}
				virtual void __stdcall CommandChecked(VARIANT Command, IDispatch*Checked) {}
				virtual void __stdcall CommandEnabled(VARIANT Command, IDispatch*Enabled) {}
				virtual void __stdcall CommandExecute(VARIANT Command) {}
				virtual void __stdcall DataSetChange() {}
				virtual void __stdcall BeforeScreenTip(IDispatch*ScreenTipText, IDispatch*SourceObject) {}
				virtual void __stdcall BeforeRender(IDispatch*drawObject, IDispatch*chartObject, IDispatch*Cancel) {}
				virtual void __stdcall AfterRender(IDispatch*drawObject, IDispatch*chartObject) {}
				virtual void __stdcall AfterFinalRender(IDispatch*drawObject) {}
				virtual void __stdcall AfterLayout(IDispatch*drawObject) {}
				virtual void __stdcall MouseWheel(VARIANT_BOOL Page, long Count) {}
				virtual void __stdcall ViewChange(long Reason) {}
				virtual void __stdcall DataChange(long Reason) {}

				BEGIN_SINK_MAP(CMSAccessFormEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000813, Load, &LoadType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000080a, Current, &CurrentType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000080b, BeforeInsert, &BeforeInsertType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000080c, AfterInsert, &AfterInsertType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000080f, Delete, &DeleteType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000810, BeforeDelConfirm, &BeforeDelConfirmType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000811, AfterDelConfirm, &AfterDelConfirmType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000812, Open, &OpenType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000814, Resize, &ResizeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000815, Unload, &UnloadType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000816, Close, &CloseType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000817, Activate, &ActivateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000818, Deactivate, &DeactivateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000823, Error, &ErrorType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000824, Timer, &TimerType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000086b, Filter, &FilterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000086c, ApplyFilter, &ApplyFilterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000089d, Dirty, &DirtyType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000861, Undo, &UndoType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000091e, RecordExit, &RecordExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000941, BeginBatchEdit, &BeginBatchEditType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000942, UndoBatchEdit, &UndoBatchEditType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000094f, OnConnect, &OnConnectType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000950, OnDisconnect, &OnDisconnectType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000951, PivotTableChange, &PivotTableChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000952, Query, &QueryType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000953, BeforeQuery, &BeforeQueryType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000954, SelectionChange, &SelectionChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000955, CommandBeforeExecute, &CommandBeforeExecuteType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000956, CommandChecked, &CommandCheckedType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000957, CommandEnabled, &CommandEnabledType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000958, CommandExecute, &CommandExecuteType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000095a, DataSetChange, &DataSetChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000095b, BeforeScreenTip, &BeforeScreenTipType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000095f, BeforeRender, &BeforeRenderType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000095d, AfterRender, &AfterRenderType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000095c, AfterFinalRender, &AfterFinalRenderType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x0000095e, AfterLayout, &AfterLayoutType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000961, MouseWheel, &MouseWheelType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000962, ViewChange, &ViewChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_FormEvents2),(DISPID)0x00000963, DataChange, &DataChangeType)
				END_SINK_MAP()
			};

			class CMSAccessImageEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessImageEvents, &__uuidof(_ImageEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessImageEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ImageEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ImageEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ImageEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ImageEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ImageEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};

			class CMSAccessLabelEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessLabelEvents, &__uuidof(DispLabelEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessLabelEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispLabelEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispLabelEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispLabelEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispLabelEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispLabelEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};

			class CMSAccessListBoxEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessListBoxEvents, &__uuidof(DispListBoxEvents)>
			{
			public:
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessListBoxEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispListBoxEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};
			
			class CMSAccessObjectFrameEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessObjectFrameEvents, &__uuidof(DispObjectFrameEvents)>
			{
			public:
				virtual void __stdcall Updated(short* Code) {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessObjectFrameEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0x0000081c, Updated, &UpdatedType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispObjectFrameEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};
			
			class CMSAccessOptionButtonEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessOptionButtonEvents, &__uuidof(DispOptionButtonEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessOptionButtonEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionButtonEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessOptionButtonInOptionEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessOptionButtonInOptionEvents, &__uuidof(_OptionButtonInOptionEvents)>
			{
			public:
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessOptionButtonInOptionEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_OptionButtonInOptionEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessOptionGroupEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessOptionGroupEvents, &__uuidof(DispOptionGroupEvents)>
			{
			public:
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessOptionGroupEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispOptionGroupEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};

			class CMSAccessPageEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessPageEvents, &__uuidof(DispPageEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessPageEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};

			class CMSAccessPageHdrFtrInReportEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessPageHdrFtrInReportEvents, &__uuidof(DispPageHdrFtrInReportEvents)>
			{
			public:
				virtual void __stdcall Format(short* Cancel, short* FormatCount) {}
				virtual void __stdcall Print(short* Cancel, short* PrintCount) {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessPageHdrFtrInReportEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageHdrFtrInReportEvents),(DISPID)0x0000081f, Format, &FormatType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageHdrFtrInReportEvents),(DISPID)0x00000820, Print, &PrintType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageHdrFtrInReportEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageHdrFtrInReportEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageHdrFtrInReportEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageHdrFtrInReportEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPageHdrFtrInReportEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};
			
			class CMSAccessPaletteButtonEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessPaletteButtonEvents, &__uuidof(DispPaletteButtonEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessPaletteButtonEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispPaletteButtonEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessRecordsetEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessRecordsetEvents, &__uuidof(_RecordsetEvents)>
			{
			public:
				//virtual void __stdcall QueryInterface(GUID*riid, void**ppvObj) {}
				//virtual ULONG __stdcall AddRef() {}
				//virtual ULONG __stdcall Release() {}
				//virtual void __stdcall GetTypeInfoCount(UINT *pctinfo) {}
				//virtual void __stdcall GetTypeInfo(UINT itinfo, ULONG lcid, void**pptinfo) {}
				//virtual void __stdcall GetIDsOfNames(GUID* riid, char** rgszNames, UINT cNames, ULONG lcid, long *rgdispid) {}
				//virtual void __stdcall Invoke(long dispidMember, GUID*riid, ULONG lcid, USHORT wFlags, DISPPARAMS* pdispparams, VARIANT *pvarResult, EXCEPINFO*pexcepinfo, UINT *puArgErr) {}
				virtual void __stdcall WillChangeField(long cFields, VARIANT Fields, ADODB::EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall FieldChangeComplete(long cFields, VARIANT Fields, IUnknown*pError, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall WillChangeRecord(EventReasonEnum adReason, long cRecords, EventStatusEnum * adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall RecordChangeComplete(EventReasonEnum adReason, long cRecords, IUnknown*pError, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall WillChangeRecordset(EventReasonEnum adReason, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall RecordsetChangeComplete(EventReasonEnum adReason, IUnknown*pError, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall WillMove(EventReasonEnum adReason, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall MoveComplete(EventReasonEnum adReason, IUnknown*pError, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall EndOfRecordset(short* fMoreData, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall FetchProgress(long Progress, long MaxProgress, EventStatusEnum *adStatus, IUnknown*pRecordset) {}
				virtual void __stdcall FetchComplete(IUnknown*pError, EventStatusEnum *adStatus, IUnknown*pRecordset) {}

				BEGIN_SINK_MAP(CMSAccessRecordsetEvents)
					//SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x60000000, QueryInterface, &QueryInterfaceType)
					//SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x60000001, AddRef, &AddRefType)
					//SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x60000002, Release, &ReleaseType)
					//SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x60010000, GetTypeInfoCount, &GetTypeInfoCountType)
					//SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x60010001, GetTypeInfo, &GetTypeInfoType)
					//SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x60010002, GetIDsOfNames, &GetIDsOfNamesType)
					//SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x60010003, Invoke, &InvokeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x00000009, WillChangeField, &WillChangeFieldType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x0000000a, FieldChangeComplete, &FieldChangeCompleteType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x0000000b, WillChangeRecord, &WillChangeRecordType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x0000000c, RecordChangeComplete, &RecordChangeCompleteType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x0000000d, WillChangeRecordset, &WillChangeRecordsetType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x0000000e, RecordsetChangeComplete, &RecordsetChangeCompleteType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x0000000f, WillMove, &WillMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x00000010, MoveComplete, &MoveCompleteType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x00000011, EndOfRecordset, &EndOfRecordsetType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x00000012, FetchProgress, &FetchProgressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_RecordsetEvents),(DISPID)0x00000013, FetchComplete, &FetchCompleteType)
				END_SINK_MAP()
			};

			class CMSAccessRectangleEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessRectangleEvents, &__uuidof(DispRectangleEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessRectangleEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispRectangleEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispRectangleEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispRectangleEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispRectangleEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispRectangleEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};

			class CMSAccessReferences_Events : public IDispEventSimpleImpl</*nID=*/1, CMSAccessReferences_Events, &__uuidof(_References_Events)>
			{
			public:
				virtual void __stdcall ItemAdded(Reference*Reference) {}
				virtual void __stdcall ItemRemoved(Reference*Reference) {}

				BEGIN_SINK_MAP(CMSAccessReferences_Events)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_References_Events),(DISPID)0x00000000, ItemAdded, &ItemAddedType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_References_Events),(DISPID)0x00000001, ItemRemoved, &ItemRemovedType)
				END_SINK_MAP()
			};

			class CMSAccessReportEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessReportEvents, &__uuidof(_ReportEvents2)>
			{
			public:
				virtual void __stdcall Open(short* Cancel) {}
				virtual void __stdcall Close() {}
				virtual void __stdcall Activate() {}
				virtual void __stdcall Deactivate() {}
				virtual void __stdcall Error(short* DataErr, short* Response) {}
				virtual void __stdcall NoData(short* Cancel) {}
				virtual void __stdcall Page() {}

				BEGIN_SINK_MAP(CMSAccessReportEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000812, Open, &OpenType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000816, Close, &CloseType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000817, Activate, &ActivateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000818, Deactivate, &DeactivateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000823, Error, &ErrorType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000871, NoData, &NoDataType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000872, Page, &PageType)
				END_SINK_MAP()
			};

			class CMSAccessReportEvents2 : public IDispEventSimpleImpl</*nID=*/1, CMSAccessReportEvents2, &__uuidof(_ReportEvents2)>
			{
			public:
				virtual void __stdcall Open(short* Cancel) {}
				virtual void __stdcall Close() {}
				virtual void __stdcall Activate() {}
				virtual void __stdcall Deactivate() {}
				virtual void __stdcall Error(short* DataErr, short* Response) {}
				virtual void __stdcall NoData(short* Cancel) {}
				virtual void __stdcall Page() {}
				virtual void __stdcall Current() {}
				virtual void __stdcall Load() {}
				virtual void __stdcall Resize() {}
				virtual void __stdcall Unload(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}
				virtual void __stdcall Timer() {}
				virtual void __stdcall Filter(short* Cancel, short* FilterType) {}
				virtual void __stdcall ApplyFilter(short* Cancel, short* ApplyType) {}
				virtual void __stdcall MouseWheel(VARIANT _BOOLPage, long Count) {}

				BEGIN_SINK_MAP(CMSAccessReportEvents2)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000812, Open, &OpenType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000816, Close, &CloseType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000817, Activate, &ActivateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000818, Deactivate, &DeactivateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000823, Error, &ErrorType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000871, NoData, &NoDataType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000872, Page, &PageType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x0000080a, Current, &CurrentType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000813, Load, &LoadType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000814, Resize, &ResizeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000815, Unload, &UnloadType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000824, Timer, &TimerType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x0000086b, Filter, &FilterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x0000086c, ApplyFilter, &ApplyFilterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(_ReportEvents2),(DISPID)0x00000961, MouseWheel, &MouseWheelType)
				END_SINK_MAP()
			};

			class CMSAccessSectionEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessSectionEvents, &__uuidof(DispSectionEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall Paint() {}

				BEGIN_SINK_MAP(CMSAccessSectionEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionEvents),(DISPID)0x000009b6, Paint, &PaintType)
				END_SINK_MAP()
			};

			class CMSAccessSectionInReportEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessSectionInReportEvents, &__uuidof(DispSectionInReportEvents)>
			{
			public:
				virtual void __stdcall Format(short* Cancel, short* FormatCount) {}
				virtual void __stdcall Print(short* Cancel, short* PrintCount) {}
				virtual void __stdcall Retreat() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall Paint() {}

				BEGIN_SINK_MAP(CMSAccessSectionInReportEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0x0000081f, Format, &FormatType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0x00000820, Print, &PrintType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0x00000821, Retreat, &RetreatType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSectionInReportEvents),(DISPID)0x000009b6, Paint, &PaintType)
				END_SINK_MAP()
			};

			class CMSAccessSubFormEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessSubFormEvents, &__uuidof(DispSubFormEvents)>
			{
			public:
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}

				BEGIN_SINK_MAP(CMSAccessSubFormEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSubFormEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSubFormEvents),(DISPID)0x0000081b, Exit, &ExitType)
				END_SINK_MAP()
			};

			class CMSAccessSubReportEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessSubReportEvents, &__uuidof(DispSubReportEvents)>
			{
			public:
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}

				BEGIN_SINK_MAP(CMSAccessSubReportEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSubReportEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispSubReportEvents),(DISPID)0x0000081b, Exit, &ExitType)
				END_SINK_MAP()
			};

			class CMSAccessTabControlEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessTabControlEvents, &__uuidof(DispTabControlEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}
				virtual void __stdcall Change() {}

				BEGIN_SINK_MAP(CMSAccessTabControlEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTabControlEvents),(DISPID)0x0000081d, Change, &ChangeType)
				END_SINK_MAP()
			};

			class CMSAccessTextBoxEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessTextBoxEvents, &__uuidof(DispTextBoxEvents)>
			{
			public:
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Change() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}
				virtual void __stdcall Dirty(short* Cancel) {}
				virtual void __stdcall Undo(short* Cancel) {}

				BEGIN_SINK_MAP(CMSAccessTextBoxEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x0000081d, Change, &ChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x0000089d, Dirty, &DirtyType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispTextBoxEvents),(DISPID)0x00000860, Undo, &UndoType)
				END_SINK_MAP()
			};
			
			class CMSAccessToggleButtonEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessToggleButtonEvents, &__uuidof(DispToggleButtonEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessToggleButtonEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessToggleButtonInOptionEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessToggleButtonInOptionEvents, &__uuidof(DispToggleButtonEvents)>
			{
			public:
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessToggleButtonInOptionEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispToggleButtonEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessDispAttachmentEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessDispAttachmentEvents, &__uuidof(DispAttachmentEvents)>
			{
			public:
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall Dirty(short* Cancel) {}
				virtual void __stdcall Change() {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}
				virtual void __stdcall AttachmentCurrent() {}

				BEGIN_SINK_MAP(CMSAccessDispAttachmentEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x0000089d, Dirty, &DirtyType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x0000081d, Change, &ChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispAttachmentEvents),(DISPID)0x000009b3, AttachmentCurrent, &AttachmentCurrentType)
				END_SINK_MAP()

			};
			
			class CMSAccessDispBoundObjectFrameEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessDispBoundObjectFrameEvents, &__uuidof(DispBoundObjectFrameEvents)>

			{
			public:
				virtual void __stdcall Updated(short* Code) {}
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessDispBoundObjectFrameEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0x0000081c, Updated, &UpdatedType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispBoundObjectFrameEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};
			
			class CMSAccessDispImageEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessDispImageEvents, &__uuidof(DispImageEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}

				BEGIN_SINK_MAP(CMSAccessDispImageEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispImageEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispImageEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispImageEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispImageEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispImageEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
				END_SINK_MAP()
			};

			class CMSAccessDispNavigationButtonEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessDispNavigationButtonEvents, &__uuidof(DispNavigationButtonEvents)>
			{
			public:
				virtual void __stdcall Click() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}

				BEGIN_SINK_MAP(CMSAccessDispNavigationButtonEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationButtonEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
				END_SINK_MAP()
			};

			class CMSAccessDispNavigationControlEvents : public IDispEventSimpleImpl</*nID=*/1, CMSAccessDispNavigationControlEvents, &__uuidof(DispNavigationControlEvents)>
			{
			public:
				virtual void __stdcall BeforeUpdate(short* Cancel) {}
				virtual void __stdcall AfterUpdate() {}
				virtual void __stdcall Change() {}
				virtual void __stdcall Enter() {}
				virtual void __stdcall Exit(short* Cancel) {}
				virtual void __stdcall GotFocus() {}
				virtual void __stdcall LostFocus() {}
				virtual void __stdcall Click() {}
				virtual void __stdcall DblClick(short* Cancel) {}
				virtual void __stdcall MouseDown(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseMove(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall MouseUp(short* Button, short* Shift, float* X, float* Y) {}
				virtual void __stdcall KeyDown(short* KeyCode, short* Shift) {}
				virtual void __stdcall KeyPress(short* KeyAscii) {}
				virtual void __stdcall KeyUp(short* KeyCode, short* Shift) {}
				virtual void __stdcall Dirty(short* Cancel) {}
				virtual void __stdcall Undo(short* Cancel) {}

				BEGIN_SINK_MAP(CMSAccessDispNavigationControlEvents)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x0000080d, BeforeUpdate, &BeforeUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x0000080e, AfterUpdate, &AfterUpdateType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x0000081d, Change, &ChangeType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x000007e3, Enter, &EnterType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x0000081b, Exit, &ExitType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x00000819, GotFocus, &GotFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x0000081a, LostFocus, &LostFocusType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda8, Click, &ClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda7, DblClick, &DblClickType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda3, MouseDown, &MouseDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda2, MouseMove, &MouseMoveType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda1, MouseUp, &MouseUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda6, KeyDown, &KeyDownType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda5, KeyPress, &KeyPressType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0xfffffda4, KeyUp, &KeyUpType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x0000089d, Dirty, &DirtyType)
					SINK_ENTRY_INFO(/*nID=*/1, __uuidof(DispNavigationControlEvents),(DISPID)0x00000860, Undo, &UndoType)
				END_SINK_MAP()
			};
		}
	}
}
