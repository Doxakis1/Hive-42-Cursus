#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = std::string("Nameless");
    std::cout << "Made zombie " << this->name << " via normal constructor "<< std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Made zombie " << this->name << " via normal constructor "<< std::endl;
}

Zombie::Zombie(Zombie &other)
{
    this->name = other.name;
    std::cout << "Made zombie " << this->name << " via copy constructor "<< std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destroying zombie " << this->name << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
