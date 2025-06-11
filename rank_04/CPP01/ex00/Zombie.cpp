#include "Zombie.hpp"
#include <iostream>

//_name(name) : init list (non-static)
//Zombie::Zombie(string name) : _name(name) {};

Zombie::Zombie() {}

Zombie::Zombie( string name ) 
	: _name(name) {
		    std::cout << _name << " is created" << std::endl;
}

Zombie::Zombie( const Zombie &source)
	: _name(source._name) {}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

Zombie& Zombie::operator=( const Zombie& source )
{
	if (this != &source)
	{
		_name = source._name;
	}
	return *this;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

