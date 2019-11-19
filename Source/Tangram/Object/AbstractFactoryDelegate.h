#pragma once

#include <stdint.h>

namespace Object
{
	class RefObject;

	class AbstractFactoryDelegate
	{
	public:
		AbstractFactoryDelegate() {};
		virtual ~AbstractFactoryDelegate() {};

		virtual CString GetName() = 0;
		virtual uint8_t GetHandleHead() = 0;
		virtual RefObject* Create(CString strConstructString) = 0;
		virtual RefObject* GetObjectFromHandle(uint64_t nHandle) = 0;

		// Invoke method
		virtual void Invoke(RefObject* pObj, CString strMethod) = 0;
		virtual void Invoke(RefObject* pObj, CString strMethod, CString strParam1) = 0;
	};
}