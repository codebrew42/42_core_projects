/*
 @param av[1]=FILENAME, av[2]=string s1, av[3]=string s2
*/
int main(int ac, char **av)
{
	if (ac != 4)
		return 0;
	//doesFileExist(filename)
	//copyFile()
	//replaceString()

}

//Q. in this kind of FUNC: ret 1 or 0 in invalid input? or recommend filename,ret valu
/* int 	doesFileExist(filename)
	if (av[1](filename) doesn't exit in the current dir, exit)
		{ret 0} 
	{ret 1}
*/

/* void copyFile(FILENAME or ptrToFILENAME)
	{cp}
*/


/* int replaceString(FILENAME or ptrToFILENAME, ptrToDest, s1, s2)
caseA, s1 = NULL
	{ret}

caseB, S1 != NULL, but not included in FILE
	{ret}

caseC-1, s1 != NULL, s1 != NULL
caseC-2, s1 != NULL, s2 = NULL
	{replace dest}
*/