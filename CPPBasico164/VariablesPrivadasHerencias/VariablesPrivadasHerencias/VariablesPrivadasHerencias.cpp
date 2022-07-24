#if 0
#include <iostream>
class Padre
{
private:
    int m_id{};
	
public:
    Padre(int id = 0)
        : m_id(id)
    {

    }


    int getId() const { return m_id; }
};

class Derivada : public Padre
{
private:	
    double m_salario{};
	
public:

    Derivada(double salario = 0.0, int id = 0)
        : Padre{ id } // Llama al constructor Padre(int) con el valor de id
        , m_salario{ salario }
    {
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



#include <string>
#include <string_view>

class Personaje
{
public:
    std::string m_nombre;
    int m_edad{};

    Personaje(const std::string_view nombre = "", int edad = 0)
        : m_nombre{ nombre }, m_edad{ edad }
    {
    }

    const std::string& getNombre() const { return m_nombre; }
    int getEdad() const { return m_edad; }
};

// Altmer hereda públicamente a Personaje
class Altmer : public Personaje
{
public:
    double m_poderMagico{};
    int m_numeroHechizos{};

    Altmer(double poderMagico = 0.0, int numeroHechizos = 0)
        : m_poderMagico{ poderMagico },
        m_numeroHechizos{ numeroHechizos }
    {
    }
};







#include <iostream>
#include <string>
#include <string_view>

class Personaje
{
private:
    std::string m_nombre;
    int m_edad{};

public:
    Personaje(const std::string_view nombre = "", int edad = 0)
        : m_nombre{ nombre }, m_edad{ edad }
    {
    }

    const std::string& getNombre() const { return m_nombre; }
    int getEdad() const { return m_edad; }

};
// Altmer hereda públicamente a Personaje
class Altmer : public Personaje
{
private:
    double m_poderMagico{};
    int m_numeroHechizos{};

public:
    Altmer(const std::string_view nombre = "", int edad = 0,
        double poderMagico = 0.0, int numeroHechizos = 0)
        // llama a Personaje(const std::string_view, int) para inicializarlos
        : Personaje{ nombre, edad } 
        , m_poderMagico{ poderMagico }, m_numeroHechizos{ numeroHechizos }
    {
    }

    double getPoderMagico() const { return m_poderMagico; }
    int getNumeroHechizos() const { return m_numeroHechizos; }
};

int main()
{
    Altmer alinor{ "Alinor Summer", 43, 0.635, 21 };

    std::cout << alinor.getNombre() << '\n';
    std::cout << alinor.getEdad() << '\n';
    std::cout << alinor.getPoderMagico() << '\n';
    std::cout << alinor.getNumeroHechizos() << '\n';

    return 0;
}

#endif



#include <iostream>

class Madre
{
public:
    Madre(int m)
    {
        std::cout << "Madre: " << m << '\n';
    }
};

class Hija : public Madre
{
public:
    Hija(int m, double h)
        : Madre{ m }
    {
        std::cout << "Hija: " << h << '\n';
    }
};

class Nieta : public Hija
{
public:
    Nieta(int m, double h, char n)
        : Hija{ m, h }
    {
        std::cout << "Nieta: " << n << '\n';
    }
};

int main()
{
    Nieta nieta{ 12, 7.1, 'D' };

    return 0;
}









