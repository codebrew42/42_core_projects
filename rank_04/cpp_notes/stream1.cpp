#include <iostream>
#include <string>

std::string getInput(std::string message) {
	std::cout << message;
	std::string returnMessage;
	std::cin >> returnMessage;
	return returnMessage;
}

void printString(std::string s) {
	std::cout << s << std::endl;
}

int main() {
	std::string name = getInput("Enter your name: ");
	printString("Entered name is: " + name);

}
