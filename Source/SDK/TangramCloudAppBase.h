#pragma once
#include <atlbase.h>
#include <atlstr.h>
#include <atlcom.h>
#include <atlwin.h>
#include "ChromeProxy.h"
#include "tangramatlappbase.h"

class CTangramAppBase :
	public ChromePlus::CTangramMessagePumpImplProxy,
	public TangramCommon::CTangramAppProxy {
public:
	CTangramAppBase();
	virtual ~CTangramAppBase();

	virtual void ProcessMsg(MSG* msg) {
		if (msg) {
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
	};

	virtual bool DoIdleWork() {
		return false;
	};

	virtual BOOL OnAppIdle(BOOL& bIdle, LONG lCount) {
		return false;
	};
	virtual BOOL IsAppIdleMessage() {
		return false;
	};
	static void InitCloudApp(bool bCrashReporting, ChromePlus::CTangramMessagePumpImplProxy* pPumpImplProxy);
};
