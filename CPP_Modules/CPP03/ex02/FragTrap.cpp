#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFlagTrap")
{
    m_hp = 100;
    m_mana = 100;
    m_ad = 30;
   std::cout << "FragTrap default no-parameter constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    m_hp = 100;
    m_mana = 100;
    m_ad = 30;
    std::cout << "FragTrap default parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.m_name)
{
    m_hp = other.m_hp;
    m_mana = other.m_mana;
    m_ad = other.m_ad;
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this == &other)
        return *this;
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    m_name = other.m_name;
    m_hp = other.m_hp;
    m_mana = other.m_mana;
    m_ad = other.m_ad;
    return *this;
}

void FragTrap::highFiveGuys() const
{
    std::cout << "FragTrap " << m_name << ": hive five fellas!" << std::endl;
}
