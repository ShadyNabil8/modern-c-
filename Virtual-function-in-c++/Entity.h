#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include <iostream>
class Entity
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

private:
};

#endif