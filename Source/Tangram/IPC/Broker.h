#pragma once

#include <map>

namespace IPC
{
	class EndPoint;

	class Broker
	{
	public:
		Broker();
		virtual ~Broker();

		void AddIPCListener(CString strChannel, EndPoint* pEndPoint);
		void RemoveIPCListener(CString strChannel, EndPoint* pEndPoint);
		void DispatchIPCMessage(CString strChannel, CString strData);

		virtual void DispatchToOtherBrokers(CString strChannel, CString strData) = 0;

	private:
		map<CString, map<EndPoint*, int>*> m_mapIPCListeners; // TODO: Need to removed when destructuring?
	};
}
