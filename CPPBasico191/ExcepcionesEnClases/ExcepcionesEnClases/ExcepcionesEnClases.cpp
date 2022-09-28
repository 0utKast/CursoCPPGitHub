#include <iostream>

class Miembro
{
public:
	Miembro()
	{
		std::cerr << "Miembro se le asignan algunos recursos\n";
	}

	~Miembro()
	{
		std::cerr << "Miembro limpiado\n";
	}
};

class A
{
private:
	int m_x{};
	Miembro m_miembro;

public:
	A(int x) : m_x{ x }
	{
		if (x <= 0)
			throw 1;
	}

	~A()
	{
		std::cerr << "~A\n"; // no debe ser llamado
	}
};


int main()
{
	setlocale(LC_ALL, "es_ES");
	try
	{
		A a{ 0 };
	}
	catch (int)
	{
		std::cerr << "Excepción capturada y finalizada\n";
	}

	return 0;
}



class Foo {
private:
	int* ptr; // "Foo" responsable de asignar y desasignar "ptr"

};

class Foo {
private:
	std::unique_ptr<int> ptr; // "std::unique_ptr" manejará asignación/desasignación de "ptr"
};





