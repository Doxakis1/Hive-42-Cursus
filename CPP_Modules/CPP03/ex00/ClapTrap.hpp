#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
    private:
        std::string     m_name;
        unsigned int    m_hp;
        unsigned int    m_mana;
        unsigned int    m_ad;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();

        ClapTrap&   operator=(const ClapTrap& other);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
    
};

#endif
