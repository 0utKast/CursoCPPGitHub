#if 0
// INICIO CODIGO 181-001

#include <iostream>
#include <string>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{}

	virtual ~Padre() = default;
};

class Derivada : public Padre
{
protected:
	std::string m_nombre{};

public:
	Derivada(int valor, const std::string& nombre)
		: Padre{ valor }, m_nombre{ nombre }
	{}

	const std::string& getNombre() const { return m_nombre; }
};

Padre* getObjeto(bool returnDerivada)
{
	if (returnDerivada)
		return new Derivada{ 1, "Maspalomas" };
	else
		return new Padre{ 2 };
}

int main()
{
	Padre* p{ getObjeto(true) };

	// ¿Cómo imprimimos el nombre del objeto Derivada aquí, si tenemos solo un puntero Padre?

	delete p;

	return 0;
}



// FINAL CODIGO 181-001
#endif


#if 0

// INICIO CODIGO 181-002

#include <iostream>
#include <string>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{}

	virtual ~Padre() = default;
};

class Derivada : public Padre
{
protected:
	std::string m_nombre{};

public:
	Derivada(int valor, const std::string& nombre)
		: Padre{ valor }, m_nombre{ nombre }
	{}

	const std::string& getNombre() const { return m_nombre; }
};

Padre* getObjeto(bool returnDerivada)
{
	if (returnDerivada)
		return new Derivada{ 1, "Maspalomas" };
	else
		return new Padre{ 2 };
}

int main()
{
	Padre* p{ getObjeto(true) };
	Derivada* d{ dynamic_cast<Derivada*>(p) }; // usamos dinamic cast para convertir un puntero Padre en un puntero Derivada	
	std::cout << "El nombre de la Derivada es: " << d->getNombre() << '\n';
	delete p;

	return 0;
}

// FINAL CODIGO 181-002

#endif

#if 0

// INICIO CODIGO 181-003

#include <iostream>
#include <string>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{}

	virtual ~Padre() = default;
};

class Derivada : public Padre
{
protected:
	std::string m_nombre{};

public:
	Derivada(int valor, const std::string& nombre)
		: Padre{ valor }, m_nombre{ nombre }
	{}

	const std::string& getNombre() const { return m_nombre; }
};

Padre* getObjeto(bool returnDerivada)
{
	if (returnDerivada)
		return new Derivada{ 1, "Maspalomas" };
	else
		return new Padre{ 2 };
}

int main()
{
	Padre* p{ getObjeto(false) };
	Derivada* d{ dynamic_cast<Derivada*>(p) }; // usamos dinamic cast para convertir un puntero Padre en un puntero Derivada	
	std::cout << "El nombre de la Derivada es: " << d->getNombre() << '\n';
	delete p;

	return 0;
}

// FINAL CODIGO 181-003

#endif



// INICIO CODIGO 181-004

#include <iostream>
#include <string>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{}

	virtual ~Padre() = default;
};

class Derivada : public Padre
{
protected:
	std::string m_nombre{};

public:
	Derivada(int valor, const std::string& nombre)
		: Padre{ valor }, m_nombre{ nombre }
	{}

	const std::string& getNombre() const { return m_nombre; }
};

Padre* getObjeto(bool returnDerivada)
{
	if (returnDerivada)
		return new Derivada{ 1, "Maspalomas" };
	else
		return new Padre{ 2 };
}

int main()
{
	Padre* p{ getObjeto(false) };

	Derivada* d{ dynamic_cast<Derivada*>(p) }; //Usa dynamic_cast para convertir de padre a derivada

	if (d) // nos aseguramos que d es no-null
		std::cout << "El nombre de la Derivada es: " << d->getNombre() << '\n';
	else
		std::cout << "Puntero Nulo";
	delete p;

	return 0;
}


// FINAL CODIGO 181-004

#if 0
#endif

































#if 0
Derivada* d{ p };
#endif





















#if 0


int main()
{
	Padre* p{ getObjeto(true) };

	Derivada* d{ dynamic_cast<Derivada*>(p) }; // usamos dinamyc cast para convertir puntero Padre en puntero Derivada

	if (d) // nos aseguramos que d no es nulo
		std::cout << "El nombre de la Derivada es: " << d->getNombre() << '\n';

	delete p;

	return 0;
}

#endif




