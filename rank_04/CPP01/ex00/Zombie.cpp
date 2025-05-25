#include "Zombie.hpp"
#include <iostream>

using std::string;

//_name(name) : init list (non-static)
//Zombie::Zombie(string name) : _name(name) {};

Zombie::Zombie( string name ) {
	_name = name;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

