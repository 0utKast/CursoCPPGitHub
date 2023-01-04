#if 0

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

// Puntero atómico a un entero
std::atomic<int*> p;

// Función que ejecutan los hilos
void sum() {
	// Leer el valor de p de forma atómica
	int* q = p.load();
	// Incrementar el valor almacenado en la dirección de memoria a la que apunta el puntero
	(*q)++;
	// Modificar el valor de p de forma atómica
	p.store(q + 1);
}

int main() {
	// Crear un vector de N elementos
	std::vector<int> v(20, 1);

	// Inicializar el puntero atómico al primer elemento del vector
	p.store(&v[0]);

	// Crear 10 hilos
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++) {
		threads.emplace_back(sum);
	}

	// Esperar a que terminen todos los hilos
	for (auto& t : threads) {
		t.join();
	}

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;	

	return 0;
}






#include <atomic> // para std::atomic
#include <memory> // para std::shared_ptr<T>

int main() {
	std::atomic<std::shared_ptr<int>> ptr;
	ptr.store(std::make_shared<int>(42));  // Almacena un puntero a un objeto de tipo int con valor 42
	std::shared_ptr<int> p = ptr.load();  // Recupera el puntero almacenado
	return 0;
}






#include <atomic> // para std::atomic<std::shared_ptr<int>>
#include <memory> // para std::make_shared<int>() y std::shared_ptr<int>
#include <thread> // para std::thread
#include <iostream>

int main() {
	// Creamos un puntero compartido a un objeto de tipo int con valor 42
	std::shared_ptr<int> shared_ptr = std::make_shared<int>(42);

	// Creamos una variable atómica para almacenar el puntero compartido
	std::atomic<std::shared_ptr<int>> ptr{ shared_ptr };

	// Creamos dos subprocesos que acceden al puntero de manera concurrente
	std::thread t1{ [&] {
		// El subproceso 1 recupera el puntero y lo usa
		std::shared_ptr<int> p = ptr.load();
	std::cout << "Subproceso 1: valor = " << *p << std::endl;
		} };
	std::thread t2{ [&] {
		// El subproceso 2 recupera el puntero y lo modifica
		std::shared_ptr<int> p = ptr.load();
		std::cout << "Subproceso 2: valor = " << *p << std::endl;
	*p = 56;
	std::cout << "Subproceso 2: valor modificado a " << *p << std::endl;
		} };

	// Esperamos a que los subprocesos terminen
	t1.join();
	t2.join();

	// Recuperamos el puntero y comprobamos el valor final
	std::shared_ptr<int> p = ptr.load();
	std::cout << "Valor final: " << *p << std::endl;
	

	return 0;
}




#include <atomic>

int main() {
	int x = 0;
	std::atomic_ref<int> a{ x };  // Declara una referencia atómica a la variable x
	a = 10;  // Asigna el valor 10 a la variable x de forma atómica
	return 0;
}





#include <atomic>
#include <iostream>
#include <thread>

int main() {
	int x = 0;
	std::atomic_ref<int> a(x);  // Declara una referencia atómica a la variable x

	// Crea dos hilos
	std::thread t1([&] {
		// Incrementa la variable x de forma atómica
		a++;
		});
	std::thread t2([&] {
		// Incrementa la variable x de forma atómica
		a++;
		});

	// Espera a que los hilos terminen
	t1.join();
	t2.join();

	// Imprime el valor final de la variable x
	std::cout << "x = " << x << std::endl;

	return 0;
}
#endif




#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <memory>

// Puntero atómico a un entero gestionado por std::shared_ptr
std::atomic<std::shared_ptr<int>> p;

// Función que ejecutan los hilos
void sum() {
	// Leer el valor de p de forma atómica
	std::shared_ptr<int> q = p.load();
	// Incrementar el valor almacenado en la dirección de memoria a la que apunta el puntero
	(*q)++;
	// Modificar el valor de p de forma atómica
	p.store(std::make_shared<int>(*q));
}

int main() {
	// Crear un vector de N elementos
	std::vector<int> v(20, 1);

	// Inicializar el puntero atómico al primer elemento del vector
	p.store(std::make_shared<int>(v[0]));

	// Crear 10 hilos
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++) {
		threads.emplace_back(sum);
	}

	// Esperar a que terminen todos los hilos
	for (auto& t : threads) {
		t.join();
	}

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}






#if 0




// Función que ejecutan los hilos
void sum() {
	// Leer el valor de p de forma atómica
	std::shared_ptr<int> q = p.load();
	// Incrementar el valor almacenado en la dirección de memoria a la que apunta el puntero
	(*q)++;
	// Modificar el valor de p de forma atómica
	p.store(std::make_shared<int>(*q + 1));
}


// Función que ejecutan los hilos
void sum() {
	// Leer el valor de p de forma atómica
	std::shared_ptr<int> q = p.load();
	// Incrementar el valor almacenado en la dirección de memoria a la que apunta el puntero
	(*q)++;
	// Modificar el valor de p de forma atómica
	p.store(p.load() + 1);
}

// Función que ejecutan los hilos
void sum() {
	// Leer el valor de p de forma atómica
	std::shared_ptr<int> q = p.load();
	// Incrementar el valor almacenado en la dirección de memoria a la que apunta el puntero
	(*q)++;
	// Modificar el valor de p de forma atómica
	p.store(std::make_shared<int>(*p.get() + 1));
}


// Función que ejecutan los hilos
void sum() {
	// Leer el valor de p de forma atómica
	std::shared_ptr<int> q = p.load();
	// Incrementar el valor almacenado en la dirección de memoria a la que apunta el puntero
	(*q)++;
	// Modificar el valor de p de forma atómica
	std::shared_ptr<int> r = p.load();
	p.store(std::make_shared<int>(*r.get() + 1));
}

#endif