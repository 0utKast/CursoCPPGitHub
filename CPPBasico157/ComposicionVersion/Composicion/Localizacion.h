#ifndef LOCALIZACION_H
#define LOCALIZACION_H

#include <iostream>


class Localizacion
{
private:
    int m_x;
    int m_y;

public:
    

    // constructor específico
    Localizacion(int x, int y)
        : m_x{ x }, m_y{ y }
    {
    }

    //operador de inserción sobrecargado
	friend std::ostream& operator<<(std::ostream& os, const Localizacion& l)
	{
		os << "(" << l.m_x << "," << l.m_y << ")";
		return os;
	}	
    
    // Funciones de Acceso
    void setLocalizacion(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
	


};
#endif
