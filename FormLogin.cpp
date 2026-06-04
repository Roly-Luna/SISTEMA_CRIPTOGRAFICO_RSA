#include "FormPrincipal.h"
#include "FormLogin.h"

using namespace System;
using namespace System::Windows::Forms;

[System::STAThreadAttribute]
int main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Iniciamos primero el formulario de Login
    SISTEMACRIPTOGRAFICORSA::FormLogin login;

    // Si el login responde que todo esta "OK" (contraseña correcta)...
    if (login.ShowDialog() == DialogResult::OK) {
        SISTEMACRIPTOGRAFICORSA::FormPrincipal formMain;
        Application::Run(% formMain);
    }

    return 0;
}