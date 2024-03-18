# Static casting

Unlike the normal C-style casting, static casting happens in the compilation time.

#### 1. We use static casting because it is easy to find in the code

```cpp
int main(int argc, char const *argv[])
{
    double d = 5.5;
    int i = 9;
    i = d;
    std::cout << i << std::endl;
    i = static_cast<int>(d);
    std::cout << i << std::endl;
    return 0;
}
```

#### 2. We use static casting because in some cases it is easy to read

```cpp
using namespace std;

class Integer
{
    int x;

public:
    Integer(int x = 0) : x{x} {}
    operator string()
    {
        return to_string(x);
    }
    int Get_X()
    {
        return x;
    }
};

int main(int argc, char const *argv[])
{
    Integer i(10);
    string str = i;            // using Conversion operator (Hard to read)
    cout << str << endl;       // 10
    cout << i.Get_X() << endl; // 10
    i = 50;                    // Using Conversion constructor
    cout << i.Get_X() << endl; // 50

    i = static_cast<Integer>(99);
    cout << i.Get_X() << endl; // 99
    str = static_cast<string>(i);
    cout << str << endl; // 99

    return 0;
}
```

#### 3. Static casting is more restrictive

```cpp
int main(int argc, char const *argv[])
{
    char c = 's';
    int *x = (int *)&c;
    *x = 5; // Pass in compile time but it is dangerous in runtime (we will access 4 bytes)

    int *y = static_cast<int *>(&c); // FAIL in compilation time
    return 0;
}

```

# Const casting

#### 1. Const casting can be used when trying to cast a const variable to unconst variable

```cpp
int main(int argc, char const *argv[])
{
    const int x = 5;
    int *y = &x; // ERROR (should be const int*)

    // VALID
    int *y = const_cast<int *>(&x);

    cout << *y << endl; // 5

    *y = 99; // NO PROBLEM

    cout << *y << endl; // 99
    return 0;
}
```

#### 2. Const casting can be used when passing a ptr to const parameter to a function that takes a ptr to non-const parameter

```cpp
void function(int *ptr)
{
    cout << *ptr + 5 << endl;
}

int main(int argc, char const *argv[])
{
    const int x = 5;
    const int *y = &x;
    function(y); //ERROR
    return 0;
}
```

```cpp
void function(int *ptr)
{
    (*ptr)++; // NO PROBLEM
    cout << *ptr + 5 << endl;
}

int main(int argc, char const *argv[])
{
    const int x = 5;
    const int *y = &x;
    function(const_cast<int*>(y));
    return 0;
}
```

**_NOTE_:** IF the finction was

```cpp
void function(int x)
{
    cout << x + 5 << endl;
}
```

And we pass it a const interger variable ```const y = 6;```, there is no problem beacuse the function has its own copy of x.

# reinterpret_cast

We can use reinterpret_cast when we want to cast a certain type to a non-compatible type like casting a ```float *``` to a ```int *```. We cannot do this conversion because it will make an error, but using reinterpret_cast, we can do it.

```cpp
    float pi = 3.14f;
    float *pi_ptr = &pi;
    // int *x = pi_ptr; // ERROR
    int *x = reinterpret_cast<int *>(pi_ptr);
    cout << pi << endl; // 3.14
    cout << *x << endl; // 1078523331 (Fault)
    return 0;
```

# dynamic_cast

We should use dynamic casting when trying to cast a base class to a sub class or sub class to base class.

* Casting sub class to base class is easy and there is no need to make casting because it can be done implictily.
* Casting a base class to a sub class is the problem. Imagine that we had an ```Entity``` class and two derived classes, ```Player``` and ```Enemy```. It is a problem when we wry to cast an entity to a player or an enemy because this entity may be a player or enemy using polymerphism. So casting entity(which may be a player) to an enemy will be a problem and may lead to crash.

The base class must be polymorphic, i.e., the base class must have a virtual function unless all this will be meaningless.

Dynamic casting works only with pointers and refreneces.

The three classes are

```cpp
class Entity
{
    void print_entity()
    {
        cout << " Hi from print_entity" << endl;
    }

public:
    virtual void print()
    {
        cout << " Hi from print function from entity" << endl;
    }
};
```

```cpp
class Player : public Entity
{
public:
    int x = 5;
    void print_player()
    {
        cout << " Hi from print_player" << endl;
    }
    void print()
    {
        cout << " Hi from print function from Player" << endl;
    }
    void sayHi()
    {
        cout << " Hi form Player" << endl;
    }
};
```

```cpp
class Enemy : public Entity
{
public:
    void print_enemy()
    {
        cout << " Hi from print_enemy" << endl;
    }
    void print()
    {
        cout << " Hi from print function from Enemy" << endl;
    }
};
```

Here in the First example

```cpp
Entity *en = new Player();
Player *pl = en; // ERROR, en can be Player or Enemy. So the player will not trust us
Enemy *en = en;  // So here
// We can do this casting to remove the error
// Player *pl = (Player *)en;
```

Here in the second example we see that the en object is ```Entity``` type but it is actually an ```Enemy```.
so when we try to make a dynamic casting to be a ```Player``` object it will not work and ```pl``` will be ```nullptr```.

```cpp
Entity *en = new Enemy();
Player *pl = dynamic_cast<Player *>(en);
if (pl) // FALSE
{
    pl->print();
    pl->print_player();
    pl->sayHi();
}
```
Suppose that we have this code

```cpp
Entity *en = new Enemy();
Player *pl = (Player *)en;
pl->print();
pl->sayHi();
cout << pl->x << endl;
```
Here poth Enemy and Player class have a print function, so no problem. But Enemy has no sayHi function, so the behaviour will be strange. Also with the case of x.

The output of the code 

```cpp
Hi from print function from Enemy
Hi form Player
0
```

But how does C++ know that the ```Entity``` object was a ```Player``` or ```Enemy```?

Using Run time Type Information (RTTI) C++ can check for the actual type of the ```Entity``` object. But it is overhead, so synamic casting causes an overhead because C++ need to check the RTTI.