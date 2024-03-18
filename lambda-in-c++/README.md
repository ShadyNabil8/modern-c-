# lambda function

lambda function is like normal function but it is used for a certain purpose, so there is no need to make it like normal function.

Forexample we have a normal function that do somethig with a vector. This thing can be different each time we call this normal function. We can specify this different thig using lambda function.

This function ```PlayWithNumbers``` takes a vector as a param and also a pointer to function (or we can say function) as param. We can pass any function we want depending on the action we want to do with thi vector each time.

```cpp
void PlayWithNumbers(std::vector<int> &numbers, void (*function)(int))
{
    for (int number : numbers)
    {
        function(number);
    }
}
```

Inside thei main we can write this code which calles the ```PlayWithNumbers``` function and pass to it the lambda function.

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
    PlayWithNumbers(numbers, [](int n)
                    { cout << n << endl; });
```

we can make it more clear by doing this

```cpp
auto lambda = [](int n){ cout << n << endl; };
PlayWithNumbers(numbers, lambda);
```

```cpp
void (*lambda)(int)  = [](int n){ cout << n << endl; };
PlayWithNumbers(numbers, lambda);
```

#### But what if we need to daed with some variables (in the scope of labmda function) inside this lambda function?

For example if we have a variable in the main function like this.

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
int x = 100;
void (*lambda)(int) = [](int n){ cout << n + x << endl; };
PlayWithNumbers(numbers, lambda);
```

We cannot deal with the var x inside tha lambda even if it is inside the labda scobe. So wo make this we can pass (capture) x to the lambda.

```cpp
auto lambda = [x](int n) { cout << n + x << endl; };
// We must use auto here
```

In this case we need to chage the prototype of the function PlayWithNumbers to be like this. i.e., the ```void (*function)(int)``` is not valid here.

```cpp
void PlayWithNumbers(std::vector<int> &numbers, const std::function<void(int)> &fun)
```

If we want to pass (capture) x py refrence we can use ```[&x]```

* ```[&x,y]``` to capture x pay refrence and y by value(copy).
* ```[=]``` capture all varuables by copy.
* ```[&]``` capture all varuables by refrence.
* ```[]``` capture nothing.

If we capture x by ```value``` and we try to change it, it is not possible.

```
auto lambda = [x](int n) { cout << n + (++x) << endl; }; // ERROR
```

To make it possible we can use ```mutable``` specifier

```cpp
auto lambda = [x](int n) mutable { cout << n + (++x) << endl; };
```
