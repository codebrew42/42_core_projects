#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	public:
		Contact();
		~Contact();
		std::string		getFirstName() const;
		void			setFirstName(const std::string& input);
		void			setLastName(const std::string& input);
		void			setNickname(const std::string& input);
		void			setPhoneNumber(const std::string& input);
		void			setDarkSecret(const std::string& input);

	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_phoneNumber;
		std::string		_darkSecret;

};

#endif