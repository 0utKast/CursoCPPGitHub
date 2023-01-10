#if 0
#include <mutex>
#include <thread>
#include <iostream>

int variable_compartida = 0;
std::mutex mutex;

void actualizar_variable(int nuevo_valor)
{
	std::lock_guard<std::mutex> lock(mutex);
	variable_compartida = nuevo_valor;
	std::cout << variable_compartida << std::endl;
	
}

int main()
{
	std::thread t0(actualizar_variable, 2);
	std::thread t1(actualizar_variable, 5);
	std::thread t2(actualizar_variable, 3);
	std::thread t3(actualizar_variable, 8);
	std::thread t4(actualizar_variable, 9);

	t0.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}



#include <iostream>
#include <thread>
#include <mutex>

int g_contador = 0;
std::mutex g_mutex;

void incrementarContador()
{
	std::lock_guard<std::mutex> lock(g_mutex);
	std::cout << std::this_thread::get_id() << ": g_contador = " << g_contador;
	++g_contador;
	std::cout << " --> g_contador = " << g_contador << std::endl;
}

int main()
{
	std::thread t1(incrementarContador);
	std::thread t2(incrementarContador);
	std::thread t3(incrementarContador);
	std::thread t4(incrementarContador);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}


	





#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;

void f()
{
	std::unique_lock <std::mutex> lck(m, std::defer_lock);
	if (lck.try_lock())
	{
		std::cout << "Adquirido el bloqueo en la función f()" << std::endl;
	}
	else
	{
		std::cout << "No se pudo adquirir el bloqueo en la función f()" << std::endl;
	}

	if (lck.owns_lock())
	{
		std::cout << "lck en f() posee el bloqueo" << std::endl;
	}
	else
	{
		std::cout << "lck en f() no posee el bloqueo" << std::endl;
	}
}

int main()
{
	std::unique_lock<std::mutex> lck(m, std::defer_lock);
	if (lck.try_lock())
	{
		std::cout << "Adquirido el bloqueo en main()" << std::endl;
	}
	else
	{
		std::cout << "No se pudo adquirir el bloqueo en main()" << std::endl;
	}

	if (lck.owns_lock())
	{
		std::cout << "lck en main() posee el bloqueo" << std::endl;
	}
	else
	{
		std::cout << "lck en main() no posee el bloqueo" << std::endl;
	}

	std::thread t(f);
	t.join();

	return 0;
}




#include <iostream>
#include <shared_mutex>
#include <thread>

// Este es el objeto compartido que vamos a proteger con un lock
int obj_compartido = 0;

// Esta es la mutex que usaremos para proteger el objeto compartido
std::shared_mutex mutex;

// Esta función aumenta el valor del objeto compartido
// y lo muestra por pantalla
void increment_and_print()
{
	// Obtenemos un shared_lock para proteger el objeto compartido
	std::shared_lock lock(mutex);

	// Aumentamos el valor del objeto compartido
	obj_compartido++;

	// Mostramos el valor del objeto compartido
	std::cout << "Valor del objeto compartido: " << obj_compartido << std::endl;
}

int main()
{
	// Creamos dos subprocesos que ejecutan la función increment_and_print()
	std::thread t1(increment_and_print);
	std::thread t2(increment_and_print);

	// Esperamos a que los subprocesos terminen
	t1.join();
	t2.join();

	return 0;
}
#endif








#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

// Este es el objeto compartido que vamos a proteger con un lock
int obj_compartido = 0;

// Esta es la mutex que usaremos para proteger el objeto compartido
std::shared_mutex mutex;

// Esta función lee el valor del objeto compartido
// y lo muestra por pantalla
void leer_e_imprimir()
{
	// Obtenemos un shared_lock para proteger el objeto compartido
	std::shared_lock lock(mutex);

	// Leemos el valor del objeto compartido
	int valor = obj_compartido;

	// Mostramos el valor del objeto compartido
	std::cout << "Valor del objeto compartido: " << valor << std::endl;
}

// Esta función escribe un nuevo valor al objeto compartido
void escribir_valor(int nuevo_valor)
{
	// Obtenemos un unique_lock para proteger el objeto compartido
	std::unique_lock lock(mutex);

	// Escribimos el nuevo valor al objeto compartido
	obj_compartido = nuevo_valor;
}

int main()
{
	// Creamos dos subprocesos que ejecutan la función leer_e_imprimir()
	std::thread t1(leer_e_imprimir);
	std::thread t2(leer_e_imprimir);

	// Esperamos a que los subprocesos terminen
	t1.join();
	t2.join();

	// Creamos un subproceso que ejecuta la función escribir_valor()
	std::thread t3(escribir_valor, 42);

	// Esperamos a que el subproceso termine
	t3.join();
    // Creamo un nuevo subprceso que lea el valor modificado
	std::thread t4(leer_e_imprimir);

	t4.join();

	return 0;
}

#if 0

#endif


























#if 0
#include <mutex>;

std::mutex mut1;
std::mutex mut2;

void procesar()
{
	std::unique_lock lock1{ mut1, std::defer_lock };
	std::unique_lock lock2{ mut2, std::defer_lock };
	//std::unique_lock<std::mutex> lock1{ mut1, std::defer_lock };
	//std::unique_lock<std::mutex> lock2{ mut2, std::defer_lock };
	lock(lock1, lock2);

	// Locks adquiridos.

} // Locks automáticamente liberados.

int main()
{
	procesar();
}



#include <mutex>;
#include <iostream>;

std::mutex mut1;
std::mutex mut2;

int accion()
{
	// Realiza alguna acción.
	return 42;
}

void procesar()
{
	std::unique_lock lock1{ mut1, std::defer_lock };
	std::unique_lock lock2{ mut2, std::defer_lock };
	lock(lock1, lock2);

	// Locks adquiridos.
	int valor = accion();
	std::cout << "El valor retornado por la accion es: " << valor << std::endl;
} // Locks automáticamente liberados.

int main()
{
	procesar();
}


#endif


#if 0
#include <mutex>;

std::mutex mut1;
std::mutex mut2;

void procesar()
{
	std::scoped_lock locks{ mut1, mut2 };
	//scoped_lock<mutex, mutex> locks{ mut1, mut2 };

	// Locks acquired.

} // Locks automatically released.

int main()
{
	procesar();
}





#include <thread>;
#include <iostream>;
#include <syncstream>;

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: m_id{ id }, m_numIterations{ numIterations }
	{
	}

	void operator()() const
	{
		for (int i{ 0 }; i < m_numIterations; ++i) {
			osyncstream{ cout } << "Counter " << m_id << " has valor " << i << endl;
		}
	}
	

private:
	int m_id;
	int m_numIterations;
};

int main()
{
	// Using uniform initialization syntax
	thread t1{ Counter{ 1, 20 } };

	// Using named variable
	Counter c{ 2, 12 };
	thread t2{ c };

	// Wait for threads to finish
	t1.join();
	t2.join();
}
#endif