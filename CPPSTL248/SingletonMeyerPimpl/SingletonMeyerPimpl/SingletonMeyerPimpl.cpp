#include <iostream>
#include "Singleton.h"

int main() {
    Singleton& s1{ Singleton::getInstance() };
    Singleton& s2{ Singleton::getInstance() };

    std::cout << "Valor de s1: " << s1.get() << std::endl;
    std::cout << "Valor de s2: " << s2.get() << std::endl;

    s1.get() = 57;

    std::cout << "Valor de s1 después del cambio: " << s1.get() << std::endl;
    std::cout << "Valor de s2 después del cambio: " << s2.get() << std::endl;

    return 0;
}





