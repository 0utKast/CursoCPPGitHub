module;                 //Comienzo del fragmento de módulo globlal
#include <cstddef>      //Incluye archivos header heredados


export module persona;  //declaración de módulo
import <iostream>;      //declaración import
import <string>;       //declaración import

export class Persona  //declaración export
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






