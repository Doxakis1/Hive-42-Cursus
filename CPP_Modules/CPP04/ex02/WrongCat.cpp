#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
  std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy.m_type)
{
   *this = copy; 
   std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
  this->m_type = other.m_type; //well any Wrongcat should be already same 
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  return (*this);
}

WrongCat::~WrongCat()
{
   std::cout << " WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
  std::cout << m_type << " noises..." << std::endl;
}
std::string WrongCat::get_type(void) const
{
  return (this->m_type);
}
