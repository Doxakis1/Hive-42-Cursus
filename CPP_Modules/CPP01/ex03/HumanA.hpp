#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
    private:
        std::string m_name;
        Weapon      &m_weapon;
    public:
        HumanA(HumanA &other);
        HumanA(std::string name, Weapon &weapon);
        void  attack() const;
};

#endif
