
#if 0
#include <functional> // std::reference_wrapper
#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string noelia{ "Noelia" };
	std::string alberto{ "Alberto" };
	// estos strings son almacenados por referencia, no por valor
	std::vector<std::reference_wrapper<std::string>> nombres{ noelia, alberto }; 

	std::string juan{ "Juan" };

	nombres.push_back(juan);

	for (auto nombre : nombres)
	{
		// Usa la función miembro get() para obtener el string referenciado.
		std::cout << nombre.get() << " Heroe \n";
	}	

	return 0;
}





//Para crear un vector de referencias constantes, tendríamos que agregar const antes de std::string 

// Vector of const references to std::string
//std::vector<std::reference_wrapper<const std::string>> nombres{ tom, berta };

#endif










#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>

// Como Abogado y Cliente tienen una dependencia circular, vamos a declaras primero Cliente
class Cliente;

class Abogado
{
private:
	std::string m_nombre{};
	std::vector<std::reference_wrapper<const Cliente>> m_cliente{};

public:
	Abogado(const std::string& nombre) :
		m_nombre{ nombre }
	{
	}

	void addCliente(Cliente& cliente);

	// Implementaremos esta función debajo de Cliente ya que necesitamos que Cliente esté definido en ese punto
	friend std::ostream& operator<<(std::ostream& out, const Abogado& abogado);

	const std::string& getNombre() const { return m_nombre; }
};

class Cliente
{
private:
	std::string m_nombre{};
	std::vector<std::reference_wrapper<const Abogado>> m_abogado{}; // así que podemos usarlo aquí

	// Vamos a hacer que addAbogado sea privado porque no queremos que el público lo use.
	// Deberán usar Abogado::addCliente() en su lugar, que está expuesto públicamente
	void addAbogado(const Abogado& abogado)
	{
		m_abogado.push_back(abogado);
	}

public:
	Cliente(const std::string& nombre)
		: m_nombre{ nombre }
	{
	}

	// Implementaremos esta función a continuación en paralelo  a operator<<(std::ostream&, const Abogado&)
	friend std::ostream& operator<<(std::ostream& out, const Cliente& cliente);

	const std::string& getNombre() const { return m_nombre; }

	// Haremos amiga a Abogado::addCliente() para que acceda a la función privada Cliente::addAbogado()
	friend void Abogado::addCliente(Cliente& cliente);
};

void Abogado::addCliente(Cliente& cliente)
{
	// Nuestro abogado añadirá este cliente
	m_cliente.push_back(cliente);

	// y el cliente añadirá también este abogado
	cliente.addAbogado(*this);
}

std::ostream& operator<<(std::ostream& out, const Abogado& abogado)
{
	if (abogado.m_cliente.empty())
	{
		out << abogado.m_nombre << " no tiene clientes de momento";
		return out;
	}

	out << abogado.m_nombre << " está viendo clientes: ";
	for (const auto& cliente : abogado.m_cliente)
		out << cliente.get().getNombre() << ". ";

	return out;
}

std::ostream& operator<<(std::ostream& out, const Cliente& cliente)
{
	if (cliente.m_abogado.empty())
	{
		out << cliente.getNombre() << " no tiene abogados de momento";
		return out;
	}

	out << cliente.m_nombre << " está viendo abogados: ";
	for (const auto& abogado : cliente.m_abogado)
		out << abogado.get().getNombre() << ". ";

	return out;
}

int main()
{
	setlocale(LC_ALL, "es_ES.UTF-8");
	// Crear un Cliente fuera del alcance de Abogado
	Cliente ana{ "Ana" };
	Cliente francisco{ "Francisco" };
	Cliente benigna{ "Benigna" };

	Abogado juan{ "Juan" };
	Abogado ernesto{ "Ernesto" };

	juan.addCliente(ana);

	ernesto.addCliente(benigna);
	ernesto.addCliente(ana);

	std::cout << juan << '\n';
	std::cout << ernesto << '\n';
	std::cout << ana << '\n';
	std::cout << francisco << '\n';
	std::cout << benigna << '\n';

	return 0;
}
#if 0
#endif