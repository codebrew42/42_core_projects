#include "Zombie.hpp"

int main() 
{
	Zombie *z1 = newZombie("Bob");
	z1->announce();
	delete z1;
	cout << endl;
	randomChump("Alice");
}