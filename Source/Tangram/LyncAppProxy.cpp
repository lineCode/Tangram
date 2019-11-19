#include "stdafx.h"
#include "TangramApp.h"
#include "TangramCore.h"
#include "LyncAppProxy.h"


CLyncAppProxy::CLyncAppProxy()
{
	m_nLyncState = ucClientStateSignedOut;
	m_strUserUri = _T("");
	m_pLyncClient = nullptr;
	m_pLyncAutomation = nullptr;
	m_spUriManager = nullptr;
	m_pLyncRoomManager = nullptr;
	m_pUCOfficeIntegration = nullptr;
	m_pLyncConversationManager = nullptr;
	m_spSessionManager = nullptr;
	m_spSignalingChannelManager = nullptr;
}

CLyncAppProxy::~CLyncAppProxy()
{
	HRESULT hr = S_OK;
	DWORD m_nRefCount = -1;
	g_pTangram->Lock();
	if (m_spUriManager)
	{
		m_nRefCount = m_spUriManager->Release();
		while (m_nRefCount>0)
		{
			m_nRefCount = m_spUriManager->Release();
		}
		m_spUriManager = nullptr;
	}
	if (m_pLyncRoomManager)
	{
		((CLyncRoomManagerEvents*)this)->DispEventUnadvise(m_pLyncRoomManager);
		m_nRefCount = m_pLyncRoomManager->Release();
		while (m_nRefCount>0)
		{
			m_nRefCount = m_pLyncRoomManager->Release();
		}
		m_pLyncRoomManager = nullptr;
	}
	if (m_pLyncConversationManager)
	{
		((CLyncConversationManagerEvents*)this)->DispEventUnadvise(m_pLyncConversationManager);
		m_nRefCount = m_pLyncConversationManager->Release();
		while (m_nRefCount>0)
		{
			m_nRefCount = m_pLyncConversationManager->Release();
		}
		m_pLyncConversationManager = nullptr;
	}
	if (m_spSessionManager)
	{
		((CUccSessionManagerEvents*)this)->DispEventUnadvise(m_spSessionManager);
		m_nRefCount = m_spSessionManager->Release();
		while (m_nRefCount>0)
		{
			m_nRefCount = m_spSessionManager->Release();
		}
		m_spSessionManager = nullptr;
	}
	if (m_spSignalingChannelManager)
	{
		DWORD m_nRefCount = m_spSignalingChannelManager->Release();
		while (m_nRefCount>0)
		{
			m_nRefCount = m_spSignalingChannelManager->Release();
		}
		m_spSignalingChannelManager = nullptr;
	}
	if (m_pLyncClient)
	{
		((CTangramLyncClientEvents*)this)->DispEventUnadvise(m_pLyncClient);
		m_nRefCount = m_pLyncClient->Release();
		while (m_nRefCount>0)
		{
			m_nRefCount = m_pLyncClient->Release();
		}
		m_pLyncClient = nullptr;
	}
	if (m_pLyncAutomation)
	{
		m_nRefCount = m_pLyncAutomation->Release();
		while (m_nRefCount>0)
		{
			m_nRefCount = m_pLyncAutomation->Release();
		}
		m_pLyncAutomation = nullptr;
	}
	g_pTangram->Unlock();
}

BOOL CLyncAppProxy::InitLyncApp()
{
	BSTR bstrVer;
	CComPtr<IUCOfficeIntegration> _pUCOfficeIntegration;
	CLSID cls;
	::CLSIDFromProgID(L"lync.UCOfficeIntegration.1", &cls);
	if (_pUCOfficeIntegration.CoCreateInstance(CComBSTR("lync.UCOfficeIntegration.1"), 0, CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER) != S_OK)
	{
		if (_pUCOfficeIntegration.CoCreateInstance(CLSID_UCOfficeIntegration, 0, CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER) == S_OK)
			bstrVer = ::SysAllocString(L"14.0.0.0");
		else
			return FALSE;
	}
	else
		bstrVer = ::SysAllocString(L"15.0.0.0");
	if (_pUCOfficeIntegration)
	{
		IDispatch* pLyncClient = NULL;
		IDispatch* pLyncAuto = NULL;
		_pUCOfficeIntegration->GetInterface(bstrVer, oiInterfaceILyncClient, (IDispatch * *)&pLyncClient);
		_pUCOfficeIntegration->GetInterface(bstrVer, oiInterfaceIAutomation, (IDispatch * *)&pLyncAuto);
		HRESULT hr = pLyncClient->QueryInterface(UCCollaborationLib::IID_ILyncClient, (void**)&m_pLyncClient);
		m_pLyncClient->AddRef();

		hr = pLyncAuto->QueryInterface(UCCollaborationLib::IID_IAutomation, (void**)&m_pLyncAutomation);
		m_pLyncAutomation->AddRef();
		::SysFreeString(bstrVer);

		((CTangramLyncClientEvents*)this)->DispEventAdvise(m_pLyncClient);
		hr = m_pLyncClient->get_ConversationManager(&m_pLyncConversationManager);
		if (hr == S_OK)
			hr = ((CLyncConversationManagerEvents*)this)->DispEventAdvise(m_pLyncConversationManager);

		CComQIPtr<IClient2>pLyncClient2(pLyncClient);
		if (pLyncClient2)
		{
			hr = pLyncClient2->get_RoomManager(&m_pLyncRoomManager);
			m_pLyncRoomManager->AddRef();
			((CLyncRoomManagerEvents*)this)->DispEventAdvise(m_pLyncRoomManager);
		}


		return TRUE;
	}
	return FALSE;
}