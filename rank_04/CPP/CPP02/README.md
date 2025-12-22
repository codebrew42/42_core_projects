# Requirements

## Excercise 00
- create a class represents a fixed-point nbr
	- private members
		- integer to store fixed-point nbr value
		- static constant integer to store the number of fractional bits = 8

	- public members
		- default contstructor that inits the fixed-point nbr value to 0
		- copy constructor
		- copy assignment operator overload
		- destructor
		- member fun `int getRawBits( void ) const;`
			- returns the raw val of fixed-point value
		- member fun `int setRawBits( int const raw ) const;`
			- sets the raw valud of fixed-point value

## Exercise 01
- create a class represents a fixed-point nbr
	- public members and functions
		- [x] a constructor that takes `constant int` as a param
			- converts it into fixed-point value
			- fractional bits = 8
		- [x] a constructor that takes `constant floating-point nbr` as a param
			- converts it into fixed-point value
			- fractional bits = 8
		- [x]`fun float toFloat( void ) const;`
			- converts fixed-point val to floating-point value
		- [x]`fun int toInt( void ) const;`
			- converts fixed-point val to int value
	- add this to the class
		- [x]`An overload of the insertion («) operator`
		- inserts floating-point representation into output stream obj passed as a param

## Exercise 02
- add public member functions to the class to overload those operators:
	- [x] The 6 comparison operators: >, <, >=, <=, ==, and !=.
	- [x] The 4 arithmetic operators: +, -, *, and /.
	- [] The 4 in-/decrement : pre-increment and post-increment, pre-decrement and post-decrement operators,
		- which will increase or decrease the fixed-point value by the smallest representable ε, such that 1 + ε > 1
- add 4 public overloaded member functions to the class : statc member functions
	- [] `min` that takes two references to fixed-point numbers as parameters
		- returns a reference to the smallest one.
	- [] `min` that takes two references to constant fixed-point numbers as parameters
		- returns a reference to the smallest one.
	- [] `max` that takes two references to fixed-point numbers as parameters
		- returns a reference to the greatest one.
	- [] `max` that takes two references to constant fixed-point numbers as parameters, 
		- returns a reference to the greatest one.