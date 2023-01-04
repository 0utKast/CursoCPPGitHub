
#if 0

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


void incremento(int& contador)
{
	for (int i{ 0 }; i < 100; ++i) {
		++contador;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

int main()
{
	int contador{ 0 };
	std::vector<std::thread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.emplace_back(std::thread{ incremento, std::ref(contador) });	
	}

	for (auto& t : threads) {
		t.join();
	}

	std::cout << "Resultado = " << contador << std::endl;
}



#include <iostream>;
#include <vector>;
#include <thread>;
#include <chrono>;
#include <atomic>;

void incremento(std::atomic<int>& contador)
{
	for (int i{ 0 }; i < 100; ++i) {
		++contador;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

int main()
{
	std::atomic<int> contador{ 0 };
	std::vector<std::thread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.push_back(std::thread{ incremento, std::ref(contador) });
	}

	for (auto& t : threads) {
		t.join();
	}

	std::cout << "Resultado = " << contador << std::endl;
}



#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>

	void incremento(int& contador)
	{
		std::atomic_ref<int> contadorAtomico{ contador };
		for (int i{ 0 }; i < 100; ++i) {
			++contadorAtomico;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}

	int main()
	{
		int contador{ 0 };
		std::vector <std::thread> threads;

		for (int i{ 0 }; i < 10; ++i) {
			threads.emplace_back(std::thread{ incremento, std::ref(contador) });
		}

		for (auto& t : threads) {
			t.join();
		}

		std::cout << "Resultado = " << contador << std::endl;
	}



#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>

	void incremento(std::atomic<int>& contador)
	{
		int resultado{ 0 };
		for (int i{ 0 }; i < 100; ++i) {
			++resultado;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		contador += resultado;
	}

	int main()
	{
		std::atomic<int> contador{ 0 };
		std::vector <std::thread> threads;

		for (int i{ 0 }; i < 10; ++i) {
			threads.push_back(std::thread{ incremento, std::ref(contador) });
	}

		for (auto& t : threads) {
			t.join();
		}

		std::cout << "Resultado = " << contador << std::endl;
		}

#endif



#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>	

	int main()
	{
		std::atomic<int> valor{ 0 };

		std::thread trabajo{ [&valor] {
			std::cout << "Subproceso inicia la espera." << std::endl;
			valor.wait(0);
			std::cout << "Subproceso despierta, valor = " << valor << std::endl;
		} };

		std::this_thread::sleep_for(std::chrono::seconds(2));

		std::cout << "Proceso Principal cambia valor a 1." << std::endl;
		valor = 1;
		valor.notify_all();  //despierta todos los subprocesos detenidos por una llamada a wait( )
		
		trabajo.join();
	}


#if 0

#endif



