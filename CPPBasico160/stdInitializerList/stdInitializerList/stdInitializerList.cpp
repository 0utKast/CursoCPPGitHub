// stdInitializerList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#if 0
#include <iostream>

int main()
{
    int array[7];	
	std::cout << array[1] << std::endl;
}





#include <iostream> 

int main()
{
	int array[]{ 9, 8, 7, 6, 5 }; // lista de inicializadores
	for (auto i : array)
		std::cout << i << ' ';

	return 0;
}





#include <iostream>

int main()
{
	auto* array{ new int[5]{ 9, 8, 7, 6, 5 } }; 
	for (int contador{ 0 }; contador < 5; ++contador)
		std::cout << array[contador] << ' ';
	delete[] array;

	return 0;
}
#endif



#include <cassert> // para assert()
#include <iostream>

class ContenedorInt
{
private:
    int m_largo{};
    int* m_datos{};

public:
    ContenedorInt() = default;

    ContenedorInt(int largo) :
        m_largo{ largo }
    {
        assert(largo >= 0);
        if (largo > 0)
            m_datos = new int[largo] {};
    }
	
    // permite a ContenedorInt ser inicializado con una lista de inicializadores
    ContenedorInt(std::initializer_list<int> lista) 
        : ContenedorInt ( static_cast<int>(lista.size()) )
        // usa el constructor delegado para configurar el contenedor inicial
    {
        // Ahora inicializamos el array desde el contenedor
        int contador{ 0 };
        for (auto elemento : lista)
        {
            m_datos[contador] = elemento;
            ++contador;
        }
    }

    ~ContenedorInt()
    {
        delete[] m_datos;
        
    }

    void borrar()
    {
        delete[] m_datos;        
        m_datos = nullptr;
        m_largo = 0;
    }

    int& operator[](int indice)
    {
        assert(indice >= 0 && indice < m_largo);
        return m_datos[indice];
    }

    int getLargo() const { return m_largo; }

};

int main()
{
    // ¿Qué pasa si intentamos usar una lista de 
    //inicializadores con esta clase contenedor?
    //ContenedorInt no admite lista inicializadores
    ContenedorInt contenedor{ 5, 4, 3, 2, 1 }; 
    for (int contador{ 0 }; contador < 5; ++contador)
        std::cout << contenedor[contador] << ' ';

    return 0;
}













#if 0
int main()
{
	ContenedorInt contenedor{ 5 };
	contenedor[0] = 1;
	contenedor[1] = 2;
	contenedor[2] = 3;
	contenedor[3] = 4;
	contenedor[4] = 5;
    for (auto contador{ 0 }; contador < 5; ++contador)
        std::cout << contenedor[contador] << ' ';
	
    return 0;
}

#endif

