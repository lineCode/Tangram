#if !defined(AFX_HOURGLASSFX_H__C53DB5BF_841A_44D4_8C41_062A9CFDD449__INCLUDED_)
#define AFX_HOURGLASSFX_H__C53DB5BF_841A_44D4_8C41_062A9CFDD449__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HourglassFX.h : header file
//
/////////////////////////////////////////////////////////////////////////////
//
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
* http://www.CloudAddin.com
*
********************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// CHourglassFX window

template <class BASE_TYPE>
class CHourglassFX : public BASE_TYPE
{
private:
	enum { ANICURSOR_FRAMES = 10 };

	HBRUSH m_hBrush;
	CRect m_rcIcon;
	int m_iAniStep;
	HCURSOR m_hAniCur;

// Construction-Destruction
public:
	CHourglassFX()
	{
		ShowWaitMessage();
		SetAnimationDelay(125);

		//m_hAniCur = AfxGetApp()->LoadCursor(IDR_HOURGLASS);
	};

	virtual ~CHourglassFX()
	{
		DestroyCursor(m_hAniCur);
	};

// Implementation
protected:
	virtual void PreAnimation(HTREEITEM hItemMsg);
	virtual void DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep);
	virtual void PostAnimation();
};

/////////////////////////////////////////////////////////////////////////////
// CHourglassFX

template <class BASE_TYPE>
void CHourglassFX<BASE_TYPE>::PreAnimation(HTREEITEM hItemMsg)
{
	BASE_TYPE::PreAnimation(hItemMsg);

	m_iAniStep = 0;

	// get msg image rect
	GetItemImageRect(hItemMsg, &m_rcIcon);

	// create background brush with current bg color (take rgb part only)
	m_hBrush = CreateSolidBrush(GetBkColor() & 0x00FFFFFF);
}

template <class BASE_TYPE>
void CHourglassFX<BASE_TYPE>::PostAnimation()
{
	DeleteObject(m_hBrush);

	BASE_TYPE::PostAnimation();
}

template <class BASE_TYPE>
void CHourglassFX<BASE_TYPE>::DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep)
{
	BASE_TYPE::DoAnimation(bTimerEvent, iMaxSteps, iStep);

	if (!bTimerEvent) return;	// process only timer events

	m_iAniStep = (m_iAniStep + 1) % ANICURSOR_FRAMES;

	CClientDC dc(this);

	DrawIconEx(dc.GetSafeHdc(), m_rcIcon.left, m_rcIcon.top, m_hAniCur,
		m_rcIcon.Width(), m_rcIcon.Height(), m_iAniStep, m_hBrush, DI_NORMAL);
}


#endif // !defined(AFX_HOURGLASSFX_H__C53DB5BF_841A_44D4_8C41_062A9CFDD449__INCLUDED_)
