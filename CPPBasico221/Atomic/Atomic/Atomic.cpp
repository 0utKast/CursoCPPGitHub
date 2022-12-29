

#if 0

int contador{ 0 }; // variable Global
//...

int main()
{
	//...
	++contador; // Ejecutado en múltiples subprocesos
	//...


}

#include <atomic>
std::atomic<int> contador{ 0 };  // Variable global

int main()
{
	//...
	++contador; // Ejecutado en múltiples subprocesos
	//...

}

#include <atomic>;
#include <iostream>;
#include <type_traits>; //para std::is_trivially_copyable_v

class Bloqueado 
{ 
private: int m_array[123]; 
};
class Libre 
{ 
private: int m_int; 
};

int main()
{
	std::atomic <Bloqueado> bloqueado;
    std:: cout << std::is_trivially_copyable_v <Bloqueado> << " " << bloqueado.is_lock_free() << std::endl;
	std::atomic<Libre> libre;
	std::cout << std::is_trivially_copyable_v <Libre> << " " << libre.is_lock_free() << std::endl;
}

#endif

#include <atomic>
#include <thread>
#include <iostream>

// Declaramos una variable atómica compartida
std::atomic<int> variable_compartida(0);

void funcion_hilo() {
	for (int i = 0; i < 10; i++) {
		// Incrementamos la variable compartida de forma atómica y almacenamos su valor anterior
		int valor_anterior = variable_compartida.fetch_add(1);
		std::cout << "Hilo " << std::this_thread::get_id()
			<< ": valor anterior = " << valor_anterior
			//<< ", nuevo valor = " << (valor_anterior + 1) << std::endl;
		    << ", nuevo valor = " << variable_compartida << std::endl;
	}
}

int main() {
	// Creamos dos hilos que ejecutan la función "funcion_hilo"
	std::thread h1(funcion_hilo);
	std::thread h2(funcion_hilo);

	// Esperamos a que los hilos terminen
	h1.join();
	h2.join();

	// Mostramos el valor final de la variable compartida
	std::cout << "Valor final de la variable compartida: " << variable_compartida << std::endl;
	return 0;
}



#if 0
#include <iostream>;
#include <atomic>
#include <thread>

std::atomic<int> contadorCompartido(0);

void incrementarContador()
{
	// Incrementa el contador compartido automáticamente
	contadorCompartido++;
}

int main()
{
	std::thread t1(incrementarContador);
	std::thread t2(incrementarContador);

	t1.join();
	t2.join();

	// El valor final del contador compartido debe ser 2
	std::cout << "Valor final del contador compartido: " << contadorCompartido << std::endl;

	return 0;
}





#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> contadorCompartido(0);

void incrementarContador()
{
	// Incrementa el contador compartido automáticamente
	contadorCompartido++;
}

int main()
{
	// Creamos un array de subprocesos
	std::thread subprocesos[10];

	// Lanzamos cada uno de los subprocesos
	for (int i = 0; i < 10; i++)
	{
		subprocesos[i] = std::thread(incrementarContador);
	}

	// Esperamos a que todos los subprocesos finalicen
	for (int i = 0; i < 10; i++)
	{
		subprocesos[i].join();
	}

	// El valor final del contador compartido debe ser 10
	std::cout << "Valor final del contador compartido: " << contadorCompartido << std::endl;

	return 0;
}
#endif
