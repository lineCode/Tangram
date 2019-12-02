/********************************************************************************
 *					Tangram Library - version 10.0.0
 **
 *********************************************************************************
 * Copyright (C) 2002-2019 by Tangram Team.   All Rights Reserved.
 **
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

#include "../stdafx.h"
#include "../TangramApp.h"
#include "../WndNode.h"
#include "../Compositor.h"
#include "../NodeWnd.h"
#include "HtmlWnd.h"
#include "BrowserWnd.h"
#include "../Markup.h" 

namespace ChromePlus {
	CHtmlWnd::CHtmlWnd() {
		m_pWebWnd = nullptr;
		m_pDevToolWnd = nullptr;
		m_pDoc = nullptr;
		m_pAppProxy = nullptr;
		m_bDevToolWnd = false;
		m_strCurKey = _T("");
		m_strCurXml = _T("");
		//m_strFormXml = _T("");
		m_strAppProxyID = _T("");
		m_pCompositorManager = nullptr;
		m_pCompositor = nullptr;
		m_hHostWnd=m_hExtendWnd = m_hChildWnd = NULL;
		m_pChromeRenderFrameHost = g_pTangram->m_pCreatingChromeRenderFrameHostBase;
		g_pTangram->m_pCreatingChromeRenderFrameHostBase = nullptr;
	}

	CHtmlWnd::~CHtmlWnd() {
		for (auto it : m_mapChildFormsInfo)
		{
			delete it.second;
		}
	}

	LRESULT CHtmlWnd::OnMouseActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		CBrowserWnd* pParent = nullptr;
		auto it = g_pTangram->m_mapBrowserWnd.find(::GetParent(m_hWnd));
		if (it != g_pTangram->m_mapBrowserWnd.end())
		{
			pParent = (ChromePlus::CBrowserWnd*)it->second;
		}
		HWND hPWnd = ::GetParent(pParent->m_hWnd);
		if (hPWnd != NULL)
		{
			g_pTangram->m_pActiveHtmlWnd = this;
			g_pTangram->m_pCompositor = nullptr;
			g_pTangram->m_bWinFormActived = false;
			LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
			::PostMessage(m_hWnd, WM_TANGRAMMSG, 20190331, 0);
			return lRes;
		}
		else
			g_pTangram->m_pActiveHtmlWnd = nullptr;
		return DefWindowProc(uMsg, wParam, lParam);
	}

	LRESULT CHtmlWnd::OnTangramMsg(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL&) {
		bool bChild = ::GetWindowLongPtr(::GetParent(m_hWnd), GWL_STYLE)&WS_CHILD;
		switch (wParam)
		{
		case 19820911:
			{
				Show(_T(""));
			}
			break;
		case 20190115:
		{
			auto it = g_pTangram->m_mapBrowserWnd.find(::GetParent(m_hWnd));
			if (it != g_pTangram->m_mapBrowserWnd.end())
			{
				CBrowserWnd* pParent = (ChromePlus::CBrowserWnd*)it->second;

				if (/*!bChild&&*/m_hExtendWnd == nullptr)
				{
					m_hExtendWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, ::GetParent(m_hWnd), NULL, theApp.m_hInstance, NULL);
					m_hChildWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, m_hExtendWnd, (HMENU)1, theApp.m_hInstance, NULL);
					//m_hChildWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, m_hExtendWnd, (HMENU)AFX_IDW_PANE_FIRST, theApp.m_hInstance, NULL);

					::SetWindowLongPtr(m_hExtendWnd, GWLP_USERDATA, (LONG_PTR)m_hChildWnd);
					::SetWindowLongPtr(m_hChildWnd, GWLP_USERDATA, (LONG_PTR)this);
				}
			}
			if (g_pTangram->m_mapCreatingWorkBenchInfo.size())
			{
				::PostAppMessage(::GetCurrentThreadId(), WM_TANGRAMMSG, 0, 20191114);
				//DWORD id = ::GetCurrentThreadId();
				//auto t = create_task([id, this]
				//	{
				//		SleepEx(500, true);
				//		try
				//		{
				//			::PostAppMessage(id, WM_TANGRAMMSG, 0, 20191114);
				//		}
				//		catch (...)
				//		{
				//		}
				//		return 1;
				//	});
			}
		}
			break;
		case 20190407:
			{
				TangramCommon::IPCMsg* pIPCInfo = (TangramCommon::IPCMsg*)lParam;
				if (pIPCInfo && pIPCInfo->m_strType == _T("eclipse"))
				{
					g_pTangram->CreateEclipseApp(pIPCInfo->m_strKey, pIPCInfo->m_strData);
				}
				if (pIPCInfo && pIPCInfo->m_strType == _T("atlmfc"))
				{
					ITangramAppProxy* pProxy = nullptr;
					CString appid = pIPCInfo->m_strKey;
					auto it2 = g_pTangram->m_mapTangramAppProxy.find(appid);
					if (it2 == g_pTangram->m_mapTangramAppProxy.end())
					{

					}
					else
					{
						pProxy = it2->second;
					}
					g_pTangram->m_pActiveMDIChildWnd = nullptr;
					CMarkup xml;
					if (xml.SetDoc(pIPCInfo->m_strData))
					{
						g_pTangram->m_strCurrentFrameID = xml.GetChildAttrib(L"mainframeid");// "apptitle"m_Parse.attr(_T("mainframeid"), _T("default"));
						if (g_pTangram->m_strCurrentFrameID == _T(""))
							g_pTangram->m_strCurrentFrameID = _T("default");
						CString strAppTitle = xml.GetChildAttrib(L"apptitle");
						g_pTangram->m_strCurrentFrameID.MakeLower();
						g_pTangram->m_strCurrentDocTemplateXml = xml.GetSubDoc();
						pProxy->m_strCreatingFrameTitle = strAppTitle;
						auto it3 = g_pTangram->m_mapTemplateInfo.find(_T(".tangramdoc"));
						if (it3 != g_pTangram->m_mapTemplateInfo.end())
						{
							pProxy->CreateNewDocument(g_pTangram->m_strCurrentFrameID, strAppTitle, it3->second, false);
							g_pTangram->m_bNewFile = FALSE;
						}
					}
				}
				delete pIPCInfo;
				return 0;
			}
			break;
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CHtmlWnd::OnParentChanged(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL&) {
		if (lParam) {
			HWND hNewPWnd = (HWND)lParam;
			::GetClassName(hNewPWnd, g_pTangram->m_szBuffer, 256);
			CString strName = CString(g_pTangram->m_szBuffer);
			if (strName == _T("Tangram_WidgetWin_0"))
			{
				if (m_hExtendWnd)
				{
					::SetParent(m_hExtendWnd, m_hWnd);
					::ShowWindow(m_hExtendWnd, SW_HIDE);
				}
				HWND hNewPWnd2 = ::GetParent(m_hWnd);
				bool bNewParent = false;
				if (hNewPWnd != hNewPWnd2)
				{
					hNewPWnd = hNewPWnd2;
					bNewParent = true;
				}
				ChromePlus::CBrowserWnd* pChromeBrowserWnd = nullptr;
				auto it = g_pTangram->m_mapBrowserWnd.find(hNewPWnd);
				if (it == g_pTangram->m_mapBrowserWnd.end())
				{
					if (::IsWindowVisible(hNewPWnd)) { 
						pChromeBrowserWnd = new CComObject<ChromePlus::CBrowserWnd>();
						pChromeBrowserWnd->SubclassWindow(hNewPWnd);
						g_pTangram->m_mapBrowserWnd[hNewPWnd] = pChromeBrowserWnd;
						pChromeBrowserWnd->m_pBrowser = g_pTangram->m_pActiveBrowser;
						g_pTangram->m_pActiveBrowser = pChromeBrowserWnd->m_pBrowser;
						if (pChromeBrowserWnd->m_pBrowser)
							pChromeBrowserWnd->m_pBrowser->m_pProxy = pChromeBrowserWnd;
						if (pChromeBrowserWnd && m_hExtendWnd) {
							::SetParent(m_hExtendWnd,hNewPWnd);
							if (::IsWindowVisible(m_hWnd)) {
								pChromeBrowserWnd->m_pVisibleWebWnd = this;
								if (bNewParent)
								{
									g_pTangram->m_pActiveBrowser = pChromeBrowserWnd->m_pBrowser;
									g_pTangram->m_pActiveBrowser->m_pProxy = pChromeBrowserWnd;
								}
							}
						}
					}
				}
			}
			else
			{
				if (m_hExtendWnd)
				{
					::SetParent(m_hExtendWnd, hNewPWnd);
					::ShowWindow(m_hExtendWnd, SW_SHOW);
				}
				HWND hNewPWnd2 = ::GetParent(m_hWnd);
				bool bNewParent = false;
				if (hNewPWnd != hNewPWnd2)
				{
					hNewPWnd = hNewPWnd2;
					bNewParent = true;
				}
				ChromePlus::CBrowserWnd* pChromeBrowserWnd = nullptr;
				auto it = g_pTangram->m_mapBrowserWnd.find(hNewPWnd);
				if (it != g_pTangram->m_mapBrowserWnd.end())
				{
					pChromeBrowserWnd = (ChromePlus::CBrowserWnd*)it->second;
					g_pTangram->m_pActiveBrowser = pChromeBrowserWnd->m_pBrowser;
					if (pChromeBrowserWnd && m_hExtendWnd) {
						if (::IsWindowVisible(m_hWnd)) {
							pChromeBrowserWnd->m_pVisibleWebWnd = this;
							if (bNewParent)
							{
								g_pTangram->m_pActiveBrowser = pChromeBrowserWnd->m_pBrowser;
								g_pTangram->m_pActiveBrowser->m_pProxy = pChromeBrowserWnd;
							}
						}
					}
				}
				else
				{
					if (::IsWindowVisible(hNewPWnd)) { 
						pChromeBrowserWnd = new CComObject<ChromePlus::CBrowserWnd>();
						pChromeBrowserWnd->SubclassWindow(hNewPWnd);
						g_pTangram->m_mapBrowserWnd[hNewPWnd] = pChromeBrowserWnd;
						pChromeBrowserWnd->m_pBrowser = g_pTangram->m_pActiveBrowser;
						g_pTangram->m_pActiveBrowser = pChromeBrowserWnd->m_pBrowser;
						if (pChromeBrowserWnd->m_pBrowser)
							pChromeBrowserWnd->m_pBrowser->m_pProxy = pChromeBrowserWnd;
						if (pChromeBrowserWnd && m_hExtendWnd) {
							::SetParent(m_hExtendWnd,hNewPWnd);
							if (::IsWindowVisible(m_hWnd)) {
								pChromeBrowserWnd->m_pVisibleWebWnd = this;
								if (bNewParent)
								{
									g_pTangram->m_pActiveBrowser = pChromeBrowserWnd->m_pBrowser;
									g_pTangram->m_pActiveBrowser->m_pProxy = pChromeBrowserWnd;
								}
							}
						}
					}
				}
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CHtmlWnd::OnDestroy(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL& /*bHandled*/) {
		if (m_hExtendWnd)
		{
			if (g_pTangram->m_bChromeNeedClosed==false&&m_pCompositor)
			{
				IWndNode* pNode = nullptr;
				m_pCompositor->Open(CComBSTR(_T("__default__key__for__chrome__")), CComBSTR(g_pTangram->m_strDefaultXml), &pNode);
			}
			::DestroyWindow(m_hExtendWnd);
		}

		m_hExtendWnd = nullptr;

		if (m_bDevToolWnd) {
			if (m_pWebWnd) {
				m_pWebWnd->m_pDevToolWnd = nullptr;
				::PostMessage(::GetParent(m_pWebWnd->m_hWnd), WM_BROWSERLAYOUT, 0, 1);
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CHtmlWnd::OnShowWindow(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL&) {
		if (::IsWindow(m_hExtendWnd))
		{
			if (wParam) {
				HWND hPWnd = ::GetParent(m_hWnd);
				if (!m_bDevToolWnd)
				{
					auto it = g_pTangram->m_mapBrowserWnd.find(hPWnd);
					if (it != g_pTangram->m_mapBrowserWnd.end()) {
						((ChromePlus::CBrowserWnd*)it->second)->m_pVisibleWebWnd = this;
					}
				}
				::ShowWindow(m_hExtendWnd, SW_SHOW);
				::SetParent(m_hExtendWnd, hPWnd);
				//::SendMessage(hPWnd, WM_BROWSERLAYOUT, 0, 2);
			}
			else
			{
				::ShowWindow(m_hExtendWnd, SW_HIDE);
				::SetParent(m_hExtendWnd, m_hWnd);
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	void CHtmlWnd::OnFinalMessage(HWND hWnd) {
		CBrowserWnd* pPWnd = nullptr;
		auto it2 = g_pTangram->m_mapBrowserWnd.find(::GetParent(hWnd));
		if (it2 != g_pTangram->m_mapBrowserWnd.end())
		{
			pPWnd = (CBrowserWnd*)it2->second;
			if (pPWnd->m_pVisibleWebWnd == this)
				pPWnd->m_pVisibleWebWnd = nullptr;
		}
		auto it = g_pTangram->m_mapHtmlWnd.find(hWnd);
		if (it != g_pTangram->m_mapHtmlWnd.end())
		{
			g_pTangram->m_mapHtmlWnd.erase(it);
		}
		if (g_pTangram->m_pActiveHtmlWnd == this)
			g_pTangram->m_pActiveHtmlWnd = nullptr;
		CWindowImpl::OnFinalMessage(hWnd);
		delete this;
	}

	void CHtmlWnd::Show(CString strID2)
	{
		if (m_pDoc)
			return;
		LONG_PTR data = 0;
		if (::IsWindow(m_hChildWnd))
			data = ::GetWindowLongPtr(m_hChildWnd, GWLP_USERDATA);

		if (data == 0 && g_pTangram->m_pTangramAppProxy)
		{
			if (::IsChild(m_hExtendWnd, m_hChildWnd))
			{
				m_strAppProxyID = _T("");
				auto it = g_pTangram->m_mapWindowPage.find(m_hExtendWnd);
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
						m_pAppProxy->m_hCreatingView = m_hChildWnd;
						::SetWindowText(m_hChildWnd, g_pTangram->m_strAppKey);
						//::SetWindowLongPtr(m_hChildWnd, GWLP_USERDATA, (LONG_PTR)1);
						m_pDoc = (CTangramDoc*)m_pAppProxy->NewDoc();
						if (m_pDoc)
						{
							auto it = m_pCompositorManager->m_mapCompositor.find(m_hChildWnd);
							if (it != m_pCompositorManager->m_mapCompositor.end())
								m_pCompositor = it->second;
						}
					}
				}
				else
				{
					ICompositor* pCompositor = nullptr;
					m_pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)m_hChildWnd), CComBSTR(L"default"), &pCompositor);
					if (pCompositor)
					{
						m_pCompositor = (CCompositor*)pCompositor;
						m_pCompositorManager->m_mapNeedSaveCompositor[m_hChildWnd] = m_pCompositor;
						IWndNode* pNode = nullptr;
						pCompositor->Open(CComBSTR("default"), CComBSTR(L""), &pNode);
					}
				}
			}
		}
	}

	IPC::Broker* CHtmlWnd::GetBroker()
	{
		return (IPC::Broker*)m_pCompositor;
	}

	void CHtmlWnd::OnIPCMessageReceived(CString strChannel, CString strData)
	{
		SendChromeIPCMessage(L"USER_LEVEL_MESSAGE", strChannel, strData);
	}

	void CHtmlWnd::SendChromeIPCMessage(CString strType, CString strParam1, CString strParam2)
	{
		if (m_pChromeRenderFrameHost != nullptr)
		{
			TangramCommon::IPCMsg pIPCInfo;
			pIPCInfo.m_strType = strType;
			pIPCInfo.m_strKey = strParam1;
			pIPCInfo.m_strData = strParam2;
			m_pChromeRenderFrameHost->SendTangramMessage(&pIPCInfo);
		}
	}

	void CHtmlWnd::OnChromeIPCMessageReceived(std::wstring strType, std::wstring strParam1, std::wstring strParam2)
	{
		// TODO: Not work
	}

	LRESULT CHtmlWnd::OnChromeIPCMsgReceived(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if (lParam)
		{
			TangramCommon::IPCMsg* pIPCInfo = (TangramCommon::IPCMsg*)lParam;
			CString strData = pIPCInfo->m_strData;
			CString strType = pIPCInfo->m_strType;
			CString strKey = pIPCInfo->m_strKey;
			HandleChromeIPCMessage(strType, strKey, strData);
		}

		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	CChromeBrowserBase* CHtmlWnd::GetChromeBrowserBase(HWND hHostWnd)
	{
		return nullptr;
	}

	void CHtmlWnd::LoadDocument2Viewport(CString strName, CString strXML)
	{
		if (/*!bChild&&*/m_hExtendWnd == nullptr)
		{
			m_hExtendWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, ::GetParent(m_hWnd), NULL, theApp.m_hInstance, NULL);
			m_hChildWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, m_hExtendWnd, (HMENU)1, theApp.m_hInstance, NULL);
			//m_hChildWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, m_hExtendWnd, (HMENU)AFX_IDW_PANE_FIRST, theApp.m_hInstance, NULL);

			::SetWindowLongPtr(m_hExtendWnd, GWLP_USERDATA, (LONG_PTR)m_hChildWnd);
			::SetWindowLongPtr(m_hChildWnd, GWLP_USERDATA, (LONG_PTR)this);
		}
		if (m_hExtendWnd)
		{
			if (m_pCompositor == nullptr) {
				CCompositorManager* pCompositorManager = nullptr;
				auto it = g_pTangram->m_mapWindowPage.find(m_hExtendWnd);
				if (it != g_pTangram->m_mapWindowPage.end())
					pCompositorManager = (CCompositorManager*)it->second;
				else
				{
					pCompositorManager = new CComObject<CCompositorManager>();
					pCompositorManager->m_hWnd = m_hExtendWnd;
					g_pTangram->m_mapWindowPage[m_hExtendWnd] = pCompositorManager;

					for (auto it : g_pTangram->m_mapTangramAppProxy)
					{
						CCompositorManagerProxy* pTangramProxy = it.second->OnCompositorManagerCreated(pCompositorManager);
						if (pTangramProxy)
							pCompositorManager->m_mapCompositorManagerProxy[it.second] = pTangramProxy;
					}
				}
				if (pCompositorManager) {
					ICompositor* pCompositor = nullptr;
					pCompositorManager->CreateCompositor(CComVariant((__int64)0), CComVariant((__int64)m_hChildWnd), CComBSTR("default"), &pCompositor);
					if (pCompositor)
					{
						m_pCompositor = (CCompositor*)pCompositor;
						m_pCompositor->m_pWebWnd = this;
					}
				}
			}
			if (m_pCompositor)
			{
				strName.MakeLower();
				IWndNode* pNode = nullptr;
				m_pCompositor->Open(CComBSTR(strName), CComBSTR(strXML), &pNode);
				if (pNode)
				{
					m_strCurKey = strName;
					m_hHostWnd = NULL;
					if (m_pCompositor->m_pBindingNode)
						m_hHostWnd = m_pCompositor->m_pBindingNode->m_pHostWnd->m_hWnd;

					::PostMessage(::GetParent(m_hWnd), WM_BROWSERLAYOUT, 0, 2);
				}
			}
		}
	}

	void CHtmlWnd::HandleChromeIPCMessage(CString strType, CString strParam1, CString strParam2)
	{
		if (strType.CompareNoCase(_T("USER_LEVEL_ADD_CHANNEL")) == 0)
		{
			AddChannelInternal(strParam1);
		}
		else if (strType.CompareNoCase(_T("USER_LEVEL_REMOVE_CHANNEL")) == 0)
		{
			// TODO: RemoveChannelInternal
		}
		else if (strType.CompareNoCase(_T("USER_LEVEL_MESSAGE")) == 0)
		{
			SendIPCMessageInternal(strParam1, strParam2);
		}
		else if (strType.CompareNoCase(_T("RENDER_ELEMENT")) == 0)
		{
			RenderHTMLElement(strParam1, strParam2);
		}
		else if (strType.CompareNoCase(_T("BUNDLE_MESSAGE")) == 0)
		{
			HandleBundledMessage(strParam1, strParam2);
		}
		else if (strType.CompareNoCase(_T("LOAD_DOCUMENT_TO_VIEWPORT")) == 0)
		{
			LoadDocument2Viewport(strParam1, strParam2);
		}
		else if (strType.CompareNoCase(_T("NTP_LOAD")) == 0)
		{
			OnNTPLoaded();
		}
		else
		{
			g_pTangram->m_pTangramDelegate->TangramIPCMsg(m_hWnd, strType, strParam1, strParam2);
		}
	}

	void CHtmlWnd::HandleBundledMessage(CString strParam1, CString strParam2)
	{
		int nTokenPos = 0;
		CString strToken = strParam1.Tokenize(_T("$$$"), nTokenPos);
		while (!strToken.IsEmpty())
		{
			// Process a single message.
			HandleSingleMessage(strToken);
			strToken = strParam1.Tokenize(_T("$$$"), nTokenPos);
		}
	}

	void CHtmlWnd::HandleSingleMessage(CString strParam)
	{
		int nTokenPos = 0;
		CString strType = strParam.Tokenize(_T("%%%"), nTokenPos);
		CString strParam1 = strParam.Tokenize(_T("%%%"), nTokenPos);
		CString strParam2 = strParam.Tokenize(_T("%%%"), nTokenPos);
		HandleChromeIPCMessage(strType, strParam1, strParam2);
	}

	void CHtmlWnd::RenderHTMLElement(CString strRuleName, CString strHTML)
	{
		if (strRuleName.CompareNoCase(_T("object")) == 0)
		{
			RenderHTMLObjectElement(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("data")) == 0)
		{
			RenderHTMLDataElement(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("doc")) == 0)
		{
			RenderHTMLDocElement(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("extra")) == 0)
		{
			RenderHTMLExtraElement(strHTML);
		}
		else 
		{
			g_pTangram->m_pTangramDelegate->TangramRenderHTMLElement(m_hWnd, strRuleName, strHTML);
		}
	}

	void CHtmlWnd::RenderHTMLObjectElement(CString strHTML)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strHTML))
		{
			CString strType = m_Parse.attr(_T("type"),_T(""));
			if (strType.CompareNoCase(_T("winform")) == 0)
			{
				CString strStartup = _T("");
				CTangramXmlParse* pChild3 = m_Parse.GetChild(_T("mdichild"));
				CString strID = m_Parse.attr(_T("formkey"), _T(""));
				CString strName = m_Parse.name();
				if (strID != _T(""))
				{
					m_mapFormsInfo[strID] = m_Parse.xml();
				}
				if (m_Parse.attrBool(_T("showstartup")))
				{
					strStartup = strID;
				}
				if (pChild3)
				{
					CTangramXmlParse* pChild4 = m_Parse.GetChild(_T("mdiclient"));
					int nCount = pChild3->GetCount();
					if (nCount && pChild4)
					{
						CMDIChildFormInfo* pInfo = new CMDIChildFormInfo();
						g_pTangram->m_pCurMDIChildFormInfo = pInfo;
						m_mapChildFormsInfo[strID] = pInfo;
						for (int i = 0; i < nCount; i++)
						{
							CString strName = pChild3->GetChild(i)->name();
							if (pChild4->GetChild(strName))
								pInfo->m_mapFormsInfo[strName] = pChild3->GetChild(i)->xml();
						}
					}
				}
				if (strStartup != _T(""))
				{
					CString strID = strStartup;
					if (g_pTangram->m_pCLRProxy == nullptr)
						g_pTangram->LoadCLR();
					if (g_pTangram->m_pCLRProxy)
					{
						auto it = m_mapFormsInfo.find(strID);
						if (it != m_mapFormsInfo.end())
						{
							auto it2 = m_mapChildFormsInfo.find(strID);
							if (it2 != m_mapChildFormsInfo.end())
								g_pTangram->m_pCurMDIChildFormInfo = it2->second;
							IDispatch * pDisp = g_pTangram->m_pCLRProxy->CreateCLRObj(it->second);
						}
					}
				}
			}
			if (strType.CompareNoCase(_T("workbench")) == 0)
			{
				bool bSkip = false;
				if (::IsChild(g_pTangram->m_hHostBrowserWnd, m_hWnd))
				{
					if (g_pTangram->m_nAppType != TANGRAM_APP_ECLIPSE && g_pTangram->m_nAppType != TANGRAM_APP_BROWSER_ECLIPSE)
					{
						bSkip = true;
					}
				}
				if (bSkip == false)
				{
					CString strStartup = _T("");
					CString strID = m_Parse.attr(_T("workbenchkey"), _T(""));
					CString strName = m_Parse.name();
					if (strID != _T(""))
					{
						g_pTangram->m_mapCreatingWorkBenchInfo[strID] = m_mapWorkBenchInfo[strID] = m_Parse.xml();
					}
					if (m_Parse.attrBool(_T("showstartup")))
					{
						strStartup = strID;
					}
					if (strStartup != _T(""))
					{
						CString strID = strStartup;
						g_pTangram->m_strWorkBenchStrs = strID;
						g_pTangram->m_strWorkBenchStrs += _T("|");
						g_pTangram->m_nAppType = TANGRAM_APP_BROWSER_ECLIPSE;
					}
				}
			}
			else if (strType.CompareNoCase(_T("browser")) == 0)
			{
				CString strUrls = _T("");
				int nCount = m_Parse.GetCount();
				for (int i = 0; i < nCount; i++)
				{
					CString strUrl = m_Parse.GetChild(i)->text(); 
					strUrls = strUrls + strUrl + _T("|");
				}
				g_pTangram->m_pBrowserFactory->CreateBrowser(NULL, strUrls);
			}
		}
	}

	void CHtmlWnd::RenderHTMLExtraElement(CString strHTML)
	{
		CMarkup rootXML;
		if (rootXML.SetDoc(strHTML) && rootXML.FindElem())
		{
			CString strTarget = rootXML.GetAttrib(_T("target"));
			if (strTarget.CompareNoCase(_T("ntp")) == 0)
			{
				g_pTangram->m_strNtpXml = strHTML;
			}
			else if (strTarget.CompareNoCase(_T("node")) == 0)
			{
				CString strNodeName = rootXML.GetAttrib(_T("name"));
				if (strNodeName != _T(""))
				{
					m_mapUserControlsInfo[strNodeName] = strHTML;
				}
			}
		}
	}

	void CHtmlWnd::RenderHTMLDataElement(CString strHTML)
	{
		CMarkup rootXML;
		if (rootXML.SetDoc(strHTML) && rootXML.FindElem())
		{
			CString strKey = rootXML.GetAttrib(_T("key"));
			g_pTangram->m_mapValInfo[strKey] = CComVariant(strHTML);
		}
	}

	void CHtmlWnd::RenderHTMLDocElement(CString strHTML)
	{
		CMarkup rootXML;
		if (rootXML.SetDoc(strHTML) && rootXML.FindElem())
		{
			CString strName = rootXML.GetAttrib(_T("name"));
			if (strName == _T(""))
			{
				strName = _T("__VIEWPORT_DEFAULT__");
			}
			LoadDocument2Viewport(strName, strHTML);
		}
	}

	void CHtmlWnd::OnNTPLoaded()
	{
		if (g_pTangram->m_strNtpXml != _T(""))
		{
			LoadDocument2Viewport(_T("__NTP_DEFAULT__"), g_pTangram->m_strNtpXml);
		}
	}

}  // namespace ChromePlus




