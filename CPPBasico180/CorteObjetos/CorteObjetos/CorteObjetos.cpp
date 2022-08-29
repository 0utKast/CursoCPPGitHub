#include <functional> // para std::reference_wrapper
#include <iostream>
#include <vector>

class Padre
{
protected:
    int m_valor{};

public:
    Padre(int valor)
        : m_valor{ valor }
    {
    }

    virtual const char* getNombre() const { return "Padre"; }
    int getValor() const { return m_valor; }

    void virtual  imprimirNombre(const Padre& padre) 
    {
        std::cout << "Yo soy un " << padre.getNombre() << '\n';
    }
};

class Derivada : public Padre
{
public:
    Derivada(int valor)
        : Padre{ valor }
    {
    }

    const char* getNombre() const override { return "Derivada"; }

    void  imprimirNombre(const Padre& derivada)  override
    {
        std::cout << "Yo soy un " << derivada.getNombre() << '\n';
    }
};

int main()
{
    Derivada d1{ 5 };
    Derivada d2{ 6 };
    Padre& b{ d2 };

    b = d1; // esta línea es problemática

    return 0;
}











#if 0

int main()
{
    std::vector<std::reference_wrapper<Padre>> v{}; // un vector de referencias reasignables a Padre

    Padre b{ 5 }; // b y c no pueden ser objetos anónimos
    Derivada d{ 6 };

    v.push_back(b); // Añadimos un objeto Padre a nuestro vector
    v.push_back(d); // Añadimos un objeto derivada a nuestro vector

    // Imprimir todos los elementos de nuestro vector
    // usamos .get() para acceder a todos los elementos de std::reference_wrapper
    for (const auto& elemento : v) // element has type const std::reference_wrapper<Base>&
        std::cout << "Yo soy un " << elemento.get().getNombre() << " con valor " << elemento.get().getValor() << '\n';

    return 0;
}
#endif




#if 0

#include <vector>
int main()
{
    std::vector<Padre*> v{};

    Padre b{ 5 }; // b y d no pueden ser objetos anónimos
    Derivada d{ 6 };

    v.push_back(&b); // añadir un objeto Padre a nuestro vector
    v.push_back(&d); // añadir un objeto Derivada a nuestro vector

    // Imprimir todos los elementos de nuestro vector
    for (const auto* elemento : v)
        std::cout << "Yo soy un " << elemento->getNombre() << " con valor " << elemento->getValor() << '\n';

    return 0;
}
#endif









#if 0
#include <vector>

int main()
{
    std::vector<Padre> v{};
    v.push_back(Padre{ 5 }); // añade un objeto Padre a nuestro vector
    v.push_back(Derivada{ 6 }); // añade un objeto Derivada a nuestro vector

    // Imprimimos todos los elementos en nuestro vector
    for (const auto& elemento : v)
        std::cout << "Yo soy un " << elemento.getNombre() << " con valor " << elemento.getValor() << '\n';

    return 0;
}


#endif









#if 0
int main()
{
    Derivada d{ 5 };    
    d.imprimirNombre(d); 

    return 0;
}

#endif


 


#if 0
void imprimirNombre(const Padre& padre) // nota: padre ahora pasado por referencia
{
    std::cout << "Yo soy un " << padre.getNombre() << '\n';
}



void imprimirNombre(const Padre padre) // nota: padre pasado por valor, no por referencia
{
    std::cout << "Yo soy un " << padre.getNombre() << '\n';
}



int main()
{
    Derivada derivada{ 5 };
    std::cout << "derivada es un " << derivada.getNombre() << " Y tiene un valor de " << derivada.getValor() << '\n';

    Padre& ref{ derivada };
    std::cout << "ref es un " << ref.getNombre() << " y tiene un valor de " << ref.getValor() << '\n';

    Padre* ptr{ &derivada };
    std::cout << "ptr es un " << ptr->getNombre() << " y tiene un valor de " << ptr->getValor() << '\n';

    return 0;
}



#endif

#if 0
int main()
{
    Derivada derivada{ 5 };
    Padre padre{ derivada }; // ¿Qué pasa aquí?
    std::cout << "padre es un " << padre.getNombre() << " y tiene un valor de " << padre.getValor() << '\n';

    return 0;
}


#endif