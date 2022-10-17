#if 0

int x{ 5 };
int& lref{ x }; // referencia l-value inicializada con el valor l-value x
int&& rref{ 5 }; // referencia r-value inicializada con el r-value 5





#include <iostream>

class Fraccion
{
private:
	int m_numerador;
	int m_denominador;

public:
	Fraccion(int numerador = 0, int denominador = 1) :
		m_numerador{ numerador }, m_denominador{ denominador }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
	{
		out << f1.m_numerador << '/' << f1.m_denominador;
		return out;
	}
};

int main()
{
	auto&& rref{ Fraccion{ 3, 5 } }; // referencia r-value a Fracción temporal

	// f1 del operator<< se vincula al temporal, no se crean copias.
	std::cout << rref << '\n';

	return 0;
} // rref (y la Fracción temporal) salen de alcance aquí
#endif


#if 0
#include <iostream>

int main()
{
	int&& rref{ 5 }; // un objeto temporal con valor 5 se crea aquí
	rref = 10;
	std::cout << rref << '\n';

	return 0;
}







#include <iostream>

void compara(const int& lref) // argumentos l-value seleccionarán esta comparación
{
	std::cout << "referencia l-value a const\n";
}

void compara(int&& rref) // argumentos r-value seleccionarán esta comparación
{
	std::cout << "referencia r-value\n";
}

int main()
{
	int x{ 5 };
	compara(x); // argumento l-value llama a la versión l-value de la comparación
	compara(5); // argumento r-value llama a la versión r-value de la comparación

	return 0;
}
#endif


#include <iostream>

void compara(const int& lref) // argumentos l-value seleccionarán esta sobrecarga
{
	std::cout << "referencia l-value a const\n";
}

void compara(int&& rref) // argumentos r-value seleccionarán esta sobrecarga
{
	std::cout << "referencia r-value\n";
}

int main()
{
	int &&rref{ 5 };
	compara(rref); 
	return 0;
}
#if 0
#endif

#if 0
int main()
{
	int x{};

	// referencias l-value
	int& ref1{ x }; // 1
	int& ref2{ 5 }; // 2

	const int& ref3{ x }; // 3
	const int& ref4{ 5 }; //4

	// referencias r-value
	int&& ref5{ x }; // 5
	int&& ref6{ 5 }; // 6

	const int&& ref7{ x }; // 7
	const int&& ref8{ 5 }; // 8

	return 0;
}
#endif