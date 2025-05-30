#include "Zombie.hpp"

using	std::cout;
using	std::string;
using	std::endl;

Zombie::Zombie() {};

Zombie::~Zombie() {
	std::cout << "zombie deleted " << this->_name << std::endl; //added
};


string Zombie::getNameOfZombie()
{
	return _name;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};