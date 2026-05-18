#include "FormPrincipal.h"

using namespace System;
using namespace System::Windows::Forms;

[System::STAThreadAttribute]
// agregamos cli:: a array
int main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Inicia el formulario principal
    SISTEMACRIPTOGRAFICORSA::FormPrincipal form;
    Application::Run(% form);

    return 0;
}