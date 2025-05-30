#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <stdexcept>
#include <sstream>
class PhoneBook
{
	private:
		int			_numberOfContacts;
		Contact		_contact[8];

	public:
		PhoneBook();
		~PhoneBook();
		PhoneBook(const PhoneBook& source);
		PhoneBook&	operator=(const PhoneBook& source);

		std::string	to_string(int number);
		void		addContact(const Contact& contact);
		int			getCurrentIndex();
		int			getNumberOfContacts();
		void		displayAllContacts();
		void		displayColumns(int index, Contact& contact);
		void		locateWords(int wordsLength);
		std::string	shortenWords(std::string input);
		void		displaySingleContact();
	};

#endif