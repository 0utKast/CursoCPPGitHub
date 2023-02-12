//Código 002
export module modelodatos;          // modulo modelodatos

export import modelodatos.persona;   // Importa y exporta submódulo persona
export import modelodatos.direccion;  // Importa y exporta dirección submódulo

import <vector>;
import <iostream>;

export namespace ModeloDatos
{
    using Personas = std::vector<Persona>;
}



#if 0
//Código 001

export module modelodatos;
import <vector>;
import <iostream>;
export namespace ModeloDatos
{
    class Persona { /* ... */ };
    class Direccion { /* ... */ };
    using Personas = std::vector<Persona>;
}

#endif