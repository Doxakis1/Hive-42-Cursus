#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::m_fixed_bits = 8;

Fixed::Fixed() : m_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : m_value(fixed.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int from) : m_value(from << m_fixed_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float from) :
    m_value(roundf(from * float(1 << m_fixed_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return *this;
    this->setRawBits(fixed.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return m_value;
}

void Fixed::setRawBits(const int raw)
{
    m_value = raw;
}

float Fixed::toFloat() const
{
    return float(m_value) / float(1 << m_fixed_bits);
}

int Fixed::toInt() const
{
    return m_value >> m_fixed_bits;
}

//the following code ideally I would have had in another file if allowed but alas

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    // std::cout << fixed.toFloat(); basically
    return os << fixed.toFloat();
}