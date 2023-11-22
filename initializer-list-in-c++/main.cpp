#include <iostream>

class Person
{
private:
public:
    Person();
    Person(int x);
    ~Person();
};

Person::Person()
{
    std::cout << "Created" << std::endl;
}

Person::Person(int x)
{
    std::cout << "Created->" << x << std::endl;
}

Person::~Person()
{
}

class Player
{
private:
    Person p1;
    Person p2;

public:
    Player();
    ~Player();
};

Player::Player() : p1(Person(2)) // results in Created->2
{
    p2 = Person(1);
    // results in:
    
    // Created
    // Created->1 
}

Player::~Player()
{
}

int main(int argc, char const *argv[])
{
    Player p = Player();
    return 0;
}
