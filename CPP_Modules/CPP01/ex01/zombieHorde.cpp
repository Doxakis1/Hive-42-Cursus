#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
    if ( n <= 0)
        return (NULL);
    Zombie *zombies = new Zombie[n];
    for (int i = 0; i < n; i++)
    {
        zombies[i].changeName(name);
    }
    return (zombies);
}
