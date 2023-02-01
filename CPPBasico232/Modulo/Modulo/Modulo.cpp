#include <iostream>
import persona;
import <string>;

int main()
{
	Persona persona{ "Juan", "Blanco" };
	std::cout << persona.getNombre() << ", " << persona.getApellido() << std::endl;
}



