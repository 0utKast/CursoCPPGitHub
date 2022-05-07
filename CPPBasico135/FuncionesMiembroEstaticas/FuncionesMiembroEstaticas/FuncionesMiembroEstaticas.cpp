
#if 0
class Cualquiera
{
private:
	static int s_valor1;
public:
	static int s_valor2;

};

int Cualquiera::s_valor1{ 1 }; // inicializador, esto es correcto aunque s_valor sea privada porque es una definición
int Cualquiera::s_valor2{ 2 }; // inicializador, esto es correcto también.

int main()
{
	// ¿Cómo acceder aquí a Cualquiera::s_valor que está declarada como privada?
	Cualquiera::s_valor1 = 2; // No podemos acceder a s_valor porque es privada
	Cualquiera::s_valor2 = 3; // Podemos acceder a s_valor2 porque es publica
	
}




#include <iostream>
class Cualquiera
{
private:
	static int s_valor;
public:
	static int getValor() { return s_valor; } // función miembro static
};

int Cualquiera::s_valor{ 1 }; // inicializador

int main()
{
	std::cout << Cualquiera::getValor() << '\n';
}







#include <iostream>
class GeneradorID
{
private:
	static int s_siguienteID; // Esta es la declaración para una variable miembro static

public:
	static int getSiguienteID(); // Esta es la declaración para una función miembro static
};

// Esta es la definición de la variable miembro static fuera de la clase. Observa que no usamos "static" aquí.
// Empezamos a generar IDs en 1
int GeneradorID::s_siguienteID{ 1 };

// Esta es la definición de la función miembro static fuera de la clase. Observa que no usamos "static" aquí.
int GeneradorID::getSiguienteID() { return s_siguienteID++; }

int main()
{
	for (int count{ 0 }; count < 5; ++count)
		std::cout << "La siguiente ID es: " << GeneradorID::getSiguienteID() << '\n';

	return 0;
}



#include <vector>
#include <iostream>
class Cualquiera
{
public:
	static std::vector<char> s_mischars;
};
//  inicializa la variable static en el punto de definición
std::vector<char> Cualquiera::s_mischars{ 'a', 'e', 'i', 'o', 'u' }; 


int main()
{
	for (auto c : Cualquiera::s_mischars)
		std::cout << c << ' ';
	std::cout << '\n';

	return 0;
}





#include <vector>
#include <iostream>

class Cualquiera
{
public:
	static std::vector<char> s_mischars;
};

std::vector<char> Cualquiera::s_mischars{
  [] { // La parameter list de lambdas sin parámetros puede ser omitida.
	  // Dentro de la lambda podemos declarar otro vector y usar un loop.
	  std::vector<char> v{};

	  for (char ch{ 'a' }; ch <= 'z'; ++ch)
	  {
		  v.push_back(ch);
	  }

	  return v;
  }() // Llama a la lambda inmediatamente
};


int main()
{
	for (auto c : Cualquiera::s_mischars)
		std::cout << c << ' ';
	std::cout << '\n';

	return 0;
}

#endif




#include <iostream>
class Foo {
public:
	static inline int i;
	static inline int j;
private:
	struct constructor {
		constructor() {
			i = 3;
			j = 4;
		}
	};
	static inline constructor cons;
};

int main() {
	std::cout << Foo::i << '\n';
	std::cout << Foo::j << '\n';
}


#if 0
#include <vector>
#include <iostream>
class Cualquiera
{
public:
	static std::vector<char> s_mischars;

	class InitStatic // estamos definiendo una clase anidada llamada InitStatic
	{
	public:
		InitStatic() // el constructor init inicializará nuestra variable static
		{
			for (char ch{ 'a' }; ch <= 'z'; ++ch)
			{
				s_mischars.push_back(ch);
			}
		}
	};

private:
	static InitStatic s_inicializador; // usaremos este objeto static para asegurarnos que el constructor InitStatic es llamado
};

std::vector<char> Cualquiera::s_mischars{}; // define nuestra variable static member
Cualquiera::InitStatic Cualquiera::s_inicializador{}; // define nuestro inicializador static, que llamará al constructor InitStatic, que inicializará s_mischars

int main()
{
	for (auto c : Cualquiera::s_mischars)
		std::cout << c << ' ';
	std::cout << '\n';
	
	Cualquiera cualquiera;
	for (auto c : cualquiera.s_mischars)
		std::cout << c << ' ';
	std::cout << '\n';
	
}
#endif