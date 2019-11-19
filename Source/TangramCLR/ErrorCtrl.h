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

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TangramCLR {

	/// <summary>
	/// Summary for ErrorCtrl
	/// </summary>
	public ref class ErrorCtrl : public System::Windows::Forms::UserControl
	{
	public:
		ErrorCtrl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		property String^ ErrorInfoText
		{
			void set(String^ errorInfo)
			{
				m_strErrorInfo = errorInfo;
			};
		}
	protected:
		String^ m_strErrorInfo = nullptr;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ErrorCtrl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  ErrorInfo;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ErrorInfo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ErrorInfo
			// 
			this->ErrorInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ErrorInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ErrorInfo->ForeColor = System::Drawing::Color::Sienna;
			this->ErrorInfo->Location = System::Drawing::Point(0, 0);
			this->ErrorInfo->Name = L"ErrorInfo";
			this->ErrorInfo->Size = System::Drawing::Size(148, 148);
			this->ErrorInfo->TabIndex = 0;
			this->ErrorInfo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ErrorInfo->Click += gcnew System::EventHandler(this, &ErrorCtrl::ErrorInfo_Click);
			// 
			// ErrorCtrl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->ErrorInfo);
			this->Name = L"ErrorCtrl";
			this->Size = System::Drawing::Size(148, 148);
			this->Load += gcnew System::EventHandler(this, &ErrorCtrl::ErrorCtrl_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ErrorCtrl_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		ErrorInfo->Text = m_strErrorInfo;
	}
	private: System::Void ErrorInfo_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
