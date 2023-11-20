#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook PhoneBook;

    while(PhoneBook.isActive())
    {
        PhoneBook.update();
        PhoneBook.getInput();
    }
    return (0);
}
