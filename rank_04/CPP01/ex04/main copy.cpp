#include <fstream>
#include <iostream>
#include <sys/stat.h>	// For checking file existence without opening
#include <cerrno>		// For checking error codes
#include <string>

using	namespace std;


bool fileExists(const char* fileName)
{
	struct stat buffer;
	return (stat(fileName, &buffer) == 0); //exists physically
}

bool fileIsReadable(const char* fileName)
{
	ifstream file(fileName);
	return file.good(); //exists&redable
}

int	displayErrorMessage(string message)
{
	cerr << message << endl;
	return 1;
}


/*
 @param av[1]=FILENAME, av[2]=string s1, av[3]=string s2
*/
int main(int ac, char **av)
{
	if (ac != 4)
	{
		return (displayErrorMessage("Error: enter 3 arguments!" ));
//		cerr << "Error: enter 3 arguments!" << endl;
//		return 1; //also err
	}
	if(!fileExists(av[1]))
	{
		cerr << "Error: file '" << av[1] << "' does not exist!" << endl;
		return 1;
	}
	if(!fileIsReadable(av[1]))
	{
		cerr << "Error: file '" << av[1] << "' does not have permission!" << endl;
		return 1;
	}
	ofstream	src(av[1]);
	if (!src)
	{
		cerr << "Error: opening file!" << endl;
		return 1;
	}


	//read and replace (edge: NULL(s1/s2))
	string line;
	string s1 = av[2]; //if av[2]=null?
	string s2 = av[3];
	// if (s1.empty())
	// {
		
	// }
	// while (getline(src, line))
	// {

	// }

}

//Q. in this kind of FUNC: ret 1 or 0 in invalid input? or recommend filename,ret valu

/* int replaceString(FILENAME or ptrToFILENAME, ptrToDest, s1, s2)
caseA: s1 = NULL
	{ret}

caseB: S1 != NULL, but not included in FILE
	{ret}

caseC-1, s1 != NULL, s1 != NULL
caseC-2, s1 != NULL, s2 = NULL
	{replace dest}
*/