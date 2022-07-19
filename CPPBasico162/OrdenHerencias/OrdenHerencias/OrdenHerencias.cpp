#if 0
#include <iostream>
class Padre
{
public:
    int m_id{};

    Padre(int id = 0)
        : m_id(id)
    {

    }


    int getId() const { return m_id; }
};

class Derivada : public Padre
{
public:
    double m_salario{};

    Derivada(double salario = 0.0)
        : m_salario(salario)
    {

    }

    double getSalario() const { return m_salario; }
};

int main()
{
    Padre padre;
    Derivada derivada;

    return 0;
}




#include <iostream>
class Padre
{
public:
    int m_id{};

    Padre(int id = 0)
        : m_id(id)
    {
        std::cout << "Padre\n";
    }


    int getId() const { return m_id; }
};

class Derivada : public Padre
{
public:
    double m_salario{};

    Derivada(double salario = 0.0)
        : m_salario(salario)
    {
        std::cout << "Derivada\n";
    }

    double getSalario() const { return m_salario; }
};

int main()
{
    std::cout << "Instanciando Padre\n";
    Padre padre;
    std::cout << "Instanciando Derivada\n";
    Derivada derivada;

    return 0;
}
#endif

#include <iostream>

class Animales
{
public:
    Animales()
    {
        std::cout << "Animales\n";
    }
};

class Vertebrados : public Animales
{
public:
    Vertebrados()
    {
        std::cout << "Vertebrados\n";
    }
};

class Mamiferos : public Vertebrados
{
public:
    Mamiferos()
    {
        std::cout << "Mamiferos\n";
    }
};

class Humanos : public Mamiferos
{
public:
    Humanos()
    {
        std::cout << "Humanos\n";
    }
};

int main()
{
    std::cout << "Construyendo Animales: \n";
    Animales a;

    std::cout << "Construyendo Vertebrados: \n";
    Vertebrados b;

    std::cout << "Construyendo Mamiferos: \n";
    Mamiferos c;

    std::cout << "Construyendo Humanos: \n";
    Humanos d;
}

#if 0
#endif