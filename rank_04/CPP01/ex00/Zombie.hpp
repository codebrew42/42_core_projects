#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

using	std::string;

class Zombie {
private:
	string _name;

public:
	Zombie( string name );
	~Zombie();
	void announce( void );
};

// Standalone functions (not member functions, so not in class)
Zombie* newZombie( string name );
void randomChump( string name );

#endif