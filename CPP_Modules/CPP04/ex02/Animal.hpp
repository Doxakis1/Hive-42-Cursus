#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal 
{
  protected:
      std::string m_type;

  public:
      Animal();
      Animal(std::string type);
      Animal(const Animal &copy);
      Animal &operator=(const Animal &other);
      virtual ~Animal();

      virtual void makeSound(void) const = 0;
      std::string get_type(void) const;
};


#endif