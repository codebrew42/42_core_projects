#ifndef CLASS_HPP
# define CLASS_HPP
#include <string>
#include <iostream>

class AccountInfo
{
	public:
	//var
		std::string	accountNumber; //account
		std::string	password; //pw
		std::string	name;
		int		balance;

	//constructors : Two init functions 

		AccountInfo();
		AccountInfo(const std::string& accNum, const std::string& pass,
					const std::string& n, int bal); 

};

AccountInfo		insertAccountInfo();
void			printAccoutInfo(const AccountInfo& account);

#endif