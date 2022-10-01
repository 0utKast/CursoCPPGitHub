#if 0

//....................Código anterior clase

int& IntArray::operator[](const int indice)
{
    if (indice < 0 || indice >= getLength())
        throw indice;

    return m_datos[indice];
}

//...............Código posterior clase



// Usando el  operator[] sobrecargado en IntArray de arriba

try
{
    int* valor{ new int{ array[indice1] + array[indice2]} };
}
catch (int valor)
{
    // ¿Qué es lo que estamos capturando aquí?
}


#include <string>
#include <string_view>

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string_view error)
		: m_error{ error }
	{
	}

	const std::string& getError() const { return m_error; }
};




#include <iostream>
#include <string>
#include <string_view>

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string_view error)
		: m_error{ error }
	{
	}

	const std::string& getError() const { return m_error; }
};

class IntArray
{
private:
	int m_datos[5]{}; // asumimos que array es de tamaño 5 para simplificar

public:
	IntArray() {}

	int getTamanho() const { return 5; }

	int& operator[](const int indice)
	{
		if (indice < 0 || indice >= getTamanho())
			throw ArrayException{ "Índice inválido" };

		return m_datos[indice];
	}

};

int main()
{
	setlocale(LC_ALL, "es_ES.utf-8");
	IntArray array;

	try
	{
		int value{ array[7] }; // subíndice fuera de rango
	}
	catch (const ArrayException& exception)
	{
		std::cerr << "Se ha producido una excepción array (" << exception.getError() << ")\n";
	}
}



#include <iostream>

class Padre
{
public:
	Padre() {}
};

class Derivada : public Padre
{
public:
	Derivada() {}
};

int main()
{
	try
	{
		throw Derivada();
	}
	catch (const Padre& padre)
	{
		std::cerr << "capturada Padre";
	}
	catch (const Derivada& derivada)
	{
		std::cerr << "capturada Derivada";
	}

	return 0;
}



#include <iostream>

class Padre
{
public:
	Padre() {}
};

class Derivada : public Padre
{
public:
	Derivada() {}
};

int main()
{
	try
	{
		throw Derivada();
	}
	catch (const Derivada& derivada)
	{
		std::cerr << "capturada Derivada";
	}
	catch (const Padre& padre)
	{
		std::cerr << "capturada Padre";
	}

	return 0;
}
#endif



#include <iostream>

class Padre
{
public:
	Padre() {}
};

class Derivada : public Padre
{
public:
	Derivada() {}
};

int main()
{
	try
	{
		throw Padre();
	}
	catch (const Derivada& derivada)
	{
		std::cerr << "capturada Derivada";
	}
	catch (const Padre& padre)
	{
		std::cerr << "capturada Padre";
	}

	return 0;
}





#if 0
#endif
