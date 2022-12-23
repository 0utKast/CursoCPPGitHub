#if 0
#include <iostream>
#include <thread>

void contador(int id, int numIteraciones)
{
	for (int i{ 0 }; i < numIteraciones; ++i) {
		std::cout << "Contador " << id << " tiene un valor " << i << '\n';
	}
}

int main()
{
	std::thread t1{ contador, 1, 6 };
	std::thread t2{ contador, 2, 4 };
	t1.join();
	t2.join();
}


#include <thread>;
#include <iostream>;

class Contador

{
private:
	int m_id;
	int m_numIteraciones;

public:
	Contador(int id, int numIteraciones)
		: m_id{ id }, m_numIteraciones{ numIteraciones }
	{
	}

	void operator()() const
	{
		for (int i{ 0 }; i < m_numIteraciones; ++i) {
			std::cout << "Contador " << m_id << " tiene un valor " << i << std::endl;
		}
	}

};

int main()
{
	// Usar sintaxis inicialización uniforme.
	std::thread t1{ Contador{ 1, 8 } };

	// Usar variable con nombre.
	Contador c{ 2, 6 };
	std::thread t2{ c };

	// Esperar a que los subprocesos finalicen.
	t1.join();
	t2.join();
}

#endif


#include <thread>;
#include <iostream>;
#include <functional>

class Contador

{
private:
	int m_id;
	int m_numIteraciones;

public:
	Contador(int id, int numIteraciones)
		: m_id{ id }, m_numIteraciones{ numIteraciones }
	{
	}

	void operator()() const
	{
		for (int i{ 0 }; i < m_numIteraciones; ++i) {
			std::cout << "Contador " << m_id << " tiene un valor " << i << std::endl;
		}
	}

};

int main()
{
	// Usar sintaxis inicialización uniforme.
	std::thread t1{ Contador{ 1, 8 } };

	// Usar variable con nombre.
	Contador c{ 2, 6 };
	std::thread t2{ c };

	//Pasar functor por referencia

	Contador d{ 3, 3 };
	std::thread t3{ std::ref(d) };


	// Esperar a que los subprocesos finalicen.
	t1.join();
	t2.join();
	t3.join();
}




#if 0

#include <iostream>

class Contador
{
private:
	int m_contador{ 0 };

public:
	int operator() (int c)
	{
		return (m_contador += c);
	}
};

int main()
{
	Contador cont{};
	Contador cont2{};
	std::cout << cont(10) << '\n'; // imprime 10
	std::cout << cont(20) << '\n'; // imprime 30
	std::cout << cont2(30) << '\n'; // imprime 30
	std::cout << cont(30) << '\n'; // imprime 60
	std::cout << cont2(20) << '\n'; // imprime 50

	return 0;
}
#endif



