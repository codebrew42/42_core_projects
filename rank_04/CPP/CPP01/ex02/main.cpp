#include	<string>
#include	<iostream>

using	std::string;
using	std::cout;
using	std::endl;

void	printMemoryAddresses(string& str, string *ptr, string& strRef)
{
	cout << "[printing memory addresses...]" << endl;
	cout << "original string: " << &str << endl;
	cout << "stringPTR: " << ptr << endl;
	cout << "stringREF: " << &strRef << endl;
}

void	printValues(string str, string *ptr, string& strRef)
{
	cout << "[printing values...]" << endl;
	cout << "original string: " << str << endl;
	cout << "stringPTR: " << *ptr << endl;
	cout << "stringREF: " << strRef << endl;
}

int		main()
{
	string	message = "HI THIS IS BRAIN";
	string	*stringPTR = &message;
	string	&stringREF = message;

	printMemoryAddresses(message, stringPTR, stringREF);
	cout << endl;
	printValues(message, stringPTR, stringREF);

}