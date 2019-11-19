#pragma once

#include <stdint.h>
#include <map>

namespace Object
{
	class RefObject;
	class CoreFactoryDelegate;
	class AbstractFactoryDelegate;

	class ObjectFactory
	{
	public:
		ObjectFactory();
		virtual ~ObjectFactory();

		void AddFactoryDelegate(AbstractFactoryDelegate* pFactoryDelegate);
		RefObject* Create(CString strFactoryName, CString strConstructString);

		CoreFactoryDelegate* GetCoreFactoryDelegate();
	private:
		CoreFactoryDelegate* m_pCoreFactoryDelegate;

		map<uint8_t, AbstractFactoryDelegate*> m_mapFactoryDelegateWithHead;
		map<CString, AbstractFactoryDelegate*> m_mapFactoryDelegateWithName;
	};
}