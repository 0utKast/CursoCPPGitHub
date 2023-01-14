
#if 0

#include <experimental/generator>
#include <chrono>
#include <iostream>

std::experimental::generator<int> getGeneradorSecuencia( int ValorInicial, int numeroDeValores)
{
	for (int i{ ValorInicial }; i < ValorInicial + numeroDeValores; ++i) {
		//Imprimir la hora local a la salida estándar
		std::time_t tt{ std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) };
		std::tm t;
		localtime_s(&t, &tt);
		std::cout << std::put_time(&t, "%H:%M:%S") << ": ";
		// Enviar un valor al llamador y pausar la rutina.
		co_yield i;
	}
}

int main()
{
	auto gen{ getGeneradorSecuencia(10, 5) };


	//std::experimental::generator<int> gen{ getGeneradorSecuencia(10, 5) };



	for (const auto& valor : gen) {
		std::cout << valor << " (Pulsa enter para el siguiente valor)";
		std::cin.ignore();
	}
}





#include <experimental/generator>
#include <chrono>
#include <iostream>

std::experimental::generator<int> getGeneradorSecuencia(int ValorInicial, int numeroDeValores)
{
	for (int i{ ValorInicial }; i < ValorInicial + numeroDeValores; ++i) {
		//Imprimir la hora local a la salida estándar
		std::time_t tt{ std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) };
		std::tm t;
		localtime_s(&t, &tt);
		std::cout << std::put_time(&t, "%H:%M:%S") << ": ";
		// Enviar un valor al llamador y pausar la rutina.
		co_yield i;
	}
}

int main()
{
	std::experimental::generator<int> gen{ getGeneradorSecuencia(10, 5) };
	for (const auto& valor : gen) {
		std::cout << valor << " (Pulsa v para el siguiente valor)";
		char c;
		std::cin >> c;
		if (c != 'v')
			continue;
	}
}



#include <experimental/generator>
#include <chrono>
#include <iostream>
#include <conio.h>

std::experimental::generator<int> getGeneradorSecuencia(int ValorInicial, int numeroDeValores)
{
	for (int i{ ValorInicial }; i < ValorInicial + numeroDeValores; ++i) {
		//Imprimir la hora local a la salida estándar
		std::time_t tt{ std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) };
		std::tm t;
		localtime_s(&t, &tt);
		std::cout << std::put_time(&t, "%H:%M:%S") << ": ";
		// Enviar un valor al llamador y pausar la rutina.
		co_yield i;
	}
}

int main()
{
	std::experimental::generator<int> gen{ getGeneradorSecuencia(10, 5) };
	for (const auto& valor : gen) {
		std::cout << valor << " (Pulsa v para el siguiente valor)" << std::endl;
		char c = _getch();
		if (c != 'v')
			continue;
	}
}








#include <iostream>
#include <experimental/generator>

std::experimental::generator<int> pares(int inicio, int fin) {
	for (int i = inicio; i <= fin; ++i) {
		if (i % 2 == 0) {
			co_yield i;
		}
	}
}

int main() {
	for (int i : pares(0, 10)) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
#endif



#include <iostream>
#include <experimental/generator>

std::experimental::generator<int> pares(int inicio, int fin) {
	int i = inicio;
	while (i <= fin) {
		if (i % 2 == 0) {
			std::cout << "Presione Enter para continuar: ";
			std::cin.get();
			co_yield i;
		}
		++i;
	}
}

int main() {
	for (int i : pares(0, 10)) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}





