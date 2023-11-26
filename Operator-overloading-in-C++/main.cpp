#include <iostream>

struct Vector
{
    int x;
    int y;
    Vector(int x, int y) : x(x), y(y) {}
    Vector add(const Vector &param) const
    {
        return Vector(x + param.x, y + param.y);
    }
    Vector multiply(const Vector &param) const
    {
        return Vector(x * param.x, y * param.y);
    }
    Vector operator+(const Vector &param) const
    {
        return Vector(x + param.x, y + param.y);
    }
    Vector operator*(const Vector &param) const
    {
        return Vector(x + param.x, y * param.y);
    }
};

// In C++, the overloaded << operator for output is typically defined as a non-member function.
// When I tried to define it inside the struct I encountered an error
// See README file file for an important note about ostream and cout.
std::ostream &operator<<(std::ostream &stream, const Vector &v)
{
    stream << v.x << ',' << v.y;
    return stream;
}

int main(int argc, char const *argv[])
{
    Vector v1(1, 2);
    Vector v2(1, 2);
    // Vector vres = v1.add(v2);
    // std::cout << vres.x << std::endl;
    // std::cout << vres.y << std::endl;
    Vector vres = v1 + (v2);
    std::cout << vres << std::endl;
    return 0;
}
