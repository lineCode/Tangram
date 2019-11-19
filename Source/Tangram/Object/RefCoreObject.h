#pragma once

#include "RefObject.h"

namespace Object
{
	class RefCoreObject : public RefObject
	{
	public:
		RefCoreObject() {};
		virtual ~RefCoreObject() {};

		virtual CString GetRefCoreObjectName() = 0;
	};
}