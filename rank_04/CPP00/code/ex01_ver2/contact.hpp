#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <cctype>
class	Contact
{
	public:
		Contact();
		~Contact();
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickname() const;
		std::string		getPhoneNumber() const;
		std::string		getDarkestSecret() const;
		void			setFirstName(const std::string& input);
		void			setLastName(const std::string& input);
		void			setNickname(const std::string& input);
		void			setPhoneNumber(const std::string& input);
		void			setDarkSecret(const std::string& input);
		Contact			addAllContactInfo();
		std::string		CapitalizeFirstLetter(std::string input) const;

	private:
		std::string		_firstName; 
		std::string		_lastName;
		std::string		_nickname;
		std::string		_phoneNumber;
		std::string		_darkestSecret;

};

#endif