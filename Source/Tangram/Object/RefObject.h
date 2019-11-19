#pragma once

#include <stdint.h>
#include <map>

namespace Object
{
	class AbstractFactoryDelegate;
	class RefObjectEventListener;
	class RefObjectEvent;

	class RefObject
	{
	public:
		RefObject();
		RefObject(AbstractFactoryDelegate* pFactoryDelegate, uint64_t nRawHandle);
		virtual ~RefObject() {};

		CString GetFactoryName();
		uint64_t GetHandle();

		void Invoke(CString strMethod);
		void Invoke(CString strMethod, CString strParam1);
		void AddEventListener(RefObjectEventListener* pEvtListener);
		void RemoveEventListener(RefObjectEventListener* pEvtListener);
		void DispatchEvent(CString strEventType, RefObjectEvent* pEvent);

	private:
		uint64_t m_nHandle = 0;

		AbstractFactoryDelegate* m_pFactoryDelegate;

		map<RefObjectEventListener*, int> m_mapEventListeners;
	};
}