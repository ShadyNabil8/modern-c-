#ifndef BOOK_H
#define BOOK_H

#pragma once

#include <iostream>
class Book
{
public:
    Book();
    ~Book();

    /* Pure virtual function */
    virtual void GetBookName() = 0;

private:
};

#endif