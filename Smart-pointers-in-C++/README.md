# Smart Pointers in C++

The smart pointer is just like the normal pointer exept one thing, ther is no need to manualy free it. If you use smart pointer (call ```new```), there is no need to call ```free```.

## Stack VS Heap allocation

We have a ```Programmer``` Class and....

```cpp
int main(int argc, char const *argv[])
{
    {
        Programmer p;
        // Programmer Created!
        // Programmer Destroyed!
    }
    return 0;
}
```

But with this, there is another output

```cpp
{
    Programmer *p = new Programmer;
    // Programmer Created!
}
```

Another example

```cpp
int *CreateArr()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    return arr;
}
int main(int argc, char const *argv[])
{
    int *ptr = CreateArr();
    LOG(ptr[5]); // Segmentation fault (core dumped)
    return 0;
}
```

We must use `new` instade of the normal stack declaration.

```cpp
    int *arr = new int[10];
```

## Shared pointer in C++

This is the first type of smart pointers in c++. The scope of this pointer ends when there is no one used this pointers. I meant that this pointer can be used by many instaces and it will be deleted when all of these instances are gone.

**There is must be at least one owner to make the shared pointer alive.**

```cpp
std::shared_ptr<Programmer> generateShared()
{
    auto sptr = std::make_shared<Programmer>();
    // Programmer Created
    return sptr;
}
```

```cpp
int main(int argc, char const *argv[])
{
    {
        auto a = generateShared();
        LOG(a.use_count()); // 1
        auto b = a;
        LOG(b.use_count()); // 2
    }
    return 0;
}
```

## Unique pointer in C++

The unique pointer only have one owner.

```cpp
std::unique_ptr<Programmer> generateUnique()
{
    std::unique_ptr sptr = std::make_unique<Programmer>();
    return sptr;
}
int main(int argc, char const *argv[])
{
    auto a  = generateUnique();
    //auto b = a; // Error
    // Note here that we move the value from
    // (sptr) to (a) without problems because
    //(sptr) is now out of scope.
    return 0;
}
```

## more about Unique pointer in C++

We can move the ownership from a unique pointer to another pointer using ```std:move()```. But ```get()``` is used to get the data that pointer points to;

```cpp
 auto a = generateUnique();
    // auto b = a; // Error
    LOG(a->x);    // 1
    LOG(a.get()); // 0x556c1caf0eb0
    auto b = std::move(a);
    LOG(b->x);    // 1
    LOG(b.get()); // 0x556c1caf0eb0
    LOG(a.get()); // 0(null)
    LOG(a->x);    // Segmentation fault
```

## Weak pointer in C++

It is used when we want to make a sharedpointer without be treated as ```owner```.

The main note in the ```weak_ptr``` is that the area that a weak pointer points to is ```not``` guaranteed to be valid!. Image all the shared pointer go out of scope, then the area is deallocated, now the ```weak_ptr``` points to nothing.

***You can't assign a ```weak_ptr``` to an ```unique_ptr```.***

***We can not derefrence the weak pointer because it has no derefrence operator.***

But we still can get a shared pointer from the weak pointer and then print the value. Using ```lock()``` function we can make it.

```cpp
auto shared  = generateShared();
LOG(shared.use_count()); // 1
std::weak_ptr weak = shared;
LOG(shared.use_count()); // still 1
// We can not derefrence the weak pointer
// It has no derefrence operator.
// LOG(weak->x);
std::shared_ptr reshared = weak.lock();
LOG(reshared->x); // 1
```
