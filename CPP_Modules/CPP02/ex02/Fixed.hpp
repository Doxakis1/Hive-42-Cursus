#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
# include <iostream>
# include <cmath>

class Fixed {
    private:
        int                 m_value;
        static const int    m_fixed_bits;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int from);
        Fixed(const float from);
        Fixed& operator=(const Fixed &fixed);
        ~Fixed();
        
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;

        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;

        Fixed&  operator++();
        Fixed&  operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);

        int     getRawBits() const;
        void    setRawBits(const int raw);
        float   toFloat() const;
        int     toInt() const;

        static const Fixed &min(const Fixed &lhs, const Fixed& rhs);
        static const Fixed &max(const Fixed &lhs, const Fixed& rhs);
        static Fixed &min(Fixed &lhs, Fixed& rhs);
        static Fixed &max(Fixed &lhs, Fixed& rhs);
};

std::ostream&   operator<<(std::ostream& os, const Fixed &fixed);

#endif
