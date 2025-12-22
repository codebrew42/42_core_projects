#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

using	std::ostream;
class Fixed{
private:
	int					_value;
	static const int	_fractBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	/*ex00*/
	int	getRawBits( void ) const;
	void setRawBits( int const raw);

	/*ex01?*/
	Fixed(const int number);
	Fixed(const float number);
	float toFloat(void) const;
	int toInt(void) const;

	/*ex02*/
	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment/decrement operators
	Fixed& operator++();		// pre-increment (++a)
	Fixed operator++(int);		// post-increment (a++)
	Fixed& operator--();		// pre-decrement (--a)
	Fixed operator--(int);		// post-decrement (a--)

	// Static min/max functions
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif