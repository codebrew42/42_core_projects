#include "Zombie.hpp"

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;


/*
`cin >> input` operation doesn't detect empty inputs the way you might expect. 
When you press Enter without typing anything, 
`cin` doesn't actually set `input` to an empty string - 
instead, the input operation fails and leaves `input` unchanged.
*/
string getUserInputString(string message)
{
	string input;

	cout << message << endl;
	if (!getline(cin, input)) {
		cout << "\nEOF detected, exiting program..." << endl;	//handle Ctrl+D(EOF) here
		exit(0);  // Or you could throw an exception that you catch in main
	}
	return input;
}

bool	isWhitespace(const string &str)
{
	return str.find_first_not_of(" \t\n\r") == string::npos;
}

bool	isEmptyOrWhitespace(const string &str)
{
	return str.empty() || isWhitespace(str);
}

int		stringToInt(string input)
{
	if (isEmptyOrWhitespace(input))
		return -2;
	try {
		return atoi(input.c_str());
	} catch (const std::exception& e) {
		return -1;
	}
}

int		getPositiveNumber(string message)
{
	int	number = -1;

	while (true)
	{
		number = stringToInt(getUserInputString(message));
		if (number <= 0)
			cout << "Error: Input must be a positive integer!(1-2147483647)" << endl;
		else
			break;
	}
	return number;
}

string getName(string message)
{
	string name;
	while (true)
	{
		name = getUserInputString(message);
		if (isEmptyOrWhitespace(name))
			cout << "Error: Input can't be empty" << endl;
		else
			break;
	}
	return name;
}

void	numberOfZombiesTester(Zombie *z, int number)
{
	int		i = -1;
	cout << "* * * Test starts... * * * " << endl;
	cout << " Name : " << z[0].getNameOfZombie() << endl;
	cout << "Number: " << number << endl;
	cout << "(Zombies start shouting...)" << endl;
	while (++i < number)
	{
		z[i].announce();
	}
	cout << "* * * Test ends...* * * " << endl;
}

int	main()
{
	int		number = -1;
	string	name;

	number = getPositiveNumber(GET_NUMBER);
	name = getName(GET_NAME);
	Zombie *z = zombieHorde(number, name);
	numberOfZombiesTester(z, number);

	delete[] z;
}