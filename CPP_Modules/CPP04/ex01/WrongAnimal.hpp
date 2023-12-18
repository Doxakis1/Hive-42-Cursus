#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal 
{
  protected:
      std::string m_type;

  public:
      WrongAnimal();
      WrongAnimal(std::string type);
      WrongAnimal(const WrongAnimal &copy);
      WrongAnimal &operator=(const WrongAnimal &other);
      virtual ~WrongAnimal();

      void makeSound(void) const;
      std::string get_type(void) const;
};

#endif