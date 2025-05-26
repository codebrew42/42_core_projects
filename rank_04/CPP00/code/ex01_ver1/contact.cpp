#include "contact.hpp"

using	std::string;

Contact::Contact() {}

Contact::~Contact() {}

string	Contact::CapitalizeFirstLetter(string input) const
{
	if (!input.empty())
		input[0] = std::toupper(input[0]);
	return input;
}

string	Contact::getFirstName() const
{
	return (CapitalizeFirstLetter(this->_firstName));
}

string	Contact::getLastName() const
{
	return (CapitalizeFirstLetter(this->_lastName));
}

string	Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

string	Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

string	Contact::getNickname() const
{
	return (this->_nickname);
}


void	Contact::setFirstName(const std::string& input)
{
	this->_firstName = input;
}

void	Contact::setLastName(const std::string& input)
{
	this->_lastName = input;
}

void	Contact::setNickname(const std::string& input)
{
	this->_nickname = input;
}

void	Contact::setPhoneNumber(const std::string& input)
{
	this->_phoneNumber = input;
}

void	Contact::setDarkSecret(const std::string& input)
{
	this->_darkestSecret = input;
}
