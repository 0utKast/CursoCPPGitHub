#include <string>
#include <iostream>

class Personaje
{
    // Hacemos todos los miembros públicos, por simplificar
public:
    std::string m_nombre{};
    int m_edad{};

    Personaje(const std::string& nombre = "", int edad = 0)
        : m_nombre{ nombre }, m_edad{ edad }
    {
    }

    const std::string& getNombre() const { return m_nombre; }
    int getEdad() const { return m_edad; }

};

class Altmer : public Personaje
{
    // Hacemos todos los miembros públicos, por simplificar
public:
    double m_poderMagico{};
    int m_numeroHechizos{};

    Altmer(double poderMagico = 0.0, int numeroHechizos = 0)
        : m_poderMagico{ poderMagico }, m_numeroHechizos{ numeroHechizos }
    {
    }
};

// Redguard hereda públicamente de Personaje
class Redguard : public Personaje
{
public:
    double m_fuerzaBase{};
    double m_estaminaBase{};

    Redguard(double fuerzaBase = 0.0, double estaminaBase = 0.0)
        : m_fuerzaBase{ fuerzaBase }, m_estaminaBase{ estaminaBase }
    {
    }

    void imprimirNombreYFuerza() const
    {
        std::cout << m_nombre << ": " << m_fuerzaBase << '\n';
    }
};

class JefeAltmer : public Altmer
{
public:
    // Puede mandar hasta 5 guerreros
    long m_guerrerosIDs[5]{};
};

int main()
{
    Redguard campeador{ 40.24, 15.34 };
    campeador.m_nombre = "Campeador"; // m_nombre es público
    campeador.imprimirNombreYFuerza();
    return 0;
}



#if 0


#include <iostream>
int main()
{
    // Crear un nuevo objeto Altmer
    Altmer outkast{};
    // Variable pública. Asignación directa.
    outkast.m_nombre = "OutKast";
    // Imprime el nombre. Usamos método getNombre()
	// heredado de Personaje
    std::cout << outkast.getNombre() << '\n'; 
    return 0;
}
#endif






