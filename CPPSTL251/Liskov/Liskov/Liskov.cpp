#if 0

#include <iostream>

class Animal {
public:
    virtual void desplazar() = 0;
};

class Ave : public Animal {
public:
    void desplazar() override {
        std::cout << "Estoy volando" << std::endl;
    }
};

class Pez : public Animal {
public:
    void desplazar() override {
        std::cout << "Estoy nadando" << std::endl;
    }
};


class Pinguino : public Ave {
public:
    void desplazar() override {
        std::cout << "Estoy nadando" << std::endl;
    }
};










class Rectangulo {
public:
    Rectangulo(int ancho, int alto) : _ancho(ancho), _alto(alto) {}
    void set_ancho(int ancho) { _ancho = ancho; }
    void set_alto(int alto) { _alto = alto; }
    int area() const { return _ancho * _alto; }

protected:
    int _ancho, _alto;
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(int lado) : Rectangulo(lado, lado) {}
    void set_ancho(int ancho) {
        _ancho = _alto = ancho;
    }
    void set_alto(int alto) {
        _ancho = _alto = alto;
    }
};



#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual void hacerRuido() = 0;
};

class Desplazable : public Animal {
public:
    virtual void desplazar() = 0;
};

class AveVoladora : public Desplazable {
public:
    void desplazar() override {
        std::cout << "Estoy volando" << std::endl;
    }
    void hacerRuido() override {
        std::cout << "Canto de ave voladora" << std::endl;
    }
};

class AveNadadora : public Desplazable {
public:
    void desplazar() override {
        std::cout << "Estoy nadando" << std::endl;
    }
    void hacerRuido() override {
        std::cout << "Canto de ave nadadora" << std::endl;
    }
};

class PezNadador : public Desplazable {
public:
    void desplazar() override {
        std::cout << "Estoy nadando" << std::endl;
    }
    void hacerRuido() override {
        std::cout << "Sonido de pez nadador" << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Desplazable>> animalesDesplazables;

    animalesDesplazables.push_back(std::make_unique<AveVoladora>());
    animalesDesplazables.push_back(std::make_unique<AveNadadora>());
    animalesDesplazables.push_back(std::make_unique<PezNadador>());

    for (const auto& animal : animalesDesplazables) {
        animal->hacerRuido();
        animal->desplazar();
        std::cout << std::endl;
    }

    return 0;
}





#include <iostream>

class Figura {
public:
    virtual int area() const = 0;
    virtual int perimetro() const = 0;
};

class Rectangulo : public Figura {
public:
    Rectangulo(int ancho, int alto) : _ancho(ancho), _alto(alto) {}
    int area() const override { return _ancho * _alto; }
    int perimetro() const override { return 2 * (_ancho + _alto); }

private:
    int _ancho, _alto;
};

class Cuadrado : public Figura {
public:
    Cuadrado(int lado) : _lado(lado) {}
    int area() const override { return _lado * _lado; }
    int perimetro() const override { return 4 * _lado; }

private:
    int _lado;
};

int main() {
    setlocale(LC_ALL, "es_ES");
    Rectangulo rectangulo(4, 6);
    Cuadrado cuadrado(5);

    std::cout << "Rect�ngulo:" << std::endl;
    std::cout << "  �rea: " << rectangulo.area() << std::endl;
    std::cout << "  Per�metro: " << rectangulo.perimetro() << std::endl;

    std::cout << "Cuadrado:" << std::endl;
    std::cout << "  �rea: " << cuadrado.area() << std::endl;
    std::cout << "  Per�metro: " << cuadrado.perimetro() << std::endl;

    return 0;
}






class Animal {
public:
    virtual void comer() = 0;
};

class Perro : public Animal {
public:
    void comer() override {
        // Implementaci�n espec�fica para Perro
    }
};

#endif


#if 0

class Vehiculo {
public:
    virtual void mover() = 0;
};

class Coche : public Vehiculo {
public:
    void mover() override {
        // Implementaci�n espec�fica para Coche
    }
};

class Barco : public Vehiculo {
public:
    void mover() override {
        // Implementaci�n espec�fica para Barco
    }
};






class Figura {
public:
    virtual double area() const = 0;
};

class Circulo : public Figura {
public:
    double area() const override {
        // Implementaci�n espec�fica para Circulo
    }
};






class Depositable {
public:
    virtual void depositar(double monto) {
        if (monto > 0) {
            // Realizar el dep�sito
        }
    }
};

class CuentaBancaria : public Depositable {
public:
    void depositar(double monto) override {
        if (monto > 10) { // Debilitamos la precondici�n
            // Realizar el dep�sito
        }
    }
};

#endif


#if 0

class Retirable {
public:
    virtual double retirar(double monto) {
        if (monto > 0) {
            // Realizar el retiro
            return monto;
        }
        return 0;
    }
};



class CuentaEspecial : public Retirable {
public:
    double retirar(double monto) override {
        if (monto > 0) {
            // Realizar el retiro
            return monto + 1; // Fortalecemos la postcondici�n
        }
        return 0;
    }
};



#endif


//C�digo 001
class DispositivoInteligente {
public:
    virtual void encender() = 0;
    virtual void apagar() = 0;
    virtual void ajustarVolumen(int nivel) = 0;
    virtual void ajustarTemperatura(float temperatura) = 0;
};


//C�digo 002

class Televisor : public DispositivoInteligente {
public:
    void encender() override { /* Implementaci�n */ }
    void apagar() override { /* Implementaci�n */ }
    void ajustarVolumen(int nivel) override { /* Implementaci�n */ }
    void ajustarTemperatura(float temperatura) override {
        // No aplicable para Televisor, pero necesitamos implementarla
    }
};

class Termostato : public DispositivoInteligente {
public:
    void encender() override { /* Implementaci�n */ }
    void apagar() override { /* Implementaci�n */ }
    void ajustarVolumen(int nivel) override {
        // No aplicable para Termostato, pero necesitamos implementarla
    }
    void ajustarTemperatura(float temperatura) override { /* Implementaci�n */ }
};

//C�digo 003
class Encendible {
public:
    virtual void encender() = 0;
    virtual void apagar() = 0;
};

class AjustableVolumen {
public:
    virtual void ajustarVolumen(int nivel) = 0;
};

class AjustableTemperatura {
public:
    virtual void ajustarTemperatura(float temperatura) = 0;
};

//C�digo 004
class Televisor : public Encendible, public AjustableVolumen {
public:
    void encender() override { /* Implementaci�n */ }
    void apagar() override { /* Implementaci�n */ }
    void ajustarVolumen(int nivel) override { /* Implementaci�n */ }
};

class Termostato : public Encendible, public AjustableTemperatura {
public:
    void encender() override { /* Implementaci�n */ }
    void apagar() override { /* Implementaci�n */ }
    void ajustarTemperatura(float temperatura) override { /* Implementaci�n */ }
};



