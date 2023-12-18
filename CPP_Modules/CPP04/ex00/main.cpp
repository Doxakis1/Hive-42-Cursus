
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* dawg = new Dog();
    const Animal* kitty = new Cat();
    std::cout << dawg->get_type() << " " << std::endl;
    std::cout << kitty->get_type() << " " << std::endl;
    kitty->makeSound(); 
    dawg->makeSound();
    meta->makeSound();

    const WrongAnimal* failure = new WrongCat();
    std::cout << failure->get_type() << " " << std::endl;
    failure->makeSound();

    delete dawg;
    delete kitty;
    delete failure;
    delete meta;

return (0);
}