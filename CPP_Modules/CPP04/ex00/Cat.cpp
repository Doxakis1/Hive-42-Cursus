#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy.m_type)
{
   *this = copy; 
   std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
  this->m_type = other.m_type; //well any cat should be already same 
  std::cout << "Cat copy assignment operator called" << std::endl;
  return (*this);
}

Cat::~Cat()
{
   std::cout << " Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
  std::cout << m_type << " noises..." << std::endl;
}
std::string Cat::get_type(void) const
{
  return (this->m_type);
}
