// Singleton.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include "logger.h"
#include <iostream>

void func(int* p) {
	if (!p) {
		Logger::instance().logError(" Puntero NULL inesperado");
	}
	else {
		Logger::instance().logInfo("Puntero es válido");
	}
}

int main() {
	int* p1 = nullptr;
	int x = 5;
	int* p2 = &x;

	func(p1);
	func(p2);

	std::cout << "Contador Errores: " << Logger::instance().getErrorCount() << std::endl;
	std::cout << "Contador advertencias: " << Logger::instance().getWarningCount() << std::endl;
	std::cout << "Contador info: " << Logger::instance().getInfoCount() << std::endl;

	return 0;
}