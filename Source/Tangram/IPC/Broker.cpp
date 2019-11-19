#include "../stdafx.h"
#include "Broker.h"
#include "EndPoint.h"

namespace IPC
{
	Broker::Broker()
	{
	}


	Broker::~Broker()
	{
		for (auto it : m_mapIPCListeners)
		{
			delete it.second;
		}
		m_mapIPCListeners.clear();
	}

	void Broker::AddIPCListener(CString strChannel, EndPoint* pEndPoint)
	{
		map<EndPoint*, int>* mapChannelListeners = nullptr;
		auto it = m_mapIPCListeners.find(strChannel);
		if (it == m_mapIPCListeners.end())
		{
			mapChannelListeners = new map<EndPoint*, int>();
			m_mapIPCListeners[strChannel] = mapChannelListeners;
		}
		else
		{
			mapChannelListeners = it->second;
		}
		(*mapChannelListeners)[pEndPoint] = 1;
	}

	void Broker::RemoveIPCListener(CString strChannel, EndPoint* pEndPoint)
	{
		map<EndPoint*, int>* mapChannelListeners = nullptr;
		auto it = m_mapIPCListeners.find(strChannel);
		if (it == m_mapIPCListeners.end())
		{
			mapChannelListeners = new map<EndPoint*, int>();
			m_mapIPCListeners[strChannel] = mapChannelListeners;
		}
		else
		{
			mapChannelListeners = it->second;
		}
		auto it2 = mapChannelListeners->find(pEndPoint);
		if (it2 != mapChannelListeners->end())
		{
			mapChannelListeners->erase(it2);
		}
	}

	void Broker::DispatchIPCMessage(CString strChannel, CString strData)
	{
		map<EndPoint*, int>* mapChannelListeners = nullptr;
		auto it = m_mapIPCListeners.find(strChannel);
		if (it == m_mapIPCListeners.end())
		{
			mapChannelListeners = new map<EndPoint*, int>();
			m_mapIPCListeners[strChannel] = mapChannelListeners;
		}
		else
		{
			mapChannelListeners = it->second;
		}
		for (auto it2 : (*mapChannelListeners))
		{
			it2.first->OnIPCMessageReceived(strChannel, strData);
		}
		DispatchToOtherBrokers(strChannel, strData);
	}
}