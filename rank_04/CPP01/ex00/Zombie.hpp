#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using	std::cout;
using	std::endl;
using	std::string;

class Zombie {
private:
	string _name;

public:
	Zombie();
	Zombie( string name );
	Zombie( const Zombie& source);
	~Zombie();
	Zombie& operator=( const Zombie& source );
	void announce( void );
};

// Standalone functions (not member functions, so not in class)
Zombie* newZombie( string name );
void randomChump( string name );

#endif