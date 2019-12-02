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
* OUTLINED IN THE TANGRAM LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
********************************************************************************/
//https://github.com/eclipse/rt.equinox.framework/tree/master/features/org.eclipse.equinox.executable.feature

#include "../stdafx.h"
#include "../TangramApp.h"
#include "../WndNode.h"
#include "../Compositor.h"
#include "../TangramCtrl.h"
#include "../SplitterWnd.h"
#include "EclipseAddin.h"

#include "atlcom.h"

extern jstring newJavaString(JNIEnv *env, _TCHAR * str);

CEclipseExtender::CEclipseExtender()
{
}

CEclipseExtender::~CEclipseExtender()
{
}

STDMETHODIMP CEclipseExtender::Close()
{
	delete this;
	return S_OK;
}

STDMETHODIMP CEclipseExtender::get_ActiveWorkBenchWindow(BSTR bstrID, IWorkBenchWindow** pVal)
{
	CString strID = OLE2T(bstrID);
	strID.Trim();
	if (strID==_T(""))
	{
		if (g_pTangram->m_pActiveEclipseWnd)
		{
			*pVal = (IWorkBenchWindow*)g_pTangram->m_pActiveEclipseWnd;
			(*pVal)->AddRef();
		}
	}
	else
	{
		ITangram* pTangram = nullptr;
		g_pTangram->get_RemoteTangram(bstrID, &pTangram);
		if (pTangram)
		{
			IWorkBenchWindow* pRet = nullptr;
			ITangramExtender* pExtender = nullptr;
			pTangram->get_Extender(&pExtender);
			if (pExtender)
			{
				CComQIPtr<IEclipseExtender> pEclipse(pExtender);
				if(pEclipse)
					pEclipse->get_ActiveWorkBenchWindow(bstrID, &pRet);
				if (pRet)
				{
					*pVal = pRet;
					(*pVal)->AddRef();
				}
			}
		}
	}

	return S_OK;
}

CEclipseWnd::CEclipseWnd(void)
{
	m_bInit = false;
	m_pDoc = nullptr;
	m_pCompositor = nullptr;
	m_pCurNode = nullptr;
	m_pHostNode = nullptr;
	m_strXml = _T("");
	m_strPath = _T("");
	m_strAppProxyID = _T("");
	m_strNodeName = _T("");
	m_strDocKey = _T("");
	m_strFrameID = _T("");
	m_pAppProxy = nullptr;
	m_pCompositorManager = nullptr;
	g_pTangram->m_pActiveEclipseWnd = this;
}

CEclipseWnd::~CEclipseWnd(void) 
{
	if (m_pCompositorManager)
	{
		HWND hWnd = m_pCompositorManager->m_hWnd;
		auto it = g_pTangram->m_mapWindowPage.find(hWnd);
		if (it != g_pTangram->m_mapWindowPage.end())
		delete m_pCompositorManager;
	}
	ATLTRACE(_T("delete CEclipseWnd:%x\n"), this);
}

void CEclipseWnd::OnFinalMessage(HWND hWnd)
{
	auto it = g_pTangram->m_mapWorkBenchWnd.find(hWnd);
	if (it != g_pTangram->m_mapWorkBenchWnd.end())
		g_pTangram->m_mapWorkBenchWnd.erase(it);
	if (g_pTangram->m_pCLRProxy)
	{
		g_pTangram->m_pCLRProxy->ReleaseTangramObj((IWorkBenchWindow*)this);
	}
	CWindowImpl::OnFinalMessage(hWnd);
	delete this;
}

void CEclipseWnd::CreatePage(BOOL bSaveToConfigFile)
{
	if (m_pCompositorManager == nullptr)
	{
		ICompositorManager* pCompositorManager = nullptr;
		g_pTangram->CreateCompositorManager((LONGLONG)m_hWnd, &pCompositorManager);
		if (pCompositorManager == nullptr)
			return;
		m_pCompositorManager = (CCompositorManager*)pCompositorManager;
		HMENU hMenu = ::GetMenu(m_hWnd);
		if (hMenu)
		{
			MENUITEMINFO mii;
			mii.fMask = MIIM_STRING;
			mii.cbSize = sizeof(MENUITEMINFO);
			int nCount = ::GetMenuItemCount(hMenu);
			for (int i = nCount - 1; i >0; i--)
			{
				mii.cch = 256;
				mii.fType = MFT_STRING;
				mii.dwTypeData = g_pTangram->m_szBuffer;
				GetMenuItemInfo(hMenu, i, true, &mii);
				CString str = mii.dwTypeData;
				if (str == _T("&Window"))
				{
					HMENU hSubMenu = ::GetSubMenu(hMenu, i);
					int nCount = ::GetMenuItemCount(hSubMenu);
					for (int i = 0; i<nCount; i++)
					{
						mii.fMask = MIIM_STRING | MIIM_ID;
						mii.cch = 256;
						mii.dwTypeData = g_pTangram->m_szBuffer;
						GetMenuItemInfo(hSubMenu, i, true, &mii);
						str = mii.dwTypeData;
						if (str == _T("&New Window"))
						{
							m_nNewWinCmdID = mii.wID;
							break;
						}
					}
					break;
				}
			}
		}
		if (::IsWindowVisible(m_hWnd))
		{
			m_strDocKey = g_pTangram->m_strCurrentEclipsePagePath;
			g_pTangram->m_strCurrentEclipsePagePath = _T("");
			Show(m_strDocKey);
			auto it2 = g_pTangram->m_mapValInfo.find(_T("newmdtframe"));
			if (it2 != g_pTangram->m_mapValInfo.end())
			{
				m_strFrameID = OLE2T(it2->second.bstrVal);
				g_pTangram->m_mapValInfo.erase(it2);
			}
		}
	}
}

