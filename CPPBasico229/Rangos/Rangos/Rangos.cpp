#if 0
//cod.001
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };

    // Recorrido del vector usando iteradores
    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
//fin cod.001
#endif

#if 0
//cod.002
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };

    // Recorrido del vector usando un bucle for-each
    for (int x : v) {
        std::cout << x << " ";
    }
    return 0;
}
//fin code.002

EXPLICACIÓN cod.002
En este ejemplo, se crea un vector de enteros y se usa el bucle for - each para recorrer el vector.
La variable "x" se inicializa con cada elemento del vector y el bucle se repite hasta que se recorren todos los elementos del vector.
El bucle for - each se encarga de obtener el rango del vector automáticamente, el inicio y el final del rango se obtienen con begin() y end() respectivamente.
El código dentro del bucle se ejecuta con cada elemento del vector, imprimiendo el valor de cada uno en pantalla.


En el caso del bucle for - each, el compilador utiliza implícitamente los métodos begin() y end() para obtener el rango de elementos a recorrer, 
sin que sea necesario llamarlos explícitamente en el código. Sin embargo, el compilador necesita que el tipo de objeto con el cual trabaja tenga esos métodos 
para poder iterar sobre él.Por lo tanto, el bucle for - each sólo se puede usar con objetos que tengan definidos esos métodos de forma estándar, 
tales como los contenedores de la STL(STL containers) como vector, list, map, etc o con objetos que los implementen.
En resumen, el bucle for - each se aprovecha de esos métodos para obtener el rango a recorrer, pero no los usa explicitamente en el código, 
sino que se encarga de ello de forma automática.
#endif


#if 0

//cod.003
#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    for (auto i = std::ranges::rbegin(vec); i != std::ranges::rend(vec); ++i) {
        std::cout << *i << " ";
    }
    return 0;
}




//fin cod. 003
EXPLICACIÓN cod.003
Este código utiliza varias características de C++20 para imprimir los elementos de un std::vector<int> en orden inverso:

1.Incluye las cabeceras necesarias para utilizar las funciones y clases de la biblioteca de rango :
2.Crea un vector de enteros llamado vec con los valores 1, 2, 3, 4, 5 :
3.Utiliza la función std::ranges::rbegin() para obtener un iterador al último elemento del vector.
  Esta función es una versión mejorada del método std::vector<int>::rbegin().
4.Utiliza la función std::ranges::rend() para obtener un iterador al primer elemento del vector.
  Esta función es una versión mejorada del método std::vector<int>::rend().
5.Utiliza un bucle for para recorrer el vector utilizando los iteradores obtenidos en los pasos 3 y 4. 
6.El operador de desreferencia(*) se utiliza para imprimir el valor al que apunta el iterador en cada iteración.
7.Finalmente, el programa retorna 0.
-Este código imprime los elementos del vector en orden inverso : 5 4 3 2 1

#endif




#if 0

//cod. 004



#include <iostream>
#include <vector>
#include <ranges>

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    std::vector<int> vec;
    if (std::ranges::empty(vec)) {
        std::cout << "El vector está vacío." << std::endl;
    }
    else {
        std::cout << "El vector no está vacío." << std::endl;
    }
    return 0;
}



//fin cod.004





EXPLICACIÓN cod.004
Este código utiliza la función std::ranges::empty() de C++20 para determinar si un std::vector<int> está vacío o no.
#endif




#if 0


//cod.005



#include <iostream>
#include <vector>
#include <ranges>

int main() 
{
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    int* data = std::ranges::data(vec);
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    return 0;
}




//fin cod.005





