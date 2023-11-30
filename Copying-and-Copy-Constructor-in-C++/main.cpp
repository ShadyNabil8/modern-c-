#include <iostream>
#include "MyString.h"

#define LOG(MSG) std::cout << MSG << std::endl

void PrintMyString(const MyString &string)
{
    LOG(string);
}

int main(int argc, char const *argv[])
{
    MyString string = "Programmer";
    MyString string_cpy = string;
    string_cpy[0] = 'V';
    // LOG(string);
    // LOG(string_cpy);
    PrintMyString(string);
    PrintMyString(string_cpy);
    return 0;
}
