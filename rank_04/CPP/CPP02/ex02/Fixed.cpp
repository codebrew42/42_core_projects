#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
};


Fixed::Fixed(const Fixed& other) : _value(other._value) {
};

Fixed::Fixed( const int number ) {
	_value = number << _fractBits;
}


Fixed::Fixed( const float number ) {
	_value = roundf(number * ( 1 << _fractBits ));
}

Fixed& Fixed::operator=(const Fixed& other){
	if (_value != other._value)
	{
		setRawBits(other._value);
	}
	return *this;
}

Fixed::~Fixed() {

};

int	Fixed::getRawBits( void ) const {
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(_value) / (1 << _fractBits);
}

int	Fixed::toInt( void ) const {
	return _value >> _fractBits;
}

ostream& operator<<(ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result._value = _value + other._value;
	return result;
}	

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result._value = _value - other._value;
	return result;
}			

/* Formula | shift | why?
 (a × b) >> 8 | Right | Remove extra fractional bits
 */

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;			//1. local object in stack generated
	result._value = (static_cast<long>(_value) * other._value) >> _fractBits;
	return result;			//2. COPY it
}							//3. local result disappears

/* Formula | shift | why?
 (a << b) / 8 | left | Preserve precision
 */
Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result._value = (static_cast<long>(_value) << _fractBits) / other._value;
	return result;
}

// Increment/decrement operators
// Pre-increment: ++a (increment, then return)
Fixed& Fixed::operator++() {
	_value++;  // Increase by smallest epsilon (1/256)
	return *this;
}

// Post-increment: a++ (return old value, then increment)
Fixed Fixed::operator++(int) {
	Fixed temp(*this);  // Save current value
	_value++;
	return temp;  // Return old value
}

// Pre-decrement: --a (decrement, then return)
Fixed& Fixed::operator--() {
	_value--;  // Decrease by smallest epsilon (1/256)
	return *this;
}

// Post-decrement: a-- (return old value, then decrement)
Fixed Fixed::operator--(int) {
	Fixed temp(*this);  // Save current value
	_value--;
	return temp;  // Return old value
}

// Static min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

