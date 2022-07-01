#if 0
#include <cassert>
#include <iostream>

class Fraccion
{
private:
	int m_numerador{ 0 };
	int m_denominador{ 1 };

public:
	// constructor con dos parámetros
	Fraccion(int numerador = 0, int denominador = 1)
		: m_numerador{ numerador }, m_denominador{ denominador }
	{
		assert(denominador != 0);
	}

	// constructor por copia
	Fraccion(const Fraccion& copy)
		: m_numerador{ copy.m_numerador }, m_denominador{ copy.m_denominador }
	{
		// no necesita comprobar si denominador es 0 porque copia una Fraccion válida
		std::cout << "Constructor por copia llamado\n"; // ver que funciona
	}

	// asignación sobrecargada
	Fraccion& operator= (const Fraccion& fraccion);

	friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
	out << f1.m_numerador << '/' << f1.m_denominador;
	return out;
}

// Una implementación muy simple de operator= 
Fraccion& Fraccion::operator= (const Fraccion& fraccion)
{
	// hacer la copia
	m_numerador = fraccion.m_numerador;
	m_denominador = fraccion.m_denominador;
	std::cout << "operador de asignacion sobrecargado usado\n"; // ver que funciona
    // devuelve el objeto existente para poder encadenar este operador
	return *this;
}

int main()
{
	Fraccion sieteCuartos{ 7, 4 };// usa el constructor con dos parámetros
	Fraccion frac{ sieteCuartos}; // usa el constructor por copia
	std::cout << frac << '\n';
	Fraccion seisQuintos{ 6, 5 };//usa el constructor con dos parámetros
	frac = seisQuintos; // llama al operador de asignación sobrecargado
	std::cout << frac << '\n';
	Fraccion frac1{ 4, 2 };
	Fraccion frac2{ 3, 6 };
	Fraccion frac3{ 7, 12 };
	frac1 = frac2 = frac3; // asignación en cadena
	std::cout << frac1 << '\n'<<frac2 << '\n' << frac3 << '\n';
	Fraccion frac4{ 8, 6 };
	frac4 = frac4;
	std::cout << frac4 << '\n';
	
	return 0;	
}

#include <iostream>

class Contratar
{
private:
	char* m_datos{};
	int m_largo{};

public:
	Contratar(const char* datos = nullptr, int largo = 0)
		: m_largo{ largo }
	{
		if (largo)
		{
			m_datos = new char[largo];

			for (int i{ 0 }; i < largo; ++i)
				m_datos[i] = datos[i];
		}
	}
	~Contratar()
	{
		delete[] m_datos;
	}

	// asignación sobrecargada
	Contratar& operator= (const Contratar& str);

	friend std::ostream& operator<<(std::ostream& out, const Contratar& s);
};

std::ostream& operator<<(std::ostream& out, const Contratar& s)
{
	out << s.m_datos;
	return out;
}

// implementación simplista de operator= (no usar)
Contratar& Contratar::operator= (const Contratar& str)
{
	// si datos existe en el string actual, bórralo
	if (m_datos) delete[] m_datos;

	m_largo = str.m_largo;

	// copiar los datos de str al objeto implícito
	m_datos = new char[str.m_largo];

	for (int i{ 0 }; i < str.m_largo; ++i)
		m_datos[i] = str.m_datos[i];

	// devuelve el objeto existente para poder encadenar este operador
	return *this;
}

int main()
{
	Contratar alex{ "Alex", 5 }; // instancia Alex
	alex = alex; // Alex se autoasigna
	std::cout << alex; // ¿Cómo te llamas?

	return 0;
}

#endif







#if 0


Contratar& Contratar::operator= (const Contratar& str)
{
	// comprueba si hay autoasignación
	if (this == &str)
		return *this;

	// si datos existe en el string actual, bórralo
	if (m_datos) delete[] m_datos;

	m_largo = str.m_largo;

	// copiar los datos de str al objeto implícito
	m_datos = new char[str.m_largo];

	for (int i{ 0 }; i < str.m_largo; ++i)
		m_datos[i] = str.m_datos[i];

	// devuelve el objeto existente para encadenar
	return *this;
}




#endif






#if 0
int main()
{
	Contratar alex("Alex", 5); // instancia Alex
	Contratar empleado;
	empleado = alex; // Alex es nuevo empleado
	std::cout << empleado; //¿cómo te llamas?

	return 0;
}
#endif



#include <cassert>
#include <iostream>

class Fraccion
{
private:
	int m_numerador{ 0 };
	int m_denominador{ 1 };

public:
	// constructor con dos parámetros
	Fraccion(int numerador = 0, int denominador = 1)
		: m_numerador{ numerador }, m_denominador{ denominador }
	{
		assert(denominador != 0);
	}

	// constructor por copia
	Fraccion(const Fraccion& copy) = delete;

	// asignación sobrecargada
	Fraccion& operator= (const Fraccion& fraccion) = delete; // impide copia por asignación

	friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
	out << f1.m_numerador << '/' << f1.m_denominador;
	return out;
}

int main()
{
	Fraccion cuatroQuintos{ 4, 5 };
	Fraccion f;
	f = cuatroQuintos; // error compilación, operator= se ha borrado
	std::cout << f;

	return 0;
}


