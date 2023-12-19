#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(std::string("DefaultScavtrap"))
{
    m_hp = 100;
    m_mana = 50;
    m_ad = 20;
    std::cout << "ScavTrap no-parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    m_hp = 100;
    m_mana = 50;
    m_ad = 20;
    std::cout << "ScavTrap default parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.m_name)
{
    m_hp = other.m_hp;
    m_mana = other.m_mana;
    m_ad = other.m_ad;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this == &other)
        return *this;
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    m_name = other.m_name;
    m_hp = other.m_hp;
    m_mana = other.m_mana;
    m_ad = other.m_ad;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (m_hp == 0)
    {
        std::cout << "Dead ScavTrap tell no tales" << std::endl;
        return;
    }
    if (m_mana < 1) // for now 1 mana is needed to attack
    {
        std::cout << "Manaless ScavTrap tell no tales" << std::endl;
        return;
    }
    m_mana -= 1; //I do -= 1 because I might want to change the attack cost at some point  
    std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_ad << " points of damage!" << std::endl;

}

void ScavTrap::guardGate() const
{
    if (m_hp == 0)
    {
        std::cout << "Dead ScavTrap guards no gates" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode" << std::endl;
}
