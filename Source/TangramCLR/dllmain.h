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

// dllmain.h : Declaration of module class.

#include "TangramCoreEvents.h"
#ifdef _WIN64
#include <ActiveDS.h>
#endif
#include <cstring>
#include <iostream>
#include "TangramBase.h"

class CWndNodeCLREvent;
typedef struct tagTangramWindowInfo {
	bool m_bContainer;
	CString m_strStyles;
} TangramWindowInfo;

class CTangramCLRApp :
	public ITangramDelegate,
	public ITangramAppProxy
{
public:
	CTangramCLRApp();
	virtual ~CTangramCLRApp();

	bool									m_bBrowserModeInit = false;
	DWORD									m_dwThreadID;
	HWND									m_hHostWnd;
	ITangram*								m_pTangram;
	IVSExtender*							m_pVSExtender;

	CString									m_strAppPath;

	int CalculateByteMD5(BYTE* pBuffer, int BufferSize, CString &MD5);
	CString GetLibPathFromAssemblyQualifiedName(CString strAssemblyQualifiedName);
	virtual void ProcessMsg(MSG* msg);
	virtual void ForegroundIdleProc() {};
	virtual bool DoIdleWork();
	virtual bool GetClientAreaBounds(HWND hWnd, RECT& rc) { return false; };
	virtual bool HookAppDocTemplateInfo() { return false; };
	virtual BOOL OnAppIdle(BOOL& bIdle, LONG lCount) {
		return false;
	};
	virtual HWND QueryCanClose(HWND hWnd) { return NULL; };
	virtual void BeginBrowserSession();
	virtual void EndBrowserSession();

	virtual BOOL IsAppIdleMessage() {
		return false;
	};

	virtual HWND GetMainWnd()
	{
		return NULL;
	};

	virtual void TangramInit() {};
	virtual CString GetNTPXml() { return _T(""); };
	virtual CString GetNTPData()  { return _T(""); };

	virtual bool BrowserAppStart() { 
		return false; 
	};
	virtual bool OnTangramPreTranslateMessage(MSG* pMsg) { return false; };

	void InitTangramApp(bool bCrashReporting);
	void ExitJVM();
private:
	//CTangramCoreEvents:
	void OnTangramClose();
	void OnOpenComplete(HWND hWnd, CString strUrl, IWndNode* pRootNode);
	HWND InitTangramApp();
	CString _GetLibPathFromAssemblyQualifiedName(CString strDir, CString strLibName);
	virtual bool EclipseAppInit();
	virtual void TangramIPCMsg(HWND hWnd, CString strType, CString strParam1, CString strParam2);
	virtual void TangramRenderHTMLElement(HWND hWnd, CString strRuleName, CString strHTML);
};

extern CTangramCLRApp theApp;

class CTangramNodeEvent : public CWndNodeEvents
{
public:
	CTangramNodeEvent();
	virtual ~CTangramNodeEvent();

	CWndNodeCLREvent* m_pTangramNodeCLREvent;
private:
	void __stdcall  OnOpenComplete();
	void __stdcall  OnDestroy();
	void __stdcall  OnDocumentComplete(IDispatch* pDocdisp, BSTR bstrUrl);
	void __stdcall  OnNodeAddInCreated(IDispatch* pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml);
	void __stdcall  OnTabChange(int nActivePage, int nOldPage);
	void __stdcall  OnIPCMessageReceived(BSTR bstrChannel, BSTR bstrData);
};

extern ITangram* GetTangram();
