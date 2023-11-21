
# Polymorphism and Virtal function in C++

An example on polymerphism concept that descrips the behavour of the program whentreating a sub class as a super class.

Here we have a function called PrintClassName() in both classes, we need to know what function of these two will be called using a base class instance in the case of treating this instance as base class object and in case of treating it as sub class object

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