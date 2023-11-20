#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook pBook;

    while(pBook.isActive())
    {
        pBook.getInput();
        pBook.update();
    }
    return (0);
}
