#include "../stdafx.h"
#include "CoreFactoryDelegate.h"

#include "RefObject.h"

namespace Object
{
	CString CoreFactoryDelegate::GetName()
	{
		return L"Core";
	}

	uint8_t CoreFactoryDelegate::GetHandleHead()
	{
		return 1;
	}

	RefObject* CoreFactoryDelegate::Create(CString strConstructString)
	{
		// WARNING: Creating a core object using the factory is not allowed.
		// Please using Import method
		return nullptr;
	}

	RefObject* CoreFactoryDelegate::GetObjectFromHandle(uint64_t nHandle)
	{
		auto it = m_mapRefObjects.find(nHandle);
		if (it != m_mapRefObjects.end())
		{
			return it->second;
		}
		return nullptr;
	}

	void CoreFactoryDelegate::Invoke(RefObject* pObj, CString strMethod)
	{

	}

	void CoreFactoryDelegate::Invoke(RefObject* pObj, CString strMethod, CString strParam1)
	{

	}

	void CoreFactoryDelegate::Import(RefObject* pObj)
	{
		if (pObj != nullptr)
		{
			uint64_t nHandle = ++m_nNextHandle;
			m_mapRefObjects[nHandle] = pObj;
		}
	}

	void CoreFactoryDelegate::Delete(RefObject* pObj)
	{
		if (pObj != nullptr)
		{
			auto it = m_mapRefObjects.find(pObj->GetHandle());
			if (it != m_mapRefObjects.end())
			{
				m_mapRefObjects.erase(it);
			}
		}
	}
}