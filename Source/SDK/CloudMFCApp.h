#pragma once

#include "TangramCloudAppBase.h"

// CCloudMFCApp:
// See CloudMFCApp.cpp for the implementation of this class
//

class CCloudMFCApp : public CWinAppEx, public CTangramAppBase {
public:
	CCloudMFCApp();
	virtual ~CCloudMFCApp();

	// Overrides
public:
	virtual BOOL OnAppIdle(BOOL& bIdle, LONG lCount);
	virtual BOOL IsAppIdleMessage();
	virtual void ProcessMsg(MSG* msg);
	virtual int Run();
};
