#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
      Brain *brain;
  public:
      Dog();
      Dog(const Dog &copy);
      Dog &operator=(const Dog &other);
      ~Dog();
      void makeSound(void) const;
      std::string get_type(void) const;
      Brain &getBrain(void) const;
};

#endif