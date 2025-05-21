#include "contact.hpp"
#include "main.hpp"
#include "phoneBook.hpp"

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

Contact createNewContact()
{
	Contact	contact;

	contact.setFirstName(getInputString("Enter your first name: "));
	contact.setLastName(getInputString("Enter your last name: "));
	contact.setNickname(getInputString("Enter your nickname: "));
	contact.setPhoneNumber(getInputString("Enter your phone number: "));
	contact.setDarkSecret(getInputString("Enter your darkest secret: "));
	return contact;
}

int main()
{
	string		command;
	Contact		contact_temp;
	PhoneBook	phoneBook;

	while (true)
	{
		command = getInputString("Please enter one of these commands(ADD, SEARCH, EXIT): \n");
		if (command == "ADD")
		{
			contact_temp = createNewContact();
			phoneBook.addContact(contact_temp);
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayAllContacts();
			phoneBook.displaySingleContact();
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			displayStringInLine("Error: Invalid input, try again!");
			continue ;
		}
	}

}
