#if 0
template <typename T>
class Almacen8
{
private:
    T m_array[8];

public:
    void set(int indice, const T& valor)
    {
        m_array[indice] = valor;
    }

    const T& get(int indice) const
    {
        return m_array[indice];
    }
};


#include <iostream>
int main()
{
    // Define un Almacen8 para integers
    Almacen8<int> intAlmacen;

    for (int contador{ 0 }; contador < 8; ++contador)
        intAlmacen.set(contador, contador);

    for (int contador{ 0 }; contador < 8; ++contador)
        std::cout << intAlmacen.get(contador) << '\n';

    // Define a Almacen8 for bool
    Almacen8<bool> boolAlmacen;
    for (int contador{ 0 }; contador < 8; ++contador)
        boolAlmacen.set(contador, contador );

    std::cout << std::boolalpha;

    for (int contador{ 0 }; contador < 8; ++contador)
    {
        std::cout << boolAlmacen.get(contador) << '\n';
    }

    return 0;
}


#endif

template <typename T>
class Almacen8
{
private:
    T m_array[8];

public:
    void set(int indice, const T& valor)
    {
        m_array[indice] = valor;
    }

    const T& get(int indice) const
    {
        return m_array[indice];
    }
};


// Requiere la definición de tipo Almacen8 de arriba

template <>
class Almacen8<bool> // Especializamos Almacen8 para bool
{
    // Lo que sigue son solo detalles estándar de implementación de la clase
private:
    unsigned char m_datos{};

public:
    void set(int indice, bool valor)
    {
        // Averiguar qué bit estamos configurando/desconfigurando
        // Esto pondrá un 1 en el bit que nos interesa activar/desactivar
        auto mask{ 1 << indice };

        if (valor)  // Si estamos configurando un bit
            m_datos |= mask;   // usamos bitwise-or para convertir ese bit on
        else  // si estamos convirtiendo un  bit off
            m_datos &= ~mask;  // bitwise AND máscara inversa para desactivar ese bit
    }

    bool get(int indice)
    {
        // Determina que bit estamos obteniendo
        auto mask{ 1 << indice };
        // bitwise-and para obtener el valor del bit en el que estamos interesados
        // Luego implícitamente convertir a boolean
        return (m_datos & mask);
  }
};



#include <iostream>
int main()
{
    // Define un Almacen8 para integers (instancia Almacen8<T>, donde T = int)
    Almacen8<int> intAlmacen;

    for (int contador{ 0 }; contador < 8; ++contador)
    {
        intAlmacen.set(contador, contador);
    }

    for (int contador{ 0 }; contador < 8; ++contador)
    {
        std::cout << intAlmacen.get(contador) << '\n';
    }

    // Define un Almacen8 para bool  (instancia la especialización Almacen8<bool>)
    Almacen8<bool> boolAlmacen;

    for (int contador{ 0 }; contador < 8; ++contador)
    {
        boolAlmacen.set(contador, contador & 3);
    }

    std::cout << std::boolalpha;

    for (int contador{ 0 }; contador < 8; ++contador)
    {
        std::cout << boolAlmacen.get(contador) << '\n';
    }

    return 0;
}
