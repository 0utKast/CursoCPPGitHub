#if 0
#include <algorithm> // std::min_elemento y std::max_elemento
#include <iostream>
#include <list>
#include <numeric> // std::iota

int main()
{
	std::list<int> li(6);
	// poblamos Fill con números a partir de 0.
	std::iota(li.begin(), li.end(), 0);

	for (auto i : li)
		std::cout << ' ' << i;
	std::cout << '\n';

	std::cout << "El menor valor  de li es: " << *std::min_element(li.begin(), li.end()) << '\n'
		<< "El mayor valor  de li es: " << *std::max_element(li.begin(), li.end()) << '\n';

	return 0;
}






#include <vector>
#include <algorithm>  // std::min_elemento
#include <iostream>

int main()
{
	std::vector<int> v{ 7,9,3,5,3,2,4,1,8,0 };
	//loop for-each muestra vector v
	for (auto i : v)
		std::cout << ' ' << i;
	std::cout << '\n';
	
	// calculamos valor menor en subrango (como en la imagen):
	auto i = min_element(begin(v) + 2, begin(v) + 7);
	auto min = *i;  // int min = 2
	std::cout << min << '\n'; //imprimimos min = 2
	v.erase(i);
	
	// calculamos valor menor en todo el contenedor:
	auto j = min_element(begin(v), end(v));
	std::cout << *j << '\n';  // imprime '0'
	
	v.erase(j);  // elimina el valor más pequeño
	
	//imprimimos el vector tras haber eliminado el valor más pequeño.
	for (auto c : v)
		std::cout << ' ' << c;
	std::cout << '\n';

}


#endif


#if 0

#include <vector>
#include <algorithm>  // std::min_elemento
#include <iostream>

int main()
{
	std::vector<int> v{ 7,9,3,5,3,2,4,1,8,0 };
	//loop for-each muestra vector v
	for (auto i : v)
		std::cout << ' ' << i;
	std::cout << '\n';

	// calculamos valor menor en subrango (como en la imagen):
	auto i = min_element(begin(v) + 2, end(v) - 2);
	auto min = *i;  // int min = 2
	std::cout << min << '\n'; //imprimimos min = 2

	// calculamos valor menor en todo el contenedor:
	auto j = min_element(begin(v), end(v));
	std::cout << *j << '\n';  // imprime '0'
	v.erase(j);  // elimina el valor más pequeño

	//imprimimos el vector tras haber eliminado el valor más pequeño.
	for (auto i : v)
		std::cout << ' ' << i;
	std::cout << '\n';

}
#endif

#include <vector>
#include <algorithm>  // std::min_elemento
#include <iostream>
int main()
{

	std::vector<int> in1{ 0,2,4,6,7 };
	std::vector<int> in2{ 1,3,5,8 };
	// make sure output can fit all elements
	std::vector<int> out;
	out.resize(in1.size() + in2.size());
	merge(begin(in1), end(in1), begin(in2), end(in2), begin(out));
	for (int x : out) { std::cout << x << ' '; }  // 0 1 2 3 4 5 6 7 8

}


















#if 0
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
int main() {
	std::map<std::string, int> ContadorMapaMundo;
	// Insert Element in map
	ContadorMapaMundo.insert(std::pair<std::string, int>("primero", 1));
	ContadorMapaMundo.insert(std::pair<std::string, int>("segundo", 2));
	ContadorMapaMundo.insert(std::pair<std::string, int>("tercero", 3));
	ContadorMapaMundo.insert(std::pair<std::string, int>("tercero", 4));
	ContadorMapaMundo.insert(std::pair<std::string, int>("tercero", 5));
	// Creamos un iterator map y apuntamos al principio del map
	std::map<std::string, int>::iterator it = ContadorMapaMundo.begin();
	// Nos iteramos por el map usando el loop for basado en rangos desde c++11
	for (std::pair<std::string, int> elemento : ContadorMapaMundo) {
		// Accedemos a CLAVE desde elemento
		std::string word = elemento.first;
		// Accedemos a VALOR desde elemento.
		int count = elemento.second;
		std::cout << word << " :: " << count << std::endl;
	}
	return 0;
}
#endif
#if 0
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
int main() {
	std::map<std::string, int> contadorMapaMundo;
	// Insertar Elemento en map
	contadorMapaMundo.insert(std::pair<std::string, int>("primero", 1));
	contadorMapaMundo.insert(std::pair<std::string, int>("segundo", 2));
	contadorMapaMundo.insert(std::pair<std::string, int>("tercero", 3));
	contadorMapaMundo.insert(std::pair<std::string, int>("tercero", 4));
	contadorMapaMundo.insert(std::pair<std::string, int>("tercero", 5));
	// Creatr un iterator map y apuntar al principio del map
	std::map<std::string, int>::iterator it = contadorMapaMundo.begin();
	// Iterarse sobre el map usando iterator hasta el final.
	while (it != contadorMapaMundo.end())
	{
		// Acceder a CLAVE desde el elemento apuntado.
		std::string word = it->first;
		// Acceder a VALOR desde el elemento apuntado.
		int count = it->second;
		std::cout << word << " :: " << count << std::endl;
		// Incrementar el Iterator para apuntar a la siguiente entrada
		it++;
	}
	return 0;
}




#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
int main() {
	std::map<std::string, int> contadorMapaMundo;
	// Insertar Elemento en map
	contadorMapaMundo.insert(std::make_pair("primero", 1));
	contadorMapaMundo.insert(std::make_pair("segundo", 2));
	contadorMapaMundo.insert(std::make_pair("tercero", 3));
	contadorMapaMundo.insert(std::make_pair("tercero", 4));
	contadorMapaMundo.insert(std::make_pair("tercero", 5));
	// Creatr un iterator map y apuntar al principio del map
	std::map<std::string, int>::iterator it = contadorMapaMundo.begin();
	// Iterarse sobre el map usando iterator hasta el final.
	while (it != contadorMapaMundo.end())
	{
		// Acceder a CLAVE desde el elemento apuntado.
		std::string word = it->first;
		// Acceder a VALOR desde el elemento apuntado.
		int count = it->second;
		std::cout << word << " :: " << count << std::endl;
		// Incrementar el Iterator para apuntar a la siguiente entrada
		it++;
	}
	return 0;
}

#endif


