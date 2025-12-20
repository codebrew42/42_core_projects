#include "Fixed.hpp"
#include <cmath>

//Default constructor
Fixed::Fixed() : _value(0) {
	cout << "Default constructor called" << endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other)
{
	cout << "Copy constructor called" << endl;
	_value = other.getRawBits();
}

//Copy assignment operator overload
Fixed& Fixed::operator=( const Fixed& other )
{
	cout << "Copy assignment operator called" << endl;
	if (this != &other)
	{
		_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

int	Fixed::getRawBits( void ) const {
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
}

//Constructor: int to fixed-point
Fixed::Fixed( const int number ) {
	cout << "Int constructor called" << endl;
	_value = number << _fractBits;
}

//Constructor: float to fixed-point
Fixed::Fixed( const float number ) {
	cout << "Float constructor called" << endl;
	_value = roundf(number * (1 << _fractBits));
}

//Convert fixed-point to float
float Fixed::toFloat( void ) const {
	return static_cast<float>(_value) / (1 << _fractBits);
}

//Convert fixed-point to int
int Fixed::toInt( void ) const {
	return _value >> _fractBits;
}

//Insertion operator overload
	/*
		Fixed obj -> able to put into `cout`
		returning `ostream` makes chaining possible
	i.e.)
		Fixed a(3.5f);
		cout << a << b << c;

	actually compiler reads this as)
		operator<<(std::cout, a);
	*/
ostream& operator<<(ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
