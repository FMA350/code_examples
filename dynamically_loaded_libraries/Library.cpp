#include "Library.hpp"

void greetings()
{
    std::cout << "A dangerous greetings() function in a C++ library \n";
}

void safeExp()
{
    safe();
    safe(1);
}

void safe()
{
    std::cout << "A safe() function in C++\n";
}

void safe(int x)
{
    std::cout << "A safe(int x) function in C++\n";
}

void mangled()
{
    std::cout << "Goodbye cruel world";
}


void mangled(int x)
{
    std::cout << "Goodbye cruel world";
}