
#if 0
class Padre
{
public:
    const char* diHola() const { return "Hola"; } // una función no virtual normal

    virtual const char* getNombre() const { return "Padre"; } // una función virtual normal

    virtual int getValor() const = 0; // una función virtual pura

    int hazAlgo() = 0; // error Compilación: no se pueden configurar funciones no-virtuales a 0
};

int main()
{
    Padre padre; // no se puede instanciar una clase base abstracta, pero para ver el ejemeplo, lo hacemos
    padre.getValor(); // ¿Qué haría esto?

    return 0;
}




class Padre
{
public:   

    virtual int getValor() const = 0; // una función virtual pura    
};

int main()
{
    Padre padre; 
    padre.getValor(); // ¿Qué haría esto?

    return 0;
}



#include <string>
#include <iostream>

class Personaje
{
    
protected:
    std::string m_nombre{};
    

    Personaje(const std::string& nombre)
        : m_nombre{ nombre }
    {
    }

    
public:
    const std::string& getNombre() const { return m_nombre; }
    virtual const char* hablar() const { return "???"; }    
    virtual ~Personaje() = default;
};

class Altmer : public Personaje
{
    Altmer(const std::string& nombre)
        : Personaje{ nombre }
    {
    }

    const char* hablar() const override { return "Habla Altmer"; }
};


class Redguard : public Personaje
{
    Redguard(const std::string& nombre)
        : Personaje{ nombre }
    {
    }

    const char* hablar() const override { return "Habla Redguard"; }
};




class Bosmer : public Personaje
{
public:
    Bosmer(const std::string& nombre)
        : Personaje{ nombre }
    {
    }

    // Olvidamos redefinir hablar
};

int main()
{
    Bosmer corim{ "Corim" };
    std::cout << corim.getNombre() << " dice " << corim.hablar() << '\n';
    Personaje* ptrCorim{ &corim };
    std::cout << ptrCorim->getNombre() << " dice " <<ptrCorim->hablar() << '\n';

    return 0;
}
#endif

#if 0
#include <string>
#include <iostream>

class Personaje
{
   
protected:
    std::string m_nombre{};

    Personaje(const std::string& nombre)
        : m_nombre{ nombre }
    {
    }


public:
    const std::string& getNombre() const { return m_nombre; }
    //virtual const char* hablar() const { return "???"; }
    virtual const char* hablar() const = 0;
    virtual ~Personaje() = default;
};

class Altmer : public Personaje
{
    Altmer(const std::string& nombre)
        : Personaje{ nombre }
    {
    }

    const char* hablar() const override { return "Habla Altmer"; }
};


class Redguard : public Personaje
{
    Redguard(const std::string& nombre)
        : Personaje{ nombre }
    {
    }

    const char* hablar() const override { return "Habla Redguard"; }
};


#include <iostream>
#include <string>

class Bosmer : public Personaje
{
public:
    Bosmer(const std::string& nombre)
        : Personaje{ nombre }
    {
    }

    const char* hablar() const override { return "Habla Bosmer"; }
};

int main()
{    
    Bosmer corim{ "Corim" };
    Personaje& rCorim{ corim };
    std::cout << rCorim.hablar(); //resuelve a Bosmer::hablar( )

    return 0;
}







#include <string>
#include <iostream>

class Personaje // Personaje es una clase Padre abstracta
{
protected:
    std::string m_nombre;

public:
    Personaje(const std::string& nombre)
        : m_nombre{ nombre }
    {
    }

    std::string getNombre() { return m_nombre; }
    virtual const char* hablar() const = 0; // El = 0 significa que esta función es virtual pura

    virtual ~Personaje() = default;
};

const char* Personaje::hablar() const  // aunque tenga un cuerpo
{
    return "general";
}

class Bosmer : public Personaje
{
public:
    Bosmer(const std::string& nombre)
        : Personaje{ nombre }
    {
    }

    const char* hablar() const override //implemente función hablar( )
    { 
        return Personaje::hablar();  //Pero llama a la Personaje
    }
};

int main()
{
    Bosmer corim{ "Corim" };
    std::cout << corim.getNombre() << " dice " << corim.hablar() << '\n'; //Personaje::hablar();

    return 0;
}



