
export module persona;
import <string>;
import <iostream>;

#if 0
// Definición clase
export class Persona
{
public:
	Persona(std::string nombre, std::string apellido);

	const std::string& getNombre() const;
	const std::string& getApellido() const;

private:
	std::string m_nombre;
	std::string m_apellido;
};

// Implementaciones
Persona::Persona(std::string nombre, std::string apellido)
	: m_nombre{ std::move(nombre) }, m_apellido{ std::move(apellido) }
{
}

const std::string& Persona::getNombre() const
{
	std::cout << m_nombre;
	return m_nombre;
}

const std::string& Persona::getApellido() const
{
	return m_apellido;
}

#endif

