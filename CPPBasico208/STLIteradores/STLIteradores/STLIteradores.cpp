#if 0
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect;
    for (int contador = 0; contador < 6; ++contador)
        vect.push_back(contador);

    std::vector<int>::const_iterator it; // declara un iterator de solo lectura
    it = vect.cbegin(); // lo asigna al comienzo del vector
    while (it != vect.cend()) // Mientras no ha llegado al final
    {
        std::cout << *it << ' '; // imprime el valor al que apunta tras indireccionarlo
        ++it; // y pasamos al siguiente elemento
    }

    std::cout << '\n';
}

#include <iostream>
#include <list>

int main()
{

    std::list<int> li;
    for (int contador = 0; contador < 6; ++contador)
        li.push_back(contador);

    std::list<int>::const_iterator it; // declara un iterator
    it = li.cbegin(); // lo asigna al comienzo de la lista
    while (it != li.cend()) // mientras no llegue al final
    {
        std::cout << *it << ' '; // imprime el valor del elemento al que apunta tras indireccionar "it"
        ++it; // y se itera al siguiente elemento
    }

    std::cout << '\n';
}




#include <iostream>
#include <set>

int main()
{
    std::set<int> miset;
    miset.insert(2);
    miset.insert(6);
    miset.insert(-3);
    miset.insert(-8);
    miset.insert(4);
    miset.insert(4);

    std::set<int>::const_iterator it; // declara un iterator
    it = miset.cbegin(); // lo asigna al comienzo del set
    while (it != miset.cend()) // mientras no haya llegado al final
    {
        std::cout << *it << ' '; // imprime el valor del elemento al que apunta
        ++it; // y se itera al siguiente elemento
    }

    std::cout << '\n';
}

#endif



#if 0

#include <iostream>
#include <list>

int main()
{

    std::list<int> li{ 3, 5, 5, 6, 4, 3 };
    

    std::list<int>::const_iterator it; // declara un iterator
    it = li.cbegin(); // lo asigna al comienzo de la lista
    while (it != li.cend()) // mientras no llegue al final
    {
        std::cout << *it << ' '; // imprime el valor del elemento al que apunta tras indireccionar "it"
        ++it; // y se itera al siguiente elemento
    }

    std::cout << '\n';
}




#include <iostream>
#include <set>

int main()
{
    std::set<int> miset{ 3, 5, -3, 5, 2, 1 };
    std::set<int>::const_iterator it; // declara un iterator
    it = miset.cbegin(); // lo asigna al comienzo del set
    while (it != miset.cend()) // mientras no haya llegado al final
    {
        std::cout << *it << ' '; // imprime el valor del elemento al que apunta
        ++it; // y se itera al siguiente elemento
    }

    std::cout << '\n';
}




#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> mimap;
    mimap.insert(std::make_pair(4, "Celtics"));
    mimap.insert(std::make_pair(2, "Lakers"));
    mimap.insert(std::make_pair(1, "Bucks"));
    mimap.insert(std::make_pair(3, "Raptors"));
    mimap.insert(std::make_pair(6, "Warriors"));
    mimap.insert(std::make_pair(5, "Pacers"));

    auto it{ mimap.cbegin() }; // declara un iterator const y lo asigna al comienzo del vector
    while (it != mimap.cend()) // mientras it no haya llegado al final
    {
        std::cout << it->first << " = " << it->second << ' '; // imprime el valor del elemento al que apunta
        ++it; // y se itera al siguiente elemento
    }

    std::cout << '\n';
}

#endif



#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> mimap;
    mimap.insert(std::make_pair(4, "Celtics"));
    mimap.insert(std::make_pair(2, "Lakers"));
    mimap.insert(std::make_pair(1, "Bucks"));
    mimap.insert(std::make_pair(3, "Raptors"));
    mimap.insert(std::make_pair(6, "Warriors"));
    mimap.insert(std::make_pair(5, "Pacers"));

    auto it{ mimap.cbegin() }; // declara un iterator const y lo asigna al comienzo del vector
    while (it != mimap.cend()) // mientras it no haya llegado al final
    {
        std::cout << it->second << " = " << it->first << ' '; // imprime el valor del elemento al que apunta
        ++it; // y se itera al siguiente elemento
    }

    std::cout << '\n';
}




