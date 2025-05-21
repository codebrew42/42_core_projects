#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <stdexcept>
class PhoneBook
{
	private:
		int			_numberOfContacts;
//		int			_currentIndex;
		Contact		_contact[8];

	public:
		PhoneBook();
		~PhoneBook();

		//functions inside phonebook.cpp
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