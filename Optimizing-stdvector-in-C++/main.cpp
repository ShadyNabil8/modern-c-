#include <iostream>
#include <vector>

struct Programmer
{
    int m_x;
    int m_y;

    Programmer(int x, int y) : m_x(x), m_y(y)
    {
        std::cout << "______CREATED______" << std::endl;
    }

    Programmer(const Programmer &prog) : m_x(prog.m_x), m_y(prog.m_y)
    {
        std::cout << "COPYYYYY" << std::endl;
    }
};
int main(int argc, char const *argv[])
{
    std::vector<Programmer> p;
    p.reserve(3);
    p.emplace_back(1, 2);
    p.emplace_back(1, 2);
    p.emplace_back(1, 2);

    return 0;
}
