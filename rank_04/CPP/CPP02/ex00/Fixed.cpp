#include "Fixed.hpp"

//Default constructor
Fixed::Fixed() {
#ifdef DEBUG
	cout << "[DEBUG] Default constructor called" << endl;
#endif
	_value = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed& other)
{
#ifdef DEBUG
	cout << "[DEBUG] Copy constructor called" << endl;
#endif
	_value = other.getRawBits();
}

//Copy assignment operator overload
Fixed& Fixed::operator=( const Fixed& other )
{
#ifdef DEBUG
	cout << "[DEBUG] Copy assignment operator called" << endl;
#endif
	if (this != &other)
	{
		_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
#ifdef DEBUG
	cout << "[DEBUG] Destructor called" << endl;
#endif
}

int	Fixed::getRawBits( void ) const {
#ifdef DEBUG
	cout << "[DEBUG] getRawBits member function called" << endl;
#endif
	return _value;
}

void Fixed::setRawBits( int const raw ) {
#ifdef DEBUG
	cout << "[DEBUG] setRawBits member function called" << endl;
#endif
	_value = raw;
}