
#if 0
#include <iostream>
#include <string>
#include <string_view>

class Computadora
{
private:
    std::string m_marca;
    std::string m_modelo;

public:
    Computadora(std::string_view marca, std::string_view modelo)
        : m_marca{ marca }, m_modelo{ modelo }
    {
    }

    friend bool operator== (const Computadora& c1, const Computadora& c2);
    friend bool operator!= (const Computadora& c1, const Computadora& c2);
};

bool operator== (const Computadora& c1, const Computadora& c2)
{
    return (c1.m_marca == c2.m_marca &&
        c1.m_modelo == c2.m_modelo);
}

bool operator!= (const Computadora& c1, const Computadora& c2)
{
    return (c1.m_marca != c2.m_marca ||
        c1.m_modelo != c2.m_modelo);
}

int main()
{
    Computadora thinkpad{ "Lenovo", "ThinkPad" };
    Computadora legion{ "Lenovo", "Legion" };

    if (thinkpad == legion)
        std::cout << "Un ThinkPad y un Legion son lo mismo.\n";

    if (thinkpad != legion)
        std::cout << "Un ThinkPad y un Legion no son lo mismo.\n";

    return 0;
}




#include <iostream>

class Euros
{
private:
    int m_euros;

public:
    Euros(int euros)
        : m_euros{ euros }
    {}

    friend bool operator== (const Euros& c1, const Euros& c2);
    friend bool operator!= (const Euros& c1, const Euros& c2);

    friend bool operator< (const Euros& c1, const Euros& c2);
    friend bool operator> (const Euros& c1, const Euros& c2);

    friend bool operator<= (const Euros& c1, const Euros& c2);
    friend bool operator>= (const Euros& c1, const Euros& c2);
};

bool operator== (const Euros& c1, const Euros& c2)
{
    return c1.m_euros == c2.m_euros;
}

bool operator!= (const Euros& c1, const Euros& c2)
{
    return c1.m_euros != c2.m_euros;
}

bool operator< (const Euros& c1, const Euros& c2)
{
    return c1.m_euros < c2.m_euros;
}

bool operator> (const Euros& c1, const Euros& c2)
{
    return c1.m_euros > c2.m_euros;
}

bool operator<= (const Euros& c1, const Euros& c2)
{
    return c1.m_euros <= c2.m_euros;
}

bool operator>= (const Euros& c1, const Euros& c2)
{
    return c1.m_euros >= c2.m_euros;
}

int main()
{
    Euros compra{ 10 };
    Euros venta{ 5 };

    if (compra > venta)
        std::cout << "La compra es mayor que la venta.\n";
    if (compra >= venta)
        std::cout << "La compra es mayor o igual que la venta.\n";
    if (compra < venta)
        std::cout << "La venta es mayor que la compra.\n";
    if (compra <= venta)
        std::cout << "La venta es mayor o igual que la compra.\n";
    if (compra == venta)
        std::cout << "La venta es igual a la compra.\n";
    if (compra != venta)
        std::cout << "La venta no es igual a la compra.\n";

    return 0;
}




#include <iostream>

class Euros
{
private:
    int m_euros;

public:
    Euros(int euros)
        : m_euros{ euros }
    {}

    friend bool operator== (const Euros& c1, const Euros& c2);
    friend bool operator!= (const Euros& c1, const Euros& c2);

    friend bool operator< (const Euros& c1, const Euros& c2);
    friend bool operator> (const Euros& c1, const Euros& c2);

    friend bool operator<= (const Euros& c1, const Euros& c2);
    friend bool operator>= (const Euros& c1, const Euros& c2);

};

bool operator== (const Euros& c1, const Euros& c2)
{
    return c1.m_euros == c2.m_euros;
}

bool operator!= (const Euros& c1, const Euros& c2)
{
    return !(operator==(c1, c2));
}

bool operator< (const Euros& c1, const Euros& c2)
{
    return c1.m_euros < c2.m_euros;
}

bool operator> (const Euros& c1, const Euros& c2)
{
    return operator<(c2, c1);
}

bool operator<= (const Euros& c1, const Euros& c2)
{
    return !(operator>(c1, c2));
}

bool operator>= (const Euros& c1, const Euros& c2)
{
    return !(operator<(c1, c2));
}

