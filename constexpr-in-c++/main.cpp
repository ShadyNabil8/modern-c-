#include <iostream>
#include <random>
using namespace std;

constexpr int factorial(int f)
{
    if (f == 1)
        return 1;
    else
        return f * factorial(f - 1);
}

int main(int argc, char const *argv[])
{
    std::random_device ran;
    constexpr int x = factorial(rd() % 5);
    cout << x << endl;
    return 0;
}
