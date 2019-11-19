#include "..\stdafx.h"
#include "RefObject.h"

#include "AbstractFactoryDelegate.h"
#include "RefObjectEventListener.h"

namespace Object
{
	RefObject::RefObject()
	{
		m_pFactoryDelegate = nullptr;
	}

	RefObject::RefObject(AbstractFactoryDelegate* pFactoryDelegate, uint64_t nRawHandle)
	{
		m_pFactoryDelegate = pFactoryDelegate;
		if (pFactoryDelegate != nullptr)
		{
			uint64_t nRaw = nRawHandle & 0xFFFFFFFFFFFFFF;
			uint64_t nHead = ((uint64_t)pFactoryDelegate->GetHandleHead()) << 56;
			m_nHandle = nHead | nRaw;
		}
	}

	CString RefObject::GetFactoryName()
	{
		if (m_pFactoryDelegate != nullptr)
		{
			return m_pFactoryDelegate->GetName();
		}
		return L"";
	}

	uint64_t RefObject::GetHandle()
	{
		return m_nHandle;
	}

	void RefObject::Invoke(CString strMethod)
	{
		if (m_pFactoryDelegate != nullptr)
		{
			m_pFactoryDelegate->Invoke(this, strMethod);
		}
	}

	void RefObject::Invoke(CString strMethod, CString strParam1)
	{
		if (m_pFactoryDelegate != nullptr)
		{
			m_pFactoryDelegate->Invoke(this, strMethod, strParam1);
		}
	}

	void RefObject::AddEventListener(RefObjectEventListener* pEvtListener)
	{
		m_mapEventListeners[pEvtListener] = 1;
	}

	void RefObject::RemoveEventListener(RefObjectEventListener* pEvtListener)
	{
		auto it = m_mapEventListeners.find(pEvtListener);
		if (it != m_mapEventListeners.end())
		{
			m_mapEventListeners.erase(it);
		}
	}

	void RefObject::DispatchEvent(CString strEventType, RefObjectEvent* pEvent)
	{
		for (auto it = m_mapEventListeners.begin(); it != m_mapEventListeners.end(); ++it)
		{
			it->first->OnEventHandle(strEventType, pEvent);
		}
	}
}