#if 0
#include <iostream>
#include <string_view>

class Padre
{
public:
	// Esta versión de getThis() devuelve un puntero a una clase Padre
	virtual Padre* getThis() { std::cout << "llamado Padre::getThis()\n"; return this; }
	void  imprimirTipo() { std::cout << "devuelve un Padre\n"; }
};

class Derivada : public Padre
{
public:
	// Normalmente las funciones override deben devolver objetos del mismo tipo que la función padre
	// Pero, como Derivada deriva de Padre, es correcto devolver Derivada* en lugar de Padre*
	Derivada* getThis() override { std::cout << "llamada Derivada::getThis()\n";  return this; }
	void imprimirTipo()  { std::cout << "devuelve una Derivada\n"; }
};

int main()
{
	Derivada derivada{};
	Derivada* ptrDerivada{&derivada};	
	Padre* ptrPadre{ &derivada };	
	derivada.getThis()->imprimirTipo(); // llama a Derivada::getThis(), devuelve un puntero a Derivada*, llama a Derivada::imprimirTipo
	ptrDerivada->getThis()->imprimirTipo();
	ptrPadre->getThis()->imprimirTipo(); // llama a Derivada::getThis(), devuelve un puntero a Padre*, llama a Padre::imprimirTipo

	return 0;
}



#include <iostream>
class Padre
{
public:
    virtual ~Padre() 
    {
        std::cout << "Llamando a ~Padre()\n";
    }
	
    virtual ~Padre() = default; // genera un destructor virtual default
};

class Derivada : public Padre
{
private:
    int* m_array;

public:
    Derivada(int tamanho)
        : m_array  { new int[tamanho] }
    {
    }

    ~Derivada() // ahora se considera override
    {
        std::cout << "Llamando ~Derivada()\n";
        delete[] m_array;
    }
};

int main()
{
    Derivada* derivada{ new Derivada(5) };
    Padre* padre{ derivada };

    delete padre;

    return 0;
}
#endif


class Padre
{
public:
    virtual ~Padre() = default;
    virtual const char* getNombre() const { return "Padre"; }
};

class Derivada : public Padre
{
public:
    virtual const char* getNombre() const { return "Derivada"; }
};

#include <iostream>
int main()
{
    Derivada derivada;
    const Padre& padre{ derivada };
    // Llama a Padre::getNombre() en lugar de la virtualización Derivada::getNombre()
    std::cout << padre.Padre::getNombre() << '\n';

    return 0;
}
