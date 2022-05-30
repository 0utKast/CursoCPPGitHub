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

#endif


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



