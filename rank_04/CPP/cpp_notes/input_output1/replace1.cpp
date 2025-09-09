#include <fstream>
#include <string>

using namespace std;

int main()
{
//open src
	ifstream in;
	in.open("test.txt");
	if (!in)
		return 1;
	
//open dest
	ofstream out;
	out.open("test_replaced.txt");
	if (!out)
	{
		in.close();
		return 1;
	}

//replace
	string	line;
	string	s1 = "?";
	string	s2 = "!";
	while (getline(in, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != string::npos)
		{
			//extract line[0] - line[pos] + s2 + line[pos(old)]
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		};
		out << line << endl;
	}


//close
	in.close();
	out.close();

}