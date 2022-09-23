#if 0
#include <iostream>
#include <cmath> // para sqrt() function

// Una funci�n ra�z cuadrada modular
double miSqrt(double x)
{
    // Si el usuario escribe un n�mero negativo, esta es la condici�n de error
    if (x < 0.0)
        throw "No se puede calcular la ra�z cuadrada de un n�mero negativo"; // throw excepci�n de tipo const char*

    return std::sqrt(x);
}

int main()
{
    setlocale(LC_ALL, "es_ES");
    std::cout << "Escribe un n�mero: ";
    double x;
    std::cin >> x;
    // Observa que ahora no incluye un manejador para la excepci�n
    std::cout << "La ra�z cuadrada de " << x << " es " << miSqrt(x) << '\n';

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
		throw 5; // lanza una excepci�n int
	}
	catch (double x)
	{
		std::cout << "Capturamos una excepci�n de tipo double: " << x << '\n';
	}
	/*catch (...) // manejador catch-all 
	{
		std::cout << "Capturamos una excepci�n de un tipo indeterminado\n";
	}*/

    catch (...) {} // ignora cualquier excepci�n no controlada
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
        std::cerr << "terminaci�n inesperada\n";
    }

    guardarEstado(); // Salva el juego del usuario
    return 1;
}
