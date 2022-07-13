

#include <iostream>
#include "ContenedorInt.h"

int main()
{
    // Declara un contenedor con 8 elementos
    ContenedorInt contenedor(8);

    // Llena el contenedor con números del 1 al 8
    for (int i{ 0 }; i < 8; ++i)
        contenedor[i] = i + 1;

    // Redimensiona el contenedor a 6 elementos
    contenedor.redimensionar(6);

    // Inserta el número 32 antes del elemento con indice 3
    contenedor.insertarAntes(32, 3);

    // Quita el elemento con indice 2
    contenedor.quitar(2);

    // Añade 20 y 55 al final y al principio del contenedor
    contenedor.insertarAlFinal(20);
    contenedor.insertarAlPrincipio(55);

    // Imprime todos los números
    for (int i{ 0 }; i < contenedor.getLargo(); ++i)
        std::cout << contenedor[i] << ' ';

    std::cout << '\n';

    return 0;
}


