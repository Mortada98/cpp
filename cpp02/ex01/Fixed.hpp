#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        // Orthodox Canonical Form
        Fixed(void);
        Fixed(Fixed const & src);
        Fixed & operator=(Fixed const & rhs);
        ~Fixed(void);

        // New Constructors for Ex01
        Fixed(const int n);
        Fixed(const float n);

        // Getters/Setters (from Ex00)
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        // Conversion Methods
        float   toFloat(void) const;
        int     toInt(void) const;

};

// Global stream insertion operator overload
std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif