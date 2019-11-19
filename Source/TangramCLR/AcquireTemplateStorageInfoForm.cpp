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
#include "AcquireTemplateStorageInfoForm.h"

namespace TangramCLR
{

void AcquireTemplateStorageInfoForm::btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!String::IsNullOrWhiteSpace(txtCategory->Text) && !String::IsNullOrWhiteSpace(txtTemplateName->Text))
	{
		strTemplateCategory = txtCategory->Text;
		strTemplateName = txtTemplateName->Text;
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
}

void AcquireTemplateStorageInfoForm::btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
}

}
