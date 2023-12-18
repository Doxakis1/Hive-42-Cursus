#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
# include <iostream>

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
        int     getRawBits() const;
        void    setRawBits(const int raw);
        float   toFloat() const;
        int     toInt() const;
};

std::ostream&   operator <<(std::ostream& os, const Fixed &fixed);

#endif
