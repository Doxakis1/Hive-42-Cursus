#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name(std::string("Default")), m_hp(10), m_mana(10), m_ad(0)
{
    std::cout << "ClapTrap no-parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hp(10), m_mana(10), m_ad(0)
{
    std::cout << "ClapTrap parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : m_name(other.m_name), m_hp(other.m_hp), m_mana(other.m_mana), m_ad(other.m_ad)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    
    if (this == &other)
        return *this;
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    m_name = other.m_name;
    m_hp = other.m_hp;
    m_mana = other.m_mana;
    m_ad = other.m_ad;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (m_hp == 0)
    {
        std::cout << "Dead ClapTraps tell no tales" << std::endl;
        return;
    }
    if (m_mana < 1) // for now 1 mana is needed to attack
    {
        std::cout << "Manaless ClapTraps tell no tales" << std::endl;
        return;
    }
    m_mana -= 1; //I do -= 1 because I might want to change the attack cost at some point  
    std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_ad << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (m_hp == 0)
    {
        std::cout << "Dead ClapTraps take no dmg" << std::endl;
        return;
    }
    if (m_hp <= amount)
        m_hp = 0;
    else
        m_hp -= amount;
    std::cout << "ClapTrap " << m_name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_hp == 0)
    {
        std::cout << "Dead ClapTraps cannot be repaired" << std::endl;
        return;
    }
    if (m_mana == 0)
    {
        std::cout << "Manaless ClapTraps cannot be repaired" << std::endl;
        return;
    }
    m_mana--;
    unsigned int holder = m_hp;
    m_hp += amount;
    if (m_hp < holder)
        m_hp = -1;
    std::cout << "ClapTrap " << m_name << " repairs itself with " << amount << " points" << std::endl;
}
