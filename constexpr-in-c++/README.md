# constexpr

Sometimes we write a code that makes some math calculations in runtime. But somwthime these calculations are rebeated. So what is the problem to move these calculations form runtime to compile time to improve the performance. This is the idea of constexpr in c++.

we have this function to calculate the factorial

```cpp
int factorial(int f)
{
    if (f == 1)
        return 1;
    else
        return f * factorial(f - 1);
}
```

We can call this function inside the main like this

```cpp
int main(int argc, char const *argv[])
{
    int x = factorial(5); 
    cout << x << endl; //120
    return 0;
}
```

If we see the assembly code we notice that we call the function ```factorial```

```assembly
00000000000011d8 <main>:
    11d8:       f3 0f 1e fa             endbr64 
    11dc:       55                      push   %rbp
    11dd:       48 89 e5                mov    %rsp,%rbp
    11e0:       48 83 ec 20             sub    $0x20,%rsp
    11e4:       89 7d ec                mov    %edi,-0x14(%rbp)
    11e7:       48 89 75 e0             mov    %rsi,-0x20(%rbp)
    11eb:       bf 05 00 00 00          mov    $0x5,%edi
    11f0:       e8 b4 ff ff ff          call   11a9 <factorial(int)>
    11f5:       89 45 fc                mov    %eax,-0x4(%rbp)
    11f8:       8b 45 fc                mov    -0x4(%rbp),%eax
```

So this means that this calculation is done in runtime. We wat it to be done in the compiation time. To do this we will add constexpt word to the function and to the variable that will carry the result of the operation.

```cpp
constexpr int factorial(int f)

/* This means thar this function can be evaluated in the runtime if we want */
```

```cpp
constexpr int x = factorial(5);
/* This teels the compiler to make this caluclation in the compilation time if possible ( and we will see when it is not possible) */
```

When we see the assembly we notice that there is no call to the function ```factorial```. And instade if it the result of the calculation qhich is ```120(0x78)``` is added.

```
00000000000011a9 <main>:
    11a9:       f3 0f 1e fa             endbr64 
    11ad:       55                      push   %rbp
    11ae:       48 89 e5                mov    %rsp,%rbp
    11b1:       48 83 ec 20             sub    $0x20,%rsp
    11b5:       89 7d ec                mov    %edi,-0x14(%rbp)
    11b8:       48 89 75 e0             mov    %rsi,-0x20(%rbp)
    11bc:       c7 45 fc 78 00 00 00    movl   $0x78,-0x4(%rbp)
    11c3:       be 78 00 00 00          mov    $0x78,%esi
```

If we want to make this calculation in runtime we can remove ```constexpr``` from the variable x and keep the ```constexpr``` in the function prototype if you want because it is just tell the compiler that we may need to use this function in the compilation time.

```cpp
int x = factorial(5);
```

#### When we cannot use constexpr ?

We cannot ust it when the calculation cannot be done is the compilation time. for example we value ```5``` in our example is replaced by a random variable that changes everytime.

```cpp
std::random_device ran;
constexpr int x = factorial(rd() % 5); // ERROR (expression must have a constant value)
```
