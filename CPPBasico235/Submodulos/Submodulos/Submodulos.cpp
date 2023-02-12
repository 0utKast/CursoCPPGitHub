
import modelodatos;

int main()
{
    ModeloDatos::Direccion b;
	ModeloDatos::Persona a;
}










//Código 003
#if 0
#include <vector>
#include <iostream>

namespace ModeloDatos
{
    class Persona {
    public:
        Persona(const std::string& nombre, int edad)
            : nombre(nombre), edad(edad) {}
        std::string nombre;
        int edad;
    };

    using Personas = std::vector<Persona>;
}

int main()
{
    setlocale(LC_ALL, "es_ES");
    ModeloDatos::Personas personas;
    personas.push_back(ModeloDatos::Persona("Juan", 30));
    personas.push_back(ModeloDatos::Persona("Ana", 25));
    personas.push_back(ModeloDatos::Persona("Pedro", 35));

    for (const auto& persona : personas) {
        std::cout << persona.nombre << " tiene " << persona.edad << " años." << std::endl;
    }

    return 0;
}
#endif
