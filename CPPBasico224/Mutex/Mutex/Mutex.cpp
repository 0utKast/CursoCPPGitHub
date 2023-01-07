
#if 0	
#include <mutex>

int contador{ 0 };
std::mutex contador_mutex;

void incrementarContador()
{
	// Adquirir el mutex
	contador_mutex.lock();

	// Proteger la sección crítica
	++contador;

	// Liberar el mutex
	contador_mutex.unlock();
}





#include <mutex>

int contador = 0;
std::recursive_mutex contador_mutex;

void doSomething()
{
	// Adquirir el mutex
	contador_mutex.lock();

	// Proteger la sección crítica
	// ...

	// Adquirir el mutex de nuevo
	contador_mutex.lock();

	// Proteger la sección crítica
	// ...

	// Liberar el mutex
	contador_mutex.unlock();

	// Liberar el mutex
	contador_mutex.unlock();
}



#include <iostream>
#include <mutex>

std::recursive_mutex m;

int funcion_recursiva(int n) {
	m.lock();
	int resultado;
	if (n > 0) {
		resultado = n + funcion_recursiva(n - 1);
	}
	else {
		resultado = 0;
	}
	m.unlock();
	return resultado;
}

int main() {
	int resultado = funcion_recursiva(5);
	std::cout << "Resultado: " << resultado << std::endl;
	return 0;
}




#include <iostream>
#include <mutex>

std::mutex m;  //provocará error deadlock en tiempo de ejecución

int funcion_recursiva(int n) {
	m.lock();
	int resultado;
	if (n > 0) {
		resultado = n + funcion_recursiva(n - 1);
	}
	else {
		resultado = 0;
	}
	m.unlock();
	return resultado;
}

int main() {
	int resultado = funcion_recursiva(5);
	std::cout << "Resultado: " << resultado << std::endl;
	return 0;
}

#endif

#if 0

#include <iostream>
#include <mutex>

std::recursive_mutex m;

void funcion_recursiva(int n) {
	m.lock();
	if (n > 0) {
		std::cout << n << std::endl;
		funcion_recursiva(n - 1);
	}
	m.unlock();
}

int main() {
	funcion_recursiva(5);
	return 0;
}




#include <iostream>
#include <thread>
#include <mutex>

// Creamos un objeto mutex
std::mutex mutex;

// Creamos una función que intentará adquirir el mutex
void funcion_con_mutex()
{
	// Intentamos adquirir el mutex
	if (mutex.try_lock())
	{
		// Si lo hemos adquirido, imprimimos un mensaje y lo liberamos
		std::cout << "Se ha adquirido el mutex" << std::endl;
		mutex.unlock();
	}
	else
	{
		// Si no hemos podido adquirir el mutex, imprimimos un mensaje
		std::cout << "No se ha podido adquirir el mutex" << std::endl;
	}
}

int main()
{
	// Creamos dos subprocesos que ejecutarán la función
	std::thread hilo1(funcion_con_mutex);
	std::thread hilo2(funcion_con_mutex);

	// Esperamos a que finalicen los subprocesos
	hilo1.join();
	hilo2.join();

	return 0;
}



#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

std::shared_mutex le_mutex;
int recurso;

void lector()
{
	while (true) {
		std::shared_lock lock(le_mutex);
		// Acceder y leer recurso
		std::cout << "Lector: " << recurso << std::endl;
	}
}

void escritor()
{
	while (true) {
		std::unique_lock lock(le_mutex);
		// Acceder y escribir en recurso
		recurso = 42;
		std::cout << "Escritor: actualizado recurso a " << recurso << std::endl;
	}
}

int main()
{
	std::thread t1(lector);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::thread t4(escritor);
	std::thread t2(lector);
	std::thread t3(lector);
	
	std::thread t5(escritor);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;
}






#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

std::shared_mutex le_mutex;
int recurso;

void lector()
{
	while (true) {
		le_mutex.lock_shared();
		// Acceder y leer recurso
		std::cout << "Lector: " << recurso << std::endl;
		le_mutex.unlock_shared();
	}
}

void escritor()

{

	while (true) {

		le_mutex.lock();
		// Acceder y escribir en recurso
		recurso = 42;
		std::cout << "Escritor: actualizado recurso a " << recurso << std::endl;
		le_mutex.unlock();
	}
	
}

int main()
{
	std::thread t1(lector);	
	std::thread t2(lector);
	std::thread t3(lector);
	std::thread t4(escritor);
	std::thread t5(escritor);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;
}



#include <iostream>
#include <shared_mutex>
#include <thread>

// Creamos una instancia de shared_mutex
std::shared_mutex mutex;

