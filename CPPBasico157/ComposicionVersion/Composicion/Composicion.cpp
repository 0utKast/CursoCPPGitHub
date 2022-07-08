#include <string>
#include <iostream>
#include "Heroe.h"
#include "Localizacion.h"
#include "Rol.h"

int main()
{    
    setlocale(LC_ALL, "es_ES.UTF-8");	
    std::cout << "Escribe un nombre para tu héroe: ";
    std::string nombre;
    std::cin >> nombre;
    Heroe heroe{ nombre, { 4, 7 } };
    std::cout << heroe << '\n';	
    {
        Rol rol{ heroe };
    }
	
    std::cout << heroe.getNombre();
   
	
	

	
#if 0
    while (true)
    {
        // imprime el nombre del heroe y su localizción
        std::cout << heroe << '\n';

        std::cout << "Escribe una nueva localización X para el héroe (-1 para salir): ";
        int x{ 0 };
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Escribe una nueva localización Y para el héroe (-1 para salir): ";
        int y{ 0 };
        std::cin >> y;
        if (y == -1)
            break;

        heroe.moverA(x, y);
        
    }
#endif

    return 0;
}

#if 0
#endif

#if 0
#include <iostream>
#include <string>

class Empleado
{
private:
    std::string m_nombre{};

public:
    Empleado(const std::string& nombre)
        : m_nombre{ nombre }
    {
    }

    const std::string& getNombre() const { return m_nombre; }
};

class Seccion
{
private:
    const Empleado& m_empleado; // Esta Seccion contiene sólo un empleado por simplicidad, pero podía contener muchos

public:
    Seccion(const Empleado& empleado)
        : m_empleado{ empleado }
    {
    }
};

int main()
{
    // Crea un empleado fuera de alcance de Seccion
    Empleado juan{ "Juan" }; // crea un empleado

    {
        // Crea una sección y usa el parámetro del constructor para
        // pasarle el empleado.
        Seccion seccion{ juan };

    } // seccion sale de alcance aquí y es destruido

    // juan aún existe aquí, pero la sección no

    std::cout << juan.getNombre() << " Juan aún existe\n";

    return 0;
}
#endif