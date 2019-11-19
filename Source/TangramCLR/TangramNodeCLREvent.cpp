/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2019 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS
* OUTLINED IN THE GPL LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
*
********************************************************************************/

#include "stdafx.h"
#include "TangramNodeCLREvent.h"

using namespace System::Runtime::InteropServices;

CWndNodeCLREvent::CWndNodeCLREvent()
{
}


CWndNodeCLREvent::~CWndNodeCLREvent()
{
	//delete m_pWndNode;
}

void CWndNodeCLREvent::OnOpenComplete(IWndNode* pNode)
{
	m_pWndNode->Fire_OpenComplete(m_pWndNode);
}

void CWndNodeCLREvent::OnDocumentComplete(IDispatch* pDocdisp, BSTR bstrUrl)
{
	Object^ pObj = reinterpret_cast<Object^>(Marshal::GetObjectForIUnknown((System::IntPtr)(pDocdisp)));
	m_pWndNode->Fire_OnDocumentComplete(m_pWndNode, pObj, BSTR2STRING(bstrUrl));
}

void CWndNodeCLREvent::OnDestroy()
{
	if (theAppProxy.m_pPropertyGrid&&theAppProxy.m_pPropertyGrid->SelectedObject==(Object^)m_pWndNode)
	{
		theAppProxy.m_pPropertyGrid->SelectedObject = nullptr;
	}
	if (m_pWndNode->m_pHostObj)
	{
		WndNode^ pNode = nullptr;
		if (TangramCLR::Tangram::m_pFrameworkElementDic->TryGetValue(m_pWndNode->m_pHostObj, pNode))
		{
			TangramCLR::Tangram::m_pFrameworkElementDic->Remove(m_pWndNode->m_pHostObj);
		}
	}
	m_pWndNode->Fire_OnDestroy(m_pWndNode);
}

void CWndNodeCLREvent::OnNodeAddInCreated(IDispatch* pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml)
{
	Object^ pAddinObj = reinterpret_cast<Object^>(Marshal::GetObjectForIUnknown((System::IntPtr)(pAddIndisp)));
	m_pWndNode->Fire_NodeAddInCreated(m_pWndNode, pAddinObj, BSTR2STRING(bstrAddInID), BSTR2STRING(bstrAddInXml));
}

void CWndNodeCLREvent::OnNodeAddInsCreated()
{
	m_pWndNode->Fire_NodeAddInsCreated(m_pWndNode);
}

void CWndNodeCLREvent::OnTabChange(int nActivePage, int nOldPage)
{
	m_pWndNode->Fire_OnTabChange(nActivePage, nOldPage);
}

void CWndNodeCLREvent::OnIPCMessageReceived(BSTR bstrChannel, BSTR bstrData)
{
	m_pWndNode->Fire_OnIPCMessageReceived(BSTR2STRING(bstrChannel), BSTR2STRING(bstrData));
}
