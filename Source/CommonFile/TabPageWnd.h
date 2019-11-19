#pragma once


// CTabPageWnd

class CTabPageWnd : public CWnd
{
public:
	CTabPageWnd();
	virtual ~CTabPageWnd();

protected:
	virtual void PostNcDestroy();
	DECLARE_MESSAGE_MAP()
};


