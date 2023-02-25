#if 0
#include <stdio.h>
#include <stdarg.h>

void mi_printf(const char* formato, ...)
{
    va_list args;
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);
}

int main()
{
    mi_printf("Hola, %s! La respuesta es %d.\n", "mundo", 42);
   

    mi_printf("Hola, %s! La respuesta es %d. %s es un gran lenguaje.\n", "Mundo", 42, "C++");

    return 0;
}






#include <iostream>
#include <string>
#include <tuple>

int main()
{
    // Crear una tupla de tipos variados con los valores adecuados
    std::tuple<std::string, std::string, int, std::string> t = std::make_tuple("hola", "mundo", 43, "C++ es un gran lenguaje.");

    // Imprimir la cadena de caracteres y los valores
    std::cout << std::get<0>(t) << ", " << std::get<1>(t) << ", la respuesta es " << std::get<2>(t) << ". " << std::get<3>(t) << std::endl;

    return 0;
}

#endif


#if 0
//Código 001
#include<stdarg.h>
#include <iostream>
int min(int count, ...)
{
    va_list args;
    va_start(args, count);
    int val = va_arg(args, int);
    for (int i = 1; i < count; i++)
    {
        int n = va_arg(args, int);
        if (n < val)
            val = n;
    }
    va_end(args);
    return val;
}
int main()
{
    std::cout << "min(42, 7)=" << min(2, 42, 7) << '\n';
    std::cout << "min(1,5,3,-4,9)=" <<
        min(5, 1, 5, 3, -4,
            9) << '\n';
}

//Código 002
#include<stdarg.h>
#include <iostream>
template <typename T>
T min(int count, ...)
{
    va_list args;
    va_start(args, count);
    T val = va_arg(args, T);
    for (int i = 1; i < count; i++)
    {
        T n = va_arg(args, T);
        if (n < val)
            val = n;
    }
    va_end(args);
    return val;
}
int main()
{
    std::cout << "min(42.0, 7.5)="
        << min<double>(2, 42.0, 7.5) << '\n';
    std::cout << "min(1,5,3,-4,9)="
        << min<int>(5, 1, 5, 3, -4, 9) << '\n';
}
#endif


//Código 003
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



// Código 004
int min(int a, int b)
{
    return a < b ? a : b;
}
int min(int a, int b, int c)
{
    return min(a, min(b, c));
}
int min(int a, int b, int c, int d)
{
    return min(a, min(b, min(c, d)));
}
int min(int a, int b, int c, int d, int e)
{
    return min(a, min(b, min(c, min(d, e))));
}




#if 0
#endif