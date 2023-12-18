#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    std::cout << "Getting the rawBits of a:" << std::endl <<  a.getRawBits() << std::endl;
    std::cout << "Getting the rawBits of b:" << b.getRawBits() << std::endl;
    std::cout << "Getting the rawBits of c:" << c.getRawBits() << std::endl;

    return 42;
}
