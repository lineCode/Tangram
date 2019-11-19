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
********************************************************************************/

// TangramTreeView.cpp : Implementation of CTangramTreeView

#include "stdafx.h"
#include "TangramHtmlTreeWnd.h"
#include "TangramTreeView.h"


// CTangramTreeView
CTangramTreeView::CTangramTreeView()
{
	m_pTangramHtmlTreeWnd = NULL;
}


STDMETHODIMP CTangramTreeView::put_TangramTreeViewCallBack(BSTR bstrKey, ITangramTreeViewCallBack* newVal)
{
	CString strKey = OLE2T(bstrKey);
	strKey.Trim();
	strKey.MakeLower();
	auto it = m_mapTangramTreeViewCallBack.find(strKey);
	if(it==m_mapTangramTreeViewCallBack.end())
	{
		m_mapTangramTreeViewCallBack[strKey] = newVal;
		newVal->AddRef();
	}

	return S_OK;
}

void CTangramTreeView::FinalRelease()
{
	for(auto it : m_mapTangramTreeViewCallBack)
	{
		it.second->Release();
	}
	m_mapTangramTreeViewCallBack.erase(m_mapTangramTreeViewCallBack.begin(),m_mapTangramTreeViewCallBack.end());
}

STDMETHODIMP CTangramTreeView::AddTreeNode(long hItem, BSTR bstrXml)
{
	if(m_pTangramHtmlTreeWnd)
	{
		CTangramXmlParse m_Parse;
		if(m_Parse.LoadXml(OLE2T(bstrXml)))
		{
			int nCount = 0;
			if((HTREEITEM)hItem)
			{
				HTREEITEM hChild = m_pTangramHtmlTreeWnd->GetChildItem((HTREEITEM)hItem);
				CTangramXHtmlTreeNode *pXTCD = m_pTangramHtmlTreeWnd->GetItemDataStruct((HTREEITEM)hChild);
				if(pXTCD->m_bWaitingFor)
					m_pTangramHtmlTreeWnd->DeleteItem(hChild);
			}
				
			CTangramXHtmlTreeNode *pXTCD = m_pTangramHtmlTreeWnd->GetItemDataStruct((HTREEITEM)hItem);
			if(pXTCD)
				pXTCD->m_strTangramXML = _T("");

			m_pTangramHtmlTreeWnd->LoadXml(&m_Parse,(HTREEITEM)hItem,nCount);
			m_pTangramHtmlTreeWnd->Expand((HTREEITEM)hItem,TVE_EXPAND);
		}
	}

	return S_OK;
}

STDMETHODIMP CTangramTreeView::InsertNode(BSTR bstrXml, long* hItem)
{
	if(m_pTangramHtmlTreeWnd)
	{
		CTangramXmlParse m_Parse;
		if(m_Parse.LoadXml(OLE2T(bstrXml)))
		{
			int nCount = 0;
			HTREEITEM _hItem = m_pTangramHtmlTreeWnd->InsertXmlItem(&m_Parse,0);
			* hItem = (long)_hItem;
		}
	}
	return S_OK;
}

STDMETHODIMP CTangramTreeView::get_FirstRoot(long* pVal)
{
	if(m_pTangramHtmlTreeWnd&&m_pTangramHtmlTreeWnd->m_hFirstRoot)
	{
		* pVal = (long)m_pTangramHtmlTreeWnd->m_hFirstRoot;
	}

	return S_OK;
}
