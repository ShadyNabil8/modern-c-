#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int x = 5;
    std::vector<int *> darr;
    darr.push_back(&x);
    std::cout << *(darr[0]) << std::endl;
    return 0;
}
