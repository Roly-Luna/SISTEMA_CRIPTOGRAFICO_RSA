#pragma once

// Incluimos los formularios a los que vamos a saltar
#include "FormEncriptar.h"
#include "FormDesencriptar.h"

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

		// Declaración de los elementos de la interfaz
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Button^ btnEncriptar;
	private: System::Windows::Forms::Button^ btnDesencriptar;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnSalir;

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
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->btnEncriptar = (gcnew System::Windows::Forms::Button());
			this->btnDesencriptar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Adobe Devanagari", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::Red;
			this->lblTitulo->Location = System::Drawing::Point(110, 40);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(510, 50);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"SISTEMA CRIPTOGRÁFICO RSA";
			// 
			// btnEncriptar
			// 
			this->btnEncriptar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnEncriptar->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEncriptar->ForeColor = System::Drawing::Color::White;
			this->btnEncriptar->Location = System::Drawing::Point(220, 110);
			this->btnEncriptar->Name = L"btnEncriptar";
			this->btnEncriptar->Size = System::Drawing::Size(260, 60);
			this->btnEncriptar->TabIndex = 1;
			this->btnEncriptar->Text = L"ENCRIPTAR MENSAJE";
			this->btnEncriptar->UseVisualStyleBackColor = false;
			this->btnEncriptar->Click += gcnew System::EventHandler(this, &FormPrincipal::btnEncriptar_Click);
			// 
			// btnDesencriptar
			// 
			this->btnDesencriptar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnDesencriptar->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDesencriptar->ForeColor = System::Drawing::Color::White;
			this->btnDesencriptar->Location = System::Drawing::Point(155, 185);
			this->btnDesencriptar->Name = L"btnDesencriptar";
			this->btnDesencriptar->Size = System::Drawing::Size(381, 60);
			this->btnDesencriptar->TabIndex = 2;
			this->btnDesencriptar->Text = L"DESENCRIPTAR DESDE ARCHIVO";
			this->btnDesencriptar->UseVisualStyleBackColor = false;
			this->btnDesencriptar->Click += gcnew System::EventHandler(this, &FormPrincipal::btnDesencriptar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->ForeColor = System::Drawing::Color::White;
			this->btnInstrucciones->Location = System::Drawing::Point(262, 262);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(194, 60);
			this->btnInstrucciones->TabIndex = 3;
			this->btnInstrucciones->Text = L"INSTRUCCIONES";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FormPrincipal::btnInstrucciones_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Maroon;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::Color::White;
			this->btnSalir->Location = System::Drawing::Point(220, 337);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(280, 60);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"SALIR DEL SISTEMA";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FormPrincipal::btnSalir_Click);
			// 
			// FormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(724, 488);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->btnEncriptar);
			this->Controls->Add(this->btnDesencriptar);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnSalir);
			this->Name = L"FormPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menú Principal - RSA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// EVENTOS DE LOS BOTONES
	private: System::Void btnEncriptar_Click(System::Object^ sender, System::EventArgs^ e) {
		FormEncriptar^ formEnc = gcnew FormEncriptar();
		formEnc->Show();
		this->Hide(); // Oculta el menú principal temporalmente
	}

	private: System::Void btnDesencriptar_Click(System::Object^ sender, System::EventArgs^ e) {
		FormDesencriptar^ formDes = gcnew FormDesencriptar();
		formDes->Show();
		this->Hide(); // Oculta el menú principal temporalmente
	}

	private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("1. Para ENCRIPTAR:\n- Ingresa el texto.\n- Ingresa números primos válidos.\n- Sigue los pasos para elegir claves.\n\n2. Para DESENCRIPTAR:\n- Selecciona el archivo de texto y usa tu clave privada.",
			"Instrucciones del Sistema RSA", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit(); // Cierra el programa completamente
	}
	};
}