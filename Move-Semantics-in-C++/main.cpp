#include <iostream>
#include "String.hpp"
#include "Entity.hpp"
int main()
{
    /* ->->->->-> Move constructor and Move assignment operator(=) <-<-<-<-<- */
    /* ->->->->-> Both do the same thing, stealing the resourses from one object to another <-<-<-<-<- */

    /* The first idea (move constructor)*/

    /* The first instance is created here (the param) */
    /* this string is a temp value(rvalue) */
    // Entity e(String("Shady"));

    // e.PrintName();
    /*********************************************************/

    /* The second idea (Move assignment operator(=))*/

    // String apple("apple");
    // String tomato;
    // printf("Apple: ");
    // apple.Print();
    // printf("Tomato: ");
    // tomato.Print();
    // /* Move assignment operator (=)*/
    // tomato = std::move(apple);
    // printf("Apple: ");
    // apple.Print();
    // printf("Tomato: ");
    // tomato.Print();

    /*********************************************************/

    /* The Third idea (difference between move constructor and Move assignment operator)*/
    /* Both do the same thing, stealing the resourses from one object to another*/

    // String apple("apple");
    // // String tomato = apple; // Call copy constructor
    // // String tomato = std::move(apple); // Call move constructor
    // String tomato;
    // tomato = std::move(apple); // Call the assignment operator
    std::cin.get();
    return 0;
}
