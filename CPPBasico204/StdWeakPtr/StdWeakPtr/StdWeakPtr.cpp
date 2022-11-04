






#include <iostream>
#include <memory> // para std::shared_ptr
#include <string>

class Persona
{
	std::string m_nombre;
	std::shared_ptr<Persona> m_socio; // inicialmente creado vacío

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
	auto laura{ std::make_shared<Persona>("Laura") }; // crea una Persona llamada "Laura"
	auto ricardo{ std::make_shared<Persona>("Ricardo") }; // crea una Persona llamada "Ricardo"

	socioUp(laura, ricardo); // Hacer a "Laura" apuntar a "Ricardo" y viceversa

	return 0;
}





#if 0

#include <iostream>
#include <memory> // para std::shared_ptr
#include <string>

class Persona
{
	std::string m_nombre;
	std::shared_ptr<Persona> m_socio; // inicialmente creado vacío

public:

	Persona(const std::string& nombre) : m_nombre(nombre)
	{
		std::cout << m_nombre << " creado\n";
	}
	~Persona()
	{
		std::cout << m_nombre << " destruido\n";
	}

	friend bool socioUp(std::shared_ptr<Persona>& p1, std::shared_ptr<Persona>& p2);
	
	
};

 bool socioUp(std::shared_ptr<Persona>& p1, std::shared_ptr<Persona>& p2)
{
	if (!p1 || !p2)
		return false;

	p1->m_socio = p2;
	p2->m_socio = p1;

	std::cout << p1->m_nombre << " es ahora socio de " << p2->m_nombre << '\n';

	return true;
}

int main()
{
	auto laura{ std::make_shared<Persona>("Laura") }; // crea una Persona llamada "Laura"
	auto ricardo{ std::make_shared<Persona>("Ricardo") }; // crea una Persona llamada "Ricardo"

	socioUp(laura, ricardo); // Hacer a "Laura" apuntar a "Ricardo" y viceversa

	return 0;
}
#endif









