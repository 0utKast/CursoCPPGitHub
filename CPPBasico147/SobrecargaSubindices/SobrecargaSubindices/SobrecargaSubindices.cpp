
#if 0

int primerArray[10];

int main()
{

	primerArray[0] = 3; // pone el valor 3 en el primer elemento del array
	primerArray[1] = 1; // pone el valor 1 en el segundo elemento del array
	primerArray[2] = 5; // pone el valor 5 en el tercer elemento del array

}





class Clientes
{
private:
	int m_clientes[10]{};
};

int main()
{
	Clientes clientes{};
	// ¿cómo acceder a elementos de m_clientes?
	return 0;
}



class Clientes
{
private:
	int m_clientes[10]{};

public:
	void setElemento(int indice, int valor) 
	{ 
		m_clientes[indice] = valor; 
	}
	int getElemento(int indice) const 
	{ 
		return m_clientes[indice]; 
	}
};

int main()
{
	Clientes clientes{};
	clientes.setElemento(0, 4);

	return 0;
}




class Clientes
{
private: 
	int m_clientes[10]{};
public: 
	int* getClientes() 
	{
		return m_clientes;
	}

};

int main() 
{ 
	Clientes clientes{}; 
	clientes.getClientes()[0] = 4; 
	return 0; 
}





#include <iostream>
class Clientes 
{ private: 
int m_clientes[10]{}; 
public: 
	int& operator[] (int indice); 
}; 

int& Clientes::operator[] (int indice) 
{ 
	return m_clientes[indice]; 
}
int main()
{
	Clientes clientes{};
	 clientes[0] = 4 ; //configura un valor
	 std::cout << clientes[0] << '\n'; // obtiene un valor
	
	return 0;
	
}
#endif



#include <iostream>
class Clientes
{
private:
	int m_clientes[10]{};
public:
	int operator[] (int indice);
};

int Clientes::operator[] (int indice)
{
	return m_clientes[indice];
}
int main()
{
	Clientes clientes{};
	clientes[0] = 4; //configura un valor
	std::cout << clientes[0] << '\n'; // obtiene un valor

	return 0;

}



#if 0
#endif