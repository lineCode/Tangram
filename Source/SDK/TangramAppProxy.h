#pragma once
#include "TangramMfcAppbase.h"
#include <atlbase.h>
#include <atlcom.h>

class CAppProxy : public TangramCommon::CTangramBrowserAppBase
{
public:
	CAppProxy();
	virtual ~CAppProxy();

	BOOL InitCloudApp(bool bCrashReporting);
	BOOL IsBrowserModel(bool bCrashReporting);
	virtual BOOL OnAppIdle(BOOL& bIdle, LONG lCount);
	virtual bool DoIdleWork();
	virtual BOOL IsAppIdleMessage();
	virtual void ProcessMsg(MSG* msg);
	virtual void ForegroundIdleProc();
	virtual CString GetNTPXml();
	virtual void TangramInit();
	virtual bool TangramInitEx();
	virtual bool OnTangramPreTranslateMessage(MSG* pMsg);
	virtual HWND GetMainWnd();

	ITangram* m_pTangram = nullptr;
	CTangramImpl* m_pTangramImpl = nullptr;
	CTangramBase* m_pTangramBase = nullptr;
};

extern CAppProxy theAppProxy;
