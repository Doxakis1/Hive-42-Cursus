#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
  public:
      Cat();
      Cat(const Cat &copy);
      Cat &operator=(const Cat &other);
      ~Cat();
      void makeSound(void) const;
      std::string get_type(void) const;
};

#endif
