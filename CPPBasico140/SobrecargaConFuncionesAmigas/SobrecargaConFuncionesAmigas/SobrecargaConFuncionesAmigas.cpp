#if 0
#include <iostream>

class Euros
{
private:
	int m_euros{};

public:
	Euros(int euros) : m_euros{ euros } { }
	int getEuros() const { return m_euros; }
};




int main()
{
	Euros cuenta1{ 6 };
	Euros cuenta2{ 8 };
	Euros sumaEuros{ cuenta1 + cuenta2 };
	std::cout << "Tengo " << sumaEuros.getEuros() << " euros.\n";
	return 0;



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
	Euros operator+(const Euros & e1, const Euros & e2)
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




#include <iostream>

	class Euros
	{
	private:
		int m_euros{};

	public:
		Euros(int euros) : m_euros{ euros } { }

		// restar Euros - Euros usando una función amiga
		friend Euros operator-(const Euros& e1, const Euros& e2);

		int getEuros() const { return m_euros; }
	};

	// nota: esta función no es una función miembro
	Euros operator-(const Euros & e1, const Euros & e2)
	{
		// usa el constructor Euros y operator-(int, int)
		// podemos acceder a m_euros directamente porque esta es una función amiga
		return Euros{ e1.m_euros - e2.m_euros };
	}

	int main()
	{
		Euros euros1{ 6 };
		Euros euros2{ 8 };
		Euros restarEuros{ euros1 - euros2 };
		std::cout << "Tengo " << restarEuros.getEuros() << " euros.\n";

		return 0;
	}


#include <iostream>

	class Euros
	{
	private:
		int m_euros{};

	public:
		Euros(int euros) : m_euros{ euros } { }

		// multiplicar Euros * Euros usando una función amiga
		friend Euros operator*(const Euros& e1, const Euros& e2);

		int getEuros() const { return m_euros; }
	};

	// nota: esta función no es una función miembro
	Euros operator*(const Euros& e1, const Euros& e2)
	{
		// usa el constructor Euros y operator-(int, int)
		// podemos acceder a m_euros directamente porque esta es una función amiga
		return Euros{ e1.m_euros * e2.m_euros };
	}

	int main()
	{
		Euros euros1{ 6 };
		Euros euros2{ 8 };
		Euros multiplicarEuros{ euros1 * euros2 };
		std::cout << "Tengo " << multiplicarEuros.getEuros() << " euros.\n";

		return 0;
	}






#include <iostream>

	class Euros
	{
	private:
		int m_euros{};

	public:
		Euros(int euros) : m_euros{ euros } { }

		// dividir Euros / Euros usando una función amiga
		friend Euros operator/(const Euros& e1, const Euros& e2);

		int getEuros() const { return m_euros; }
	};

	// nota: esta función no es una función miembro
	Euros operator/(const Euros& e1, const Euros& e2)
	{
		// usa el constructor Euros y operator/(int, int)
		// podemos acceder a m_euros directamente porque esta es una función amiga
		return Euros{ e1.m_euros / e2.m_euros };
	}

	int main()
	{
		Euros euros1{ 6 };
		Euros euros2{ 8 };
		Euros dividirEuros{ euros1 / euros2 };
		std::cout << "Tengo " << dividirEuros.getEuros() << " euros.\n";

		return 0;
	}

#include <iostream>

	class Euros
	{
	private:
		double m_euros{};

	public:
		Euros(double euros) : m_euros{ euros } { }

		// dividir Euros / Euros usando una función amiga
		friend Euros operator/(const Euros& e1, const Euros& e2);

		double getEuros() const { return m_euros; }
	};

	// nota: esta función no es una función miembro
	Euros operator/(const Euros& e1, const Euros& e2)
	{
		// usa el constructor Euros y operator/(double, double)
		// podemos acceder a m_euros directamente porque esta es una función amiga
		return Euros{ e1.m_euros / e2.m_euros };
	}

	int main()
	{
		Euros euros1{ 6 };
		Euros euros2{ 8 };
		Euros dividirEuros{ euros1 / euros2 };
		std::cout << "Tengo " << dividirEuros.getEuros() << " euros.\n";

		return 0;
	}

	


	
#include <iostream>

	class Euros
	{
	private:
		int m_euros{};

	public:
		Euros(int euros) : m_euros{ euros } { }

		// suma Euros + Euros usando una función amiga
	   // Esta función no se considera miembro de la clase, aunque esté definida dentro de la clase
		friend Euros operator+(const Euros& c1, const Euros& c2)
		{
			// usa el constructor Euros y operator+(int, int)			
			return Euros{ c1.m_euros + c2.m_euros };
		}

		int getEuros() const { return m_euros; }
	};

	int main()
	{
		Euros euros1{ 6 };
		Euros euros2{ 8 };
		Euros eurosSum{ euros1 + euros2 };
		std::cout << "Tengo " << eurosSum.getEuros() << " euros.\n";

		return 0;
	}




#include <iostream>

	class Euros
	{
	private:
		int m_euros{};

	public:
		Euros(int euros) : m_euros{ euros } { }

		// suma Euros + int usando una función amiga
		friend Euros operator+(const Euros& c1, int valor);

		// suma int + Euros usando una función amiga
		friend Euros operator+(int valor, const Euros& c1);


		int getEuros() const { return m_euros; }
	};

	// nota: esta función no es una función miembro
	Euros operator+(const Euros& c1, int valor)
	{
		// usa el constructor Euros y operator+(int, int)
		// podemos acceder a m_euros directamente porque esta es una función amiga
		return { c1.m_euros + valor };
	}

	// nota: esta función no es una función miembro
	Euros operator+(int valor, const Euros& c1)
	{
		// usa el constructor Euros y operator+(int, int)
		// podemos acceder a m_euros directamente porque esta es una función amiga
		return { c1.m_euros + valor };
	}

	int main()
	{
		Euros c1{ Euros{ 7 } + 3 };
		Euros c2{ 3 + Euros{ 7 } };

		std::cout << "Tengo " << c1.getEuros() << " euros.\n";
		std::cout << "Tengo " << c2.getEuros() << " euros.\n";

		return 0;
	}
#endif


#include <iostream>

	class MinMax
	{
	private:
		int m_min{}; // Valor mínimo visto hasta ahora
		int m_max{}; // Valor máximo visto hasta ahora

	public:
		MinMax(int min, int max)
			: m_min{ min }, m_max{ max }
		{ }

		int getMin() const { return m_min; }
		int getMax() const { return m_max; }

		friend MinMax operator+(const MinMax& m1, const MinMax& m2);
		friend MinMax operator+(const MinMax& m, int valor);
		friend MinMax operator+(int valor, const MinMax& m);
	};

	MinMax operator+(const MinMax& m1, const MinMax& m2)
	{
		// Obrener el valor mínimo visto en m1 y m2
		int min{ m1.m_min < m2.m_min ? m1.m_min : m2.m_min };

		// Obtener el valor máximo visto en m1 y m2
		int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };

		return { min, max };
	}

	MinMax operator+(const MinMax& m, int valor)
	{
		// Obtener el valor mínimo visto en m y valor
		int min{ m.m_min < valor ? m.m_min : valor };

		// Obtener el valor máximo visto en m y valor
		int max{ m.m_max > valor ? m.m_max : valor };

		return { min, max };
	}

	MinMax operator+(int valor, const MinMax& m)
	{
		// llama a operator+(MinMax, int)
		return { m + valor };
	}

	int main()
	{
		MinMax m1{ 10, 15 };
		MinMax m2{ 8, 11 };
		MinMax m3{ 3, 12 };

		MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };

		std::cout << "Resultado: (" << mFinal.getMin() << ", " <<
			mFinal.getMax() << ")\n";

		return 0;
	}



#if 0
#endif