
# Move Semantics in C++

The main idea is copying. How avoid additional copying of objects when we try to assign one object to another object. We we didn't just move the temp created object to the other object. Copying is heavy specially in the large objects.

**_Note:_** You need to see the rvalue and lvalue file to understand this file well

We have a class claaed ```String```

```cpp
class String
{
public:
    String()
    {
        m_data = nullptr;
        m_size = 0;
    };

    String(const char *data)
    {
        printf("Created!\n");
        m_size = strlen(data);
        m_data = new char[m_size];
        memcpy(m_data, data, m_size);
    }
    ~String()
    {
        printf("String deleted!\n");
        if (!m_data)
            delete m_data;
    }
    void Print()
    {
        if (!m_data)
        {
            for (int i = 0; i < m_size; i++)
                printf("%c", m_data[i]);

            printf("%c", '\n');
        }
    }
private:
    uint32_t m_size;
    char *m_data;
};
```

We have a class claaed ```Entity```

```cpp
class Entity
{
public:
    Entity(const String &string) : m_string(string)
    {
    }
    void PrintName()
    {
        m_string.Print();
    }
    ~Entity()
    {
        printf("Entity deleted!\n");
    }

private:
    String m_string;
};
```

As we can see that the ```Entity``` class has a member of type ```String```. And in the Entity constructor we try to ```copy``` the string passed as param to the member string.

```cpp
Entity(const String &string) : m_string(string)
{
}
```

To make this copying work, we need to adda ```copy constructor``` in the String class to create a String from another String.

```cpp
String(const String &other)
{
    /* Remember if there is no const keyword in the param, this constructor will only take a lvalue (see the file of the rvalue and lvalue )*/
    printf("Copied!\n");
    m_size = other.m_size;
    m_data = new char[m_size];
    memcpy(m_data, other.m_data, m_size);
}
```

But the idea is do we need to copy the String object to the member one? Why we don't move the temp created String to the member string.

```cpp
Entity e = Entity(String("Ahmed"));
```

This line of code will create ```2``` String objects and ```1``` Entity object. The first String object will be created temoporarily in the main function. i.e., the compilere will make somthing like this.

```cpp
String temp = String("Ahmed"); // The first String obj
Entity e = Entity(temp);
```

**_NOTE:_** The compiler will nake something like this and then delete the temporary created object before (not after) the end of the scope (acually it will be deleted when the copying is done, This is very important. This temp created object will not last after copying, the compiler will delete it because there is no need to it anymore). We will not do this ourselves, we shouldn't unledd the ```temp``` will not be deleted execpt at the end of the scope.

To prove that the temp object will be deleted after copying, we will add this to susbend the program form termination.

```cpp
Entity e = Entity(String("Ahmed"));
std::cin.get();
```

the output will be

```
Created!
Copied!
String deleted!
```

As we can see the temp object is deleted after copying and befor the scope ended. This is the idea of this file. Why we jest do not use data inside this ```temp``` object rather than copying this data again inside the ```Entity``` object.

The second ```String``` object will be created to be a member in the ```Entity``` class. The constructor in the ```Entity``` class will use the copy constructor in the String class to make this copy.

```cpp
Entity(const String &string) : m_string(string)
{
    // m_string(string) will call the Copy constructor in the String class String(const String &other)   
}
```

So the output of the code will be

```
Created!
Copied!
Entity deleted!
String deleted!
String deleted!
```

We can escape from this copying operation by moving the temporary created object to the member object in the Entity class. But first we need to add a ```move constructor``` in the ```String``` class.

```cpp
String(String &&other)
{
    printf("Moved!\n");
    m_size = other.m_size;
    m_data = other.m_data; // We copy the pointer itself
    other.m_size = 0;
    other.m_data = nullptr;
}
```

As we see we make a shallow copy, we take the size of the temporariy created object and also the pointet of its data and then reset its data to ```0``` and ```nullptr``` because when it is deleted after the moving, its pointer (m_data) will also be deleted, bu we used it already in ```m_data = other.m_data;```. So to avoid deleting this pointer, we will make it to null and when it is deleted, there is no problem.

