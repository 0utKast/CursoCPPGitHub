
#if 0
class CalculadoraArea {
public:
    double calcularArea(Rectangulo rectangulo) {/*...*/ }
};





class Figura {
public:
    virtual double calcularArea() = 0;
};


class Rectangulo : public Figura {
public:
    double calcularArea() override {/*...*/ }
};

class Circulo : public Figura {
public:
    double calcularArea() override {/*...*/ }
};




#include <iostream>

class Rectangulo {
public:
    Rectangulo(double ancho, double alto) : ancho_(ancho), alto_(alto) {}

    double area() const {
        return ancho_ * alto_;
    }

private:
    double ancho_;
    double alto_;
};

class CalculadoraArea {
public:
    double calcularArea(const Rectangulo& rectangulo) {
        return rectangulo.area();
    }
};

int main() {
    Rectangulo rectangulo(5, 4);
    CalculadoraArea calculadora;

    std::cout << "Area del rectangulo: " << calculadora.calcularArea(rectangulo) << std::endl;

    return 0;
}

#endif



#if 0

#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

class Figura {
public:
    virtual double calcularArea() const = 0;
};

class Rectangulo : public Figura {
public:
    Rectangulo(double ancho, double alto) : ancho_(ancho), alto_(alto) {}

    double calcularArea() const override {
        return ancho_ * alto_;
    }

private:
    double ancho_;
    double alto_;
};

class Circulo : public Figura {
public:
    explicit Circulo(double radio) : radio_(radio) {}

    double calcularArea() const override {
        return PI * radio_ * radio_;
    }

private:
    double radio_;
};

class CalculadoraArea {
public:
    double calcularArea(const Figura& figura) {
        return figura.calcularArea();
    }
};

int main() {
    Rectangulo rectangulo(5, 4);
    Circulo circulo(3);

    CalculadoraArea calculadora;

    std::cout << "Área del rectángulo: " << calculadora.calcularArea(rectangulo) << std::endl;
    std::cout << "Área del círculo: " << calculadora.calcularArea(circulo) << std::endl;

    return 0;
}





#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

class Figura {
public:
    virtual double calcularArea() const = 0;
};

class Rectangulo : public Figura {
public:
    Rectangulo(double ancho, double alto) : ancho_(ancho), alto_(alto) {}

    double calcularArea() const override {
        return ancho_ * alto_;
    }

private:
    double ancho_;
    double alto_;
};

class Circulo : public Figura {
public:
    explicit Circulo(double radio) : radio_(radio) {}

    double calcularArea() const override {
        return PI * radio_ * radio_;
    }

private:
    double radio_;
};

class Triangulo : public Figura {
public:
    Triangulo(double base, double altura) : base_(base), altura_(altura) {}

    double calcularArea() const override {
        return 0.5 * base_ * altura_;
    }

private:
    double base_;
    double altura_;
};

class CalculadoraArea {
public:
    double calcularArea(const Figura& figura) {
        return figura.calcularArea();
    }
};

int main() {
    Rectangulo rectangulo(5, 4);
    Circulo circulo(3);
    Triangulo triangulo(6, 4);

    CalculadoraArea calculadora;

    std::cout << "Area del rectangulo: " << calculadora.calcularArea(rectangulo) << std::endl;
    std::cout << "Area del circulo: " << calculadora.calcularArea(circulo) << std::endl;
    std::cout << "Area del triangulo: " << calculadora.calcularArea(triangulo) << std::endl;

    return 0;
}
#endif


#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

class Figura {
public:
    virtual double calcularArea() const = 0;
};

class Rectangulo : public Figura {
public:
    Rectangulo(double ancho, double alto) : ancho_(ancho), alto_(alto) {}

    double calcularArea() const override {
        return ancho_ * alto_;
    }

private:
    double ancho_;
    double alto_;
};

class Circulo : public Figura {
public:
    explicit Circulo(double radio) : radio_(radio) {}

    double calcularArea() const override {
        return PI * radio_ * radio_;
    }

private:
    double radio_;
};

class CalculadoraArea {
public:
    double calcularArea(const Figura* figura) {
        return figura->calcularArea();
    }
};

int main() {
    Rectangulo rectangulo(5, 4);
    Circulo circulo(3);

    CalculadoraArea calculadora;

    std::cout << "Área del rectángulo: " << calculadora.calcularArea(&rectangulo) << std::endl;
    std::cout << "Área del círculo: " << calculadora.calcularArea(&circulo) << std::endl;

    return 0;
}
