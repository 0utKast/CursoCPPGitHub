
#if 0
#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador{ 0 };
    int m_denominador{ 1 };

public:
    // constructor
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador{ numerador }
        , m_denominador{ denominador }
    {
        assert(denominador != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}




#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador{ 0 };
    int m_denominador{ 1 };

public:
    // constructor
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador{ numerador }
        , m_denominador{ denominador }
    {
        assert(denominador != 0);
    }

    // posible implementación de constructor por copia implícito
    Fraccion(const Fraccion& f)
        : m_numerador{ f.m_numerador }
        , m_denominador{ f.m_denominador }
    {
    }

    // Posible implementación de operador de asignación implícito
    Fraccion& operator= (const Fraccion& fraccion)
    {
        // control de autoasignación
        if (this == &fraccion)
            return *this;

        // hacer la copia
        m_numerador = fraccion.m_numerador;
        m_denominador = fraccion.m_denominador;

        // devuelve el objeto existente para encadenamientos
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
    {
        out << f1.m_numerador << '/' << f1.m_denominador;
        return out;
    }
};






#include <cstring> // para strlen()
#include <cassert> // para assert() C++17
#include <iostream>

class Frase
{
private:
    char* m_datos{};
    int m_largo{};

public:
    Frase(const char* origen = "")
    {
        assert(origen); // asegurarse que origen no es un string nulo

        // Encontrar el largo para el string
        // más un carácter para un terminador
        m_largo = std::strlen(origen) + 1;

        // Asigna un buffer igual a este largo
        m_datos = new char[m_largo];

        // Copia el parámetro string en nuestro buffer interno
        for (int i{ 0 }; i < m_largo; ++i)
            m_datos[i] = origen[i];
    }

    ~Frase() // destructor
    {
        // Necesitamos desasignar nuestro string
        delete[] m_datos;
    }

    char* getString() { return m_datos; }
    int getLargo() { return m_largo; }
};

int main()
{
    Frase frase{ "Viendo the wire" };
    {
        Frase copia{ frase }; // usa constructor por copia predeterminado
    } // copia es una variable local, así que es destruida aquí. 
      //El destructor borra el string de copia, lo que deja a frase con un puntero colgante

    std::cout << frase.getString() << '\n'; // tendrá un comportamiento indefinido

    return 0;
}

#endif



#if 0
Frase::Frase(const Frase& fuente)
    : m_largo{ fuente.m_largo }
    , m_datos{ fuente.m_datos }
{
}

#endif


#include <cstring> // para strlen()
#include <cassert> // para assert() C++17
#include <iostream>

class Frase
{
private:
    char* m_datos{};
    int m_largo{};

public:
    Frase(const char* origen = "")
    {
        assert(origen); // asegurarse que origen no es un string nulo

        // Encontrar el largo para el string
        // más un carácter para un terminador
        m_largo = std::strlen(origen) + 1;

        // Asigna un buffer igual a este largo
        m_datos = new char[m_largo];

        // Copia el parámetro string en nuestro buffer interno
        for (int i{ 0 }; i < m_largo; ++i)
            m_datos[i] = origen[i];
    }
	
    // constructor por copia
    Frase(const Frase& fuente)
    {
        copiaProfunda(fuente);
    }

    ~Frase() // destructor
    {
        // Necesitamos desasignar nuestro string
        delete[] m_datos;
    }

    char* getString() { return m_datos; }
    int getLargo() { return m_largo; }

    // operador de asignación
    Frase& operator=(const Frase& fuente)
    {
        // comprobar autoasignación
        if (this != &fuente)
        {
            // now do the deep copy
            copiaProfunda(fuente);
        }

        return *this;
    }
	
    // asume que m_datos se ha inicializado
    void copiaProfunda(const Frase& fuente)
    {
        // primero necesitamos desasignar cualquier valor que contenga este string
        delete[] m_datos;

        // como m_largo no es un puntero, podemos hacer una copia superficial aquí
        m_largo = fuente.m_largo;

        // m_datos es un puntero, así que necesitamos una copia profunda si no es no-null
        if (fuente.m_datos)
        {
            // asigna memoria para nuestra copia
            m_datos = new char[m_largo];

            // hace la copia
            for (int i{ 0 }; i < m_largo; ++i)
                m_datos[i] = fuente.m_datos[i];
        }
        else
            m_datos = nullptr;
    }
};

int main()
{
    Frase frase{ "Viendo the wire" };
    {
        Frase copia{ frase }; // usa constructor por copia predeterminado
    } // copia es una variable local, así que es destruida aquí. 
      //El destructor borra el string de copia, lo que deja a frase con un puntero colgante

    std::cout << frase.getString() << '\n'; // tendrá un comportamiento indefinido

    return 0;
}


















