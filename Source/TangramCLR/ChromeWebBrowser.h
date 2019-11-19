#pragma once

#include "BrowserWndOpenDisposition.h"

using namespace System;

namespace TangramCLR
{

	public ref class ChromeWebBrowser
	{
	public:
		IChromeWebBrowser*				m_pChromeWebBrowserHost;
		ChromeWebBrowser(IChromeWebBrowser* pChromeWebBrowser);
		void OpenURL(String^ url, Disposition disposition, String^ key, String^ xml);
	};

}