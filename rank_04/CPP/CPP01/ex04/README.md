# ex04 : Sed is for losers

## to submit
- [x] Makefile
- [x] main.cpp
- [x] *.cpp
- [x] *.hpp : no .hpp

## requirements
- prg 
	- [x] takes 3 param: filename, string s1, string s2
	- [x] open FILENAME
	- [x] cpy FILENAME's content to a new file `FILENAME.replace`
	- [x] also replace every s1 with s2 in `*.replace`
- edge cases
	- unexpected inputs
		- [x] no param
		- [x] one param
		- [x] FILENAME: x exist
		- [x] FILENAME: exist, but no permission
		- [x] s1, s2: NULL& not NULL, NULL&NULL, ... 
	-  errors
		- [x] error opening file

## check
- forbidden
	- [x] std::string::replace
	- [x] but otherwise, std::string (OK)
	- [x] c file manipulation functions


## key concept of C++
Q1. how to open a file using FILENAME (cin)?
Q2. how to create a new file?
	A2.	when creating Outfile, ofstream creates ".txt" automatically, if x exist
	Otherwise,...

	A1-2.
```cpp
	#include <fstream>
	int main()
		ofstream outFile("myNew.txt");
		if (!outFile)
			return 1;
		newFile << "NEW DATA" << endl; //putting new data
	outFile.close()
```



Q3. how to cpy one file into another?

```cpp
int main()
	ifstream inFile("src.txt");
	if (!inFile)
		return 1

	ofstream outFile("output.txt")
	if (!outFile)
		inFile.close();
		return 1;

//copy : read each line & save
	string line;
	while (getline(inFile, line))
		dest << line << endl;
	
	inFile.close();
	outFile.close();

```
Q4. how to replace strings inside a file with other string?
```cpp
#include <fstream>
int main()
//open input file
	ifstream source("src.txt")
	if (!source)
		return 1;

//open output file
	ofstream dest("dst.txt")
	if (!dest)
		source.close();
		return 1;

//replace and save
	string line;
	string s1 = "oldText";
	string s2 = "newText";
	while (getline(source, line))
		size_t pos = 0;
		// while (found : from s1[pos]) {substitute && update pos}	
		while ((pos = line.find(s1, pos)) != string::npos) //npos = not found
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		dest << line << endl;

//close
	source.close();
	dest.close();
```
Q5. how does std::string::replace work?

```cpp
int main()
//basic
	string str = "Hello world!";
	str.replace(6, 5, "there")
	cout << str << endl; //Output: world->there

// Replace using iterators
	string text = "The quick brown fox";
	text.replace(text.begin() + 4, text.begin() + 9, "smart");
	cout << text << endl; // Output: The smart brown fox

// Replace with another string
	string original = "Programming is fun";
	string replacement = "exciting";
	original.replace(14, 3, replacement);
	cout << original << endl; // Output: Programming is exciting
```