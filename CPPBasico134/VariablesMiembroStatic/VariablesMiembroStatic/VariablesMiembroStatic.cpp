#if 0
#include <iostream>

int generarID()
{
    static int s_id{ 0 };
    return ++s_id;
}

int main()
{
    std::cout << generarID() << '\n';
    std::cout << generarID() << '\n';
    std::cout << generarID() << '\n';

    return 0;
}



#include <iostream>

class Cualquiera
{
public:
    int m_valor{ 1 };
};

int main()
{
    Cualquiera primero;
    Cualquiera segundo;

    primero.m_valor = 2;

    std::cout << primero.m_valor << '\n';
    std::cout << segundo.m_valor << '\n';

    return 0;
}



#include <iostream>

class Cualquiera
{
public:
    static int s_valor;
};

//int Cualquiera::s_valor{ 1 };

int main()
{
    Cualquiera primero;
    Cualquiera segundo;

    primero.s_valor = 2;

    std::cout << primero.s_valor << '\n';
    std::cout << segundo.s_valor << '\n';
    return 0;
}





#include <iostream>

class Cualquiera
{
public:
    
    static int s_valor; // declara la variable miembro como static
};

 int Cualquiera::s_valor{ 1 } ; // define la variable miembro static

int main()
{
    // nota: no estamos instanciando ningún objeto de tipo Cualquiera
    
    Cualquiera::s_valor = 2;
    std::cout << Cualquiera::s_valor << '\n';
    return 0;
}




#include <iostream>
class Foo
{
public:
    static const int s_valor{ 4 }; // un int static const puede ser definido e inicializado directamente
};

int main()
{
    Foo foo;
    std::cout << Foo::s_valor << '\n';
    std::cout << foo. s_valor << '\n';
}





#include <array>
#include <iostream>

class Foo
{
public:
    static constexpr double s_valor{ 2.2 }; // correcto
    // esto incluso funciona para las clases que admitan la inicialización constexpr
    static constexpr std::array<int, 3> s_array{ 1, 2, 3 }; 
};


int main()
{
	Foo foo;
	std::cout << Foo::s_valor << '\n';
	std::cout << foo.s_valor << '\n';
	std::cout << Foo::s_array[0] << '\n';
	std::cout << foo.s_array[0] << '\n';
}



#include <iostream>
class Foo
{
public:
    // un int static inline puede ser declarado e inicializado directamente (C++17)
    static inline int s_valor{ 4 }; 
};

int main()
{
	Foo foo;
	std::cout << Foo::s_valor << '\n';
	std::cout << foo.s_valor << '\n';
}
#endif




#include <iostream>

class Cualquiera
{
private:
    static inline int s_generadorID{ 1 }; // C++17
//  static int s_generadorID;              // Usar en su lugar para C++14 ó más viejo
    int m_id{ };

public:
    Cualquiera() : m_id{ s_generadorID++ } // toma el siguiente valor del generador id
    {}

    int getID() const { return m_id; }
};

// Para C++14 o anterior, tenemos que inicializzar el miembro static no-const fuera de la definición de clase
// definimos e inicializamos s_generadorID fuera de la Clase aunque esté declarado como private
// int Cualquiera::s_generadorID { 1 }; // debes descomentar está línea para C++ 14 o anterior

int main()
{
    Cualquiera primero;
    Cualquiera segundo;
    Cualquiera tercero;

    std::cout << primero.getID() << '\n';
    std::cout << segundo.getID() << '\n';
    std::cout << tercero.getID() << '\n';
    return 0;
}




#if 0

#endif