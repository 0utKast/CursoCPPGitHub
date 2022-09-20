
#if 0
#include <cmath> // para función sqrt()
#include <iostream>

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    std::cout << "Escribe un número: ";
    double x{};
    std::cin >> x;

    try // Busca excepciones que ocurren dentro del bloque try y enruta al bloque(s) catch vinculados
    {
        // Si el usuario escribe un número negativo, esta es una condición de error
        if (x < 0.0)
            throw "No se puede calcular sqrt de número negativo"; // lanza excepción de tipo const char*


        // en otro caso, imprime la respuesta
        std::cout << "La raíz cuadrada de " << x << " es " << std::sqrt(x) << '\n';
    }
    catch (const char* exception) // captura excepciones de tipo const char*
    {
        std::cerr << "Error: " << exception << '\n';

    }

    std::cout << "continúa el flujo normal del programa";
}







#include <cmath> // para función sqrt()
#include <iostream>

// Una función raíz cuadrada modular
double miSqrt(double x)
{
    // Si el usuario escribe un número negativo, esta es una condición de error
    if (x < 0.0)
        throw "No se puede calcular la raíz cuadrada de un número negativo"; // throw excepción de tipo const char*

    return std::sqrt(x);
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    std::cout << "Escribe un número: ";
    double x{};
    std::cin >> x;

    try // Busca excepciones que ocurran dentro del bloque try y enruta a los bloques catch vinculados
    {
        double d = miSqrt(x);
        std::cout << "La raíz cuadrada de " << x << " es " << d << '\n';
    }
    catch (const char* excepcion) // excepciones catch de tipo const char*
    {
        std::cerr << "Error: " << excepcion << std::endl;
    }

    return 0;
}
#endif





#include <iostream>

void final() // llamado por tercero()
{
    std::cout << "Empieza final\n";
    std::cout << "final throwing excepción int\n";

    throw - 1.0;

    std::cout << "Termina final\n";
}

void tercero() // llamado por segundo()
{
    std::cout << "Empieza tercero\n";
    final();
    std::cout << "Termina tercero\n";
}

void segundo() // llamado by primero()
{
    std::cout << "Empieza segundo\n";
    try
    {
        tercero();
    }
    catch (double)
    {
        std::cerr << "segundo captura excepción double\n";
    }
    std::cout << "Termina segundo\n";
}

void primero() // llamado por main()
{
    std::cout << "Empieza primero\n";
    try
    {
        segundo();
    }
    catch (int)
    {
        std::cerr << "primero captura excepción int\n";
    }
    catch (double)
    {
        std::cerr << "primero captura excepción double\n";
    }
    std::cout << "Termina primero\n";
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    std::cout << "Empieza main\n";
    try
    {
        primero();
    }
    catch (int)
    {
        std::cerr << "main captura excepción int\n";
    }
    std::cout << "Termina main\n";

    return 0;
}


#if 0
#endif