#if 0
#include <fstream>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    // ofstream es usado para escribir desde archivos
    // crearemos un archivo llamado Ejemplo.txt    
    std::ofstream outf{ "Ejemplo.txt" };
    
    //std::ofstream outf{ "C:/Users/educa/Documents/Ejemplo.txt" };



    // Si no podemos abrir el archivo del stream ouput para escribir
    if (!outf)
    {
        // Imprimimos en consola un error y salimos
        std::cerr << "No se ha podido abrir Ejemplo.txt para escribir\n";
        return 1;
    }

    // Escribimos dos líneas en este archivo
    outf << "Esta es la primera línea modificada\n";
    outf << "Esta es la segunda línea modificada\n";

    return 0;

    // Cuando outf sale de alcance, el destructor
    // de ofstream cerrará el archivo
}



#include <fstream>
#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    // ifstream es usado para leer archivos
    // Leeremos desde un archivo llamado Ejemplo.txt
    std::ifstream inf{ "Ejemplo.txt" };

    // Si no podemos abrir el archivo del stream input para leer
    if (!inf)
    {
        // Imprimimos un error y salimos
        std::cerr << "No se ha podido abrir Ejemplo.txt para lectura\n";
        return 1;
    }

    // Mientras todavía quede algo que leer
    while (inf)
    {
        // lee lo que se encuentra dentro del archivo como un string e imprímelo
        std::string strInput;
        inf >> strInput;
        std::cout << strInput << '\n';
    }

    return 0;

    // Cuando inf sale de alcance, el destructor
    // de ifstream cerrará el archivo
}




#include <fstream>
#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    // ifstream es usado para leer archivos
   // Leeremos desde un archivo llamado Ejemplo.txt
    std::ifstream inf{ "Ejemplo.txt" };

    // Si no podemos abrir el archivo del stream input para leer
    if (!inf)
    {
        // Imprimimos un error y salimos
        std::cerr << "No se ha podido abrir Ejemplo.txt para lectura\n";
        return 1;
    }

    // Mientras todavía quede algo que leer
    while (inf)
    {
        // lee lo que se encuentra dentro del archivo como un string e imprímelo
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    }

    return 0;

    // Cuando inf sale de alcance, el destructor
    // de ifstream cerrará el archivo
}




#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    // pasaremos el flag ios:app para decir a ofstream que añada
    // en lugar de reescribir el archivo. No necesitamos pasarle std::ios::out
    // porque ofstream está predeterminado a std::ios::out
    std::ofstream outf{ "Ejemplo.txt", std::ios::app };

    // Si no podemos abrir el archivo output para escribir
    if (!outf)
    {
        // imprime un error y sale
        std::cerr << "No se ha podido abrir Ejemplo.txt para escribir\n";
        return 1;
    }

    outf << "Esta es la tercera línea\n";
    outf << "Esta es la cuarta línea\n";

    return 0;

    // Cuando outf sale de alcance, el destructor
    // de ofstream cerrará el archivo
}
#endif



#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");

std::ofstream outf{ "otroArchivo.txt" };
outf << "Esta es la línea 1\n";
outf << "Esta es la línea 2\n";
outf.close(); // explícitamente cierra el archivo

// Olvidamos algo, así que abrimos el archivo de nuevo
outf.open("otroArchivo.txt", std::ios::app);
outf << "Esta es la línea 3\n";
outf.close();
}


#if 0
#include <iostream>

// Define la función factorial
int fact(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}

int main() {
    std::cout << "Enter a number:" << std::endl;
    int a;
    std::cin >> a;  // Leer un número

    std::cout << fact(a) << std::endl;

    return 0;
}

#endif