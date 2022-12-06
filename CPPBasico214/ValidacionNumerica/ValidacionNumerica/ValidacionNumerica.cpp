#if 0

#include <iostream>
#include <limits>

int main()
{
    int edad{};

    while (true)
    {
        std::cout << "Escribe tu edad: ";
        std::cin >> edad;

        if (std::cin.fail()) // Si no se produce la extracción
        {
            std::cin.clear(); // restablece el bitstate del stream a goodbit para poder usar ignore()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiamos el mal input desde el stream
            continue; // prueba de nuevo
        }

        if (edad <= 0) // comprueba que la edad es positiva
            continue;

        break;
    }

    std::cout << "Has escrito: " << edad << '\n';
}








#include <iostream>
#include <limits>

int main()
{
    int edad{};

    while (true)
    {
        std::cout << "Escribe tu edad: ";
        std::cin >> edad;

        if (std::cin.fail()) // si no se produce la extracción
        {
            std::cin.clear(); // restablece el bitstate del stream a goodbit para poder usar ignore()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiamos el mal input desde el stream
            continue; // prueba de nuevo
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiamos el mal input desde el stream

        if (edad <= 0) // comprueba que la edad es positiva
            continue;

        break;
    }

    std::cout << "Has escrito: " << edad << '\n';
}






#include <iostream>
#include <limits>

int main()
{
    int edad{};

    while (true)
    {
        std::cout << "Escribe tu edad: ";
        std::cin >> edad;

        if (std::cin.fail()) // si no se produce la extracción
        {
            std::cin.clear(); // restablece el bitstate del stream a goodbit para poder usar ignore()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiamos el mal input desde el stream
            continue; // prueba de nuevo
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiamos cualquier input adicional desde el stream
        if (std::cin.gcount() > 1) // si limpiamos más de un carácter adicional
        {
            continue; // consideraremos este input como inválido
        }

        if (edad <= 0) // comprueba que la edad es positiva
        {
            continue;
        }

        break;
    }

    std::cout << "Has escrito: " << edad << '\n';
}
#endif

#include <charconv> // std::from_chars
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

std::optional<int> extraerEdad(std::string_view edad)
{
    int resultado{};
    auto final{ edad.data() + edad.length() };

    // Intenta analizar un int desde edad
    if (std::from_chars(edad.data(), final, resultado).ptr != final)
    {
        return {};
    }

    if (resultado <= 0) // se asegura que edad es positivo
    {
        return {};
    }

    return resultado;
}

int main()
{
    int edad{};

    while (true)
    {
        std::cout << "Escribe tu edad: ";
        std::string strEdad{};
        std::getline(std::cin >> std::ws, strEdad);

        if (auto extraered{ extraerEdad(strEdad) })
        {
            edad = *extraered;
            break;
        }
    }

    std::cout << "Has escrito: " << edad << '\n';
}




#if 0
#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    // Creamos un objeto de flujo de entrada para abrir un archivo
    std::ifstream input_file("file.txt");

    // Si el archivo no se pudo abrir, establecemos failbit en el objeto de flujo
    if (!input_file) {
        input_file.setstate(std::ios_base::failbit);
    }

    // Intentamos leer una línea del archivo
    std::string line;
    if (!std::getline(input_file, line)) {
        // Si no se pudo leer la línea (por ejemplo, porque el archivo está vacío),
        // establecemos failbit en el objeto de flujo
        input_file.setstate(std::ios_base::failbit);
    }

    // Comprobamos si se ha establecido failbit en el objeto de flujo
    if (input_file.fail()) {
        std::cout << "Error de lectura en el archivo" << std::endl;

        // Limpiamos failbit y cerramos el archivo
        input_file.clear();
        input_file.close();
    }
    else {
        std::cout << "Línea leída del archivo: " << line << std::endl;
    }

    return 0;
}
#endif
