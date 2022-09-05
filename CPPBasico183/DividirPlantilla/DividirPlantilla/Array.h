#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <typename T>
class Array
{
private:
    int m_longit{};
    T* m_datos{};

public:

    Array(int longit)
    {
        assert(longit > 0);
        m_datos = new T[longit]{};
        m_longit = longit;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_datos;
    }

    void borrar()
    {
        delete[] m_datos;

        m_datos = nullptr;
        m_longit = 0;
    }

    T& operator[](int indice)
    {
        assert(indice >= 0 && indice < m_longit);
        return m_datos[indice];
    }

    int getLongit() const;
};

template <typename T>
int Array<T>::getLongit() const
{
    return m_longit;
}

#endif



