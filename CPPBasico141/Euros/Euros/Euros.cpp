#include "Euros.h"

// nota: esta función no es una función miembro ni una función amiga
Euros operator+(const Euros& c1, const Euros& c2)
{
	// usa el constructor Euros y operator+(int, int)
	// no necesitamos acceso directo a miembros privados aquí
	return { c1.getEuros() + c2.getEuros() };
}