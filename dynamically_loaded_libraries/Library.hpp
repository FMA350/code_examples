#include <iostream>

void greetings();

extern "C"
{
    void safeExp();
}
void safe();
void safe(int);

void mangled();
void mangled(int);