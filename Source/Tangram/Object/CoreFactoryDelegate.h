#pragma once

#include <stdint.h>
#include <atomic>
#include <map>

#include "AbstractFactoryDelegate.h"

namespace Object
{
	class RefObject;

	class CoreFactoryDelegate : public AbstractFactoryDelegate
	{
	public:
		CoreFactoryDelegate() {};
		virtual ~CoreFactoryDelegate() {};

		CString GetName() override;
		uint8_t GetHandleHead() override;
		RefObject* Create(CString strConstructString) override;
		RefObject* GetObjectFromHandle(uint64_t nHandle) override;

		void Invoke(RefObject* pObj, CString strMethod) override;
		void Invoke(RefObject* pObj, CString strMethod, CString strParam1) override;

		void Import(RefObject* pObj);
		void Delete(RefObject* pObj);

	private:
		atomic<uint64_t> m_nNextHandle = 100000; // WARNING: Thread safe

		map<uint64_t, RefObject*> m_mapRefObjects;
	};
}