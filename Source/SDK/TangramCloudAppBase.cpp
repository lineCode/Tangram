
#include "TangramCloudAppBase.h"
#include "TangramAtlAppBase.cpp"

CTangramAppBase::CTangramAppBase()
{
	theAppImpl.m_pTangramAppProxy = this;
}

CTangramAppBase::~CTangramAppBase()
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

void CTangramAppBase::InitCloudApp(bool bCrashReporting, ChromePlus::CTangramMessagePumpImplProxy* pPumpImplProxy)
{
	HMODULE hModule = ::LoadLibrary(L"chromert.dll");
	if (hModule) {
		::PostAppMessage(::GetCurrentThreadId(), WM_TANGRAMMSG,
			(WPARAM)& theAppImpl, 20190420);
		typedef int(__stdcall * _InitApp)(bool bSupportCrashReporting, void*);
		_InitApp FuncInitApp;
		FuncInitApp = (_InitApp)GetProcAddress(hModule, "InitApp");
		if (FuncInitApp != NULL) {
			FuncInitApp(bCrashReporting, pPumpImplProxy);
		}
	}
};

