#include <iostream>
#include <string>

int main() 
{
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
//	std::cout << "Entered name is " + name + "\n";
//	std::cout << "Entered name's length is " << name.length() << "\n";


	std::string middleOfMessage = "* Hello, " + name + " *";

	std::string endOfMessage(middleOfMessage.length(), '*');
	std::string blank(middleOfMessage.length() - 2, ' ');
	blank = "*" + blank + "*";


	std::cout << endOfMessage + "\n";
	std::cout << blank + "\n";
	std::cout << middleOfMessage + "\n";
	std::cout << blank + "\n";
	std::cout << endOfMessage + "\n";

}