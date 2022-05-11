
#if 0
class Acumulador
{
private:
    int m_valor{ 0 };

public:
    void sumar(int valor) { m_valor += valor; }

    // Hacer la función () una amiga de esta clase
    friend void restablecer(Acumulador& acumulador);
};

// reset() es ahora una amiga de la clase Acumulador
void restablecer(Acumulador& acumulador)
{
    // Y puede acceder a los datos privados de objetos Acumulador
    acumulador.m_valor = 0;
}

int main()
{
    Acumulador acu;
    acu.sumar(5); // suma 5 al acumulador
    restablecer(acu); // restablece el acumulador a 0

    return 0;
}




#include <iostream>
class Valor
{
private:
    int m_valor{};

public:
    Valor(int valor)
        : m_valor{ valor }
    {
    }

    friend bool esIgual(const Valor& valor1, const Valor& valor2);
};

bool esIgual(const Valor& valor1, const Valor& valor2)
{
    return (valor1.m_valor == valor2.m_valor);
}

int main()
{
    Valor v1{ 5 };
    Valor v2{ 6 };
    std::cout << std::boolalpha << esIgual(v1, v2);

    return 0;
}







#include <iostream>

class Humedad;

class Temperatura
{
private:
    int m_temp{};

public:
    Temperatura(int temp = 0)
        : m_temp{ temp }
    {
    }

    friend void imprimirTiempo(const Temperatura& temperatura, const Humedad& humedad);
};

class Humedad
{
private:
    int m_humedad{};

public:
    Humedad(int humedad = 0)
        : m_humedad{ humedad }
    {
    }

    friend void imprimirTiempo(const Temperatura& temperatura, const Humedad& humedad);
};

void imprimirTiempo(const Temperatura& temperatura, const Humedad& humedad)
{
    std::cout << "La temperatura es: " << temperatura.m_temp <<
        " y la humedad es: " << humedad.m_humedad << '\n';
}

int main()
{
    Humedad hum{ 10 };
    Temperatura temp{ 12 };

    imprimirTiempo(temp, hum);

    return 0;
}



#include <iostream>
class Almacenar
{
private:
    int m_nValor{};
    double m_dValor{};
public:
    Almacenar(int nValor, double dValor)
        : m_nValor{ nValor }, m_dValor{ dValor }
    {
    }

    // Hacer la clase Mostrar amiga de Almacenar
    friend class Mostrar;
};

class Mostrar
{
private:
    bool m_mostrarIntPrimero;

public:
    Mostrar(bool mostrarIntPrimero)
        : m_mostrarIntPrimero{ mostrarIntPrimero }
    {
    }

    void mostrarItem(const Almacenar& almacenar)
    {
        if (m_mostrarIntPrimero)
            std::cout << almacenar.m_nValor << ' ' << almacenar.m_dValor << '\n';
        else // mostrar double primero
            std::cout << almacenar.m_dValor << ' ' << almacenar.m_nValor << '\n';
    }
};

int main()
{
    Almacenar almacenar{ 5, 6.7 };
    Mostrar mostrar{ false };

    mostrar.mostrarItem(almacenar);

    return 0;
}





#include <iostream>

class Mostrar; // declaración anticipada para la clase Mostrar

class Almacenar
{
private:
    int m_nValor{};
    double m_dValor{};
public:
    Almacenar(int nValor, double dValor)
        : m_nValor{ nValor }, m_dValor{ dValor }
    {
    }

    //  Hacer la función miembro Mostrar::MostrarItem  amiga de la clase Almacenar
    friend void Mostrar::MostrarItem(const Almacenar& almacenar); // error: Almacenar no ha tenido acceso a la definición completa de la clase Mostrar
};

class Mostrar
{
private:
    bool m_MostrarIntPrimero{};

public:
    Mostrar(bool MostrarIntPrimero)
        : m_MostrarIntPrimero{ MostrarIntPrimero }
    {
    }

    void MostrarItem(const Almacenar& almacenar)
    {
        if (m_MostrarIntPrimero)
            std::cout << almacenar.m_nValor << ' ' << almacenar.m_dValor << '\n';
        else // Mostrar double primero
            std::cout << almacenar.m_dValor << ' ' << almacenar.m_nValor << '\n';
    }
};







#include <iostream>


class Mostrar
{
private:
    bool m_mostrarIntPrimero{};

public:
    Mostrar(bool mostrarIntPrimero)
        : m_mostrarIntPrimero{ mostrarIntPrimero }
    {
    }

    void mostrarItem(const Almacenar& almacenar) // error: el compilador no sabe lo que es  Almacenar
    {
        if (m_mostrarIntPrimero)
            std::cout << almacenar.m_nValor << ' ' << almacenar.m_dValor << '\n';
        else // mostrar double primero
            std::cout << almacenar.m_dValor << ' ' << almacenar.m_nValor << '\n';
    }
};



class Almacenar
{
private:
    int m_nValor{};
    double m_dValor{};
public:
    Almacenar(int nValor, double dValor)
        : m_nValor{ nValor }, m_dValor{ dValor }
    {
    }

    // Hacer la función miembro Mostrar::mostrarItem  una amiga de la clase Almacenar
    friend void Mostrar::mostrarItem(const Almacenar& almacenar);
};
#endif



#include <iostream>
class Almacenar; // declaración anticipada para la clase Almacenar

class Mostrar
{
private:
    bool m_mostrarIntPrimero{};

public:
    Mostrar(bool mostrarIntPrimero)
        : m_mostrarIntPrimero{ mostrarIntPrimero }
    {
    }

    void mostrarItem(const Almacenar& almacenar); // declaración anticipada arriba de la clase almacenar necesaria para esta línea
};

class Almacenar // definición completa de la clase almacenar
{
private:
    int m_nValor{};
    double m_dValor{};
public:
    Almacenar(int nValor, double dValor)
        : m_nValor{ nValor }, m_dValor{ dValor }
    {
    }

    // Hacer la función miembro Mostrar::mostrarItem  amiga de la clase Almacenar requiere haber visto la definición completa de la Clase)
    friend void Mostrar::mostrarItem(const Almacenar& almacenar);
};

// Ahora podemos definir Mostrar::mostrarItem, que necesita haber visto la definición completa de la clase Almacenar
void Mostrar::mostrarItem(const Almacenar& almacenar)
{
    if (m_mostrarIntPrimero)
        std::cout << almacenar.m_nValor << ' ' << almacenar.m_dValor << '\n';
    else // mostrar double first
        std::cout << almacenar.m_dValor << ' ' << almacenar.m_nValor << '\n';
}



int main()
{
    Almacenar almacenar(5, 6.7);
    Mostrar mostrar(false);

    mostrar.mostrarItem(almacenar);

    return 0;
}

#if 0
#endif
