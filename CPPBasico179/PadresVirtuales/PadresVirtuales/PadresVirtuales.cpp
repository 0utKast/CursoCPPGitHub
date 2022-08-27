#if 0
#include <iostream>

class AdaptadorUniversal
{
public:
    AdaptadorUniversal(int potencia)
    {
        std::cout << "AdaptadorUniversal: " << potencia << '\n';
    }
};

class DispositivoRemoto : virtual public AdaptadorUniversal
{
public:
    DispositivoRemoto(int dispositivoR, int potencia)
        : AdaptadorUniversal{ potencia }
    {
        std::cout << "DispositivoRemoto: " << dispositivoR << '\n';
    }
};

class DispositivoDisco : virtual public AdaptadorUniversal
{
public:
    DispositivoDisco(int dispositivoD, int potencia)
        : AdaptadorUniversal{ potencia }
    {
        std::cout << "DispositivoDisco: " << dispositivoD << '\n';
    }
};

class DispositivoMultiple : public DispositivoRemoto, public DispositivoDisco
{
public:
    DispositivoMultiple(int dispositivoR, int dispositivoD, int potencia)
        : DispositivoRemoto{ dispositivoR, potencia }, DispositivoDisco{ dispositivoD, potencia }
    {
    }
};

int main()
{
    DispositivoMultiple dispositivoM{ 1, 2, 3 };

    return 0;
}
#endif




#include <iostream>

class AdaptadorUniversal
{
public:
    AdaptadorUniversal(int potencia)
    {
        std::cout << "AdaptadorUniversal: " << potencia << '\n';
    }
};

class DispositivoRemoto : virtual public AdaptadorUniversal
{
public:
    DispositivoRemoto(int dispositivoR, int potencia)
        : AdaptadorUniversal{ potencia }
    {
        std::cout << "DispositivoRemoto: " << dispositivoR << '\n';
    }
};

class DispositivoDisco : virtual public AdaptadorUniversal
{
public:
    DispositivoDisco(int dispositivoD, int potencia)
        : AdaptadorUniversal{ potencia }
    {
        std::cout << "DispositivoDisco: " << dispositivoD << '\n';
    }
};

class DispositivoMultiple : public DispositivoRemoto, public DispositivoDisco
{
public:
    DispositivoMultiple(int dispositivoR, int dispositivoD, int potencia)
        : AdaptadorUniversal{ potencia }, DispositivoRemoto{ dispositivoR, potencia }, DispositivoDisco{ dispositivoD, potencia }
    {
    }
};



int main()
{
    DispositivoMultiple dispositivoM{ 1, 2, 3 };
    

    return 0;
}
