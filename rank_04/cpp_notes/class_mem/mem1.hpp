#ifndef MEM_HPP
#define MEM_HPP

#include <string>
#include <iostream>

using	std::string;

class Zombie
{
private:
	std::string	_characteristic;
	int			_age;
	double		_height;
	double		_weight;

public:
	void	displayCharacteristic();
	string	getUserInputString(string message);
	string	getCharacteristic();
	// Declare the constructor (without implementation {})
	Zombie(std::string name);
	// Declare the destructor
	~Zombie();
}
;



#endif