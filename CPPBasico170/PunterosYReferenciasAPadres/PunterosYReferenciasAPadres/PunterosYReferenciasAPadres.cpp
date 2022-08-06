
#include <string_view> //c++17

class Padre
{
protected:
    int m_valor{};

public:
    Padre(int valor)
        : m_valor{ valor }
    {
    }

    std::string_view getNombre() const { return "Padre"; }
    int getValor() const { return m_valor; }
};

class Derivada : public Padre
{
public:
    Derivada(int valor)
        : Padre{ valor }
    {
    }

    std::string_view getNombre() const { return "Derivada"; }
    int getValorDoblado() const { return m_valor * 2; }
};

#include <iostream>

int main()
{
    Derivada derivada{ 5 };
    Derivada& rDerivada { derivada };
    Derivada* pDerivada{ &derivada };

    // ambas son legales
    Padre& rPadre{ derivada };
    Padre* pPadre{ &derivada };
    
    std::cout << "derivada es un " << derivada.getNombre() << " y tiene un valor de " << derivada.getValor() << '\n';
    std::cout << "rDerivada es un " << rDerivada.getNombre() << " y tiene un valor de " << rDerivada.getValor() << '\n';
    std::cout << "pDerivada es un " << pDerivada->getNombre() << " y tiene un valor de " << pDerivada->getValor() << '\n';
    std::cout << "rPadre es un " << rPadre.getNombre() << " y tiene un valor " << rPadre.getValor() << '\n';
    std::cout << "pPadre es un " << pPadre->getNombre() << " y tiene un valor " << pPadre->getValor() << '\n';
    std::cout << "pPadre es un " << pPadre->getNombre() << " y tiene un valor doblado de " << pPadre->getValorDoblado() << '\n';
    std::cout << "rPadre es un " << rPadre.getNombre() << " y tiene un valor doblado de " << rPadre.getValorDoblado() << '\n';
	

    return 0;
}





#if 0
std::cout << "derivada es un " << derivada.getNombre() << " y tiene un valor de " << derivada.getValor() << '\n';

Derivada& rDerivada{ derivada };
std::cout << "rDerivada es un " << rDerivada.getNombre() << " y tiene un valor de " << rDerivada.getValor() << '\n';

Derivada* pDerivada{ &derivada };
std::cout << "pDerivada es un " << pDerivada->getNombre() << " y tiene un valor de " << pDerivada->getValor() << '\n';


#endif


#if 0
#include <iostream>

int main()
{
    Derivada derivada{ 5 };

    // ambas son legales
    Padre& rPadre{ derivada };
    Padre* pPadre{ &derivada };

    std::cout << "derivada es un " << derivada.getNombre() << " y tiene un valor de " << derivada.getValor() << '\n';
    std::cout << "rPadre es un " << rPadre.getNombre() << " y tiene un valor " << rPadre.getValor() << '\n';
    std::cout << "pPadre es un " << pPadre->getNombre() << " y tiene un valor " << pPadre->getValor() << '\n';
	std::cout << "pPadre es un " << pPadre->getNombre() << " y tiene un valor doblado de " << pPadre->getValorDoblado() << '\n';
    std::cout << "rPadre es un " << rPadre.getNombre() << " y tiene un valor doblado de " << rPadre.getValorDoblado() << '\n';
	

    return 0;
}




#endif





#include <iostream>
#include <string_view>
class Sanador
{
protected:
    std::string m_nombre;

    // Hacemos este constructor protected porque
    //  no queremos que se puedan crear objetos Sanador públicamente,
    // pero sí que lo puedan hacer las clases derivadas.
    Sanador(std::string_view nombre)
        : m_nombre{ nombre }
    {
    }

    // Para prevenir slicing (aún no cubierto)
    Sanador(const Sanador&) = default;
    Sanador& operator=(const Sanador&) = default;

public:
    std::string_view getNombre() const { return m_nombre; }
    std::string_view hechizo() const { return "???"; }
};

class Altmer : public Sanador
{
public:
    Altmer(std::string_view nombre)
        : Sanador{ nombre }
    {
    }

    std::string_view hechizo() const { return "Lovilian"; }
};

class Argoniano : public Sanador
{
public:
    Argoniano(std::string_view nombre)
        : Sanador{ nombre }
    {
    }

    std::string_view hechizo() const { return "Ajum-Tei"; }
};


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


void informe(const Altmer& ganril)
{
    std::cout << ganril.getNombre() << " lanza " << ganril.hechizo() << '\n';
}

void informe(const Argoniano& nerei)
{
    std::cout << nerei.getNombre() << " lanza " << nerei.hechizo() << '\n';
}
#if 0
#endif