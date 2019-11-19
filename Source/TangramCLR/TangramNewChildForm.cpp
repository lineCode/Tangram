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
* OUTLINED IN THE GPL LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
*
********************************************************************************/

#include "stdafx.h"
#include "TangramNewChildForm.h"
#include "dllmain.h"
#include "TangramClrProxy.h"
extern CTangramCLRProxy theAppProxy;

namespace TangramCLR {
	System::Void TangramNewChildForm::NewTemplateListView_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		String^ strXml = NewTemplateListView->SelectedItems[0]->Tag->ToString();
		if (String::IsNullOrEmpty(strXml) == false)
		{
			IDispatch* pFormDisp = theApp.m_pTangramImpl->m_pCLRProxy->CreateCLRObj(strXml);
		}
		Close();
	}
}
