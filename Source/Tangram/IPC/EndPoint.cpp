#include "../stdafx.h"
#include "EndPoint.h"
#include "Broker.h"

namespace IPC
{
	EndPoint::EndPoint()
	{
	}

	EndPoint::~EndPoint()
	{
	}

	void EndPoint::OnIPCMessageReceived(CString strChannel, CString strData)
	{
		// Fire COM event and notifies the C++ layer via "virtual function overload" 
		// or "delegate objects".
	}

	void EndPoint::AddChannelInternal(CString strChannel)
	{
		Broker* pBroker = GetBroker();
		if (pBroker != nullptr)
		{
			pBroker->AddIPCListener(strChannel, this);
		}
	}

	void EndPoint::SendIPCMessageInternal(CString strChannel, CString strData)
	{
		// Do not call the Dispatch method directly. Use this method to route the
		// IPC message to specified Broker depending on the situation.

		Broker* pBroker = GetBroker();
		if (pBroker != nullptr)
		{
			pBroker->DispatchIPCMessage(strChannel, strData);
		}
	}
}