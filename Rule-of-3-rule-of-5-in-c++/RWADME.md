# Rule of 3

A class that defined any of the following member functions:

* Destructor
* Copy constructor
* Copy assignment operator

Then it should define all the three of them.

We have Entit class

```cpp
class Entity
{
private:
    int *member_ptr;

public:
    Entity()
    {
        member_ptr = new int(0);
    }
    ~Entity()
    {
        delete member_ptr;
    }
    void SetValue(int val)
    {
        *member_ptr = val;
    }

    int GetValue()
    {
        return *member_ptr;
    }
};
```

If we wrote this code, we will face a problem

```cpp
Entity e0;
e0.SetValue(5);
cout << "e0 " << e0.GetValue() << endl;

Entity e1 = e0;
e1.SetValue(7);
e0.SetValue(10);

cout << "e0 " << e0.GetValue() << endl;
cout << "e1 " << e1.GetValue() << endl;
```

```
e0 5
e0 10
e1 10
```

We cen see than e1 is not equal to ```7```. The ```default copy constructor``` that is called in this line makes a ```shallow copy```. So this default copy constructor copy the pointer member_pointer to e1. I mean that now e0 and e1 points to the **same area in heap**.

To solve this we need to add a copy constructor that maked a deep copy.

```cpp
Entity(const Entity &other)
{
    member_ptr = new int(*(other.member_ptr));
}
```

The output them will be

```
e0 5
e0 10
e1 7
```

This is a copy constructor don't forget. It constructs. So Don't make something like this.

```cpp
Entity(const Entity &other)
{
    *member_ptr = *(other.member_ptr);
}
```

Fault beacuse member_ptr isn't constructeed yet.

Do not forget that thr copy constructor only is called int he construction of the object, i.e., if the object already exist, then something else will be called which is the copy assignment operator.

IF we wrote this code

```cpp
Entity mouse;
mouse.SetValue(55);
Entity keyboard;
keyboard = mouse;
cout << "mouse: " << mouse.GetValue() << endl;
cout << "keyboard: " << keyboard.GetValue() << endl;
mouse.SetValue(99);
cout << "mouse: " << mouse.GetValue() << endl;
cout << "keyboard: " << keyboard.GetValue() << endl;
```

Thot output is supposed to be like this

```
mouse: 55
keyboard: 55
mouse: 99
keyboard: 55
```

But is actually is

```
mouse: 55
keyboard: 55
mouse: 99
keyboard: 99
```

This assignment operator (which is the default copy assignment operator here) maked a ```shallow copy```. It copies all the content of the class as it is to the other class includint the pointer itself not the data it points to, so both objects points to the same address in memory.

And there is another problem, when the scope is ended, the the progrom will call the destructor of the first object and then free the pointer, then when it called the destructor of the second object there will be a crash because the pointer already freed, so when the program tries to free it again, the program will crash.

**So both the default constructor and the default copy assignment operator make a shallow copy.**

So we need to overload this operator to make a deep copy

```cpp
Entity &operator=(const Entity &other)
{
    /* There is no need to make a copy if the objects are the same like making this (mouse = mouse)*/
    if (this != &other)
    {
        *member_ptr = *(other.member_ptr);
    }
}
```

```
mouse: 55
keyboard: 55
mouse: 99
keyboard: 55
```

**_NOTE:_** Do not make thing like this

```cpp
Entity &operator=(const Entity &other)
{
    if (this != &other)
    {
        member_ptr = new int(*(other.member_ptr));
    }
    return *this;
}
```

Do allocat new memory, the object is already created and its memory already created.So do not use ```new``` like that.