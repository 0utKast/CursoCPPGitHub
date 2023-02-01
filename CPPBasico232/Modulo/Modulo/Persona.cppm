module;                 //Comienzo del fragmento de m�dulo globlal
#include <cstddef>      //Incluye archivos header heredados


export module persona;  //declaraci�n de m�dulo
import <iostream>;      //declaraci�n import
import <string>;       //declaraci�n import

export class Persona  //declaraci�n export
{
private:
	std::string m_nombre;
	std::string m_apellido;
public:
	Persona(std::string nombre, std::string apellido)
		: m_nombre{ std::move(nombre) }, m_apellido{ std::move(apellido) } { }

	const std::string& getNombre() const { return m_nombre; }
	const std::string& getApellido() const { return m_apellido; }


};






