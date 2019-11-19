#include "../stdafx.h"
#include "WebRuntimeDelegate.h"

namespace Boot
{
	WebRuntimeDelegate::WebRuntimeDelegate()
	{

	}

	CString WebRuntimeDelegate::GetName()
	{
		return _T("Web");
	}
}