STDMETHODIMP CEclipseWnd::get_Count(long* pCount)
{
	*pCount = (long)m_mapCtrl.size();
	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_Ctrl(VARIANT vIndex, IEclipseCtrl **ppCtrl)
{
	if (vIndex.vt == VT_I4)
	{
		long lCount = m_mapCtrl.size();
		int iIndex = vIndex.lVal;
		if (iIndex < 0 || iIndex >= lCount) return E_INVALIDARG;

		auto it = m_mapCtrl.begin();
		int iPos = 0;
		while (it != m_mapCtrl.end())
		{
			if (iPos == iIndex) break;
			iPos++;
			it++;
		}

		*ppCtrl = it->second;
		return S_OK;
	}

	return S_OK;
}

STDMETHODIMP CEclipseWnd::CloseTangramUI()
{
	if (m_pCompositor)
	{
		HWND _hWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), L"", WS_CHILD, 0, 0, 0, 0, g_pTangram->m_hHostWnd, NULL, AfxGetInstanceHandle(), NULL);
		HWND _hChildWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), L"", WS_CHILD, 0, 0, 0, 0, (HWND)_hWnd, NULL, AfxGetInstanceHandle(), NULL);
		if (::IsWindow(m_hWnd))
		{
			m_pCompositor->ModifyHost((LONGLONG)_hChildWnd);
			::DestroyWindow(_hWnd);
		}
		m_pCompositor = nullptr;
		delete m_pCompositorManager;
		m_pCompositorManager = nullptr;
	}

	return S_OK;
}

STDMETHODIMP CEclipseWnd::get__NewEnum(IUnknown** ppVal)
{
	typedef CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT>>
		CComEnumVariant;

	CComObject<CComEnumVariant> *pe = 0;
	HRESULT hr = pe->CreateInstance(&pe);

	if (SUCCEEDED(hr))
	{
		pe->AddRef();
		long nLen = (long)m_mapCtrl.size();
		VARIANT* rgvar = new VARIANT[nLen];
		ZeroMemory(rgvar, sizeof(VARIANT)*nLen);
		VARIANT* pItem = rgvar;
		for (auto it : m_mapCtrl)
		{
			IUnknown* pDisp = nullptr;
			CEclipseCtrl* pObj = it.second;
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

STDMETHODIMP CEclipseWnd::get_Handle(LONGLONG* pVal)
{
	*pVal = (LONGLONG)m_hClient;
	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_CompositorManager(ICompositorManager** pVal)
{
	if (m_pCompositorManager)
		*pVal = m_pCompositorManager;

	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_Compositor(ICompositor** pVal)
{
	if (m_pCompositor)
		*pVal = m_pCompositor;
	return S_OK;
}

STDMETHODIMP CEclipseWnd::Open(BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode)
{
	CString strKey = OLE2T(bstrKey);
	strKey.Trim();
	HRESULT hr = S_FALSE;
	if (m_hClient == NULL)
		return S_FALSE;
	if (m_pCompositorManager == nullptr)
	{
		ICompositorManager* pCompositorManager = nullptr;
		g_pTangram->CreateCompositorManager((LONGLONG)m_hWnd, &pCompositorManager);
		if (pCompositorManager == nullptr)
			return S_FALSE;
		m_pCompositorManager = (CCompositorManager*)pCompositorManager;
		if (m_pCompositor == nullptr)
		{
			ICompositor* pCompositor = nullptr;
			m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)m_hClient), CComBSTR(L"default"), &pCompositor);
			if (pCompositor == nullptr)
			{
				delete m_pCompositorManager;
				m_pCompositorManager = nullptr;
			}
			m_pCompositor = (CCompositor*)pCompositor;
		}
	}
	else
	{
		m_pCompositor = (CCompositor*)::SendMessage(m_hClient, WM_TANGRAMDATA, 0, 1992);
		if (m_pCompositor == nullptr)
		{
			auto it = m_pCompositorManager->m_mapCompositor.find(m_hClient);
			if (it != m_pCompositorManager->m_mapCompositor.end())
				m_pCompositor = it->second;
			else
			{
				ICompositor* pCompositor = nullptr;
				m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)m_hClient), CComBSTR(L"default"), &pCompositor);
				if (pCompositor == nullptr)
				{
					delete m_pCompositorManager;
					m_pCompositorManager = nullptr;
				}
				m_pCompositor = (CCompositor*)pCompositor;
			}
		}
	}
	if (m_pCompositor)
	{
		hr = m_pCompositor->Open(bstrKey, bstrXml, ppNode);
		if (*ppNode)
		{
			m_pCurNode = (CWndNode*)*ppNode;
		}
	}
	return hr;
} 

