#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
    private:
        int                 m_value;
        static const int    fixed_bits;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed &other);
        ~Fixed();
        
        int     getRawBits() const;
        void    setRawBits(const int rawBits);
};

#endif
