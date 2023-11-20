
# Move Semantics in C++

In this repo we will make 2 examples include move constructor, move assignment operator and the difference between them.


# Exmple1 (Move Constructor)

The main idea of the move constrictor that it steals the resourses form temp object to another object. i.e., instade of creating two object using the copy constructor, we can simply use the move constructor to use the resources of the temp one.





## Copy constructor

```c++
/* The first instance is created here (the param) */
/* this string is a temp value(rvalue) */
String apple(String("apple"));
String tomato(apple); 

String::String(const String &str)
{
    std::cout << "Copied!" << std::endl;
    this->m_size = str.m_size;

    /* Data copied in the heap which is bad thing*/
    /* So that we create two instances, but we need only one!*/
    this->m_data = new char[this->m_size];

    memcpy(this->m_data, str.m_data, this->m_size);
}

}
```

## Move constructor

```c++
Entity e(String("Shady")); 

String::String(String &&str)
{
    printf("Moved!\n");
    this->m_size = str.m_size;

    /* There is no data allocated in heap, we steal the data from the temo object (the parameter))*/
    this->m_data = str.m_data;
    
    str.m_size = 0;
    str.m_data = nullptr;
}
}
```
# Example2 Move assignment operator(=)
It is the same as the Move constructor. But with the move assignment operator we actually call a function.

```c++
String apple("apple");
String tomato; 

/* Move assignment operator (=)*/
tomato = std::move(apple);
}
