
#if 0
throw - 1; // throw a literal integer value
throw ENUM_INVALID_INDEX; // throw an enum value
throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
throw dX; // throw a double variable that was previously defined
throw MyException("Fatal Error"); // Throw an object of class MyException


try { // Statements that may throw exceptions you want to handle go here throw -1; // here's a trivial throw statement }


catch (int x) 
{ // Maneja una excepción de tipo int 
    std::cerr << "Capturamos una excepción int con valor" << x << '\n'; 
}

    catch (double) // note: no variable name since we don't use it in the catch block below
    {
        // Handle exception of type double here
        std::cerr << "We caught an exception of type double" << '\n';
    }



#include <iostream>
#include <string>

    int main()
    {
        setlocale(LC_ALL, "es_ES.utf8");
        try
        {      
            // Las declaraciones que pueden lanzar excepciones que queremos manejar deben ir aquí
             //throw - 1; // este es un ejemplo trivial
             throw 3.5; // otro ejemplo trivial
             //throw std::string("Esto es un string"); //otro ejemplo trivial más
        }
        catch (int x)
        {
            // Cualquier excepción de tipo int lanzada dentro del bloque try anterior envía el programa aquí
            std::cerr << "Detectamos una excepción int con un valor de : " << x << '\n';
        }
        catch (double) // sin nombre de variable ya que no usamos la excepción en sí misma en el bloque catch a continuación
        {
            // Cualquier excepción de tipo double lanzada dentro del bloque try de arriba envía el programa aquí
            std::cerr << "Detectamos una excepción de tipo double" << '\n';
        }        
        catch (const std::string&) // catch clases por referencia const
        {
            // Cualquier excepción std::string lanzada dentro del bloque try anterior envía el programa aquí
            std::cerr << "Detectamos una excepción de tipo std::string" << '\n';
        }

        std::cout << "Tras resolverse la excepción el programa continúa.\n";

        return 0;
    }



#include <iostream>

    int main()
    {
        try
        {
            throw 2.7; // throw (lanza) excepción de tipo double
            std::cout << "Esto nunca se imprime\n";
        }
        catch (double x) // maneja excepción de tipo double
        {
            std::cerr << "Hemos capturado un double de valor: " << x << '\n';
        }

        return 0;
    }
#endif


#if 0

#include <cmath> // para función sqrt()
#include <iostream>

    int main()
    {
        setlocale(LC_ALL, "es_ES.utf8");
        std::cout << "Escribe un número: ";
        double x{};
        std::cin >> x;

        try // Busca excepciones que ocurren dentro del bloque try y enruta al bloque(s) catch vinculados
        {
            // Si el usuario escribe un número negativo, esta es una condición de error
            if (x < 0.0)
                throw "No se puede calcular sqrt de número negativo"; // lanza excepción de tipo const char*
            

            // en otro caso, imprime la respuesta
            std::cout << "La raíz cuadrada de " << x << " es " << std::sqrt(x) << '\n';
        }
        catch (const char* exception) // captura excepciones de tipo const char*
        {
            std::cerr << "Error: " << exception << '\n';
            
        }

        std::cout << "continúa el flujo normal del programa";
    }

#endif


#include <iostream>
    bool imprimirDivision(int x, int y)
    {
        try
        {
        if (y == 0)
            throw "No se puede dividir por cero"; // lanza excepción de tipo const char*

        std::cout << static_cast<double>(x) / y;
    }
        catch (const char* exception) // captura excepciones de tipo const char*
        {
            std::cerr << "Error: " << exception << '\n';

        }

        return true;
    }

    int main()
    {
        setlocale(LC_ALL, "es_ES.utf8");
        imprimirDivision(4, 0);
        std::cout << "continúa flujo normal del programa";
   }

