
#if 0
#include <iostream>
#include <string_view>

class Padre
{
public:
    std::string_view getNombre() const { return "Padre"; }
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





#include <iostream>
#include <string_view>

class Primera
{
public:
    virtual std::string_view getNombre() const { return "Primera"; }
};

class Segunda : public Primera
{
public:
    virtual std::string_view getNombre() const { return "Segunda"; }
};

class Tercera : public Segunda
{
public:
    virtual std::string_view getNombre() const { return "Tercera"; }
};

class Cuarta : public Tercera
{
public:
    virtual std::string_view getNombre() const { return "Cuarta"; }
};

int main()
{
    Tercera tercera;
    Primera& rPadre{ tercera };
    std::cout << "rPadre es una " << rPadre.getNombre() << '\n';

    return 0;
}



#include <iostream>
#include <string>
#include <string_view>

class Sanador
{
protected:
    std::string m_nombre;

    
    Sanador(const std::string& nombre)
        : m_nombre{ nombre }
    {
    }

public:
    const std::string& getNombre() const { return m_nombre; }
    std::string_view hechizo() const { return "???"; }
};

class Altmer : public Sanador
{
public:
    Altmer(const std::string& nombre)
        : Sanador{ nombre }
    {
    }

    std::string_view hechizo() const { return "Lovilian"; }
};

class Argoniano : public Sanador
{
public:
    Argoniano(const std::string& nombre)
        : Sanador{ nombre }
    {
    }

    std::string_view hechizo() const { return "Ajum-Tei"; }
};

void informe(const Sanador& sanador)
{
    std::cout << sanador.getNombre() << " lanza " << sanador.hechizo() << '\n';
}

int main()
{
    Altmer ganril{ "Ganril" };
    Argoniano nerei{ "Nerei" };

    informe(ganril);
    informe(nerei);

    return 0;
}





#include <iostream>
#include <string>
#include <string_view>

class Sanador
{
protected:
    std::string m_nombre;


    Sanador(const std::string& nombre)
        : m_nombre{ nombre }
    {
    }

public:
    const std::string& getNombre() const { return m_nombre; }
    virtual std::string_view hechizo() const { return "???"; }
};

class Altmer : public Sanador
{
public:
    Altmer(const std::string& nombre)
        : Sanador{ nombre }
    {
    }

    virtual std::string_view hechizo() const { return "Lovilian"; }
};

class Argoniano : public Sanador
{
public:
    Argoniano(const std::string& nombre)
        : Sanador{ nombre }
    {
    }

    virtual std::string_view hechizo() const { return "Ajum-Tei"; }
};

void informe(const Sanador& sanador)
{
    std::cout << sanador.getNombre() << " lanza " << sanador.hechizo() << '\n';
}

int main()
{
    Altmer ganril{ "Ganril" };
    Argoniano nerei{ "Nerei" };

    informe(ganril);
    informe(nerei);

    return 0;
}
#endif




#include <iostream>
#include <string>
#include <string_view>

class Sanador
{
protected:
    std::string m_nombre;


    Sanador(const std::string& nombre)
        : m_nombre{ nombre }
    {
    }

public:
    const std::string& getNombre() const { return m_nombre; }
    virtual std::string_view hechizo() const { return "???"; }
};

class Altmer : public Sanador
{
public:
    Altmer(const std::string& nombre)
        : Sanador{ nombre }
    {
    }

    virtual std::string_view hechizo() const { return "Lovilian"; }
};

class Argoniano : public Sanador
{
public:
    Argoniano(const std::string& nombre)
        : Sanador{ nombre }
    {
    }

    virtual std::string_view hechizo() const { return "Ajum-Tei"; }
};

void informe(const Sanador& sanador)
{
    std::cout << sanador.getNombre() << " lanza " << sanador.hechizo() << '\n';
}

int main()
{
    Altmer ganril{ "Ganril" };
    Altmer tragril{ "Tragril" };
    Altmer ungantar{ "Ungantar" };

    Argoniano nerei{ "Nerei" };
    Argoniano ineius{ "Ineius" };
    Argoniano milzara{ "Milzara" };

    // Configuramos un array de punteros a sanadores, 
    //y configuramos esos punteros a nuestros objetos  Altmer y Argoniano
    Sanador* sanadores[]{ &ganril, &tragril, &ungantar, &nerei, &ineius, &milzara };

    for (const auto* sanador : sanadores)
        std::cout << sanador->getNombre() << " lanza " << sanador->hechizo() << '\n';

    return 0;
}


class Padre
{
public:
    virtual int getValor() const { return 5; }
};

class Derived : public Padre
{
public:
    virtual double getValor() const { return 6.78; }
};


#if 0
#endif
