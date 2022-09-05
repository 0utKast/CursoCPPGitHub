#include <iostream>
#include "Array.h"

int main()
{
	Array<int> intArray{ 14 };
	Array<double> doubleArray{ 14 };

	for (int contador{ 0 }; contador < intArray.getLongit(); ++contador)
	{
		intArray[contador] = contador;
		doubleArray[contador] = contador + 0.5;
	}

	for (int contador{ intArray.getLongit() - 1 }; contador >= 0; --contador)
		std::cout << intArray[contador] << '\t' << doubleArray[contador] << '\n';

	return 0;
}





