#if 0
#include <vector>
#include <iostream>

int main()
{

    std::vector<int> vect;


    for (int contador = 0; contador < 6; ++contador)
        vect.push_back(10 - contador); // inserta al final del array

    for (int indice = 0; indice < vect.size(); ++indice)
        std::cout << vect[indice] << ' ';

    std::cout << '\n';
}



#include <vector>
#include <iostream>

int main()
{

    std::vector<int> vect;
    for (int contador = 0; contador < 16; ++contador)
        vect.push_back(10 - contador); // inserta al final del array

    for (int indice = 0; indice < vect.size(); ++indice)
        std::cout << vect[indice] << ' ';

    std::cout << '\n';
}





#include <iostream>
#include <deque>

int main()
{
    std::deque<int> deq;
    for (int contador = 0; contador < 3; ++contador)
    {
        deq.push_back(contador); // inserta al final del array
        deq.push_front(10 - contador); // inserta al principio del array
    }

    for (int indice = 0; indice < deq.size(); ++indice)
        std::cout << deq[indice] << ' ';

    std::cout << '\n';
}


#include <iostream>
#include <deque>

int main()
{
    std::deque<int> deq;
    for (int contador = 0; contador < 13; ++contador)
    {
        deq.push_back(contador); // inserta al final del array
        deq.push_front(10 - contador); // inserta al principio del array
    }

    for (int indice = 0; indice < deq.size(); ++indice)
        std::cout << deq[indice] << ' ';

    std::cout << '\n';
}


#include <algorithm>
#include <iostream>
#include <list>

int main()
{
    // Crear una lista que contiene integers
    std::list<int> l  { 7, 5, 16, 8 };

    // Añadir un integer al principio de la lista
    l.push_front(25);
    // Añadir un integer al final de la lista
    l.push_back(13);

    // Inserta un integer antes de 16 buscando
    auto insertar = std::find(l.begin(), l.end(), 16);
    if (insertar != l.end())
        l.insert(insertar, 42);

    // Imprime la lista
    std::cout << "l  { ";
    for (int n : l)
        std::cout << n << ", ";
    std::cout << "};\n";
}






#include <iostream>
#include <set>

int main()
{
    std::set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');
    a.insert('V');
    a.insert('A');
    for (auto& str : a)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';
    return 0;
}




#include <iostream>
#include <set>

int main()
{
    std::set<int> i;
    i.insert(5);
    i.insert(4);
    i.insert(7);
    i.insert(5);
    i.insert(3);
    for (auto& str : i)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';
    return 0;
}





#include <iostream>
#include <set>

int main()
{
    std::multiset<int> i;
    i.insert(5);
    i.insert(4);
    i.insert(7);
    i.insert(5);
    i.insert(3);
    for (auto& str : i)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';
    return 0;
}






#include <iostream>
#include <string>
#include <map> 

int main() {
    setlocale(LC_ALL, "es_ES");

    std::map<int, std::string> Alumnos;

    Alumnos.insert(std::pair<int, std::string>(001, "Alba"));

    Alumnos.insert(std::pair<int, std::string>(002, "Ivancinho"));

    Alumnos.insert(std::pair<int, std::string>(003, "Killian"));

    Alumnos.insert(std::pair<int, std::string>(003, "Alberto"));

    std::cout << "El tamaño del Map es: " << Alumnos.size() << std::endl;

    std::cout << std::endl << "El orden predeterminado del map es: " << std::endl;

    for (std::map<int, std::string>::iterator it = Alumnos.begin(); it != Alumnos.end(); ++it) {

        std::cout << (*it).first << ": " << (*it).second << std::endl;
    }
}
#endif

#if 0
#include <iostream>
#include <string>
#include <map> 

int main() {
    setlocale(LC_ALL, "es_ES");

    std::multimap<int, std::string> Alumnos;

    Alumnos.insert(std::pair<int, std::string>(001, "Alba"));

    Alumnos.insert(std::pair<int, std::string>(002, "Ivancinho"));

    Alumnos.insert(std::pair<int, std::string>(003, "Killian"));

    Alumnos.insert(std::pair<int, std::string>(003, "Alberto"));

    std::cout << "El tamaño del Map es: " << Alumnos.size() << std::endl;

    std::cout << std::endl << "El orden predeterminado del map es: " << std::endl;

    for (std::multimap<int, std::string>::iterator it = Alumnos.begin(); it != Alumnos.end(); ++it) {

        std::cout << (*it).first << ": " << (*it).second << std::endl;
    }
}



#include <iostream>
#include <stack>

int main() {
    std::stack<int> pila;
    pila.push(21);
    pila.push(22);
    pila.push(24);
    pila.push(25);

    pila.pop();
    pila.pop();

    while (!pila.empty()) {
        std::cout << pila.top() << "\n";
        pila.pop();
    }
}
#endif

#if 0

#include <iostream>
#include <queue>

int main() {
    std::queue<int> cola;
    cola.push(21);
    cola.push(22);
    cola.push(24);
    cola.push(25);

    cola.pop();
    cola.pop();

    while (!cola.empty()) {
        std::cout << cola.front() << "\n";
        cola.pop();
    }
}
#endif



#include <iostream>
#include <queue>


int main()
{
    std::priority_queue<int> prioridad;
    prioridad.push(10);
    prioridad.push(30);
    prioridad.push(20);
    prioridad.push(5);
    prioridad.push(1);   

    prioridad.pop();
    prioridad.pop();

    while (!prioridad.empty()) {
        std::cout << prioridad.top() << "\n";
        prioridad.pop();
    }
   

    return 0;
}


