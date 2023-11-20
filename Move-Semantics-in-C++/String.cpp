#include "String.hpp"

String::String()
{
    this->m_data = nullptr;
}

String::String(const char *str)
{
    std::cout << "Created!" << std::endl;
    this->m_size = strlen(str);
    this->m_data = new char[this->m_size];
    memcpy(this->m_data, str, this->m_size);
}
String::String(const String &str)
{
    std::cout << "Copied!" << std::endl;
    this->m_size = str.m_size;

    /* Data copied in the heap which is bad thing*/
    this->m_data = new char[this->m_size];

    memcpy(this->m_data, str.m_data, this->m_size);
}
void String::Print()
{
    if (m_data != nullptr)
    {
        for (int i = 0; i < m_size; i++)
            printf("%c", m_data[i]);
    }
    printf("\n");
}

String::String(String &&str)
{
    printf("Moved!\n");
    this->m_size = str.m_size;

    /* Here instade of deep copy(copiny all data block)
     * we copied only the pointer that points to the temp data.
     * But temp data will be deleted!!(data that we point to!!) => so the move constructor should not end here
     * see what will be done
     */
    this->m_data = str.m_data;

    /**
     * After coping the pointer of the temp data to our string in Entity obj,
     * assigning the temp data pointer to null solve the problrm
     * becaise deleting null pointer will not make any thing bad.
     */
    str.m_size = 0;
    str.m_data = nullptr;
}

String &String::operator=(String &&str)
{
    /* Make sure that the two instances are different.
     * Otherwise the move is useless.
     */
    if (this != &str)
    {
        printf("Moved=\n");

        /* Because m_data may already contain old data */
        delete[] m_data;

        this->m_size = str.m_size;
        this->m_data = str.m_data;
        str.m_data = nullptr;
    }
    return *this;
}
String::~String()
{
    printf("Deleted!\n");
    delete[] m_data;
}