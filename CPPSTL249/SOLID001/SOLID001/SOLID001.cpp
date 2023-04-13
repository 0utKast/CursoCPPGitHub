
#if 0
// Incorrecto: La clase "Alumno" realiza dos tareas diferentes.
class Alumno {
public:
    void datosAlumno() {/*...*/ }
    void calcularNotaAlumno() {/*...*/ }
};

// Correcto: Separamos las responsabilidades en dos clases distintas.
class Alumno {
public:
    void datosAlumno() {/*...*/ }
};

class notasAlumnos {
public:
    void calcularNota(Alumno alumno) {/*...*/ }
};






#include <iostream>
#include <string>
#include <vector>

class Alumno {
private:
    std::string nombre;
    int edad;
    std::vector<double> notas;

public:
    Alumno(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

    void setNombre(std::string nuevoNombre) {
        nombre = nuevoNombre;
    }

    std::string getNombre() {
        return nombre;
    }

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;
    }

    int getEdad() {
        return edad;
    }

    void agregarNota(double nota) {
        notas.push_back(nota);
    }

    double calcularPromedio() {
        double suma = 0;
        for (double nota : notas) {
            suma += nota;
        }
        return suma / notas.size();
    }

    void imprimirInformacion() {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", Promedio: " << calcularPromedio() << std::endl;
    }
};

int main() {
    Alumno alumno("Juan Perez", 20);
    alumno.agregarNota(9.0);
    alumno.agregarNota(8.5);
    alumno.agregarNota(7.0);

    alumno.imprimirInformacion(); // Salida: Nombre: Juan Perez, Edad: 20, Promedio: 8.16667

    return 0;
}

#endif


#include <iostream>
#include <string>
#include <vector>

class DatosPersonales {
private:
    std::string nombre;
    int edad;

public:
    DatosPersonales(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

    void setNombre(std::string nuevoNombre) {
        nombre = nuevoNombre;
    }

    std::string getNombre() {
        return nombre;
    }

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;
    }

    int getEdad() {
        return edad;
    }
};

class GestorNotas {
private:
    std::vector<double> notas;

public:
    void agregarNota(double nota) {
        notas.push_back(nota);
    }

    double calcularPromedio() {
        double suma = 0;
        for (double nota : notas) {
            suma += nota;
        }
        return suma / notas.size();
    }
};

int main() {
    DatosPersonales datosPersonales("Juan Perez", 20);
    GestorNotas gestorNotas;
    gestorNotas.agregarNota(9.0);
    gestorNotas.agregarNota(8.5);
    gestorNotas.agregarNota(7.0);

    std::cout << "Nombre: " << datosPersonales.getNombre() << ", Edad: " << datosPersonales.getEdad() << ", Promedio: " 
        << gestorNotas.calcularPromedio() << std::endl; // Salida: Nombre: Juan Perez, Edad: 20, Promedio: 8.16667

    return 0;
}




#if 0
#endif