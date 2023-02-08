#if 0
//Código 001
import persona;     // Declaración Import para módulo persona

int main()
{
    std::string str;
    Persona persona{ "Juan", "Blanco" };
    const std::string& apellido{ persona.getApellido() };

}



//Código 002

import persona;     // Declaración Import para módulo persona

int main()
{
    Persona persona{ "Juan", "Blanco" };
    const auto& apellido{ persona.getApellido() };
    auto length{ apellido.length() };
    std::cout << length;


}
#endif

// Importing a standard library header as a header unit.
import <iostream>; // instead of #include <iostream>

int main() {
    std::cout << "Welcome to C++20 Modules!\n";
}