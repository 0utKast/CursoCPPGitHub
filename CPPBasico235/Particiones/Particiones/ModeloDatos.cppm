export module modelodatos; // modulo modelodatos (archivo de interfaz de m�dulo primario)

export import :persona;   // Importa y exporta partici�n persona
export import :direccion;  // Importa y exporta partici�n direccion
import <iostream>;
import <vector>;

export namespace ModeloDatos
{
	using Personas = std::vector<Persona>;
}





