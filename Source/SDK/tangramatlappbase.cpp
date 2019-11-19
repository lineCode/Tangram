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

//#include "stdafx.h"
#include "Tangram.c"
#include "TangramatlAppBase.h"
#include "TangramXmlParse.cpp"

typedef CTangramImpl* (__stdcall* GetTangramImpl)();
typedef CTangramBase* (__stdcall* GetTangramBase)();
typedef ITangram* (__stdcall* GetTangram)();

typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*, TangramCommon::CTangramApplicationImpl*);
typedef bool(__stdcall* _IsBrowserModel)(bool bSupportCrashReporting, void*, TangramCommon::CTangramApplicationImpl*);
_InitApp FuncInitApp;
_IsBrowserModel FuncIsBrowserModel;

namespace TangramCommon
{
	ITangram* g_pTangram = nullptr;
	TangramCommon::CChromeBrowserCreatorImpl* g_pCreatorImpl = nullptr;
	CTangramApplicationImpl theAppImpl;

	CTangramWindow::CTangramWindow()
	{
		m_pChild = NULL;
	}

	CTangramWindow::~CTangramWindow()
	{
	}

	void CTangramWindow::OnFinalMessage(HWND hWnd)
	{
		CWindowImpl::OnFinalMessage(hWnd);
		delete this;
	}


