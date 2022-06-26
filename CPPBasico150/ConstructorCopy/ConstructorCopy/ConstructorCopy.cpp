#if 0
#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador{};
    int m_denominador{};

public:
    // Constructor predeterminado
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador{ numerador }, m_denominador{ denominador }
    {
        assert(denominador != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}


int main()
{
	//podemos hacer una inicialización directa
    int x(4); // Inicialización directa de un integer
    Fraccion tresCuartos(3, 4); // Inicialización directa de una Fraccion, 
                                //llama al constructor de Fraccion(int, int)
	
	//Desde C++ 11 podemos hacer una inicialización uniforme
    int y{ 6 }; // Inicialización uniforme de un integer (desde C++ 11)
    Fraccion seisQuintos{ 6, 5 }; // Inicialización uniforme de una Fraccion, 
                                  //llama al constructor Fraccion(int, int)
	
	//También podemos hacer una inicialización por copia
    int z = 9; // Inicialización por copia de un integer
    // Inicialización por copia de una Fracción llamará a Fraccion(3, 1)
    Fraccion tres = Fraccion(3);
    // Inicializa por copia una Fraccion.El compilador intentará encontrar un mo- 
   // do de convertir 9 a una Fraccion,lo que invocará el constructor Fraccion(9,1)
    Fraccion nueve = 9; 
                       
	
}


int main()
{
    //inicialización directa
    int x(4); // de un tipo int
    Fraccion tresCuartos(3, 4); // de un tipo Fraccion

    //inicialización uniforme
    int y{ 6 }; // de un tipo int
    Fraccion seisQuintos{ 6, 5 }; // de un tipo Fraccion
                                  

    //inicialización por copia
    int z = 9; // de un tipo int    
    Fraccion nueve = 9; // de un tipo Fraccion
    Fraccion nueve = Fraccion(9); // de un tipo Fraccion
}
#endif

#if 0

#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador{};
    int m_denominador{};

public:
    // constructor predeterminado
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador{ numerador }, m_denominador{ denominador }
    {
        assert(denominador != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}

int main()
{
    Fraccion tresCuartos{ 3, 4 }; // Inicializa entre llaves una Fraccion, llama al constructor Fraccion(int, int)
    //Fraccion copiaFrac{ tresCuartos }; // Inicializa entre llaves una Fraccion, ¿Pero con qué constructor?
    Fraccion copiaFrac{ tresCuartos }; // Inicializa entre llaves una Fraccion, llama al constructor Fraccion(int, int)
    std::cout << copiaFrac << '\n';
}


#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador{};
    int m_denominador{};

public:
    // constructor que toma dos parámetros
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador{ numerador }, m_denominador{ denominador }
    {
        assert(denominador != 0);
    }

    // constructor por copia
    Fraccion( const Fraccion& frac)
        : m_numerador{ frac.m_numerador }, m_denominador{ frac.m_denominador }
        
    {
        // Aquí no necesitamos comprobar que denominador no es 0 porque
		// el constructor del objeto que copia ya lo ha hecho
        std::cout << "Constructor por copia llamado\n"; // ver que funciona
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}

int main()
{
    Fraccion tresCuartos{ 3, 4 }; // Inicialización uniforme, llama al constructor Fraccion(int, int)
    Fraccion copiaFrac{ tresCuartos }; // Inicialización uniforme, llama al constructor por copia
    std::cout << copiaFrac << '\n';
	
    Fraccion sieteQuintos{ 7,5 };
}

#endif

#if 0
#include <cassert>
#include <iostream>

class Fraccion
{
private:
    int m_numerador{};
    int m_denominador{};

    // constructor por copia (privado)
    Fraccion(const Fraccion& fraccion)
        : m_numerador{ fraccion.m_numerador }, m_denominador{ fraccion.m_denominador }
    {
        // Aquí no necesitamos comprobar que denominador no es 0 porque
       // el constructor del objeto que copia ya lo ha hecho
        std::cout << "constructor por copia llamado\n"; // ver que funciona
    }

public:
    // constructor que toma dos parámetros
    Fraccion(int numerador = 0, int denominador = 1)
        : m_numerador{ numerador }, m_denominador{ denominador }
    {
        assert(denominador != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraccion& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraccion& f1)
{
    out << f1.m_numerador << '/' << f1.m_denominador;
    return out;
}

int main()
{
    Fraccion tresCuartos{ 3, 4 }; // Inicialización uniforme, llama al constructor Fraccion(int, int)
	//el constructor por copia ahora es privado así que no podemos instanciar este objeto.
    Fraccion copiaFrac{ tresCuartos }; // // Inicialización uniforme, llama al constructor por copia
    std::cout << copiaFrac << '\n';
}
#endif