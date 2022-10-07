


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
			throw; // nota: Ahora aquí relanzamos el objeto
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






