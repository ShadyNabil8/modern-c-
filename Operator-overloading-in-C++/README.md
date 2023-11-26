# Operator overloading in C++

* Operator is just a function does some thing.
* Operator overloading means to change the function of this operator when dealing with acetain datatype.

## Operator+ overloading

Suppose we have this struct.
```cpp
struct Vector
{
    int x;
    int y;
    Vector(int x, int y) : x(x), y(y) {}
};
```
If we want to add or multiply a certain values to the members x and y we can add functions like this to the struct.
```cpp
Vector add(const Vector &param) const
{
    return Vector(x + param.x, y + param.y);
}
```
And write this code 
```cpp
Vector v1(1,2);
Vector v2(1,2);
Vector vres = v1.add(v2);
std::cout << vres.x << std::endl; // 2
std::cout << vres.y << std::endl; // 4
```
But ther is another way to do it using operator overloading.

We first overload the operator+ in the struct.
```cpp
Vector operator+(const Vector &param) const
{
    return Vector(x + param.x, y + param.y);
}
```
So we can use this feature.
```cpp
Vector vres = v1 + (v2);
std::cout << vres.x << std::endl; // 2
std::cout << vres.y << std::endl; // 4
```

## Operator<< overloading
In C++, the overloaded << operator for output is typically defined as a non-member function.
When I tried to define it inside the struct I encountered an error.

The reason we use ```std::ostream& stream``` instead of ```std::cout& stream``` as the parameter type for the overloaded ```<<``` operator is to allow flexibility in where the output is directed. By using ```std::ostream& stream```, we can pass not only ```std::cout``` but also other output streams, such as file streams or string streams, to the operator. This makes the code more versatile and reusable, as the overloaded operator can work with any output stream, not just ```std::cout```.

```cpp
std::ostream &operator<<(std::ostream &stream, const Vector &v)
{
    stream << v.x << ',' << v.y;
    return stream;
}
```
```cpp
Vector vres = v1 + (v2);
std::cout << vres << std::endl;
```

We used ```&``` because it allows the operator to access the Vector object without making a copy of it.

Using references in these contexts can be more efficient than passing objects by value, especially for large objects like streams and complex data structures.

