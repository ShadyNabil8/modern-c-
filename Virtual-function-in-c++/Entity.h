#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include <iostream>
#include "Book.h"
class Entity : public Book
{
public:
    Entity();
    ~Entity();
    void PrintEnity();

    /* Virtual function must be defined in the class defination */
    virtual void PrintClassName()
    {
        std::cout << "EntityClass" << std::endl;
    }

    void GetBookName() override
    {
        std::cout << "EntityBook" << std::endl;
    }

private:
};

#endif