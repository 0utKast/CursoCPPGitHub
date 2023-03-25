
//Código 001
#if 0
// En el archivo header:
extern Singleton SingletonInstance;

// En el archivo .cpp:
Singleton SingletonInstance;



//Código 002


class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void do_operation() {
        // Operación a realizar
    }

private:
    Singleton() {} // Constructor privado

    // Deshabilitar la copia y asignación
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

void f() {
    Singleton& Sf = Singleton::getInstance();
    Sf.do_operation();
}

void g() {
    Singleton& Sg = Singleton::getInstance(); // Refiere a la misma instancia que Sf
    Sg.do_operation();
}
#endif


#include <iostream>
class Singleton {
public:
    Singleton() {}
    int& get() { return value_; }

private:
    static int value_;
};

int Singleton::value_{ 0 };

int main() {
    // Crear un objeto Singleton y acceder a su valor
    Singleton s1;
    std::cout << "Valor inicial: " << s1.get() << std::endl;

    // Incrementar el valor y mostrarlo usando otro objeto Singleton
    ++s1.get();
    Singleton s2;
    std::cout << "Valor después de incrementar: " << s2.get() << std::endl;

    // Incrementar el valor usando un objeto temporal
    ++Singleton().get();
    std::cout << "Valor después de incrementar con objeto temporal: " << s1.get() << std::endl;

    return 0;
}

























#if 0

class Singleton {
public:
    Singleton() {}
    int& amp; get() { return value_; }
private:
    static int value_;
};
int Singleton::value_ = 0;

#endif