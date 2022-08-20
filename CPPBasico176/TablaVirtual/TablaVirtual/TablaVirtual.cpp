#if 0
#include <iostream>
class Padre
{
public:
    //Virtual Table* __vfptr;
    virtual void funcion1() {
        std::cout << "padref1"<<'\n';
    }
    virtual void funcion2() {
        std::cout << "padref2" << '\n';
    }
};

class Derivada1 : public Padre
{
public:
    void funcion1() override {
        std::cout << "derivada1f1" << '\n';
    
    }
};

class Derivada2 : public Padre
{
public:
    void funcion2() override {
        std::cout << "derivada1f2" << '\n';
    }
};


int main()
{
    Padre padre;
    padre.funcion1();
    padre.funcion2();
    Padre* padrePtr{ &padre };
    padrePtr->funcion1();
    padrePtr->funcion2();


    Derivada1 derivada1;
    derivada1.funcion1();
    derivada1.funcion2();

    Padre* d1Ptr{ &derivada1 };
    d1Ptr->funcion1();
    d1Ptr->funcion2();
    Derivada2 derivada2;
    Derivada1* d2Ptr{ &derivada2 };
    d2Ptr->funcion1();
    d2Ptr->funcion2();

    return 0;
}
#endif














#include <iostream>
class Padre
{
public:
    //Virtual Table* __vfptr;
    virtual void funcion1() {
        std::cout << "padref1" << '\n';
    }
    virtual void funcion2() {
        std::cout << "padref2" << '\n';
    }
};

class Derivada1 : public Padre
{
public:
    void funcion1() override {
        std::cout << "derivada1f1" << '\n';

    }
};

class Derivada2 : public Derivada1
{
public:
    void funcion2() override {
        std::cout << "derivada2f2" << '\n';
    }
};


int main()
{
    Derivada2 derivada2;
    derivada2.funcion1();
    derivada2.funcion2();
    Derivada1* d2Ptr{ &derivada2 };
    d2Ptr->funcion1();
    d2Ptr->funcion2();

    return 0;
}

