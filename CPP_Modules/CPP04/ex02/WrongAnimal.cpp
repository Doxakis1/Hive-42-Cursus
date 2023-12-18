#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type(std::string("typelessWrongAnimal"))
{
  std::cout << "WrongAnimal no-parameter constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : m_type(type)
{
  std::cout << "WrongAnimal parameter constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
   *this = other;
   std::cout << "WrongAnimal copy constructor called" << std::endl;
  
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  m_type = other.m_type;
  return (*this);
}

WrongAnimal::~WrongAnimal()
{
   std::cout << " WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
  std::cout << m_type << " noises..." << std::endl;
}

std::string WrongAnimal::get_type(void) const
{
  return (m_type);
}