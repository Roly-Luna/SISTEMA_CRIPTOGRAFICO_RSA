#pragma once
#include "Recursos.h"

// clase mate
class MatematicaRSA {
public:
    static bool es_primo(int numero);
    static int calcular_mcd(int a, int b);
    static vector<int> obtener_posibles_e(int phi);
    static int algoritmo_euclides_extendido(int e, int phi);
    static vector<int> obtener_posibles_d(int e, int phi);
};