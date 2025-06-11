#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>
#include <cstdlib>

using	std::string;
using	std::cout;
using	std::endl;
using	std::cin;

#define GET_NUMBER "How many zombies do you want to create?: "
#define GET_NAME "Which name you want to give to these zombies?: "

class Zombie
{
public:
	Zombie();
	Zombie( const Zombie& source );
	~Zombie();
	Zombie&	operator=( const Zombie& source );
	void	announce(void);
	void	setName(string name);
	string	getNameOfZombie();

private:
	string _name;

};

//main.cpp
string	getUserInputString(string message);
int		stringToInt(string input);
int		getPositiveNumber(string message);
void	numberOfZombiesTester(Zombie *z, int number);

//zombieHorde.cpp
Zombie*		zombieHorde( int N, string name );

#endif