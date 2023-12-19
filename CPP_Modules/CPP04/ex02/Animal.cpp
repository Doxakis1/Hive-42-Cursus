#include"Animal.hpp"

Animal::Animal() : m_type(std::string("typeless"))
{
  std::cout << "Animal no-parameter constructor called" << std::endl;
}

Animal::Animal(std::string type) : m_type(type)
{
  std::cout << "Animal parameter constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
   *this = other;
   std::cout << "Animal copy constructor called" << std::endl;
  
}

Animal &Animal::operator=(const Animal &other)
{
  std::cout << "Animal copy assignment operator called" << std::endl;
  m_type = other.m_type;
  return (*this);
}

Animal::~Animal()
{
   std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
  std::cout << m_type << " noises..." << std::endl;
}

std::string Animal::get_type(void) const
{
  return (m_type);
}