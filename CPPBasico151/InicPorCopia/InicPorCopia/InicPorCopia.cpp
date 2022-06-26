#if 0
#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador;
    int m_denominador;

public:
    // constructor
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador(numerador), m_denominador(denominador)
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


int main()
{
    Fraccion diez = Fraccion(10);    
    std::cout << diez;   
    return 0;
}



#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador{};
    int m_denominador{};

public:
    // constructor con dos parámetros
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador{ numerador }, m_denominador{ denominador }
    {
        assert(denominador != 0);
    }

    // constructor por copia
    Fraccion(const Fraccion& fraccion)
        : m_numerador{ fraccion.m_numerador }, m_denominador{ fraccion.m_denominador }
    {
        // no necesitamos comprobar si el denominador es 0 al ser una copia
        std::cout << "constructor por copia llamado\n"; // para ver que funciona
    }


    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}

int main()
{
    Fraccion sieteQuintos{ Fraccion { 7, 5 } };
    std::cout << sieteQuintos;
    return 0;
}

#endif


#if 0
#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador;
    int m_denominador;

public:
	
    // constructor
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador(numerador), m_denominador(denominador)
    {
        assert(denominador != 0);
    }
	
    // constructor por copia
    Fraccion(const Fraccion& fraccion)
        : m_numerador{ fraccion.m_numerador }, m_denominador{ fraccion.m_denominador }
    {
        // no necesitamos comprobar si el denominador es 0 al ser una copia
        std::cout << "constructor por copia llamado\n"; // para ver que funciona
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}


int main()
{
    Fraccion diez = Fraccion(10);
    std::cout << diez;  
    return 0;
}




#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador;
    int m_denominador;

public:
    // constructor con dos parámetros
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador(numerador), m_denominador(denominador)
    {
        assert(denominador != 0);
    }

    // constructor por copia
    Fraccion(const Fraccion& copy) :
        m_numerador(copy.m_numerador), m_denominador(copy.m_denominador)
    {
        // no necesitamos comprobar si el denominador es 0 al ser una copia
        std::cout << "constructor por copia llamado\n"; // para ver que funciona
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
    int getNumerador() { return m_numerador; }
    void setNumerador(int numerador) { m_numerador = numerador; }
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}

Fraccion hacerNegativa(Fraccion f) // quizá mejor hacer referencia const
{
    f.setNumerador(-f.getNumerador());
    return f;
}

int main()
{
    Fraccion sieteQuintos(7, 5);
    std::cout << hacerNegativa(sieteQuintos);

    return 0;
}
#endif


#include <iostream>
class Cualquiera
{
public:
    Cualquiera() = default;
    Cualquiera(const Cualquiera&)
    {
        std::cout << "constructor por copia llamado\n";
    }
};

Cualquiera foo()
{
    return Cualquiera(); // constructor por copia llamado aquí
}
Cualquiera goo()
{
    Cualquiera s;
    return s; // constructor por copia llamado aquí
}

int main()
{
    std::cout << "Inicializar primero\n";
    Cualquiera primero = foo(); // constructor por copia llamado aquí

    std::cout << "Inicializar segundo\n";
    Cualquiera segundo = goo(); // constructor por copia llamado aquí
}


#if 0
#endif

