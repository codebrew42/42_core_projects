#include "Zombie.hpp"

//just function in file => is expected

Zombie* newZombie( string name )
{
	//creating on heap 
	Zombie* z = new Zombie(name);
	return z;
};
