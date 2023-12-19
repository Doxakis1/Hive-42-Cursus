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

        static const Fixed &min(const Fixed &first, const Fixed& second);
        static const Fixed &max(const Fixed &first, const Fixed& second);
        static Fixed &min(Fixed &first, Fixed& second);
        static Fixed &max(Fixed &first, Fixed& second);
};

std::ostream&   operator<<(std::ostream& os, const Fixed &fixed);

#endif
