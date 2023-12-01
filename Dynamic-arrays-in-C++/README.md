*

<h3 align="center">std::vector<></h3>
<div align="center">

</div>

## 📝 Table of Contents

- [📝 Table of Contents](#-table-of-contents)
- [🧐 About ](#-about-)
- [🏁 Getting Started ](#-getting-started-)
- [Note](#note)

## 🧐 About <a name = "about"></a>


The main idea about the std::vector is that it is a dynamic array that grows dynamically; we do not specify a size for it. So we only push elements, and it grows if it needs it. That is it. If it needs to grow, it copies all of the data to a new place, which is, of course, a bigger place in memory. So there is an important idea here, which is how to optimize this growing process as much as possible.

## 🏁 Getting Started <a name = "getting_started"></a>

1. The first thing you need to include is ```vector``` in your project.

```cpp
#include <vector>
```

2. Create your own dynamic array.

```cpp
std::vector<int> darr;
```

The most important question here is: where should we allocate our data? We can choose to allocate it in the ```heap``` or ```stack```, but each choice has its advantages and disadvantages.

If we choose to allocate in ```heap``` in this case, we will store it as pointers.

```cpp
int main(int argc, char const *argv[])
{
std::vector<int *> darr;
return0;
}
```

In this case, our ```pointers``` will be in ```row``` in the stack (like normal arrays), but the actual data will be fragmented in ```heap```. What is wrong with this?

The problem is that the access time will be relatively high because we need to first derive the pointers to get the actual data.

The good point of storing our data as ```pointes``` is that when there is a need to resize our vector, there is no big problem because the pointers are not so large to move. If we store our data as objects and these objects are big enough, there will be a problem moving all this large amount of data.

```cpp
int x = 5;
std::vector<int *> darr;
darr.push_back(&x);
std::cout << *(darr[0]) << std::endl;
```

But on the other hand, if we choose to allocate the data as normal objects, it will also be in ```row``` in the memory, but the difference is that this is the actual data, not '''pointrs''', so there is no need to dereference the pointers.

The bad thing about this option is that if the object size is large and there is a need to resize and grow, the vector needs to be copied to a larger place in memory, which will be costly in cases of large sizes.

## Note

In the example above, we directly use the ```[]``` operator to access the elements of the vector. In other languages, there is a need to use functions like ```vec.get(0)```, but C++ supports operator overloading, and by using ```[]```, it will return the data of the desired index.