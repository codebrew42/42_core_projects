#include <iostream> //for err msg
#include <fstream>

using	std::ofstream;
using	std::cerr;
using	std::endl;

/* Dynamic allocation
	when? specific need
			- creating stream basd on runtime condition
			- storing them in containers

int	main() {
	ofstream* out = new ofstream("out1.txt");
	if(!out->is_open())
	{
		cerr << "Error: opening file!" << endl;
		delete out;
		return 1;
	}

	*out << "new text";

	out->close();
	delete out; //dealloc

}*/

//not-dynamic alloc : safer, clear, efficient
int main()
{
	//will truncate(fill with null)
	ofstream out("test.txt", std::ios::app);

	//will not : append mode
	//ofstream out("out3.txt", std::ios::app)

	if (!out)
	{
		cerr << "Error: opening file!" << endl;
		return 1;
	}

	out << "NEW TEXT";
	out.close();

}