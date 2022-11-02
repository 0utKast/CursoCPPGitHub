
#include <iostream>
#include <memory> // para std::shared_ptr

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	// asigna un objeto Recurso y hacemos que sea propiedad de std::shared_ptr
	Recurso* res{ new Recurso };
	std::shared_ptr<Recurso> ptr1{ res };
	{
		std::shared_ptr<Recurso> ptr2{ ptr1 }; // hace otro std::shared_ptr apuntando al mismo Recurso

		std::cout << "Eliminando uno de los punteros shared\n";
	} // ptr2 sale de alcance aquí, pero no pasa nada con el Recurso

	std::cout << "Eliminando otro de los punteros shared\n";

	return 0;
} // ptr1 sale de alcance aquí, y el Recurso asignado es destruido


#if 0

#include <iostream>
#include <memory> // para std::shared_ptr

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	Recurso* res{ new Recurso };
	std::shared_ptr<Recurso> ptr1{ res };
	{
		std::shared_ptr<Recurso> ptr2{ res }; // crea ptr2 directamente desde res (en lugar de desde ptr1)

		std::cout << "Eliminando un puntero shared\n";
	} // ptr2 sale de alcande aquí, y el Recurso asignado es destruido

	std::cout << "Eliminando otro puntero shared\n";

	return 0;
} // ptr1 sale de alcance aquí, y el Recurso asignado es destruido aquí



#endif





#if 0

#endif




#include <iostream>
#include <memory> // para std::shared_ptr

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	// asignar un objeto Recurso y hacerlo propiedad de std::shared_ptr
	auto ptr1{ std::make_shared<Recurso>() };
	{
		auto ptr2{ ptr1 }; // creamos ptr2 usando copia de ptr1

		std::cout << "Eliminando un puntero compartido\n";
	} // ptr2 sale de alcance aquí, pero el recurso sigue existinedo

	std::cout << "Eliminando el otro puntero compartido\n";


	

	return 0;
} // ptr1 sale de alcance aquí, y el Recurso asignado es destruido


std::unique_ptr<std::string> unique = std::make_unique<std::string>("test");
std::shared_ptr<std::string> shared = std::move(unique);
std::shared_ptr<std::string> shared = std::make_unique<std::string>("test");
std::unique_ptr<int> up_ = std::make_unique<int>();
std::shared_ptr<int> sp_ = std::move(up_);