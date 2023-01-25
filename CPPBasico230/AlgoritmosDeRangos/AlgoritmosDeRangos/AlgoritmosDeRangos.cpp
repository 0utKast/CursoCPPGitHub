#if 0
//cod.001



#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> datos{ 33, 11, 22 };
    std::sort(std::begin(datos), std::end(datos));
    for (const auto& i : datos) {
        std::cout << i << " ";
    }
    return 0;
}



// fin cod.001


//cod.002


#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> datos{ 33, 11, 22 };
    std::ranges::sort(datos);
    for (const auto& i : datos) {
        std::cout << i << " ";
    }
    return 0;
}


//fin cod.002



//cod.003




#include <iostream>
#include <algorithm>
#include <list>
#include <ranges>

int main() {
    std::list datos{ 33, 11, 22 };
    std::ranges::sort(datos);
    for (const auto& i : datos) {
        std::cout << i << " ";
    }
    return 0;
}





//fin cod.003



//code.004



#include <iostream>
#include <vector>
#include <ranges>

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    std::vector<int> data{ 1, 2, 3, 4, 5, 3 };
    int target = 3;
    auto it = std::ranges::find(data, target);
    if (it != data.end()) {
        std::cout << "Se encontró el elemento " << target << " en el índice " << std::distance(data.begin(), it) << std::endl;
    }
    else {
        std::cout << "No se encontró el elemento " << target << std::endl;
    }
    return 0;
}



//fin cod.004



//cod.005



#include <string>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <algorithm>;

class Persona
{
private:
    std::string m_nombre;
    std::string m_apellido;
public:
    Persona(std::string nombre, std::string apellido)
        : m_nombre{ move(nombre) }, m_apellido{ move(apellido) } { }

    const std::string& getNombre() const { return m_nombre; }
    const std::string& getApellido() const { return m_apellido; }


};

int main()
{
    std::vector personas{ Persona{"Juan", "Monero"}, Persona{"Rosa", "Velarte"} };

    std::sort(begin(personas), end(personas)); // Error: no compila.
    
}




//fin cod.005




//cod.006



#include <string>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <algorithm>;

class Persona
{
private:
    std::string m_nombre;
    std::string m_apellido;
public:
    Persona(std::string nombre, std::string apellido)
        : m_nombre{ move(nombre) }, m_apellido{ move(apellido) } { }

    const std::string& getNombre() const { return m_nombre; }
    const std::string& getApellido() const { return m_apellido; }

};

int main()
{
    std::vector personas{ Persona{"Juan", "Monero"}, Persona{"Rosa", "Velarte"} };   
    std::ranges::sort(personas); // Error: no compila.
   
}




//fin cod.006  




//cod.007


#include <string>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <algorithm>;

class Persona
{
public:
    Persona(std::string nombre, std::string apellido)
        : m_nombre{ move(nombre) }, m_apellido{ move(apellido) } { }

    const std::string& getNombre() const { return m_nombre; }
    const std::string& getApellido() const { return m_apellido; }

private:
    std::string m_nombre;
    std::string m_apellido;
};

int main()
{
    std::vector personas{ Persona{"Rosa", "Velarte"}, Persona{"Juan", "Monero"}  };

     std::ranges::sort(personas, {},[](const Persona& persona) { return persona.getNombre(); }); 

    for (const auto& persona : personas) 
    { 
        std::cout << persona.getNombre() << std::endl;
       
    }
}



//fin cod.007 



#include <string>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <algorithm>;

class Persona
{
public:
    Persona(std::string nombre, std::string apellido)
        : m_nombre{ move(nombre) }, m_apellido{ move(apellido) } { }

    const std::string& getNombre() const { return m_nombre; }
    const std::string& getApellido() const { return m_apellido; }

private:
    std::string m_nombre;
    std::string m_apellido;
};

int main()
{
    std::vector personas{ Persona{"Vicente", "Velarte"}, Persona{"Rosa", "Velarte"}, Persona{"Juan", "Monero"}, Persona{"Juan", "Rendero"} };

    std::ranges::sort(personas, {}, [](const Persona& persona) { return std::pair{ persona.getNombre(),persona.getApellido() }; });

    for (const auto& persona : personas) {
        std::cout << persona.getNombre() << ' ' << persona.getApellido() << '\n';
    }
}
#endif

#if 0
#endif



//cod.008



#include <string>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <algorithm>;

class Persona
{
public:
    Persona(std::string nombre, std::string apellido)
        : m_nombre{ move(nombre) }, m_apellido{ move(apellido) } { }

    const std::string& getNombre() const { return m_nombre; }
    const std::string& getApellido() const { return m_apellido; }

private:
    std::string m_nombre;
    std::string m_apellido;
};

int main()
{
    std::vector personas{ Persona{"Juan", "Monero"}, Persona{"Rosa", "Velarte"} };  

    std::ranges::sort(personas, {}, &Persona::getNombre);

    for (const auto& person : personas) { std::cout << person.getNombre() << std::endl; }
}



//fin cod.008 




#if 0
#endif
#if 0
Este código crea una clase llamada Persona, la cual tiene dos propiedades privadas, m_nombre y m_apellido, y dos métodos públicos, getNombre() y getApellido(), 
para acceder a estas propiedades.En el método principal, se crea un vector de objetos Persona, luego se utiliza la función std::ranges::sort para ordenar los elementos 
en el vector utilizando el método getNombre() como criterio de ordenamiento.Finalmente, se usa un bucle for para imprimir el nombre de cada persona en el vector ordenado.
La función std::ranges::sort es una función de ordenamiento de C++20 que se basa en el concepto de rango, que es un conjunto de elementos que pueden ser iterados.
El primer argumento de la función es el rango a ordenar(en este caso, personas), el segundo argumento es un objeto de comparación opcional(en este caso, esta vacío) 
y el tercer argumento es un puntero a función(en este caso, &Persona::getNombre) que se utiliza para determinar el orden de los elementos en el rango.
En resumen, el código crea un vector de personas, ordena las personas según el nombre y finalmente imprime los nombres de las personas ordenadas.



#include <string_view>;
#include <vector>;
#include <ranges>;
#include <iostream>;

void imprimirRango(std::string_view mensaje, auto& rango)
{
    std::cout << mensaje;
    for (const auto& valor : rango) { std::cout << valor << " "; }
    std::cout << std::endl;
}

int main()
{
    std::vector valores{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    imprimirRango("Secuencia original: ", valores);

    // Filtrar todos los valores impares, dejando solo los valores pares.
    auto resultado1{ valores | std::views::filter([](const auto& valor) { return valor % 2 == 0; }) };
    //Or:
    //  auto resultado1{ std::ranges::filter_view{ valores, [](const auto& valor) { return valor % 2 == 0; } } };
    imprimirRango("Solo valores pares: ", resultado1);

    // Transformar todos los valores a su valor doble.
    auto resultado2{ resultado1 | std::views::transform([](const auto& valor) { return valor * 2.0; }) };
    imprimirRango("Valores doblados: ", resultado2);

    // Eliminar los dos primeros elementos.
    auto resultado3{ resultado2 | std::views::drop(2) };
    imprimirRango("Dos primeros eliminados: ", resultado3);

    // Invertir la vista.
    auto resultado4{ resultado3 | std::views::reverse };
    imprimirRango("Secuencia invertida: ", resultado4);
}

#endif










