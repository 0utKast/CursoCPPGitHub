#include "Euros.h"
#include <iostream>

int main()
{
	Euros euros1{ 7 };
	Euros euros2{ 3 };
	//sin el prototipo en Euros.h, esto dar�a error de compilaci�n
	Euros sumarEuros{ euros1 + euros2 }; 
	std::cout << "Tengo " << sumarEuros.getEuros() << " euros.\n";

	return 0;
}