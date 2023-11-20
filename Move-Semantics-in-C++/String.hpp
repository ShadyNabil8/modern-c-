#ifndef STRING_H
#define STRING_H

#pragma once

#include <stdint.h>
#include <iostream>
#include <string.h>

class String
{
public:
    
    String();
    String(const char *string);
    String(const String &str);
    String(String &&str);
    String& operator=(String&& string);
    void Print();
    ~String();

private:
    uint32_t m_size;
    char *m_data;
};

#endif