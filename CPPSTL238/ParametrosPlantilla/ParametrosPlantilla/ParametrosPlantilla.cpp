#if 0
//Plantilla de función Código 001
template <typename T>
T max(T const a, T const b)
{
	return a > b ? a : b;
}





//Plantilla de clase Código 002
template <typename T>
struct vector
{
	vector();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void clear();
	void resize(size_t const size);
	void push_back(T valor);
	void pop_back();
	T at(size_t const index) const;
	T operator[](size_t const index) const;
private:
	T* data_;
	size_t size_;
	size_t capacity_;
};






//Plantilla de variable Código 003

#include <iostream>

template<typename T>
constexpr T pi = T(3.1415926535897932385);

int main() {
	double pi_double = pi<double>;
	float pi_float = pi<float>;
	long double pi_long_double = pi<long double>;

	std::cout << "pi (double) = " << pi_double << std::endl;
	std::cout << "pi (float) = " << pi_float << std::endl;
	std::cout << "pi (long double) = " << pi_long_double << std::endl;

	return 0;
}





//versión de plantilla de variable usando setprecision Código 004
#include <iostream>
#include <iomanip>

template<typename T>
constexpr T pi = T(3.1415926535897932385);

int main() {
	double pi_double = pi<double>;
	float pi_float = pi<float>;
	long double pi_long_double = pi<long double>;

	std::cout << "pi (double) = " << std::fixed << std::setprecision(10) << pi_double << std::endl;
	std::cout << "pi (float) = " << std::fixed << std::setprecision(5) << pi_float << std::endl;
	std::cout << "pi (long double) = " << std::fixed << std::setprecision(20) << pi_long_double << std::endl;

	return 0;
}




//Especialización de plantillas de variable. Código 005

#include <iostream>

template<typename T>
constexpr T valor_predeterminado = T(0);

template<>
constexpr int valor_predeterminado<int> = 42;

template<>
constexpr char valor_predeterminado<char> = 'X';

template<>
constexpr double valor_predeterminado<double> = 3.14159265359;

int main() {
	int i {valor_predeterminado<int> };
	char c = valor_predeterminado<char>;
	double d = valor_predeterminado<double>;
	float f = valor_predeterminado<float>;

	std::cout << "valor_predeterminado<int> = " << i << std::endl;
	std::cout << "valor_predeterminado<char> = " << c << std::endl;
	std::cout << "valor_predeterminado<double> = " << d << std::endl;
	std::cout << "valor_predeterminado<float> = " << f << std::endl;


	return 0;
}



//Ejemplo plantila de variable Código 006
#include <iostream>
#include <string>

template<typename T>
constexpr T NuevaLinea = T('\n');

int main()
{
	std::wstring test = L"demo";
	std::wstring test2 = L"demo2";	

	test += NuevaLinea<wchar_t>;
	test2 += NuevaLinea<char16_t>;	

	std::wcout << test;
	std::wcout << test2;
	
}






//Plantilla de alias Código 007
#include <vector>
template<typename T> using MiAlias = std::vector<T>;
int main()
{
	MiAlias<int> miVector;

}




// Plantilla de clase cubierta_simple Código 008
#include <iostream>
template <typename T>
class cubierta_simple
{
public:
	T valor;
};


// Plantilla de clase cubierta_elegante Código 009
template <typename T>
class cubierta_elegante
{
private:
	T valor;

public:
	cubierta_elegante(T const v) :valor(v)
	{
	}
	T const& get() const { return valor; }
	template <typename U>
	U como() const
	{
		return static_cast<U>(valor);
	}

};

//Plantilla de clase cubierta_par con un parámetro plantilla de plantilla Código 010
template <typename T, typename U, template<typename> typename W = cubierta_elegante>
class cubierta_par
{
public:	
	cubierta_par(T const a, U const b) :
		item1(a), item2(b)
	{
	}
	W<T> item1;
	W<U> item2;
};

int main()
{
	cubierta_par<int, double> p1(42.4, 42.3);
	std::cout << p1.item1.get() << ' '	<< p1.item2.get() << '\n';

	cubierta_par<double, int, cubierta_simple> p2(42.4, 42.3); 
	std::cout << p2.item1.valor << ' '	<< p2.item2.valor << '\n';	

	cubierta_par<int, int> par1(42.4, 42.3);
	std::cout << par1.item1.como<double>() << " " << par1.item2.como<int>() << std::endl; 

	

}



// Lambda como predicado y como comparación Código 011 

#include <iostream>
#include <algorithm>

int main()
{
	setlocale(LC_ALL, "es_ES.utf-8");
	int arr[] = { 1, 6, 3, 8, 4, 2, 9 };

	// Ordenar el array en orden descendente
	std::sort(std::begin(arr), std::end(arr),
		[](int const a, int const b) { return a > b; });

	// Contar el número de elementos mayores que un pivote dado
	int eje = 5;
	auto count = std::count_if(std::begin(arr), std::end(arr),
		[eje](int const a) { return a > eje; });

	// Mostrar los resultados
	std::cout << "Array ordenado en orden descendente: ";
	for (auto const& x : arr) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	std::cout << "Número de elementos mayores que " << eje << ": " << count << "\n";

	return 0;
}



// tres diferentes lambdas. Código 12

#include <iostream>
#include <string>

