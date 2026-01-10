#include "Fixed.hpp"

// --- Orthodox Canonical Form ---

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// --- New Constructors for Ex01 ---

// Int Constructor: Convert int to fixed point
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    // Shift left by 8 is the same as multiplying by 256
    this->_fixedPointValue = n << this->_fractionalBits;
}

// Float Constructor: Convert float to fixed point
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    // 1. Multiply by 256 (1 << 8)
    // 2. Round to nearest integer to keep precision
    this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

// --- Member Functions ---

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Convert back to float
float Fixed::toFloat(void) const {
    // Divide by 256 (1 << 8)
    return (float)this->_fixedPointValue / (float)(1 << this->_fractionalBits);
}

// Convert back to int
int Fixed::toInt(void) const {
    // Shift right by 8 to discard fractional bits
    return this->_fixedPointValue >> this->_fractionalBits;
}

// --- Stream Operator Overload ---

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    // We print the float representation
    o << i.toFloat();
    return o;
}