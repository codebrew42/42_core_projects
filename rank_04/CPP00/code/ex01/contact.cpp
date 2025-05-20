#include "contact.hpp"

using	std::string;

Contact::Contact()
{
	return;
}

Contact::~Contact()
{
	return;
}

string	Contact::getFirstName() const
{
	return (this->_firstName);
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
	this->_darkSecret = input;
}
