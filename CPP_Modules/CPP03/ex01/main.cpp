#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
  ScavTrap ScavTrapper("Mike");
  ScavTrapper.attack("Hans");
  ScavTrapper.takeDamage(30);
  ScavTrapper.beRepaired(12);
  ScavTrapper.guardGate();
  ScavTrapper.attack("Tuomas");
  ScavTrapper.takeDamage(90);
  ScavTrapper.beRepaired(100);
  ScavTrapper.attack("Dean");
  return (0);
}