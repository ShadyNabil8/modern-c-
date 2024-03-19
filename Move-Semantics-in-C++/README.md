
# Move Semantics in C++

The main idea is copying. How avoid additional copying of objects when we try to assign one object to another object. We we didn't just move the temp created object to the other object. Copying is heavy specially in the large objects.

**_Note:_** You need to see the rvalue and lvalue file to understand this file well

We have a class claaed ```String```

```cpp
class String
{
public:
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
        delete m_data;
    }
    void Print()
    {
        for (int i = 0; i < m_size; i++)
            printf("%c", m_data[i]);

        printf("%c", '\n');
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