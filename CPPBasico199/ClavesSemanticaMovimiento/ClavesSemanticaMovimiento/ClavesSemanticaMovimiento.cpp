#if 0
#include <iostream>

template<typename T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Constructor por copia
	// Hace una copia profunda de a.m_ptr a m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Constructor por movimiento
	// Transfiere propiedad de a.m_ptr a m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // Desasignar a.m_ptr
	}

	// asignación por Copia
	// Hace copia profunda de a.m_ptr a m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Detección auto-asignación
		if (&a == this)
			return *this;

		// Libera cualquier recurso almacenado aquí
		delete m_ptr;

		// Copia el recurso
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Asignación por Movimiento
	// Transferir propiedad de a.m_ptr a m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
		// Detección de auto-asignación
		if (&a == this)
			return *this;

		// Libera cualquier recurso almacenado aquí
		delete m_ptr;

		// Transfeerr propiedad de a.m_ptr a m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // desasignar a.m_ptr

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

Auto_ptr4<Recurso> generarRecurso()
{
	Auto_ptr4<Recurso> res{ new Recurso };
	return res; // este valor de retorno invocará el constructor por movimiento
}

int main()
{
	Auto_ptr4<Recurso> mainres;
	mainres = generarRecurso(); // esta asignación invocará la asignación por movimiento

	return 0;
}
#endif



#include <iostream>

template<typename T>
class Auto_ptr5
{
	T* m_ptr;
public:
	Auto_ptr5(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr5()
	{
		delete m_ptr;
	}

	// Constructor por copia ahora impide que se hagan copias
	Auto_ptr5(const Auto_ptr5& a) = delete;

	// Constructor por Movimietno
	// Transfiere propiedad de a.m_ptr a m_ptr
	Auto_ptr5(Auto_ptr5&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}

	// asignación por copia. No copia permitida
	Auto_ptr5& operator=(const Auto_ptr5& a) = delete;

	// Asignación por movimiento
	// Transfiere propiedad de a.m_ptr a m_ptr
	Auto_ptr5& operator=(Auto_ptr5&& a) noexcept
	{
		// Detección auto-asignación
		if (&a == this)
			return *this;

		// Libera cualquier recurso almacenado aquí
		delete m_ptr;

		// Transfiere propiedad de a.m_ptr a m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

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

Auto_ptr5<Recurso> generarRecurso()
{
	Auto_ptr5<Recurso> res{ new Recurso };
	return res; // este valor de retorno invocará el constructor por movimiento
}

int main()
{
	Auto_ptr5<Recurso> mainres;
	mainres = generarRecurso(); // esta asignación invocará la asignación por movimiento

	return 0;
}























