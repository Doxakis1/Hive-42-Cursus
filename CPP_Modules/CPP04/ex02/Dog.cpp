#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
  std::cout << "Dog constructor called" << std::endl;
  this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy) , brain(new Brain(*copy.brain))
{
   std::cout << "Dog copy constructor called" << std::endl; 
}

Dog &Dog::operator=(const Dog &other)
{
  std::cout << "Dog copy assignment operator called" << this->brain << std::endl;
  this->m_type = other.m_type; //well any Dog should be already same
  *this->brain = *other.brain;
  return (*this);
}

Dog::~Dog()
{
   delete brain;
   std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
  std::cout << "Dog noises..." << std::endl;
}
std::string Dog::get_type(void) const
{
  return (this->m_type);
}

Brain &Dog::getBrain(void) const
{
  return (*this->brain);
}
