#include "Entity.hpp"

Entity::Entity()
{
}

Entity::~Entity()
{
}

Entity::Entity(const String& estr) : m_estr(estr) /* Here, the second instance is created */
{
    /* Note that m_estr(estr) calles the copy constructor in the String class.
     * So it taked an l value refrence meaning redundance.
     * The soulution is in the move semantics.
     * Instade of passing lvalue, we will pass rvalue.
    */
}

Entity::Entity(String&& estr) :m_estr(std::move(estr)) // equal m_estr((String&&)(estr))
{

}

void Entity::PrintName()
{
    m_estr.Print();
}