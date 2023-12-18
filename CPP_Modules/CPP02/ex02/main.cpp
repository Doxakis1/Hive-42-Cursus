#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.15f ) * Fixed( 4.2f ) );

    std::cout << a << std::endl;
    
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}
