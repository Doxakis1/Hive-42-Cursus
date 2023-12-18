#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
      WrongCat();
      WrongCat(const WrongCat &copy);
      WrongCat &operator=(const WrongCat &other);
      ~WrongCat();

      void makeSound(void) const;
      std::string get_type(void) const;
};

#endif
