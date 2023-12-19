#include "Brain.hpp"

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
  return (this->m_ideas[index]);
}

void Brain::setIdea(int index,  std::string idea)
{
  this->m_ideas[index] = idea;
}