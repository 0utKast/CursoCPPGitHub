
//Ejemplo de un array clásico en C++

#include <iostream>



int main() {
    int miArray[5] { 1, 2, 3, 4, 5 };

    std::cout << "Los elementos del array son: ";

    for (int i = 0; i < 5; i++) {
        std::cout << miArray[i] << " ";
    }

    return 0;
}


//ejemplo de un array clásico similar escrito en C
#include <stdio.h>

int main() {
    int miArray[5] = { 1, 2, 3, 4, 5 };

    printf("Los elementos del array son: ");

    for (int i = 0; i < 5; i++) {
        printf("%d ", miArray[i]);
    }

    return 0;
}



#if 0
#endif

#if 0
//Ejemplo de un array clásico decaído a puntero
#include <iostream>

int main() {
    int miArray[] = { 1, 2, 3, 4, 5 };
    int* punteroArray = miArray; // Decaimos el array a un puntero

    std::cout << "Los elementos del array son: ";

    for (int i = 0; i < 5; i++) {
        std::cout << *(punteroArray + i) << " ";
    }

    return 0;
}


//Ejemplo de como llevar a cabo una búsqueda en un array clásico usando un centinela
#include <iostream>

using namespace std;

int main() {
    int miArray[] = { 1, 2, 3, 4, 5, -1 };
    int* punteroArray = miArray; // Decaimos el array a un puntero

    int elementoBuscado = 3;

    while (*punteroArray != -1) {
        if (*punteroArray == elementoBuscado) {
            cout << "El elemento " << elementoBuscado << " se encuentra en el array." << endl;
            return 0;
        }
        punteroArray++;
    }

    cout << "El elemento " << elementoBuscado << " no se encuentra en el array." << endl;

    return 0;
}



//Forma de calcular el tamaño de un array clásico y lleva a cabo búsquedas en sus elementos
#include <iostream>

using namespace std;

int main() {
    int miArray[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(miArray) / sizeof(miArray[0]);

    int elementoBuscado = 3;

    for (int* ptr = miArray; ptr < miArray + n; ptr++) {
        if (*ptr == elementoBuscado) {
            cout << "El elemento " << elementoBuscado << " se encuentra en el array." << endl;
            return 0;
        }
    }

    cout << "El elemento " << elementoBuscado << " no se encuentra en el array." << endl;

    return 0;
}

//Forma de calcular el tamaño de un array clásico y determinar su primer y último elemento.

#include <iostream>

using namespace std;

int main() {
    int miArray[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(miArray) / sizeof(miArray[0]);

    int* primerElemento = &miArray[0];
    int* ultimoElemento = &miArray[n - 1];

    cout << "El primer elemento del array es: " << *primerElemento << endl;
    cout << "El último elemento del array es: " << *ultimoElemento << endl;

    return 0;
}



// Ejemplo de cálculo del tamaño de un array clásico en tiempo de ejecución
#include <iostream>

using namespace std;

int main() {
    int miArray[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(miArray) / sizeof(miArray[0]);

    cout << "El tamaño del array es: " << n << endl;

    return 0;
}




//Ejemplo de un array clásico utilizando aritmética de punteros
#include <iostream>

using namespace std;

int main() {
    int miArray[] = { 1, 2, 3, 4, 5 };
    int* ptr = miArray;

    int n = *(ptr + 4) - *ptr + 1;

    cout << "El tamaño del array es: " << n << endl;

    return 0;
}
#endif



#include <iostream>
#include <array>

int main() {
    // Inicializar un std::array con algunos valores
    std::array<int, 5> myArray = { 1, 2, 3, 4, 5 };

    // Usar un loop for-each para iterar a través de los elementos del array e imprimirlos
    for (int& element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}





