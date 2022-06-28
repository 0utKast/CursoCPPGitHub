#if 0

#include <cassert>
#include <iostream>

class Fraccion
{
private:
	int m_numerador;
	int m_denominador;

public:
	// constructor toma dos parámetros
	Fraccion(int numerador = 0, int denominador = 1)
		: m_numerador(numerador), m_denominador(denominador)
	{
		assert(denominador != 0);
	}

	// constructor por copia
	Fraccion(const Fraccion& copy)
		: m_numerador(copy.m_numerador), m_denominador(copy.m_denominador)
	{
		// no necesita comprobar el denominador 0 porque ya es una fraccion válida
		std::cout << "Copy constructor called\n"; // ver que funciona
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
	int getNumerador() { return m_numerador; }
	void setNumerador(int numerador) { m_numerador = numerador; }
};

void imprimirFraccion(const Fraccion& f)
{
	std::cout << f;
}

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
	out << f1.m_numerador << '/' << f1.m_denominador;
	return out;
}

int main()
{
	imprimirFraccion(6);

	return 0;
}



#include <string>
#include <iostream>

class Frase
{
private:
	std::string m_string;
public:
	Frase(int x) // asigna string de tamaño x
	{
		m_string.resize(x);
	}

	Frase(const char* string) // asigna string para contener valor string
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const Frase& s);

};

std::ostream& operator<<(std::ostream& out, const Frase& s)
{
	out << s.m_string;
	return out;
}

void imprimirString(const Frase& s)
{
	std::cout << s;
}

int main()
{
	Frase frase = 'x'; // Compilará y usará Frase(int)
	std::cout << frase << '\n';
	imprimirString('x'); // Compilará y usará Frase(int)
	Frase otraFrase[]{ "una frase" }; // Compilará y usará Frase(const char*)
	std::cout << otraFrase << '\n'; // imprime direcc en memoria de primer char
	std::cout << *otraFrase << '\n';// imprime string completo
	return 0;
}

#endif









#if 0

int main()
{
	Frase frase = 'x'; // Compilará y usará Frase(int)
	std::cout << frase << '\n';
	imprimirString('x'); // Compilará y usará Frase(int)	
	return 0;
}















#include <string>
#include <iostream>

class Frase
{
private:
	std::string m_string;
public:
	// palabra clave explicit hace que este constructor no pueda realizar conversiones implícitas
	explicit Frase(int x) // asigna string de tamaño x
	{
		m_string.resize(x);
	}

	Frase(const char* string) // asigna string para contener valor string
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const Frase& s);

};

std::ostream& operator<<(std::ostream& out, const Frase& s)
{
	out << s.m_string;
	return out;
}

void imprimirString(const Frase& s)
{
	std::cout << s;
}

int main()
{
	Frase frase = 'x';
	imprimirString('x');
	
	std::cout << static_cast<Frase>(8); // compilará y usará Frase(int)

	return 0;
}



#include <string>
#include <iostream>

class Frase
{
private:
	std::string m_string;

	Frase(char) // objetos de tipo Frase(char) no pueden ser construidos desde fuera de la clase
	{
	}

public:
	// explicit impide conversiones implícitas con este constructor
	explicit Frase(int x) // asigna string de tamaño x
	{
		m_string.resize(x);
	}

	Frase(const char* string) // asigna string para contener valor string
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const Frase& s);

};

std::ostream& operator<<(std::ostream& out, const Frase& s)
{
	out << s.m_string;
	return out;
}

int main()
{
	Frase frase('x'); // error compilación, Frase(char) es private
	std::cout << frase;
	return 0;
}
#endif



#include <string>
#include <iostream>

class Frase
{
private:
	std::string m_string;

public:
	Frase(char) = delete; // cualquier uso de este constructor dará error

	// explicit evita las conversiones explícitas
	explicit Frase(int x) // asigna string de tamaño x /
	{
		m_string.resize(x);
	}

	Frase(const char* string) // asigna string para contener valor string
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const Frase& s);

};

std::ostream& operator<<(std::ostream& out, const Frase& s)
{
	out << s.m_string;
	return out;
}

int main()
{
	Frase frase('x'); // error compilación, Frase(char) borrado
	std::cout << frase;
	return 0;
}




#if 0

#endif
