#if 0
#include <iostream>

int sumar(int x, int y)
{
	int suma{ x + y };
	return suma;
}

int main()
{
	std::cout << sumar(5, 3) << '\n';

	return 0;
}




#include <iostream>

int sumar(int x, int y)
{
	// Creamos un objeto anónimo para contener y devolver el resultado de "x + y"
	return x + y; 
}

int main()
{
	std::cout << sumar(5, 3) << '\n';

	return 0;
}






#include <iostream>

void imprimirValor(int valor)
{
	std::cout << valor;
}

int main()
{
	int sum{ 5 + 3 };
	imprimirValor(sum);

	return 0;
}


#include <iostream>

void imprimirValor(int valor)
{
	std::cout << valor;
}

int main()
{
	imprimirValor(5 + 3);
	return 0;
}





#include <iostream>

class Centimos
{
private:
	int m_centimos{};

public:
	Centimos(int centimos)
		: m_centimos{ centimos }
	{}

	int getCentimos() const { return m_centimos; }
};

void imprimir(const Centimos& centimos)
{
	std::cout << centimos.getCentimos() << " centimos\n";
}

int main()
{
	Centimos centimos{ 6 };  // variable normal
	
	
	
	
	
	imprimir(centimos);

	return 0;
}




#include <iostream>

class Centimos
{
private:
	int m_centimos{};

public:
	Centimos(int centimos)
		: m_centimos{ centimos }
	{}

	int getCentimos() const { return m_centimos; }
};

void imprimir(const Centimos& centimos)
{
	std::cout << centimos.getCentimos() << " centimos\n";
}

int main()
{
	
	imprimir(Centimos{ 8 });

	return 0;
}





#include <iostream>

class Centimos
{
private:
	int m_centimos{};

public:
	Centimos(int centimos)
		: m_centimos{ centimos }
	{}

	int getCentimos() const { return m_centimos; }
};

Centimos sumar(const Centimos& c1, const Centimos& c2)
{
	Centimos sum{ c1.getCentimos() + c2.getCentimos() };
	return sum;
}

int main()
{
	Centimos centimos1{ 6 };
	Centimos centimos2{ 8 };
	Centimos sum{ sumar(centimos1, centimos2) };
	std::cout << "Tengo " << sum.getCentimos() << " centimos.\n";

	return 0;
}
#endif





#include <iostream>

class Centimos
{
private:
	int m_centimos{};

public:
	Centimos(int centimos)
		: m_centimos{ centimos }
	{}

	int getCentimos() const { return m_centimos; }
};

Centimos sumar(const Centimos& c1, const Centimos& c2)
{
	// devuelve valor anónimo de Centimos
	return { c1.getCentimos() + c2.getCentimos() }; 
}

int main()
{
	Centimos centimos1{ 6 };
	Centimos centimos2{ 8 };
	// imprime valor anónimo de Centimos
	std::cout << "Tengo " << sumar(centimos1, centimos2).getCentimos() << " centimos.\n"; 

	return 0;
}




#include <iostream>

class Centimos
{
private:
	int m_centimos{};

public:
	Centimos(int centimos)
		: m_centimos{ centimos }
	{}

	int getCentimos() const { return m_centimos; }
};

Centimos sumar(const Centimos& c1, const Centimos& c2)
{
	// devuelve valor anónimo de Centimos
	return { c1.getCentimos() + c2.getCentimos() }; 
}

int main()
{
	// imprime valor anónimo de Centimos
	std::cout << "Tengo " << sumar(Centimos{ 6 }, Centimos{ 8 }).getCentimos() << " centimos.\n"; 

	return 0;
}


#if 0
#endif