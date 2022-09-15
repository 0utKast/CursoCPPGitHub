#if 0

#include <iostream>
void imprimirDivision(int x, int y)
{
    if (y != 0)
        std::cout << static_cast<double>(x) / y;
}


void imprimirDivision(int x, int y)
{
    if (y != 0)
        std::cout << static_cast<double>(x) / y;
    else
        std::cerr << "Error: No se puede dividir por cero\n";
}

double hacerDivision(int x, int y) 
{ 
    return static_cast<double>(x) / y; 
}







#include <iostream>
bool imprimirDivision(int x, int y)
{
    if (y == 0)
    {
        std::cerr << "Error: No se puede dividir por cero\n";
        return false;
    }
    std::cout << static_cast<double>(x) / y;

    return true;
}
#endif




// El recíproco de x es 1/x
double reciproco(double x)
{
    return 1.0 / x;
}


// El recíproco de x es 1/x, devuelve 0.0 si x==0
double reciproco(double x)
{
    if (x == 0.0)
        return 0.0;

    return 1.0 / x;
}



