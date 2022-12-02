#if 0

#include <iostream>

int main()
{
    std::cout << "Escribe tu edad: ";
    int edad{};
    std::cin >> edad;
    std::cout << edad;
}


#include <algorithm> // std::all_of
#include <cctype> // std::isalpha, std::isspace
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>

bool esNombreValido(std::string_view nombre)
{
    return std::ranges::all_of(nombre, [](char ch) {
        return (std::isalpha(ch) || std::isspace(ch));
        });

    // Antes C++20, sin rangos
    // return std::all_of(nombre.begin(), nombre.end(), [](char ch) {
    //    return (std::isalpha(ch) || std::isspace(ch));
    // });
}

int main()
{
    std::string nombre{};

    do
    {
        std::cout << "Escribe tu nombre: ";
        std::getline(std::cin, nombre); // obtenemos la línea entera, incluidos espacios
    } while (!esNombreValido(nombre));

    std::cout << "Hola " << nombre << "\n";
}








#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>

bool contieneCaracteresNombreInvalidos(std::string_view input) {
	return !std::ranges::all_of(
		input,
		[](char x) { return std::isalpha(x) || std::isspace(x); }
	);
}

auto cuentaEspacios(std::string_view input) {
	return std::ranges::count_if(
		input,
		[](char x) { return std::isspace(x); }
	);
}

bool nombreInvalido(std::string_view input) {
	return (input.length() < 2) // Nuevo
		|| (contieneCaracteresNombreInvalidos(input))
		|| (cuentaEspacios(input) > 1); // Nuevo
}

int main() {
	std::string input{};

	do
	{
		std::cout << "Escribe tu nombre: ";

		std::getline(std::cin, input);
	} while (nombreInvalido(input));

	std::cout << "Hola " << input << "!\n";
}
#endif


#include <algorithm> // std::equal
#include <cctype> // std::isdigit, std::isspace, std::isalpha
#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <string_view>

bool entradaCoincide(std::string_view input, std::string_view modelo)
{
    if (input.length() != modelo.length())
    {
        return false;
    }

    // Esta tabla define todos los símbolos especiales que pueden coincidir con un rango de entrada del usuario
    // Cada símbolo se asigna a una función que determina si la entrada es válida para ese símbolo    
    static const std::map<char, int (*)(int)> validadores{
      { '#', &std::isdigit },
      { '_', &std::isspace },
      { '@', &std::isalpha },
      { '?', [](int) { return 1; } }
    };

    // Antes de C++20, usar
    // return std::equal(input.begin(), input.end(), modelo.begin(), [](char ch, char mascara) -> bool {
    // ...

    return std::ranges::equal(input, modelo, [](char ch, char mascara) -> bool {
        if (auto encontrado{ validadores.find(mascara) }; encontrado != validadores.end())
        {
            // El elemento actual del modelo se encontró en los validadores. 
            // Llama a la función correspondiente.
            return (*encontrado->second)(ch);
        }
        else
        {
            // No se encontró el elemento actual del modelo en los validadores.
           // los caracteres tienen que ser una coincidencia exacta.
            return (ch == mascara);
        }
        });
}

int main()
{
    setlocale(LC_ALL, "es_ES");
    std::string numeroTelefono{};

    do
    {
        std::cout << "Escribe un número de teléfono (###) ###-####: ";
        std::getline(std::cin, numeroTelefono);
    } while (!entradaCoincide(numeroTelefono, "(###) ###-####"));

    std::cout << "Has escrito: " << numeroTelefono << '\n';
}


#if 0
#endif







