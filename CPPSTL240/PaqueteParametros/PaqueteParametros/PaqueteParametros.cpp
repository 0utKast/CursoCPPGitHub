#if 0
//Código 000
#include <iostream>
template <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}
template <typename T, typename... Args>
T min(T a, Args... args)
{
    return min(a, min(args...));
}
int main()
{
    std::cout << "min(42.0, 7.5)=" << min(42.0, 7.5)
        << '\n';
    std::cout << "min(1,5,3,-4,9)=" << min(1, 5, 3, -4, 9)
        << '\n';
}




//Código 001


#include <iostream>

template <typename T, typename... Args>
T sum(T a, Args... args)
{
    if constexpr (sizeof...(args) == 0)
        return a;
    else
        return a + sum(args...);
    
}

int main()
{
    int result = sum(1, 2, 3, 4, 5);
    std::cout << "La suma total es: " << result << std::endl;

    double result2 = sum(1.5, 2.5, 3.5, 4.5);
    std::cout << "La suma total es: " << result2 << std::endl;

    return 0;
}






//Código 004

#include <iostream>
#include <array>

template<typename... Args>
constexpr auto get_type_sizes()
{
    
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    auto sizes = get_type_sizes<short, int, long, long long>();
    std::cout << "Tamaño de short: " << sizes[0] << std::endl;
    std::cout << "Tamaño de int: " << sizes[1] << std::endl;
    std::cout << "Tamaño de long: " << sizes[2] << std::endl;
    std::cout << "Tamaño de long long: " << sizes[3] << std::endl;

    return 0;
}
#endif



// Código 005



#include <iostream>
#include <array>

template<typename... Args>
constexpr auto get_type_sizes()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    std::cout << "Número de tipos: " << sizeof...(Args) << std::endl; 

    return std::array<std::size_t, sizeof...(Args)>{sizeof(Args)...};   
    
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    auto sizes = get_type_sizes<short, int, long, long long>();
    std::cout << "Tamaño de short: " << sizes[0] << std::endl;
    std::cout << "Tamaño de int: " << sizes[1] << std::endl;
    std::cout << "Tamaño de long: " << sizes[2] << std::endl;
    std::cout << "Tamaño de long long: " << sizes[3] << std::endl;

    return 0;
}

#if 0

//Código 006
#include <iostream>

template <typename... Args>
void show_size(Args... args)
{
    ((std::cout << "Tamaño en bytes de args: " << sizeof(args) << std::endl), ...);
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    show_size(1, 2, 3, 4, 5);
    show_size(1.5, 2.5, 3.5, 4.5);

    return 0;
}



//Código 007

#include <iostream>

template<typename... Args>
int sum(Args... args) {
    return (args + ...);
}

int main() {
    int result1 = sum(1, 2, 3, 4, 5);
    std::cout << "La suma total es: " << result1 << std::endl;

    double result2 = sum(1.5, 2.5, 3.5, 4.5);
    std::cout << "La suma total es: " << result2 << std::endl;

    return 0;
}

#endif

