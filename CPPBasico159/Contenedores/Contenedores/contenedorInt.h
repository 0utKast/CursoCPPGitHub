#ifndef CONTENEDORINT_H
#define CONTENEDORINT_H

#include <cassert> // para assert()

class ContenedorInt
{
private:
    int m_largo{};
    int* m_datos{};

public:
    ContenedorInt() = default;

    ContenedorInt(int largo) :
        m_largo{ largo }
    {
        assert(largo >= 0);
        if (largo > 0)
            m_datos = new int[largo] {};
    }

    ~ContenedorInt()
    {
        delete[] m_datos;
        // no necesitamos configurar m_datos a nullptr o m_largo a 0 aquí,
        // porque el objeto será destruido inmediatamente después de esta función
    }

    void borrar()
    {
        delete[] m_datos;
        // Tenemos que asegurarnos de configurar m_datos a nullptr aquí, ¡de no hacerlo
        // puede quedar apuntando a una memoria desasignada!
        m_datos = nullptr;
        m_largo = 0;
    }

    int& operator[](int indice)
    {
        assert(indice >= 0 && indice < m_largo);
        return m_datos[indice];
    }
	
    int getLargo() const { return m_largo; }

    // reasignar redimensiona el ContenedorInt.  Cualquier elemento existente será destruido. Esta función es muy rápida.
    void reasignar(int nuevoLargo)
    {
        // Primero borramos todos los elementos existentes
        borrar();

        // Si el nuevo tamaño da lugar a un contenedor vacío, usamos return para salir aquí
        if (nuevoLargo <= 0)
            return;

        // Si el nuevo tamaño es mayor de 0, le asignamos al Contenedor nuevos elementos
        m_largo = nuevoLargo;
        m_datos = new int[nuevoLargo];
       
    }    

    // redimensionar redimensiona el ContenedorInt.  Mantiene los elementos existentes, pero es más lento.
    void redimensionar(int nuevoLargo)
    {
        // Si el nuevo contenedor tiene ya el largo correcto, todo está hecho
        if (nuevoLargo == m_largo)
            return;

        // Si vamos a redimensionar a un contenedor vacío, lo hacemos llamando a borrar( ) y salimos
        if (nuevoLargo <= 0)
        {
            borrar();
            return;
        }

        // Ahora ya nos aseguramos que nuevoLargo tiene al menos un elemento.  
        // Desarrollamos un algoritmo con estos pasos: Primero asignamos un nuevo
        // ContenedorInt, luego copiamos los elementos del ContenedorArray existente al nuevo.
        // Una vez hecho, podemos destruir el viejo ContenedorInt, y hacer que m_datos
        // apunte al nuevo ContenedorInt.

        // Primero tenemos que asignar un nuevo ContenedorInt
        int* datos{ new int[nuevoLargo] };

        // Luego tenemos que calcular cuantos elementos copiar del existente
        // ContenedorInt al nuevo. Queremos copiar tantos elementos como haya
        // en el más pequeño de los dos ContenedoresInt.
        if (m_largo > 0)
        {
            int elementosACopiar{ (nuevoLargo > m_largo) ? m_largo : nuevoLargo };

            // Ahora copiamos los elementos uno por uno
            for (int indice{ 0 }; indice < elementosACopiar; ++indice)
                datos[indice] = m_datos[indice];
        }
		
        // Ahora podemos borrar el ContenedorInt viejo que ya no necesitamos
        delete[] m_datos;

        // Y usamos el nuevo ContenedorInt en su lugar  Observa que esto se hace con m_datos apuntando
        // a la misma dirección del nuevo ContenedorInt que hemos asignado dinámicamente. Como
        // datos fue asignado dinámicamente, no será destruido cuando salga de alcance.
        m_datos = datos;
        m_largo = nuevoLargo;
    }

    void insertarAntes(int valor, int indice)
    {
        // comprobamos que pasamos un indice dentro de los límites correctos
        assert(indice >= 0 && indice <= m_largo);

        // Primero creamos un nuevo ContenedorInt un elemento mayor que el viejo
        int* datos{ new int[m_largo + 1] };

        // Copiamos todos los elementos hasta el indice
        for (int antes{ 0 }; antes < indice; ++antes)
            datos[antes] = m_datos[antes];

        // Insertamos nuestro nuevo elemento en el nuevo ContenedorInt
        datos[indice] = valor;

        // Copiamos todos los valores después del elemento insertado
        for (int despues{ indice }; despues < m_largo; ++despues)
            datos[despues + 1] = m_datos[despues];

        // Terminamos, borrando el viejo ContenedorInt, y usando el nuevo en su lugar
        delete[] m_datos;
        m_datos = datos;
        ++m_largo;
    }

    void quitar(int indice)
    {
        // comprobamos que pasamos un indice dentro de los limites correctos
        assert(indice >= 0 && indice < m_largo);

        // Si el viejo ContenedorInt solo tiene un elemento, lo borramos y volvemos
        if (m_largo == 1)
        {
            borrar();
            return;
        }

        // Primero creamos un nuevo ContenedorInt un elemento más pequeño que el viejo
        int* datos{ new int[m_largo - 1] };

        // Copiamos todos los elementos hasta el índice
        for (int antes{ 0 }; antes < indice; ++antes)
            datos[antes] = m_datos[antes];

        // Copiamos todos los valores después del elemento que queremos eliminar
        for (int despues{ indice + 1 }; despues < m_largo; ++despues)
            datos[despues - 1] = m_datos[despues];

        // Terminamos, borrando el viejo ContenedorInt, y usamos el nuevo en su lugar
        delete[] m_datos;
        m_datos = datos;
        --m_largo;
    }

    // Un par de funciones adicionales por comodidad
    void insertarAlPrincipio(int valor) { insertarAntes(valor, 0); }
    void insertarAlFinal(int valor) { insertarAntes(valor, m_largo); }    
};

#endif


