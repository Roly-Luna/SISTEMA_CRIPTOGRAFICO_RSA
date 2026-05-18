#pragma once

namespace SISTEMACRIPTOGRAFICORSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormPrincipal
	/// </summary>
	public ref class FormPrincipal : public System::Windows::Forms::Form
	{
	public:
		FormPrincipal(void)
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
		~FormPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Sistema_RSA;
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
			this->btn_Sistema_RSA = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_Sistema_RSA
			// 
			this->btn_Sistema_RSA->BackColor = System::Drawing::Color::Blue;
			this->btn_Sistema_RSA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Sistema_RSA->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_Sistema_RSA->Location = System::Drawing::Point(133, 178);
			this->btn_Sistema_RSA->Name = L"btn_Sistema_RSA";
			this->btn_Sistema_RSA->Size = System::Drawing::Size(321, 86);
			this->btn_Sistema_RSA->TabIndex = 0;
			this->btn_Sistema_RSA->Text = L"SISTEMA RSA";
			this->btn_Sistema_RSA->UseVisualStyleBackColor = false;
			// 
			// FormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 488);
			this->Controls->Add(this->btn_Sistema_RSA);
			this->Name = L"FormPrincipal";
			this->Text = L"FormPrincipal";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
