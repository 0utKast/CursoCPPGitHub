#if 0
// INICIO VT 182 COD. 001
#include <iostream>
#include <string>

// Identificador de la clase
enum class ClassID
{
	padre,
	derivada
	// Podemos seguir a�adiendo aqu� otros
};

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}

	virtual ~Padre() = default;

	virtual  ClassID getClassID() const 
	{ 
		return ClassID::padre; 
	}
};

class Derivada : public Padre
{
protected:
	std::string m_nombre{};

public:
	Derivada(int valor, const std::string& nombre)
		: Padre{ valor }, m_nombre{ nombre }
	{
	}

	const std::string& getNombre() const { return m_nombre; }
	
	ClassID getClassID() const override   
	{ 
		return ClassID::derivada; 
	}

};

Padre* getObjeto(bool bReturnDerivada)
{
	if (bReturnDerivada)
		return new Derivada{ 1, "Maspalomas" };
	else
		return new Padre{ 2 };
}

int main()
{
	Padre* p{ getObjeto(false) };

	if (p->getClassID() == ClassID::derivada)
	{
		// Ya hemos comprobado que b est� apuntando a un objeto Derivada, as� que siempre ser� correcto
		Derivada* d{ static_cast<Derivada*>(p) };
		std::cout << "El nombre de la Derivada es: " << d->getNombre() << '\n';
	}
	else
		std::cout << "No es derivada";

	delete p;

	return 0;
}
// FINAL VT 182 COD. 001
#endif




// INICIO VT 182 COD. 002

#include <iostream>
#include <string>

class Padre
{
protected:
	int m_valor;

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}

	virtual ~Padre() = default;
};

class Derivada : public Padre
{
protected:
	std::string m_nombre;

public:
	Derivada(int valor, const std::string& nombre)
		: Padre{ valor }, m_nombre{ nombre }
	{
	}

	const std::string& getNombre() const { return m_nombre; }
};

int main()
{
	Derivada maspalomas{ 1, "Maspalomas" }; // crea un maspalomas
	Padre& p{ maspalomas }; // configura referencia padre a objeto
	Derivada& d{ dynamic_cast<Derivada&>(p) }; // dynamic cast usa una referencia en lugar de un puntero

	std::cout << "El nombre de Derivada es: " << d.getNombre() << '\n'; // Podemos acceder a Derivada::getNombre a trav�s de d

	return 0;
}

// FINAL VT 182 COD. 002


#if 0

// INICIO VT 182 COD. 003

#include <iostream>
#include <string>

class Padre
{
protected:
	int m_valor;

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}

	virtual ~Padre() = default;
};

class Derivada : public Padre
{
protected:
	std::string m_nombre;

public:
	Derivada(int valor, const std::string& nombre)
		: Padre{ valor }, m_nombre{ nombre }
	{
	}

	const std::string& getNombre() const { return m_nombre; }
};

int main()
{
	Padre otro{ 1 }; // crea un objeto Padre
	Padre& p{ otro }; // configura referencia padre a objeto
	Derivada& d{ dynamic_cast<Derivada&>(p) }; // dynamic cast usa una referencia en lugar de un puntero

	std::cout << "El nombre de Derivada es: " << d.getNombre() << '\n'; // Ojo. Lanza excepci�n.

	return 0;
}
// FINAL VT 182 COD. 003

#endif