STDMETHODIMP CEclipseWnd::OpenEx(BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode)
{
	HRESULT hr = Open(bstrKey, bstrXml, ppNode);
	if (*ppNode)
	{
		m_pCurNode = (CWndNode*)*ppNode;
		m_pCurNode->put_SaveToConfigFile(true);
	}
	return hr;
} 

STDMETHODIMP CEclipseWnd::OpenInView(int nIndex, BSTR bstrKey, BSTR bstrXml, IWndNode** ppRetNode)
{
	IEclipseCtrl* pCtrl = nullptr;
	get_Ctrl(CComVariant((int)nIndex), &pCtrl);
	if (pCtrl)
	{
		IWndNode* pNode = nullptr;
		return pCtrl->Open(CComBSTR(L"EclipseView"), bstrKey, bstrXml, ppRetNode);
	}

	return S_OK;
}

STDMETHODIMP CEclipseWnd::Active()
{
	SetFocus();

	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_TangramCtrl(LONGLONG hWnd, IEclipseCtrl** pVal)
{
	auto it = m_mapCtrl.find((HWND)hWnd);
	if (it != m_mapCtrl.end())
	{
		*pVal = it->second;
		(*pVal)->AddRef();
	}
	return S_OK;
}

void CEclipseWnd::Show(CString strID)
{
	if (m_pDoc)
		return;
	LONG_PTR data = 0;
	if(::IsWindow(m_hClient))
		data = ::GetWindowLongPtr(m_hClient, GWLP_USERDATA);
	if (g_pTangram->m_bIsEclipseInit == false)
		g_pTangram->m_bIsEclipseInit = true;
	if (data==0&&g_pTangram->m_pTangramAppProxy)
	{
		m_strPath = strID;
		if (::IsChild(m_hWnd, m_hClient))
		{
			m_strAppProxyID = _T("");
			auto it = g_pTangram->m_mapWindowPage.find(m_hWnd);
			if (it != g_pTangram->m_mapWindowPage.end())
				m_pCompositorManager = (CCompositorManager*)it->second;
			else
			{
				m_pCompositorManager = new CComObject<CCompositorManager>();
				m_pCompositorManager->m_hWnd = m_hWnd;
				g_pTangram->m_mapWindowPage[m_hWnd] = m_pCompositorManager;

				for (auto it : g_pTangram->m_mapTangramAppProxy)
				{
					CCompositorManagerProxy* pTangramProxy = it.second->OnCompositorManagerCreated(m_pCompositorManager);
					if (pTangramProxy)
						m_pCompositorManager->m_mapCompositorManagerProxy[it.second] = pTangramProxy;
				}
			}

			if (m_strPath == _T("")||::PathFileExists(m_strPath)==false)
			{
				auto it = g_pTangram->m_mapCreatingWorkBenchInfo.find(strID);
				if (it != g_pTangram->m_mapCreatingWorkBenchInfo.end())
				{
					m_strDocKey = m_strXml = it->second;
					g_pTangram->m_mapCreatingWorkBenchInfo.erase(it);
				}
				else
					m_strDocKey = m_strXml = m_strPath = g_pTangram->m_strAppDataPath + _T("default.workbench");
			}
			else
			{
				m_strDocKey = m_strXml = m_strPath;
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadFile(m_strDocKey))
				{
					m_strAppProxyID = m_Parse.attr(_T("styleproxyid"), _T(""));
				}
			}
			if (m_strAppProxyID != _T(""))
			{
				m_pAppProxy = nullptr;
				auto it = g_pTangram->m_mapTangramAppProxy.find(m_strAppProxyID.MakeLower());
				if (it != g_pTangram->m_mapTangramAppProxy.end())
					m_pAppProxy = it->second;
				else
				{
					CString strPath = g_pTangram->m_strAppPath;
					HMODULE hHandle = nullptr;
					CString strAppName = _T("");
					int nPos = m_strAppProxyID.Find(_T("."));
					if (nPos != -1)
						strAppName = m_strAppProxyID.Left(nPos);
					CString strdll = strPath + m_strAppProxyID + _T("\\") + strAppName + _T(".dll");
					if (::PathFileExists(strdll))
						hHandle = ::LoadLibrary(strdll);
					if (hHandle == nullptr)
					{
						strdll = g_pTangram->m_strAppCommonDocPath2 + m_strAppProxyID + _T("\\") + strAppName + _T(".dll");
						if (::PathFileExists(strdll))
							hHandle = ::LoadLibrary(strdll);
					}
					if (hHandle)
					{
						it = g_pTangram->m_mapTangramAppProxy.find(m_strAppProxyID.MakeLower());
						if (it != g_pTangram->m_mapTangramAppProxy.end())
						{
							m_pAppProxy = it->second;
						}
					}
				}
				if (m_pAppProxy)
				{
					g_pTangram->m_pActiveAppProxy = m_pAppProxy;
					m_pAppProxy->m_hCreatingView = m_hClient;
					::SetWindowText(m_hClient, g_pTangram->m_strAppKey);
					::SetWindowLongPtr(m_hClient, GWLP_USERDATA, (LONG_PTR)1);
					m_pDoc = (CTangramDoc*)m_pAppProxy->NewDoc();
					if (m_pDoc)
					{
						auto it = m_pCompositorManager->m_mapCompositor.find(m_hClient);
						if (it != m_pCompositorManager->m_mapCompositor.end())
							m_pCompositor = it->second;
					}
				}
			}
			else if(strID !=_T(""))
			{
				ICompositor* pCompositor = nullptr;
				m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)m_hClient), CComBSTR(L"default"), &pCompositor);
				if (pCompositor)
				{
					m_pCompositor = (CCompositor*)pCompositor;
					m_pCompositorManager->m_mapNeedSaveCompositor[m_hClient] = m_pCompositor;
					CString strKey = _T("default");
					if (m_strDocKey == _T(""))
					{
						m_strDocKey = m_strXml = m_strPath = g_pTangram->m_strAppDataPath + _T("default.workbench");
					}
					else
					{
						strKey = strID;
						if (g_pTangram->m_nAppType == TANGRAM_APP_ECLIPSE)
							m_strDocKey = g_pTangram->m_strStartupURL;
					}
					IWndNode* pNode = nullptr;
					pCompositor->Open(CComBSTR(strKey), CComBSTR(m_strDocKey), &pNode);
					if (pNode == nullptr)
					{
						delete m_pCompositor;
						m_pCompositor = nullptr;
						m_pCompositorManager = nullptr;
					}
				}
			}
		}
	}
}

