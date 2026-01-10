#include "Fixed.hpp"

// 1. Default Constructor
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// 2. Copy Constructor
Fixed::Fixed(Fixed const & src) {
    std::cout << "Copy constructor called" << std::endl;
    // It's best practice to use the assignment operator here
    // *this = src; 
    
    // However, the subject output example implies getRawBits is NOT called 
    // during the copy constructor, but IS called during assignment.
    // To match the output perfectly, we might just copy the value directly:
    this->_fixedPointValue = src.getRawBits(); 
}

// 3. Copy Assignment Operator
Fixed & Fixed::operator=(Fixed const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;

    // Self-assignment check (standard safety)
    if (this != &rhs) {
        // According to the subject output example, getRawBits is called here [cite: 172]
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

// 4. Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}