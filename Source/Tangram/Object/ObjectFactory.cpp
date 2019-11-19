#include "../stdafx.h"
#include "ObjectFactory.h"

#include "AbstractFactoryDelegate.h"
#include "CoreFactoryDelegate.h"

namespace Object
{
	ObjectFactory::ObjectFactory()
	{
		m_pCoreFactoryDelegate = new CoreFactoryDelegate();
		AddFactoryDelegate(m_pCoreFactoryDelegate);
	}

	ObjectFactory::~ObjectFactory() 
	{
		delete m_pCoreFactoryDelegate;
	}

	void ObjectFactory::AddFactoryDelegate(AbstractFactoryDelegate* pFactoryDelegate)
	{
		if (pFactoryDelegate != nullptr)
		{
			m_mapFactoryDelegateWithName[pFactoryDelegate->GetName()] = pFactoryDelegate;
			m_mapFactoryDelegateWithHead[pFactoryDelegate->GetHandleHead()] = pFactoryDelegate;
		}
	}

	RefObject* ObjectFactory::Create(CString strFactoryName, CString strConstructString)
	{
		auto it = m_mapFactoryDelegateWithName.find(strFactoryName);
		if (it != m_mapFactoryDelegateWithName.end())
		{
			return it->second->Create(strConstructString);
		}
		return nullptr;
	}

	CoreFactoryDelegate* ObjectFactory::GetCoreFactoryDelegate()
	{
		return m_pCoreFactoryDelegate;
	}
}