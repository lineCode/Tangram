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

// TangramOutLookCustomizeFormDlg.h : COutLookCustomizeFormDlg implementation file

#pragma once

#include "../Tangram/resource.h"      
#include <atlhost.h>
#include <atlstr.h>
using namespace ATL;

// COutLookCustomizeFormDlg

namespace OfficePlus
{
	namespace OutLookPlus
	{
		class COutLookInspector;
		class COutLookCustomizeFormDlg :
			public CAxDialogImpl<COutLookCustomizeFormDlg>
		{
		public:
			COutLookCustomizeFormDlg();
			~COutLookCustomizeFormDlg();

			enum { IDD = IDD_TANGRAMOUTLOOKCUSTOMIZEFORMDLG };

			CString				m_strName;
			COutLookInspector*	m_pOutLookInspector;
			BEGIN_MSG_MAP(COutLookCustomizeFormDlg)
				MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
				COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
				COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
				CHAIN_MSG_MAP(CAxDialogImpl<COutLookCustomizeFormDlg>)
			END_MSG_MAP()

			LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
			LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
			LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		};
	}
}
