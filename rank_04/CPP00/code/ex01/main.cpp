#include "contact.hpp"
#include "main.hpp"

using	std::string;
using	std::cin;
using	std::cout;

void displayStringInLine(string message)
{
	cout << message << "\n";
}

string getInputString(string message)
{
	string		output;

	cout << message;
	cin >> output;
	return output;
}

int main() {
	// Contact	contact;
	// contact.setFirstName(getInputString("Enter: "));
	// displayStringInLine(contact.getFirstName());
	string		command;

	while (true)
	{
		command = getInputString("Please enter one of these commands(ADD, SEARCH, EXIT): \n");
		if (command == "ADD" || command == "SEARCH" || command == "EXIT")
			break ;
	}

}
