#if 0
#include <iostream>

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros) : m_euros{ euros } {}

    // Sobercarga -Euros con una función miembro
    Euros operator-() const;

    int getEuros() const { return m_euros; }
};

// nota: esta función es una función miembro
Euros Euros::operator-() const
{
    return -m_euros; // como el tipo de retorno es  Euros, hace una conversión 
                     //implícita de int a Euros usando el constructor Euros(int)
}

int main()
{
    const Euros euros{ 5 };
    std::cout << "Mi gasto ha sido de " << ( -euros).getEuros() << " euros\n";

    return 0;
}



#include <iostream>

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros) : m_euros{ euros } {}

    // Sobrecarga Euros con una función miembro
    Euros operator+() const;

    int getEuros() const { return m_euros; }
};

// nota: esta función es una función miembro
Euros Euros::operator+() const
{
    return +m_euros; // como el tipo de retorno es  Euros, hace una 
                     //conversión implícita de int a Euros usando el constructor Euros(int)
}

int main()
{
    const Euros euros{ -5 };
    std::cout << "Mi gasto ha sido de " << (+euros).getEuros() << " euros\n";

    return 0;
}



#include <iostream>

class Punto
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Punto(double x = 0.0, double y = 0.0, double z = 0.0) :
        m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    // Convierte un Punto en su equivalente negativo
    Punto operator- () const;

    // Devuelve true si el punto es configurado como el origen
    bool operator! () const;

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

// Convierte un Punto en su equivalente negativo
Punto Punto::operator- () const
{
    return { -m_x, -m_y, -m_z };
}

// Devuelve true si el punto es configurado como el origen, en otros caso, falso
bool Punto::operator! () const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main()
{
    Punto punto{}; // usa constructor predeterminado para configurar a (0.0, 0.0, 0.0)

    if (!punto)
        std::cout << "punto es configurado al origen.\n";
    else
        std::cout << "punto no es configurado como el origen.\n";

    return 0;
}




#include <iostream>

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros) : m_euros{ euros } {}

    // Sobercarga -Euros con una función miembro
    Euros operator-() const;

    // sumar Euros + Euros usando una función amiga
    friend Euros operator+(const Euros& e1, const Euros& e2);

    int getEuros() const { return m_euros; }
};

// nota: esta función es una función miembro
Euros Euros::operator-() const
{
    return -m_euros; // como el tipo de retorno es  Euros, hace una conversión implícita de int a Euros usando el constructor Euros(int)
}

// nota: esta función no es una función miembro
Euros operator+(const Euros& e1, const Euros& e2)
{
    // usa el constructor Euros y operator+(int, int)
    // podemos acceder a m_euros directamente porque esta es una función amiga
    return Euros{ e1.m_euros + e2.m_euros };
}

int main()
{
    const Euros euros1{ 5 };
	const Euros euros2{ 10 };
	const Euros euros3{ euros1+euros2 };
    std::cout << "Mi gasto ha sido de " << (-euros3).getEuros() << " euros\n";

    return 0;
}




#include <iostream>

class Punto
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Punto(double x = 0.0, double y = 0.0, double z = 0.0) :
        m_x{ x }, m_y{ y }, m_z{ z }
    {
    }  

    // Devuelve true si el punto es configurado como el origen
    bool operator! () const;    

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};


// Devuelve true si el punto es configurado como el origen, en otro caso, false
bool Punto::operator! () const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main()
{
    Punto punto{}; // usa constructor predeterminado para configurar a (0.0, 0.0, 0.0)

    if (!punto)
        std::cout << "punto es configurado al punto origen.\n";
    else
        std::cout << "punto no es configurado como el origen.\n";
	
    if (punto)
        std::cout << "punto es configurado al punto origen.\n";
    else
        std::cout << "punto no es configurado como el origen.\n";

    return 0;
}
#endif





#include <iostream>
class Punto
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Punto(double x = 0.0, double y = 0.0, double z = 0.0) :
        m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    // Devuelve true si el punto es configurado como el origen
    bool operator! () const;

    explicit operator bool() const
    {
        return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
    }


    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

// Devuelve true si el punto es configurado como el origen, en otro caso, false
bool Punto::operator! () const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main()
{
    Punto punto{}; // usa constructor predeterminado para configurar a (0.0, 0.0, 0.0)

    if (!punto)
        std::cout << "punto es configurado al punto origen.\n";
    else
        std::cout << "punto no es configurado como el origen.\n";

    if (punto)
        std::cout << "punto es configurado al punto origen.\n";
    else
        std::cout << "punto no es configurado como el origen.\n";

    return 0;
}





#if 0
#endif