#include "contact.hpp"
#include "main.hpp"
#include "phoneBook.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;

void displayStringInLine(string message)
{
	cout << message << "\n";
}

string	getInputString(string message)
{
	static string		output;

	cout << message;
	cin >> output;
	if (cin.eof()) //check for EOF (ctr D)
	{
		cout << "\n";
		exit(0);
	}
	return	output;
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
	int			hasContactFlag = 0;
	string		command;
//	Contact		contactTemp; //better to combine in c++; clear intent, fewer glabal ->more efficient
	PhoneBook	phoneBook;

	while (true)
	{
		command = getInputString("Please enter one of these commands(ADD, SEARCH, EXIT): \n");
		if (command.empty()) // if ctr+D case
			return 1;
		if (command == "ADD")
		{
			hasContactFlag = 1;
			Contact contactTemp = createNewContact();
			phoneBook.addContact(contactTemp);
		}
		else if (command == "SEARCH")
		{
			if (hasContactFlag == 0)
			{
				cout << "You should add any contact info first, try again!" << endl;
				continue ;
			}
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