#include <string>
#include <iostream>
#include "Harl.hpp"

int	displayMessage(const char* message)
{
	cout << message << endl;
	return 0;
}

int	displayErrorMessage(const char* message)
{
	cerr << message << endl;
	return 1;
}

int main(int ac, char **av)
{
	Harl	harl;

#ifdef TEST
	(void)ac;
	(void)av[0];
	displayMessage("=== RUNNING TESTS ===");
	displayMessage("case 1: DEBUG");
	harl.complain("DEBUG");

	displayMessage("case 2: INFO");
	harl.complain("INFO");

	displayMessage("case 3: WARNING");
	harl.complain("WARNING");

	displayMessage("case 4: ERROR");
	harl.complain("ERROR");
	displayMessage("=== TESTS COMPLETED ===");
#else
	if (ac != 2)
		return (displayErrorMessage("Error: type ./harl <level>! (either DEBUG, INFO, WARNING, or ERROR)"));
	string level(av[1]); 	//convert: char * -> string
	if (level.empty())
		return (displayErrorMessage("Error: level can't be empty!"));
	harl.complain(level);
#endif

}