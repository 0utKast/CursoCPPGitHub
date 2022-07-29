#if 0
#include <iostream>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}


	void localizar() const { std::cout << "Yo soy un Padre\n"; }

};


class Derivada : public Padre
{
public:
	Derivada(int valor)
		: Padre{ valor }
	{
	}

	int getValor() const { return m_valor; }

};

int main()
{
	Padre padre{ 7 };
	Derivada derivada{ 12 };
	std::cout << "derivada tiene un valor de: " << derivada.getValor() << '\n';
	std::cout << "padre tiene un valor de: " << padre.getValor() << '\n';



	return 0;
}




#include <iostream>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}

	void localizar() const { std::cout << "Soy un Padre\n"; }
};
#endif
#if 0
class Derivada : public Padre
{
public:
	Derivada(int valor)
		: Padre{ valor }
	{
	}
};





#include <iostream>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}

	void localizar() const { std::cout << "Soy un Padre\n"; }
};

class Derivada : public Padre
{
public:
	Derivada(int valor)
		: Padre{ valor }
	{
	}

	int getValor() const { return m_valor; }

	// Añadimos Aquí la función localizar
	void localizar() const { std::cout << "Soy una Derivada\n"; }

};
int main()
{
	Padre padre{ 12 };
	padre.localizar();

	Derivada derivada{ 6 };
	derivada.localizar();

	return 0;
}





#include <iostream>

class Padre
{
protected:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}

	void localizar() const { std::cout << "Soy un Padre\n"; }
};

class Derivada : public Padre
{
public:
	Derivada(int valor)
		: Padre{ valor }
	{
	}

	int getValor() const { return m_valor; }

	void localizar() const
	{
		Padre::localizar(); // llama a Padre::localizar() primero
		std::cout << "Soy una Derivada\n"; // luego se sigue ejecutando
	}
};

int main()
{
	Padre padre{ 12 };
	padre.localizar();

	Derivada derivada{ 6 };
	derivada.localizar();

	return 0;
}

#endif



#include <iostream>

class Padre
{
private:
	int m_valor{};

public:
	Padre(int valor)
		: m_valor{ valor }
	{
	}

	friend std::ostream& operator<< (std::ostream& salida, const Padre& b)
	{
		salida << "En Padre\n";
		salida << b.m_valor << '\n';
		return salida;
	}
};

class Derivada : public Padre
{
public:
	Derivada(int valor)
		: Padre{ valor }
	{
	}

	friend std::ostream& operator<< (std::ostream& salida, const Derivada& d)
	{
		salida << "En Derivada\n";
		// usamos static_cast con "d" el parámetro de tipo derivada pasado, y lo convertimos 
		// a tipo Padre para usar la versión correcta de operator <<
		salida << static_cast<const Padre&>(d);
		return salida;
	}
};

int main()
{
	Derivada derivada{ 7 };

	std::cout << derivada << '\n';

	return 0;
}









