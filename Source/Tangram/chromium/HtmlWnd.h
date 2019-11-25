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

#pragma once

#include "../stdafx.h"
#include "../IPC/EndPoint.h"

namespace ChromePlus
{
	class ATL_NO_VTABLE CHtmlWnd :
		public CWindowImpl<CHtmlWnd, CWindow>,
		public CChromeRenderFrameHostProxyBase,
		public CComObjectRootEx<CComSingleThreadModel>,
		public IDispatchImpl<IChromeWebContent, &_uuidof(IChromeWebContent)>,
		public IPC::EndPoint
	{
	public:
		CHtmlWnd();
		~CHtmlWnd() override;

		BOOL								m_bDevToolWnd;

		HWND								m_hHostWnd;
		HWND								m_hChildWnd;
		HWND								m_hExtendWnd;

		CString								m_strURL;
		CString								m_strCurKey;
		CString								m_strCurXml;
		CString								m_strAppProxyID;

		CCompositor*						m_pCompositor;
		CTangramDoc*						m_pDoc;
		ITangramAppProxy*					m_pAppProxy;
		CCompositorManager*					m_pCompositorManager;

		CHtmlWnd*							m_pWebWnd;
		CHtmlWnd*							m_pDevToolWnd;
		map<CString, CString>				m_mapFormsInfo;
		map<CString, CString>				m_mapAtlMFCsInfo;
		map<CString, CString>				m_mapStartupsInfo;
		map<CString, CString>				m_mapeclipsesInfo;
		map<CString, CString>				m_mapWorkBenchInfo;
		map<CString, CString>				m_mapUserControlsInfo;
		map<CString, CMDIChildFormInfo*>	m_mapChildFormsInfo;
		BEGIN_MSG_MAP(CHtmlWnd)
			MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
			MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
			MESSAGE_HANDLER(WM_TANGRAMMSG, OnTangramMsg)
			MESSAGE_HANDLER(WM_MOUSEACTIVATE, OnMouseActivate)
			MESSAGE_HANDLER(WM_CHROMEIPCMSG, OnChromeIPCMsgReceived)
			MESSAGE_HANDLER(WM_CHROMEWNDPARENTCHANGED, OnParentChanged)
		END_MSG_MAP()

		BEGIN_COM_MAP(CHtmlWnd)
			COM_INTERFACE_ENTRY(IDispatch)
			COM_INTERFACE_ENTRY(IChromeWebContent)
		END_COM_MAP()

		// IPC message
		IPC::Broker* GetBroker() override;
		void OnIPCMessageReceived(CString strChannel, CString strData) override;

		void SendChromeIPCMessage(CString strType, CString strParam1, CString strParam2);
		void OnChromeIPCMessageReceived(std::wstring strType, std::wstring strParam1, std::wstring strParam2) override;
		CChromeBrowserBase* GetChromeBrowserBase(HWND) override;

		void LoadDocument2Viewport(CString strName, CString strXML);

		void HandleChromeIPCMessage(CString strType, CString strParam1, CString strParam2);
		void HandleBundledMessage(CString strParam1, CString strParam2);
		void HandleSingleMessage(CString strParam);
		void RenderHTMLElement(CString strRuleName, CString strHTML);
		void RenderHTMLObjectElement(CString strHTML);
		void RenderHTMLExtraElement(CString strHTML);
		void RenderHTMLDataElement(CString strHTML);
		void RenderHTMLDocElement(CString strHTML);
		void OnNTPLoaded();
	protected:
		ULONG InternalAddRef() { return 1; }
		ULONG InternalRelease() { return 1; }

	private:
		void Show(CString strID);
		void OnFinalMessage(HWND hWnd) override;
		LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
		LRESULT OnShowWindow(UINT, WPARAM, LPARAM, BOOL&);
		LRESULT OnTangramMsg(UINT, WPARAM, LPARAM, BOOL&);
		LRESULT OnMouseActivate(UINT, WPARAM, LPARAM, BOOL&);
		LRESULT OnParentChanged(UINT, WPARAM, LPARAM, BOOL&);
		LRESULT OnChromeIPCMsgReceived(UINT, WPARAM, LPARAM, BOOL&);
	};
};