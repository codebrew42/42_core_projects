#include "main.hpp"

bool	isReadable(const char* fileName)
{
	ifstream file(fileName);
	return file.good(); //exists && readable
}


bool	fileExists(const char *fileName)
{
	struct stat buffer;
	return (stat(fileName, &buffer) == 0); //exists physically
}

void	validateArguments(const string& fileName, const string& s1)
{
	if (s1.empty())
		throw invalid_argument("Searching string cannot be empty!");
	if (!fileExists(fileName.c_str())) //(!) c_str() convert: string -> char *
		throw runtime_error("File '" + fileName + "' does not exist!");
	if (!isReadable(fileName.c_str()))
		throw runtime_error("File '" + fileName + "' is not readable, change permission!");
		//(!)'invalid_argument', 'runtime_error' are fixed  in <stdexcept>
}

int		displayErrorMessage(const char* message)
{
	cerr << message << endl;
	return 1;
}

void	getDestName(const char* source, string& dest) //&: to be visible to the caller by using refrences
{
	string sourceStr(source);
	if (sourceStr.find('.', 0) == string::npos)
	{
		dest = sourceStr + ".replace";
		return ;
	}
	size_t lastDot = sourceStr.find_last_of('.');
	dest = sourceStr.substr(0, lastDot) + ".replace" + sourceStr.substr(lastDot);
}

void	replaceStrings(string s1, string s2, ifstream& in, ofstream& out)
{
	string	line;

	while (getline(in, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		out << line << endl;
	}
}

/*
	av[1]=FILENAME, av[2]=string s1, av[3]=string s2
*/
int main(int ac, char **av)
{

//validate & exit on err
	try {
		if (ac != 4)
			throw invalid_argument("Error: enter 3 arguments(filename, string to search, string to replace)");
		validateArguments(av[1], av[2]);
	}
	catch (const exception& err) //(!) exception: can be used for msging
	{
		return (displayErrorMessage(err.what()));
	}

//open src
	ifstream src(av[1]);
	if (!src)
	{
		return (displayErrorMessage("Error: opening file!"));
	}

//open dest
	string	destName;
	getDestName(av[1], destName);
	ofstream dest(destName.c_str());
	if (!dest)
	{
		return (displayErrorMessage("Error: opening file!"));
	}

//replace s1 with s2
	string s1(av[2]);
	string s2(av[3]);
	replaceStrings(s1, s2, src, dest);

}
