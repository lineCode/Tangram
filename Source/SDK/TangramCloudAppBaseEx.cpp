
#include "TangramCloudAppBaseEx.h"
#include "TangramAppBase.cpp"

CMessagePumpImplProxy::CMessagePumpImplProxy()
{
	m_pApp = nullptr;
}

CMessagePumpImplProxy::~CMessagePumpImplProxy()
{
}

BOOL CMessagePumpImplProxy::OnAppIdle(BOOL& bIdle, LONG lCount) {
	_AFX_THREAD_STATE* pState = AfxGetThreadState();
	while (bIdle &&
		!::PeekMessage(&(pState->m_msgCur), NULL, NULL, NULL, PM_NOREMOVE)) {
		if (m_pApp&&!m_pApp->OnIdle(lCount++))
			bIdle = FALSE;  // assume "no idle" state
	}
	return true;
}

BOOL CMessagePumpImplProxy::IsAppIdleMessage() {
	_AFX_THREAD_STATE* pState = AfxGetThreadState();
	if (AfxGetApp()->IsIdleMessage(&(pState->m_msgCur))) {
		return true;
	}
	return false;
}

void CMessagePumpImplProxy::ProcessMsg(MSG* msg) {
	if (msg->message != WM_KICKIDLE &&
		//msg->message != WM_CONTROLBARCREATED &&
		//msg->message != WM_MDICLIENTCREATED && 
		!AfxPreTranslateMessage(msg)) {
		if (msg->hwnd == 0 && msg->message == WM_TANGRAMMSG)
		{
			switch (msg->lParam)
			{
			case 20190422:
			{
			}
			break;
			default:
				break;
			}
		}
		::TranslateMessage(msg);
		::DispatchMessage(msg);
	}
}

CMessagePumpImplProxy theAppMessagePumpImplProxy;

CTangramAppBaseEx::CTangramAppBaseEx()
{
	theAppImpl.m_pTangramAppProxy = this;
}

CTangramAppBaseEx::~CTangramAppBaseEx()
{
	HMODULE hModule = ::GetModuleHandle(L"tangramcore.dll");
	if (hModule) {
		typedef int(__stdcall * FreeCLR)();
		FreeCLR FuncFreeCLR;
		FuncFreeCLR = (FreeCLR)GetProcAddress(hModule, "FreeCLR");
		if (FuncFreeCLR != NULL) {
			FuncFreeCLR();
		}
		BOOL bUnload = ::FreeLibrary(hModule);
		while (bUnload)
			bUnload = ::FreeLibrary(hModule);
	}
}

BOOL CTangramAppBaseEx::CheckChromeRT()
{
	TCHAR exefile[MAX_PATH];
	GetModuleFileName(::GetModuleHandle(nullptr), exefile, MAX_PATH * sizeof(TCHAR));
	CString m_strChromeRTPath = CString(exefile);
	int nPos = m_strChromeRTPath.ReverseFind('\\');
	m_strChromeRTPath = m_strChromeRTPath.Left(nPos + 1);
	return ::PathFileExists(m_strChromeRTPath + _T("chromert.dll"));
}

int CTangramAppBaseEx::Run() {
	return CWinAppEx::Run();
	if (CTangramAppBaseEx::InitCloudApp(false) == FALSE)
	{
		CWinAppEx::Run();
		return 1;
	}
	ExitInstance();
	return 0;
}

BOOL CTangramAppBaseEx::InitCloudApp(bool bCrashReporting)
{
	HMODULE hModule = ::LoadLibrary(L"chromert.dll");
	if (hModule) {
		typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*, TangramCommon::CTangramApplicationImpl*);
		_InitApp FuncInitApp;
		FuncInitApp = (_InitApp)GetProcAddress(hModule, "InitApp");
		if (FuncInitApp != NULL) {
			theAppMessagePumpImplProxy.m_pApp = this;
			FuncInitApp(bCrashReporting, (TangramCommon::CTangramBrowserAppBase*)&theAppMessagePumpImplProxy, &theAppImpl);
		}
		return true;
	}
	else
		return false;
};

