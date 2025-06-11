#include <iostream>

class PhoneBook
{
private:
	int		_numberOfContacts;
	int		_intArr[8];
	int		*_intPtr;
	int		*_intMixedArrPtr[8];

public:
	PhoneBook();
	PhoneBook(int number, int *intArr, int *intPtr, int *intMixed[8]);
	PhoneBook(const PhoneBook& source);
	PhoneBook& operator=(const PhoneBook& source);
	~PhoneBook();
};