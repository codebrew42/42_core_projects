# key concept
- getting input
- validating input

# issue

## case1 : when index=alphabet (displaying single info)
- check: the getting index part
- probably here of the ex01
```
void PhoneBook::displaySingleContact()
{
	int requestedIndex;

	while (true)
	{
		requestedIndex = atoi(getInputString("Enter the index you want to see the detail: ").c_str());

		(... rest of the code ...)
	}
}
```

## case2 : "Enter your darkest secret: I love eating icecream with pommes" in input part(contact.cpp)
- check: how strings are handled
- these 2 parts
```
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
```