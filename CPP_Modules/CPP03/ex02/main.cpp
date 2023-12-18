#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
  FragTrap FragTrapper("Mike");
  FragTrapper.attack("Hans");
  FragTrapper.takeDamage(40);
  FragTrapper.beRepaired(11);
  FragTrapper.highFiveGuys();
  FragTrapper.attack("Tuomas");
  FragTrapper.takeDamage(90);
  FragTrapper.beRepaired(100);
  FragTrapper.attack("Dean");
  
  return (0);
}