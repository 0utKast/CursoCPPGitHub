#if 0
#include <iostream>
#include <memory> // para std::shared_ptr

class Recurso
{
public:
	std::shared_ptr<Recurso> m_ptr{}; // inicialmente creado vacío

	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	auto ptr1{ std::make_shared<Recurso>() };

	ptr1->m_ptr = ptr1; // m_ptr está ahora compartiendo el Recurso que lo contiene

	return 0;
}




#include <iostream>
#include <memory> // para std::shared_ptr y std::weak_ptr
#include <string>

class Persona
{
	std::string m_nombre;
	std::weak_ptr<Persona> m_socio; // observa: Esto es ahora un std::weak_ptr

public:

	Persona(const std::string& nombre) : m_nombre(nombre)
	{
		std::cout << m_nombre << " creado\n";
	}
	~Persona()
	{
		std::cout << m_nombre << " destruido\n";
	}

	friend bool socioUp(std::shared_ptr<Persona>& p1, std::shared_ptr<Persona>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_socio = p2;
		p2->m_socio = p1;

		std::cout << p1->m_nombre << " es ahora socio de " << p2->m_nombre << '\n';

		return true;
	}
};

int main()
{
	auto laura{ std::make_shared<Persona>("Laura") };
	auto ricardo{ std::make_shared<Persona>("Ricardo") };

	socioUp(laura, ricardo);

	return 0;
}

#endif


#if 0

#include <iostream>
#include <memory> // para std::shared_ptr y std::weak_ptr
#include <string>

class Persona
{
	std::string m_nombre;
	std::weak_ptr<Persona> m_socio; // observa: Esto es ahora un std::weak_ptr

public:

	Persona(const std::string& nombre) : m_nombre(nombre)
	{
		std::cout << m_nombre << " creado\n";
	}
	~Persona()
	{
		std::cout << m_nombre << " destruido\n";
	}

	friend bool socioUp(std::shared_ptr<Persona>& p1, std::shared_ptr<Persona>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_socio = p2;
		p2->m_socio = p1;

		std::cout << p1->m_nombre << " es ahora socio de " << p2->m_nombre << '\n';

			return true;
	}

	const std::shared_ptr<Persona> getSocio() const { return m_socio.lock(); } // usamos lock() para convertir weak_ptr a shared_ptr
	const std::string& getNombre() const { return m_nombre; }
};

int main()
{
	auto laura{ std::make_shared<Persona>("Laura") };
	auto ricardo{ std::make_shared<Persona>("Ricardo") };

	socioUp(laura, ricardo);

	auto socio = ricardo->getSocio(); // get shared_ptr a socio de Ricardo
	std::cout << "El socio de " << ricardo->getNombre() << " es: " << socio->getNombre() << '\n';
	

	return 0;
}


#endif



#include <iostream>
#include <memory> // para std::shared_ptr y std::weak_ptr

class Recurso
{
public:
	std::weak_ptr<Recurso> m_ptr{}; // inicialmente creado vacío

	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	auto ptr1{ std::make_shared<Recurso>() };

	ptr1->m_ptr = ptr1; // m_ptr está ahora compartiendo el Recurso que contiene

	return 0;
}


#if 0
#endif 