	LRESULT CTangramWindow::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		ATLTRACE(_T("OnCreate Tangram Document :%x\n"), this);
		HWND hPWnd = ::GetParent(m_hWnd);
		if (hPWnd == NULL)
		{
			RECT rc;
			::GetClientRect(m_hWnd, &rc);
			m_pChild = new CTangramWindow();
			m_pChild->Create(m_hWnd, ATL::_U_RECT(&rc), _T(""), WS_CHILD | WS_VISIBLE, 0, 0xe900U, 0);
			ICompositorManager* pCompositorManager = nullptr;
			g_pTangram->CreateCompositorManager((__int64)m_hWnd, &pCompositorManager);
			if (pCompositorManager)
			{
				IWndNode* pNode = nullptr;
				pCompositorManager->CreateCompositorWithDefaultNode((__int64)m_pChild->m_hWnd, CComBSTR(""), CComBSTR(""), CComBSTR(""), true, &pNode);
			}
		}
		return DefWindowProc(uMsg, wParam, lParam);
	}

	LRESULT CTangramWindow::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		ATLTRACE(_T("Close Tangram Window :%x\n"), this);
		return DefWindowProc(uMsg, wParam, lParam);
	}

	LRESULT CTangramWindow::OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		return DefWindowProc(uMsg, wParam, lParam);
	}

	LRESULT CTangramWindow::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		if (m_pChild)
		{
			HWND hDesignerWnd = theAppImpl.m_pTangramAppProxy->m_pTangramImpl->m_hHostWnd;
			if(::IsWindow(hDesignerWnd))
				::DestroyWindow(hDesignerWnd);
			PostQuitMessage(0);
		}
		return DefWindowProc(uMsg, wParam, lParam);
	}

	LRESULT CTangramWindow::OnWindowPosChanging(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		LRESULT hr = DefWindowProc(uMsg, wParam, lParam);

		if (m_pChild&&::IsWindow(m_pChild->m_hWnd))
		{
			WINDOWPOS* lpwndpos = (WINDOWPOS*)lParam;
			RECT rc;
			::GetClientRect(m_hWnd, &rc);
			::SetWindowPos(m_pChild->m_hWnd, HWND_BOTTOM, 0, 0, rc.right, rc.bottom, SWP_NOREDRAW | SWP_NOACTIVATE);
		}
		return hr;
	}

	CTangramApplicationImpl::CTangramApplicationImpl()
	{
		m_pTangramAppProxy	= nullptr;
	}

	CTangramApplicationImpl::~CTangramApplicationImpl()
	{
		OutputDebugString(_T("delete CTangramApplicationImpl\n"));
		//HMODULE hModule = ::GetModuleHandle(L"tangramcore.dll");
		//if (hModule) {
		//	typedef int(__stdcall* FreeCLR)();
		//	FreeCLR FuncFreeCLR;
		//	FuncFreeCLR = (FreeCLR)GetProcAddress(hModule, "FreeCLR");
		//	if (FuncFreeCLR != NULL) {
		//		FuncFreeCLR();
		//	}
		//	BOOL bUnload = ::FreeLibrary(hModule);
		//	while (bUnload)
		//		bUnload = ::FreeLibrary(hModule);
		//}
		
		//hModule = ::GetModuleHandle(L"chrome.dll");
		//if (hModule) {
		//	BOOL bUnload = ::FreeLibrary(hModule);
		//	while (bUnload)
		//		bUnload = ::FreeLibrary(hModule);
		//}
		
		//hModule = ::GetModuleHandle(L"chromert.dll");
		//if (hModule) {
		//	BOOL bUnload = ::FreeLibrary(hModule);
		//	//while (bUnload)
		//	//	bUnload = ::FreeLibrary(hModule);
		//}
	}

	HRESULT CTangramApplicationImpl::InitTangram(BOOL bUsingDefaultUI, CTangramAppProxy* pProxy)
	{
		return S_OK;
		//m_bUsingDefaultUI = bUsingDefaultUI;
		//m_pTangramAppProxy = pProxy;
		//m_pTangramAppProxy->m_bAutoDelete = FALSE;
		//BSTR bstrKey = ::SysAllocString(L"TangramApplicationImpl");
		//HRESULT hr = S_FALSE;
		//if (g_pTangram == nullptr)
		//{
		//	hr = CoCreateInstance(CLSID_Tangram, NULL, CLSCTX_ALL, IID_ITangram, (LPVOID*)&g_pTangram);
		//}
		//hr = g_pTangram->put_AppKeyValue(bstrKey, CComVariant((__int64)(static_cast<CTangramApplicationImpl*>(this))));
		//::SysFreeString(bstrKey);
		//return m_pJVMenv ? S_FALSE : hr;
	}

	CTangramAppProxy::CTangramAppProxy()
	{
		m_bAutoDelete = TRUE;
		m_hMainWnd = nullptr;
		m_hClosingFrame = m_hCreatingView = nullptr;
		m_pvoid = nullptr;
		m_pCurDocProxy = nullptr;
		m_strProxyName = _T("");
		m_strProxyID = _T("");
		m_strClosingFrameID = _T("");
		m_strCreatingFrameTitle = _T("");

		m_bCreatingNewFrame = FALSE;
		m_mapTangramDoc.clear();

		m_nFrameIndex = 0;
		m_strAppKey = _T("");
	}

	BOOL CTangramAppProxy::InitTangram(void* pVoid)
	{
		return TRUE;
	}

	HWND CTangramAppProxy::CreateNewFrame(CString strFrameKey)
	{
		return nullptr;
	};

	void CTangramAppProxy::RegistWndRunTimeClass(void* clsInfo)
	{
	}

	void CTangramAppProxy::OnActiveMainFrame(HWND hWnd)
	{
	}

	BOOL CTangramAppProxy::TangramSaveAllModified()
	{
		return TRUE;
	}

	int CTangramAppProxy::OnDestroyMainFrame(CString strID, int nMainFrameCount, int nWndType)
	{
		return -1;
	}

	HWND CTangramAppProxy::CreateWindowObj(LPCTSTR _strClsName, IWndNode* pNode, HWND hParent)
	{
		return nullptr; 
	}

	LRESULT CTangramAppProxy::OnForegroundIdleProc()
	{
		return 0;
	}

	BOOL CTangramAppProxy::TangramPreTranslateMessage(MSG* pMsg)
	{
		return TRUE;
	}

	void CTangramAppProxy::MouseMoveProxy(HWND hWnd)
	{
	}

	HWND CTangramAppProxy::GetActivePopupMenu(HWND hWnd)
	{
		return nullptr;
	}

	ITangramDoc* CTangramAppProxy::OpenDocument(void* pDocTemplate, CString strFile, BOOL bNewFrame)
	{
		return nullptr;
	}

	ITangramDoc* CTangramAppProxy::CreateNewDocument(LPCTSTR lpszFrameID, LPCTSTR lpszAppTitle, void* pDocTemplate, BOOL bNewFrame)
	{
		return nullptr;
	};

	void CTangramAppProxy::OnActiveDocument(ITangramDoc* ActiveDoc, IWndNode* pNodeInDoc, IWndNode* pNodeInCtrlBar, HWND hCtrlBar)
	{
	}

	void CTangramAppProxy::RemoveDoc(LONGLONG llDocID)
	{
		auto it = m_mapTangramDoc.find(llDocID);
		if (it != m_mapTangramDoc.end())
			m_mapTangramDoc.erase(it);
	}

	void CTangramAppProxy::AddDoc(LONGLONG llDocID, ITangramDoc* pDoc)
	{
		m_mapTangramDoc[llDocID] = pDoc;
	}

	ITangramDoc* CTangramAppProxy::GetDoc(LONGLONG llDocID)
	{
		auto it = m_mapTangramDoc.find(llDocID);
		if (it != m_mapTangramDoc.end())
			return it->second;
		return nullptr; 
	}
}
