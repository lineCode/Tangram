
#include "CloudMFCApp.h"
#include "TangramCloudAppBase.cpp"

// CCloudMFCApp initialization
CCloudMFCApp::CCloudMFCApp()
{
	theAppImpl.m_pTangramAppProxy = this;
}

CCloudMFCApp::~CCloudMFCApp()
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

BOOL CCloudMFCApp::OnAppIdle(BOOL& bIdle, LONG lCount) {
	_AFX_THREAD_STATE* pState = AfxGetThreadState();
	while (bIdle &&
		!::PeekMessage(&(pState->m_msgCur), NULL, NULL, NULL, PM_NOREMOVE)) {
		if (!OnIdle(lCount++))
			bIdle = FALSE;  // assume "no idle" state
	}
	return true;
}

BOOL CCloudMFCApp::IsAppIdleMessage() {
	_AFX_THREAD_STATE* pState = AfxGetThreadState();
	if (IsIdleMessage(&(pState->m_msgCur))) {
		return true;
	}
	return false;
}

void CCloudMFCApp::ProcessMsg(MSG* msg) {
	if (msg->message != WM_KICKIDLE && !AfxPreTranslateMessage(msg)) {
		::TranslateMessage(msg);
		::DispatchMessage(msg);
	}
}

int CCloudMFCApp::Run() {
	CTangramAppBase::InitCloudApp(false, &theApp);
	ExitInstance();
	return 0;
}
