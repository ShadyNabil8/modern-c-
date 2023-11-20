#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include <string.h>
#include "String.hpp"
class Entity
{
public:
    Entity();
    Entity(const String &estr);
    Entity(String&& estr);
    ~Entity();
    void PrintName();
    String m_estr;

private:

};

#endif