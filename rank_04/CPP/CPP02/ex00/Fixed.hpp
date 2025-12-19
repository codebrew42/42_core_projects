#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

using	std::cout;
using	std::endl;

class Fixed {
private:
	int					_value;		//store value of fixed-point
	static const int	_fractBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other); // `a=b;` will call this `a.operator=(b);`
	~Fixed();

	int		getRawBits() const;				// return raw value
	void	setRawBits(int const raw);		// set raw value
};

#endif