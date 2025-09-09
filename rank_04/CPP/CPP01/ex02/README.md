# ex02: HI THIS IS BRAIN

## files
- [x] Makefile
- [x] main.cpp

## flow
- this program contains
	- [x] string var : "HI THIS IS BRAIN"
	- [x] stringPTR : to the str
	- [x] stringREF : ref to the string
- this program must print
	- mem adr 
		- [x] of the string var
		- [x] held by stringPTR
		- [x] held by stringREF
	- val
		- [x] of the string var
		- [x] pointed to by stringPTR
		- [x] pointed to by stringREF

## key concepts
- references vs. address manipulation


### reference vs. ptr
- what's `reference`?
	- nickname for a var
	- don't have own strage location
	- once init, can't be made to refer another var
	- can't be null
```c
int& ref; //ERR

int x = 5;
int& ref = x; //OK: refers to X
int* ptr1 = &x; //OK: points to X

int* ptr2 = nullptr; //OK (even nullptr has no obj)
```
	- changing val
```c
int x = 5;
int y = 10;
int& ref = x;
ref = y; //changes value of x: 5->10

int a = -5;
int b = -10;
int* ptr = &x;
ptr = &y //now points to y, (x unchanged)
```

- in this code, `stringPTR` and `stringREF` reer to `message`
	- BUT `*PTR` = var which stores adr.
	- `*REF` = an alias for `message` (not a seperate var)