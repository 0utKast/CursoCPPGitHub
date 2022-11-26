#if 0
#include<iostream>
#include<vector>
using namespace std;
int main() {

    int num;
    char name[20];

    cout << "Enter your Roll Number and Name:\n";
    cin >> num;

    cin.getline(name, 20); // getline() take a string as input

    cout << "Your Details are:\n";
    cout << num << endl;
    cout << name << endl;

    return 0;
}


#include<iostream>
#include<ios> //for stream size
#include<limits> //for numeric limits
using namespace std;
int main() {

    int num;
    char name[20];

    cout << "Enter your Roll Number and Name:\n";
    cin >> num;

    //It will clear the buffer before taking the new input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cin.getline(name, 20);

    cout << "Your Details are:\n";
    cout << num << endl;
    cout << name << endl;

    return 0;
}


#include<iostream>
using namespace std;
int main()
{
    int x;
    char c[50];
    // input a number from user
    cin >> x;

    // input a char array
    cin.getline(c, 50);

    // prints the number
    cout << x << endl;

    // does not print the string
    cout << c << endl;
}


#include<iostream>
#include<limits>
using namespace std;
int main()
{
    int x;
    char c[50];
    // input a number from user
    cin >> x;

    // removes the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // input a char array
    cin.getline(c, 50);
    // prints the number
    cout << x << endl;
    // prints the string
    cout << c << endl;
}


#include<iostream>

int main() {

   
    char Str[100];
    char Ostr[50];   

    std::cout << "Escribe  Tu nombre:\n";
  
    std::cin.getline(Ostr, 50); //toma un string

    std::cout << "Escribe  Tus apellidos:\n";
    std::cin.getline(Str, 100); //toma un string

    std::cout << "Nombre :" << Ostr<< ", Apellidos: " << Str << std::endl;

    

}




#include<iostream>

int main() {

    int num;   

    char Str[100];

    std::cout << "Escribe tu edad:\n";
    std::cin >> num;

    std::cout << "Escribe tu nombre:\n";
    
    std::cin.getline(Str, 100); //toma un string

    std::cout << "Edad :" << num << ", Nombre: " << Str << std::endl;

}


#include<iostream>


int main() {

    int num;

    char Str[100];

    std::cout << "Escribe tu edad:\n";

    std::cin >> num; //debemos limpiar el buffer antes de tomar la nueva línea
   
    std::cin.ignore();

    std::cout << "Escribe tu nombre:\n";

    std::cin.getline(Str, 100); //toma un string.

    std::cout << "Edad :" << num << ", Nombre: " << Str << std::endl;

}







#include<iostream>


int main() {

    int num;

    char Str[100];

    std::cout << "Escribe tu edad:\n";

    std::cin >> num; //debemos limpiar el buffer antes de tomar la nueva línea

    std:: cin.ignore(std::numeric_limits<std:: streamsize>::max(), '\n');    

    std::cout << "Escribe tu nombre:\n";

    std::cin.getline(Str, 100); //toma un string.

    std::cout << "Edad :" << num << ", Nombre: " << Str << std::endl;

}





#include <sstream>
#include <iostream>
int main()
{
    std::istringstream s1("Hola Mundo.");
    char c1 = s1.peek();
    char c2 = s1.get();
    std::cout << "Visto: " << c1 << " Tomado: " << c2 << '\n';
    char c3 = s1.peek();
    char c4 = s1.get();
    std::cout << "Visto: " << c3 << " Tomado: " << c4 << '\n';

}







// C++ código para basic_istream::unget()
#include <sstream>
#include <iostream>

// Driver code
int main()
{
    // Declare string stream
    std::istringstream gfg("Hola Mundo");

    char a = gfg.get();    
    char c1 = gfg.peek();
    std::cout << "obtenemos: " << c1 <<std::endl;    
    gfg.unget();
    char c2 = gfg.peek();
    std::cout << "obtenemos: " << c2 << std::endl;  

    return 0;
}



#include <iostream>
#include <sstream>

int main()
{
    std::stringstream s1("Hola Mundo"); // IO stream
    s1.get();
    s1.putback('Y'); // modifica el buffer
    std::cout << s1.rdbuf() << '\n';  
    
}



#include <iostream>
int main()
{
    std::cout.setf(std::ios::showpos); // activa el flag std::ios::showpos
    std::cout << 27 << '\n';
}






#include <iostream>
int main()
{
    std::cout.setf(std::ios::showpos | std::ios::uppercase); // activa los flags std::ios::showpos y std::ios::uppercase
    std::cout << 1234567.89f << '\n';
}


#include <iostream>
int main()
{
    std::cout.setf(std::ios::showpos); // activa el flag std::ios::showpos
    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos); // desactiva el flag std::ios::showpos
    std::cout << 28 << '\n';
}



#include <iostream>
int main()
{
    std::cout.setf(std::ios::hex); // intenta activar output hex
    std::cout << 27 << '\n';
}





#include <iostream>
int main()
{
    std::cout.unsetf(std::ios::dec); // desactiva decimal output
    std::cout.setf(std::ios::hex); // activa hexadecimal output
    std::cout << 27 << '\n';
}





#include <iostream>
int main()
{
    // activa std::ios::hex como el único flag std::ios::basefield
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';
}
#endif





#include <iostream>
int main()
{
    std::cout << std::hex << 27 << '\n'; // imprime 27 en hex
    std::cout << 28 << '\n'; // seguimos con hex
    std::cout << std::dec << 29 << '\n'; // vuelta a decimal
}





#if 0
#endif