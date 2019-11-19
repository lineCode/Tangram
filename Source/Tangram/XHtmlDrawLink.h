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
* OUTLINED IN THE TANGRAM LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
********************************************************************************/


#ifndef XHTMLDRAWLINK_H
#define XHTMLDRAWLINK_H

#include "XHtmlDraw.h"

class CXHtmlDrawLink
{
// ctor
public:
	CXHtmlDrawLink();
	virtual ~CXHtmlDrawLink();

// Operations
public:
	BOOL	GotoURL(LPCTSTR url, int showcmd, LPARAM lParam);
	BOOL	ProcessAppCommand(LPCTSTR lpszCommand, LPARAM lParam);
	void	SetAppCommands(CXHtmlDraw::XHTMLDRAW_APP_COMMAND * paAppCommands, 
				int nAppCommands);
	BOOL	SetLinkCursor();

// Implementation
protected:
    HCURSOR		m_hLinkCursor;		// cursor for links
	int			m_nAppCommands;
	CXHtmlDraw::XHTMLDRAW_APP_COMMAND * m_paAppCommands;

	LONG	GetRegKey(HKEY key, LPCTSTR subkey, LPTSTR lpData);
	void	SetDefaultCursor();
};

#endif //XHTMLDRAWLINK_H
