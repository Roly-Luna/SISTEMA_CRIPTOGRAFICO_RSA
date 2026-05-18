#pragma once

#include "MatematicaRSA.h"
#include "CifradoRSA.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>

namespace SISTEMACRIPTOGRAFICORSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class FormEncriptar : public System::Windows::Forms::Form
	{
	public:
		FormEncriptar(void)
		{
			InitializeComponent();
		}

	protected:
		~FormEncriptar()
		{
			if (components)
			{
				delete components;
			}
		}

		// Declaracion de controles de la UI
	private: System::Windows::Forms::Label^ lblMensaje;
	private: System::Windows::Forms::TextBox^ txtMensaje;
	private: System::Windows::Forms::Label^ lblPrimos;
	private: System::Windows::Forms::TextBox^ txtP;
	private: System::Windows::Forms::TextBox^ txtQ;
	private: System::Windows::Forms::Button^ btnCalcularMatematica;
	private: System::Windows::Forms::Label^ lblDetalles;
	private: System::Windows::Forms::Label^ lblE;
	private: System::Windows::Forms::ComboBox^ comboE;
	private: System::Windows::Forms::Label^ lblD;
	private: System::Windows::Forms::ComboBox^ comboD;
	private: System::Windows::Forms::Button^ btnEncriptar;
	private: System::Windows::Forms::TextBox^ txtResultado;
	private: System::Windows::Forms::Button^ btnGuardarTxt;
	private: System::Windows::Forms::Button^ btnVolver;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblMensaje = (gcnew System::Windows::Forms::Label());
			this->txtMensaje = (gcnew System::Windows::Forms::TextBox());
			this->lblPrimos = (gcnew System::Windows::Forms::Label());
			this->txtP = (gcnew System::Windows::Forms::TextBox());
			this->txtQ = (gcnew System::Windows::Forms::TextBox());
			this->btnCalcularMatematica = (gcnew System::Windows::Forms::Button());
			this->lblDetalles = (gcnew System::Windows::Forms::Label());
			this->lblE = (gcnew System::Windows::Forms::Label());
			this->comboE = (gcnew System::Windows::Forms::ComboBox());
			this->lblD = (gcnew System::Windows::Forms::Label());
			this->comboD = (gcnew System::Windows::Forms::ComboBox());
			this->btnEncriptar = (gcnew System::Windows::Forms::Button());
			this->txtResultado = (gcnew System::Windows::Forms::TextBox());
			this->btnGuardarTxt = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblMensaje
			// 
			this->lblMensaje->AutoSize = true;
			this->lblMensaje->Location = System::Drawing::Point(20, 20);
			this->lblMensaje->Name = L"lblMensaje";
			this->lblMensaje->Size = System::Drawing::Size(147, 13);
			this->lblMensaje->TabIndex = 14;
			this->lblMensaje->Text = L"1. Ingrese el texto a encriptar:";
			// 
			// txtMensaje
			// 
			this->txtMensaje->Location = System::Drawing::Point(20, 40);
			this->txtMensaje->Name = L"txtMensaje";
			this->txtMensaje->Size = System::Drawing::Size(440, 20);
			this->txtMensaje->TabIndex = 13;
			// 
			// lblPrimos
			// 
			this->lblPrimos->AutoSize = true;
			this->lblPrimos->Location = System::Drawing::Point(20, 80);
			this->lblPrimos->Name = L"lblPrimos";
			this->lblPrimos->Size = System::Drawing::Size(272, 13);
			this->lblPrimos->TabIndex = 12;
			this->lblPrimos->Text = L"2. Ingrese dos números primos (1 o 2 cifras) para \'p\' y \'q\':";
			// 
			// txtP
			// 
			this->txtP->Location = System::Drawing::Point(20, 100);
			this->txtP->Name = L"txtP";
			this->txtP->Size = System::Drawing::Size(60, 20);
			this->txtP->TabIndex = 11;
			// 
			// txtQ
			// 
			this->txtQ->Location = System::Drawing::Point(100, 100);
			this->txtQ->Name = L"txtQ";
			this->txtQ->Size = System::Drawing::Size(60, 20);
			this->txtQ->TabIndex = 10;
			// 
			// btnCalcularMatematica
			// 
			this->btnCalcularMatematica->Location = System::Drawing::Point(180, 98);
			this->btnCalcularMatematica->Name = L"btnCalcularMatematica";
			this->btnCalcularMatematica->Size = System::Drawing::Size(120, 25);
			this->btnCalcularMatematica->TabIndex = 9;
			this->btnCalcularMatematica->Text = L"Calcular n y phi";
			this->btnCalcularMatematica->UseVisualStyleBackColor = true;
			this->btnCalcularMatematica->Click += gcnew System::EventHandler(this, &FormEncriptar::btnCalcularMatematica_Click);
			// 
			// lblDetalles
			// 
			this->lblDetalles->AutoSize = true;
			this->lblDetalles->Location = System::Drawing::Point(20, 140);
			this->lblDetalles->Name = L"lblDetalles";
			this->lblDetalles->Size = System::Drawing::Size(150, 13);
			this->lblDetalles->TabIndex = 8;
			this->lblDetalles->Text = L"Modulo n: -- | Funcion phi(n): --";
			// 
			// lblE
			// 
			this->lblE->AutoSize = true;
			this->lblE->Location = System::Drawing::Point(20, 180);
			this->lblE->Name = L"lblE";
			this->lblE->Size = System::Drawing::Size(119, 13);
			this->lblE->TabIndex = 7;
			this->lblE->Text = L"3. Seleccione clave (e):";
			// 
			// comboE
			// 
			this->comboE->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboE->Enabled = false;
			this->comboE->Location = System::Drawing::Point(20, 200);
			this->comboE->Name = L"comboE";
			this->comboE->Size = System::Drawing::Size(120, 21);
			this->comboE->TabIndex = 6;
			this->comboE->SelectedIndexChanged += gcnew System::EventHandler(this, &FormEncriptar::comboE_SelectedIndexChanged);
			// 
			// lblD
			// 
			this->lblD->AutoSize = true;
			this->lblD->Location = System::Drawing::Point(160, 180);
			this->lblD->Name = L"lblD";
			this->lblD->Size = System::Drawing::Size(119, 13);
			this->lblD->TabIndex = 5;
			this->lblD->Text = L"4. Seleccione clave (d):";
			// 
			// comboD
			// 
			this->comboD->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboD->Enabled = false;
			this->comboD->Location = System::Drawing::Point(160, 200);
			this->comboD->Name = L"comboD";
			this->comboD->Size = System::Drawing::Size(120, 21);
			this->comboD->TabIndex = 4;
			// 
			// btnEncriptar
			// 
			this->btnEncriptar->Location = System::Drawing::Point(20, 240);
			this->btnEncriptar->Name = L"btnEncriptar";
			this->btnEncriptar->Size = System::Drawing::Size(440, 30);
			this->btnEncriptar->TabIndex = 3;
			this->btnEncriptar->Text = L"ENCRIPTAR MENSAJE";
			this->btnEncriptar->UseVisualStyleBackColor = true;
			this->btnEncriptar->Click += gcnew System::EventHandler(this, &FormEncriptar::btnEncriptar_Click);
			// 
			// txtResultado
			// 
			this->txtResultado->Location = System::Drawing::Point(20, 280);
			this->txtResultado->Multiline = true;
			this->txtResultado->Name = L"txtResultado";
			this->txtResultado->ReadOnly = true;
			this->txtResultado->Size = System::Drawing::Size(440, 80);
			this->txtResultado->TabIndex = 2;
			// 
			// btnGuardarTxt
			// 
			this->btnGuardarTxt->Enabled = false;
			this->btnGuardarTxt->Location = System::Drawing::Point(20, 370);
			this->btnGuardarTxt->Name = L"btnGuardarTxt";
			this->btnGuardarTxt->Size = System::Drawing::Size(150, 30);
			this->btnGuardarTxt->TabIndex = 1;
			this->btnGuardarTxt->Text = L"Guardar en TXT";
			this->btnGuardarTxt->UseVisualStyleBackColor = true;
			this->btnGuardarTxt->Click += gcnew System::EventHandler(this, &FormEncriptar::btnGuardarTxt_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(310, 370);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(150, 30);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->Text = L"Volver al Menú";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FormEncriptar::btnVolver_Click);
			// 
			// FormEncriptar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(490, 420);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->btnGuardarTxt);
			this->Controls->Add(this->txtResultado);
			this->Controls->Add(this->btnEncriptar);
			this->Controls->Add(this->comboD);
			this->Controls->Add(this->lblD);
			this->Controls->Add(this->comboE);
			this->Controls->Add(this->lblE);
			this->Controls->Add(this->lblDetalles);
			this->Controls->Add(this->btnCalcularMatematica);
			this->Controls->Add(this->txtQ);
			this->Controls->Add(this->txtP);
			this->Controls->Add(this->lblPrimos);
			this->Controls->Add(this->txtMensaje);
			this->Controls->Add(this->lblMensaje);
			this->Name = L"FormEncriptar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fase de Encriptacion RSA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Variables globales del formulario
		int n_global;
		int phi_global;

	private: System::Void btnCalcularMatematica_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int p = System::Convert::ToInt32(txtP->Text);
			int q = System::Convert::ToInt32(txtQ->Text);

			if (p > 99 || q > 99) {
				MessageBox::Show("Los números deben ser de 1 o 2 cifras máximo.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			if (!MatematicaRSA::es_primo(p) || !MatematicaRSA::es_primo(q)) {
				MessageBox::Show("Rechazado: Ambos números deben ser primos. Corrige la entrada.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (p == q) {
				MessageBox::Show("Los números primos deben ser diferentes entre sí.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			n_global = p * q;
			phi_global = (p - 1) * (q - 1);

			if (n_global <= 26) {
				MessageBox::Show("El modulo n (" + n_global + ") es muy pequeño. Debe ser mayor a 26. Intenta con primos más grandes.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			lblDetalles->Text = "Modulo n: " + n_global + " | Funcion phi(n): " + phi_global;

			// Cargar opciones de 'e'
			std::vector<int> opciones_e = MatematicaRSA::obtener_posibles_e(phi_global);
			comboE->Items->Clear();
			for (int val : opciones_e) {
				comboE->Items->Add(val);
			}
			comboE->Enabled = true;
			comboD->Items->Clear();
			comboD->Enabled = false;

			MessageBox::Show("Cálculos exitosos. Ahora selecciona la clave pública 'e'.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (Exception^) {
			MessageBox::Show("Por favor, ingresa valores numéricos enteros válidos.", "Error de Formato", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void comboE_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboE->SelectedItem != nullptr) {
			int e_val = System::Convert::ToInt32(comboE->SelectedItem);

			// Cargar opciones de 'd'
			std::vector<int> opciones_d = MatematicaRSA::obtener_posibles_d(e_val, phi_global);
			comboD->Items->Clear();
			for (int val : opciones_d) {
				comboD->Items->Add(val);
			}
			comboD->Enabled = true;
		}
	}

	private: System::Void btnEncriptar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtMensaje->Text == "") {
			MessageBox::Show("El mensaje no puede estar vacío.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (comboE->SelectedItem == nullptr || comboD->SelectedItem == nullptr) {
			MessageBox::Show("Debes seleccionar las claves 'e' y 'd' primero.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		std::string texto_ingresado = msclr::interop::marshal_as<std::string>(txtMensaje->Text);
		int e_val = System::Convert::ToInt32(comboE->SelectedItem);

		std::map<char, int> diccionario = CifradoRSA::generar_diccionario();
		std::vector<long long> resultado = CifradoRSA::encriptar_texto(texto_ingresado, e_val, n_global, diccionario);

		System::String^ texto_salida = "";
		for (long long num : resultado) {
			texto_salida += num.ToString() + " ";
		}

		txtResultado->Text = texto_salida;
		btnGuardarTxt->Enabled = true;
	}

	private: System::Void btnGuardarTxt_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		sfd->Filter = "Archivos de texto (*.txt)|*.txt";
		sfd->Title = "Guardar Mensaje Encriptado";

		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
			sw->WriteLine("=== SISTEMA RSA ===");
			sw->WriteLine("Mensaje Cifrado: " + txtResultado->Text);
			sw->WriteLine("Clave Privada sugerida (d): " + comboD->SelectedItem->ToString());
			sw->WriteLine("Modulo (n): " + n_global.ToString());
			sw->Close();
			MessageBox::Show("¡Archivo guardado con éxito! Ya puedes compartirlo.", "Guardado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		// Busca el FormPrincipal abierto y lo vuelve a mostrar
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