#if 0
#include <iostream>
#include <string_view>

class Padre
{
public:
	virtual std::string_view getNombre1(int x) { return "Padre"; }
	virtual std::string_view getNombre2(int x) { return "Padre"; }
};

class Derivada : public Padre
{
public:
	virtual std::string_view getNombre1(short int x) { return "Derivada"; } // nota: parametro es un short int
	virtual std::string_view getNombre2(int x) const { return "Derivada"; } // nota: función es const
};

int main()
{
	Derivada segunda{};
	Padre& rPadre{ segunda };
	std::cout << rPadre.getNombre1(1) << '\n';
	std::cout << rPadre.getNombre2(2) << '\n';

	return 0;
}




#include <string_view>

class Primera
{
public:
	virtual std::string_view getNombre1(int x) { return "Primera"; }
	virtual std::string_view getNombre2(int x) { return "Primera"; }
	virtual std::string_view getNombre3(int x) { return "Primera"; }
};

class Segunda : public Primera
{
public:
	 std::string_view getNombre1(short int x) override { return "Segunda"; } // error de compilación, función no es una override
	 std::string_view getNombre2(int x) const override { return "Segunda"; } // error de compilación, función no es una override
	 std::string_view getNombre3(int x) override { return "Segunda"; } // correcto, función es un override de Primera::getNombre3(int)

};

int main()
{
	return 0;
}



#include <string_view>

class Primera
{
public:
	virtual std::string_view getNombre() { return "Primera"; }
};

class Segunda : public Primera
{
public:
	// el uso del especificador final hace que esta función no sea "anulable" "overridable"
	std::string_view getNombre() override final { return "Segunda"; } // correcto, anula a Primera::getNombre()
};

class Tercera : public Segunda
{
public:
	std::string_view getNombre() override { return "Tercera"; } // error de compilación: overrides Segunda::getNombre(), que es final
};





#include <string_view>

class Primera 
{
public:
	virtual std::string_view getNombre() { return "Primera"; }
};

class Segunda final : public Primera // Observa localización de identificador final
{
public:
	std::string_view getNombre() override { return "Segunda"; }
};

class Tercera : public Segunda // error compilación: no puede heredar de clase final
{
public:
	std::string_view getNombre() override { return "Tercera"; }
};



#include <string_view>

class Primera
{
public:
	virtual std::string_view getNombre() { return "Primera"; }
};

class Segunda final : public Primera // Observa localización de identificador final
{
public:
	std::string_view getNombre() override { return "Segunda"; }
};

class Tercera : public Primera 
{
public:
	std::string_view getNombre() override { return "Tercera"; }
};




#include <iostream>
#include <string_view>

class Padre
{
public:
	// Esta versión de getThis() devuelve un puntero a una clase Padre
	virtual Padre* getThis() { std::cout << "llamado Padre::getThis()\n"; return this; }
	void imprimirTipo() { std::cout << "devuelve un Padre\n"; }
};

class Derivada : public Padre
{
public:
	// Normalmente las funciones override deben devolver objetos del mismo tipo que la función padre
	// Pero, como Derivada deriva de Padre, es correcto devolver Derivada* en lugar de Padre*
	Derivada* getThis() override { std::cout << "llamada Derivada::getThis()\n";  return this; }
	void imprimirTipo() { std::cout << "devuelve una Derivada\n"; }
};

int main()
{
	Derivada derivada{};
	Padre* padre{ &derivada };
	derivada.getThis()->imprimirTipo(); // llama a Derivada::getThis(), devuelve un puntero a Derivada*, llama a Derivada::imprimirTipo
	padre->getThis()->imprimirTipo(); // llama a Derivada::getThis(), devuelve un puntero a Padre*, llama a Padre::imprimirTipo

	return 0;
}

#endif


#include <iostream>
#include <string_view>

class Padre
{
public:
	// Esta versión de getThis() devuelve un puntero a una clase Padre
	virtual Padre* getThis() { std::cout << "llamado Padre::getThis()\n"; return this; }
	void virtual imprimirTipo() { std::cout << "devuelve un Padre\n"; }
};

class Derivada : public Padre
{
public:
	// Normalmente las funciones override deben devolver objetos del mismo tipo que la función padre
	// Pero, como Derivada deriva de Padre, es correcto devolver Derivada* en lugar de Padre*
	Derivada* getThis() override { std::cout << "llamada Derivada::getThis()\n";  return this; }
	void imprimirTipo() override { std::cout << "devuelve una Derivada\n"; }
};

int main()
{
	Derivada derivada{};
	Padre* padre{ &derivada };
	derivada.getThis()->imprimirTipo(); // llama a Derivada::getThis(), devuelve un puntero a Derivada*, llama a Derivada::imprimirTipo
	padre->getThis()->imprimirTipo(); // llama a Derivada::getThis(), devuelve un puntero a Padre*, llama a Padre::imprimirTipo

	return 0;
}





#if 0
#endif

