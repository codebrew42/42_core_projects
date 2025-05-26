#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>
#include <cstdlib>

using	std::string;

#define GET_NUMBER "How many zombies do you want to create?: "
#define GET_NAME "Which name you want to give to these zombies?: "

class Zombie
{
public:
	Zombie();
	~Zombie();
	void	announce(void);
	void	setName(string name);

private:
	string _name;

};

//main.cpp
string	getUserInputString(string message);
int		stringToInt(string input);
int		getPositiveNumber(string message);

//zombieHorde.cpp
Zombie*		zombieHorde( int N, string name );

#endif