But untill now the problem of copyinf still exists because in this Entity constructor, the copy constructor (not the move constructor) in String calss is called.

```cpp
Entity(const String &string) : m_string(string) // Call copy constructor
{
}
```

We need to do and implicit casting to make it call the move constructor.

```cpp
Entity(const String &string) : m_string((String &&)string)
{
}
```

the output of this code will be

```cpp
Entity e = Entity(String("Ahmed"));
```

```
Created!
Moved!
String deleted!
Entity deleted!
String deleted!
```

If we make thing like this

```cpp
String khaled = String("Khaled");
String Ahmed(khaled);
```

In the second line, the copy constructor will be called. If we want to call the move constructor we will do this

```cpp
String Ahmed((String &&)khaled);
```

This casting maked khaled as rvalue and then the move constructor will be called. But the best thing is di this

```cpp
String Ahmed(std::move(khaled));
```

```std::move()``` itself doesn't release any resources. It's important to understand that std::move() is simply a cast that converts its argument into an rvalue reference.

It's the move constructor (or move assignment operator as we will se later) that actually releases the resources of an object and transfers them to another object. When you use std::move(), you're signaling to the compiler that it should call the move constructor (or move assignment operator) if one is available

If we thing like this

```cpp
String khaled = String("Khaled");
String ahmed = String("Ahmed");
khaled = std::move(ahmed);
```

In this case we try to ```move``` an ```existing``` object to anther ```existing``` object using move assignment operator ```=```. So we need to overload this operator inside the Sting class.

```cpp
String &operator=(String &&other)
{
    printf("Moved assignment! \n");
    m_size = other.m_size;
    m_data = other.m_data;
    other.m_size = 0;
    other.m_data = nullptr;
    return *this;
}
```

```
Created!
Created!
Moved assignment! 
String deleted!
String deleted!
```

**_Remember:_** std::move() is a tool for enabling move semantics, but it doesn't directly release any resources. The release of resources typically happens within the move assignment operator (or move constructor) of the class, which is called after using std::move() in an assignment.

You can say "Whay I am using std::move to do this while I can implement a copy assignment operator overload and use it without std::move and implement the same functionality of moving like this code"

```cpp
String &operator=(String &other)
{
    printf("Copy assignment\n");
    m_size = other.m_size;
    m_data = other.m_data;
    other.m_size = 0;
    other.m_data = nullptr;
    return *this;
}```

```cpp
String mostafa = String("Mostafa");
String shady = String("Shady");
mostafa = shady;
```

```
Created!
Created!
Copy assignment
String deleted!
String deleted!
```

while technically possible, implementing the copy assignment operator to behave like a move assignment operator is unconventional and can lead to confusion and unexpected behavior. It's better to follow the standard conventions for copy and move semantics, which involve distinguishing between copy and move operations using appropriate language features (std::move() for move semantics) and providing separate implementations for copy and move assignment operators.

If we make something like this, we will make something very bad as you can imagine .

```cpp
ahmed = std::move(ahmed);
```

To avoid this bad use we can rewite the move assignment operator overloading to be like this

```cpp
String &operator=(String &&other)
{
    if (this != &other)
    {
        /* If the two object was not the same but the data inside them are the same, there is no need to copy */
        if (m_data != other.m_data)
        {
            printf("Moved assignment! \n");
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_size = 0;
            other.m_data = nullptr;
        }
    }
    return *this;
}
```

### The final example to see

```cpp
String khaled;
String ahmed = String("Ahmed");

printf("Khalid: ");
khaled.Print();
printf("\n");
printf("ahmed: ");
ahmed.Print();

khaled = std::move(ahmed);
printf("MOVED\n");

printf("Khalid: ");
khaled.Print();
printf("ahmed: ");
printf("\n");
ahmed.Print();
```

```
Created!
Khalid: 
ahmed: Ahmed
Moved assignment! 
MOVED
Khalid: Ahmed
ahmed: 
String deleted!
String deleted!
```
