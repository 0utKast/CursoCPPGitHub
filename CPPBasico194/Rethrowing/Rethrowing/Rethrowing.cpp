
#if 0
BaseDatos* crearBaseDatos(std::string nombrearchivo)
{
	try
	{
		BaseDatos* d = new BaseDatos(nombrearchivo);
		d->open(); // asume que esto lanza una excepción si falla
		return d;
	}
	catch (int exception)
	{
		// Creación BaseDatos falla
		delete d;
		// Escribe un error a algún logfile global
		g_log.logError("Creación de BaseDatos ha fallado");
	}

	return nullptr;
}


int getValorIntDeBaseDatos(BaseDatos* d, std::string tabla, std::string clave)
{
	assert(d);

	try
	{
		return d->getValorInt(tabla, clave); // lanza excepción int si falla
	}
	catch (int exception)
	{
		// Escribe un error a algún logfile global
		g_log.logError("getValorIntDeBaseDatos ha fallado");

		// Sin embargo, no hemos manejado realmente este error
		// ¿Qué es lo qué hacemos aquí?
	}
}

int getValorIntDeBaseDatos(BaseDatos* d, std::string tabla, std::string clave)
{
	assert(d);

	try
	{
		return d->getValorInt(tabla, clave); // lanza excepción int si falla
	}
	catch (int exception)
	{
		// Escribe un error a algún logfile global
		g_log.logError("getValorIntDeBaseDatos ha fallado");

		throw 'q'; // lanza excepción char 'q' que se propagará por la pila para ser manejado por el llamador de getValorIntDeBaseDatos()
	}
}




int getValorIntDeBaseDatos(BaseDatos* d, std::string tabla, std::string clave)
{
	assert(d);

	try
	{
		return d->getIntValue(table, key); // lanza excepción int si falla
	}
	catch (int exception)
	{
		// Escribe un error a algún logfile global
		g_log.logError("getValorIntDeBaseDatos ha fallado");

		throw exception;
	}
}



int getValorIntDeBaseDatos(BaseDatos* d, std::string tabla, std::string clave)
{
	assert(d);

	try
	{
		return d->getValorInt(tabla, clave); // lanza excepción Derivada en caso de fallo
	}
	catch (Base& exception)
	{
		// Escribe un error a algún logfile global
		g_log.logError("getIntValueFromDatabase failed");

		throw exception; // Peligro: esto lanza un objeto Base, no un objeto Derivada
	}
}


#include <iostream>
class Padre
{
public:
	Padre() {}
	virtual void imprimir() { std::cout << "Padre"; }
};

class Derivada : public Padre
{
public:
	Derivada() {}
	void imprimir() override { std::cout << "Derivada"; }
};

int main()
{
	try
	{
		try
		{
			throw Derivada{};
		}
		catch (Padre& b)
		{
			std::cout << "Capturada Padre b, que es realmente una ";
			b.imprimir();
			std::cout << '\n';
			throw b; // El objeto Derivada aquí ha sido cortado
		}
	}
	catch (Padre& b)
	{
		std::cout << "Capturada Padre b, que realmente es una ";
		b.imprimir();
		std::cout << '\n';
	}

	return 0;
}
#endif


#include <iostream>
class Padre
{
public:
	Padre() {}
	virtual void imprimir() { std::cout << "Padre"; }
};

class Derivada : public Padre
{
public:
	Derivada() {}
	void imprimir() override { std::cout << "Derivada"; }
};

int main()
{
	try
	{
		try
		{
			throw Derivada{};
		}
		catch (Padre& b)
		{
			std::cout << "Capturada Padre b, que es realmente una ";
			b.imprimir();
			std::cout << '\n';
			throw; // nota: Ahora aquí relanzamos el  mismo objeto
		}
	}
	catch (Padre& b)
	{
		std::cout << "Capturada Padre b, que es realmente una ";
		b.imprimir();
		std::cout << '\n';
	}

	return 0;
}

#if 0
#endif