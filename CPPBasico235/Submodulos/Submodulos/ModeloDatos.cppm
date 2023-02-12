//C�digo 002
export module modelodatos;          // modulo modelodatos

export import modelodatos.persona;   // Importa y exporta subm�dulo persona
export import modelodatos.direccion;  // Importa y exporta direcci�n subm�dulo

import <vector>;
import <iostream>;

export namespace ModeloDatos
{
    using Personas = std::vector<Persona>;
}



#if 0
//C�digo 001

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