# Const keyword in C/C++

### This example shows the difference between const in C/C++ especially with pointers.

```c
const int y = 1;
int *x = &y; // Valid in C but not in C++

/* To make it valid */
int *z = (int *) &y;
```
### Char array with const keyword in C/C++
```cpp
/* C++ code */
std::string name = "shady";
```
#### In C++, ```"shady"``` will be treated as ```const char[]```. The string class has a constructor that takes const char[] as a parameter.


```c
/* C code */
char *str = "Nabil";
```
#### In C, ```"Nabil"``` will be treated as char[] not const.
```"shady"``` in C/C++ is immutable (cannot be modified). If an attempt is made to use str (in both exanples) to modify the contents of the array, the behavior is undefined.


#### Why this?
Because string literals are stored in the.rodata section, they do vary by platform. For example, simpler chip architectures may not support read-only memory segments, so the data segment will be writable. So pointing to this data using ```char *str = "shady"``` results in pointing to read-only data.

#### How do I make it modifiable?
```c
/* C/C++ */
char str[] = "Shady";
```
#### This declaration is identical to
```c
/* C/C++ */
char str[] = {'s', 'h', 'a', 'd', 'y'};
str[1] = '*'; // results in "s*ady"
```
#### Summary
* ```char s[]```: stack
* ```char *s```: .rodata section of the object file.
### More about the const keyword in C++


```const``` keyword for methods inside a class means that I cannot change the values of the members in this class.


```cpp
class Player
{
private:
public:
  int x;
  Player();
  ~Player();
  void modifyx() const
  {
    x = 5; // Error
  }
}
```

But suppose that the function ```modifyx()``` was not a const function, and there is another function outside the class called ```print(const Player* p)```. And we do this.
```cpp
void print (const Player* p)
{
  p->modifyx(); // Error because the object has type qualifiers that are not compatible with the member function.
}
```
### mutable keyword
To be able to modify the class member inside the const methos, use the mutable keyword.
```cpp
mutable int x; // The previous error will be gone.
```
