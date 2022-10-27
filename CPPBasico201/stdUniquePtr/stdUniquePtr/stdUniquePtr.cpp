#if 0
#include <iostream>
#include <memory> // para std::unique_ptr

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	// asigna un objeto Recurso y hace que sea propiedad de std::unique_ptr
	std::unique_ptr<Recurso> res{ new Recurso() };

	return 0;
} // res sale de alcance aquí, y el recurso asignado es destruido






#include <iostream>
#include <memory> // para std::unique_ptr
#include <utility> // para std::move

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	std::unique_ptr<Recurso> res1{ new Recurso{} }; // Recurso creado aquí
	std::unique_ptr<Recurso> res2{}; // comienza como nullptr

	std::cout << "res1 es " << (res1 ? "no null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "no null\n" : "null\n");

	// res2 = res1; // no compilará: asignación por copia está deshabilitada
	res2 = std::move(res1); // res2 asume la propiedad, res1 es configurado a null

	std::cout << "Propiedad transferida\n";

	std::cout << "res1 es " << (res1 ? "no null\n" : "null\n");
	std::cout << "res2 es " << (res2 ? "no null\n" : "null\n");

	return 0;
} // Recurso destruido aquí cuando res2 sale de alcance

#endif



#include <iostream>
#include <memory> // para std::unique_ptr

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

int main()
{
	std::unique_ptr<Recurso> res{ new Recurso{} };

	if (res) // usa cast implícito a bool para asegurarse que res contiene un Recurso
		std::cout << *res << '\n'; // imprime el Recurso que posee res

	return 0;
}




#if 0
#endif