

#ifndef ROL_H
#define ROL_H
#include "Heroe.h"
#include <vector>

class Rol
{
private:
    const Heroe& m_heroe; // Este Rol contiene s�lo un h�roe para simplificar.
    //std::vector<const Heroe&> m_heroe{}; // Illegal

  

public:
    Rol(const Heroe& heroe)
        : m_heroe{ heroe }
    {
        std::cout << heroe << " Es ahora un Altmer" << '\n';
    }
};
#endif





