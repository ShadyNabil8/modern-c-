# lvalues and rvalues in C++

lvalue are a variable that has a location in the memory. While the rvalue are a temp value.

```cpp
int x = 5;
// x : lvalue
// 5 : rvalue
```

We will build another example to see the difference.

```cpp
string firstName = "Ahmed";
string lastName = "Ali";
string fullName = firstName + lastName;
```

We can see here that the ```firstName``` and ```lastName``` are lvalues. ```Ahmed``` and ```Ali``` are ``rvalues``.

Also ```fullName``` is ```lvalue``` but ```firstName + lastName``` is rvalue because it is a temp object that is created to be assigened to fullName. Adn we will prove it.

We can use rvalue refrence and lvalue refrence to prove it.

```cpp
string &str = "Moahmed"; // ERROR
```

This causes an error because str is a lvalue refrence, so it only accepts lvalues.

But if we make str a const string we can do it and there will be no error.

```cpp
const string &str = "Moahmed";
```

There will be no error because by logic the compiler will make sothing like this

```cpp
string temp = "Moahmed";
const string &str = temp;
```

To see what is the rvalue refrence we will write these code

```cpp
void PrintName(string &name)
{
    cout << "lavlue" << endl;
    cout << name << endl;
}
```

This function can only take a lvalue because it takes a lvalue refrence as param. So when we pass to it a rvalue, there will be an error.

```cpp
PrintName(firstName); // OK
PrintName(firstName + lastName); // ERROR
```

There will be an error because ```firstName + lastName``` is an rvalue as we said.

We can write a function that will take a rvalue refrence as param. If we pass lvalue to it, there will be an error.

```cpp
void PrintName(string &&name)
{
    cout << "ravalue" << endl;
    cout << name << endl;
}
```

```cpp
string firstName = "Ahmed";
string lastName = "Ali";
string fullName = firstName + lastName;
PrintName(firstName);
PrintName(firstName + lastName);
```

```
lavlue
Ahmed
ravalue
AhmedAli
```

rvalue and lvalue are important to understand move semantics
