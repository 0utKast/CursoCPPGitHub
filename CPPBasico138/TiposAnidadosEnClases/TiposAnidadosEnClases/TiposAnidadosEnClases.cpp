
#if 0

#include <iostream>

enum class TipoFruta
{
	manzana,
	platano,
	fresa
};

class Fruta
{
private:
	TipoFruta m_tipo{};	

public:


	Fruta(TipoFruta tipo) :
		m_tipo{ tipo }
	{
	}

	TipoFruta getTipo() const { return m_tipo; }
	
};

int main()
{
	Fruta manzana{ TipoFruta::manzana };

	if (manzana.getTipo() == TipoFruta::manzana)
		std::cout << "Soy una manzana";
	else
		std::cout << "No soy una manzana";

	return 0;
}
#endif



#include <iostream>

class Fruta 
{
public:
	// Nota: hemos movido TipoFruta dentro de la clase
	
	enum TipoFruta
	{
		manzana,
		platano,
		fresa
	};

private:
	TipoFruta m_tipo{};
	

public:


	Fruta(TipoFruta tipo) :
		m_tipo{ tipo }
	{
	}

	TipoFruta getTipo() const { return m_tipo; }
	
};

int main()
{
	// Nota: accedemos al TipoFruta vía Fruta ahora
	Fruta manzana{ Fruta::manzana };

	if (manzana.getTipo() == Fruta::manzana)
		std::cout << "Soy una manzana";
	else
		std::cout << "No soy una manzana";

	return 0;
}

