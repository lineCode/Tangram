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

#pragma once
//#include "dllmain.h"

#include "TangramObj.h"
#include "Tangram.h"       // main symbols
#include "TangramBase.h"       // main symbols
using namespace System;
using namespace System::Reflection;
using namespace TangramCLR;

class CWndNodeCLREvent
{
public:
	CWndNodeCLREvent();
	virtual ~CWndNodeCLREvent();

	gcroot<TangramCLR::WndNode^>	m_pWndNode;

	void OnDestroy();
	void OnNodeAddInsCreated();
	void OnOpenComplete(IWndNode* pNode);
	void OnDocumentComplete(IDispatch* pDocdisp, BSTR bstrUrl);
	void OnNodeAddInCreated(IDispatch* pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml);
	void OnTabChange(int nActivePage, int nOldPage);
	void OnIPCMessageReceived(BSTR bstrChannel, BSTR bstrData);
};
