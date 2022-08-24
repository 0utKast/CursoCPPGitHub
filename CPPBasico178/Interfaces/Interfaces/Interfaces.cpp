
#include <iostream>

class IRegistrador
{
public:
	virtual ~IRegistrador() = default;
	virtual void reg_transfer(long de, long para, double cantidad) = 0;
};

class ConsolaIRegistrador : public IRegistrador
{
	void reg_transfer(long de, long para, double cantidad) override
	{
		std::cout << "[cons] " << de << "-> " << para << ": " << cantidad << '\n';
	}
};

class ArchivoIRegistrador : public IRegistrador
{
	void reg_transfer(long de, long para, double cantidad) override
	{
		std::cout << "[arch] " << de << ":: " << para << " .- " << cantidad << '\n';
	}
};

class ImpIRegistrador : public IRegistrador
{

	void reg_transfer(long de, long para, double cantidad) override
	{

		std::cout << "[imp] " << de << ": " << para << " : " << cantidad << '\n';
	}
};


class DirIRegistrador : public IRegistrador
{

	void reg_transfer(long de, long para, double cantidad) override
	{

		std::cout << "[dir] " << de << ":: " << para << " :: " << cantidad << '\n';
	}
};


class Enviar
{
public:
	void set_registrador(IRegistrador* nuevo_registrador)
	{
		registrador = nuevo_registrador;
	}
	void hacer_transfer(long de, long para, double cantidad) {
		if (registrador)
			registrador->reg_transfer(de, para, cantidad);
	}

private:
	IRegistrador* registrador{};
};

int main() {
	ConsolaIRegistrador consola_registrador;
	ArchivoIRegistrador archivo_registrador;
	ImpIRegistrador imp_registrador;


	DirIRegistrador dir_registrador;

	Enviar enviar;
	enviar.set_registrador(&consola_registrador);
	enviar.hacer_transfer(1000, 2000, 49.95);
	enviar.set_registrador(&archivo_registrador);
	enviar.hacer_transfer(2000, 4000, 20.00);
	enviar.set_registrador(&imp_registrador);
	enviar.hacer_transfer(4000, 2999, 34.54);
	enviar.set_registrador(&dir_registrador);
	enviar.hacer_transfer(5000, 23999, 343.54);


}








#if 0
class Enviar {
public:
	Enviar(IRegistrador& registrador)
		: registrador{ registrador } {}

	void hacer_transfer(long de, long para, double cantidad) {

		registrador.reg_transfer(de, para, cantidad);
	}

private:
	IRegistrador& registrador;
};

int main() {
	ConsolaIRegistrador registrador;
	Enviar enviar{ registrador };
	enviar.hacer_transfer(1000, 2000, 49.95);
	enviar.hacer_transfer(2000, 4000, 20.00);
}

#endif











