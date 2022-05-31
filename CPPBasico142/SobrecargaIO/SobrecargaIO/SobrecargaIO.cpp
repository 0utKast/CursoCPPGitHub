#if 0
#include <iostream>
class Punto
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Punto(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};
int main() {
    Punto punto{ 5.0, 6.0, 7.0 };

    std::cout << "Punto(" << punto.getX() << ", " <<
        punto.getY() << ", " <<
        punto.getZ() << ')';
}


#include <iostream>
class Punto
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Punto(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

    void imprimir() const
    {
        std::cout << "Punto(" << m_x << ", " << m_y << ", " << m_z << ')';
    }
};

int main()
{
    const Punto punto{ 5.0, 6.0, 7.0 };

    std::cout << "Mi punto es: ";
    punto.imprimir();
    std::cout << " en el espacio Cartesiano.\n";
}


#include <iostream>
class Punto
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Punto(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {    
    }

    friend std::ostream& operator<< (std::ostream& out, const Punto& punto);
};

std::ostream& operator<< (std::ostream& out, const Punto& punto)
{
    // Como operator<< es amiga de la clase Punto, 
    //podemos acceder directamente a los miembros de Punto.
    // output real se hace aquí
    out << "Punto(" << punto.m_x << ", " << punto.m_y << ", " << punto.m_z << ')'; 

    return out; // return std::ostream así podemos encadenar llamadas a operator<<
}

int main()
{
    const Punto punto1{ 2.0, 3.0, 4.0 };
	
    std::cout << punto1 << std::endl;
	
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
    Punto(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Punto& punto);
};

std::ostream& operator<< (std::ostream& out, const Punto& punto)
{
    // Como operator<< es amiga de la clase Punto, podemos acceder directamente a los miembros de Punto.
    out << "Punto(" << punto.m_x << ", " << punto.m_y << ", " << punto.m_z << ')';

    return out;
}

int main()
{
    Punto punto1{ 2.0, 3.5, 4.0 };
    Punto punto2{ 6.0, 7.5, 8.0 };

    std::cout << punto1 << ' ' << punto2 << '\n';

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
    Punto(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Punto& punto);
    friend std::istream& operator>> (std::istream& in, Punto& punto);
};

std::ostream& operator<< (std::ostream& out, const Punto& punto)
{
    //Como operator<< es amiga de la clase Punto, podemos acceder directamente a los miembros de Punto.
    out << "Punto(" << punto.m_x << ", " << punto.m_y << ", " << punto.m_z << ')';

    return out;
}

std::istream& operator>> (std::istream& in, Punto& punto)
{
    //Como operator>> es amiga de la clase Punto, podemos acceder directamente a los miembros de Punto.
    // observa que el parámetro punto debe ser no-const de modo que podemos modificar los miembros de la clase con los valores input
    in >> punto.m_x;
    in >> punto.m_y;
    in >> punto.m_z;

    return in;
}

int main()
{
    std::cout << "Escribe un punto: ";

    Punto punto;
    std::cin >> punto;

    std::cout << "Has escrito: " << punto << '\n';

    return 0;
}
#if 0
#endif