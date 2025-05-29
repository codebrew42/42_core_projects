#include "phoneBook.hpp"
#include "contact.hpp"
#include "main.hpp"

using std::cout;
using std::string;

PhoneBook::PhoneBook() : _numberOfContacts(0) {}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook& source)
	: _numberOfContacts(source._numberOfContacts) //having here: more efficient
{
	int	i = -1;
	while (++i < 8)
	{
		_contact[i] = source._contact[i];
	}
}

PhoneBook&	PhoneBook::operator=(const PhoneBook& source)
{
	if (this != &source)
	{
		_numberOfContacts = source._numberOfContacts;
		int i = -1;
		while (++i < 8)
			_contact[i] = source._contact[i];
	}
	return *this;
}


string	PhoneBook::to_string(int number)
{
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

/* when to use "this->"*/
// if multiple phonebook: using "this->"" is necessary
// Otherwise, using property name: enough
void PhoneBook::addContact(const Contact &contact)
{
	int index = _numberOfContacts % 8;
	_contact[index] = contact;
	_numberOfContacts++;
}

int PhoneBook::getNumberOfContacts()
{
	return _numberOfContacts;
}

int PhoneBook::getCurrentIndex()
{
	return _numberOfContacts % 8;
}

void PhoneBook::locateWords(int wordsLength)
{
	if (wordsLength >= 10)
		return;
	int numberOfSpacing = 10 - wordsLength;
	string spaces(numberOfSpacing, ' ');
	cout << spaces;
}

string PhoneBook::shortenWords(string input)
{
	if (input.length() > 10)
		return input.substr(0, 9) + ".";
	return input;
}

void PhoneBook::displayColumns(int index, Contact &contact)
{
	string info[4];
	info[0] = to_string(index);
	//	info[0] = to_string(getCurrentIndex());
	info[1] = contact.getFirstName();
	info[2] = contact.getLastName();
	info[3] = contact.getNickname();

	int i = -1;
	while (++i < 4)
	{
		info[i] = shortenWords(info[i]);
		locateWords(info[i].length());
		cout << info[i];
		if (i < 3)
			cout << "|";
	}
	cout << "\n";
}

void PhoneBook::displayAllContacts()
{
	displayStringInLine("=============================================");
	displayStringInLine("     Index|First Name| Last Name|  Nickname");
	displayStringInLine("");
	int i = -1;
	while (++i < 8 && i < getNumberOfContacts())
		displayColumns(i, _contact[i]);
	displayStringInLine("=============================================");
}

void PhoneBook::displaySingleContact()
{
	int requestedIndex;

	while (true)
	{
		requestedIndex = atoi(getInputString("Enter the index you want to see the detail: ").c_str());
		if (requestedIndex >= getNumberOfContacts() || requestedIndex >= 8 || requestedIndex < 0)
		{
			displayStringInLine("Error: the index doesn't exist in the phonebook, try again!");
			continue;
		}
		else
			break;
	}
	displayStringInLine("=============================================");
	cout << "    First name: " << _contact[requestedIndex].getFirstName() << "\n";
	cout << "     Last name: " << _contact[requestedIndex].getLastName() << "\n";
	cout << "      Nickname: " << _contact[requestedIndex].getNickname() << "\n";
	cout << "  Phone number: " << _contact[requestedIndex].getPhoneNumber() << "\n";
	cout << "Darkest Secret: " << _contact[requestedIndex].getDarkestSecret() << "\n";
	displayStringInLine("=============================================");
}