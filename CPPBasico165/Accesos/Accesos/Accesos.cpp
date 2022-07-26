
#if 0
class Cualquiera
{
private:
    int m_privada{}; // sólo pueden acceder los miembros de Padre y amigos (no clases derivadas)
public:
    int m_publica{}; // accesible desde cualquier parte del programa
};





class Padre
{
public:
    int m_publica{}; // accesible desde cualquier parte del programa
private:
    int m_privada{}; // sólo pueden acceder los miembros de Padre y amigos (no clases derivadas)
protected:
    int m_protegida{}; // accesible para miembros de padre, amigos y miembros de clases derivadas
};

class Derivada : public Padre
{
public:
    Derivada()
    {
        m_publica = 1; //permitido: puede accederse desde cualquir parte, incluidas clases derivadas
        m_protegida = 2; //permitido: miembros de derivadas acceden a miembros protected clase Padre
        m_privada = 3; //no permitido: miembros privados clase Padre inaccesibles para clases derivadas
    }
};

int main()
{
    Padre padre;
    padre.m_publica = 1; // permitido: miembros public accesibles desde fuera de la clase
    padre.m_protegida = 2; // no permitido: miembros protected inacesibles desde fuera de la clase
    padre.m_privada = 3; // no permitido: miembros private inaccesibles desde fuera de la clase

    return 0;
}
#endif

#if 0
class Padre
{
public:
    int m_publica{}; // accesible desde cualquier parte del programa
private:
    int m_privada{}; // sólo pueden acceder los miembros de Padre y amigos (no clases derivadas)
protected:
    int m_protegida{}; // pueden acceder los miembros de Padre , amigos y clases derivadas
};

// Hereda públicamente de Padre
class Publica : public Padre
{
};

// Hereda en modo protegido de Padre
class Protegida : protected Padre
{
};

// Hereda en modo privada de Padre
class Privada : private Padre
{
};

//Modo predeterminado es Herencia privada
class Predeteminada : Padre 
{
};







class Padre
{
public:
    int m_public{};
protected:
    int m_protected{};
private:
    int m_private{};
};

class Pub : public Padre // nota: herencia pública
{
    // Herencia pública significa:
    // Los miembros heredados como Public se mantienen public (así m_public es tratado como public)
    // Los miembros heredados Protected se mantienen protected (así m_protected es tratado como protected)
    // Los miembros heredados Private se mantienen inaccesibles (así m_private ess inaccesible)
public:
    Pub()
    {
        m_public = 1; // correcto: m_public fue heredado como public
        m_protected = 2; // correcto: m_protected fue heredado como protected
        m_private = 3; // incorrecto: m_private es inaccesible  desde la clase derivada
    }
};

int main()
{
    // Los accesos externos utilizan los especificadores de acceso de la clase a la que acceden
    Padre padre;
    padre.m_public = 1; // correcto: m_public es public en Padre
    padre.m_protected = 2; // incorrecto: m_protected es protected en Padre
    padre.m_private = 3; // incorrecto: m_private es private en Padre

    Pub pub;
    pub.m_public = 1; // correcto: m_public es public en Pub
    pub.m_protected = 2; // incorrecto: m_protected es protected en Pub
    pub.m_private = 3; // incorrecto: m_private es inaccessible en Pub

    return 0;
}
#endif





class Padre
{
public:
    int m_public{};
protected:
    int m_protected{};
private:
    int m_private{};
};

class Pri : private Padre // nota: herencia privada
{
    // Herencia Privada significa:
    // Miembros public heredados se convierten en private (así m_public es tratado como private)
    // Miembros protected heredados se convierten en private (así m_protected es tratado como private)
    // Miembros private heredados se mantienen inaccesibles (así, m_private es inaccesible)
public:
    Pri()
    {
        m_public = 1; // correcto:  pero m_public pasa a ser private en Pri
        m_protected = 2; // correcto: pero m_protected pasa a ser private en Pri
        m_private = 3; // incorrecto: clases derivadas no pueden acceder a miembros privados en la clase padre
    }
};

int main()
{
    // Los accesos externos utilizan los especificadores de acceso de la clase a la que acceden.
    // En este caso, los especificadores de acceso de padre.
    Padre padre;
    padre.m_public = 1; // correcto: m_public es public en Padre
    padre.m_protected = 2; // incorrecto: m_protected es protected en Padre
    padre.m_private = 3; // incorrecto: m_private es private en Padre
    //en este caso, los especificadores de acceso de pri.
    Pri pri;
    pri.m_public = 1; // incorrecto: m_public es ahora private en Pri
    pri.m_protected = 2; // incorrecto: m_protected es ahora private en Pri
    pri.m_private = 3; // incorrecto: m_private es inaccesible en Pri

    return 0;
}






