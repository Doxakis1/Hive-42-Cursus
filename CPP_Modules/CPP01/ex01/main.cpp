#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name);

int main()
{
    Zombie *zombies = zombieHorde(5, "Bob");
    for (int i = 0; i < 5; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;
    return (42);
}
