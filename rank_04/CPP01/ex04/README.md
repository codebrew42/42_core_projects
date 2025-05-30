# ex04

## to submit
- [] Makefile
- [] main.cpp
- [] *.cpp
- [] *.hpp

## requirements
- prg 
	- [] takes 3 param: filename, string s1, string s2
	- [] open FILENMAE
	- [] cpy FILENAME's content to a new file `FILENAME.replace`
	- [] also replace every s1 with s2 in `*.replace`
- edge cases
	- unexpected inputs
		- [] no param
		- [] one param
		- [] FILENAME: x exist
	- [] errors

## check
- forbidden
	- [] std::string::replace
	- [] but otherwise, std::string (OK)
	- [] c file manipulation functions


## key concept of C++
- how to open a file using FILENAME (cin)?
- how to create a new file?
- how to cpy one file into another?
- how to replace strings inside a file with other string?
- how does std::string::replace work?