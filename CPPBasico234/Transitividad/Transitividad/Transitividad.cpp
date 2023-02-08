import persona;
import <string>;
import <iostream>;
import <vector>;

int main()
{
    std::string str{ "Juan" };
    std::cout << str;

}







#if 0
import persona;
import <string>;
import <iostream>;
import <vector>;


int main()
{
    std::string str{ "Juan" };
    std::cout << str;

}

int main()
{
    Persona persona{ "Juan", "Blanco" };
    const auto& nombre{ persona.getNombre() };
    auto length{ nombre.length() };
   
}
#endif


#if 0
int main()
{
    std::string str;
    Persona persona{ "Juan", "Blanco" };
    const std::string& apellido{ persona.getApellido() };
}
#endif



