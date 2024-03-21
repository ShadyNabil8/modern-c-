# Copying in C++

When we assign an object to another using ```=```, we actually ```copying``` the content of the first to the second. And may be this what we do't want to do.

```cpp
Programmer p1(10);
LOG(p1.languages); // 10
Programmer p2 = p1;
LOG(p2.languages); // 10
```

But when dealing with ```pointers``` we assign not the actual object but the address, i.e., there is no copying here.

```cpp
Programmer*p3 = new Programmer();
p3->languages = 20;
LOG(p3->languages); // 20
Programmer*p4 = p3;
p4->languages=30;
LOG(p3->languages); // 30
```

# shallow copy

If we make somthing like this,

```cpp
MyString string = "Programmer"; 
LOG(string);
MyString string_cpy = string;
LOG(string_cpy);
```

The output will be

```bash
Programmer
Programmer
free(): double free detected in tcache 2
Aborted (core dumped)
```

And this is because when we use ```=``` it means to copy the ```m_Size``` and ```*m_Buffer``` which is an address. This means that we assign one address to two pointers. So when the program free one pointer(may be at the end of the function), the another pointer pointes to null, so ant attempt to free it, the program wiil crash. I want to say that without creating a ```copy constructor```, cpp will copy thr data (m_Size/m_Buffer) to the other class(using the default copy constructor), whaich is a problem.

Another example to make it clear.

```cpp
MyString string = "Programmer";
MyString string_cpy = string;
string_cpy[0] = 'V';
LOG(string);
LOG(string_cpy);
```

```
Vrogrammer
Vrogrammer
free(): double free detected in tcache 2
Aborted (core dumped)
```

## Deep copy (Problem of the dynamiclly allocated data)

To aviod the above issue and create another object when we need to create another one not just refer to it, use deep copy instade.

1. Create a ```copy constructor```

```cpp
MyString::MyString(const MyString &string)
{
    this->m_Size = string.m_Size;
    this->m_Buffer = new char[m_Size + 1];
    strcpy(this->m_Buffer, string.m_Buffer);
}
```

```cpp
MyString string = "Programmer";
MyString string_cpy = string;
string_cpy[0] = 'V';
LOG(string);
LOG(string_cpy);
///////////// OUTPUT /////////////
Programmer
Vrogrammer
```

There is no ```segmentation fault``` as seen, we create a now location for the new object.

# Note

If we replaced the ```LOG()``` with anither finction to print the string like this and run the code.

```cpp
void PrintMyString(const MyString string)
{
    LOG(string);
}
```

In this function we pass the object as acual object not as a ```refrence```, so in this function we copy the object each time we pass it to the function and then print the object then delete it!!.


So, Always pass te obkects as ```refrences```.

```cpp
void PrintMyString(const MyString& string)
```

And there is another issue, if we remove the **copy constructor** and did't use refrences, we actually can delete our pointers```m_buffer``` inside the function that prints.

```cpp
MyString string = "Programmer";
MyString string_cpy = string;
string_cpy[0] = 'V';
PrintMyString(string);
PrintMyString(string);
PrintMyString(string);
PrintMyString(string_cpy);
```

```
Vrogrammer
�.�_
free(): double free detected in tcache 2
Aborted (core dumped)
```