

#ifndef ROL_H
#define ROL_H
#include "Heroe.h"

class Rol
{
private:
    const Heroe& m_heroe; // Esta Seccion contiene s�lo un h�roe por simplicidad, pero pod�a contener muchos

public:
    Rol(const Heroe& heroe)
        : m_heroe{ heroe }
    {
    }
};
#endif
