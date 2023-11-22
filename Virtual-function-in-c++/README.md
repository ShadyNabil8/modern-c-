
# Polymorphism and Virtal function in C++

An example of the polymerphism concept that describes the behavior of the program when treating a subclass as a superclass

Here we have a function called PrintClassName() in both classes. We need to know what the function of these two will be called using a base class instance in the case of treating this instance as a base class object and in the case of treating it as a subclass object.

## EntityClass

```cpp
void PrintClassName()
{
  std::cout << "EntityClass" << std::endl;
}
```
## PlayerClass

```cpp
void PrintClassName()
{
  std::cout << "PlayerClass" << std::endl;
}
```

## Program

```cpp
void print(Entity *e)
{
    e->PrintClassName();
}
```
Here if we pass a pointer to an ```Entity``` class opject, it is clear that the outpput will be "EntityClass". But if we pass a pointer to a ```Player``` class opject, the outpput will be "EntityClass" even if the function in this object prints "PlayerClass". We need the compiler to know that he should points to the function in the ```Player``` class even if we call it using pointer (e) which is of type ```Entity```but it poits to Player class data.

## Virtal function
```cpp
/* Virtual function must be defined in the class defination */
virtual void PrintClassName()
{
  std::cout << "EntityClass" << std::endl;
}
```

```cpp
int main()
{
  /* Here we must use pointer to make tha functionality */
  Entity* e = new Entity();
  Player* p = new Player();
  print(e); // output: EntityClass
  print(p); // output: PlayerClass 

  Entity e_o =  Entity();
  Player p_o =  Player();
  print(e_o); // output: EntityClass
  print(p_o); // output: EntityClass 
}
```

## Virtal function drawback
* Memory: We need to store a ```virtual table``` in the base class that maps to which function should be called.
* Time: In each call to this function, there will be a time to determine using the virtual table which function should be called.


# Pure virtual function in c++
* Interface is a class that has only abstract methods (pure virtual functions).
* Pure virual function is the same as abstract method in other languages like c# and java.
* Function defined in a base class as pure virtual function forces the other subclasses to implement this function.
* If a subclass has a pure v-function (from the base class), we cannot create an instance from this class (subclass) unless we implement this function.

```cpp
/* First, we create a class called Book and create a pure virtual fucntion like this*/
virtual void GetBookName() = 0;
```
```cpp
/* Second Entity inherite from the Book class and already Player inherite form the Entity */
class Entity : public book
```

| :memo: | Take note of this |
|---------------|:------------------------|
#### If we notice we will see that there are erros with every Entity and PLayer instances because we must implement the pure virtual function.

```cpp
Entity* e = new Entity(); // Error
Player* p = new Player(); //Error
```
Then we define this function in ```Player``` and ```Entity``` classes.

```cpp
/* Test our code */
void VPrint(Book *b)
{
    b->GetBookName();
}
int main()
{
  Entity* e = new Entity();
  Player* p = new Player();
  VPrint(e);
  VPrint(p);
}
```
