#if 0
#include <iostream>

template <typename T, int tamanho> // tamanho es un parámetro no-de-tipo integral.
class ArrayEstatico
{
private:
    // El parámetro no-de-tipo controla el tamaño del array.
    T m_array[tamanho]{};

public:
    T* getArray();

    T& operator[](int indice)
    {
        return m_array[indice];
    }
};

// Muestra como una función para una clase con un parámetro no-de-tipo es definida fuera de la clase.
template <typename T, int tamanho>
T* ArrayEstatico<T, tamanho>::getArray()
{
    return m_array;
}

int main()
{
    // declaramos un array integer con espacio para 12 integers.
    ArrayEstatico<int, 12> intArray;

    // Poblamos en orden, e imprimimos en orden inverso
    for (int contador{ 0 }; contador < 12; ++contador)
        intArray[contador] = contador;

    for (int contador{ 11 }; contador >= 0; --contador)
        std::cout << intArray[contador] << ' ';
    std::cout << '\n';

    // declaramos un array double con espacio para 4 doubles
    ArrayEstatico<double, 4> doubleArray;

    // poblamos en orden, e imprimimos en orden
    for (int contador{ 0 }; contador < 4; ++contador)
        doubleArray[contador] = 4.4 + 0.1 * contador;

    for (int contador{ 0 }; contador < 4; ++contador)
        std::cout << doubleArray[contador] << ' ';

    return 0;
}

#endif


#include <iostream>

template <typename T, int tamanho> // tamanho es un parámetro no-de-tipo integral.
class ArrayEstatico
{
private:
    // El parámetro no-de-tipo controla el tamaño del array.
    T m_array[tamanho]{};

public:
    T* getArray();

    T& operator[](int indice)
    {
        return m_array[indice];
    }
};

// Muestra como una función para una clase con un parámetro no-de-tipo es definida fuera de la clase.
template <typename T, int tamanho>
T* ArrayEstatico<T, tamanho>::getArray()
{
    return m_array;
}

int main()
{
    // declaramos un array integer con espacio para 12 integers.
    constexpr int x{ 12 };
    ArrayEstatico<int, x> intArray;

    // Poblamos en orden, e imprimimos en orden inverso
    for (int contador{ 0 }; contador < 12; ++contador)
        intArray[contador] = contador;

    for (int contador{ 11 }; contador >= 0; --contador)
        std::cout << intArray[contador] << ' ';
    std::cout << '\n';

    // declaramos un array double con espacio para 4 doubles

    int     y{ 4 };
    
    ArrayEstatico<double, y> doubleArray;

    // poblamos en orden, e imprimimos en orden
    for (int contador{ 0 }; contador < 4; ++contador)
        doubleArray[contador] = 4.4 + 0.1 * contador;

    for (int contador{ 0 }; contador < 4; ++contador)
        std::cout << doubleArray[contador] << ' ';

    return 0;
}



#if 0
#include <iostream>
#include <string>

template <typename T>
class Foo
{    
private:
       T m_valor{};
public:

   Foo (T valor)
    {
       m_valor = valor;

    }

   void getValor()
   {
       std::cout << m_valor << '\n';
   }
};


int main()
{
   
    Foo<int> entero {3};
    Foo<double> decimal{ 4.7 };
    Foo<std::string> string {"Hola Mundo"};
    entero.getValor();
    decimal.getValor();
    string.getValor();
  
}

#endif