int main() {
	auto lambdaRegular = [](int a) {return a + a; };
	auto lambdaGenerica = [](auto a) {return a + a; };
	auto lambdaPlantilla = []<typename T>(T a) { return a + a; };

	int v1 = lambdaRegular(42);
	// advertencia: conversión implícita de "double" a "int" cambia el valor de  42.0 a 42 [-Wliteral-conversion]
	double v2 = lambdaRegular(42.0);
	// error: operandos inválidos para expresión binaria. Función candidata no viable: no conoce forma de conversión
	//std::string v3 = lambdaRegular(std::string{ 42 }); //error
	
	auto v5 = lambdaGenerica(42);
	auto v6 = lambdaGenerica(42.0);
	auto v7 = lambdaGenerica(std::string{ "42" });

	auto v8 = lambdaPlantilla(42);
	auto v9 = lambdaPlantilla(42.0);
	auto v10 = lambdaPlantilla(std::string{ "42" });

	std::cout << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v3 = " << "error" << std::endl;
	std::cout << "v5 = " << v5 << std::endl;
	std::cout << "v6 = " << v6 << std::endl;
	std::cout << "v7 = " << v7 << std::endl;
	std::cout << "v8 = " << v8 << std::endl;
	std::cout << "v9 = " << v9 << std::endl;
	std::cout << "v10 = " << v10 << std::endl;

	return 0;
}
#endif




#if 0
//Tres lambdas diferentes, con dos parámetros. Código 13
#include <iostream>
#include <string>

int main() {
	auto lambdaRegular = [](int a, int b) {return a + b; };
	auto lambdaGenerica = [](auto a, auto b) {return a + b; };
	auto lambdaPlantilla = []<typename T, typename U>(T a, U b) { return a + b; };
	

	int v1 = lambdaRegular(42, 1);
	// advertencia: conversión implícita de "double" a "int" cambia el valor de  42.0 a 42 [-Wliteral-conversion]
	double v2 = lambdaRegular(42.0, 1.0);
	// error: operandos inválidos para expresión binaria. Función candidata no viable: no conoce forma de conversión
	std::string v3;	

	auto v4 = lambdaGenerica(42, 1);
	auto v5 = lambdaGenerica(42.0, 1);
	auto v6 = lambdaGenerica(std::string{ "42" }, '1');
	std::string v7 = lambdaGenerica(std::string{ "42" }, std::string{ "1" });

	auto v8 = lambdaPlantilla(42, 1);
	auto v9 = lambdaPlantilla(42.0, 1);
	auto v10 = lambdaPlantilla(std::string{ "42" }, '1');	
	std::string v11 = lambdaPlantilla(std::string{ "42" }, std::string{ "42" });
	

	std::cout << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v3 = " << "error" << std::endl;
	std::cout << "v4 = " << v4 << std::endl;
	std::cout << "v5 = " << v5 << std::endl;
	std::cout << "v6 = " << v6 << std::endl;
	std::cout << "v7 = " << v7 << std::endl;
	std::cout << "v8 = " << v8 << std::endl;
	std::cout << "v9 = " << v9 << std::endl;
	std::cout << "v10 = " << v10 << std::endl;
	std::cout << "v11 = " << v11 << std::endl;

	return 0;
}

#endif



//Tres lambdas diferentes, con dos parámetros del mismo tipo. Código 14
#include <iostream>
#include <string>

int main() {
	auto lambdaRegular = [](int a, int b) {return a + b; };
	//auto lambdaGenerica = [](auto a, auto b) {return a + b; };
	//auto lambdaPlantilla = []<typename T, typename U>(T a, U b) { return a + b; };
	auto lambdaGenerica = [](auto a, decltype(a) b) {return a + b; };
	auto lambdaPlantilla = []<typename T>(T a, T b) { return a + b; };

	int v1 = lambdaRegular(42, 1);
	// advertencia: conversión implícita de "double" a "int" cambia el valor de  42.0 a 42 [-Wliteral-conversion]
	double v2 = lambdaRegular(42.0, 1.0);
	// error: operandos inválidos para expresión binaria. Función candidata no viable: no conoce forma de conversión
	std::string v3;

	auto v4 = lambdaGenerica(42, 1);
	auto v5 = lambdaGenerica(42.0, 1);
	auto v6 = lambdaGenerica(std::string{ "42" }, '1');
	std::string v7 = lambdaGenerica(std::string{ "42" }, std::string{ "1" });

	auto v8 = lambdaPlantilla(42, 1);
	auto v9 = lambdaPlantilla(42.0, 1);
	auto v10 = lambdaPlantilla(std::string{ "42" }, '1');
	std::string v11 = lambdaPlantilla(std::string{ "42" }, std::string{ "42" });


	std::cout << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v3 = " << "error" << std::endl;
	std::cout << "v4 = " << v4 << std::endl;
	std::cout << "v5 = " << v5 << std::endl;
	std::cout << "v6 = " << v6 << std::endl;
	std::cout << "v7 = " << v7 << std::endl;
	std::cout << "v8 = " << v8 << std::endl;
	std::cout << "v9 = " << v9 << std::endl;
	std::cout << "v10 = " << v10 << std::endl;
	std::cout << "v11 = " << v11 << std::endl;

	return 0;
}
