## ex01: Moar brainz!

### files to turn in
- Makefile, main.cpp, Zombie.hpp, Zombie.cpp, zombieHorde.cpp

### features
- create a horde of Zombies
- write a function in the appropriate file
```
Zombie* zombieHorde( int N, std::string name );
```
	- [x] alloc N Zombie obj in a single alloc
		- [x] get N from user input
	- [x] then, init zombies (name them with param)
		- get each Name from user input
	- [x] then, ret {ptr to 1st zombie}
- write your own tester
	- [x] ensure func 'zombieHorde()' works as expected
	- [x] call announce() for each zombie

## check mem leak
- [x] always use 'delete' after 'new'