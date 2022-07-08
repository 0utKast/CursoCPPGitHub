

#ifndef ROL_H
#define ROL_H
#include "Heroe.h"

class Rol
{
private:
    const Heroe& m_heroe; // Este Rol contiene s�lo un h�roe para simplificar.

public:
    Rol(const Heroe& heroe)
        : m_heroe{ heroe }
    {
        std::cout << heroe << " Es ahora un Altmer" << '\n';
    }
};
#endif





