
#include <iostream>
#include <string>
class MiString
{
public:
	MiString(std::string)
	{
		
	}
};
	

int main()
{
	int x{ 2 };
	int y{ 3 };
	std::cout << x + y << '\n';

	double z{ 2.0 };
	double w{ 3.0 };
	std::cout << w + z << '\n';

	MiString string1{ "Hello, " };
	MiString string2{ "World!" };
	//std::cout << string1 + string2 << '\n';
}


#include <iostream>
#include <string>
class MiString
{
public:
	MiString(std::string)
	{

	}
};


int main()
{
	
	MiString string1{ "Hola, " };
	MiString string2{ "Mundo" };
	std::cout << string1 + string2 << '\n';
}






#if 0

double operator+ (double w, double z){....}


















