#include <string>
#include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int main()
{
    //Zombie *zombie1 = newZombie("");
    Zombie *zombie1 = newZombie("Zombie 1");
    Zombie *zombie2 = zombie1;
    zombie1->announce();
    zombie2->announce();
    randomChump("randomChump");
    delete zombie1;
    return (EXIT_SUCCESS);
}
