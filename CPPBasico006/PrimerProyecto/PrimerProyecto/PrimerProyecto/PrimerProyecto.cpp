#include <iostream>  // for std::cout and std::cin

int main()
{
	
	setlocale(LC_ALL, "es-ES");
	std::cout << "Escribe un n�mero: "; // Se le pide al usuario que escriba un n�mero
	int x{ }; // definimos variable x para que almacene entrada del usuario y lo inicializamos a cero, o vac�o como ya sabemos.
	std::cin >> x; // Obtenemos un n�mero desde el teclado y lo almacenamos en la variable x
	std::cout << "Has escrito:  " << x << '\n'; //Lo mostramos en la consola. El saldo de l�nea no es t�cnicamente necesario. 
	return 0;
	
}




























/*#include <iostream> // Para poder acceder a std::cout

int main()
{
	std::cout << "Hola Mundo. \n";
	std::cout << "Estamos despegando" ;
	return 0;
}*/

















/*#include <iostream>

int main()
{
	int x{ 5 }; //define variable x de tipo integer, la inicializa con valor 5
	std::cout << "x es igual a: " << x; //imprime el valor de x (5) en la consola
	return 0;
}*/













