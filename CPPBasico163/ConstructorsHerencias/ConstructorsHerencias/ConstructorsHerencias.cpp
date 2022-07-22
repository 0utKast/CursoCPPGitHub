
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
    Padre padre{ 5 }; // usa constructor Padre(int)
	
    Derivada derivada{ 1.3 }; // usa constructor Derivada(double)

    return 0;
}

#endif



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

    Derivada(double salario = 0.0, int id = 0)
        : Padre{ id } // Llama al constructor Padre(int) con el valor de id
        , m_salario{ salario }
    {
    }

    double getSalario() const { return m_salario; }
};


#include <iostream>

int main()
{
    Derivada derivada{ 1.3, 5 }; // usa constructor Derivada(double, int)
    std::cout << "Id: " << derivada.getId() << '\n';
    std::cout << "Salario: " << derivada.getSalario() << '\n';

    return 0;
}



#if 0


class Derivada : public Padre
{
public:
    double m_salario{};

    Derivada(double salario = 0.0, int id = 0)
        : m_salario{ salario }, m_id{ id }  // no trabaja
    {
    }

    double getSalario() const { return m_salario; }
};



class Derivada : public Padre
{
public:
    double m_salario{};

    Derivada(double salario = 0.0, int id = 0)
        : Padre{ id } // Llama al constructor Padre(int) con el valor de id
        , m_salario{ salario }
    {
    }

    double getSalario() const { return m_salario; }
};


#include <iostream>

int main()
{
    Derivada derivada{ 1.3, 5 }; // usa constructor Derivada(double, int)
    std::cout << "Id: " << derivada.getId() << '\n';
    std::cout << "Salario: " << derivada.getSalario() << '\n';

    return 0;
}


class Derivada : public Padre
{
public:
    double m_salario{};

    Derivada(double salario = 0.0, int id = 0)
        : m_salario{ salario }
    {
        m_id = id;
    }

    double getSalario() const { return m_salario; }
};


int main()
{
    Derivada derivada{ 1.3, 5 }; // usa constructor Derivada(double, int)
    std::cout << "Id: " << derivada.getId() << '\n';
    std::cout << "Salario: " << derivada.getSalario() << '\n';

    return 0;
}
#endif