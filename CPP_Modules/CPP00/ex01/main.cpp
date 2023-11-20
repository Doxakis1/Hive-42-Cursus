#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook pBook;

    while(pBook.isActive())
    {
        pBook.update();
        pBook.getInput();
    }
    return (0);
}
