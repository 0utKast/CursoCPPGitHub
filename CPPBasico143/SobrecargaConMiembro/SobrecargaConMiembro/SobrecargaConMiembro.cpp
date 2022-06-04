#if 0
//sobrecarga Euros + int con función amiga
#include <iostream>

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros)
        : m_euros{ euros } { }

    // Sobrecarga Euros + int
    friend Euros operator+(const Euros& euros, int valor);

    int getEuros() const { return m_euros; }
};

// nota: esta función no es una función miembro
Euros operator+(const Euros& euros, int valor)
{
    return Euros(euros.m_euros + valor);
}

int main()
{
    Euros euros1{ 6 };
    Euros euros2{ euros1 + 2 };
    std::cout << "Tengo " << euros2.getEuros() << " euros.\n";

    return 0;
}


// sobrecargar Euros + int con función miembro
#include <iostream>

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros)
        : m_euros{ euros } { }

    // Sobrecarga Euros + int
    Euros operator+ (int valor);

	// Sobrecargar int + Euros (imposible)
	int operator+ ( Euros euros);

    int getEuros() const { return m_euros; }
};

// nota: esta función es una función miembro
// el parámetro euros en la versión amiga es ahora el parámetro implícito *this
Euros Euros::operator+ (int valor)
{
    return Euros{ this->m_euros + valor };
}

int main()
{
    Euros euros1{ 6 };
    Euros euros2{ euros1 + 2 };
    std::cout << "Tengo " << euros2.getEuros() << " euros.\n";

    return 0;
}
#endif

#if 0
// sobrecargar euros + euros con función amiga
#include <iostream>
class Euros
{
private:
	int m_euros{};

public:
	Euros(int euros) : m_euros{ euros } { }

	// sumar Euros + Euros usando una función amiga
	friend Euros operator+(const Euros& e1, const Euros& e2);

	int getEuros() const { return m_euros; }
};

// nota: esta función no es una función miembro
Euros operator+(const Euros& e1, const Euros& e2)
{
	// usa el constructor Euros y operator+(int, int)
	// podemos acceder a m_euros directamente porque esta es una función amiga
	return Euros{ e1.m_euros + e2.m_euros };
}

int main()
{
	Euros euros1{ 6 };
	Euros euros2{ 8 };
	Euros sumarEuros{ euros1 + euros2 };
	std::cout << "Tengo " << sumarEuros.getEuros() << " euros.\n";

	return 0;
}


//sobrecargar euros + euros con función miembro
#include <iostream>
class Euros
{
private:
	int m_euros1;
	int m_euros2;
public:
	Euros(int e1, int e2) : m_euros1{ e1 }, m_euros2{ e2 }
	{
		std::cout << "Dentro del constructor de dos elementos" << std::endl;
	}
	const Euros operator+(const Euros& e) const
	{
		Euros resultado(this->m_euros1 + e.m_euros1, this->m_euros2 + e.m_euros2);
		return resultado;
	}
	
	friend std::ostream& operator<< (std::ostream& out, const Euros& euros);

	

};

std::ostream& operator<< (std::ostream& out, const Euros& euros)
{
	
	out << "Punto(" << euros.m_euros1 << ", " << euros.m_euros2 << ", " <<  ')';

	return out;
}

int main()
{
	Euros a(3, 5);
	Euros b(7, 6);
	std::cout << a + b << std::endl;
	
}
#endif



//sobrecargar euros + euros con función miembro
#include <iostream>
class Euros
{
private:
	int m_euros;
	
public:
	Euros(int e) : m_euros{ e }
	{
		
	}
	const Euros operator+(const Euros& e) const
	{
		return Euros{ this ->m_euros + e.m_euros };
		
		
	}

	friend std::ostream& operator<< (std::ostream& out, const Euros& euros);
};

std::ostream& operator<< (std::ostream& out, const Euros& euros)
{

	out  << euros.m_euros ;

	return out;
}

int main()
{
	Euros a{ 5 };
	Euros b{ 6 };	
	std::cout << a + b << std::endl;
	

}