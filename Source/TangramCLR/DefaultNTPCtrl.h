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
	/// Summary for DefaultNTPCtrl
	/// </summary>
	public ref class DefaultNTPCtrl : public System::Windows::Forms::UserControl
	{
	public:
		DefaultNTPCtrl(void)
		{
			InitializeComponent();
			hostnode = nullptr;
			bindnode = nullptr;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DefaultNTPCtrl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: WndNode^ hostnode;
	private: WndNode^ bindnode;
	private: System::Windows::Forms::Button^ btnNewPage;
	protected:
	private: System::Windows::Forms::Button^ btnTangramSite;
	private: System::Windows::Forms::TreeView^ TangramTreeView;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnNewPage = (gcnew System::Windows::Forms::Button());
			this->btnTangramSite = (gcnew System::Windows::Forms::Button());
			this->TangramTreeView = (gcnew System::Windows::Forms::TreeView());
			this->SuspendLayout();
			// 
			// btnNewPage
			// 
			this->btnNewPage->Location = System::Drawing::Point(33, 24);
			this->btnNewPage->Name = L"btnNewPage";
			this->btnNewPage->Size = System::Drawing::Size(212, 50);
			this->btnNewPage->TabIndex = 0;
			this->btnNewPage->Text = L"NewChromePage";
			this->btnNewPage->UseVisualStyleBackColor = true;
			this->btnNewPage->Click += gcnew System::EventHandler(this, &DefaultNTPCtrl::BtnNewPage_Click);
			// 
			// btnTangramSite
			// 
			this->btnTangramSite->Location = System::Drawing::Point(37, 102);
			this->btnTangramSite->Name = L"btnTangramSite";
			this->btnTangramSite->Size = System::Drawing::Size(207, 52);
			this->btnTangramSite->TabIndex = 1;
			this->btnTangramSite->Text = L"Tangram WebSite";
			this->btnTangramSite->UseVisualStyleBackColor = true;
			this->btnTangramSite->Click += gcnew System::EventHandler(this, &DefaultNTPCtrl::BtnTangramSite_Click);
			// 
			// TangramTreeView
			// 
			this->TangramTreeView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TangramTreeView->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TangramTreeView->Location = System::Drawing::Point(37, 186);
			this->TangramTreeView->Name = L"TangramTreeView";
			this->TangramTreeView->Size = System::Drawing::Size(444, 389);
			this->TangramTreeView->TabIndex = 2;
			this->TangramTreeView->ShowNodeToolTips = true;
			this->TangramTreeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &DefaultNTPCtrl::TangramTreeView_AfterSelect);
			this->TangramTreeView->NodeMouseClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &DefaultNTPCtrl::TangramTreeView_NodeMouseClick);
			this->TangramTreeView->NodeMouseDoubleClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &DefaultNTPCtrl::TangramTreeView_NodeMouseDoubleClick);
			// 
			// DefaultNTPCtrl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Controls->Add(this->TangramTreeView);
			this->Controls->Add(this->btnTangramSite);
			this->Controls->Add(this->btnNewPage);
			this->Name = L"DefaultNTPCtrl";
			this->Size = System::Drawing::Size(521, 605);
			this->Load += gcnew System::EventHandler(this, &DefaultNTPCtrl::DefaultNTPCtrl_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoadNode(TreeNode^ pNode, CTangramXmlParse* pParse);
	private: System::Void BtnNewPage_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnTangramSite_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DefaultNTPCtrl_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TangramTreeView_NodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e);
	private: System::Void TangramTreeView_NodeMouseClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e);
	private: System::Void TangramTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
};
}
