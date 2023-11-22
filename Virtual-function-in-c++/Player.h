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

    /**
     * The override keyword helps us by preventing us from making the mistake of writing
     * a function name that does not match the name of the entity class because there will be an error.
     * Also, prevent us from overriding a function that is not virtual because there will be an error.
     */
    void PrintClassName() override
    {
        std::cout << "PlayerClass" << std::endl;
    }

    void GetBookName() override
    {
        std::cout << "PlayerBook" << std::endl;
    }

private:
};

#endif