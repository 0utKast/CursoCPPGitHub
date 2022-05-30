#pragma once

#ifndef EUROS_H
#define EUROS_H

class Euros
{
private:
    int m_euros{};

public:
    Euros(int euros)
        : m_euros{ euros }
    {}

    int getEuros() const { return m_euros; }
};

// Necesario para proveer explícitamente un prototipo para operator+ de modo
//que el uso de operator+ en otros archivos sepa que esta sobrecarga existe
Euros operator+(const Euros& c1, const Euros& c2);

#endif
