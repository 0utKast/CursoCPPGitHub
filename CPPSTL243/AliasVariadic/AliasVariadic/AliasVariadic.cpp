#if 0
//Código 001


#include <type_traits>
template <typename T, typename... Args>
struct foo
{
	//los miembros aquí
};
template <typename... Args>
using int_foo = foo<int, Args...>;

int main()
{
	foo<double, char, int> f1;
	foo<int, char, double> f2;
	int_foo<char, double> f3;
	static_assert(std::is_same_v<decltype(f2), decltype(f3)>);

}





//Código 003


#include <type_traits>
#include <iostream>

template <typename T, typename... Args>
struct foo
{
	//los miembros aquí
};

template <typename... Args>
using int_foo = foo<int, Args...>;

int main()
{
	setlocale(LC_ALL, "es_ES.utf-8");
	foo<double, char, int> f1;
	foo<int, char, double> f2;
	int_foo<char, double> f3;

	if (std::is_same_v<decltype(f2), decltype(f3)>)
	{
		std::cout << "f2 y f3 son del mismo tipo" << std::endl;
	}
	else
	{
		std::cout << "f2 y f3 no son del mismo tipo" << std::endl;
	}

	static_assert(std::is_same_v<decltype(f1), decltype(f2)> == false);
	static_assert(std::is_same_v<decltype(f1), decltype(f3)> == false);
	std::cout << "el programa finaliza correctamente porque las dos últimas declaraciones son false";

	return 0;
}





#include <cstddef>
#include<iostream>
#include<array>
template<typename T, std::size_t N>
using ArrayModerno = std::array<T, N>;

int main()
{
	ArrayModerno<int, 10> miArray;
	ArrayModerno<double, 10> otroArray;
	ArrayModerno<std::string, 5> masArray;
}







//Código 004

#include <iostream>
#include <functional>
#include <tuple>
template<typename T, T... Ints>
struct secuencia_enteros
{
};

template<std::size_t... Ints>
using secuencia_indices = secuencia_enteros<std::size_t, Ints...>;

template<typename Tuple, std::size_t... Ints>
auto select_tuple(Tuple&& tuple, secuencia_indices<Ints...>)
{
	return std::make_tuple(
		std::get<Ints>(std::forward<Tuple>(tuple))...);
}

int main()
{
	std::tuple<int, char, double> t1{ 42, 'x', 42.99 };
	auto t2 = select_tuple(t1, secuencia_indices<0, 2>{});
	std::cout << std::get<0>(t2) << ", " << std::get<1>(t2) << std::endl;
}

#endif







#include <iostream>

template <int... R>
constexpr int Sum = (... + R);
int main()
{
	std::cout << Sum<1> << '\n';
	std::cout << Sum<1, 2> << '\n';
	std::cout << Sum<1, 2, 3, 4, 5> << '\n';
	
}


#if 0
#endif