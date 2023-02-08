export module persona;  // Declaración módulo

import <string>;       // declaración Import
import <iostream>;

export class Persona    // declaración Export
{
private:
    std::string m_nombre;
    std::string m_apellido;

public:
    Persona(std::string nombre, std::string apellido)
        : m_nombre{ std::move(nombre) }
        , m_apellido{ std::move(apellido) } { }
    const std::string& getNombre() const { return m_nombre; }
    const std::string& getApellido() const { return m_apellido; }
};
