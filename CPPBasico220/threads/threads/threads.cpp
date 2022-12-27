#if 0
#include <thread>
#include <iostream>

int main()
{
    int id{ 1 };
    int numIteraciones{ 5 };
    std::thread t1{ [id, numIteraciones] {
        for (int i { 0 }; i < numIteraciones; ++i) {
           std::cout << "Contador " << id << " tiene valor " << i << std::endl;
        }
    } };
    t1.join();
}







#include <thread>
#include <iostream>
class Consulta
{
public:
    Consulta(int id) : m_id{ id } { }
    void proceso() { std::cout << "Procesando consulta " << m_id << std::endl; }
private:
    int m_id;
};

int main()
{
    Consulta cons{ 100 };
    std::thread t{ &Consulta::proceso, &cons };
    t.join();
}



#include <thread>;
#include <iostream>;

int k{};
thread_local int n{};

void funcionThread(int id)
{
        std::cout << "Thread " << id << " k=" << k << " n=" << n << '\n';
        ++k;
        ++n;    
}

int main()
{
    std::thread t1{ funcionThread, 1 };
    t1.join();

    std::thread t2{ funcionThread, 2 };
    t2.join();

    
}

#endif


#if 0
import <thread>;

using namespace std;

int main()
{

	jthread job{ [](stop_token token) {
		while (!token.stop_requested()) {
			//...
		}
	} };

	job.request_stop();
}




import <thread>;

using namespace std;

int main()
{

	jthread job{ [](stop_token token) {
		while (!token.stop_requested()) {
			//...
		}
	} };

	job.request_stop();
}


#include <thread>
#include <iostream>

int main()
{
	std::jthread job{ [](std::stop_token token) {
		int contador = 0;
		while (!token.stop_requested()) {
			std::cout << "Iteracion del bucle: " << contador << std::endl;
			contador++;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	} 
	
	};

	std::this_thread::sleep_for(std::chrono::seconds(5));
	job.request_stop();
}
#endif


#include <thread>
#include <iostream>

int main()
{
    // Crear un objeto jthread que ejecuta una función lambda en un hilo de ejecución secundario
    std::jthread job{ [](std::stop_token token) {
        int contador = 0;
        // Bucle que se ejecuta mientras no se haya solicitado la cancelación y el contador sea menor que 10
        while (!token.stop_requested() && contador < 10) {
            std::cout << "Iteracion del bucle: " << contador << std::endl;
            contador++;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } };

    // Esperar a que el hilo de ejecución secundario finalice
    // job.join(); //desactivamos la función join()

    std::cout << "Hilo de ejecucion secundario finalizado" << std::endl;
}