LRESULT CEclipseWnd::OnShowWindow(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	if (m_pDoc == nullptr)
	{
		if (g_pTangram->m_strWorkBenchStrs != _T(""))
		{
			int nPos = g_pTangram->m_strWorkBenchStrs.Find(_T("|"));
			m_strDocKey = g_pTangram->m_strWorkBenchStrs.Left(nPos);
			g_pTangram->m_strWorkBenchStrs = g_pTangram->m_strWorkBenchStrs.Mid(nPos + 1);
		}

		if (g_pTangram->m_strCurrentEclipsePagePath != _T(""))
		{
			m_strDocKey = g_pTangram->m_strCurrentEclipsePagePath;
			g_pTangram->m_strCurrentEclipsePagePath = _T("");
		}
		if (::IsWindow(m_hClient)/*&& m_strDocKey!=_T("")*/)
		{
			Show(m_strDocKey);
		}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	if (wParam == m_nNewWinCmdID)
	{
		if (g_pTangram->m_strCurrentEclipsePagePath == _T(""))
		{
			CComBSTR bstrTemplate(L"");
			g_pTangram->GetDocTemplateXml(CComBSTR("Please select New Eclipse Window Bench Template:"), CComBSTR(g_pTangram->m_strAppDataPath+_T("workbench\\")), _T(".eclipse"), &bstrTemplate);
			g_pTangram->m_strCurrentEclipsePagePath = OLE2T(bstrTemplate);
		}
		if (g_pTangram->m_strCurrentEclipsePagePath == _T("")&& m_pCompositor)
		{
			IWndNode* pNode = nullptr;
			m_pCompositor->Open(CComBSTR(L"newdocument"), g_pTangram->m_strNewDocXml.AllocSysString(), &pNode);
			if (pNode)
				return 0;
		}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnTangramGetXml(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	CString strFrameName = (LPCTSTR)wParam;
	CString currentKey = (LPCTSTR)lParam;
	CString strIndex = strFrameName + L"_" + currentKey;
	CTangramXmlParse parse;
	if (parse.LoadXml(m_strXml) || parse.LoadFile(m_strXml))
	{
		CTangramXmlParse* pParse = parse.GetChild(strFrameName);
		if (pParse)
		{
			CTangramXmlParse* pParse2 = pParse->GetChild(currentKey);
			if (pParse2)
			{
				auto it = g_pTangram->m_mapValInfo.find(strIndex);
				if (it != g_pTangram->m_mapValInfo.end())
				{
					g_pTangram->m_mapValInfo.erase(it);
				}
				g_pTangram->m_mapValInfo[strIndex] = CComVariant(pParse2->xml());
				return 1;
			}
		}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnTangramMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	switch (wParam)
	{
	case 1963:
		{
			return ::SendMessage(::GetParent(m_hClient), WM_QUERYAPPPROXY, wParam, 0);
		}
		break;
	case 20190305:
		{
			return (LRESULT)this;
		}
		break;
	case 19820911:
		{
			if (lParam == 0)
			{
				::PostMessage(m_hWnd, WM_TANGRAMMSG, 19820911, 1);
			}
			if (lParam == 1)
			{
				CCompositor* pCompositor = (CCompositor*)::SendMessage(m_hClient, WM_TANGRAMDATA, 0, 1992);
				if (pCompositor)
				{
					pCompositor->m_nCompositorType = EclipseWorkBenchCompositor;
					pCompositor->m_pWorkBenchFrame = this;
				}
				else
				{
					if (m_pDoc == nullptr)
					{
						if (g_pTangram->m_strWorkBenchStrs != _T(""))
						{
							int nPos = g_pTangram->m_strWorkBenchStrs.Find(_T("|"));
							m_strDocKey = g_pTangram->m_strWorkBenchStrs.Left(nPos);
							g_pTangram->m_strWorkBenchStrs = g_pTangram->m_strWorkBenchStrs.Mid(nPos + 1);
						}
						if (g_pTangram->m_strCurrentEclipsePagePath != _T(""))
						{
							m_strDocKey = g_pTangram->m_strCurrentEclipsePagePath;
							g_pTangram->m_strCurrentEclipsePagePath = _T("");
						}
						LONG_PTR data = 0;
						if (::IsWindow(m_hClient)/*&& m_strDocKey!=_T("")*/)
						{
							data = ::GetWindowLongPtr(m_hClient, GWLP_USERDATA);
							if (data == 0)
							{
								Show(m_strDocKey);
								break;
							}
						}
					}
				}
			}
		}
		break;
	}

	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	m_strPath = g_pTangram->m_strAppDataPath + _T("default.workbench");
	if (m_strPath != _T(""))
	{
		LRESULT lRes = ::SendMessage(::GetParent(m_hClient),WM_QUERYAPPPROXY,0,19631222);
		if (lRes == 0)
		{
			CTangramXmlParse m_Parse;
			if (m_pCompositorManager)
			{
				m_strXml = _T("<eclipseplus>");
				for (auto it : m_pCompositorManager->m_mapCompositor)
				{
					CCompositor* pCompositor = it.second;
					for (auto it2 : pCompositor->m_mapNode)
					{
						CWndNode* pWindowNode = (CWndNode*)it2.second;
						if (pWindowNode)
						{
							if (pWindowNode->m_pTangramWindow)
							{
								if (pWindowNode->m_nActivePage > 0)
								{
									CString strVal = _T("");
									strVal.Format(_T("%d"), pWindowNode->m_nActivePage);
									pWindowNode->m_pHostParse->put_attr(_T("activepage"), strVal);
								}
								pWindowNode->m_pTangramWindow->Save();
							}
							if (pWindowNode->m_nViewType == Splitter)
							{
								((CSplitterNodeWnd*)pWindowNode->m_pHostWnd)->Save();
							}
							g_pTangram->UpdateWndNode(pWindowNode);
							for (auto it2 : pWindowNode->m_vChildNodes)
							{
								g_pTangram->UpdateWndNode(it2);
							}
						}
					}
				}
				for (auto it : m_pCompositorManager->m_mapNeedSaveCompositor)
				{
					CCompositor* pCompositor = it.second;
					auto it2 = pCompositor->m_mapNode.find(_T("default"));
					if (it2 != pCompositor->m_mapNode.end())
					{
						CWndNode* _pNode = (CWndNode*)it2->second;
						if (pCompositor->m_strCompositorName.Find(_T("@")) == -1)
						{
							CString strXml = _pNode->m_pTangramNodeCommonData->m_pTangramParse->xml();
							strXml.Replace(_T("/><"), _T("/>\r\n<"));
							strXml.Replace(_T("/>"), _T("></node>"));
							CString s = _T("");
							s.Format(_T("<%s>%s</%s>"), pCompositor->m_strCompositorName, strXml, pCompositor->m_strCompositorName);
							m_strXml += s;
						}
					}
				}
				m_strXml += _T("</eclipseplus>");
			}
			bool bSave = false;
			if (m_Parse.LoadXml(m_strXml))
			{
				if (m_pAppProxy)
				{
					m_Parse.put_attr(_T("styleproxyid"), m_strAppProxyID);
				}
				bSave = m_Parse.SaveFile(m_strPath);
			}
		}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	CTangramXmlParse xmlParse;
	if (xmlParse.LoadFile(g_pTangram->m_strConfigDataFile))
	{
		CTangramXmlParse* pParse = xmlParse.GetChild(_T("openedworkbench"));
		if (pParse == nullptr)
		{
			pParse = xmlParse.AddNode(_T("openedworkbench"));
		}
		if (pParse)
		{
			CString strWorkBenchStrs = m_strDocKey + _T("|");
			strWorkBenchStrs += pParse->text();
			pParse->put_text(strWorkBenchStrs);
			xmlParse.SaveFile(g_pTangram->m_strConfigDataFile);
		}
	}
	if (g_pTangram->m_pActiveEclipseWnd == this)
		g_pTangram->m_pActiveEclipseWnd = nullptr;
	auto it = g_pTangram->m_mapWorkBenchWnd.find(m_hWnd);
	if (it != g_pTangram->m_mapWorkBenchWnd.end())
	{
		g_pTangram->m_mapWorkBenchWnd.erase(it);
		//if (g_pTangram->m_mapWorkBenchWnd.size()==0)
		//{
		//	if(::IsWindow(g_pTangram->m_hHostWnd))
		//		::DestroyWindow(g_pTangram->m_hHostWnd);
		//}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	if (g_pTangram->m_mapWorkBenchWnd.size() == 0)
	{
		if (::GetModuleHandle(L"chrome_elf.dll"))
		{
			if (g_pTangram)
			{
				if (g_pTangram->m_mapBrowserWnd.size())
				{
					g_pTangram->m_bChromeNeedClosed = true;
					auto it = g_pTangram->m_mapBrowserWnd.begin();
					((ChromePlus::CBrowserWnd*)it->second)->SendMessageW(WM_CLOSE, 0, 0);
				}
			}
		}
		if (::IsWindow(g_pTangram->m_hHostWnd))
			::DestroyWindow(g_pTangram->m_hHostWnd);
	}
	return lRes;
}

LRESULT CEclipseWnd::OnActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	if (LOWORD(wParam) != WA_INACTIVE)
	{
		g_pTangram->m_pActiveEclipseWnd = this;
		g_pTangram->m_pActiveAppProxy = m_pAppProxy;
	}
	return lRes;
}

LRESULT CEclipseWnd::OnQueryAppProxy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	LRESULT lRes = ::SendMessage(::GetParent(m_hClient), uMsg, wParam, 19631992);
	if (lRes)
	{
		if (m_pAppProxy==nullptr)
			m_pAppProxy = (ITangramAppProxy*)lRes;

		return lRes;
	}
	
	lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

CEclipseCtrl::CEclipseCtrl()
{
	m_varTag.vt = VT_BSTR;
	m_varTag.bstrVal = ::SysAllocString(L"");
	m_hEclipseViewWnd = NULL;
	m_pCurNode = nullptr;
	m_pEclipseWnd = nullptr;
	m_pCompositorManagerProxy = nullptr;
}

STDMETHODIMP CEclipseCtrl::get_AppKeyValue(BSTR bstrKey, VARIANT* pVal)
{
	if (g_pTangram)
	{
		return g_pTangram->get_AppKeyValue(bstrKey, pVal);
	}
	return S_FALSE;
}

STDMETHODIMP CEclipseCtrl::put_AppKeyValue(BSTR bstrKey, VARIANT newVal)
{
	if (g_pTangram)
	{
		return g_pTangram->put_AppKeyValue(bstrKey, newVal);
	}

	return S_OK;
}

STDMETHODIMP CEclipseCtrl::get_tag(VARIANT* pVal)
{
	*pVal = m_varTag;
	return S_OK;
}

STDMETHODIMP CEclipseCtrl::put_tag(VARIANT newVal)
{
	::VariantClear(&m_varTag);
	m_varTag = newVal;
	return S_OK;
}

HRESULT CEclipseCtrl::Fire_CompositorManagerLoaded(IDispatch* sender, BSTR url)
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
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnCompositorManagerLoaded(sender, OLE2T(url));
	return hr;
}

HRESULT CEclipseCtrl::Fire_NodeCreated(IWndNode * pNodeCreated)
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
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnNodeCreated(pNodeCreated);
	return hr;
}

HRESULT CEclipseCtrl::Fire_AddInCreated(IWndNode * pRootNode, IDispatch * pAddIn, BSTR bstrID, BSTR bstrAddInXml)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[4];
		avarParams[3] = pRootNode;
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
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnAddInCreated(pRootNode, pAddIn, OLE2T(bstrID), OLE2T(bstrAddInXml));
	return hr;
}

HRESULT CEclipseCtrl::Fire_BeforeOpenXml(BSTR bstrXml, LONGLONG hWnd)
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
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnBeforeOpenXml(OLE2T(bstrXml), (HWND)hWnd);
	return hr;
}

HRESULT CEclipseCtrl::Fire_OpenXmlComplete(BSTR bstrXml, LONGLONG hWnd, IWndNode * pRetRootNode)
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
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnOpenXmlComplete(OLE2T(bstrXml), (HWND)hWnd, pRetRootNode);

	return hr;
}

