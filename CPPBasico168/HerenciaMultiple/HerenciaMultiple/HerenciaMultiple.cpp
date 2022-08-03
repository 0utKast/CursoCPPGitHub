#if 0
#include <string>
#include <iostream>

class Personaje
{
private:
    std::string m_nombre;
    int m_edad{};

public:
    Personaje(const std::string& nombre, int edad)
        : m_nombre{ nombre }, m_edad{ edad }
    {
    }

    const std::string& getNombre() const { return m_nombre; }
    int getEdad() const { return m_edad; }
};

class Sanador
{
private:
    std::string m_anillo;
    double m_potenciaHechizo{};

public:
    Sanador(const std::string& anillo, double potenciaHechizo)
        : m_anillo{ anillo }, m_potenciaHechizo{ potenciaHechizo }
    {
    }

    const std::string& getAnillo() const { return m_anillo; }
    double getPotenciaHechizo() const { return m_potenciaHechizo; }
};

// Altmer hereda públicamente Personaje y Sanador
class Altmer : public Personaje, public Sanador
{
private:
    int m_nivel{};

public:
    Altmer(const std::string& nombre, int edad, std::string anillo, double potenciaHechizo, int nivel)
        : Personaje{ nombre, edad }, Sanador{ anillo, potenciaHechizo }, m_nivel{ nivel }
    {
    }
};

int main()
{
    Altmer litman{ "Litman Elsiniath", 235, "Anillo de Mara", 14.3, 8 };
    std::cout << litman.getNombre(); 

    return 0;
}




#include <string>

struct Localizacion
{
    int x;
    int y;
};

class Caja // clase mixin Caja 
{
public:
    void setSupIzq(Localizacion punto) { m_supIzq = punto; }
    void setInferDer(Localizacion punto) { m_inferDer = punto; }
private:
    Localizacion m_supIzq{};
    Localizacion m_inferDer{};
};

class Etiqueta // clase mixin Etiqueta
{
public:
    void setTexto(const std::string_view str) { m_texto = str; }
    void setFuenteTam(int fuenteTam) { m_fuenteTam = fuenteTam; }
private:
    std::string m_texto{};
    int m_fuenteTam{};
};

class Pie : public Caja, public Etiqueta {};

int main()
{
    Pie pie{};
    pie.Caja::setSupIzq({ 1, 1 });
    pie.Caja::setInferDer({ 10, 10 });
    pie.Etiqueta::setTexto("Usuario: ");
    pie.Etiqueta::setFuenteTam(6);
}




// El Curiously Recurring Template Pattern (CRTP)
template <class T>
class Mixin
{
    // Mixin<T> puede usar el parámetro tipo plantilla T para acceder a miembros de Derivada
    // via (static_cast<T*>(this))
};

class Derivada : public Mixin<Derivada>
{
};

#endif








#include <iostream>

template <typename Derivada>
class Mixin {
public:
    void nombre() 
    { 
        (static_cast<Derivada*>(this))->impl(); 
    } 
};

class Derivada1 : public Mixin<Derivada1> 
{
public:
    void impl() 
    {
        std::cout << "Derivada1::impl()\n"; 
    } 
};
class Derivada2 : public Mixin<Derivada2> 
{
public:
    void impl() 
    { 
        std::cout << "Derivada2::impl()\n"; 
    } 
};

class Fandango : public Mixin<Fandango>
{
public:
    void impl()
    {
        std::cout << "Fandango::impl()\n";
    }
};

int main()
{
    Mixin<Derivada1> mixin1; 
    mixin1.nombre();
    Mixin<Derivada2> mixin2; 
    mixin2.nombre();
	Mixin<Fandango> mixin3;
	mixin3.nombre();

    Derivada1 derivada1; 
    derivada1.nombre();
    Derivada2 derivada2; 
    derivada2.nombre();
	Fandango fandango;
	fandango.nombre();
}




#if 0
#endif