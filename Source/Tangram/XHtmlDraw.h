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


#ifndef XHTMLDRAW_H
#define XHTMLDRAW_H

#pragma warning(disable : 4996)	// disable bogus deprecation warning

const int	XHTMLDRAW_MAX_TEXT = 1000;
const DWORD	COLOR_NONE = ((DWORD)-1);

class CXHtmlDraw
{
// draw struct
public:
	struct XHTMLDRAWSTRUCT
	{
		// ctor
		XHTMLDRAWSTRUCT()
		{
			crText              = COLOR_NONE;//GetSysColor(COLOR_WINDOWTEXT);
			crAnchorText        = RGB(0,0,255);
			crBackground        = COLOR_NONE;//GetSysColor(COLOR_WINDOW);
			crTextBackground    = COLOR_NONE;
			hDC					= NULL;
			hBitmap				= NULL;
			hOldBitmap			= NULL;
			bIgnoreColorTag		= false;
			bTransparent		= false;
			bBold               = false;
			bItalic             = false;
			bUnderline          = false;
			bStrikeThrough      = false;
			bUseEllipsis        = false;
			bLogFont            = false;
			bHasAnchor          = false;
			bAnchorIsUnderlined = false;
			uFormat				= DT_VCENTER | DT_SINGLELINE | DT_LEFT | DT_NOPREFIX;
			pszAnchor			= NULL;
			nRightX             = 0;
			nID                 = 0;
			memset(&rect, 0, sizeof(RECT));
			memset(&rectAnchor, 0, sizeof(RECT));
			memset(&lf, 0, sizeof(LOGFONT));
		}

		// copy ctor
		XHTMLDRAWSTRUCT(const XHTMLDRAWSTRUCT& ds)
		{
			crText = ds.crText;
			crAnchorText = ds.crAnchorText;
			crBackground = ds.crBackground;
			crTextBackground = ds.crTextBackground;
			hDC = 0;
			hBitmap = 0;
			hOldBitmap = 0;
			bIgnoreColorTag = ds.bIgnoreColorTag;
			bTransparent = ds.bTransparent;
			bBold = ds.bBold;
			bItalic = ds.bItalic;
			bUnderline = ds.bUnderline;
			bStrikeThrough = ds.bStrikeThrough;
			bUseEllipsis = ds.bUseEllipsis;
			bLogFont = ds.bLogFont;
			bHasAnchor = ds.bHasAnchor;
			bAnchorIsUnderlined = ds.bAnchorIsUnderlined;
			uFormat = ds.uFormat;
			if (ds.pszAnchor)
			{
				size_t len = _tcslen(ds.pszAnchor);
				pszAnchor = new TCHAR [len + 4];
				memset(pszAnchor, 0, (len+4)*sizeof(TCHAR));
				_tcsncpy(pszAnchor, ds.pszAnchor, len);
			}
			nRightX = ds.nRightX;
			lf = ds.lf;
			rect = ds.rect;
			rectAnchor = ds.rectAnchor;
			nID = ds.nID;
		}

		// assignment operator
		XHTMLDRAWSTRUCT& operator=(const XHTMLDRAWSTRUCT& ds)
		{
			if ((ds.pszAnchor == NULL) ||
				(ds.pszAnchor != pszAnchor))  // check for a = a
			{
				crText = ds.crText;
				crAnchorText = ds.crAnchorText;
				crBackground = ds.crBackground;
				crTextBackground = ds.crTextBackground;
				hDC = 0;
				hBitmap = 0;
				hOldBitmap = 0;
				bIgnoreColorTag = ds.bIgnoreColorTag;
				bTransparent = ds.bTransparent;
				bBold = ds.bBold;
				bItalic = ds.bItalic;
				bUnderline = ds.bUnderline;
				bStrikeThrough = ds.bStrikeThrough;
				bUseEllipsis = ds.bUseEllipsis;
				bLogFont = ds.bLogFont;
				bHasAnchor = ds.bHasAnchor;
				bAnchorIsUnderlined = ds.bAnchorIsUnderlined;
				uFormat = ds.uFormat;
				if (ds.pszAnchor)
				{
					size_t len = _tcslen(ds.pszAnchor);
					pszAnchor = new TCHAR [len + 4];
					memset(pszAnchor, 0, (len+4)*sizeof(TCHAR));
					_tcsncpy(pszAnchor, ds.pszAnchor, len);
				}
				nRightX = ds.nRightX;
				lf = ds.lf;
				rect = ds.rect;
				rectAnchor = ds.rectAnchor;
				nID = ds.nID;
			}

			return *this;
		}

