
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <stdexcept>

int main(void)
{
  Animal *AnimalArray[6];

  for (int i = 0; i < 6; i++)
  {
    if (i % 2 == 0)
      AnimalArray[i] = new Dog();
    else
      AnimalArray[i] = new Cat();
  }

  
  std::cout << "\nDeep copy test!" << std::endl;
	Cat cat;
  try{
    cat.getBrain().setIdea(0, "I LOVE TUNA");
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
	Cat copyCat(cat);
  try{
    copyCat.getBrain().setIdea(0, "I ADMIRE TUNA");
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
	Cat assignCat = cat;
  try{
    assignCat.getBrain().setIdea(0, "I HATE TUNA");
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  try{
    std::cout << "Cat 1: " << cat.getBrain().getIdea(0) << std::endl;
	  std::cout << "Cat 2: " << copyCat.getBrain().getIdea(0) << std::endl;
	  std::cout << "Cat 3: " << assignCat.getBrain().getIdea(0) << std::endl;
	  std::cout << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  AnimalArray[0]->makeSound();
  AnimalArray[1]->makeSound();
  std::cout << std::endl;

  for (int i = 0; i < 6; i++)
    delete AnimalArray[i];

  return (0);
}
