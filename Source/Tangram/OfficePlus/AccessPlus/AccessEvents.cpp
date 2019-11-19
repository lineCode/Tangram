#include "../../stdafx.h"
#include "AccessEvents.h"

namespace OfficePlus
{
	namespace AccessPlus
	{
		namespace AccessPlusEvent
		{
			_ATL_FUNC_INFO LoadType						= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO CurrentType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO BeforeInsertType				= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO AfterInsertType				= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO BeforeUpdateType				= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO AfterUpdateType				= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO DeleteType					= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO BeforeDelConfirmType			= { CC_STDCALL , VT_EMPTY , 2 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO AfterDelConfirmType			= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO OpenType						= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO ResizeType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO UnloadType					= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO CloseType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO ActivateType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO DeactivateType				= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO GotFocusType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO LostFocusType				= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO ClickType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO DblClickType					= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO MouseDownType				= { CC_STDCALL , VT_EMPTY , 4 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF , VT_R4 | VT_BYREF , VT_R4 | VT_BYREF };
			_ATL_FUNC_INFO MouseMoveType				= { CC_STDCALL , VT_EMPTY , 4 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF , VT_R4 | VT_BYREF , VT_R4 | VT_BYREF };
			_ATL_FUNC_INFO MouseUpType					= { CC_STDCALL , VT_EMPTY , 4 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF , VT_R4 | VT_BYREF , VT_R4 | VT_BYREF };
			_ATL_FUNC_INFO KeyDownType					= { CC_STDCALL , VT_EMPTY , 2 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO KeyPressType					= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO KeyUpType					= { CC_STDCALL , VT_EMPTY , 2 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO ErrorType					= { CC_STDCALL , VT_EMPTY , 2 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO TimerType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO FilterType					= { CC_STDCALL , VT_EMPTY , 2 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO ApplyFilterType				= { CC_STDCALL , VT_EMPTY , 2 , VT_I2 | VT_BYREF , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO DirtyType					= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO UndoType						= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO RecordExitType				= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO BeginBatchEditType			= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO UndoBatchEditType			= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO OnConnectType				= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO OnDisconnectType				= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO PivotTableChangeType			= { CC_STDCALL , VT_EMPTY , 1 , VT_I4 };
			_ATL_FUNC_INFO QueryType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO BeforeQueryType				= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO SelectionChangeType			= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO CommandBeforeExecuteType		= { CC_STDCALL , VT_EMPTY , 2 , VT_VARIANT , VT_DISPATCH };
			_ATL_FUNC_INFO CommandCheckedType			= { CC_STDCALL , VT_EMPTY , 2 , VT_VARIANT , VT_DISPATCH };
			_ATL_FUNC_INFO CommandEnabledType			= { CC_STDCALL , VT_EMPTY , 2 , VT_VARIANT , VT_DISPATCH };
			_ATL_FUNC_INFO CommandExecuteType			= { CC_STDCALL , VT_EMPTY , 1 , VT_VARIANT };
			_ATL_FUNC_INFO DataSetChangeType			= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO BeforeScreenTipType			= { CC_STDCALL , VT_EMPTY , 2 , VT_DISPATCH , VT_DISPATCH };
			_ATL_FUNC_INFO BeforeRenderType				= { CC_STDCALL , VT_EMPTY , 3 , VT_DISPATCH , VT_DISPATCH , VT_DISPATCH };
			_ATL_FUNC_INFO AfterRenderType				= { CC_STDCALL , VT_EMPTY , 2 , VT_DISPATCH , VT_DISPATCH };
			_ATL_FUNC_INFO AfterFinalRenderType			= { CC_STDCALL , VT_EMPTY , 1 , VT_DISPATCH };
			_ATL_FUNC_INFO AfterLayoutType				= { CC_STDCALL , VT_EMPTY , 1 , VT_DISPATCH };
			_ATL_FUNC_INFO MouseWheelType				= { CC_STDCALL , VT_EMPTY , 2 , VT_BOOL , VT_I4 };
			_ATL_FUNC_INFO ViewChangeType				= { CC_STDCALL , VT_EMPTY , 1 , VT_I4 };
			_ATL_FUNC_INFO DataChangeType				= { CC_STDCALL , VT_EMPTY , 1 , VT_I4 };
			_ATL_FUNC_INFO QueryInterfaceType			= { CC_STDCALL , VT_EMPTY , 2 , VT_I4 | VT_BYREF , VT_EMPTY | VT_BYREF | VT_BYREF };
			_ATL_FUNC_INFO GetTypeInfoCountType			= { CC_STDCALL , VT_EMPTY , 1 , VT_UINT | VT_BYREF };
			_ATL_FUNC_INFO GetTypeInfoType				= { CC_STDCALL , VT_EMPTY , 3 , VT_UINT , VT_UI4 , VT_EMPTY | VT_BYREF | VT_BYREF };
			_ATL_FUNC_INFO GetIDsOfNamesType			= { CC_STDCALL , VT_EMPTY , 5 , VT_I4 | VT_BYREF , VT_I1 | VT_BYREF | VT_BYREF , VT_UINT , VT_UI4 , VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO InvokeType					= { CC_STDCALL , VT_EMPTY , 8 , VT_I4 , VT_I4 | VT_BYREF , VT_UI4 , VT_UI2 , VT_I4 | VT_BYREF , VT_VARIANT | VT_BYREF , VT_I4 | VT_BYREF , VT_UINT | VT_BYREF };
			_ATL_FUNC_INFO WillChangeFieldType			= { CC_STDCALL , VT_EMPTY , 4 , VT_I4 , VT_VARIANT , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO FieldChangeCompleteType		= { CC_STDCALL , VT_EMPTY , 5 , VT_I4 , VT_VARIANT , VT_UNKNOWN , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO WillChangeRecordType			= { CC_STDCALL , VT_EMPTY , 4 , VT_I4 , VT_I4 , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO RecordChangeCompleteType		= { CC_STDCALL , VT_EMPTY , 5 , VT_I4 , VT_I4 , VT_UNKNOWN , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO WillChangeRecordsetType		= { CC_STDCALL , VT_EMPTY , 3 , VT_I4 , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO RecordsetChangeCompleteType	= { CC_STDCALL , VT_EMPTY , 4 , VT_I4 , VT_UNKNOWN , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO WillMoveType					= { CC_STDCALL , VT_EMPTY , 3 , VT_I4 , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO MoveCompleteType				= { CC_STDCALL , VT_EMPTY , 4 , VT_I4 , VT_UNKNOWN , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO EndOfRecordsetType			= { CC_STDCALL , VT_EMPTY , 3 , VT_I2 | VT_BYREF , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO FetchProgressType			= { CC_STDCALL , VT_EMPTY , 4 , VT_I4 , VT_I4 , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO FetchCompleteType			= { CC_STDCALL , VT_EMPTY , 3 , VT_UNKNOWN , VT_I4 | VT_BYREF , VT_UNKNOWN };
			_ATL_FUNC_INFO ItemAddedType				= { CC_STDCALL , VT_EMPTY , 1 , VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO ItemRemovedType				= { CC_STDCALL , VT_EMPTY , 1 , VT_I4 | VT_BYREF };
			_ATL_FUNC_INFO NoDataType					= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO PageType						= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO EnterType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO ExitType						= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO ChangeType					= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO AttachmentCurrentType		= { CC_STDCALL , VT_EMPTY , 0 , NULL };
			_ATL_FUNC_INFO UpdatedType					= { CC_STDCALL , VT_EMPTY , 1 , VT_I2 | VT_BYREF };
			_ATL_FUNC_INFO NotInListType				= { CC_STDCALL , VT_EMPTY , 2 , VT_BSTR | VT_BYREF , VT_I2 | VT_BYREF };
		}
	}
}

