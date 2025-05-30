#include "Zombie.hpp"

void	randomChump(string name)
{
	// Create a zombie on the stack (not heap)
	Zombie z(name);
	z.announce();
	// Zombie will be automatically destroyed when function ends
}