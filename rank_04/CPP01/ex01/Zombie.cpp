#include "Zombie.hpp"

using	std::cout;
using	std::string;
using	std::endl;

Zombie::Zombie() {};

Zombie::~Zombie() {
	std::cout << "zombie deleted " << this->_name << std::endl; //added
};


Zombie::Zombie( const Zombie& source )
	: _name(source._name) {};

Zombie& Zombie::operator=( const Zombie& source )
{
	if (this != &source)
		_name = source._name;
	return *this;
}

string Zombie::getNameOfZombie()
{
	return _name;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};