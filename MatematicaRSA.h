#pragma once
#include "Recursos.h"

// Verificar si un numero es primo: Big O(sqrt(n))
bool esPrimo(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 9) return false;

	// solo verificar hasta sqrt(n):
	int limite = sqrt(n);
	for (int i = 3; i < limite; i+=2)
	{
		if (n % i == 0) return false;
	}
	return true;
}

