#pragma once

namespace TangramCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Win32AppForm
	/// </summary>
	public ref class Win32AppForm : public System::Windows::Forms::Form
	{
	public:
		Win32AppForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Win32AppForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// Win32AppForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(812, 509);
			this->Name = L"Win32AppForm";
			this->Text = L"Default Form for Win32 App";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Win32AppForm::Win32AppForm_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Win32AppForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		System::Windows::Forms::Application::Exit();
	}
	};
}
