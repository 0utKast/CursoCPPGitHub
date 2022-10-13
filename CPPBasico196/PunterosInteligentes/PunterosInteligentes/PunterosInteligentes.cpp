#if 0

#include <iostream>

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
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	Auto_ptr1<Recurso> res(new Recurso());
	Auto_ptr1<Recurso> otro(res); // Alternativamente, no inicializar otro y luego asignar otro = res;

	return 0;
}




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
	Auto_ptr1<Recurso> res(new Recurso());
	pasarPorValor(res);

	return 0;
}

void pasarPorValor(Auto_ptr1<Recurso> res)
{
}

? ? ? recursoGenerado()
{
	Recurso* r{ new Recurso() };
	return Auto_ptr1(r);
}



int main()
{
	Auto_ptr1<Recurso> res(new Recurso());
	Auto_ptr1<Recurso> otro(res); // Tampoco inicializar otro y luego asignar otro = res;

	return 0;
}
#endif


#include <iostream>

template <typename T>
class Auto_ptr2
{
	T* m_ptr;
public:
	Auto_ptr2(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// Un constructor por copia que implementa la semántica de movimiento
	Auto_ptr2(Auto_ptr2& a) // Observa: no const
	{
		m_ptr = a.m_ptr; // transferimos nuestro puntero tonto desde la fuente a nuestro objeto local
		a.m_ptr = nullptr; // nos aseguramos que la fuente ya no posea el puntero
	}

	// Un operador de asignación que implementa la semántica de movimiento
	Auto_ptr2& operator=(Auto_ptr2& a) // Observa: no const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // nos aseguramos que desasignamos cualquier puntero que el destino ya tenga antes
		m_ptr = a.m_ptr; // luego transferimos nuestro puntero tonto de la fuente al objeto local
		a.m_ptr = nullptr; // nos aseguramos que la fuente ya no poseea el puntero
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Recurso
{
public:
	Recurso() { std::cout << "Recurso adquirido\n"; }
	~Recurso() { std::cout << "Recurso destruido\n"; }
};

int main()
{
	Auto_ptr2<Recurso> res(new Recurso());
	Auto_ptr2<Recurso> otro; // Empieza como nullptr

	std::cout << "res es " << (res.isNull() ? "null\n" : "no null\n");
	std::cout << "otro es " << (otro.isNull() ? "null\n" : "no null\n");

	otro = res; // otro asume la propiedad, res es configurado como nulo

	std::cout << "Propiedad transferida\n";

	std::cout << "res es " << (res.isNull() ? "null\n" : "no null\n");
	std::cout << "otro es " << (otro.isNull() ? "null\n" : "no null\n");

	return 0;
}











