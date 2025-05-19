#include <iostream>
#include <string>

int main() {
	std::string s;
	s = "hi";
	s = s + " there";

	std::cout << "<default> str 's': " << s << "\ns's len: " << s.length() << std::endl;
	std::cout << "s[3]: " << s[3] << std::endl;
	std::cout << "\n<substracted> s.substr(3, 8): " << s.substr(3, 8) << "\n" << std::endl;
	std::cout << "type a new string 's': ";
	std::getline(std::cin, s);
	std::cout << "<changed> str: " << s << "\nstr's len: " << s.length() << "\n" << std::endl;
	s.clear();
	std::cout << "<cleared> str 's': " << s << "\ns's len: " << s.length() << std::endl;
}