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

// TangramObject.cpp : Implementation of CCompositorManager

#include "stdafx.h"
#include "WndNode.h"
#include "Compositor.h"
#include "TangramCtrl.h"
#include "TangramApp.h"
#include "TangramCore.h"

CTangramNodeCommonData::CTangramNodeCommonData()
{
	m_pOldCompositor			= nullptr;
	m_pOfficeObj		= nullptr;
	m_pTangramParse		= nullptr;
	m_pHostClientView	= nullptr;
#ifdef _DEBUG
	g_pTangram->m_nTangramNodeCommonData++;
#endif	
};

CTangramNodeCommonData::~CTangramNodeCommonData()
{
	if (m_pTangramParse)
		delete m_pTangramParse;
#ifdef _DEBUG
	g_pTangram->m_nTangramNodeCommonData--;
#endif	
};

// CCompositorManager

CCompositorManager::CCompositorManager()
{
	m_hWnd								= 0;
	m_bIsBlank							= false;
	m_bPageDataLoaded					= false;
	m_bIsDestory						= false;
	m_bDocComplete						= false;
	m_bDoc								= false;
	m_strXmlHeader						= _T("");
	m_strPageFileName					= _T("");
	m_strPageFilePath					= _T("");
	m_strConfigFileNodeName				= _T("tangramdefaultpage");
	m_pBKFrame							= nullptr;
	m_pActiveDoc						= nullptr;
	g_pTangram->m_pCompositorManager					= this;
	m_pTangramAppProxy					= nullptr;
	m_pTangramDocTemplate				= nullptr;

#ifdef _DEBUG
	g_pTangram->m_nTangram++;
#endif	
}

