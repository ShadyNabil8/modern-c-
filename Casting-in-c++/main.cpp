#include <iostream>
using namespace std;

class Entity
{
    void print_entity()
    {
        cout << " Hi from print_entity" << endl;
    }

public:
    virtual void print()
    {
        cout << " Hi from print function from entity" << endl;
    }
};

class Player : public Entity
{
public:
    int x = 5;
    void print_player()
    {
        cout << " Hi from print_player" << endl;
    }
    void print()
    {
        cout << " Hi from print function from Player" << endl;
    }
    void sayHi()
    {
        cout << " Hi form Player" << endl;
    }
};

class Enemy : public Entity
{
public:
    void print_enemy()
    {
        cout << " Hi from print_enemy" << endl;
    }
    void print()
    {
        cout << " Hi from print function from Enemy" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Entity *en = new Enemy();
    // Player *pl = en; // ERROR, en can be Player or Enemy. So the player will not trust us
    // Enemy *en = en;  // So here

    // We can do this casting to remove the error
    Player *pl = (Player *)en;
    pl->print();
    pl->sayHi();
    cout << pl->x << endl;
    return 0;
}
