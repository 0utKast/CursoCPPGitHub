#if 0
class Forma2D
{
private:
    double valores[5][5]{};
};



#include <cassert> // para assert()
#include <iostream>

class Forma2D
{
private:
    double m_valores[5][5]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const; // para objetos const
};

double& Forma2D::operator()(int row, int col)
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return m_valores[row][col];
}

double Forma2D::operator()(int row, int col) const
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return m_valores[row][col];
}

int main()
{
    Forma2D forma2D;
    forma2D(3, 4) = 2.3;
    std::cout << forma2D(3, 4) << '\n';

    return 0;
}




#include <cassert> // para assert()
#include <iostream>
class Forma2D
{
private:
    double m_valores[5][5]{};

public:
    
    
    double& operator()(int row, int col);    
    double operator()(int row, int col) const;
    
    void operator()();
};

double& Forma2D::operator()(int row, int col)
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return m_valores[row][col];
}

double Forma2D::operator()(int row, int col) const
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return m_valores[row][col];
}

void Forma2D::operator()()
{
    // reinicia todos los elementos de la matriz a 0.0
    for (int row{ 0 }; row < 5; ++row)
    {
        for (int col{ 0 }; col < 5; ++col)
        {
            m_valores[row][col] = 0.0;
        }
    }
}

int main()
{
    Forma2D forma2D{};
    forma2D(3, 4) = 2.3;
	std::cout << forma2D(3, 4) << '\n';
    forma2D(); // erase forma2D
    std::cout << forma2D(3, 4) << '\n';

    return 0;
}


#include <iostream>

class Contador
{
private:
    int m_contador{ 0 };

public:
    int operator() (int c)
    {
        return (m_contador += c);
    }
};

int main()
{
    Contador cont{};   
    std::cout << cont(10) << '\n'; // imprime 10
    std::cout << cont(20) << '\n'; // imprime 30 

    return 0;
}
#endif






#include <iostream>

class Contador
{
private:
    int m_contador{ 0 };

public:
    int operator() (int c) 
    { 
        return (m_contador += c); 
    }
};

int main()
{
   Contador cont{};
   Contador cont2{};
    std::cout << cont(10) << '\n'; // imprime 10
    std::cout << cont(20) << '\n'; // imprime 30
	std::cout << cont2(30) << '\n'; // imprime 30
	std::cout << cont(30) << '\n'; // imprime 60
	std::cout << cont2(20)<< '\n'; // imprime 50

    return 0;
}



#if 0
#endif