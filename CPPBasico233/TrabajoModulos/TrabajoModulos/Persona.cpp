
//código 003b
module persona;  // declaración del Módulo, pero sin la palabra clave export



Persona::Persona(std::string nombre, std::string apellido)
    : m_nombre{ std::move(nombre) }, m_apellido{ move(apellido) }
{
}

const std::string& Persona::getNombre() const { return m_nombre; }
const std::string& Persona::getApellido() const { return m_apellido; }




