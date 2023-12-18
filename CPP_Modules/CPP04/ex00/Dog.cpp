#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy.m_type)
{
   *this = copy; 
   std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
  this->m_type = other.m_type; //well any Dog should be already same 
  std::cout << "Dog copy assignment operator called" << std::endl;
  return (*this);
}

Dog::~Dog()
{
   std::cout << " Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
  std::cout << m_type << " noises..." << std::endl;
}
std::string Dog::get_type(void) const
{
  return (this->m_type);
}