#if 0
//Código 001
template <typename T>
T sum(T a)
{
	return a;
}
template <typename T, typename... Args>
T sum(T a, Args... args)
{
	return a + sum(args...);
}






//Código 002


template<typename T, typename... Args>
T sum(T a, Args... args) {
    if constexpr (sizeof...(args) == 0) {
        return a;
    }
    else {
        return a + sum(args...);
    }
}

#endif




//Código 003





template <typename... T>
int sum(T... args)
{
    return (... + args);
}

//Código 004


#include <iostream>
int main()
{
    int s1 = sum();           // error


    int s2 = sum_from_zero(); // OK



    std::cout << sum(1) << '\n';
    std::cout << sum(1, 2) << '\n';
    std::cout << sum(1, 2, 3, 4, 5) << '\n';
}


//Código 005


template <typename... T>
int sum_from_zero(T... args)
{
    return (0 + ... + args);
}




#if 0
//Código 006
template <typename... T>
void printl(T... args)
{
    (..., (std::cout << args)) << '\n';
}
template <typename... T>
void printr(T... args)
{
    ((std::cout << args), ...) << '\n';
}


template<typename T, typename... Args>
void push_back_many(std::vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);
}
push_back_many(v, 1, 2, 3, 4, 5); // v = {1, 2, 3, 4, 5}

// Código 007




int min(int a, int b)
{
    return a < b ? a : b;
}
int min(int a, int b, int c)
{
    return min(a, min(b, c));
}
int min(int a, int b, int c, int d)
{
    return min(a, min(b, min(c, d)));
}
int min(int a, int b, int c, int d, int e)
{
    return min(a, min(b, min(c, min(d, e))));
}
#endif