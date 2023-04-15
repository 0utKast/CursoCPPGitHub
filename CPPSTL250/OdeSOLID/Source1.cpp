


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




