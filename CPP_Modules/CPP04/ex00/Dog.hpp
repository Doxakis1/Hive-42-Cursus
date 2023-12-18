#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
  public:
      Dog();
      Dog(const Dog &copy);
      Dog &operator=(const Dog &other);
      ~Dog();

      void makeSound(void) const;
      std::string get_type(void) const;
};


#endif
