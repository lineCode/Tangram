#pragma once
#include "OfficePlus\LyncPlus\lync.h"
#include "OfficePlus\LyncPlus\uccapi.h"
#include "OfficePlus\LyncPlus\UccAPIEvent.h"
#include "OfficePlus\LyncPlus\lyncevent.h"
using namespace UCCAPILib;
using namespace UCCollaborationLib;
using namespace OfficePlus::LyncPlus::UccApiEvent;
using namespace OfficePlus::LyncPlus::LyncClientEvent;

class CLyncAppProxy : 
	public CLyncRoomManagerEvents, 
	public CUccSessionManagerEvents,
	public CTangramLyncClientEvents,
	public CLyncConversationManagerEvents
{
public:
	CLyncAppProxy();
	virtual ~CLyncAppProxy();

	ClientState								m_nLyncState;
	CString									m_strUserUri;
	ILyncClient*							m_pLyncClient;
	IAutomation*							m_pLyncAutomation;
	IUccUriManager*							m_spUriManager;
	IRoomManager*							m_pLyncRoomManager;
	IUCOfficeIntegration*					m_pUCOfficeIntegration;
	IConversationManager*					m_pLyncConversationManager;
	IUccSessionManager*						m_spSessionManager;
	IUccSignalingChannelManager*			m_spSignalingChannelManager;

	BOOL InitLyncApp();
};

