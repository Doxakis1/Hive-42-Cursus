#include "Brain.hpp"

Brain::Brain()
{
  std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
  std::cout << "Brain copy constructor called" << std::endl;
  *this = copy;
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
  static std::string error_message("Out of array bounds!");
  if (index < 100 && index >= 0)
    return (this->m_ideas[index]);
  return error_message;
}

void Brain::setIdea(int index,  std::string idea)
{
  if (index < 100 && index >= 0)
    this->m_ideas[index] = idea;
}