#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap clapTrap1("Mike");
  clapTrap1.attack("Hans");
  clapTrap1.takeDamage(3);
  clapTrap1.beRepaired(1);
  clapTrap1.attack("Tuomas");
  clapTrap1.beRepaired(1);
  clapTrap1.takeDamage(9);
  clapTrap1.attack("Dean");
  clapTrap1.beRepaired(10);
  return (0);
}
