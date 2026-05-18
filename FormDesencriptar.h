#pragma once

#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <vector>
#include <string>

namespace SISTEMACRIPTOGRAFICORSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class FormDesencriptar : public System::Windows::Forms::Form
	{
	public:
		FormDesencriptar(void)
		{
			InitializeComponent();
		}

	protected:
		~FormDesencriptar()
		{
			if (components)
			{
				delete components;
			}
		}

		// Controles de la Interfaz
	private: System::Windows::Forms::Label^ lblInstruccion1;
	private: System::Windows::Forms::TextBox^ txtMensajeCifrado;
	private: System::Windows::Forms::Button^ btnCargarTxt;
	private: System::Windows::Forms::Label^ lblClaveD;
	private: System::Windows::Forms::TextBox^ txtD;
	private: System::Windows::Forms::Label^ lblModuloN;
	private: System::Windows::Forms::TextBox^ txtN;
	private: System::Windows::Forms::Button^ btnDesencriptar;
	private: System::Windows::Forms::Label^ lblResultado;
	private: System::Windows::Forms::TextBox^ txtResultado;
	private: System::Windows::Forms::Button^ btnVolver;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblInstruccion1 = (gcnew System::Windows::Forms::Label());
			this->txtMensajeCifrado = (gcnew System::Windows::Forms::TextBox());
			this->btnCargarTxt = (gcnew System::Windows::Forms::Button());
			this->lblClaveD = (gcnew System::Windows::Forms::Label());
			this->txtD = (gcnew System::Windows::Forms::TextBox());
			this->lblModuloN = (gcnew System::Windows::Forms::Label());
			this->txtN = (gcnew System::Windows::Forms::TextBox());
			this->btnDesencriptar = (gcnew System::Windows::Forms::Button());
			this->lblResultado = (gcnew System::Windows::Forms::Label());
			this->txtResultado = (gcnew System::Windows::Forms::TextBox());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			// lblInstruccion1
			this->lblInstruccion1->AutoSize = true;
			this->lblInstruccion1->Location = System::Drawing::Point(20, 20);
			this->lblInstruccion1->Name = L"lblInstruccion1";
			this->lblInstruccion1->Size = System::Drawing::Size(300, 13);
			this->lblInstruccion1->Text = L"1. Pegue el mensaje cifrado (números) o cargue el archivo TXT:";

			// txtMensajeCifrado
			this->txtMensajeCifrado->Location = System::Drawing::Point(20, 40);
			this->txtMensajeCifrado->Multiline = true;
			this->txtMensajeCifrado->Name = L"txtMensajeCifrado";
			this->txtMensajeCifrado->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtMensajeCifrado->Size = System::Drawing::Size(330, 80);

			// btnCargarTxt
			this->btnCargarTxt->Location = System::Drawing::Point(370, 40);
			this->btnCargarTxt->Name = L"btnCargarTxt";
			this->btnCargarTxt->Size = System::Drawing::Size(120, 30);
			this->btnCargarTxt->Text = L"Cargar TXT";
			this->btnCargarTxt->UseVisualStyleBackColor = true;
			this->btnCargarTxt->Click += gcnew System::EventHandler(this, &FormDesencriptar::btnCargarTxt_Click);

			// lblClaveD
			this->lblClaveD->AutoSize = true;
			this->lblClaveD->Location = System::Drawing::Point(20, 140);
			this->lblClaveD->Name = L"lblClaveD";
			this->lblClaveD->Size = System::Drawing::Size(130, 13);
			this->lblClaveD->Text = L"2. Ingrese Clave Privada (d):";

			// txtD
			this->txtD->Location = System::Drawing::Point(20, 160);
			this->txtD->Name = L"txtD";
			this->txtD->Size = System::Drawing::Size(100, 20);

			// lblModuloN
			this->lblModuloN->AutoSize = true;
			this->lblModuloN->Location = System::Drawing::Point(180, 140);
			this->lblModuloN->Name = L"lblModuloN";
			this->lblModuloN->Size = System::Drawing::Size(110, 13);
			this->lblModuloN->Text = L"3. Ingrese Módulo (n):";

			// txtN
			this->txtN->Location = System::Drawing::Point(180, 160);
			this->txtN->Name = L"txtN";
			this->txtN->Size = System::Drawing::Size(100, 20);

			// btnDesencriptar
			this->btnDesencriptar->BackColor = System::Drawing::Color::SeaGreen;
			this->btnDesencriptar->ForeColor = System::Drawing::Color::White;
			this->btnDesencriptar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnDesencriptar->Location = System::Drawing::Point(20, 200);
			this->btnDesencriptar->Name = L"btnDesencriptar";
			this->btnDesencriptar->Size = System::Drawing::Size(470, 35);
			this->btnDesencriptar->Text = L"DESENCRIPTAR MENSAJE";
			this->btnDesencriptar->UseVisualStyleBackColor = false;
			this->btnDesencriptar->Click += gcnew System::EventHandler(this, &FormDesencriptar::btnDesencriptar_Click);

			// lblResultado
			this->lblResultado->AutoSize = true;
			this->lblResultado->Location = System::Drawing::Point(20, 250);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(93, 13);
			this->lblResultado->Text = L"Mensaje Original:";

			// txtResultado
			this->txtResultado->Location = System::Drawing::Point(20, 270);
			this->txtResultado->Multiline = true;
			this->txtResultado->Name = L"txtResultado";
			this->txtResultado->ReadOnly = true;
			this->txtResultado->Size = System::Drawing::Size(470, 60);

			// btnVolver
			this->btnVolver->Location = System::Drawing::Point(370, 350);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(120, 30);
			this->btnVolver->Text = L"Volver al Menú";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FormDesencriptar::btnVolver_Click);

			// FormDesencriptar
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 400);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->txtResultado);
			this->Controls->Add(this->lblResultado);
			this->Controls->Add(this->btnDesencriptar);
			this->Controls->Add(this->txtN);
			this->Controls->Add(this->lblModuloN);
			this->Controls->Add(this->txtD);
			this->Controls->Add(this->lblClaveD);
			this->Controls->Add(this->btnCargarTxt);
			this->Controls->Add(this->txtMensajeCifrado);
			this->Controls->Add(this->lblInstruccion1);
			this->Name = L"FormDesencriptar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fase de Desencriptación RSA";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// Funcion matematica para desencriptar M = C^d mod n
	private: long long exponenciacion_modular(long long base, long long exp, long long mod) {
		long long res = 1;
		base = base % mod;
		while (exp > 0) {
			if (exp % 2 == 1) res = (res * base) % mod;
			exp = exp >> 1;
			base = (base * base) % mod;
		}
		return res;
	}

	private: System::Void btnCargarTxt_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Archivos de texto (*.txt)|*.txt";
		ofd->Title = "Seleccionar Archivo Encriptado";

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				StreamReader^ sr = gcnew StreamReader(ofd->FileName);
				String^ contenido = sr->ReadToEnd();
				sr->Close();

				txtMensajeCifrado->Text = contenido;
				MessageBox::Show("Archivo cargado. Asegúrate de borrar el texto innecesario y dejar solo los NÚMEROS en la primera caja. Luego ingresa 'd' y 'n' en sus casillas.", "Instrucción", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^) {
				MessageBox::Show("Error al intentar leer el archivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void btnDesencriptar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtMensajeCifrado->Text == "" || txtD->Text == "" || txtN->Text == "") {
			MessageBox::Show("Todos los campos son obligatorios.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			long long d_val = System::Convert::ToInt64(txtD->Text);
			long long n_val = System::Convert::ToInt64(txtN->Text);

			cli::array<String^>^ numerosStr = txtMensajeCifrado->Text->Split(gcnew cli::array<Char>{' ', '\n', '\r', '\t'}, StringSplitOptions::RemoveEmptyEntries);

			String^ alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
			String^ mensajeOriginal = "";

			for each (String ^ numStr in numerosStr) {
				long long c_val = System::Convert::ToInt64(numStr);

				// Aplicar RSA: M = C^d mod n
				long long m_val = exponenciacion_modular(c_val, d_val, n_val);

				// Revertir diccionario
				if (m_val >= 0 && m_val < alfabeto->Length) {
					mensajeOriginal += alfabeto[(int)m_val];
				}
				else {
					mensajeOriginal += "?"; // En caso de que el cálculo falle o las claves sean incorrectas
				}
			}

			txtResultado->Text = mensajeOriginal;

		}
		catch (Exception^) {
			MessageBox::Show("Error en el formato. Asegúrate de que el mensaje cifrado contenga SOLO números separados por espacios, y que 'd' y 'n' sean valores numéricos correctos.", "Error de Desencriptación", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (Form ^ form in Application::OpenForms) {
			if (form->Name == "FormPrincipal") {
				form->Show();
				break;
			}
		}
		this->Close();
	}
	};
}