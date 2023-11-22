#include <iostream>

class Player
{
private:
public:
    mutable int x;
    Player();
    ~Player();
    void modifyx() const
    {
        x = 5;
    }
};

Player::Player()
{
}

Player::~Player()
{
}

int print(const Player *p)
{
    p->modifyx();
    return p->x;
}

int main(int argc, char const *argv[])
{
    Player p;
    std::cout << print(&p) << std::endl; // 5
    return 0;
}
