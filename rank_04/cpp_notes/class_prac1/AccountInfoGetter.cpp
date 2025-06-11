#include <iostream>
#include <string>
#include "AccountInfo.hpp"

using	std::cin;
using	std::cout;
using	std::string;
using	std::endl;

string	getUserInputString(string input); //Forward declaration
int		getUserInputInt(string input);

void	printAccoutInfo(const AccountInfo& account)
{
	cout << "Account Number: " << account.accountNumber << "\n";
	cout << "Pw: " << account.password << endl;
	cout << "Name: " << account.name << endl;
	cout << "Balance: " << account.balance << endl;

}

AccountInfo	insertAccountInfo()
{
	AccountInfo account; //calls default const-r == AccountInfo::AccountInfo()

	account.accountNumber = getUserInputString("Enter your account number: ");
	account.password = getUserInputString("Enter your password: ");
	account.name = getUserInputString("Enter your name: ");
	account.balance = getUserInputInt("Enter your balance: ");
	return account;
}

string	getUserInputString(string input)
{
	string	output;

	cout << input;
	cin >> output;
	return output;
}

int	getUserInputInt(string input)
{
	int	output;

	cout << input;
	cin >> output;
	return output;
}

