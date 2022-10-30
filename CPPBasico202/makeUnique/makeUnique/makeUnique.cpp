
#if 0
#include <memory> // para std::unique_ptr y std::make_unique
#include <iostream>

class Fraccion
{
private:
	int m_numerador{ 0 };
	int m_denominador{ 1 };

public:
	Fraccion(int numerador = 0, int denominador = 1) :
		m_numerador{ numerador }, m_denominador{ denominador }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
	{
		out << f1.m_numerador << '/' << f1.m_denominador;
		return out;
	}
};


int main()
{
	// Crea una Fracción única asignada dinámicamente con numerador 3 y denominador 5
	// Podemos usar la deducción automática de tipo para un mejor efecto
	auto f1{ std::make_unique<Fraccion>(3, 5) };
	std::cout << *f1 << '\n';

	// Crea un array de Fracciones asignado dinámicamente de tamaño 4
	auto f2{ std::make_unique<Fraccion[]>(4) };
	std::cout << f2[1] << '\n';
	

	return 0;
}


#include <iostream>
#include <memory> // para std::unique_ptr

class Recurso
{
private:
	int m_num{ 4 };
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Recurso& res)
	{
		out << "Soy un Recurso";
		return out;
	}
	int getNum()
	{
		std::cout << m_num << '\n';
	}
};

int main()
{
	std::unique_ptr<Recurso> res1{ new Recurso{} };
	

	if (res1) // usa cast implícito a bool para asegurarse que res1 contiene un Recurso
	{
		std::cout << *res1 << '\n'; // imprime el Recurso que posee res1
	}

	

	return 0;
}

#endif

#include <iostream>
#include <iomanip> // para std::quoted
#include <vector>
#include <string>

class Foo
{
	int a;
	double b;
	std::string c;
public:

	

	Foo(int const a = 0, double const b = 0, std::string const& c = "")
		:a(a), b(b), c(c)
	{}

	void print() const
	{
		std::cout << '(' << a << ',' << b << ',' << std::quoted(c) << ')'
			<< std::endl;
	}
};
#if 0
int main()
{
	std::unique_ptr <int> pnull;
	std::unique_ptr <int> pi1(new int(23));
	std::cout << *pi1 << std::endl;
	std::unique_ptr<int[]> pa1(new int[3] { 1, 2, 3 });
	std::cout << pa1[0] << std::endl;
	std::unique_ptr<Foo>pf1(new Foo(93, 93.0, "93"));
	pf1->print();
	std::unique_ptr<int>   pi2 = std::make_unique<int>(42);
	std::cout << *pi2 << std::endl;
	std::unique_ptr<int[]> pa2 = std::make_unique<int[]>(3);
	std::cout << pa2[2] << std::endl;
	std::unique_ptr<Foo>   pf2 = std::make_unique<Foo>(42, 42.0, "42");
	pf2->print();

}
#endif


#if 0

//Devolver por valor std::unique_ptr desde una función
#include <memory> // para std::unique_ptr

std::unique_ptr <Foo> crearRecurso()  //espera como valor de retorno un puntero listo std::unique_ptr
{
	return std::make_unique<Foo>();
}

int main()
{
	auto ptr{ crearRecurso() };

	 ptr->print(); //imprime valores predeterminados de objeto foo administrado por "ptr"
	// hacer algo

	return 0;
}





#include <iostream>
#include <memory> // para std::unique_ptr
#include <utility> // para std::move

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Recurso& res)
	{
		out << "Soy un Recurso";
		return out;
	}
};

void tomarPropiedad(std::unique_ptr<Recurso> res)
{
	if (res)
		std::cout << *res << '\n';
} // El Recurso "res" es destruido aquí

int main()
{
	auto ptr{ std::make_unique<Recurso>() };

	//    tomarPropiedad(ptr); // Esto no funciona, debemos usar semánticas de movimiento
	tomarPropiedad(std::move(ptr)); // correcto: usa semánticas de movimiento

	std::cout << "programa finalizado\n";

	return 0;
}



#include <iostream>
#include <memory> // para std::unique_ptr
#include <utility> // para std::move

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Recurso& res)
	{
		out << "Soy un Recurso";
		return out;
	}
};

void tomarPropiedad(std::unique_ptr<Recurso> res)
{
	if (res)
		std::cout << *res << '\n';
} // El Recurso "res" es destruido aquí

int main()
{
	Recurso* res{ new Recurso() };
	std::unique_ptr<Recurso> res1{ res };
	std::unique_ptr<Recurso> res2{ res };

	Recurso* res{ new Recurso() };
	std::unique_ptr<Recurso> res1{ res };
	delete res;
}









