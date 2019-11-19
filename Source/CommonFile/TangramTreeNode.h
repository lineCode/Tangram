/********************************************************************************
*					Tangram Library - version 8.0								*
*********************************************************************************
* Copyright (C) 2002-2016 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO 
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED 
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS 
* OUTLINED IN THE TANGRAM LICENSE AGREEMENT.TANGRAM TEAM 
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE 
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:sunhuizlz@yeah.net
* http://www.cloudaddin.com
*
********************************************************************************/
// TangramTreeNode.h : Declaration of the CTangramTreeNode

#pragma once
#include "resource.h"       // main symbols
#include "Tangram.h"

struct CTangramXHtmlTreeNode;
// CTangramTreeNode

class CTangramTreeNode :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ITangramTreeNode, &IID_ITangramTreeNode, &LIBID_TangramLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTangramTreeNode();

DECLARE_NO_REGISTRY()


BEGIN_COM_MAP(CTangramTreeNode)
	COM_INTERFACE_ENTRY(ITangramTreeNode)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	CTangramXHtmlTreeNode* m_pXHTMLTREEDATA;
};
