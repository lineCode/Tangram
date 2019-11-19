#pragma once

namespace IPC
{
	class Broker;

	class EndPoint
	{
	public:
		EndPoint();
		virtual ~EndPoint();

		virtual Broker* GetBroker() = 0;
		virtual void OnIPCMessageReceived(CString strChannel, CString strData);

		void AddChannelInternal(CString strChannel);
		void SendIPCMessageInternal(CString strChannel, CString strData);
	};
}
