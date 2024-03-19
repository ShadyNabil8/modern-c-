#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
class String
{
public:
    String(const char *data)
    {
        printf("Created!\n");
        m_size = strlen(data);
        m_data = new char[m_size];
        memcpy(m_data, data, m_size);
    }

    ~String()
    {
        printf("String deleted!\n");
        delete m_data;
    }

    String(const String &other)
    {
        printf("Copied!\n");
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }

    String(String &&other)
    {
        printf("Moved!\n");
        m_size = other.m_size;
        m_data = other.m_data;

        other.m_size = 0;
        other.m_data = nullptr;
    }

    String &operator=(String &&other)
    {
        printf("Moved assignment! \n");
        m_size = other.m_size;
        m_data = other.m_data;

        other.m_size = 0;
        other.m_data = nullptr;

        return *this;
    }

    // For fun
    // String &operator=(String &other)
    // {
    //     printf("Copy assignment\n");
    //     m_size = other.m_size;
    //     m_data = other.m_data;

    //     other.m_size = 0;
    //     other.m_data = nullptr;

    //     return *this;
    // }

    void Print()
    {
        for (int i = 0; i < m_size; i++)
            printf("%c", m_data[i]);

        printf("%c", '\n');
    }

private:
    uint32_t m_size;
    char *m_data;
};

class Entity
{
public:
    Entity(const String &string) : m_string((String &&)string)
    {
    }

    void PrintName()
    {
        m_string.Print();
    }
    ~Entity()
    {
        printf("Entity deleted!\n");
    }

private:
    String m_string;
};
int main()
{
    String khaled = String("Khaled");
    String ahmed = String("Ahmed");
    khaled = std::move(ahmed);

    // For fun
    // String mostafa = String("Mostafa");
    // String shady = String("Shady");
    // mostafa = shady;
    //std::cin.get();
    return 0;
}
