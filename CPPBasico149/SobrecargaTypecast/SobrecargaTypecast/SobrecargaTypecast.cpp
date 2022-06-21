
#if 0
int main()
{
	int x{ 12 };
    // Hace un cast de int a double
	auto y{ static_cast<double>(x) }; 
}





#include <iostream>
class Centimos
{
private:
    int m_centimos;
public:
    Centimos(int centimos = 0)
        : m_centimos{ centimos }
    {
    }

    int getCentimos() const { return m_centimos; }
    void setCentimos(int centimos) { m_centimos = centimos; }
};

void imprimirInt(int cantidad)
{
    std::cout << cantidad;
}

int main()
{
    Centimos centimos{ 45 };
    imprimirInt(centimos.getCentimos()); // imprime 45    
	

    std::cout << '\n';

    return 0;
}






#include <iostream>
class Centimos
{
private:
    int m_centimos;
public:
    Centimos(int centimos = 0)
        : m_centimos{ centimos }
    {
    }

    // Sobrecarga int cast
    operator int() const { return m_centimos; }

    int getCentimos() const { return m_centimos; } //no necesaria
    void setCentimos(int centimos) { m_centimos = centimos; }
};

void imprimirInt(int cantidad)
{
    std::cout << cantidad;
}

int main()
{
    Centimos centimos{ 45 };
    imprimirInt(centimos); // imprime 45
	
    Centimos centimos{ 12 };
    int c{ static_cast<int>(centimos) };
	std::cout << c; // imprime 12

    std::cout << '\n';  

    return 0;
}

#endif





#if 0
int main()
{
    Centimos centimos{ 54 };
    int c{ static_cast<int>(centimos) };
}


#endif






#include <iostream>
class Centimos
{
private:
    int m_centimos;
public:
    Centimos(int centimos = 0)
        : m_centimos{ centimos }
    {
    }

    // Sobrecarga int cast
    operator int() const { return m_centimos; }

  
    void setCentimos(int centimos) { m_centimos = centimos; }
};

class Euros
{
private:
    int m_euros;
public:
    Euros(int euros = 0)
        : m_euros{ euros }
    {
    }

    // Nos permite convertir Euros en Centimos
    operator Centimos() const { return Centimos{ m_euros * 100 }; }
};

void imprimirCentimos(Centimos centimos)
{
    // centimos serán convertidos IMPLICITAMENTE a int aquí
    std::cout << centimos; 
}

int main()
{
    Euros euros{ 35 };
    // euros serán convertidos IMPLICITAMENTE a Centimos aquí
    imprimirCentimos(euros); 

    std::cout << " centimos de euro" << '\n';

    return 0;
}















#if 0
#endif