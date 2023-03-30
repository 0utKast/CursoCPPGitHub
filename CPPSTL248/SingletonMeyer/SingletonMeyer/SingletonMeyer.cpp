#if 0
//Código 001


#include <iostream>

class Singleton {
public:
    static Singleton& instance() {
        static Singleton inst;
        return inst;
    }

    int& get() { return value_; }

private:
    Singleton() : value_(0) {
        std::cout << "Singleton::Singleton()" << std::endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    ~Singleton() {
        std::cout << "Singleton::~Singleton()" << std::endl;
    }

private:
    int value_;
};

int main() {
    int i = Singleton::instance().get();
    
    ++Singleton::instance().get();
    

    return 0;
}




//Código 002



static bool inicializada = false;     // Variable oculta generada por el compilador
// Memoria para el ojbeto static, no inicializada al principio
char memoria[sizeof(Singleton)];
class Singleton {
public:
    static Singleton& instance() {
        if (!inicializada) {          // Pasa solo una vez
            inicializada = true;
            new (memoria) Singleton;  // Colocación new
            // Llama al constructor Singleton
        }
        // La memoria ahora contiene un objeto Singleton
        return *(Singleton*)(memoria);
    }
   // ...
};

#endif






//Código 003


#include <iostream>
class Singleton {
public:
    static Singleton& instance() {
        return instance_;
    }

    int&  get() { return value_; }

private:
    Singleton() : value_(0) 
    {
        std::cout << "Singleton::Singleton()" << std::endl;
    }
    ~Singleton() {
        std::cout << "Singleton::~Singleton()" << std::endl;
    }
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton& ) = delete;

private:
    static Singleton instance_;
    int value_;
};
Singleton Singleton::instance_;


#if 0
#endif