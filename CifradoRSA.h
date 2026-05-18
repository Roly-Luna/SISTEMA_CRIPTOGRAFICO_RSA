#pragma once
#include "Recursos.h"

class CifradoRSA {
private:
    // Función de exponenciación modular para evitar el desbordamiento de memoria en C++
    static long long exponenciacion_modular(long long base, long long exp, long long mod);
public:
    static map<char, int> generar_diccionario();
    static vector<long long> encriptar_texto(string texto, int e, int n, map<char, int> diccionario);
};