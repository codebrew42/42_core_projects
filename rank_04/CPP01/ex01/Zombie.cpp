#include "Zombie.hpp"

using	std::cout;
using	std::string;
using	std::endl;

Zombie::Zombie() {};

Zombie::~Zombie() {};

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};