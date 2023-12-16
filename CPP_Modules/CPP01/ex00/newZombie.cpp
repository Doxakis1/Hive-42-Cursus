#include <string>
#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    if (name == std::string(""))
        name = std::string("Nameless");
    return new Zombie(name);
}
