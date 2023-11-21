#include <iostream>
#include "Entity.h"
#include "Player.h"

/**
 * An example on polymerphism concept that descrips the behavour of the program when
 * treating a sub class as a super class.
 * 
 * Here we have a function called PrintClassName() in both classes, we need to know
 * what function of these two will be called using a base class instance in the case of
 * treating this instance as base class object and in case of treating it as sub class object
*/
void print(Entity *e)
{
    e->PrintClassName();
}
void print(Entity e)
{
    e.PrintClassName();
}

int main()
{
    /* Here we must use pointer to make the functionality */
    Entity* e = new Entity();
    Player* p = new Player();
    print(e);
    print(p);

    Entity e_o =  Entity();
    Player p_o =  Player();
    print(e_o);
    print(p_o);
}