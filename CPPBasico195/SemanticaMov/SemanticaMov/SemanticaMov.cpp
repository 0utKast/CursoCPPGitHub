
#if 0
void algunaFuncion()
{
    Recurso* ptr = new Recurso(); // Recurso es una struct o clase

    // hacer algo con ptr aquí

    delete ptr;
}


#include <iostream>

void algunaFuncion()
{
    Recurso* ptr = new Recurso();

    int x;
    std::cout << "Escribe un integer: ";
    std::cin >> x;

    if (x == 0)
        return; // La función se devuelve anticipadamente, y ptr no será deleted

    // hacer algo con ptr aquí

    delete ptr;
}


#include <iostream>

void algunaFuncion()
{
	Recurso* ptr = new Recurso();

	int x;
	std::cout << "Escribir un integer: ";
	std::cin >> x;

	if (x == 0)
		throw 0; // La función se devuelve anticipadamente, y ptr no será deleted

	// hacer algo con ptr aquí

	delete ptr;
}
#endif

#include <iostream>

template <typename T>
class Auto_ptr1
{
	T* m_ptr;
public:
	// Le pasamo un puntero que le "pertenezca" a través del constructor
	Auto_ptr1(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	// El destructor se asegurará que el puntero sea desasignado
	~Auto_ptr1()
	{
		delete m_ptr;
	}

	// Sobrecargamos los operadores de indirección (*) y flecha ( -> ) para poder usar Auto_ptr1 como m_ptr.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

// Una clase de ejemplo para ver que lo anterior funciona
class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	Auto_ptr1<Recurso> res(new Recurso()); // Observa la asignación de memoria aquí
	Auto_ptr1<Recurso> otro(res);


	// ... Pero no necesitamos usar delete explícitamente

// Observa también que el Recurso entre paréntesis angulares no necesita el símbolo *, porque se lo provee la plantilla

	return 0;
} // res sale de alcance aquí, y destruye el Recurso asignado por nosotros





#if 0

#include <iostream>

template <typename T>
class Auto_ptr1
{
	T* m_ptr;
public:
	// Le pasamo un puntero que le "pertenezca" a través del constructor
	Auto_ptr1(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	// El destructor se asegurará que el puntero sea desasignado
	~Auto_ptr1()
	{
		delete m_ptr;
	}

	// Sobrecargamos los operadores de indirección (*) y flecha ( -> ) para poder usar Auto_ptr1 como m_ptr.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

// Una clase de ejemplo para ver que lo anterior funciona
class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
	void diHola() { std::cout << "Hola\n"; }
};

void algunaFuncion()
{
	Auto_ptr1<Recurso> ptr(new Recurso()); // ptr ahora posee a Recurso

	int x;
	std::cout << "Escribe un integer: ";
	std::cin >> x;

	if (x == 0)
		return; // retorno anticipado de la función

	// Hacer algo con ptr aquí
	ptr->diHola();
}

int main()
{
	algunaFuncion();

	return 0;
}




#include <iostream>

// Same as above
template <typename T>
class Auto_ptr1
{
	T* m_ptr;
public:
	Auto_ptr1(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr1()
	{
		delete m_ptr;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

class Recurso
{
public:
	Recurso() { std::cout << "Recurso acquired\n"; }
	~Recurso() { std::cout << "Recurso destroyed\n"; }
};

int main()
{
	Auto_ptr1<Recurso> res1(new Recurso());
	Auto_ptr1<Recurso> res2(res1); // Alternatively, don't initialize res2 and then assign res2 = res1;

	return 0;
}

#endif