CCompositorManager::~CCompositorManager()
{
	if (this == g_pTangram->m_pDesignerCompositorManager)
		g_pTangram->m_pDesignerCompositorManager = nullptr;
#ifdef _DEBUG
	g_pTangram->m_nTangram--;
#endif	
	//if(g_pTangram->m_nTangram==0)
	//	return;

	for (auto it2 : m_mapExternalObj)
	{
		it2.second->Release();
	}
	m_mapExternalObj.erase(m_mapExternalObj.begin(), m_mapExternalObj.end());

	m_mapCompositor.erase(m_mapCompositor.begin(), m_mapCompositor.end());
	m_mapNode.erase(m_mapNode.begin(), m_mapNode.end());
	auto it = g_pTangram->m_mapWindowPage.find(m_hWnd);
	if (it != g_pTangram->m_mapWindowPage.end())
	{
		g_pTangram->m_mapWindowPage.erase(it);
	}
	if (g_pTangram->m_mapWindowPage.size() == 0)
		g_pTangram->Close();
	else
	{
		if (g_pTangram->m_mapWindowPage.size() == 1 && g_pTangram->m_pDesignerCompositorManager)
		{
			if (g_pTangram->m_bDeleteCompositorManager == FALSE)
				::DestroyWindow(g_pTangram->m_hHostWnd);
			else
				g_pTangram->m_bDeleteCompositorManager = FALSE;
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		if (it.second->m_bAutoDelete)
			delete it.second;
	}
	m_mapCompositorManagerProxy.clear();
	for (auto it : m_mapEventObj)
		delete it.second;
	m_mapEventObj.clear();
}

STDMETHODIMP CCompositorManager::get_Count(long* pCount)
{
	*pCount = (long)m_mapCompositor.size();
	return S_OK;
}

STDMETHODIMP CCompositorManager::get_Compositor(VARIANT vIndex, ICompositor ** ppCompositor)
{
	if (vIndex.vt == VT_I4)
	{
		long lCount = m_mapCompositor.size();
		int iIndex = vIndex.lVal;
		HWND hWnd = (HWND)iIndex;
		if (::IsWindow(hWnd))
		{
			auto it = m_mapCompositor.find(hWnd);
			if (it != m_mapCompositor.end())
			{
				*ppCompositor = it->second;
				return S_OK;
			}
		}
		if (iIndex < 0 || iIndex >= lCount) return E_INVALIDARG;

		auto it = m_mapCompositor.begin();
		int iPos = 0;
		while (it != m_mapCompositor.end())
		{
			if (iPos == iIndex)
			{
				*ppCompositor = it->second;
				return S_OK;
			};
			iPos++;
			it++;
		}
		return S_OK;
	}

	if (vIndex.vt == VT_BSTR)
	{
		CString strKey = OLE2T(vIndex.bstrVal);
		auto it = m_mapWnd.find(strKey);
		if (it != m_mapWnd.end())
		{
			auto it2 = m_mapCompositor.find(it->second);
			if (it2 != m_mapCompositor.end())
			{
				*ppCompositor = it2->second;
				return S_OK;
			}
		}
		return E_INVALIDARG;
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::get__NewEnum(IUnknown** ppVal)
{
	typedef CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT>>
		CComEnumVariant;

	CComObject<CComEnumVariant> *pe = 0;
	HRESULT hr = pe->CreateInstance(&pe);

	if (SUCCEEDED(hr))
	{
		pe->AddRef();
		long nLen = (long)m_mapCompositor.size();
		VARIANT* rgvar = new VARIANT[nLen];
		ZeroMemory(rgvar, sizeof(VARIANT)*nLen);
		VARIANT* pItem = rgvar;
		for (auto it : m_mapCompositor)
		{
			IUnknown* pDisp = nullptr;
			CCompositor* pObj = it.second;
			hr = pObj->QueryInterface(IID_IUnknown, (void**)&pDisp);
			pItem->vt = VT_UNKNOWN;
			pItem->punkVal = pDisp;
			if (pItem->punkVal != nullptr)
				pItem->punkVal->AddRef();
			pItem++;
			pDisp->Release();
		}

		hr = pe->Init(rgvar, &rgvar[nLen], 0, AtlFlagTakeOwnership);
		if (SUCCEEDED(hr))
			hr = pe->QueryInterface(IID_IUnknown, (void**)ppVal);
		pe->Release();
	}
	return S_OK;
}

STDMETHODIMP CCompositorManager::CreateCompositor(VARIANT ParentObj, VARIANT HostWnd, BSTR bstrFrameName, ICompositor** pRetFrame)
{
	HWND h = 0; 
	CString strFrameName = OLE2T(bstrFrameName);
	//auto it = m_mapWnd.find(strFrameName);
	//if (it != m_mapWnd.end())
	//{
	//	int i = 0;
	//	CString s = _T("");
	//	s.Format(_T("%s%d"), strFrameName,i);
	//	auto it = m_mapWnd.find(s);
	//	while (it != m_mapWnd.end())
	//	{
	//		i++;
	//		s.Format(_T("%s%d"), strFrameName, i);
	//		it = m_mapWnd.find(s);
	//		if (it == m_mapWnd.end())
	//			break;
	//	}
	//	strFrameName = s;
	//}
	BSTR bstrName = strFrameName.MakeLower().AllocSysString();
	if (ParentObj.vt == VT_DISPATCH&&HostWnd.vt == VT_BSTR)
	{
		if (g_pTangram->m_pCLRProxy)
		{
			IDispatch* pDisp = nullptr;
			pDisp = g_pTangram->m_pCLRProxy->GetCtrlByName(ParentObj.pdispVal, HostWnd.bstrVal, true);
			if (pDisp)
			{
				h = g_pTangram->m_pCLRProxy->GetCtrlHandle(pDisp);
				if (h)
				{
					HRESULT hr = CreateCompositor(CComVariant(0), CComVariant((long)h), bstrName, pRetFrame);
					::SysFreeString(bstrName);
					return hr;
				}
			}
		}
		::SysFreeString(bstrName);
		return S_FALSE;
	}
	if (HostWnd.vt == VT_DISPATCH)
	{
		if (g_pTangram->m_pCLRProxy)
		{
			h = g_pTangram->m_pCLRProxy->IsCtrlCanNavigate(HostWnd.pdispVal);
			if (h)
			{
				CString strName = strFrameName;
				if (strName == _T(""))
				{
					::SysFreeString(bstrName);
					bstrFrameName = g_pTangram->m_pCLRProxy->GetCtrlName(HostWnd.pdispVal);
					strName = OLE2T(bstrFrameName);
					if (strName == _T(""))
						bstrFrameName = CComBSTR(L"Default");
					
					strFrameName = OLE2T(bstrFrameName);
					auto it = m_mapWnd.find(strFrameName);
					if (it != m_mapWnd.end())
					{
						int i = 0;
						CString s = _T("");
						s.Format(_T("%s%d"), strFrameName, i);
						auto it = m_mapWnd.find(s);
						while (it != m_mapWnd.end())
						{
							i++;
							s.Format(_T("%s%d"), strFrameName, i);
							it = m_mapWnd.find(s);
							if (it == m_mapWnd.end())
								break;
						}
						strFrameName = s;
					}

				}
				auto it = m_mapCompositor.find((HWND)h);
				if (it == m_mapCompositor.end())
					return CreateCompositor(CComVariant(0), CComVariant((long)h), CComBSTR(strFrameName.MakeLower()), pRetFrame);
				else
					*pRetFrame = it->second;
			}
		}
	}
	else if (HostWnd.vt == VT_I2||HostWnd.vt == VT_I4 || HostWnd.vt == VT_I8)
	{
		BOOL bIsMDI = FALSE;
		HWND _hWnd = NULL;
		if(HostWnd.vt == VT_I4)
			_hWnd = (HWND)HostWnd.lVal;
		if(HostWnd.vt == VT_I8)
			_hWnd = (HWND)HostWnd.llVal;
		if (_hWnd == 0)
		{
			_hWnd = ::FindWindowEx(m_hWnd, NULL, _T("MDIClient"), NULL);
			if (_hWnd == NULL)
				_hWnd = ::GetWindow(m_hWnd, GW_CHILD);
			else
				bIsMDI = TRUE;
		}
		if (_hWnd&&::IsWindow(_hWnd))
		{
			auto it = m_mapCompositor.find(_hWnd);
			if (it == m_mapCompositor.end())
			{
				DWORD dwID = ::GetWindowThreadProcessId(_hWnd, NULL);
				TangramThreadInfo* pThreadInfo = g_pTangram->GetThreadInfo(dwID);

				CCompositor* m_pExtenderCompositor = new CComObject<CCompositor>();
				CString strName = strFrameName;
				if (strName == _T(""))
					strName = _T("default");
				strName.MakeLower();
				m_pExtenderCompositor->m_strCompositorName = strName;
				if (strName.CompareNoCase(_T("System.Windows.Forms.MdiClient")) == 0)
					m_pExtenderCompositor->m_nCompositorType = WinFormMDIClientCompositor;
				else if(bIsMDI)
					m_pExtenderCompositor->m_nCompositorType = MDIClientCompositor;
				::GetClassName(::GetParent(_hWnd), g_pTangram->m_szBuffer, MAX_PATH);
				CString strClassName = CString(g_pTangram->m_szBuffer);
				if (strClassName.Find(_T("Afx:ControlBar:")) == 0)
				{
					if (g_pTangram->m_pMDIMainWnd)
					{
						auto it = g_pTangram->m_pMDIMainWnd->m_mapDesignableWnd.find(_hWnd);
						if (it == g_pTangram->m_pMDIMainWnd->m_mapDesignableWnd.end())
						{
							g_pTangram->m_pMDIMainWnd->m_mapDesignableWnd[_hWnd] = strName;
						}
					}
					m_pExtenderCompositor->m_nCompositorType = CtrlBarCompositor;
				}
				else if (strClassName.Find(_T("MDIClient")) == 0)
				{
					m_pExtenderCompositor->m_nCompositorType = MDIClientCompositor;
				}
				m_pExtenderCompositor->m_pCompositorManager = this;
				m_pExtenderCompositor->m_hHostWnd = _hWnd;
				if (ParentObj.vt == VT_I8 || ParentObj.vt == VT_I4)
				{
					HWND hPWnd = (HWND)ParentObj.llVal;
					if (::IsWindow(hPWnd))
					{
						m_pExtenderCompositor->m_hPWnd = hPWnd;
					}
				}
				pThreadInfo->m_mapCompositor[_hWnd] = m_pExtenderCompositor;
				m_mapCompositor[_hWnd] = m_pExtenderCompositor;
				m_mapWnd[strName] = _hWnd;

				for (auto it : g_pTangram->m_mapTangramAppProxy)
				{
					CCompositorProxy* pCompositorProxy = it.second->OnCompositorCreated(m_pExtenderCompositor);
					if (pCompositorProxy)
					{
						m_pExtenderCompositor->m_mapCompositorProxy[it.second] = pCompositorProxy;
					}
				}

				*pRetFrame = m_pExtenderCompositor;
			}
			else
				*pRetFrame = it->second;
		}
	}
		
	return S_OK;
}


STDMETHODIMP CCompositorManager::GetCompositorFromCtrl(IDispatch* CtrlObj, ICompositor** ppCompositor)
{
	if (g_pTangram->m_pCLRProxy)
	{
		HWND h = g_pTangram->m_pCLRProxy->IsCtrlCanNavigate(CtrlObj);
		if (h)
		{
			auto it = m_mapCompositor.find(h);
			if (it != m_mapCompositor.end())
				* ppCompositor = it->second;
		}
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::GetWndNode(BSTR bstrFrameName, BSTR bstrNodeName, IWndNode** pRetNode)
{
	CString strKey = OLE2T(bstrFrameName);
	CString strName = OLE2T(bstrNodeName);
	if (strKey == _T("") || strName == _T(""))
		return S_FALSE;
	auto it = m_mapWnd.find(strKey);
	if (it != m_mapWnd.end())
	{
		HWND hWnd = it->second;
		if (::IsWindow(hWnd))
		{
			auto it = m_mapCompositor.find(hWnd);
			if (it != m_mapCompositor.end())
			{
				CCompositor* pCompositor = it->second;
				strName = strName.MakeLower();
				auto it2 = pCompositor->m_mapNode.find(strName);
				if (it2 != pCompositor->m_mapNode.end())
					*pRetNode = (IWndNode*)it2->second;
				else
				{
					it2 = m_mapNode.find(strName);
					if (it2 != m_mapNode.end())
						*pRetNode = (IWndNode*)it2->second;
				}
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::get_Extender(BSTR bstrExtenderName, IDispatch** pVal)
{
	CString strName = OLE2T(bstrExtenderName);
	if (strName == _T(""))
		return S_OK;
	auto it = m_mapExternalObj.find(strName);
	if (it != m_mapExternalObj.end())
	{
		*pVal = it->second;
		(*pVal)->AddRef();
	}
	return S_OK;
}


STDMETHODIMP CCompositorManager::put_Extender(BSTR bstrExtenderName, IDispatch* newVal)
{
	CString strName = OLE2T(bstrExtenderName);
	if (strName == _T(""))
		return S_OK;
	auto it = m_mapExternalObj.find(strName);
	if (it == m_mapExternalObj.end())
	{
		m_mapExternalObj[strName] = newVal;
		newVal->AddRef();
	}
	return S_OK;
}

STDMETHODIMP CCompositorManager::get_CompositorName(LONGLONG hHwnd, BSTR* pVal)
{
	HWND _hWnd = (HWND)hHwnd;
	if (_hWnd)
	{
		auto it = m_mapCompositor.find(_hWnd);
		if (it!=m_mapCompositor.end())
			*pVal = it->second->m_strCompositorName.AllocSysString();
	}

	return S_OK;
}

//STDMETHODIMP CCompositorManager::get_Compositor(BSTR bstrFrameName, ICompositor** pVal)
//{
//	CString strName = OLE2T(bstrFrameName);
//	if (strName != _T(""))
//	{
//		auto it = m_mapWnd.find(strName);
//		if (it != m_mapWnd.end())
//		{
//			HWND h = it->second;
//			auto it2 = m_mapCompositor.find(h);
//			if (it2 != m_mapCompositor.end())
//				*pVal = it2->second;
//		}
//	}
//	return S_OK;
//}

void CCompositorManager::OnNodeDocComplete(WPARAM wParam)
{
	bool bState = false;
	for (auto it1 : m_mapCompositor)
	{
		for (auto it2 : it1.second->m_mapNode)
		{
			if (it2.second->m_bCreated == false)
			{
				::PostMessage(m_hWnd, WM_TANGRAM_WEBNODEDOCCOMPLETE, wParam, 0);
				return;
			}
		}
	}

	switch (wParam)
	{
	case 0:
		break;
	case 1:
	default:
		break;
	}
}

void CCompositorManager::UpdateMapKey(CString strXml)
{
	if (m_strXmlHeader != _T(""))
		return;
	CTangramXmlParse m_Parse;
	if (m_Parse.LoadXml(strXml)||m_Parse.LoadFile(strXml))
	{
		strXml = m_Parse.xml();
		int nPos = strXml.Find(_T(">"));
		m_strXmlHeader = strXml.Left(nPos + 1);
		nPos = strXml.ReverseFind('<');
		if (nPos != -1)
			m_strXmlBottom = strXml.Mid(nPos);
		CString strMainKey = _T("tangramdefaultpage");
		int nCount = m_Parse.GetCount();
		for (int i = 0; i < nCount; i++)
		{
			CTangramXmlParse* pChild = m_Parse.GetChild(i);
			CString strFrameName = pChild->name();
			int nCount = pChild->GetCount();
			for (int i = 0; i < nCount; i++)
			{
				CTangramXmlParse* _pChild = pChild->GetChild(i);
				CString strKey = _pChild->name();
				if (strKey.CompareNoCase(_T("tangram")) == 0)
					strKey = _T("default");
				CString _strKey = strKey + _T("@") + strFrameName + _T("@") + strMainKey;
				m_strMapKey[_strKey] = _pChild->xml();
			}
		}

		if (m_bPageDataLoaded == false)
		{
			m_bPageDataLoaded = true;
			CTangramXmlParse* pParse = (CTangramXmlParse*)m_Parse.GetChild(_T("pagedata"));
			if (pParse&&::PathFileExists(g_pTangram->m_strTemplatePath) == TRUE)
			{
				int nCount = pParse->GetCount();
				if (nCount)
				{
					for (int i = 0; i < nCount; i++)
					{
						CString strPath = g_pTangram->m_strTemplatePath;
						CTangramXmlParse* pChild = pParse->GetChild(i);
						CString strName = pChild->name();
						m_mapXtml[strName] = pChild->xml();
						int nPos = strPath.ReverseFind('\\');
						CString strFileName = strPath.Mid(nPos + 1);
						int nPos1 = strFileName.ReverseFind('.');
						strFileName = strFileName.Left(nPos1);
						strPath = strPath.Left(nPos + 1) + strFileName + _T("_") + strName + _T(".bmp");
						if (::PathFileExists(strPath))
						{
							m_mapXtml[strName + _T("_imagePath")] = strPath;
							CString strData = g_pTangram->EncodeFileToBase64(strPath);
							m_mapXtml[strName + _T("_image")] = strData;
						}
					}
				}
			}
		}
	}
}

void CCompositorManager::BeforeDestory()
{
	if (!m_bIsDestory)
	{
		m_bIsDestory = true;
		Fire_Destroy();

		for (auto it: m_mapCompositor)
			it.second->Destroy();

		if (g_pTangram->m_pCLRProxy)
		{
			g_pTangram->m_pCLRProxy->ReleaseTangramObj((ICompositorManager*)this);
		}
	}
}

STDMETHODIMP CCompositorManager::get_Node(BSTR bstrNodeName, IWndNode** pVal)
{
	CString strName = OLE2T(bstrNodeName);
	if (strName == _T(""))
		return S_OK;
	auto it2 = m_mapNode.find(strName);
	if (it2 == m_mapNode.end())
		return S_OK;

	if (it2->second)
		*pVal = it2->second;

	return S_OK;
}

STDMETHODIMP CCompositorManager::get_XObject(BSTR bstrName, IDispatch** pVal)
{
	CString strName = OLE2T(bstrName);
	if (strName == _T(""))
		return S_OK;
	auto it2 = m_mapNode.find(strName);
	if (it2 == m_mapNode.end())
		return S_OK;
	if (it2->second->m_pDisp)
	{
		*pVal = it2->second->m_pDisp;
		(*pVal)->AddRef();
	}
	return S_OK;
}

STDMETHODIMP CCompositorManager::get_Width(long* pVal)
{
	if (m_hWnd)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		*pVal = rc.right - rc.left;
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::put_Width(long newVal)
{
	if (m_hWnd&&newVal)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		rc.right = rc.left + newVal;
		::SetWindowPos(m_hWnd, NULL, rc.left, rc.top, newVal, rc.bottom - rc.top, SWP_NOACTIVATE | SWP_NOREDRAW);
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::get_Height(long* pVal)
{
	if (m_hWnd)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		*pVal = rc.bottom - rc.top;
	}
	return S_OK;
}

STDMETHODIMP CCompositorManager::put_Height(long newVal)
{
	if (m_hWnd&&newVal)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		rc.right = rc.left + newVal;
		::SetWindowPos(m_hWnd, NULL, rc.left, rc.top, rc.right - rc.left, newVal, SWP_NOACTIVATE | SWP_NOREDRAW);
	}
	return S_OK; 
}

STDMETHODIMP CCompositorManager::get_NodeNames(BSTR* pVal)
{
	CString strNames = _T("");
	for (auto it : m_mapNode)
	{
		strNames += it.first;
		strNames += _T(",");
	}
	int nPos = strNames.ReverseFind(',');
	strNames = strNames.Left(nPos);
	*pVal = strNames.AllocSysString();
	return S_OK;
}

STDMETHODIMP CCompositorManager::get_Parent(ICompositorManager** pVal)
{
	HWND hWnd = ::GetParent(m_hWnd);
	if (hWnd == NULL)
		return S_OK;

	auto it = g_pTangram->m_mapWindowPage.find(hWnd);
	while (it == g_pTangram->m_mapWindowPage.end())
	{
		hWnd = ::GetParent(hWnd);
		if (hWnd == NULL)
			return S_OK;
		it = g_pTangram->m_mapWindowPage.find(hWnd);
		if (it != g_pTangram->m_mapWindowPage.end())
		{
			*pVal = it->second;
			return S_OK;
		}
	}
	return S_OK;
}

STDMETHODIMP CCompositorManager::get_Handle(LONGLONG* pVal)
{
	if (m_hWnd)
		*pVal = (LONGLONG)m_hWnd;
	return S_OK;
}

STDMETHODIMP CCompositorManager::GetCtrlInNode(BSTR NodeName, BSTR CtrlName, IDispatch** ppCtrl)
{
	CString strName = OLE2T(NodeName);
	if (strName == _T(""))
		return S_OK;
	auto it2 = m_mapNode.find(strName);
	if (it2 == m_mapNode.end())
		return S_OK;

	CWndNode* pNode = it2->second;
	if (pNode)
		pNode->GetCtrlByName(CtrlName, true, ppCtrl);

	return S_OK;
}

STDMETHODIMP CCompositorManager::get_xtml(BSTR strKey, BSTR* pVal)
{
	map<CString, CString>::iterator it = m_mapXtml.find(OLE2T(strKey));
	if (it != m_mapXtml.end())
		*pVal = it->second.AllocSysString();

	return S_OK;
}

STDMETHODIMP CCompositorManager::put_xtml(BSTR strKey, BSTR newVal)
{
	CString strkey = OLE2T(strKey);
	CString strVal = OLE2T(newVal);
	if (strkey == _T("") || strVal == _T(""))
		return S_OK;
	auto it = m_mapXtml.find(strkey);
	if (it != m_mapXtml.end())
		m_mapXtml.erase(it);

	m_mapXtml[strkey] = strVal;
	return S_OK;
}

STDMETHODIMP CCompositorManager::Open(IDispatch* Parent, BSTR CtrlName, BSTR FrameName, BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode)
{
	if (g_pTangram->m_pCLRProxy)
	{
		IDispatch* pDisp = nullptr;
		pDisp =g_pTangram->m_pCLRProxy->GetCtrlByName(Parent, CtrlName, true);
		if (pDisp)
		{
			HWND h = 0;
			h = g_pTangram->m_pCLRProxy->IsCtrlCanNavigate(pDisp);
			if (h)
			{
				CString strFrameName = OLE2T(FrameName);
				CString strKey = OLE2T(bstrKey);
				if (strFrameName == _T(""))
					FrameName = CtrlName;
				if (strKey == _T(""))
					bstrKey = CComBSTR(L"Default");
				auto it = m_mapCompositor.find((HWND)h);
				if (it == m_mapCompositor.end())
				{
					ICompositor* pCompositor = nullptr;
					CreateCompositor(CComVariant(0), CComVariant((long)h), FrameName, &pCompositor);
					return pCompositor->Open(bstrKey, bstrXml, ppRetNode);
				}
				else
				{
					return it->second->Open(bstrKey, bstrXml, ppRetNode);
				}
			}
		}
	}
	return S_OK;
}

STDMETHODIMP CCompositorManager::OpenCtrl(VARIANT MdiForm, BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode)
{
	HWND h = 0;
	bool bMDI = false;
	if (MdiForm.vt == VT_DISPATCH)
	{
		if (g_pTangram->m_pCLRProxy)
		{
			h = g_pTangram->m_pCLRProxy->GetMDIClientHandle(MdiForm.pdispVal);
			if (h)
				bMDI = true;
			else
			{
				h = g_pTangram->m_pCLRProxy->IsCtrlCanNavigate(MdiForm.pdispVal);
				if (h)
				{
					CComBSTR bstrName(L"");
					bstrName = g_pTangram->m_pCLRProxy->GetCtrlName(MdiForm.pdispVal);
					CString strKey = OLE2T(bstrKey);
					if (strKey == _T(""))
						bstrKey = CComBSTR(L"Default");
					ICompositor* pCompositor = nullptr;
					map<HWND, CCompositor*>::iterator it = m_mapCompositor.find((HWND)h);
					if (it == m_mapCompositor.end())
					{
						CreateCompositor(CComVariant(0), CComVariant((long)h), bstrName, &pCompositor);
						return pCompositor->Open(bstrKey, bstrXml, ppRetNode);
					}
					else
					{
						return it->second->Open(bstrKey, bstrXml, ppRetNode);
					}
				}
			}
		}
	}
	else if (MdiForm.vt == VT_I4 || MdiForm.vt == VT_I8)
	{
		HWND hWnd = NULL;
		if (MdiForm.vt == VT_I4)
		{
			if (MdiForm.lVal == 0)
			{
				hWnd = ::FindWindowEx(m_hWnd, NULL, _T("MDIClient"), NULL);
				if (hWnd)
				{
					bMDI = true;
				}
				else
				{
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);
				}
			}
			else
			{
				hWnd = (HWND)MdiForm.lVal;
				if (::IsWindow(hWnd) == false)
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);
			}
		}
		if (MdiForm.vt == VT_I8)
		{
			if (MdiForm.llVal == 0)
			{
				hWnd = ::FindWindowEx(m_hWnd, NULL, _T("MDIClient"), NULL);
				if (hWnd)
				{
					bMDI = true;
				}
				else
				{
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);
				}
			}
			else
			{
				hWnd = (HWND)MdiForm.llVal;
				if (::IsWindow(hWnd) == false)
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);

			}
		}
		h = hWnd;
	}
	if (h)
	{
		CString strKey = OLE2T(bstrKey);
		if (strKey == _T(""))
			bstrKey = CComBSTR(L"Default");
		ICompositor* pCompositor = nullptr;
		if (bMDI)
		{
			HRESULT hr = CreateCompositor(CComVariant(0), CComVariant((long)h), CComBSTR(L"TangramMDIClientCompositor"), &pCompositor);
			if (pCompositor)
			{
				return pCompositor->Open(bstrKey, bstrXml, ppRetNode);
			}
		}
		else
		{
			CString strKey = OLE2T(bstrKey);
			if (strKey == _T(""))
				bstrKey = CComBSTR(L"Default");

			ICompositor* pCompositor = nullptr;
			auto it = m_mapCompositor.find((HWND)h);
			if (it == m_mapCompositor.end())
			{
				TCHAR szBuffer[MAX_PATH];
				::GetWindowText((HWND)h, szBuffer, MAX_PATH);
				CString strText = szBuffer;
				if (strText == _T(""))
				{
					CString s = _T("");
					s.Format(_T("Frame_%p"), h);
					strText = s;
				}
				CreateCompositor(CComVariant(0), CComVariant((long)h), CComBSTR(strText), &pCompositor);
				return pCompositor->Open(bstrKey, bstrXml, ppRetNode);
			}
			else
			{
				return it->second->Open(bstrKey, bstrXml, ppRetNode);
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::ConnectTangramCtrl(ITangramCtrl* eventSource)
{
	if (g_pTangram->m_bEclipse)
	{
		if (eventSource != nullptr)
		{
			CEclipseCtrl* pCtrl = (CEclipseCtrl*)eventSource;
			HWND hCtrl = pCtrl->m_hWnd;
			auto it = m_mapNotifyCtrl.find(hCtrl);
			if (it == m_mapNotifyCtrl.end())
				m_mapNotifyCtrl[hCtrl] = pCtrl;
		}
	}
	return S_OK;
}

HRESULT CCompositorManager::Fire_CompositorManagerLoaded(IDispatch* sender, BSTR url)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[2];
		avarParams[1] = sender;
		avarParams[1].vt = VT_DISPATCH;
		avarParams[0] = url;
		avarParams[0].vt = VT_BSTR;

		DISPPARAMS params = { avarParams, NULL, 2, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_CompositorManagerLoaded(sender, url);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnCompositorManagerLoaded(sender, OLE2T(url));
	}
	return hr;
}

HRESULT CCompositorManager::Fire_NodeCreated(IWndNode * pNodeCreated)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[1];
		avarParams[0] = pNodeCreated;
		avarParams[0].vt = VT_DISPATCH;

		DISPPARAMS params = { avarParams, NULL, 1, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_NodeCreated(pNodeCreated);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnNodeCreated(pNodeCreated);
	}
	return hr;
}

HRESULT CCompositorManager::Fire_AddInCreated(IWndNode * pRootNode, IDispatch * pAddIn, BSTR bstrID, BSTR bstrAddInXml)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[4];
		avarParams[3] = pRootNode;
		avarParams[3].vt = VT_DISPATCH;
		avarParams[2] = pAddIn;
		avarParams[2].vt = VT_DISPATCH;
		avarParams[1] = bstrID;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = bstrAddInXml;
		avarParams[0].vt = VT_BSTR;

		DISPPARAMS params = { avarParams, NULL, 4, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_AddInCreated(pRootNode, pAddIn, bstrID, bstrAddInXml);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnAddInCreated(pRootNode, pAddIn, OLE2T(bstrID), OLE2T(bstrAddInXml));
	}
	return hr;
}

HRESULT CCompositorManager::Fire_BeforeOpenXml(BSTR bstrXml, LONGLONG hWnd)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{		
		CComVariant avarParams[2];
		avarParams[1] = bstrXml;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = hWnd;
		avarParams[0].vt = VT_I8;

		DISPPARAMS params = { avarParams, NULL, 2, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(4, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}
	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_BeforeOpenXml(bstrXml, hWnd);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnBeforeOpenXml(OLE2T(bstrXml), (HWND)hWnd);
	}
	return hr;
}

HRESULT CCompositorManager::Fire_OpenXmlComplete(BSTR bstrXml, LONGLONG hWnd, IWndNode * pRetRootNode)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[3];
		avarParams[2] = bstrXml;
		avarParams[2].vt = VT_BSTR;
		avarParams[1] = hWnd;
		avarParams[1].vt = VT_I8;
		avarParams[0] = pRetRootNode;
		avarParams[0].vt = VT_DISPATCH;

		DISPPARAMS params = { avarParams, NULL, 3, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(5, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_OpenXmlComplete(bstrXml, hWnd, pRetRootNode);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnOpenXmlComplete(OLE2T(bstrXml), (HWND)hWnd, pRetRootNode);
	}
	return hr;
}

HRESULT CCompositorManager::Fire_Destroy()
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		DISPPARAMS params = { NULL, NULL, 0, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(6, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_Destroy();
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnDestroy();
	}
	return hr;
}

HRESULT CCompositorManager::Fire_NodeMouseActivate(IWndNode * pActiveNode)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[1];
		avarParams[0] = pActiveNode;
		avarParams[0].vt = VT_DISPATCH;
		DISPPARAMS params = { avarParams, NULL, 1, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(7, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			map<HWND, CEclipseCtrl*>::iterator it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_NodeMouseActivate(pActiveNode);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnNodeMouseActivate(pActiveNode);
	}
	return hr;
}

HRESULT CCompositorManager::Fire_ClrControlCreated(IWndNode * Node, IDispatch * Ctrl, BSTR CtrlName, LONGLONG CtrlHandle)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[4];
		avarParams[3] = Node;
		avarParams[3].vt = VT_DISPATCH;
		avarParams[2] = Ctrl;
		avarParams[2].vt = VT_DISPATCH;
		avarParams[1] = CtrlName;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = CtrlHandle;
		avarParams[0].vt = VT_I8;
		DISPPARAMS params = { avarParams, NULL, 4, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(8, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_ClrControlCreated(Node, Ctrl, CtrlName, CtrlHandle);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnClrControlCreated(Node, Ctrl, OLE2T(CtrlName), (HWND)CtrlHandle);
	}
	return hr;
}

HRESULT CCompositorManager::Fire_IPCMsg(ICompositor* pSender, BSTR bstrType, BSTR bstrContent, BSTR bstrFeature)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[4];
		avarParams[3] = pSender;
		avarParams[3].vt = VT_DISPATCH;
		avarParams[2] = bstrType;
		avarParams[2].vt = VT_BSTR;
		avarParams[1] = bstrContent;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = bstrFeature;
		avarParams[0].vt = VT_BSTR;
		DISPPARAMS params = { avarParams, NULL, 4, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(13, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	return hr;
}

HRESULT CCompositorManager::Fire_TabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[3];
		avarParams[2] = sender;
		avarParams[2].vt = VT_DISPATCH;
		avarParams[1] = ActivePage;
		avarParams[1].vt = VT_I4;
		avarParams[0] = OldPage;
		avarParams[0].vt = VT_I4;
		DISPPARAMS params = { avarParams, NULL, 3, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(9, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	if (g_pTangram->m_bEclipse)
	{
		int nSize = m_mapNotifyCtrl.size();
		if (nSize)
		{
			auto it = m_mapNotifyCtrl.begin();
			map<HWND, CEclipseCtrl*> m_mapTemp;
			for (it = m_mapNotifyCtrl.begin(); it != m_mapNotifyCtrl.end(); it++)
			{
				CEclipseCtrl* pCtrl = it->second;
				if (::IsWindow(it->first))
				{
					it->second->Fire_TabChange(sender, ActivePage, OldPage);
				}
				else
				{
					m_mapTemp[it->first] = it->second;
				}
			}
			nSize = m_mapTemp.size();
			if (nSize)
			{
				for (it = m_mapTemp.begin(); it != m_mapTemp.end(); it++)
				{
					auto it2 = m_mapNotifyCtrl.find(it->first);
					if (it2 != m_mapNotifyCtrl.end())
						m_mapNotifyCtrl.erase(it2);
				}
				m_mapTemp.clear();
			}
		}
	}
	for (auto it : m_mapCompositorManagerProxy)
	{
		it.second->OnTabChange(sender, ActivePage, OldPage);
	}
	return hr;
}

HRESULT CCompositorManager::Fire_TangramEvent(ITangramEventObj* pEventObj)
{
	CTangramEventObj* pEvent = (CTangramEventObj*)pEventObj;
	m_mapEventObj[(__int64)pEvent] = pEvent;
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[1];
		avarParams[0] = pEventObj;
		avarParams[0].vt = VT_DISPATCH;
		DISPPARAMS params = { avarParams, NULL, 1, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(12, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}
	return hr;
}

STDMETHODIMP CCompositorManager::get_NewVersion(VARIANT_BOOL* bNewVersion)
{
	*bNewVersion = m_bNewVersion;
	return S_OK;
}

STDMETHODIMP CCompositorManager::put_NewVersion(VARIANT_BOOL bNewVersion)
{
	m_bNewVersion = bNewVersion;
	return S_OK;
}


STDMETHODIMP CCompositorManager::get_CompositorManagerXML(BSTR* pVal)
{
	CString strData = m_strXmlHeader;
	if (strData == _T(""))
		strData = _T("<tangramdefaultpage>");
	CString strIndex = _T("@");
	for (auto it : m_mapCompositor)
	{
		CComBSTR bstrXml(L"");
		strIndex += it.second->m_strCompositorName;
		strIndex += _T("@");
		it.second->get_CompositorXML(&bstrXml);
		strData += OLE2T(bstrXml);
	}
	map<CString, CString> m_mapTemp;
	for (auto it : m_strMapKey)
	{
		CString strKey = it.first;
		int nPos = strKey.Find(_T("@"));
		if (nPos != -1)
		{
			strKey = strKey.Mid(nPos);
			nPos = strKey.ReverseFind('@');
			if (nPos != -1)
			{
				strKey = strKey.Left(nPos + 1);
				if (strIndex.Find(strKey) == -1)
				{
					strKey.Replace(_T("@"), _T(""));
					auto it2 = m_mapTemp.find(strKey);
					if (strKey != _T(""))
					{
						if (it2 == m_mapTemp.end())
						{
							m_mapTemp[strKey] = it.second;
						}
						else
						{
							m_mapTemp[strKey] = it2->second+it.second;
						}
					}
				}
			}
		}
	}
	for (auto it : m_mapTemp)
	{
		CString strXml = _T("");
		strXml.Format(_T("<%s>%s</%s>"), it.first, it.second, it.first);
		strData += strXml;
	}
	if (m_strXmlBottom != _T(""))
		strData += m_strXmlBottom;
	else
		strData += _T("</tangramdefaultpage>");
	*pVal = CComBSTR(strData);
	return S_OK;
}

STDMETHODIMP CCompositorManager::put_ConfigName(BSTR newVal)
{
	m_strConfigFileNodeName = OLE2T(newVal);
	m_strConfigFileNodeName.Trim();
	m_strConfigFileNodeName.MakeLower();
	if (m_strConfigFileNodeName == _T(""))
		m_strConfigFileNodeName = _T("default");
	if (m_strConfigFileNodeName.Find(_T(" ")))
		m_strConfigFileNodeName.Replace(_T(" "), _T("_"));

	if (m_strPageFileName == _T("")&&::GetParent(m_hWnd)==nullptr)
	{
		m_strPageFileName = g_pTangram->m_strExeName;
		m_strPageFilePath = g_pTangram->m_strConfigDataFile;
	}
	
	if (::PathFileExists(m_strPageFilePath))
	{
		CTangramXmlParse m_Parse2;
		if (m_Parse2.LoadFile(m_strPageFilePath))
		{
			CTangramXmlParse* m_pTangramPageParse = m_Parse2.GetChild(_T("tangrampage"));
			if (m_pTangramPageParse == nullptr)
			{
				m_Parse2.AddNode(_T("tangrampage"));
				m_pTangramPageParse = m_Parse2.GetChild(_T("tangrampage"));
			}
			if (m_pTangramPageParse)
			{
				CTangramXmlParse* m_pTangramPageParse2 = m_pTangramPageParse->GetChild(m_strConfigFileNodeName);
				if (m_pTangramPageParse2 == nullptr)
				{
					if(m_pTangramPageParse->AddNode(m_strConfigFileNodeName)!=nullptr)
						m_Parse2.SaveFile(m_strPageFilePath);
				}
				if (m_pTangramPageParse2)
				{
					int nCount = m_pTangramPageParse2->GetCount();
					for (int i = 0; i < nCount; i++)
					{
						CTangramXmlParse* _pParse = m_pTangramPageParse2->GetChild(i);
						CString _str = _T("@") + _pParse->name() + _T("@") + m_strConfigFileNodeName;
						int nCount2 = _pParse->GetCount();
						for (int i = 0; i < nCount2; i++)
						{
							CTangramXmlParse* _pParse2 = _pParse->GetChild(i);
							m_strMapKey[_pParse2->name() + _str] = _pParse2->xml();
						}
					}
				}
			}
		}
	}
	else
	{
		if (::PathIsDirectory(g_pTangram->m_strAppDataPath) == false)
		{
			if (::SHCreateDirectoryEx(NULL, g_pTangram->m_strAppDataPath, NULL))
				return S_FALSE;
		}
		CString strXml = _T("");
		strXml.Format(_T("<%s><tangrampage><%s /></tangrampage></%s>"), m_strPageFileName, m_strConfigFileNodeName, m_strPageFileName);
		CTangramXmlParse m_Parse2;
		m_Parse2.LoadXml(strXml);
		m_Parse2.SaveFile(m_strPageFilePath);
	}
	return S_OK;
}

STDMETHODIMP CCompositorManager::CreateCompositorWithDefaultNode(ULONGLONG hFrameWnd, BSTR bstrFrameName, BSTR bstrDefaultNodeKey, BSTR bstrXml, VARIANT_BOOL bSaveToConfig, IWndNode** ppNode)
{
	CString strXml = OLE2T(bstrXml);
	strXml.Trim();
	if (strXml == _T(""))
		strXml = _T("<default><window><node name=\"Start\" /></window></default>");
	ICompositor* pCompositor = nullptr;
	CreateCompositor(CComVariant(0), CComVariant((LONGLONG)hFrameWnd), bstrFrameName, &pCompositor);
	if (pCompositor)
	{
		if (m_pTangramDocTemplate)
			((CCompositor*)pCompositor)->m_pTangramDocTemplate = m_pTangramDocTemplate;
		pCompositor->Open(bstrDefaultNodeKey, strXml.AllocSysString(), ppNode);
		if (*ppNode&&bSaveToConfig)
		{
			(*ppNode)->put_SaveToConfigFile(true);
			//CCompositor* pFrame2 = (CCompositor*)::SendMessage(((CCompositor*)pCompositor)->m_hWnd, WM_TANGRAMDATA, 0, 1992);
			//if (pCompositor)
			//{
			//	pFrame2->m_nCompositorType = EclipseWorkBenchCompositor;
			//	//pCompositor->m_pWorkBenchFrame = this;
			//}
		}
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::OpenCompositors(BSTR bstrFrames, BSTR bstrKey, BSTR bstrXml, VARIANT_BOOL bSaveToConfigFile)
{
	CString strFrames = OLE2T(bstrFrames);
	CString strKey = OLE2T(bstrKey);
	CString strXml = OLE2T(bstrXml);
	if (strFrames == _T(""))
	{
		for (auto it : m_mapCompositor)
		{
			if (it.second != m_pBKFrame)
			{
				IWndNode* pNode = nullptr;
				it.second->Open(bstrKey, bstrXml, &pNode);
				if (pNode&&bSaveToConfigFile)
					pNode->put_SaveToConfigFile(true);
			}
		}
	}
	else
	{
		strFrames = _T(",") + strFrames;
		for (auto it : m_mapCompositor)
		{
			CString strName = _T(",") + it.second->m_strCompositorName + _T(",");
			if (strFrames.Find(strName) != -1)
			{
				IWndNode* pNode = nullptr;
				it.second->Open(bstrKey, bstrXml, &pNode);
				if (pNode&&bSaveToConfigFile)
					pNode->put_SaveToConfigFile(true);
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CCompositorManager::get_CurrentDesignCompositorType(CompositorType* pVal)
{
	if (g_pTangram->m_pDesignWindowNode)
	{
		CCompositor* pCompositor = g_pTangram->m_pDesignWindowNode->m_pTangramNodeCommonData->m_pCompositor;
		*pVal = pCompositor->m_nCompositorType;
	}
	else
		*pVal = NOCompositor;

	return S_OK;
}

STDMETHODIMP CCompositorManager::get_CurrentDesignNode(IWndNode** pVal)
{
	if (g_pTangram->m_pDesignWindowNode)
		*pVal = g_pTangram->m_pDesignWindowNode;

	return S_OK;
}

void CCompositorManager::DispatchToOtherBrokers(CString strChannel, CString strData)
{
	// TODO
}