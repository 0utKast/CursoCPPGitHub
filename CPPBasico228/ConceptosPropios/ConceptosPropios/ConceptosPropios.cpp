
#if 0
//cod.001


#include <concepts>

template<typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;



//fin cod.001





//cod.002


#include <concepts>
template <typename T, typename U>
concept Iguales = std::same_as<T, U>;


//fin cod.002







//cod. 003

#include <concepts>

template<typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;

template<typename T> requires Numerico<T>
T multiplicar(T primero, T segundo) { return primero * segundo; }

//fin cod.003





//cod.004



#include <concepts>
template <typename T, typename U>
concept Iguales = std::same_as<T, U>;

template <typename T, typename U> requires Iguales<T, U>
void foo(T t, U u)
{
	// cuerpo de la función
}





//fin cod.004





//cod.005


#include <concepts>

template<typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;

template<typename T>
T multiplicar(T primero, T segundo) requires Numerico<T> {
	return primero * segundo;
}




//fin cod.005






//cod. 006



#include <concepts>
template <typename T, typename U>
concept Iguales = std::same_as<T, U>;


template <typename T, typename U>
void foo(T t, U u) requires Iguales<T, U>
{
	// cuerpo de la función
}

int main()
{
	int x = 0;
	foo(x, 0); // esto es válido
	foo(x, 0.0); // esto causará un error en tiempo de compilación
	return 0;
}

//fin cod.006




//cod.007


#include <iostream>
template<typename T1, typename T2>
T2 multiplicar(T1 primero, T2 segundo) { return primero * segundo; }

int main() {
	std::cout << "Producto de 5 por 3: " << multiplicar(5, 3)
		<< "\nProducto de 7.25 por 2.0: " << multiplicar(7.25, 2.0)
		<< "\nProducto of 5 por 7.25: " << multiplicar(5, 7.25) << "\n";
}



//fin cod.007




//cod.008




#include <iostream>
template<typename T1, typename T2>
auto multiplicar(T1 primero, T2 segundo) { return primero * segundo; }

int main() {
	std::cout << "Producto de 5 por 3: " << multiplicar(5, 3)
		<< "\nProducto de 7.25 por 2.0: " << multiplicar(7.25, 2.0)
		<< "\nProducto of 5 por 7.25: " << multiplicar(5, 7.25) << "\n";
}





//fin cod.008




//cod.009

#include <concepts>
#include <iostream>

// El concepto propio Numerico agrega std::integral y std::floating_point
template<typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;

// plantilla de función abreviada con auto restringido
auto multiplicar(Numerico auto primero, Numerico auto segundo) {
	return primero * segundo;
}

int main() {
	std::cout << "Producto de 5 por 3: " << multiplicar(5, 3)
		<< "\nProducto de 7.25 por 2.0: " << multiplicar(7.25, 2.0)
		<< "\nProducto de 5 por 7.25: " << multiplicar(5, 7.25) << "\n";
}


#endif



//fin cod.009


#if 0

#include <concepts>
#include <iostream>

// El concepto propio Numerico agrega std::integral y std::floating_point
template<typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;

// plantilla de función abreviada con auto restringido

template<Numerico T1, Numerico T2>
auto multiplicar(T1 primero, T2 segundo) { return primero * segundo; }

int main() {
	std::cout << "Producto de 5 por 3: " << multiplicar(5, 3)
		<< "\nProducto de 7.25 por 2.0: " << multiplicar(7.25, 2.0)
		<< "\nProducto de 5 por 7.25: " << multiplicar(5, 7.25) << "\n";
}





#endif




#include <concepts>
#include <iostream>

// El concepto propio Numerico agrega std::integral y std::floating_point
template<typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;

// plantilla de función abreviada con auto restringido

template<Numerico T1, Numerico T2>
auto multiplicar(T1 primero, T2 segundo) { return primero * segundo; }

int main() {
	std::cout << "Producto de 5 por 3: " << multiplicar(5, 3)
		<< "\nProducto de 7.25 por 2.0: " << multiplicar(7.25, 2.0)
		<< "\nProducto de 5 por 7.25: " << multiplicar(5, 7.25) << "\n";

	std::string s1{ "uno" };
	std::string s2{ "dos" };
	auto resultado{ multiplicar(s1, s2) };
}





#if 0
#endif


