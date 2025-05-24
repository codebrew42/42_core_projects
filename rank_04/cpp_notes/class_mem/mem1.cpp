#include "mem1.hpp"

using	std::cout;
using	std::string;
using	std::cin;
using	std::endl;

void	Zombie::displayCharacteristic()
{
	cout << "this zombie's charm is: " << _characteristic << endl;
}

string	Zombie::getUserInputString(string message)
{
	string		output;
	cout << message << endl;
	//Ver1. cint << output is wrong, when getting input mltpl times

	//Ver2. Clear and get a new cin
		//clearany leftover characters in the input buffer
	cin.clear();
		// Use getline instead of cin >> to read the entire line
	std::getline(cin, output);
		// If the line is empty (e.g. just a newline), try again
	while (output.empty()) {
		cout << "empty line is not accepted, type again!" << endl;
		std::getline(cin, output);
	}
	return output;
}

string	Zombie::getCharacteristic()
{
	return getUserInputString("Enter Zombie's Characteristic: ");
}

// Implement the constructor
Zombie::Zombie(std::string name)
{
	cout << "One Zombie: " << name << " is created" << std::endl;
	_characteristic = getCharacteristic();
}

// Implement the destructor
Zombie::~Zombie()
{
	cout << "Zombie is destroyed\n" << std::endl;
}

int main()
{
	//1.alloc on heap
	Zombie* z = new Zombie("Bob");
	z->displayCharacteristic();
	delete z;
	//-> call destructor to free mem

	//2.alloc on stack
	Zombie y("Alice"); 
	y.displayCharacteristic();

	//->autmtcly destroyed when scope ends


}
