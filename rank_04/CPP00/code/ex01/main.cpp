#include "contact.hpp"
#include "main.hpp"
#include "phoneBook.hpp"

using std::cin;
using std::cout;
using std::string;

void displayStringInLine(string message)
{
	cout << message << "\n";
}

string getInputString(string message)
{
	string output;

	cout << message;
	cin >> output;
	if (cin.eof()) //check for EOF (ctr D)
	{
		cout << "\n";
		exit(0);
	}
	return output;
}

Contact createNewContact()
{
	Contact contact;

	contact.setFirstName(getInputString("Enter your first name: "));
	contact.setLastName(getInputString("Enter your last name: "));
	contact.setNickname(getInputString("Enter your nickname: "));
	contact.setPhoneNumber(getInputString("Enter your phone number: "));
	contact.setDarkSecret(getInputString("Enter your darkest secret: "));
	return contact;
}

int main()
{
	string command;
	Contact contact_temp;
	PhoneBook phoneBook;

	while (true)
	{
		command = getInputString("Please enter one of these commands(ADD, SEARCH, EXIT): \n");
		if (command.empty()) // if ctr+D case
			return 1;
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
			break;
		}
		else
		{
			displayStringInLine("Error: Invalid input, try again!");
			continue;
		}
	}
	return 0;
}