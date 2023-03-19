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


template <typename T>
struct analizador_base
{
    using tipo_valor = T;
};
template <typename T>
struct analizador : analizador_base<T>
{
    void analizar()
    {
        tipo_valor v{};                       // [1] error
        // or
        analizador_base<T>::tipo_valor v{};       // [2] error
        std::cout << "analizar\n";
    }
};
#endif

#if 0
#include <iostream>
template <typename T>
struct analizador_base
{
    using tipo_valor = T;
};

template <typename T>
struct analizador : analizador_base<T>
{
    void analizar()
    {
        typename analizador_base<T>::tipo_valor v{}; // [3] OK
        std::cout << "analizar\n";
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



#include <map>
#include <string>
struct atributos_diccionario
{
    using tipo_clave = int;
    using tipo_mapa = std::map<tipo_clave, std::string>;
    static constexpr int identidad = 1;
};
template <typename T>
struct diccionario : T::tipo_mapa      // [1]
{
    int clave_inicio{ T::identidad };   // [2]
    T::tipo_clave clave_siguiente;   // [3]
};
int main()
{
    diccionario<atributos_diccionario> d;
}