EXPLICACIÓN cod.005
Este código utiliza la función std::ranges::data() para obtener un puntero al primer elemento de un std::vector<int> y luego imprime todos los elementos del vector.
1.Incluye las cabeceras necesarias para utilizar las funciones y clases de la biblioteca de rango
2.Crea un vector de enteros llamado vec con los valores 1, 2, 3, 4, 5   
3.Utiliza la función std::ranges::data() para obtener un puntero al primer elemento del vector.Esta función se utiliza para obtener un puntero al primer elemento de un rango.
En este caso, se está pasando el vector vec como argumento.
4.Utiliza el método size() del vector para obtener su tamaño y almacenarlo en una variable llamada size
5.Utiliza un bucle for para recorrer el vector utilizando el puntero obtenido en el paso 3 y el tamaño del vector obtenido en el paso 4. 
El operador de desreferencia(*) se utiliza para imprimir el valor al que apunta el puntero en cada iteración.
6.Finalmente, el programa retorna 0.
-Este código imprime los elementos del vector en orden :

#endif

#if 0

//cod.006



#include <vector>
#include <iostream>

int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    int* data = v.data();
    for (int i = 0; i < 3; i++)
        std::cout << data[i] << ' ';
    return 0;
}




//fin cod.006




EXPLICACIÓN cod.006
Similar a cod.005, pero pasamos como final del loop for  3, con lo que solo
devolverá los tres primeros elementos del vector.
#endif






#include <vector>
#include <iostream>
#include <span>

int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::span<int> rng(v.data(), 3);
    int* data = std::ranges::data(rng);
    int size = rng.size();
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    return 0;
}



#if 0
#endif





#if 0
#include <algorithm>
#include <iostream>
#include <forward_list>

template <typename R>
    requires std::sortable<typename R::iterator>
void my_sort(R& r) {
    std::sort(r.begin(), r.end());
}

int main() {
    std::forward_list<int> my_list = { 3, 4, 1, 5, 2 };
    my_list.sort();
    for (int x : my_list) {
        std::cout << x << " ";
    }
    return 0;
}
#endif


#if 0
En este ejemplo, se define una plantilla de función "my_sort" que toma un argumento de referencia a un rango "R" 
y ordena los elementos en ese rango utilizando la función "sort" de la biblioteca estándar de C++.
La plantilla tiene una restricción que asegura que los iteradores del rango sean sortable, usando la palabra clave "requires" y el tipo "iterator_t<R>".
En el main se declara una "forward_list" de enteros y se le aplica la función my_sort.En la siguiente línea se recorre la lista con un for - each y se imprime 
cada elemento en pantalla. Nota que se incluyen las cabeceras necesarias y se muestra una salida en el main, como lo solicitaste.



#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// Proyección para elevar al cuadrado cada elemento del rango
int square(int x) { return x * x; }

int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    // Utilizamos la proyección square para elevar al cuadrado los elementos del rango
    std::ranges::transform(v, v.begin(), square);
    // Imprimimos el resultado
    for (int x : v) {
        std::cout << x << ' ';
    }
}

#endif

#if 0
En este ejemplo, se tiene un vector de enteros llamado v, y se quiere elevar al cuadrado cada elemento del vector.Para ello se crea una función llamada square 
que recibe un entero y retorna el cuadrado de ese número, entonces se utiliza la función std::ranges::transform que recibe como primer parámetro 
el rango a transformar(en este caso el vector v), el segundo parámetro es un iterador al comienzo del rango de destino, y el tercer parámetro es 
la proyección a utilizar(en este caso square).Esto reemplazará los valores del vector original con los valores elevados al cuadrado.
Es importante mencionar que esta proyección no altera el tamaño del rango original, solo modifica los valores.




#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> data{ 33, 11, 22 };
    std::sort(std::begin(data), std::end(data));
    for (const auto& i : data) {
        std::cout << i << " ";
    }
    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> data{ 33, 11, 22 };
    std::ranges::sort(data);
    for (const auto& i : data) {
        std::cout << i << " ";
    }
    return 0;
}




import <string>;
import <vector>;
import <ranges>;
import <iostream>;
import <algorithm>;

using namespace std;

class Person
{
public:
    Person(string first, string last)
        : m_firstName{ move(first) }, m_lastName{ move(last) } { }

    const string& getFirstName() const { return m_firstName; }
    const string& getLastName() const { return m_lastName; }

private:
    string m_firstName;
    string m_lastName;
};

#endif







#if 0



#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    int* data = std::ranges::data(vec);
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    return 0;
}






#endif