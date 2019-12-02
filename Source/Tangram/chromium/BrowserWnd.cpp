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
#include "BrowserWnd.h"
#include "HtmlWnd.h"

namespace ChromePlus {
	CBrowserWnd::CBrowserWnd() {
		m_hDrawWnd = 0;
		m_pBrowser = nullptr;
		m_fdevice_scale_factor = 1.0f;
		m_strCurKey = _T("");
		m_pVisibleWebWnd = nullptr;
		m_pOmniboxViewViews = nullptr;
		if (g_pTangram->m_pCreatingOmniboxViewViews) {
			m_pOmniboxViewViews = g_pTangram->m_pCreatingOmniboxViewViews;
			g_pTangram->m_pCreatingOmniboxViewViews = nullptr; 
		}
	}

	CBrowserWnd::~CBrowserWnd() {}

	LRESULT CBrowserWnd::BrowserLayout() {
		if (g_pTangram->m_bChromeNeedClosed == TRUE ||
			!::IsWindowVisible(m_hWnd) ||
			(m_pVisibleWebWnd && (!::IsWindow(m_pVisibleWebWnd->m_hWnd) ||
				!::IsWindow(m_pVisibleWebWnd->m_hExtendWnd))))
			return 0;

		if (m_pVisibleWebWnd)
		{
			if (!::IsWindow(m_pVisibleWebWnd->m_hWnd)||!::IsWindowVisible(m_pVisibleWebWnd->m_hWnd))
			{
				if (::IsWindow(m_pVisibleWebWnd->m_hWnd)&&m_pVisibleWebWnd->m_hExtendWnd)
					::SetParent(m_pVisibleWebWnd->m_hExtendWnd, m_pVisibleWebWnd->m_hWnd);
				HWND hWnd = m_pBrowser->GetActiveWebContentWnd();
				if (::IsWindow(hWnd) && m_pBrowser->IsActiveWebContentWnd(hWnd)){
					auto it = g_pTangram->m_mapHtmlWnd.find(hWnd);
					if (it != g_pTangram->m_mapHtmlWnd.end())
					{
						m_pVisibleWebWnd = (CHtmlWnd*)it->second;
						if (m_pVisibleWebWnd->m_hExtendWnd)
							::SetParent(m_pVisibleWebWnd->m_hExtendWnd, m_hWnd);
					}
				}
			}

			if (::IsWindow(m_hDrawWnd) == false) {
				m_hDrawWnd = ::FindWindowEx(m_hWnd, nullptr, _T("Intermediate D3D Window"), nullptr);
			}

			if (::IsWindow(m_hDrawWnd) == false) {
				m_hDrawWnd = ::FindWindowEx(m_hWnd, nullptr, _T("Intermediate Software Window"), nullptr);
			}

			RECT rc;
			if (m_pVisibleWebWnd->m_hExtendWnd) {
				if (m_pVisibleWebWnd->m_pCompositor == nullptr)
				{
					::SetWindowPos(m_pVisibleWebWnd->m_hExtendWnd, m_pVisibleWebWnd->m_hWnd, 0, 0, 0, 0, SWP_SHOWWINDOW);
					GetWindowRect(&rc);

					::ScreenToClient(m_hWnd, (LPPOINT)& rc);
					::ScreenToClient(m_hWnd, ((LPPOINT)& rc) + 1);
					::SetWindowRgn(m_hDrawWnd, ::CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom), true);
					return 0;
				}

				m_pVisibleWebWnd->m_pCompositor->HostPosChanged();

				if (::IsChild(m_hWnd, m_pVisibleWebWnd->m_hExtendWnd) == false) {
					::SetParent(m_pVisibleWebWnd->m_hExtendWnd, m_hWnd);
				}

				if (m_hDrawWnd) {
					if (m_pVisibleWebWnd&&m_pVisibleWebWnd->m_hChildWnd) {
						::GetWindowRect(m_hWnd, &rc);
						::ScreenToClient(m_hWnd, (LPPOINT)& rc);
						::ScreenToClient(m_hWnd, ((LPPOINT)& rc) + 1);

						HRGN hGPUWndRgn = ::CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
						HRGN hTemp = ::CreateRectRgn(0, 0, 0, 0);
						RECT rc2;
						::GetWindowRect(m_pVisibleWebWnd->m_hExtendWnd, &rc2);
						::ScreenToClient(m_hWnd, (LPPOINT)& rc2);
						::ScreenToClient(m_hWnd, ((LPPOINT)& rc2) + 1);
						HRGN hWebExtendWndRgn = ::CreateRectRgn(rc2.left, rc2.top, rc2.right, rc2.bottom);

						RECT rc3;
						CWndNode * _pBindingNode = m_pVisibleWebWnd->m_pCompositor->m_pBindingNode;
						CCompositor * _pCompositor = nullptr;
						if (_pBindingNode && _pBindingNode->m_pHostCompositor)
						{
							_pCompositor = _pBindingNode->m_pHostCompositor;
							while (_pCompositor)
							{
								_pBindingNode = _pCompositor->m_pBindingNode;
								if (_pBindingNode->m_pHostCompositor)
									_pCompositor = _pBindingNode->m_pHostCompositor;
								else
								{
									if (_pCompositor && _pCompositor != m_pVisibleWebWnd->m_pCompositor)
										_pCompositor->HostPosChanged();
									break;
								}
							}
						}

						HWND hChild = m_pVisibleWebWnd->m_hChildWnd;
						if (_pBindingNode){
							hChild = _pBindingNode->m_pHostWnd->m_hWnd;
						}
						::GetWindowRect(hChild, &rc3);
						::ScreenToClient(m_hWnd, (LPPOINT)& rc3);
						::ScreenToClient(m_hWnd, ((LPPOINT)& rc3) + 1);
						bool bClientVisible = ::IsWindowVisible(hChild)?(rc3.right - rc3.left) * (rc3.bottom - rc3.top):false;
						HRGN hTemp2 = ::CreateRectRgn(0, 0, 0, 0);
						if (bClientVisible)
						{
							HRGN hWebExtendWndRgn2 = ::CreateRectRgn(rc3.left, rc3.top, rc3.right, rc3.bottom);
							HRGN hTemp1 = ::CreateRectRgn(0, 0, 0, 0);
							::CombineRgn(hTemp1, hWebExtendWndRgn, hWebExtendWndRgn2, RGN_DIFF);
							::CombineRgn(hTemp2, hGPUWndRgn, hTemp1, RGN_DIFF);
							::DeleteObject(hTemp1);
							::DeleteObject(hWebExtendWndRgn2);
						}
						else
						{
							::CombineRgn(hTemp2, hGPUWndRgn, hWebExtendWndRgn , RGN_DIFF);
						}
						::SetWindowRgn(m_hDrawWnd,hTemp2, false);
						::DeleteObject(hWebExtendWndRgn);
						::DeleteObject(hGPUWndRgn);
					}
					else
					{
						RECT rcWndRng;
						if (m_pVisibleWebWnd->m_pDevToolWnd == nullptr) {
							::GetWindowRect(m_pVisibleWebWnd->m_hWnd, &rcWndRng);
						}
						else  if (m_pVisibleWebWnd) {
							if (::GetParent(m_pVisibleWebWnd->m_hWnd) == ::GetParent(m_pVisibleWebWnd->m_pDevToolWnd->m_hWnd))
								::GetWindowRect(m_pVisibleWebWnd->m_pDevToolWnd->m_hWnd, &rcWndRng);
							else
								::GetWindowRect(m_pVisibleWebWnd->m_hWnd, &rcWndRng);
						}
						ScreenToClient(&rcWndRng);
						::SetWindowRgn(m_hDrawWnd, ::CreateRectRgn(rcWndRng.left, rcWndRng.top,
							rcWndRng.right, rcWndRng.bottom), true);
					}
				}
			}
			else {
				if (m_hDrawWnd) {
					GetWindowRect(&rc);

					::ScreenToClient(m_hDrawWnd, (LPPOINT)& rc);
					::ScreenToClient(m_hDrawWnd, ((LPPOINT)& rc) + 1);
					::SetWindowRgn(m_hDrawWnd, ::CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom), true);
				}
			}
		}

		return 0;
	}

	void CBrowserWnd::ActiveChromeTab(HWND hActive, HWND hOldWnd)
	{
		if (m_pBrowser)
		{
			BrowserLayout();
			m_pBrowser->LayoutBrowser();
		}
	}

	void CBrowserWnd::UpdateContentRect(RECT & rc, int nTopFix) {
		if (g_pTangram->m_bOMNIBOXPOPUPVISIBLE)
			return;
		if (m_pVisibleWebWnd)
		{
			HWND hExtendWnd = m_pVisibleWebWnd->m_hExtendWnd;
			if (::IsWindow(hExtendWnd)){
				::SetWindowPos(hExtendWnd, HWND_BOTTOM, 
					rc.left,
					nTopFix * m_fdevice_scale_factor, 
					rc.right * m_fdevice_scale_factor, 
					(rc.bottom - rc.top) * m_fdevice_scale_factor, 
					SWP_SHOWWINDOW |SWP_NOREDRAW |  SWP_NOACTIVATE);// | SWP_NOSENDCHANGING);
				HWND hHostWnd = m_pVisibleWebWnd->m_hHostWnd;
				if (hHostWnd == NULL)
					hHostWnd = m_pVisibleWebWnd->m_hChildWnd;
				if (::IsWindowVisible(hHostWnd) == false) {
					rc = { 0,0,1,1 };
					BrowserLayout();
					return;
				}
				RECT rc2;
				::GetWindowRect(hHostWnd, &rc2);
				if (::ScreenToClient(hExtendWnd, (LPPOINT)& rc2))
				{
					::ScreenToClient(hExtendWnd, ((LPPOINT)& rc2) + 1);
					RECT rect;
					::GetClientRect(hExtendWnd, &rect);

					rc.left += rc2.left / m_fdevice_scale_factor;
					rc.right -= (rect.right - rc2.right) / m_fdevice_scale_factor;
					if (rc.right <= rc.left){
						rc = { 0,0,1,1 };
						BrowserLayout();
						return;
					}
					rc.top += (rc2.top - rect.top) / m_fdevice_scale_factor;
					rc.bottom -= (rect.bottom - rc2.bottom) / m_fdevice_scale_factor;
					if (rc.bottom <= rc.top)
						rc = { 0,0,1,1 };
				}
				BrowserLayout();
			}
		}
	};

	LRESULT CBrowserWnd::OnActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		if (LOWORD(wParam) != WA_INACTIVE) {
			if (m_pBrowser) {
				if (m_pVisibleWebWnd && m_pVisibleWebWnd->m_hExtendWnd)
				{
					::SetParent(m_pVisibleWebWnd->m_hExtendWnd, m_hWnd);
				}
				g_pTangram->m_pActiveBrowser = m_pBrowser;
				g_pTangram->m_pActiveBrowser->m_pProxy = this;
			}
		}
		return lRes;
	}

	LRESULT CBrowserWnd::OnDeviceScaleFactorChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		m_fdevice_scale_factor = (float)lParam / 100;
		return lRes;
	}

	LRESULT CBrowserWnd::OnMouseActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		if (m_pVisibleWebWnd)
		{
			g_pTangram->m_pActiveHtmlWnd = m_pVisibleWebWnd;
			if (g_pTangram->m_pActiveHtmlWnd && g_pTangram->m_pActiveHtmlWnd->m_pChromeRenderFrameHost)
			{
				g_pTangram->m_pCompositor = nullptr;
				g_pTangram->m_bWinFormActived = false;
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CBrowserWnd::OnChromeTabChange(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		//BrowserLayout();
		m_pBrowser->LayoutBrowser();
		g_pTangram->m_pActiveHtmlWnd = m_pVisibleWebWnd;
		if (m_pVisibleWebWnd && g_pTangram->m_pActiveHtmlWnd->m_pChromeRenderFrameHost)
		{
			g_pTangram->m_pCompositor = nullptr;
			g_pTangram->m_bWinFormActived = false;
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CBrowserWnd::OnTangramMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		HWND hWnd = (HWND)lParam;
		switch (wParam) {
		case 0: {
			g_pTangram->m_pHtmlWndCreated = new CComObject<CHtmlWnd>;
			g_pTangram->m_pHtmlWndCreated->SubclassWindow(hWnd);
			HWND hPWnd = ::GetParent(m_hWnd);
			if (g_pTangram->m_bCreatingDevTool == false)
			{
				g_pTangram->m_pHtmlWndCreated->m_bDevToolWnd = false;
				g_pTangram->m_mapHtmlWnd[hWnd] = g_pTangram->m_pHtmlWndCreated;
				if (m_hWnd != g_pTangram->m_hHostBrowserWnd)
					m_pVisibleWebWnd = g_pTangram->m_pHtmlWndCreated;
			}
			else
			{
				g_pTangram->m_bCreatingDevTool = false;
				g_pTangram->m_pHtmlWndCreated->m_bDevToolWnd = true;
				if (m_pVisibleWebWnd) {
					m_pVisibleWebWnd->m_pDevToolWnd = g_pTangram->m_pHtmlWndCreated;
					g_pTangram->m_pHtmlWndCreated->m_pWebWnd = m_pVisibleWebWnd;
				}
			}
			if (hPWnd)
			{
				g_pTangram->m_pActiveHtmlWnd = g_pTangram->m_pHtmlWndCreated;
				g_pTangram->m_pCompositor = nullptr;
				g_pTangram->m_bWinFormActived = false;
				::PostMessage(hWnd, WM_TANGRAMMSG, 20190331, 0);
				::PostMessage(hPWnd, WM_BROWSERLAYOUT, 0, 1);
			}
		} break;
		break;
		case 20190527:
			return (LRESULT)((IChromeWebBrowser*)this);
			break;
		case 20190629:
		{
			switch (lParam)
			{
			case 1:
				return m_pVisibleWebWnd && ::IsWindow(m_pVisibleWebWnd->m_hExtendWnd);
				break;
			}
		}
		break;
		}
		return lRes;
	}

	LRESULT CBrowserWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		if (g_pTangram->m_pCLRProxy)
		{
			IChromeWebBrowser* pIChromeWebBrowser = nullptr;
			QueryInterface(__uuidof(IChromeWebBrowser), (void**)& pIChromeWebBrowser);
			g_pTangram->m_pCLRProxy->OnDestroyChromeBrowser(pIChromeWebBrowser);
		}

		m_pVisibleWebWnd = nullptr;
		auto it = g_pTangram->m_mapBrowserWnd.find(m_hWnd);
		if (it != g_pTangram->m_mapBrowserWnd.end()) {
			g_pTangram->m_mapBrowserWnd.erase(it);
		}

		if (g_pTangram->m_hHostBrowserWnd == m_hWnd)
		{
			g_pTangram->m_bChromeNeedClosed = true;

			for (auto it : g_pTangram->m_mapBrowserWnd)
			{
				if (((ChromePlus::CBrowserWnd*)it.second)->m_hWnd != m_hWnd)
					((ChromePlus::CBrowserWnd*)it.second)->PostMessageW(WM_CLOSE, 0, 0);
			}
		}

		if ((/*g_pTangram->m_nAppType!=TANGRAM_APP_BROWSER_ECLIPSE&&*/g_pTangram->m_hMainWnd == NULL && g_pTangram->m_mapBrowserWnd.size() == 0) ||
			g_pTangram->m_hHostBrowserWnd == m_hWnd) {
			if (g_pTangram->m_hHostBrowserWnd == m_hWnd)
				g_pTangram->m_hHostBrowserWnd = NULL;
			if (g_pTangram->m_pCLRProxy)
			{
				if (g_pTangram->m_pTangramCLRAppProxy)
					g_pTangram->m_pTangramCLRAppProxy->OnTangramClose();

				g_pTangram->m_bClose = true;
			}

			if (g_pTangram->m_hCBTHook) {
				UnhookWindowsHookEx(g_pTangram->m_hCBTHook);
				g_pTangram->m_hCBTHook = nullptr;
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);

		if (g_pTangram->m_hMainWnd == NULL && 
			g_pTangram->m_bChromeNeedClosed == false && 
			g_pTangram->m_mapBrowserWnd.size() == 1 && 
			::IsWindow(g_pTangram->m_hHostBrowserWnd)&&
			g_pTangram->m_nAppID == 10000 && 
			g_pTangram->m_bEclipse == false)
		{
			::SendMessageW(g_pTangram->m_hHostBrowserWnd, WM_CLOSE, 0, 0);
		}
		return lRes;
	}

	LRESULT ChromePlus::CBrowserWnd::OnWindowPosChanging(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		//if(g_pTangram->m_bOMNIBOXPOPUPVISIBLE)
		::SendMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 2);
		return lRes;
	}

	LRESULT CBrowserWnd::OnBrowserLayout(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		DefWindowProc(uMsg, wParam, lParam);
		if (m_pVisibleWebWnd)
		{
			switch (lParam)
			{
			case 1:
			{
				if (m_pBrowser)
				{
					switch (wParam)
					{
					case 1:
					{
						if (m_pVisibleWebWnd->m_pCompositor)
						{
							IWndNode* pNode = nullptr;
							m_pVisibleWebWnd->m_pCompositor->Open(m_pVisibleWebWnd->m_strCurKey.AllocSysString(), CComBSTR(""), &pNode);
							return 0;
						}
					}
					break;
					}
					BrowserLayout();
					m_pBrowser->LayoutBrowser();
				}
			}
			break;
			case 2:
			{
				if (m_pBrowser)
				{
					//if (g_pTangram->m_bOMNIBOXPOPUPVISIBLE)
					{
						BrowserLayout();
					}
					m_pBrowser->LayoutBrowser();
				}
			}
			break;
			case 3:
			{
				if (m_pBrowser)
				{
					BrowserLayout();
					m_pBrowser->LayoutBrowser();
				}
			}
			break;
			}
		}
		return 0;
	}

	void CBrowserWnd::OnFinalMessage(HWND hWnd) {
		CWindowImpl::OnFinalMessage(hWnd);
		delete this;
	}

	STDMETHODIMP CBrowserWnd::OpenURL(BSTR bstrURL, BrowserWndOpenDisposition nDisposition, BSTR bstrKey, BSTR bstrXml)
	{
		if (m_pVisibleWebWnd)
		{
			CString strDisposition = _T("");
			strDisposition.Format(_T("%d"), nDisposition);
			if (m_pVisibleWebWnd->m_pChromeRenderFrameHost)
			{
				IPCMsg msg;
				msg.m_strType = L"OPEN_URL";
				msg.m_strKey = OLE2T(bstrURL);
				msg.m_strData = strDisposition;
				m_pVisibleWebWnd->m_pChromeRenderFrameHost->SendTangramMessage(&msg);
				//IPCMsg* msg = new IPCMsg;
				//msg->m_strType = L"OPEN_URL";
				//msg->m_strKey = OLE2T(bstrURL);
				//msg->m_strData = strDisposition;
				//m_pVisibleWebWnd->m_pChromeRenderFrameHost->SendTangramMessage(msg);
				//g_pTangram->m_mapIPCCollection[(__int64)msg] = msg;
			}
		}
		return S_OK;
	}
}  // namespace ChromePlus

