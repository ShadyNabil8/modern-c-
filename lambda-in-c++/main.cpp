#include <iostream>
#include <vector>
#include <functional>
using namespace std;
void PlayWithNumbers(std::vector<int> &numbers, const std::function<void(int)> &fun)
{
    for (int number : numbers)
    {
        fun(number);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int x = 100;
    auto lambda = [x](int n) mutable { cout << n + (++x) << endl; };
    PlayWithNumbers(numbers, lambda);
    return 0;
}
