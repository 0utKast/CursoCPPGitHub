#if 0
#include <iostream>

class Padre
{
private:
    int m_valor{};

public:
    Padre(int valor)
        : m_valor{ valor }
    {
    }

protected:
    void imprimirValor() const { std::cout << m_valor; }
};


class Derivada : public Padre
{
public:
    Derivada(int valor)
        : Padre{ valor }
    {
    }

    // Padre::imprimirValor fue heredado comno protected, así que resto programa sin acceso
    // Pero lo cambiamos a public con una declaración using
    using Padre::imprimirValor; // ¡Observa: sin paréntesis tras nombre función!
};

int main()
{
    Padre padre{ 12 };
    Derivada derivada{ 7 };

    // imprimirValor es public en Derivada, así que correcto:
    derivada.imprimirValor(); // imprime 7
    padre.imprimirValor(); //error
    return 0;
}


#include <iostream>
class Padre
{
public:
    int m_valor{};
};

class Derivada : public Padre
{
private:
    using Padre::m_valor;

public:
    Derivada(int valor)
        // No podemos inicializar m_valor, porque es miembro de Padre (Padre debe inicializarlo)
    {
        // Pero podemos asignarle un valor
        m_valor = valor; //no válido si fuera const o ref.
    }
};

int main()
{
    Derivada derivada{ 7 };

    // Error porque m_valor ha sido redefinida como private
    std::cout << derivada.m_valor;

    return 0;
}
#endif


#include <iostream>
class Padre
{
private:
    int m_valor{};

public:
    Padre(int valor)
        : m_valor{ valor }
    {
    }

    int getValor() const { return m_valor; }
};

class Derivada : public Padre
{
public:
    Derivada(int valor)
        : Padre{ valor }
    {
    }


    int getValor() = delete; // marca esta función como inaccesible
};

int main()
{
    Derivada derivada{ 12 };

    // Podemos llamar a la función Base::getValor() directamente
    std::cout << derivada.Padre::getValor();

    // O podemos convertir Derivada a una referencia Padre y getValor()  resolverá a Base::getValor()
    std::cout << static_cast<Padre&>(derivada).getValor();

    return 0;
}


#if 0
#endif
#if 0

int main()
{
    Derivada derivada{ 12 };

    // Error porque getValor( ) ha sido eliminada en Derivada
    std::cout << derivada.getValor();

    return 0;
}


#endif