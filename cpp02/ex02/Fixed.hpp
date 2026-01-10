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

        // Constructors
        Fixed(const int n);
        Fixed(const float n);

        // Getters/Setters
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        // Conversions
        float   toFloat(void) const;
        int     toInt(void) const;

        // --- EX02: Operator Overloading ---

        // 1. Comparison Operators
        bool    operator>(Fixed const & rhs) const;
        bool    operator<(Fixed const & rhs) const;
        bool    operator>=(Fixed const & rhs) const;
        bool    operator<=(Fixed const & rhs) const;
        bool    operator==(Fixed const & rhs) const;
        bool    operator!=(Fixed const & rhs) const;

        // 2. Arithmetic Operators
        Fixed   operator+(Fixed const & rhs) const;
        Fixed   operator-(Fixed const & rhs) const;
        Fixed   operator*(Fixed const & rhs) const;
        Fixed   operator/(Fixed const & rhs) const;

        // 3. Increment/Decrement Operators
        Fixed & operator++(void);       // Pre-increment
        Fixed   operator++(int);        // Post-increment
        Fixed & operator--(void);       // Pre-decrement
        Fixed   operator--(int);        // Post-decrement

        // 4. Static Min/Max Functions
        static Fixed & min(Fixed & a, Fixed & b);
        static const Fixed & min(Fixed const & a, Fixed const & b);
        static Fixed & max(Fixed & a, Fixed & b);
        static const Fixed & max(Fixed const & a, Fixed const & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif