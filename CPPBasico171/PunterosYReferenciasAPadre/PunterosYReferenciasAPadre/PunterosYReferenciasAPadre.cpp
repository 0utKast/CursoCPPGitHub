
#if 0
#include <iostream>
#include <string_view>
#include <string>

class Sanador
{
protected:
    std::string m_nombre;
	
    Sanador(std::string_view nombre)
        : m_nombre{ nombre }
    {
    }    

public:
    std::string_view getNombre() const { return m_nombre; }
    std::string_view hechizo() const { return "???"; }
	
    void informe(const Sanador& rSanador)
    {
        std::cout << rSanador.getNombre() << " lanza " << rSanador.hechizo() << '\n';
    }
};

class Altmer : public Sanador
{
public:
    Altmer(std::string_view nombre)
        : Sanador{ nombre }
    {
    }

    std::string_view hechizo() const { return "Lovilian"; }
	
    void informe(const Altmer& ganril)
    {
        std::cout << ganril.getNombre() << " lanza " << ganril.hechizo() << '\n';
    }
};

class Argoniano : public Sanador
{
public:
    Argoniano(std::string_view nombre)
        : Sanador{ nombre }
    {
    }

    std::string_view hechizo() const { return "Ajum-Tei"; }
	
    void informe(const Argoniano& nerei)
    {
        std::cout << nerei.getNombre() << " lanza " << nerei.hechizo() << '\n';
    }

};


#include <array>

int main()
{
    const Altmer ganril{ "Ganril" };
    const Altmer tragril{ "Tragril" };
    const Altmer ungantar{ "Ungantar" };

    const Argoniano nerei{ "Nerei" };
    const Argoniano ineius{ "Ineius" };
    const Argoniano milzara{ "Milzara" };

    // Configurar un array de punteros a sanadores, y configurar esos punteros a nuestros objetos Altmer y Argoniano
    // Nota: to_array necesita usar versión C++20 que visual studio a día de hoy(agosto 2022) no admite
    //const auto sanadores{ std::to_array<const Sanador*>({&ganril, &tragril, &ungantar, &nerei, &ineius, &milzara }) };

    // Antes C++20, debemos señalar específicamente  el tamaño del array
     const std::array<const Sanador*, 6> sanadores{ &ganril, &tragril, &ungantar, &nerei, &ineius, &milzara };

    for (const auto sanador : sanadores)
    {
        std::cout << sanador->getNombre() << " lanza " << sanador->hechizo() << '\n';
    }

    return 0;
}

















#include <array>

int main()
{
    const auto& altmers{ std::to_array<Altmer>({{ "Ganril" }, { "Tragril" }, { "Ungantar" }}) };
    const auto& argonianos{ std::to_array<Argoniano>({{ "Nerei" }, { "Ineius" }, { "Milzara" }}) };

    // Antes de C++20
    // const std::array<Altmer, 3> altmers{{ { "Ganril" }, { "Tragril }, { "Ungantar" } }};
    // const std::array<Argoniano, 3> argonianos{{ { "Nerei" }, { "Ineius" }, { "Milzara" } }};

    for (const auto& altmer : altmers)
    {
        std::cout << altmer.getNombre() << " lanza " << altmer.hechizo() << '\n';
    }

    for (const auto& argoniano : argonianos)
    {
        std::cout << argoniano.getNombre() << " lanza " << argoniano.hechizo() << '\n';
    }

    return 0;
}

#endif





#if 0


int main()
{
    Altmer ganril{ "Ganril" };
    ganril.informe( ganril);
    Argoniano nerei{ "Nerei" };
	nerei.informe( nerei); 
    Sanador& rSanador{ ganril };
    rSanador.informe(ganril);

    return 0;
}





int main()
{
    const Altmer ganril{ "Ganril" };
    std::cout << "El nombre del Altmer es " << ganril.getNombre() << ", y lanza el hechizo " << ganril.hechizo() << '\n';

    const Argoniano nerei{ "Nerei" };
    std::cout << "El nombre del Argoniano es " << nerei.getNombre() << ", y lanza el hechizo " << nerei.hechizo() << '\n';

    const Sanador* pSanador{ &ganril };
    std::cout << "El nombre de pSanador es " << pSanador->getNombre() << ", y lanza el hechizo " << pSanador->hechizo() << '\n';

    pSanador = &nerei;
    std::cout << "El nombre de pSanador es " << pSanador->getNombre() << ", y lanza el hechizo " << pSanador->hechizo() << '\n';

    return 0;
}













// Para prevenir slicing (aún no cubierto)
Sanador(const Sanador&) = default;
Sanador& operator=(const Sanador&) = default;

void informe(const Sanador& rSanador)
{
    std::cout << rSanador.getNombre() << " lanza " << rSanador.hechizo() << '\n';
}
void informe(const Altmer& ganril)
{
    std::cout << ganril.getNombre() << " lanza " << ganril.hechizo() << '\n';
}

void informe(const Argoniano& nerei)
{
    std::cout << nerei.getNombre() << " lanza " << nerei.hechizo() << '\n';
}


void informe(const Sanador& rSanador)
{
    std::cout << rSanador.getNombre() << " lanza " << rSanador.hechizo() << '\n';
}



#include <array>
#include <iostream>

// Altmer y Argoniano del ejemplo de arriba

int main()
{
    const auto& altmers{ std::to_array<Altmer>({{ "Ganril" }, { "Tragril" }, { "Ungantar" }}) };
    const auto& argonianos{ std::to_array<Argoniano>({{ "Nerei" }, { "Ineius" }, { "Milzara" }}) };

    // Antes de C++20
    // const std::array<Altmer, 3> cats{{ { "Ganril" }, { "Tragril }, { "Ungantar" } }};
    // const std::array<Argoniano, 3> dogs{{ { "Nerei" }, { "Ineius" }, { "Milzara" } }};

    for (const auto& altmer : altmers)
    {
        std::cout << altmer.getNombre() << " lanza " << altmer.hechizo() << '\n';
    }

    for (const auto& argoniano : argonianos)
    {
        std::cout << argoniano.getNombre() << " lanza " << argoniano.hechizo() << '\n';
    }

    return 0;
}



#include <array>
#include <iostream>

int main()
{
    const Altmer ganril{ "Ganril" };
    const Altmer tragril{ "Tragril" };
    const Altmer ungantar{ "Ungantar" };

    const Argoniano nerei{ "Nerei" };
    const Argoniano ineius{ "Ineius" };
    const Argoniano milzara{ "Milzara" };

    // Configurar un array de punteros a sanadores, y configurar esos punteros a nuestros objetos Altmer y Argoniano
    // Nota: to_array necesita usar versión C++20 
    const auto sanadores{ std::to_array<const Sanador*>({&ganril, &tragril, &ungantar, &nerei, &ineius, &milzara }) };

    // Antes C++20, debíamos específicamente indicar el tamaño del array
    // const std::array<const Sanador*, 6> sanadores{ &ganril, &tragril, &ungantar, &nerei, &ineius, &milzara };

    for (const auto sanador : sanadores)
    {
        std::cout << sanador->getNombre() << " lanza " << sanador->hechizo() << '\n';
    }

    return 0;
}
#endif




#include <iostream>
#include <string_view>

class Padre
{
public:
    virtual std::string_view getNombre() const { return "Padre"; } // Observa palabra clave virtual
};

class Derivada : public Padre
{
public:
     std::string_view getNombre() const { return "Derivada"; }
};

int main()
{
    Derivada derivada;
    Padre& rPadre{ derivada };
    std::cout << "rPadre es un " << rPadre.getNombre() << '\n';

    return 0;
}






