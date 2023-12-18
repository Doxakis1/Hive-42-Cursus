#include "Fixed.hpp"

const int Fixed::m_fixed_bits = 8;

Fixed::Fixed() : m_value(0) {}

Fixed::Fixed(const Fixed &fixed) : m_value(fixed.m_value) {}

Fixed::Fixed(const int from) : m_value(from << m_fixed_bits) {}

Fixed::Fixed(const float from) :
    m_value(roundf(from * float(1 << m_fixed_bits)))
{}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this == &fixed)
        return *this;
    m_value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator==(const Fixed &other) const
{
    return m_value == other.m_value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return !(*this == other);
}

bool Fixed::operator<(const Fixed &other) const
{
    return m_value < other.m_value;
}

bool Fixed::operator>(const Fixed &other) const
{
    return !(*this == other || *this < other);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return !(*this < other);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return *this < other || *this == other;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed   output(*this);

    output.m_value += other.m_value;
    return output;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed   output(*this);

    output.m_value -= other.m_value;
    return output;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed   output(*this);

    output.m_value = long(output.m_value) * long(other.m_value) >> m_fixed_bits;
    return output;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed   output(*this);

    output.m_value = (long(output.m_value) << m_fixed_bits) / long(other.m_value);
    return output;
}

Fixed& Fixed::operator++()
{
    return ++m_value, *this;
}

Fixed& Fixed::operator--()
{
    return --m_value, *this;
}

Fixed Fixed::operator++(int)
{
    Fixed   output(*this);

    return ++m_value, output;
}

Fixed Fixed::operator--(int)
{
    Fixed   output(*this);

    return --m_value, output;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed& second)
{
    if (first < second)
        return first;
    return second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed& second)
{
    if (first > second)
        return first;
    return second;
}

Fixed &Fixed::min(Fixed &first, Fixed& second)
{
    if (const_cast<Fixed &>(first) < const_cast<Fixed &>(second))
        return const_cast<Fixed &>(first);
    return const_cast<Fixed &>(second);
}

Fixed &Fixed::max(Fixed &first, Fixed& second)
{
    if (const_cast<Fixed &>(first) > const_cast<Fixed &>(second))
        return const_cast<Fixed &>(first);
    return const_cast<Fixed &>(second);
}

//the following code ideally I would have had in another file if allowed but alas

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
    // std::cout << fixed.toFloat(); basically
    return os << fixed.toFloat();
}