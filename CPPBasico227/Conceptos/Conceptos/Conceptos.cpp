#if 0
#include <list>
#include <algorithm>

int main() {
    std::list<int> myList = { 1, 2, 3, 4, 5 };

    std::sort(myList.begin(), myList.end()); // Este algoritmo requiere iteradores directos y contiguos

    return 0;
}


// Plantilla de función multiplicar sin restricciones.
#include <iostream>

template<typename T>
T multiplicar(T primero, T segundo) { return primero * segundo; }

int main() {
    std::cout << "5 multiplicado por 3: " << multiplicar(4, 6) << "\n";    
    std::cout << "8.34 multiplicado por 4.56: " << multiplicar(7.25, 2.0) << "\n";

     std::string s1{"uno"};
     std::string s2{"dos"};
     auto resultado{multiplicar(s1, s2)}; // string no tiene un operador * 

}
#endif





// Plantilla de función multiplicar restringida que permite
//solo números enteros y valores de punto flotante.

#include <concepts>
#include <iostream>

template<typename T>
    requires std::integral<T> || std::floating_point<T>
T multiplicar(T primero, T segundo) { return primero * segundo; }

int main() {
    std::cout << "5 multiplicado por 3: " << multiplicar(4, 6) << "\n";
    std::cout << "8.34 multiplicado por 4.56: " << multiplicar(7.25, 2.0) << "\n";

    std::string s1{ "uno" };
    std::string s2{ "dos" };
    auto resultado{ multiplicar(s1, s2) };
}





#if 0
#endif











