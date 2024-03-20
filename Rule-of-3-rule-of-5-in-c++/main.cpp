#include <iostream>
using namespace std;
class Entity
{
private:
    int *member_ptr;

public:
    Entity()
    {
        member_ptr = new int(0);
    }

    Entity(const Entity &other)
    {
        member_ptr = new int(*(other.member_ptr));
    }

    ~Entity()
    {
        delete member_ptr;
        cout << "Deleted" << endl;
    }

    void SetValue(int val)
    {
        *member_ptr = val;
    }
    int GetValue()
    {
        return *member_ptr;
    }

    Entity &operator=(const Entity &other)
    {
        if (this != &other)
        {
            *member_ptr = *(other.member_ptr);
        }
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    // Entity e0;
    // e0.SetValue(5);
    // cout << "e0 " << e0.GetValue() << endl;
    // Entity e1 = e0;
    // e1.SetValue(7);
    // e0.SetValue(10);
    // cout << "e0 " << e0.GetValue() << endl;
    // cout << "e1 " << e1.GetValue() << endl;

    Entity mouse;
    mouse.SetValue(55);
    Entity keyboard;
    keyboard = mouse;
    cout << "mouse: " << mouse.GetValue() << endl;
    cout << "keyboard: " << keyboard.GetValue() << endl;
    mouse.SetValue(99);
    cout << "mouse: " << mouse.GetValue() << endl;
    cout << "keyboard: " << keyboard.GetValue() << endl;
    return 0;
}
