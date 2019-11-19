#pragma once

namespace TangramCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AcquireTemplateStorageInfoForm
	/// </summary>
	public ref class AcquireTemplateStorageInfoForm : public System::Windows::Forms::Form
	{
	public:
		AcquireTemplateStorageInfoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			strTemplateCategory = L"";
			strTemplateName = L"";
		}

		String^ strTemplateCategory;
		String^ strTemplateName;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AcquireTemplateStorageInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtCategory;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtTemplateName;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnCancel;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtCategory = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtTemplateName = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(305, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter New Template Category:";
			// 
			// txtCategory
			// 
			this->txtCategory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtCategory->Location = System::Drawing::Point(16, 44);
			this->txtCategory->Name = L"txtCategory";
			this->txtCategory->Size = System::Drawing::Size(379, 31);
			this->txtCategory->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(274, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Enter New Template Name:";
			// 
			// txtTemplateName
			// 
			this->txtTemplateName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtTemplateName->Location = System::Drawing::Point(16, 114);
			this->txtTemplateName->Name = L"txtTemplateName";
			this->txtTemplateName->Size = System::Drawing::Size(379, 31);
			this->txtTemplateName->TabIndex = 3;
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(86, 226);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(85, 55);
			this->btnSave->TabIndex = 4;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &AcquireTemplateStorageInfoForm::btnSave_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(197, 226);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(121, 55);
			this->btnCancel->TabIndex = 4;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &AcquireTemplateStorageInfoForm::btnCancel_Click);
			// 
			// AcquireTemplateStorageInfoForm
			// 
			this->ClientSize = System::Drawing::Size(407, 342);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtTemplateName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtCategory);
			this->Controls->Add(this->label1);
			this->Name = L"AcquireTemplateStorageInfoForm";
			this->Text = L"Save New Template";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e);
};
}
