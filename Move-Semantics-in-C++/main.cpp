#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
class String
{
public:
    String()
    {
        m_data = nullptr;
        m_size = 0;
    };

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
        if (!m_data)
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
        if (this != &other)
        {
            if (m_data != other.m_data)
            {
                printf("Moved assignment! \n");
                delete[] m_data;
                m_size = other.m_size;
                m_data = other.m_data;

                other.m_size = 0;
                other.m_data = nullptr;
            }
        }
        return *this;
    }

    // For fun
    // String &operator=(String &other)
    // {
    //     printf("Copy assignment\n");
    //     delete[] m_data;
    //     m_size = other.m_size;
    //     m_data = other.m_data;

    //     other.m_size = 0;
    //     other.m_data = nullptr;

    //     return *this;
    // }

    void Print()
    {
        if (m_data)
        {
            for (int i = 0; i < m_size; i++)
                printf("%c", m_data[i]);

            printf("%c", '\n');
        }
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
    String khaled;
    String ahmed = String("Ahmed");
    
    printf("Khalid: ");
    khaled.Print();
    printf("\n");
    printf("ahmed: ");
    ahmed.Print();

    khaled = std::move(ahmed);
    printf("MOVED\n");

    printf("Khalid: ");
    khaled.Print();
    printf("ahmed: ");
    printf("\n");
    ahmed.Print();

    // For fun
    // String mostafa = String("Mostafa");
    // String shady = String("Shady");
    // mostafa = shady;
    // std::cin.get();
    return 0;
}
