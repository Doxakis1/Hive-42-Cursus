#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
  std::cout << "Cat constructor called" << std::endl;
  this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy.m_type)
{
   *this = copy; 
   std::cout << "Cat copy constructor called" << std::endl;
   this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &other)
{
  this->m_type = other.m_type; //well any cat should be already same 
  delete this->brain;
  this->brain = new Brain(*other.brain);
  std::cout << "Cat copy assignment operator called" << std::endl;
  return (*this);
}

Cat::~Cat()
{
   delete brain;
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

Brain &Cat::getBrain(void) const
{
  return (*this->brain);
}
