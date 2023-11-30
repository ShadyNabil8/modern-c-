#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once

#include <string.h>
#include <iostream>
class MyString
{
private:
    char *m_Buffer;
    unsigned char m_Size;

public:
    MyString();
    MyString(const char *data);
    ~MyString();
    friend std::ostream &operator<<(std::ostream &stream, const MyString &string);
    char &operator[](unsigned int x);
    void operator=(const MyString &string);
    unsigned char GetSize();
    char *GetBuffer();
    //friend void MyString::operator=(const MyString &string);
    MyString(const MyString& string);
};

#endif