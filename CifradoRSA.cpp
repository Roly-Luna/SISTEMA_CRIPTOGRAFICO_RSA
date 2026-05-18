#include "CifradoRSA.h"

long long CifradoRSA::exponenciacion_modular(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

map<char, int> CifradoRSA::generar_diccionario() {
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    map<char, int> diccionario_letras;
    int contador = 0;
    for (char letra : alfabeto) {
        diccionario_letras[letra] = contador;
        contador++;
    }
    return diccionario_letras;
}

vector<long long> CifradoRSA::encriptar_texto(string texto, int e, int n, map<char, int> diccionario) {
    string texto_mayusculas = "";
    for (char c : texto) {
        texto_mayusculas += toupper(c);
    }

    string texto_limpio = "";
    for (char caracter : texto_mayusculas) {
        if (diccionario.find(caracter) != diccionario.end()) {
            texto_limpio += caracter;
        }
    }

    vector<long long> lista_cifrada;
    for (char caracter : texto_limpio) {
        long long numero_base = diccionario[caracter];
        long long valor_cifrado = exponenciacion_modular(numero_base, e, n);
        lista_cifrada.push_back(valor_cifrado);
    }

    return lista_cifrada;
}