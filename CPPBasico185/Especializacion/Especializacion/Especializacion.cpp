#if 0
#include <iostream>

template <typename T>
class Almacen
{
private:
    T m_valor{};
public:
    Almacen(T valor)
        : m_valor{ valor }
    {
    }

    void imprimir()
    {
        std::cout << m_valor << '\n';
    }
};

template <>
void Almacen<double>::imprimir()
{
    std::cout << std::scientific << m_valor << '\n';
}

int main()
{
    // Define algunas unidades de almacenamiento
    Almacen<int> iValor{ 12 };
    Almacen<double> dValor{ 12.6 };

    // Imprime algunos valores
    iValor.imprimir();
    dValor.imprimir();
}
#endif

#if 0

#include <iostream>
#include <string>

template <typename T>
class Almacen
{
private:
    T m_valor{};
public:
    Almacen(T valor)
        : m_valor{ valor }
    {
    }

    void imprimir()
    {
        std::cout << m_valor << '\n';
    }
};

template <>
Almacen<char*>::Almacen(char* valor)
    : m_valor{ valor }
{
    // std::cout << "es un char"<< '\n';
}

int main()
{
    // Dinámicamente asigna un string temporal
    std::string s;

    // Pide al usuario el nombre
    std::cout << "Escribe tu nombre: ";
    std::cin >> s;

    // Almacena el nombre
    Almacen<char*> almacen{ s.data() };
    almacen.imprimir(); // Imprime nuestro nombre

    s.clear(); // limpia el std::string

    almacen.imprimir(); // No imprime nada
}


#endif


#include <iostream>

template <typename T>
class Almacen
{
private:
    T m_valor{};
public:
    Almacen(T valor)
        : m_valor{ valor }
    {
    }

    ~Almacen() {}; // necesitamos un destructor definido explícitamente para poder especializarlo

    void imprimir()
    {
        std::cout << m_valor << '\n';
    }
};


template <>
Almacen<char*>::Almacen(char* const valor)
{
    if (!valor)
        return;

    // calcula el tamaño del string de valor
    int tamanho{ 0 };
    while (valor[tamanho] != '\0')
        ++tamanho;
    ++tamanho; // +1 para dar cuenta del terminador nulo

    // Asigna memoria para contener el string valor
    m_valor = new char[tamanho];

    // Copia el string valor real en la memoria de m_valor que le hemos asignado
    for (int contador = 0; contador < tamanho; ++contador)
        m_valor[contador] = valor[contador];
}

template <>
Almacen<char*>::~Almacen()
{
    delete[] m_valor;
}


int main()
{
    // Dinámicamente asigna un string temporal
    std::string s;

    // Pide al usuario el nombre
    std::cout << "Escribe tu nombre: ";
    std::cin >> s;

    // Almacena el nombre
    Almacen<char*> almacen{ s.data() };
    almacen.imprimir(); // Imprime nuestro nombre

    s.clear(); // limpia el std::string

    almacen.imprimir(); // No imprime nada
}

