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



#include <iostream>

int main()
{
	int&& rref{ 5 }; // como estamos inicializando una referencia r-value con un literal, un objeto temporal con valor 5 se crea aquí
	rref = 10;
	std::cout << rref << '\n';

	return 0;
}
#endif

#include <iostream>

void fun(const int& lref) // argumentos l-value seleccionarán esta función
{
	std::cout << "referencia l-value a const\n";
}

void fun(int&& rref) // argumentos r-value seleccionarán esta función
{
	std::cout << "referencia r-value\n";
}

int main()
{
	int x{ 5 };
	fun(x); // argumento l-value llama a la versión l-value de la función
	fun(5); // argumento r-value llama a la versión r-value de la función

	return 0;
}