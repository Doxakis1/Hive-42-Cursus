#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    m_type = type;
}

const std::string &Weapon::getType() const
{
    return m_type;
}

void Weapon::setType(std::string newType)
{
    m_type = newType;
}
