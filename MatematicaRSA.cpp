#include "MatematicaRSA.h"

bool MatematicaRSA::es_primo(int numero) {
    if (numero < 2) return false;
    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

int MatematicaRSA::calcular_mcd(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

vector<int> MatematicaRSA::obtener_posibles_e(int phi) {
    vector<int> lista_opciones_e;
    for (int i = 2; i < phi; i++) {
        if (calcular_mcd(i, phi) == 1) {
            lista_opciones_e.push_back(i);
            // Limitamos a 10 opciones para no saturar la interfaz gráfica
            if (lista_opciones_e.size() == 10) break;
        }
    }
    return lista_opciones_e;
}

int MatematicaRSA::algoritmo_euclides_extendido(int e, int phi) {
    int d = 0, d_anterior = 1;
    int r = phi, r_anterior = e;

    while (r != 0) {
        int cociente = r_anterior / r;

        int r_temporal = r;
        r = r_anterior - (cociente * r);
        r_anterior = r_temporal;

        int d_temporal = d;
        d = d_anterior - (cociente * d);
        d_anterior = d_temporal;
    }

    if (d_anterior < 0) {
        d_anterior = d_anterior + phi;
    }
    return d_anterior;
}

vector<int> MatematicaRSA::obtener_posibles_d(int e, int phi) {
    int valor_d_base = algoritmo_euclides_extendido(e, phi);
    vector<int> lista_opciones_d = { valor_d_base, valor_d_base + phi, valor_d_base + (2 * phi) };
    return lista_opciones_d;
}