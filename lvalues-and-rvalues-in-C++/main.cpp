#include <iostream>
using namespace std;

void PrintName(string &name)
{
    cout << "lavlue" << endl;
    cout << name << endl;
}

void PrintName(string &&name)
{
    cout << "ravalue" << endl;
    cout << name << endl;
}

int main(int argc, char const *argv[])
{
    string firstName = "Ahmed";
    string lastName = "Ali";
    string fullName = firstName + lastName;
    PrintName(firstName);
    PrintName(firstName + lastName);
    return 0;
}
