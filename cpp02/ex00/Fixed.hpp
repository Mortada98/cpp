#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        // 1. Default Constructor
        Fixed(void);

        // 2. Copy Constructor
        Fixed(Fixed const & src);

        // 3. Copy Assignment Operator
        Fixed & operator=(Fixed const & rhs);

        // 4. Destructor
        ~Fixed(void);

        // Getters and Setters
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

};

#endif