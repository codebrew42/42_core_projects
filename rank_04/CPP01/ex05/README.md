# ex05 : Harl 2.0

## to submit
- [x] Makefile
- [x] main.cpp
- [x] Harl.cpp
- [x] Harl.hpp

## forbidden function
- no

## requirements
- the program
	- [x] gets parameter which is the level
	- [x] automates `Harl` which makes comments

- Harl class
	- private functions
		- `void debug( void );`
			- [x] Debug messages contain contextual info
			- [x] for problem diagonosis
		- `void info( void );`
			- [x] Info messages contain extensive info
			- [x] for tracing program execution in a production env.
		- `void warning( void );`
			- [x] Warning messages indicate a potential issue in the system
			- [x] the issue can be handled or ignored
		- [] `void error( void );`
			- [x] Error messages indicate the unrecoverable error has occurred
			- [x] that error is usually critical that it requires manual intervention
	- public function
		- `void complain( std::string level );`
			- [x] calls four member functions above depending on the level(param)

## checklist
- don't use:
	- [x] a forest of if/else, if/else
- use:
	- [x] pointers to member functions
- recommended:
	- [x] use examples of comments or choose comments of your own

## key concept of C++
### string comparison
```c
std::string		levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
MemberFuncPtr	funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl:error};

for (int i = 0, i < 4; i++)
{
	if (level == levels[i])
	{
		(this->*funcs[i])(); //call func
		return ;
	}
}
```

* forest of if/else that you need to avoid
```c
if (level == "DEBUG")
    debug();
else if (level == "INFO")
    info();
else if (level == "WARNING")
    warning();
else if (level == "ERROR")
    error();
```


### use pointers to member functions

```c
//Harl.hpp
class Harl{
...
private:
	void (Harl::*MemberFuncPtr)(void);
}

//Harl.cpp
Harl::Harl( const Harl& source)
	for (int i = 0; i < 4; i++)
		if _levels == source._levels[i]
			(this->*_ptrs[i])()
```
This creates a new type called `MemberFuncPtr` which represents a ptr to a memb func

- `void`: ret type (ret nothing)
- `Harl::`: the ptr belongs to the Harl class

- `_levels` vs `(this->*_ptrs[i])()`
	- syntactic sugar: 
		- 'this->' implied for all memb var access
		- compiler automatically translate `_levels[i]` to `this->_levels[i]`
	- `->*` (a pointer to a member function) requires explicit `this`
