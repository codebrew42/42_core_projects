#include <iostream>
#include <string>


void printString(std::string s) {
	std::cout << s << std::endl;
}

int main() {
	std::string s1; //null str
	s1 = "jin";
	std::string new_s1 = s1; //cp str
	printString("default string: " + s1);

	std::string fill_s(10, '*'); //fill n-char
	printString("filled string: " + fill_s);

}
