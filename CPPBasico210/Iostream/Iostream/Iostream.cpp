
#if 0

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

    for (const auto& [key, value] : mimap)
    {
        std::cout << key << " has value " << value << std::endl;
    }   

}



#include <iostream>
int main()
{
    std::string x;
    std::string y;
    std::cout << "Escribe tu nombre: ";
    std::cin >> x;
    std::cout<< x << std::endl;
    std::cout << "Escribe tu apellidos: ";
    std::cin >> y;
    std::cout << y << std::endl;

}


#include<iostream>
#include<cstdlib>
using namespace std;

int main() {

    // Providing a seed value
    srand((unsigned)time(NULL));

    // Get a random number
    int random = rand();

    // Print the random number
    cout << random << endl;

    return 1;
}



#include <iostream>
#include <chrono>
template<typename Diff>
void log_progress(Diff d)
{
    std::cout << "..("
        << std::chrono::duration_cast<std::chrono::milliseconds>(d).count()
        << " ms).." << std::flush;
}
int main()
{
    volatile int sink = 0;

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < 5; ++j)
    {
        for (int n = 0; n < 10000; ++n)
            for (int m = 0; m < 20000; ++m)
                sink += m * n; // do some work
        auto now = std::chrono::high_resolution_clock::now();
        log_progress(now - t1);
    }
    std::cout << '\n';
}




#include <iostream>
struct Foo {
    int n;
    Foo() {
        std::cout << "Escribe un int: "; 
        std::cin >> n;
    }
};

int main()
{
    Foo f;
    std::cout << "f.n es " << f.n << '\n';
}



#include <thread>
#include <iostream>
#include <chrono>
void f()
{
    std::cout << "Salida desde subproceso..." << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "...subproceso llama a flush()" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "es_ES");
    std::thread t1(f);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::clog << "Esta salida de main no está 'tie()' a cout\n";
    std::cerr << "Esta salida esta 'tie()' a cout\n";
    t1.join();
}


// C++ program to illustrate std::cerr

#include <iostream>
using namespace std;

// Driver Code
int main()
{

    // This will print "Welcome to GfG"
    // in the error window
    cerr << "Welcome to GfG! :: cerr";

    // This will print "Welcome to GfG"
    // in the output window
    cout << "Welcome to GfG! :: cout";
    return 0;
}



// Programa C++ para mostrar
// el uso de std::cerr
#include <iostream>


// Driver code
int main()
{
    std::cerr << "El mensaje mostrado no está almacenado en el buffer";
    return 0;
}



// Programa C++ para mostrar
// el uso de std::clog
#include <iostream>


// Driver code
int main()
{
    std::clog << "El mensaje mostrado está almacenado en el buffer";
    return 0;
}





#include <iostream>
int main()
{
    char ch;
    std::cout << "Escribe un texto: ";
    while (std::cin >> ch)
        std::cout << ch;

    return 0;
}



#include <iostream>
int main()
{
    char ch;
    std::cout << "Escribe un texto: ";
    while (std::cin.get(ch))
        std::cout << ch;

    return 0;
}





#include <iostream>
int main()
{
    char strBuf[11];
    std::cout << "Escribe un texto: ";
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    return 0;
}



#include <iostream>
int main()
{
    char strBuf[11];
    std::cout << "Escribe un texto: ";
    // Lee hasta 10 caracteres
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    // Lee 10 caracteres más
    std::cout << "Escribe otro texto: ";
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';
    return 0;
}




#include <iostream>
int main()
{
    char strBuf[11];
    std::cout << "Escribe un texto: ";
    // Lee hasta 10 caracteres
    std::cin.getline(strBuf, 11);
    std::cout << strBuf << '\n';

    std::cout << "Escribe un texto: ";
    // Lee hasta 10 caracteres
    std::cin.getline(strBuf, 11);
    std::cout << strBuf << '\n';
    return 0;
}




#include <iostream>
int main()
{
    std::cout << "Escribe un texto: ";
    char strBuf[100];
    std::cin.getline(strBuf, 100);
    std::cout << strBuf << '\n';
    std::cout << std::cin.gcount() << " caracteres pasados" << '\n';

    return 0;
}
#endif




#include <string>
#include <iostream>

int main()
{
    std::cout << "Escribe un texto: ";
    std::string strBuf;
    std::getline(std::cin, strBuf);
    std::cout << strBuf << '\n';

    return 0;
}



#if 0
#include <string>
#include <iostream>

int main()
{
    std::string strBuf;
    std::getline(std::cin, strBuf);
    std::cout << strBuf << '\n';

    return 0;
}




#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;
int main() {
    int x;
    char str[80];
    cout << "Enter a number and a string:";
        cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), ' '); //clear buffer before taking new  line
        cin.getline(str, 80); //take a string
    cout << "You have entered: ";
        cout << x << endl;
    cout << str << endl;
}


#include<iostream>
int main()
{
    char buf[10];
    std::cin >> buf;
    std::cout << buf;
}

#include<iostream>
#include <iomanip>
int main()
{
    char buf[10];   
    std::cout << "escribe un texto: ";
    std::cin >> std::setw(10) >> buf;
    std::cout << buf;
    

}
#endif