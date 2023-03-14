#if 0
#include <iostream>

template <typename T>
struct analizador;             // [1] declaraci�n de plantilla

void manejar(double valor)  // [2] definici�n manejar(double)
{
    std::cout << "procesando un double: " << valor << '\n';
}

template <typename T>
struct analizador              // [3] definici�n plantilla
{
    void analiza()
    {
        manejar(42);          // [4] nombre no-dependiente
    }
};

void manejar(int valor)     // [5] definici�n manejar(int) 
{
    std::cout << "procesando un int: " << valor << '\n';
}

int main()
{
        analizador<int> p;       // [6] instanciaci�n plantilla
        p.analiza();
}






#include <iostream>
template <typename T>
struct manejador          // [1] definici�n de plantilla
{
    void manejar(T valor)
    {
        std::cout << "manejador<T>: " << valor << '\n';
    }
};

template <typename T>
struct analizador           // [2] definici�n de plantilla
{
    void analiza(T arg)
    {
        arg.manejar(42);   // [3] nombre dependiente
    }
};

template <>
struct manejador<int>     // [4] especial�zaci�n de plantilla
{
    void manejar(int valor)
    {
        std::cout << "manejador<int>: " << valor << '\n';
    }
};

int main()
{
    manejador<int> h;         // [5] instanciaci�n de plantilla
    analizador<manejador<int>> p; // [6] instanciaci�n de plantilla
    p.analiza(h);
}
#endif


#include <iostream>
template <typename T>
struct analizador_base
{
    void init()
    {
        std::cout << "init\n";
    }
};
template <typename T>
struct analizador : analizador_base<T>
{
    void analizar()
    {
        init();        // error: identificador no encontrado
        std::cout << "analizar\n";
    }
};
int main()
{
    analizador<int> p;
    p.analizar();
}


#if 0
#include <iostream>
template <typename T>
struct analizador_base
{
    void init()
    {
        std::cout << "init\n";
    }
};

template <typename T>
struct analizador : analizador_base<T>
{
    void analizar()
    {
        this->init();        // OK
        std::cout << "analizar\n";
    }
};

template <>
struct analizador_base<int>
{
    void init()
    {
        std::cout << "init especializado\n";
    }
};

int main()
{
    analizador<int> p1;
    p1.analizar();
    analizador<double> p2;
    p2.analizar();
}

#endif
