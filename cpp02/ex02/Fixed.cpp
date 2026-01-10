#include "Fixed.hpp"

// --- Orthodox Canonical Form & Constructors ---

Fixed::Fixed(void) : _fixedPointValue(0) {}

Fixed::Fixed(Fixed const & src) { *this = src; }

Fixed & Fixed::operator=(Fixed const & rhs) {
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const int n) {
    this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(const float n) {
    this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

// --- Basic Member Functions ---

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }
float Fixed::toFloat(void) const { return (float)this->_fixedPointValue / (float)(1 << this->_fractionalBits); }
int Fixed::toInt(void) const { return this->_fixedPointValue >> this->_fractionalBits; }

// --- 1. Comparison Operators ---

bool Fixed::operator>(Fixed const & rhs) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const {
    return this->getRawBits() != rhs.getRawBits();
}

// --- 2. Arithmetic Operators ---

Fixed Fixed::operator+(Fixed const & rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

// --- 3. Increment/Decrement Operators ---

// Pre-increment (++i)
Fixed & Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

// Post-increment (i++)
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

// Pre-decrement (--i)
Fixed & Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

// Post-decrement (i--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// --- 4. Static Min/Max Functions (Using If-Else) ---

Fixed & Fixed::min(Fixed & a, Fixed & b) {
    if (a < b)
        return a;
    return b;
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b) {
    if (a < b)
        return a;
    return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
    if (a > b)
        return a;
    return b;
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b) {
    if (a > b)
        return a;
    return b;
}

// --- Stream Overload ---
std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}