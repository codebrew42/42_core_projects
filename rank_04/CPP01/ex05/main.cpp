#include <string>
#include <iostream>
#include "Harl.hpp"
using	namespace std;

int	displayErrorMessage(const char* message)
{
	cerr << message << endl;
	return 1;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (displayErrorMessage("Error: type ./harl <level>!"));

	//convert!
	string level(av[1]);
	if (level.empty())
		return (displayErrorMessage("Error: level can't be empty!"));

	Harl	harl;


}