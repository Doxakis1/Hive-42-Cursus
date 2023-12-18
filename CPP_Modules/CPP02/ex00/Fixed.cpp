#include "Fixed.hpp"

const int Fixed::fixed_bits = 8;

Fixed::Fixed()
{   
    std::cout << "Default constructor called" << std::endl; 
    this->m_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->m_value = other.m_value;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this == &other)
        return *this;
    m_value = other.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return m_value;
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->m_value = raw;
}
