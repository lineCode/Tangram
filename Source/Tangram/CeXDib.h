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


#ifndef _CEXDIB_H_
#define _CEXDIB_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef	HDIB
#define HDIB	HANDLE
#endif

#ifndef WIDTHBYTES
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)
#endif

#ifndef BFT_BITMAP
#define BFT_BITMAP 0x4d42   // 'BM'
#endif

class CCeXDib  
{
public:
	CCeXDib();
	virtual ~CCeXDib();

	HDIB Create(DWORD dwWidth, DWORD dwHeight, WORD wBitCount);
	void Clone(CCeXDib* src);
	void Draw(HDC hDC, DWORD dwX, DWORD dwY);
	void Copy(HDC hDC, DWORD dwX, DWORD dwY);
	LPBYTE GetBits();
	void Clear(BYTE byVal = 0);

	void SetGrayPalette();
	void SetPaletteIndex(BYTE byIdx, BYTE byR, BYTE byG, BYTE byB);
	void SetPixelIndex(DWORD dwX, DWORD dwY, BYTE byI);
	void BlendPalette(COLORREF crColor, DWORD dwPerc);

	WORD GetBitCount();
	DWORD GetLineWidth();
	DWORD GetWidth();
	DWORD GetHeight();
	WORD GetNumColors();

	BOOL WriteBMP(LPCTSTR bmpFileName);

private:
	void FreeResources();

	DWORD GetPaletteSize();
	DWORD GetSize();

	RGBQUAD RGB2RGBQUAD(COLORREF cr);

	HDIB				m_hDib;
    BITMAPINFOHEADER    m_bi;
	DWORD				m_dwLineWidth;
	WORD				m_wColors;

	HBITMAP				m_hBitmap;	// Handle to bitmap
	HDC					m_hMemDC;	// Handle to memory DC
	LPVOID				m_lpBits;	// Pointer to actual bitmap bits
};

#endif 
