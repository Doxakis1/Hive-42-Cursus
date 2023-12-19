#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
  std::cout << "Cat constructor called" << std::endl;
  this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
   std::cout << "Cat copy constructor called" << std::endl;
   this->brain = NULL;
   *this = copy; 
}

Cat &Cat::operator=(const Cat &other)
{
  std::cout << "Cat copy assignment operator called" << this->brain << std::endl;
  this->m_type = other.m_type; //well any cat should be already same
  if (this->brain)
    delete this->brain;
  this->brain = new Brain(*other.brain); // this is done because we want a copy of the other brain but not just a copy of the pointer 
  return (*this);
}

Cat::~Cat()
{
   delete brain;
   std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
  std::cout << "Cat noises..." << std::endl;
}
std::string Cat::get_type(void) const
{
  return (this->m_type);
}

Brain &Cat::getBrain(void) const
{
  return (*this->brain);
}
