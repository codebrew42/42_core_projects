#include <fstream>
#include <iostream>

using	std::ofstream;
using	std::cerr;
using	std::endl;

int main() 
{
	ofstream out("test.txt");

//	ofstream out("test.txt", std::ios::app);
	if (!out)
	{
		cerr << "Error opening file!" << endl;
		out.close();
		return 1;
	}
	out << " BYE ";


}