#if 0
#include <iostream>
#include <cmath> // para sqrt() function

// Una función raíz cuadrada modular
double miSqrt(double x)
{
    // Si el usuario escribe un número negativo, esta es la condición de error
    if (x < 0.0)
        throw "No se puede calcular la raíz cuadrada de un número negativo"; // throw excepción de tipo const char*

    return std::sqrt(x);
}

int main()
{
    setlocale(LC_ALL, "es_ES");
    std::cout << "Escribe un número: ";
    double x;
    std::cin >> x;
    // Observa que ahora no incluye un manejador para la excepción
    std::cout << "La raíz cuadrada de " << x << " es " << miSqrt(x) << '\n';

    return 0;
}
#endif


#if 0


#include <iostream>

int main()
{
    setlocale(LC_ALL, "es_ES");
	try
	{
		throw 5; // lanza una excepción int
	}
	catch (double x)
	{
		std::cout << "Capturamos una excepción de tipo double: " << x << '\n';
	}
	/*catch (...) // manejador catch-all 
	{
		std::cout << "Capturamos una excepción de un tipo indeterminado\n";
	}*/

    catch (...) {} // ignora cualquier excepción no controlada
}
#endif


#include <iostream>

int main()
{

    try
    {
        ejecutaJuego();
    }
    catch (...)
    {
        std::cerr << "terminación inesperada\n";
    }

    guardarEstado(); // Salva el juego del usuario
    return 1;
}
