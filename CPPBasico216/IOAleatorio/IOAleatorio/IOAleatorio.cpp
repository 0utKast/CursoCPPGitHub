#if 0
#include <fstream>

int main()
{
    std::setlocale(LC_ALL, "es_ES.UTF-8");

    std::ifstream inf{ "Ejemplo.txt" };

    inf.seekg(14, std::ios::cur); // Mueve puntero hacia adelante 14 bytes desde la posición actual 
    inf.seekg(-18, std::ios::cur); // Mueve puntero hacia atrás 18 bytes desde la posición actual 
    inf.seekg(22, std::ios::beg); // Mueve puntero al byte 22 en el archivo 
    inf.seekg(24); // Mueve puntero al byte 24 en el archivo 
    inf.seekg(-28, std::ios::end); // mueve puntero al byte 28 contando desde el final del archivo
    return 0;
}


#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::setlocale(LC_ALL, "es_ES.UTF-8");
    std::ifstream inf{ "Ejemplo.txt" };
    //std::ifstream inf("Ejemplo.txt", std::ifstream::binary);

    // Si no podemos abrir el archivo input stream para lectura
    if (!inf)
    {
        // imprime un error y sale
        std::cerr << "El archivo Ejemplo.txt no ha podido ser abierto para lectura\n";
        return 1;
    }

    std::string strData;

    inf.seekg(5); // se mueve al quinto carácter
    // Obtiene el resto de la línea y lo imprime, se mueve a la línea 2
    std::getline(inf, strData);
    std::cout << strData << '\n';

    inf.seekg(8, std::ios::cur); // Se mueve 8 bytes en el archivo
    // Obtiene el resto de la línea y lo imprime y se mueve a la línea 3
    std::getline(inf, strData);
    std::cout << strData << '\n';

    inf.seekg(-14, std::ios::end); // Se mueve 14 bytes desde el final del archivo
    // Obtiene el resto de la línea y lo imprime
    std::getline(inf, strData);
    std::cout << strData << '\n';

    return 0;
}



#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::setlocale(LC_ALL, "es_ES.UTF-8");
    std::ifstream inf{ "Ejemplo.txt" };    

    // Si no podemos abrir el archivo input stream para lectura
    if (!inf)
    {
        // imprime un error y sale
        std::cerr << "El archivo Ejemplo.txt no ha podido ser abierto para lectura\n";
        return 1;
    }
  
    inf.seekg(0, std::ios::end); // se mueve al final del archivo
    std::cout << inf.tellg();   

    return 0;
}





#include <fstream>
#include <iostream>
#include <string>

using namespace std;



int main() {

    std::setlocale(LC_ALL, "es_ES.UTF-8");

    // Creamos un objeto de fstream para crear el archivo
    fstream file;
    // Creamos el archivo en modo escritura
    file.open("mi_archivo.txt", ios::out);

    // Comprobamos si el archivo se ha creado correctamente
    if (!file.is_open()) {
        cerr << "Error al crear el archivo" << endl;
        return 1;
    }

    // Añadimos tres líneas al archivo
    file << "Esta es la primera línea del archivo" << endl;
    file << "Esta es la segunda línea del archivo" << endl;
    file << "Esta es la tercera línea del archivo" << endl;

    // Cerramos el archivo
    file.close();


    // Creamos un objeto de fstream para abrir el archivo
    fstream ifile;
    // Abrimos el archivo en modo lectura
    ifile.open("mi_archivo.txt", ios::in);

    // Comprobamos si el archivo se ha abierto correctamente
    if (!ifile.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    // Creamos una cadena para almacenar cada línea del archivo
    string line;

    // Mientras no hayamos llegado al final del archivo
    while (getline(ifile, line)) {
        // Recorremos la línea carácter por carácter
        for (char& c : line) {
            // Si el carácter es una vocal, lo reemplazamos por #
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'í') {
                c = '#';
            }
        }

        // Mostramos la línea modificada por pantalla
        cout << line << endl;
    }

    // Cerramos el archivo
    ifile.close();

    return 0;
}


#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::setlocale(LC_ALL, "es_ES.UTF-8");
    // Observa que especificamos tanto in como out porque usamos fstream
    std::fstream iofile{ "Ejemplo.txt", std::ios::in | std::ios::out };

    // Si no se puede abrir iofile, se imprime un error
    if (!iofile)
    {
        // Imprime un error y sale
        std::cerr << "Ejemplo.txt no ha podido abrirse\n";
        return 1;
    }

    char chChar{}; // vamos hacer esto carácter a carácter
    

    // Mientras siga habiendo datos que procesar
    while (iofile.get(chChar))
    {
        switch (chChar)
        {
           
            // Si encontramos una vocal
        case 'a':
        case 'e':
        case 'i':
        case 'í':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':

            // Nos movemos atrás 1 carácter
            iofile.seekg(-1, std::ios::cur);

            // Como hicimos un seek, podemos hacer ahora un write seguro,
            // escribimos una # almohadilla sobre la vocal
            iofile << '#';

            // Ahora queremos volver al modo lectura para buscar la siguiente vocal
            // Para que get() se ejecute correctamente. Hacemos seekg( ) a current
            // Permite cambiar de escritura a lectura sin mover el puntero del archivo.
            iofile.seekg(iofile.tellg(), std::ios::beg);

            break;
        }
    }

    return 0;
}



#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    // Asumimos que el archivo "mi_archivo.txt" ya existe

    // Borramos el archivo "mi_archivo.txt"
    if (remove("mi_archivo.txt") != 0)
        cout << "Error al borrar el archivo" << endl;
    else
        cout << "El archivo fue borrado exitosamente" << endl;

    return 0;
}

#endif

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Creamos un stream de archivo para escribir
    ofstream archivo("mi_archivo.txt");

    // Verificamos si el stream está abierto
    if (archivo.is_open())
        cout << "El stream de archivo está abierto" << endl;
    else
        cout << "El stream de archivo está cerrado" << endl;

    // Cerramos el stream de archivo
    archivo.close();

    return 0;
}
