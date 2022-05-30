#if 0
#include <iostream>

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros)
        : m_euros{ euros }
    {}

    // sumar Euros + Euros usando una función amiga
    friend Euros operator+(const Euros& c1, const Euros& c2);

    int getEuros() const { return m_euros; }
};

// nota: esta función no es una función miembro
Euros operator+(const Euros& c1, const Euros& c2)
{
    // usa el constructor Euros y operator+(int, int)
    // podemos acceder a m_euros directamente porque esta es una función amiga
    return { c1.m_euros + c2.m_euros };
}

int main()
{
    Euros euros1{ 7 };
    Euros euros2{ 3};
    Euros sumarEuros{ euros1 + euros2 };
    std::cout << "Tengo " << sumarEuros.getEuros() << " euros.\n";

    return 0;
}
#endif


#include <iostream>

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros)
        : m_euros{ euros }
    {}

    int getEuros() const { return m_euros; }
};

// nota: esta función no es una función miembro y tampoco una función amiga
Euros operator+(const Euros& c1, const Euros& c2)
{
    // usa el constructor Euros y operator+(int, int)
    // no necesitamos acceder a miembros privados aquí
    return Euros{ c1.getEuros() + c2.getEuros() };
}

int main()
{
    Euros euros1{ 7 };
    Euros euros2{ 3 };
    Euros sumarEuros{ euros1 + euros2 };
    std::cout << "Tengo " << sumarEuros.getEuros() << " euros.\n";

    return 0;
}





