#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "Entity.h"
#include <iostream>

class Player : public Entity
{
public:
    Player();
    ~Player();
    void PrintPlayer();
    void PrintClassName();

private:

};

#endif