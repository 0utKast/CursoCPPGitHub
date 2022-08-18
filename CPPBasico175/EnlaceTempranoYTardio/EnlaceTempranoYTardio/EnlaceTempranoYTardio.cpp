#if 0
#include <iostream>

void imprimirValor(int valor)
{
    std::cout << valor;
}

int main()
{
    imprimirValor(5); // Llamada directa a función
    return 0;
}






#include <iostream>

int sumar(int x, int y)
{
    return x + y;
}

int restar(int x, int y)
{
    return x - y;
}

int multiplicar(int x, int y)
{
    return x * y;
}

int main()
{
    int x{};
    std::cout << "Escribe un numero: ";
    std::cin >> x;

    int y{};
    std::cout << "Escribe otro numero: ";
    std::cin >> y;

    int op{};
    do
    {
        std::cout << "Escribe una operacion (0=sumar, 1=restar, 2=multiplicar): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    int resultado{};
    switch (op)
    {
        // llama a la función de destino usando enlazado temprano
    case 0: resultado = sumar(x, y); break;
    case 1: resultado = restar(x, y); break;
    case 2: resultado = multiplicar(x, y); break;
    }

    std::cout << "La respuesta es: " << resultado << '\n';

    return 0;
}


#include <iostream>

int sumar(int x, int y)
{
    return x + y;
}

int main()
{
    // Creamos un puntero de función y hacemos que apunte a la función sumar
    int (*pFcn)(int, int) { sumar };
    std::cout << pFcn(5, 3) << '\n'; // sumar 5 + 3

    return 0;
}




#include <iostream>

int sumar(int x, int y)
{
    return x + y;
}

int restar(int x, int y)
{
    return x - y;
}

int multiplicar(int x, int y)
{
    return x * y;
}

int main()
{
    int x{};
    std::cout << "Escribe un numero: ";
    std::cin >> x;

    int y{};
    std::cout << "Escribe otro numero: ";
    std::cin >> y;

    int op{};
    do
    {
        std::cout << "Escribe una operacion (0=sumar, 1=restar, 2=multiplicar): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    // Crear un puntero de función llamado pFcn (observa los paréntesis en el nombre)
    int (*pFcn)(int, int) { nullptr };

    // Configuramos pFcn para que apunte a la función que elija el usuario
    switch (op)
    {
    case 0: pFcn = sumar; break;
    case 1: pFcn = restar; break;
    case 2: pFcn = multiplicar; break;
    }

    // Llama a la función a la que está apuntando pFcn con x e y como parámetros
    // esto usa enlazado tardío
    std::cout << "La respuesta es: " << pFcn(x, y) << '\n';

    return 0;
}

#endif


#include <utility> // para std::swap
#include <iostream>

// Observa que la comparación definida por el usuario es el tercer parámetro
void ordenSeleccion(int* array, int tamanho, bool (*fcnComparacion)(int, int))
{
    // Se itera a través de cada elemento del array
    for (int indiceInicio{ 0 }; indiceInicio < (tamanho - 1); ++indiceInicio)
    {
        // mejorIndice es el índice del elemento mayor/menor encontrado hasta ahora.
        int mejorIndice{ indiceInicio };

        // Buscar el elmento mayor/menor que se mantiene en el array (empezando en inicioIndice+1)
        for (int indiceActual{ indiceInicio + 1 }; indiceActual < tamanho; ++indiceActual)
        {
            // Si el elemento actual es mayor/menor que el previamente encontrado
            if (fcnComparacion(array[mejorIndice], array[indiceActual])) // AQUÍ SE HACE LA COMPARACIÓN
            {
                // Este es el nuevo número mayor/menor para esta iteración
                mejorIndice = indiceActual;
            }
        }

        // Swap (intercambiar) nuestro elemento inicial con el elemento mayor/menor
        std::swap(array[indiceInicio], array[mejorIndice]);
    }
}

// Esta es una función de comparación que coloca en orden ascendente
// (Nota: es exactamente la misma que la función ascendente( ) anterior)
bool ascendente(int x, int y)
{
    return x > y; // swap(intercambia) si el primer elemento es mayor que el segundo
}

// Esta es una función de comparación que coloca en orden descendente
bool descendente(int x, int y)
{
    return x < y; // swap(intercambia) si el segundo elementos es mayor que el primero
}

// Esta función imprime los valores en el array
void imprimirArray(int* array, int tamanho)
{
    for (int indice{ 0 }; indice < tamanho; ++indice)
    {
        std::cout << array[indice] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    std::cout << "Escribe 1 para orden descendente o 2 para orden ascendente: ";

    int elegir{ };
    std::cin >> elegir;
    if (elegir == 1)
    {
        // Coloca el array en orden descendente usando la función descendente()
        ordenSeleccion(array, 9, descendente);
        imprimirArray(array, 9);
    }
    else if (elegir == 2)
    {
        // Coloca el array en orden ascendente usando la función ascendente()
        ordenSeleccion(array, 9, ascendente);
        imprimirArray(array, 9);
    }

    else
        std::cout << "Escribe 1 o 2";

    return 0;
}








#if 0
#endif