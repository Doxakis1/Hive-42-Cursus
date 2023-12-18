#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
      Brain *brain;
  public:
      Cat();
      Cat(const Cat &copy);
      Cat &operator=(const Cat &other);
      ~Cat();
      void makeSound(void) const;
      std::string get_type(void) const;
      Brain &getBrain(void) const;
};

#endif