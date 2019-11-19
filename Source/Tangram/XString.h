/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2018 by Tangram Team.   All Rights Reserved.				*
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
* mailto:sunhuizlz@yeah.net
* http://www.cloudaddin.com
*
********************************************************************************/

#ifndef XSTRING_H
#define XSTRING_H

// find
TCHAR * _tcsistr(const TCHAR * str, const TCHAR * substr);
int _tcsccnt(const TCHAR *str, TCHAR ch);

// removal
TCHAR * _tcscrem(TCHAR *str, TCHAR ch);
TCHAR * _tcsicrem(TCHAR *str, TCHAR ch);
TCHAR * _tcsstrrem(TCHAR *str, const TCHAR *substr);
TCHAR * _tcsistrrem(TCHAR *str, const TCHAR *substr);

// replace
TCHAR * _tcscrep(TCHAR *str, TCHAR chOld, TCHAR chNew);
TCHAR * _tcsicrep(TCHAR *str, TCHAR chOld, TCHAR chNew);
int     _tcsistrrep(const TCHAR * lpszStr, 
					const TCHAR * lpszOld, 
					const TCHAR * lpszNew, 
					TCHAR * lpszResult);

// trim
TCHAR *_tcsltrim(TCHAR *str, const TCHAR *targets);
TCHAR *_tcsrtrim(TCHAR *str, const TCHAR *targets);
TCHAR *_tcstrim(TCHAR *str, const TCHAR *targets);

// copy
TCHAR *_tcsnzdup(const TCHAR *str, size_t count);
TCHAR *_tcszdup(const TCHAR * str);

#endif //XSTRING_H
