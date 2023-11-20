#include <iostream>
#include "String.hpp"
#include "Entity.hpp"
int main()
{
    /* The first instance is created here (the param) */
    /* this string is a temp value(rvalue) */
    Entity e("Shady");

    e.PrintName();

    std::cin.get();
    return 0;
}
