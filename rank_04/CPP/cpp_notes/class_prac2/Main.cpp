#include <string>
#include <cstring> //memcpy, strlen
#include <iostream>

class String
{
private:
	char*	_Buffer;
	int		_Size;

public:
	String(const char *string)
	{
		_Size = strlen(string);
		_Buffer = new char[_Size + 1];
		memcpy(_Buffer, string, _Size);
		_Buffer[_Size] = 0;
	}
	~String()
	{
		delete[] _Buffer; //why?
	}
	/* what's friend?* 
	- declare func 'optr<<' as 'friend' of the class 'String'
	- not a member of a class, but has access to class's priv/pub members
	*/
//    friend std::ostream& operator<<(std::ostream& stream, const String& string);
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	char& operator[](unsigned int index)
	{
		return _Buffer[index];
	}
};

/* about this func
- stream output optr : an overload of stream output op(<<) for class 'String'
- allows to use : 'std::cout << myString'
*/

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string._Buffer;
	return stream;
}

int main() 
{
	String string = "Type your Name: ";
	std::string name;


	std::cout << string << std::endl;
//	std::cin.get(); //get takes the first char
	std::cin >> name;
	name[2] = 'A';
	std::cout << "Typed name: " << name << std::endl;



}