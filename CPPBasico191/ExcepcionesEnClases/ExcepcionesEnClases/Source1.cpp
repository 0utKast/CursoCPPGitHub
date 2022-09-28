
//....................Código anterior clase

int& IntArray::operator[](const int indice)
{
    return m_datos[indice];
}

//...............Código posterior clase



//....................Código anterior clase

int& IntArray::operator[](const int indice)
{
    assert(indice >= 0 && indice < getLength());
    return m_datos[indice];
}

//...............Código posterior clase



//....................Código anterior clase

int& IntArray::operator[](const int indice)
{
    if (indice < 0 || indice >= getLength())
        throw indice;

    return m_datos[indice];
}

//...............Código posterior clase




