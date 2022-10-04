#if 0
#include <cstddef> // para std::size_t
#include <exception> // para std::exception
#include <iostream>
#include <limits>
#include <string> // para este ejemplo

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    try
    {
        // Nuestro código usando la biblioteca estándar va aquí
        // Activaremos una de estas excepciones intencionalment para simplificar
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // Activará una excepción std::length_error o de asignación
    }
    // Toda derivada es-un padre. Este controlador capturará std::exception y todas las excepciones derivadas también
    catch (const std::exception& excepcion)
    {
        std::cerr << "Excepción estándar: " << excepcion.what() << '\n';
    }

    return 0;
}





#include <cstddef> // para std::size_t
#include <exception> // para std::exception
#include <iostream>
#include <limits>
#include <string> // para este ejemplo

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    try
    {
        // Nuestro código usando la biblioteca estándar va aquí
       // Activaremos una de estas excepciones intencionalment para simplificar
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // Activará una excepción std::length_error o de asignación
    }
    //Este catch se lanza con excepciones de tipo std::length_error
    catch (const std::length_error& exception)
    {
        std::cerr << "¡Te quedaste sin memoria!" << '\n';
    }
    //Este catch se lanzará con exceptiones de tipo std::exception y derivadas, excepto std::length_error
    catch (const std::exception& exception)
    {
        std::cerr << "Excepción estándar: " << exception.what() << '\n';
    }
}



#include <exception> // para std::exception
#include <iostream>
#include <stdexcept> // para std::runtime_error

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    try
    {
        throw std::runtime_error("Algo malo ha pasado");
    }
    // Este manejador capturará std::exception y todas las excepciones derivadas
    catch (const std::exception& exception)
    {
        std::cerr << "Excepción estándar: " << exception.what() << '\n';
    }

    return 0;
}

#endif



#include <exception> // para std::exception
#include <iostream>
#include <string>
#include <string_view>

class ArrayException : public std::exception
{
private:
    std::string m_error{}; // Maneja nuestro propio string

public:
    ArrayException(std::string_view error)
        : m_error{ error }
    {
    }

    // std::exception::what() devuelve un const char*, así que debemos hacerlo
    const char* what() const noexcept override { return m_error.c_str(); }
};

class IntArray
{
private:
    int m_datos[5]{}; // asume que el array es de tamaño 5 por simplicidad

public:
    IntArray() {}

    int getLength() const { return 3; }

    int& operator[](const int indice)
    {
        if (indice < 0 || indice >= getLength())
            throw ArrayException("Índice inválido");

        return m_datos[indice];
    }

};

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    IntArray array;

    try
    {
        int valor{ array[7] };
    }
    catch (const ArrayException& exception) // Los bloques catch derivados deben ir primero
    {
        std::cerr << "Una excepción Array ha ocurrido (" << exception.what() << ")\n";
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Alguna otra std::exception ha ocurrido (" << exception.what() << ")\n";
    }
}

#if 0
#endif