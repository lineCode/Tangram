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
*
********************************************************************************/

#include "stdafx.h"
#include "ChromeWebBrowser.h"

using System::Runtime::InteropServices::Marshal;

namespace TangramCLR
{
	ChromeWebBrowser::ChromeWebBrowser(IChromeWebBrowser* pChromeWebBrowser)
	{
		m_pChromeWebBrowserHost = pChromeWebBrowser;
	}

	void ChromeWebBrowser::OpenURL(String^ url, Disposition disposition, String^ key, String^ xml)
	{
		BSTR bstrUrl = STRING2BSTR(url);
		BSTR bstrKey = STRING2BSTR(key);
		BSTR bstrXml = STRING2BSTR(xml);
		if (m_pChromeWebBrowserHost)
		{
			m_pChromeWebBrowserHost->OpenURL(bstrUrl, (BrowserWndOpenDisposition)disposition, bstrKey, bstrXml);
		}
	}

}