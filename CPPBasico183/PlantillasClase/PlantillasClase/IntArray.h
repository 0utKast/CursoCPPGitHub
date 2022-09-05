#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>

class IntArray
{
private:
    int m_longit{};
    int* m_datos{};

public:

    IntArray(int longit)
    {
        assert(longit > 0);
        m_datos = new int[longit] {};
        m_longit = longit;
    }
    
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    ~IntArray()
    {
        delete[] m_datos;
    }

    void borrar()
    {
        delete[] m_datos;
        // Tenemos que asegurarnos de configurar m_dato a 0 aquí
        // o m_datos apuntará a una memoria desasignada(fuga)
        m_datos = nullptr;
        m_longit = 0;
    }

    int& operator[](int indice)
    {
        assert(indice >= 0 && indice < m_longit);
        return m_datos[indice];
    }

    int getLongit() const { return m_longit; }
};

#endif




