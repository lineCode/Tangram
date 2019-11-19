// TabPageWnd.cpp : implementation file
//

#include "stdafx.h"
#include "TabPageWnd.h"


// CTabPageWnd

CTabPageWnd::CTabPageWnd()
{
	ATLTRACE(_T("TabPageCreate:%x\n"),this);
}

CTabPageWnd::~CTabPageWnd()
{
	ATLTRACE(_T("TabPageClose:%x\n"),this);
}


BEGIN_MESSAGE_MAP(CTabPageWnd, CWnd)
	//ON_WM_DESTROY()
END_MESSAGE_MAP()



// CTabPageWnd message handlers
void CTabPageWnd::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class

	CWnd::PostNcDestroy();
	delete this;
}
