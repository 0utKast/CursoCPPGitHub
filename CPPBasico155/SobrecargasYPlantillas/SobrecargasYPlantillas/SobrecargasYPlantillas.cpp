
#include <iostream> 
class Euros
{
private:
	int m_euros{};
public:
	Euros(int euros)
		: m_euros{ euros }
	{
	}

	friend std::ostream& operator<< (std::ostream& ostr, const Euros& c)
	{
		ostr << c.m_euros;
		return ostr;
	}
};

template <typename T>
const T& mayor(T x, T y)
{
	return (x < y) ? y : x;
}

int main()
{
	Euros corto{ 4 };
	Euros largo{ 6 };

	Euros masCaro = mayor(corto, largo);
	std::cout << masCaro << " es más caro\n";

	return 0;
}



#if 0


#endif


#if 0
template <>
const Euros& max(const Euros& x, const Euros& y)
{
	return (x < y) ? y : x;
}
#endif

#if 0
#include <iostream>

class Euros
{
private:
	int m_euros{};
public:
	Euros(int euros)
		: m_euros{ euros }
	{
	}

	friend bool operator< (const Euros& c1, const Euros& c2)
	{
		return (c1.m_euros < c2.m_euros);
	}

	friend std::ostream& operator<< (std::ostream& ostr, const Euros& c)
	{
		ostr << c.m_euros;
		return ostr;
	}
};

template <typename T>
const T& mayor(const T& x, const T& y)
{
	return (x < y) ? y : x;
}

int main()
{
	setlocale(LC_ALL, "es_ES.UTF-8");
	Euros corto{ 4 };
	Euros largo{ 6 };

	Euros masCaro = mayor(corto, largo);
	std::cout << masCaro << " es más caro\n";

	return 0;
}





#include <iostream>

template <typename T>
T promedio(const T* empleados, int numValores)
{
	T sum{ 0 };
	for (int contador{ 0 }; contador < numValores; ++contador)
		sum += empleados[contador];

	sum /= numValores;
	return sum;
}



int main()
{
	int intEmpleados[]{ 5, 2, 1, 6, 7 };
	std::cout << promedio(intEmpleados, 5) << '\n';

	double doubleEmpleados[]{ 2.45, 1.52, 7.87, 0.52 };
	std::cout << promedio(doubleEmpleados, 4) << '\n';

	return 0;
}
#endif













#if 0
// conversión interna por el compilador de la plantilla promedio a la función promedio de tipo int
template <int>
int promedio(const int* empleados, int numnValores)
{
	int sum{ 0 };
	for (int contador{ 0 }; contador < numValores; ++contador)
		sum += empleados[contador];

	sum /= numValores;
	return sum;
}

#endif




#if 0
#include <iostream> 
class Euros
{
private:
	int m_euros{};
public:
	Euros(int euros)
		: m_euros{ euros }
	{
	}
	
	Euros& operator+= (const Euros& euros)
	{
		m_euros += euros.m_euros;
		return *this;
	}

	Euros& operator/= (int x)
	{
		m_euros /= x;
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& ostr, const Euros& c)
	{
		ostr << c.m_euros;
		return ostr;
	}
	
	
};

template <typename T>
T promedio(const T* empleados, int numValores)
{
	T sum{ 0 };
	for (int contador{ 0 }; contador < numValores; ++contador)
		sum += empleados[contador];

	sum /= numValores;
	return sum;
}

int main()
{
	Euros eurosEmpleados[]{ Euros { 12 }, Euros { 7 }, Euros { 21 }, Euros { 3 } };
	std::cout << promedio(eurosEmpleados, 4) << '\n';

	return 0;
}










template <>
Euros promedio(const Euros* eurosEmpleados, int numValores)
{
	Euros sum{ 0 };
	for (int contador{ 0 }; contador < numValores; ++contador)
		sum += eurosEmpleados[contador];

	sum /= numValores;
	return sum;
}

#endif
