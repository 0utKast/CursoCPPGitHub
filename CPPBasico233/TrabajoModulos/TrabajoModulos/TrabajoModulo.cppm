#if 0
//C�digo 001
export module TrabajoModulo;

import <vector>;
export namespace ModeloDatos
{
    class Persona { /* ... */ };
    class Direccion { /* ... */ };
    using Personas = std::vector<Persona>;
}


//C�digo 002
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