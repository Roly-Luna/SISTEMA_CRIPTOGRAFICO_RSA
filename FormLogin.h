#pragma once

namespace SISTEMACRIPTOGRAFICORSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormLogin : public System::Windows::Forms::Form
	{
	public:
		FormLogin(void)
		{
			InitializeComponent();
		}

	protected:
		~FormLogin()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblUsuario;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::Label^ lblContrasena;
	private: System::Windows::Forms::TextBox^ txtContrasena;
	private: System::Windows::Forms::Button^ btnIngresar;
	private: System::Windows::Forms::Button^ btnSalir;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblUsuario = (gcnew System::Windows::Forms::Label());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->lblContrasena = (gcnew System::Windows::Forms::Label());
			this->txtContrasena = (gcnew System::Windows::Forms::TextBox());
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			// lblTitulo
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTitulo->Location = System::Drawing::Point(60, 20);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(170, 24);
			this->lblTitulo->Text = L"INICIO DE SESIÓN";

			// lblUsuario
			this->lblUsuario->AutoSize = true;
			this->lblUsuario->Location = System::Drawing::Point(40, 70);
			this->lblUsuario->Name = L"lblUsuario";
			this->lblUsuario->Size = System::Drawing::Size(46, 13);
			this->lblUsuario->Text = L"Usuario:";

			// txtUsuario
			this->txtUsuario->Location = System::Drawing::Point(40, 90);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(200, 20);

			// lblContrasena
			this->lblContrasena->AutoSize = true;
			this->lblContrasena->Location = System::Drawing::Point(40, 130);
			this->lblContrasena->Name = L"lblContrasena";
			this->lblContrasena->Size = System::Drawing::Size(64, 13);
			this->lblContrasena->Text = L"Contraseña:";

			// txtContrasena
			this->txtContrasena->Location = System::Drawing::Point(40, 150);
			this->txtContrasena->Name = L"txtContrasena";
			this->txtContrasena->PasswordChar = '*'; // Oculta la contraseña
			this->txtContrasena->Size = System::Drawing::Size(200, 20);

			// btnIngresar
			this->btnIngresar->BackColor = System::Drawing::Color::SeaGreen;
			this->btnIngresar->ForeColor = System::Drawing::Color::White;
			this->btnIngresar->Location = System::Drawing::Point(40, 200);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(90, 30);
			this->btnIngresar->Text = L"Ingresar";
			this->btnIngresar->UseVisualStyleBackColor = false;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &FormLogin::btnIngresar_Click);

			// btnSalir
			this->btnSalir->BackColor = System::Drawing::Color::Brown;
			this->btnSalir->ForeColor = System::Drawing::Color::White;
			this->btnSalir->Location = System::Drawing::Point(150, 200);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(90, 30);
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FormLogin::btnSalir_Click);

			// FormLogin
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnIngresar);
			this->Controls->Add(this->txtContrasena);
			this->Controls->Add(this->lblContrasena);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->lblUsuario);
			this->Controls->Add(this->lblTitulo);
			this->Name = L"FormLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Acceso";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = txtUsuario->Text;
		String^ password = txtContrasena->Text;

		// Validacion de los dos usuarios permitidos
		if ((usuario == "USUARIO1" && password == "123") || (usuario == "USUARIO2" && password == "123")) {
			MessageBox::Show("Bienvenido al sistema RSA, " + usuario + ".", "Acceso Concedido", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Si es correcto, le decimos al programa principal que todo salio bien (OK) y cerramos el login
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else {
			MessageBox::Show("Usuario o contraseña incorrectos.", "Acceso Denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			txtContrasena->Text = ""; // Limpia la contraseña para intentar de nuevo
		}
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}