HRESULT CEclipseCtrl::Fire_Destroy()
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
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnDestroy();

	return hr;
}

HRESULT CEclipseCtrl::Fire_NodeMouseActivate(IWndNode * pActiveNode)
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

	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnNodeMouseActivate(pActiveNode);
	return hr;
}

HRESULT CEclipseCtrl::Fire_ClrControlCreated(IWndNode * Node, IDispatch * Ctrl, BSTR CtrlName, LONGLONG CtrlHandle)
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

	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnClrControlCreated(Node, Ctrl, OLE2T(CtrlName), (HWND)CtrlHandle);
	return hr;
}

HRESULT CEclipseCtrl::Fire_TabChange(IWndNode* sender, LONG ActivePage, LONG OldPage)
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

	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnTabChange(sender, ActivePage, OldPage);
	return hr;
}

HRESULT CEclipseCtrl::Fire_Event(IWndNode* sender, IDispatch* EventArg)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[2];
		avarParams[1] = sender;
		avarParams[1].vt = VT_DISPATCH;
		avarParams[0] = EventArg;
		avarParams[0].vt = VT_DISPATCH;
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
				hr = pConnection->Invoke(10, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	return hr;
}

HRESULT CEclipseCtrl::Fire_ControlNotify(IWndNode * sender, LONG NotifyCode, LONG CtrlID, LONGLONG CtrlHandle, BSTR CtrlClassName)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[5];
		avarParams[4] = sender;
		avarParams[4].vt = VT_DISPATCH;
		avarParams[3] = NotifyCode;
		avarParams[3].vt = VT_I4;
		avarParams[2] = CtrlID;
		avarParams[2].vt = VT_I4;
		avarParams[1] = CtrlHandle;
		avarParams[1].vt = VT_I8;
		avarParams[0] = CtrlClassName;
		avarParams[0].vt = VT_BSTR;
		DISPPARAMS params = { avarParams, NULL, 5, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pTangram->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			g_pTangram->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(11, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnControlNotify(sender, NotifyCode, CtrlID, (HWND)CtrlHandle, OLE2T(CtrlClassName));
	return hr;
}

HRESULT CEclipseCtrl::Fire_TangramEvent(ITangramEventObj* pEventObj)
{
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
	if (m_pCompositorManagerProxy)
		m_pCompositorManagerProxy->OnTangramEvent(pEventObj);
	return hr;
}

STDMETHODIMP CEclipseCtrl::InitCtrl(BSTR bstrXml)
{
	CString strXml = OLE2T(bstrXml);
	if (strXml != _T(""))
	{
		CTangramXmlParse m_Parse;
		if (!m_Parse.LoadXml(strXml))
		{
			CString strPath = g_pTangram->m_strAppPath + strXml;
			if (m_Parse.LoadFile(strPath) == false)
				return S_OK;
		}
		int nCount = m_Parse.GetCount();
		CTangramXmlParse* pChild = nullptr;
		for (int i = 0; i < nCount; i++)
		{
			pChild = m_Parse.GetChild(i);
			CString strName = pChild->name();
			strName.MakeLower();
			auto it = m_mapTangramInfo.find(strName);
			if (it == m_mapTangramInfo.end())
			{
				m_mapTangramInfo[strName] = pChild->xml();
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CEclipseCtrl::put_TangramHandle(BSTR bstrHandleName, LONGLONG newVal)
{
	CString strName = OLE2T(bstrHandleName);
	HWND hWnd = (HWND)newVal;
	if (strName != _T("") && ::IsWindow(hWnd))
	{
		auto it = m_mapTangramHandle.find(strName);
		if (it != m_mapTangramHandle.end())
			m_mapTangramHandle.erase(strName);
		m_mapTangramHandle[strName] = hWnd;
	}

	return S_OK;
}

STDMETHODIMP CEclipseCtrl::Open(BSTR bstrFrameName, BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode)
{
	CString strFrameName = OLE2T(bstrFrameName);
	if (strFrameName == _T(""))
		strFrameName = _T("EclipseView");
	if (strFrameName.CompareNoCase(_T("TopView")) == 0)
	{
		return m_pEclipseWnd->Open(bstrKey, bstrXml, ppNode);
	}
	auto it = m_mapTangramHandle.find(strFrameName);
	if (it == m_mapTangramHandle.end())
		return S_FALSE;
	HWND hWnd = it->second;
	CString strKey = OLE2T(bstrKey);
	if (strKey == _T(""))
		strKey= _T("default");
	CString strXml = OLE2T(bstrXml);
	IWndNode* pNode = nullptr;
	auto it2 = m_mapCompositor.find(strFrameName);
	if (it2 == m_mapCompositor.end())
	{
		HWND hTop = ::GetAncestor(m_hWnd, GA_ROOT);
		ICompositorManager* pCompositorManager = nullptr;
		g_pTangram->CreateCompositorManager((LONGLONG)hTop, &pCompositorManager);
		if (pCompositorManager == nullptr)
			return S_OK;
		//m_pCompositorManager = (CCompositorManager*)pCompositorManager;m_pEclipseWnd->m_
		ICompositor* pCompositor = nullptr;
		pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((long)hWnd), bstrFrameName, &pCompositor);
		if (pCompositor == nullptr)
		{
			return S_FALSE;
		}
		m_mapCompositor[strFrameName] = (CCompositor*)pCompositor;
		HRESULT hr = pCompositor->Open(bstrKey, bstrXml, ppNode);
		if (hr == S_OK&&strFrameName.CompareNoCase(_T("EclipseView")) == 0)
		{
			if (strFrameName.CompareNoCase(_T("EclipseView")) == 0)
			{
				((CCompositor*)pCompositor)->m_nCompositorType = EclipseViewCompositor;
			}
			else
				((CCompositor*)pCompositor)->m_nCompositorType = EclipseSWTCompositor;
			(*ppNode)->put_SaveToConfigFile(true);
		}
		return hr;
	}
	HRESULT hr = it2->second->Open(bstrKey, bstrXml, ppNode);
	if(hr==S_OK&&strFrameName.CompareNoCase(_T("EclipseView")) == 0)
		(*ppNode)->put_SaveToConfigFile(true);
	return hr;
}
	
STDMETHODIMP CEclipseCtrl::OpenEx(BSTR bstrFrameName, BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode)
{
	HRESULT hr = Open(bstrFrameName, bstrKey, bstrXml, ppNode);
	if (hr == S_OK&&*ppNode != nullptr)
		(*ppNode)->put_SaveToConfigFile(true);
	return S_OK;
}

void CEclipseCtrl::OnFinalMessage(HWND hWnd)
{
	::VariantClear(&m_varTag);
	if (m_pEclipseWnd)
	{
		auto it = m_pEclipseWnd->m_mapCtrl.find(hWnd);
		if (it != m_pEclipseWnd->m_mapCtrl.end())
			m_pEclipseWnd->m_mapCtrl.erase(it);
	}
	__super::OnFinalMessage(hWnd);
	if (g_pTangram->m_bEclipse)
		Release();
}

STDMETHODIMP CEclipseCtrl::get_EclipseViewHandle(LONGLONG* pVal)
{
	*pVal = (LONGLONG)m_hEclipseViewWnd;
	return S_OK;
}

LRESULT CEclipseCtrl::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	LRESULT lr = DefWindowProc(uMsg, wParam, lParam);
	HWND hTop = ::GetAncestor(m_hWnd, GA_ROOT);
	HWND hClient = ::GetWindow(hTop, GW_CHILD);
	m_mapTangramHandle[_T("TopView")] = hClient;
	m_hEclipseViewWnd = ::GetParent(::GetParent(::GetParent(m_hWnd)));
	m_mapTangramHandle[_T("EclipseView")] = m_hEclipseViewWnd;
	::PostMessage(m_hWnd, WM_TANGRAMMSG, 0, 0);
	return lr;
}

LRESULT CEclipseCtrl::OnTangramMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	LRESULT lr = DefWindowProc(uMsg, wParam, lParam);
	HWND hTop = ::GetAncestor(m_hWnd, GA_ROOT);

	auto it = g_pTangram->m_mapWorkBenchWnd.find(hTop);
	if (it != g_pTangram->m_mapWorkBenchWnd.end())
	{
		m_pEclipseWnd = (CEclipseWnd*)it->second;
		auto it2 = m_pEclipseWnd->m_mapCtrl.find(m_hWnd);
		if (it2 == m_pEclipseWnd->m_mapCtrl.end())
			m_pEclipseWnd->m_mapCtrl[m_hWnd] = this;
		if (m_pEclipseWnd->m_pCompositorManager)
		{
			auto it = m_pEclipseWnd->m_pCompositorManager->m_mapNotifyCtrl.find(m_hWnd);
			if (it == m_pEclipseWnd->m_pCompositorManager->m_mapNotifyCtrl.end())
				m_pEclipseWnd->m_pCompositorManager->m_mapNotifyCtrl[m_hWnd] = this;
		}
	}
	return lr;
}

STDMETHODIMP CEclipseCtrl::get_HWND(LONGLONG* pVal)
{
	*pVal = (LONGLONG)m_hWnd;
	return S_OK;
}

STDMETHODIMP CEclipseCtrl::get_Tangram(ITangram** pVal)
{
	*pVal = g_pTangram;
	return S_OK;
}

STDMETHODIMP CEclipseCtrl::get_CompositorManager(ICompositorManager** pVal)
{
	if (m_pEclipseWnd->m_pCompositorManager)
		*pVal = m_pEclipseWnd->m_pCompositorManager;
	return S_OK;
}

STDMETHODIMP CEclipseCtrl::get_WorkBenchWindow(IWorkBenchWindow** pVal)
{
	if (m_pEclipseWnd)
		*pVal = m_pEclipseWnd;
	return S_OK;
}

STDMETHODIMP CEclipseCtrl::get_TopCompositorManager(ICompositorManager** pVal)
{
	if (m_pEclipseWnd)
	{
		*pVal = m_pEclipseWnd->m_pCompositorManager;
	}

	return S_OK;
}

STDMETHODIMP CEclipseCtrl::get_TopCompositor(ICompositor** pVal)
{
	if (m_pEclipseWnd)
	{
		*pVal = m_pEclipseWnd->m_pCompositor;
	}

	return S_OK;
}

STDMETHODIMP CEclipseCtrl::get_ActiveTopNode(IWndNode** pVal)
{
	if (m_pEclipseWnd)
	{
		*pVal = m_pEclipseWnd->m_pCompositor->m_pWorkNode;
	}

	return S_OK;
}

HRESULT CEclipseCtrl::FinalConstruct()
{
	CString strKey = _T("startdata");
	auto it = g_pTangram->m_mapValInfo.find(strKey);
	if (it != g_pTangram->m_mapValInfo.end())
	{
		CString strData = OLE2T(it->second.bstrVal);
		int nPos = strData.Find(_T("|"));
		if (nPos != -1)
		{
			g_pTangram->m_strStartView = strData.Left(nPos);
			g_pTangram->m_strStartXml = strData.Mid(nPos + 1);
			if (::IsWindow(g_pTangram->m_hHostWnd))
			{
				::PostMessage(g_pTangram->m_hHostWnd, WM_TANGRAMAPPQUIT, 0, 0);
			}
		}
		::VariantClear(&it->second);
		g_pTangram->m_mapValInfo.erase(it);
	}

	return S_OK;
}
