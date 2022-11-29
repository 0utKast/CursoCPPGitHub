#if 0
#include <sstream>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "es_ES.utf-8");
	std::stringstream os1;
	os1 << "String creado con operador de inserción\n"; // configua el buffer stringstream al texto

	std::stringstream os2;
	os2.str("String creado con función str( )\n"); // configua el buffer stringstream al texto

	std::cout << os2.str();
	std::cout << os1.str();	
	
}




#include <sstream>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "es_ES.utf-8");
	std::stringstream os1;
	os1 << "String creado con operador de inserción\n"; 

	std::stringstream os2;
	os2.str("String creado con función str( )\n"); 

	std::string valorStr1;
	std::string valorStr2;

	os1 >> valorStr1;
	os2 >> valorStr2;

	std::cout << valorStr1 << '\n';
	std::cout << valorStr2 << '\n';

}

#endif

#if 0

#include <sstream>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "es_ES.utf-8");
	std::stringstream os1;
	os1 << "String creado con operador de inserción\n"; 

	std::stringstream os2;
	os2.str("String creado con función str( )\n"); 	

	std::string valorStr1;	
	std::string valorStr2;

	while (os1 >> valorStr1) {
		std::cout << valorStr1;
		std::cout << " ";
	}

	std::cout << '\n';

	while (os2 >> valorStr2) {
		std::cout << valorStr2;
		std::cout << " ";
	}	

}


#include <sstream>
#include <iostream>

int main()
{
	std::stringstream os;

	int nValor{ 12345 };
	double dValor{ 67.89 };
	os << nValor << ' ' << dValor;

	std::string strValor1, strValor2;
	os >> strValor1 >> strValor2;

	std::cout << strValor1 << ' ' << strValor2 << '\n';

}



#include <sstream>
#include <iostream>

int main()
{
	std::stringstream os;
	os << "12345 67.89"; 

	int nValor;
	double dValor;

	os >> nValor >> dValor;

	std::cout << nValor << ' ' << dValor << '\n';

	double multiplicar{ dValor * 3.5 };
	int sumar{ nValor + 2 };

	std::cout << multiplicar << '\n';
	std::cout << sumar << '\n';
	
}



#include <sstream>
#include <iostream>

int main()
{

	std::stringstream os;
	os << "Hola ";

	os.str(""); // borra el buffer

	os << "Mundo";
	std::cout << os.str();
}



#include <sstream>
#include <iostream>

int main()
{

	std::stringstream os;
	os << "Hola ";

	os.str(std::string{}); // borra el buffer

	os << "Mundo";
	std::cout << os.str();
}
#endif



#include <sstream>
#include <iostream>

int main()
{
std::stringstream os;
os << "Hola ";

os.str(""); // borra contenido del buffer
os.clear(); // reset error flags

os << "Mundo";
std::cout << os.str();
}


#if 0
#endif
