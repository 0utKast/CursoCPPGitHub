#if 0

#include <iostream>
#include <string>

template<class T>
void intercambioPorCopia(T& a,  T& b)
{
	T temp{ a }; // invoca constructor por copia
	a = b; // invoca asignación por copia
	b = temp; // invoca asignación por copia
}

int main()
{
	 std::string x{ "principio" };
	 std::string y{ "final" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	intercambioPorCopia(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
}





#endif

#if 0

#include <iostream>
#include <string>
#include <utility> // para std::move

template<class T>
void intercambioPorMovimiento(T& a, T& b)
{
	T tmp{ std::move(a) }; // invoca constructor por movimiento
	a = std::move(b); // invoca asignación por movimiento
	b = std::move(tmp); // invoca asignación por movimiento
}

int main()
{
	std::string x{ "principio" };
	std::string y{ "final" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	intercambioPorMovimiento(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
}

#endif




#include <iostream>
#include <string>
#include <utility> // para std::move
#include <vector>

int main()
{
	std::vector<std::string> vector;

	// Usamos std::string porque es "movible" (std::string_view no lo es)
	std::string frase1{ "Pasando primera frase(copiada)" };
	std::string frase2{ "Pasando segunda frase(movida)" };


	std::cout << "Copiando string\n";
	vector.push_back(frase1); // llama a la versión l-value de push_back, que copia frase en el elemento array

	std::cout << "frase1: " << frase1 << '\n';
	std::cout << "vector: " << vector[0] << '\n';

	std::cout << "\nMoviendo string\n";

	vector.push_back(std::move(frase2)); // llama versión  r-value de push_back, que mueva  frase al elemento array

	std::cout << "frase1: " << frase1 << '\n';
	std::cout << "frase2: " << frase2 << '\n'; // El resultado de esto es indeterminado
	std::cout << "vector:" << vector[0] << ' ' << vector[1] << '\n';

	return 0;
}



#if 0
#endif


