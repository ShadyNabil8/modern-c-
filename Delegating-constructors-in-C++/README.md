# Delegating constructors

IT is just a way to reduce the dublication in the code by moving the rebeated code i nthe constructors to one constructor.

```cpp
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
    Rectangle(int l, int w, std::string c)
    {
        cout << "Second constructor" <<endl;
        width = w;
        length = l;
        area = length * width;
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
```

In this class, ther is a code dublication in the constructors in this part of code.
```cpp
width = w;
length = l;
area = length * width;
```

So we can move this part of code to only one constrictor and use constructor delegation to aboid dublication. We can do this by modifying the second constructor.

```cpp
Rectangle(int l, int w, std::string c) : Rectangle(l, w)
{
    cout << "Second constructor" <<endl;
    color = c;
}
```

By doing this, the second constructor will first call the first constructor and then containue its work.

```cpp
int main(int argc, char const *argv[])
{
    Rectangle r = Rectangle(5,3,"RED");
    r.PrintInfo();
    return 0;
}
```

```
First constructor
Second constructor
width is 3
length is 5
area is 15
color is RED
```