#pragma once


// CNewFrameDlg dialog

class CNewFrameDlg : public CDialog
{
	DECLARE_DYNAMIC(CNewFrameDlg)

public:
	CNewFrameDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewFrameDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWFRAMEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strFrameID;
	afx_msg void OnBnClickedOk();
};
