export module modelodatos; // modulo modelodatos (archivo de interfaz de módulo primario)

export import :persona;   // Importa y exporta partición persona
export import :direccion;  // Importa y exporta partición direccion
import <iostream>;
import <vector>;

export namespace ModeloDatos
{
	using Personas = std::vector<Persona>;
}





