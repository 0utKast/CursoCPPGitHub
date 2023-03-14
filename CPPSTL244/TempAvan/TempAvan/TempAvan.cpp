#if 0
#include <iostream>

template <typename T>
struct analizador;             // [1] declaración de plantilla

void manejar(double valor)  // [2] definición manejar(double)
{
    std::cout << "procesando un double: " << valor << '\n';
}

template <typename T>
struct analizador              // [3] definición plantilla
{
    void analiza()
    {
        manejar(42);          // [4] nombre no-dependiente
    }
};

void manejar(int valor)     // [5] definición manejar(int) 
{
    std::cout << "procesando un int: " << valor << '\n';
}

int main()
{
        analizador<int> p;       // [6] instanciación plantilla
        p.analiza();
}






#include <iostream>
template <typename T>
struct manejador          // [1] definición de plantilla
{
    void manejar(T valor)
    {
        std::cout << "manejador<T>: " << valor << '\n';
    }
};

template <typename T>
struct analizador           // [2] definición de plantilla
{
    void analiza(T arg)
    {
        arg.manejar(42);   // [3] nombre dependiente
    }
};

template <>
struct manejador<int>     // [4] especialízación de plantilla
{
    void manejar(int valor)
    {
        std::cout << "manejador<int>: " << valor << '\n';
    }
};

int main()
{
    manejador<int> h;         // [5] instanciación de plantilla
    analizador<manejador<int>> p; // [6] instanciación de plantilla
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
