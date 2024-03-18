#include <iostream>
using namespace std;
class Rectangle
{
private:
    int width;
    int length;
    int area;
    string color;

public:
    Rectangle(int l, int w)
    {
        cout << "First constructor" << endl;
        width = w;
        length = l;
        area = length * width;
    }
    Rectangle(int l, int w, std::string c) : Rectangle(l, w)
    {
        cout << "Second constructor" << endl;
        color = c;
    }
    void PrintInfo()
    {
        cout << "width is " << width << endl;
        cout << "length is " << length << endl;
        cout << "area is " << area << endl;
        cout << "color is " << color << endl;
    }
};

int main(int argc, char const *argv[])
{
    Rectangle r = Rectangle(5,3,"RED");
    r.PrintInfo();
    return 0;
}
