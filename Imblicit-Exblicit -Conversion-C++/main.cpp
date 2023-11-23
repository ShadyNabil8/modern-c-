#include <iostream>

#define TEST 1

class Entity
{
private:
public:
    std::string m_name;
    int m_age;
    Entity();
    ~Entity();
    // #if TEST == 0
    // Entity(std::string name);
    // #elif TEST == 1
    explicit Entity(const std::string &name);
    // #endif
    Entity(int age);
};

Entity::Entity()
{
}

Entity::~Entity()
{
}
// #if TEST == 0
//  Entity::Entity(std::string name) : m_name(name)
//  {
//  }
// #elif TEST == 1
Entity::Entity(const std::string &name) : m_name(name)
{
}
// #endif
Entity::Entity(int age) : m_age(age)
{
}

void printEntity(const Entity &e)
{
    std::cout << e.m_name << std::endl;
}

int main(int argc, char const *argv[])
{
    /**
     * Here when we make the constructo exblicit, there is no problem because
     * we prevent the conversion between string to Entity not from const char[] to string.
    */
    Entity e1("shady"); // "shady" will be converted to a string and then call the constructor
    std::cout << e1.m_name << std::endl;

    /**
     * Error: No suitable constructor exists to convert from "const char [6]" to "Entity"
     * implicit conversion failed.
     */
    Entity e2 = "shady"; //
    std::cout << e2.m_name << std::endl;

    /*
     * Using implicit conversion, 5 will be converted to an Entity.
     * But why in the above exmple c++ failed to convert "shad" to Entity!!!.
     */
    Entity e3 = 5; // Equal to Entity e3 = Entity(5);
    std::cout << e3.m_age << std::endl;

    /*
     * Using implicit conversion, 5 will be converted to an Entity
     */
    printEntity(99);

    /**
     * implicit conversion failed because in this case c++ has to make two imblicit conversion
     * onr form a const char[] to string anr the other form string to an Entity.
     */
    printEntity("shady");

    /**
     * Here, string "shady" will be imblicitly converted to an Entity.
     */
    printEntity(std::string("shady"));

    /**
     * Here, cinat char [] "shady" will be imblicitly converted to an string.
     * Then call the constructor.
     * Here when we make the constructo exblicit, there is no problem because
     * we prevent the conversion between string to Entity not from const char[] to string.
     */
    printEntity(Entity("shady"));

    return 0;
}
