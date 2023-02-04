#if 0
//Código 001
export module TrabajoModulo;

import <vector>;
export namespace ModeloDatos
{
    class Persona { /* ... */ };
    class Direccion { /* ... */ };
    using Personas = std::vector<Persona>;
}


//Código 002
export module TrabajoModulo;
import <vector>;

export
{
    namespace ModeloDatos
    {
        class Persona { /* ... */ };
        class Direccion { /* ... */ };
        using Personas = std::vector<Persona>;
    }
}
#endif