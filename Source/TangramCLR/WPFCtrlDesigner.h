#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

namespace TangramDesigner {

	/// <summary>
	/// Summary for WPFCtrlDesigner
	/// </summary>
	public ref class WPFCtrlDesigner : public System::Windows::Forms::UserControl
	{
	public:
		WPFCtrlDesigner(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_strCurAssembly = nullptr;
			m_strCurAssemblys = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WPFCtrlDesigner()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnCreate;
	protected:
	private: System::Windows::Forms::Button^  btnLoadCtrl;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBoxCLRCtrl;

	protected:

	private:
		String^ m_strCurAssembly;
		String^ m_strCurAssemblys;
		Dictionary<String^, String^>^	m_pTangramAssemblyDic = gcnew Dictionary<String^, String^>();
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
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btnLoadCtrl = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxCLRCtrl = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// btnCreate
			// 
			this->btnCreate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnCreate->Location = System::Drawing::Point(15, 78);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(218, 20);
			this->btnCreate->TabIndex = 7;
			this->btnCreate->Text = L"Create";
			this->btnCreate->UseVisualStyleBackColor = true;
			this->btnCreate->Click += gcnew System::EventHandler(this, &WPFCtrlDesigner::btnCreate_Click);
			// 
			// btnLoadCtrl
			// 
			this->btnLoadCtrl->Location = System::Drawing::Point(123, 16);
			this->btnLoadCtrl->Name = L"btnLoadCtrl";
			this->btnLoadCtrl->Size = System::Drawing::Size(110, 22);
			this->btnLoadCtrl->TabIndex = 6;
			this->btnLoadCtrl->Text = L"Load WPF Ctrl Library";
			this->btnLoadCtrl->UseVisualStyleBackColor = true;
			this->btnLoadCtrl->Click += gcnew System::EventHandler(this, &WPFCtrlDesigner::btnLoadCtrl_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 12);
			this->label1->TabIndex = 5;
			this->label1->Text = L"WPF Control ID:";
			// 
			// comboBoxCLRCtrl
			// 
			this->comboBoxCLRCtrl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBoxCLRCtrl->DropDownHeight = 100;
			this->comboBoxCLRCtrl->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCLRCtrl->DropDownWidth = 600;
			this->comboBoxCLRCtrl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxCLRCtrl->FormattingEnabled = true;
			this->comboBoxCLRCtrl->IntegralHeight = false;
			this->comboBoxCLRCtrl->ItemHeight = 16;
			this->comboBoxCLRCtrl->Location = System::Drawing::Point(16, 44);
			this->comboBoxCLRCtrl->Name = L"comboBoxCLRCtrl";
			this->comboBoxCLRCtrl->Size = System::Drawing::Size(217, 24);
			this->comboBoxCLRCtrl->Sorted = true;
			this->comboBoxCLRCtrl->TabIndex = 4;
			// 
			// WPFCtrlDesigner
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->btnCreate);
			this->Controls->Add(this->btnLoadCtrl);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxCLRCtrl);
			this->Name = L"WPFCtrlDesigner";
			this->Size = System::Drawing::Size(251, 166);
			this->Load += gcnew System::EventHandler(this, &WPFCtrlDesigner::WPFCtrlDesigner_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void WPFCtrlDesigner_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnLoadCtrl_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCreate_Click(System::Object^  sender, System::EventArgs^  e);
};
}