// Creamos una función que utiliza lock_shared() y unlock_shared()
void acceso_compartido_a_recurso() {
	// Bloqueamos el mutex en modo compartido
	mutex.lock_shared();
	try {
		// Accedemos al recurso compartido
		std::cout << "Accediendo al recurso compartido" << std::endl;
	}
	catch (...) {
		// Desbloqueamos el mutex si se lanza una excepción
		mutex.unlock_shared();
		throw;
	}
	// Desbloqueamos el mutex
	mutex.unlock_shared();
}

int main() {
	// Creamos dos subprocesos que ejecutan la función anterior
	std::thread thread1(acceso_compartido_a_recurso);
	std::thread thread2(acceso_compartido_a_recurso);

	// Iniciamos los subprocesos
	thread1.join();
	thread2.join();

	return 0;
}


#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

// Este es el recurso compartido que se protegerá con los bloqueos lectores-escritores
int recurso;

// Este es el bloqueo lectores-escritores
std::shared_mutex le_mutex;

void subproceso_escritor()
{
	// Obtiene un bloqueo exclusivo (para escritores)
	std::unique_lock<std::shared_mutex> lock(le_mutex);

	// Modifica el recurso compartido
	recurso++;
	std::cout << "Writer thread: " << recurso << std::endl;
}

void subproceso_lector()
{
	// Obtiene un bloqueo compartido (para lectores)
	std::shared_lock<std::shared_mutex> lock(le_mutex);

	// Accede al recurso compartido
	std::cout << "Reader thread: " << recurso << std::endl;
}

int main()
{
	std::thread writer1(subproceso_escritor);
	std::thread writer2(subproceso_escritor);
	std::thread reader1(subproceso_lector);
	std::thread reader2(subproceso_lector);

	writer1.join();
	writer2.join();
	reader1.join();
	reader2.join();

	return 0;
}




#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

// Este es el recurso compartido que se protegerá con los bloqueos lectores-escritores
int recurso;

// Este es el bloqueo lectores-escritores
std::shared_mutex le_mutex;

void subproceso_escritor()
{
	// Obtiene un bloqueo exclusivo (para escritores)
	std::lock_guard<std::shared_mutex> lock(le_mutex);

	// Modifica el recurso compartido
	recurso++;
	std::cout << "Subproceso escritor: " << recurso << std::endl;
}

void subproceso_lector()
{
	// Obtiene un bloqueo compartido (para lectores)
	std::shared_lock<std::shared_mutex> lock(le_mutex);

	// Accede al recurso compartido
	std::cout << "Subproceso lector: " << recurso << std::endl;
}

int main()
{
	std::thread escritor1(subproceso_escritor);
	std::thread escritor2(subproceso_escritor);
	std::thread lector1(subproceso_lector);
	std::thread lector2(subproceso_lector);

	escritor1.join();
	escritor2.join();
	lector1.join();
	lector2.join();

	return 0;
}
#endif


#include <mutex>
#include <iostream>

std::mutex m;

void func()
{
	std::lock_guard<std::mutex> guard(m);
	std::cout << "Accediendo al recurso compartido" << std::endl;
	// Accediendo al recurso compartido
}

int main()
{
	func();
	return 0;
}



#if 0
#endif































#if 0
#include <mutex>
#include <shared_mutex>
#include <iostream>

std::shared_mutex le_mutex;
int recurso;

void lector()
{
	while (true) {
		std::shared_lock lock(le_mutex);
		// Acceder y leer recurso
		std::cout << recurso << std::endl;
	}
}

void escritor()
{
	while (true) {
		std::unique_lock lock(le_mutex);
		// Acceder y escribir en recurso
		recurso = 42;
	}
}

#endif



















#if 0

#include <cstddef>
#include <thread>;
#include <vector>;
#include <iostream>;
#include <atomic>;
#include <format>;
#include <functional>;



std::atomic_flag spinlock = ATOMIC_FLAG_INIT; // Uniform initialization is not allowed.
static const size_t NumberOfThreads{ 50 };
static const size_t LoopsPerThread{ 100 };

void dowork(size_t threadNumber, std::vector<size_t>& data)
{
	for (size_t i{ 0 }; i < LoopsPerThread; ++i) {
		while (spinlock.test_and_set()) {}  // Spins until lock is acquired.
		// Save to handle shared data...
		data.push_back(threadNumber);
		spinlock.clear();                    // Releases the acquired lock.
	}
}

int main()
{
	std::vector<size_t> data;
	std::vector<std::thread> threads;
	for (size_t i{ 0 }; i < NumberOfThreads; ++i) {
		threads.push_back(std::thread{ dowork, i, ref(data) });
	}
	for (auto& t : threads) {
		t.join();
	}
	std::cout << std::format("data contains {} elements, expected {}.\n", data.size(),
		NumberOfThreads * LoopsPerThread);
}
#endif