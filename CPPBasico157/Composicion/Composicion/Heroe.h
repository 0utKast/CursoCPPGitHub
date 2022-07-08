#ifndef HEROE_H
#define HEROE_H

#include <iostream>
#include <string>
#include "Localizacion.h"


class Heroe
{
private:
    std::string m_nombre;
    Localizacion m_localizacion;

public:
    Heroe(const std::string& nombre, const Localizacion& localizacion)
        : m_nombre{ nombre }, m_localizacion{ localizacion }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Heroe& heroe)
    {
        out << heroe.m_nombre << "  " << heroe.m_localizacion;
        return out;
    }
	
	const std::string& getNombre() const { return m_nombre; }

    void moverA(int x, int y)
    {
        m_localizacion.setLocalizacion(x, y);
    }
};
#endif


