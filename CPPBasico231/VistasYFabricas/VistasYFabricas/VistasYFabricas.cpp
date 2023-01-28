
#if 0
#include <string_view>;
#include <vector>;
#include <ranges>;
#include <iostream>;

void imprimirRango(std::string_view mensaje, auto& rango)
{
    std::cout << mensaje;
    for (const auto& valor : rango) { std::cout << valor << " "; }
    std::cout << std::endl;
}

int main()
{
    std::vector valores{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    imprimirRango("Secuencia original: ", valores);

    // Filtrar todos los valores impares, dejando solo los valores pares.
    auto resultado1{ valores | std::views::filter([](const auto& valor) { return valor % 2 == 0; }) };
    //o podemos usar:
    //  auto resultado1{ std::ranges::filter_view{ valores, [](const auto& valor) { return valor % 2 == 0; } } };
    imprimirRango("Solo valores pares: ", resultado1);

    // Transformar todos los valores a su valor doble.
    auto resultado2{ resultado1 | std::views::transform([](const auto& valor) { return valor * 2.0; }) };
    imprimirRango("Valores doblados: ", resultado2);

    // Eliminar los dos primeros elementos.
    auto resultado3{ resultado2 | std::views::drop(2) };
    imprimirRango("Dos primeros eliminados: ", resultado3);

    // Invertir la vista.
    auto resultado4{ resultado3 | std::views::reverse };
    imprimirRango("Secuencia invertida: ", resultado4);
}
#endif


#if 0
#include <string_view>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <format>

void imprimirRango(std::string_view mensaje, auto& rango)
{
    std::cout << mensaje;
    for (const auto& valor : rango) { std::cout << valor << " "; }
    std::cout << std::endl;
}

int main()
{
    std::vector valores{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    imprimirRango("Secuencia original: ", valores);

    auto resultado{ valores
     | std::views::filter([](const auto& value) { return value % 2 == 0; })
     | std::views::transform([](const auto& value) { return value * 2.0; })
     | std::views::drop(2)
     | std::views::reverse };
    imprimirRango("Secuencia Final: ", resultado);
}
#endif

#include <string_view>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <format>

void imprimirRango(std::string_view mensaje, auto& rango)
{
    std::cout << mensaje;
    for (const auto& valor : rango) { std::cout << valor << " "; }
    std::cout << std::endl;
}

int main()
{
    std::vector valores{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    imprimirRango("Secuencia original: ", valores);

    auto resultado{ valores
    | std::views::filter([](const auto& value) { return value % 2 == 0; })
    | std::views::take(3)
    | std::views::transform([](const auto& v) { return std::format(R"("{}")", v); }) };
    imprimirRango("Resultado: ", resultado);
}





#if 0
#include <string_view>;
#include <vector>;
#include <ranges>;
#include <iostream>;
#include <format>

void imprimirRango(std::string_view mensaje, auto& rango)
{
    std::cout << mensaje;
    for (const auto& valor : rango) { std::cout << valor << " "; }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    std::vector valores{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    imprimirRango("Secuencia original: ", valores);

    // Filtrar todos los valores impares, dejando solo los valores pares.
    auto resultado1{ valores
        | std::views::filter([](const auto& valor) { return valor % 2 == 0; }) };
    imprimirRango("Solo valores pares: ", resultado1);

    // Eliminar los dos primeros elementos.
    auto resultado2{ resultado1 | std::views::drop(2) };
    imprimirRango("Dos primeros eliminados: ", resultado2);

    // Invertir la vista.
    auto resultado3{ resultado2 | std::views::reverse };
    imprimirRango("Secuencia invertida: ", resultado3);

    // Modificar los elementos usando un loop for basado en rangos.
    for (auto& valor : resultado3) { valor *= 10; }
    imprimirRango("Modificados los elementos originales por la vista, el vector contiene: ", valores);
}
#endif





