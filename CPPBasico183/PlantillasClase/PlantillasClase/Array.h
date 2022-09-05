#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <typename T> // añadido
class Array
{
private:
    int m_longit{};
    T* m_datos{}; // tipo cambiado a T

public:

    Array(int longit)
    {
        assert(longit > 0);
        m_datos = new T[longit]{}; // asignado un array de objeto de tipo T
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
        // Tenemos que asegurarnos de configurar m_dato a 0 aquí
       // o m_datos apuntará a una memoria desasignada(fuga)      
        m_datos = nullptr;
        m_longit = 0;
    }

    T& operator[](int indice) // Ahora devuelve un T&
    {
        assert(indice >= 0 && indice < m_longit);
        return m_datos[indice];
    }

    // Plantilla de función getLongit() definida abajo
    int getLongit() const;
};

// las funciones miembro definidas fuera de la clase necesitan su propia declaración de plantilla
template <typename T>
int Array<T>::getLongit() const // observa que el nombre de la clase es Array<T>, no
{
    return m_longit;
}

#endif
