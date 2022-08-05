
#include <iostream>

class DispositivoRemoto
{
private:
    long m_id{};

public:
    DispositivoRemoto(long id)
        : m_id{ id }
    {
    }

    long getID() const { return m_id; }
};

class DispositivoDisco
{
private:
    long m_id{};

public:
    DispositivoDisco(long id)
        : m_id{ id }
    {
    }

    long getID() const { return m_id; }
};

class AdaptadorUniversal : public DispositivoRemoto, public DispositivoDisco
{
public:
    AdaptadorUniversal(long remotoId, long discoId)
        : DispositivoRemoto{ remotoId }, DispositivoDisco{ discoId }
    {
    }
};

int main()
{
    AdaptadorUniversal conexion{ 33543, 21742 };
    std::cout << conexion.getID(); // ¿cuál getID()? Ambiguo
    std::cout << conexion.DispositivoDisco::getID(); // especificamos explícitamente cual usar
	

    return 0;
}
#endif


class AdaptadorUniversal
{
};

class DispositivoRemoto : public AdaptadorUniversal
{
};

class DispositivoDisco : public AdaptadorUniversal
{
};

class DispositivoMultiple : public DispositivoRemoto, public DispositivoDisco
{
};






