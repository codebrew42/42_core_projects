#include "contact.hpp"

using	std::string;

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(const Contact& original) //more efficient using init list
    : _firstName(original._firstName),
      _lastName(original._lastName),
      _nickname(original._nickname),
      _phoneNumber(original._phoneNumber),
      _darkestSecret(original._darkestSecret)
{
	// _firstName = original._firstName;
	// _lastName = original._lastName;
	// _nickname = original._nickname;
	// _phoneNumber = original._phoneNumber;
	// _darkestSecret = original._darkestSecret;
}

Contact& Contact::operator=(const Contact& source)
{
	if (this != &source)
	{
		_firstName = source._firstName;
		_lastName = source._lastName;
		_nickname = source._nickname;
		_phoneNumber = source._phoneNumber;
		_darkestSecret = source._darkestSecret;
	}
	return *this;
}

string	Contact::CapitalizeFirstLetter(const string& input) const
{
	string result = input;
	if (!result.empty())
		result[0] = std::toupper(result[0]);
	return result;
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