		// dtor
		~XHTMLDRAWSTRUCT()
		{
			if (hOldBitmap)
			{
				if (hDC)
					SelectObject(hDC, hOldBitmap);
			}
			hOldBitmap = NULL;
			if (hDC)
				DeleteDC(hDC);
			hDC = NULL;
			if (hBitmap)
				DeleteObject(hBitmap);
			hBitmap = NULL;

			if (pszAnchor)
				delete [] pszAnchor;
			pszAnchor = NULL;
		}

		COLORREF crText;				// text color
		COLORREF crAnchorText;			// anchor text
		COLORREF crBackground;			// background color for window - used
										// to fill entire drawing rect
		COLORREF crTextBackground;		// text background color - used for 
										// background of text
		HDC		hDC;					// saved dc - used to preserve display 
										// area, in case there are links and 
										// bTransparent = true
		HBITMAP	hBitmap;				// bitmap associated with hDC
		HBITMAP	hOldBitmap;				// old bitmap from hDC
										// the link underline)
		BOOL	bIgnoreColorTag;		// true = ignore any font color tags
		BOOL	bTransparent;			// true = use transparency
		BOOL	bBold;					// true = text is bold
		BOOL	bItalic;				// true = text is italic
		BOOL	bUnderline;				// true = text is underlined
		BOOL	bStrikeThrough;			// true = text is strike through
		BOOL	bUseEllipsis;			// true = draw with ellipsis (...)
		BOOL	bLogFont;				// true = use lf member
		BOOL	bHasAnchor;				// true = contains anchor <a>...</a>
		BOOL	bAnchorIsUnderlined;	// true = anchor currently underlined
		UINT	uFormat;				// Specifies the method of formatting 
										// the text.  See DrawText() for values
		TCHAR *	pszAnchor;				// url for <A> tag
		int		nRightX;				// rightmost pixel position (in client coords)
		LOGFONT	lf;						// default LOGFONT (optional)
		RECT	rect;					// rect for drawing
		RECT	rectAnchor;				// rect for anchor
		UINT	nID;					// id to allow you to uniquely identify this
										// CXHtmlDraw object
	};

	struct XHTMLDRAW_APP_COMMAND
	{
		HWND	hWnd;			// HWND of window to receive message
		UINT	uMessage;		// message sent to parent
		WPARAM	wParam;			// user defined data returned in wParam parameter
		TCHAR *	pszCommand;		// string that ties this entry to HTML hyperlink
	};

// Construction
public:
	CXHtmlDraw(UINT nMaxText = XHTMLDRAW_MAX_TEXT);
	virtual ~CXHtmlDraw();

// Operations
public:
	int Draw(HDC hdc,
			 LPCTSTR lpszText, 
			 XHTMLDRAWSTRUCT * pXHDS,
			 BOOL bUnderlineUrl);

	int GetPlainText(const TCHAR *html, TCHAR *plain, DWORD nPlainSize);
	static BOOL IsOverAnchor(HWND hWnd, XHTMLDRAWSTRUCT * pXHDS);


// Implementation
private:
	struct CHAR_ENTITIES
	{
		TCHAR *	pszName;		// string entered in HTML - e.g., "&nbsp;"
		TCHAR	cCode;			// code generated by XHtmlDraw
		TCHAR	cSymbol;		// character symbol displayed
	};
	BOOL	m_bOverAnchor;		// true = cursor over url
	UINT	m_nMaxText;			// max text length in TCHARs

	static CHAR_ENTITIES m_aCharEntities[];

	TCHAR	GetCharEntity(TCHAR cCode);
	void	InitCharEntities();
	BOOL	IsTrueType(HDC hDC);
	void	ReplaceCharEntities(TCHAR * buf, size_t buflen);
};

#endif //XHTMLDRAW_H
