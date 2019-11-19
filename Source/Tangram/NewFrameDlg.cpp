// NewFrameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NewFrameDlg.h"
#include "resource.h"


// CNewFrameDlg dialog

IMPLEMENT_DYNAMIC(CNewFrameDlg, CDialog)

CNewFrameDlg::CNewFrameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_NEWFRAMEDLG, pParent)
	, m_strFrameID(_T(""))
{

}

CNewFrameDlg::~CNewFrameDlg()
{
}

void CNewFrameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strFrameID);
	DDV_MaxChars(pDX, m_strFrameID, 256);
}


BEGIN_MESSAGE_MAP(CNewFrameDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CNewFrameDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CNewFrameDlg message handlers


void CNewFrameDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDialog::OnOK();
}
