#include "Brain.hpp"
#include <stdexcept>

Brain::Brain()
{
  std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
  std::cout << "Brain copy constructor called" << std::endl;
  *this = copy;
  for (int i = 0; i < 100; i++)
    this->m_ideas[i] = copy.m_ideas[i];
}
Brain &Brain::operator=(const Brain &other)
{
  std::cout << "Brain copy assignment operator called" << std::endl;
  for (int i = 0; i < 100; i++)
    this->m_ideas[i] = other.m_ideas[i];
  return (*this);
}

Brain::~Brain()
{
  std::cout<< "Brain destructor being called" << std::endl;
}

std::string &Brain::getIdea(int index)
{
  if (index < 100 && index >= 0)
    return (this->m_ideas[index]);
  throw std::out_of_range(std::string("Out of bounds access"));
}

void Brain::setIdea(int index,  std::string idea)
{
  if (index < 100 && index >= 0)
    {
this->m_ideas[index] = idea;
return;
}
  throw std::out_of_range(std::string("Out of bounds access"));
}