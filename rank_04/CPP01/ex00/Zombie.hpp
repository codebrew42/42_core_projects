#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

using	std::string;

class Zombie {
private:
	string _name;

public:
	Zombie();
	~Zombie();
	Zombie* Zombie::NewZombie( string name );
};

#endif