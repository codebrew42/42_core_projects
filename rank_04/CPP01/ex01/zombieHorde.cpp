
#include "Zombie.hpp"

using	std::string;
using	std::cout;

void		Zombie::setName(string name)
{
	_name = name;
}

Zombie*		zombieHorde( int N, std::string name )
{
	Zombie *z = new Zombie[N];

	int		i = -1;
	while (++i < N)
	{
		z[i].setName(name);
//		z[i].announce();
	}
	return z;
}