

//C�digo 003a


export module persona;  // Declaraci�n de Modulo

import <string>;
import <iostream>;

export class Persona
{
private:
    std::string m_nombre;
    std::string m_apellido;
public:
    Persona(std::string nombre, std::string apellido);
    const std::string& getNombre() const;
    const std::string& getApellido() const;

};




#if 0
//C�digo 004



export module persona;
import <string>;
import <iostream>;
// Definici�n de Clase (interfaz p�blica)
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
    : m_nombre{ std::move(nombre) }, m_apellido{ std::move(apellido) } { }
const std::string& Persona::getNombre() const { return m_nombre; }
const std::string& Persona::getApellido() const { return m_apellido; }
#endif