#include "MyString.h"

MyString::MyString()
{
}
MyString::MyString(const char *data)
{
    m_Buffer = new char[strlen(data) + 1];
    strcpy(m_Buffer, data);
}
MyString::~MyString()
{
    delete[] m_Buffer;
}

unsigned char MyString::GetSize()
{
    return this->m_Size;
}
char *MyString::GetBuffer()
{
    return this->m_Buffer;
}
std::ostream &operator<<(std::ostream &stream, const MyString &string)
{
    stream << string.m_Buffer;
    return stream;
}

char &MyString::operator[](unsigned int x)
{
    return m_Buffer[x];
}

// void MyString::operator=(const MyString &string)
// {
//     this->m_Size = string.m_Size;
//     this->m_Buffer = new char[m_Size + 1];
//     strcpy(this->m_Buffer, string.m_Buffer);
// }

MyString::MyString(const MyString &string)
{
    std::cout << "Copied!! " << std::endl;
    this->m_Size = string.m_Size;
    this->m_Buffer = new char[m_Size + 1];
    strcpy(this->m_Buffer, string.m_Buffer);
}