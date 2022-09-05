#pragma once
#ifndef DOUBLEARRAY_H
#define DOUBLEARRAY_H

#include <cassert>

class DoubleArray
{
private:
    int m_longit{};
    double* m_datos{};

public:

    DoubleArray(int longit)
    {
        assert(longit > 0);
        m_datos = new double[longit] {};
        m_longit = longit;
    }

    DoubleArray(const DoubleArray&) = delete;
    DoubleArray& operator=(const DoubleArray&) = delete;

    ~DoubleArray()
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

    double& operator[](int index)
    {
        assert(index >= 0 && index < m_longit);
        return m_datos[index];
    }

    int getLongit() const { return m_longit; }
};

#endif
