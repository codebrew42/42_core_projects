#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numberOfContacts(0) {
	std::cout << "Default constructor called" << std::endl;
}

PhoneBook::PhoneBook(int number, int *intArr, int *intPtr, int *intMixed[8])
{
	_numberOfContacts = number;


}

PhoneBook::PhoneBook(const PhoneBook& source) {
	std::cout << "Copy constructor called" << std::endl;
	// Rest of your code...
}

PhoneBook& PhoneBook::operator=(const PhoneBook& source) {
	std::cout << "Assignment operator called" << std::endl;
	// Rest of your code...
	return *this;
}

PhoneBook::~PhoneBook() {}

int main()
{
	std::cout << "[part0]" << std::endl;
	int	temp1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	*temp2 = {-1, -2, -3, -4, -5, -6, -7, -8};
	int	*temp3 = {0, 0, 0, 0, 0, 0, 0, 0};
	PhoneBook default(3, temp1, temp2, &temp3);

	std::cout << "[part1]" << std::endl;
	std::cout << "(origin)";
	PhoneBook origin;

	PhoneBook copied1 = origin; // == PhoneBook copied(origin);

	std::cout << std::endl << "[part2]"  << std::endl;
	std::cout << "(copied2)";
	PhoneBook copied2;

	copied2 = origin; // == copied2 =(origin);
	
}