int main()
{
    Euros compra{ 10 };
    Euros venta{ 5 };

    if (compra > venta)
        std::cout << "La compra es mayor que la venta.\n";
    if (compra >= venta)
        std::cout << "La compra es mayor o igual que la venta.\n";
    if (compra < venta)
        std::cout << "La venta es mayor que la compra.\n";
    if (compra <= venta)
        std::cout << "La venta es mayor o igual que la compra.\n";
    if (compra == venta)
        std::cout << "La venta es igual a la compra.\n";
    if (compra != venta)
        std::cout << "La venta no es igual a la compra.\n";

    return 0;
}




//Práctica 1: añade los seis operadores de comparación a la clase Fraccion
#include <iostream>
#include <numeric> // para std::gcd

class Fraccion
{
private:
    int m_numerador{};
    int m_denominador{};

public:
    Fraccion(int numerador = 0, int denominador = 1) :
        m_numerador{ numerador }, m_denominador{ denominador }
    {
        // ¡Ponemos reduce() en el constructor para asegurarnos 
        // que cualquier fracción nueva que hagamos se reduzca!
        // Cualquier fracción que se sobrescriba deberá volver a reducirse
        reduce();
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerador, m_denominador) };
        if (gcd)
        {
            m_numerador /= gcd;
            m_denominador /= gcd;
        }
    }

	
/*
//para versiones anteriores a C++ 17 usamos esta función
#include <cmath>

    int gcd(int a, int b) {
        return (b == 0) ? std::abs(a) : gcd(b, a % b);
    }
*/
    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}

int main()
{
    Fraccion f1{ 3, 2 };
    Fraccion f2{ 5, 8 };
#if 0
    std::cout << f1 << ((f1 == f2) ? " == " : " no == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " no != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " no < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " no > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " no <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " no >= ") << f2 << '\n';
#endif
    return 0;
}

#endif



// Solución práctica añadir operadores de sobrecarga a la clase Fraccion
#include <iostream>
#include <numeric> // para std::gcd

class Fraccion
{
private:
    int m_numerador{};
    int m_denominador{};

public:
    Fraccion(int numerador = 0, int denominador = 1) :
        m_numerador{ numerador }, m_denominador{ denominador }
    {
        // ¡Ponemos reduce() en el constructor para asegurarnos de que cualquier fracción nueva que hagamos se reduzca!
        // Cualquier fracción que se sobrescriba deberá volver a reducirse
        reduce();
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerador, m_denominador) };
        if (gcd)
        {
            m_numerador /= gcd;
            m_denominador /= gcd;
        }
    }

    friend bool operator== (const Fraccion& f1, const Fraccion& f2);
    friend bool operator!= (const Fraccion& f1, const Fraccion& f2);

    friend bool operator< (const Fraccion& f1, const Fraccion& f2);
    friend bool operator> (const Fraccion& f1, const Fraccion& f2);

    friend bool operator<= (const Fraccion& f1, const Fraccion& f2);
    friend bool operator>= (const Fraccion& f1, const Fraccion& f2);

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}

bool operator== (const Fraccion& f1, const Fraccion& f2)
{
    return (f1.m_numerador == f2.m_numerador) && (f1.m_denominador == f2.m_denominador);
}

bool operator!= (const Fraccion& f1, const Fraccion& f2)
{
    return !(operator==(f1, f2));
}

bool operator< (const Fraccion& f1, const Fraccion& f2)
{
    return (f1.m_numerador * f2.m_denominador < f2.m_numerador* f1.m_denominador);
}

bool operator> (const Fraccion& f1, const Fraccion& f2)
{
    return operator<(f2, f1);
}

bool operator<= (const Fraccion& f1, const Fraccion& f2)
{
    return !(operator>(f1, f2));
}

bool operator>= (const Fraccion& f1, const Fraccion& f2)
{
    return !(operator<(f1, f2));
}

int main()
{
    Fraccion f1{ 3, 2 };
    Fraccion f2{ 5, 8 };

    std::cout << f1 << ((f1 == f2) ? " == " : " no == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " no != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " no < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " no > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " no <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " no >= ") << f2 << '\n';

    return 0;
}

