#include <iostream>
#include <string>

int main(){
	int	i = 3+4;
	std::cout << "enter your first name:" << std::endl;
	std::string firstName;
	std::cin >> firstName;
	std::cout << "enter your last name:";
	std::string lastName;
	std::cin >> lastName;
	std::cout << "hi, " << firstName << lastName << "!" << std::endl;
//	std::cout << i << std::endl;
//	std::cout << "this \" is backslash \' haha" << std::endl;
//	return 0;
}