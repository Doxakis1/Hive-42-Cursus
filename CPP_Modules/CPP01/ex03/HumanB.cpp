#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL) {}

void HumanB::attack() const
{
    if (!this->m_weapon)
        return ;
    std::cout << this->m_name << " attacks with their " << this->m_weapon->getType();
    std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->m_weapon = &weapon;
}
