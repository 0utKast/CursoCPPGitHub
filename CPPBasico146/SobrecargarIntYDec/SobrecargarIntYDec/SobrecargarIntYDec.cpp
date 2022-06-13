#if 0

#include <iostream>

class Digito
{
private:
    int m_digito;
public:
    Digito(int digito = 0)
        : m_digito{ digito }
    {
    }

    Digito& operator++();
    Digito& operator--();

    friend std::ostream& operator<< (std::ostream& out, const Digito& d);
};

Digito& Digito::operator++()
{
    // Si nuestro número ya es 9, vuelve a 0
    if (m_digito == 9)
        m_digito = 0;
    // en otro caso, incrementa al siguiente número
    else
        ++m_digito;

    return *this;
}

Digito& Digito::operator--()
{
    // Si nuestro número ya es 0, vuelve a 9
    if (m_digito == 0)
        m_digito = 9;
    // en otro caso, decrementa al siguiente número
    else
        --m_digito;

    return *this;
}

std::ostream& operator<< (std::ostream& out, const Digito& d)
{
    out << d.m_digito;
    return out;
}

int main()
{
    Digito digito{ 8 };

    std::cout << digito;
    std::cout << ++digito;
    std::cout << ++digito;
    std::cout << --digito;
    std::cout << --digito;
    return 0;
}
#endif




#include <iostream>
class Digito
{
private:
    int m_digito;
public:
    Digito(int digito = 0)
        : m_digito{ digito }
    {
    }

    Digito& operator++(); // prefijo no tiene parámetro
    Digito& operator--(); // prefijo no tiene parámetro

    Digito operator++(int); // posfijo tiene un parámetro int
    Digito operator--(int); // posfijo tiene un parámetro int

    friend std::ostream& operator<< (std::ostream& out, const Digito& d);
};

// Sin parámetro significa que este es un operator++ prefijo
Digito& Digito::operator++()
{
    // Si nuestro número ya es 9, vuelve a 0
    if (m_digito == 9)
        m_digito = 0;
    // en otro caso, incrementa al siguiente número
    else
        ++m_digito;

    return *this;
}

// Sin parámetro significa que es un operator-- prefijo
Digito& Digito::operator--()
{
    // Si nuestro número ya es 0, vuelve a 9
    if (m_digito == 0)
        m_digito = 9;
    // en otro caso, decrementa al número anterior
    else
        --m_digito;

    return *this;
}

// el parámetro int significa que es un operator++ posfijo
Digito Digito::operator++(int)
{
    // Crea una variable temporal con nuestro dígito actual
    Digito temp{ *this };

    // Usa el operator prefijo para incrementar este dígito
    ++(*this); // incrementa en 1 el objeto

    // devuelve resultado temporal
    return temp; // devuelve el estado salvado antes del incremento
}

// el parámetro int significa que es un operator-- posfijo
Digito Digito::operator--(int)
{
    // Crea una variable temporal con nuestro dígito actual
    Digito temp{ *this };

    // Usa el operator prefijo para decrementar este dígito
    --(*this); // disminuye en 1 el objeto

    // devuelve el resultado temporal
    return temp; // devuelve el estado salvado antes del decremento
}

std::ostream& operator<< (std::ostream& out, const Digito& d)
{
    out << d.m_digito;
    return out;
}

int main()
{
    Digito digito(5);

    std::cout << digito;
    std::cout << ++digito; // llama a Digito::operator++();
    std::cout << digito++; // llama a Digito::operator++(int);
    std::cout << digito;
    std::cout << --digito; // llama a Digito::operator--();
    std::cout << digito--; // llama a Digito::operator--(int);
    std::cout << digito;

    return 0;
}



