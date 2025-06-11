# ex05 : Harl 2.0

## to submit
- [] Makefile
- [] main.cpp
- [] Harl.cpp
- [] Harl.hpp

## forbidden function
- no

## requirements
- the program
	- [x] gets parameter which is the level
	- [] automates `Harl` which makes comments

- Harl class
	- private functions
		- `void debug( void );`
			- [] Debug messages contain contextual info
			- [] for problem diagonosis
		- `void info( void );`
			- [] Info messages contain extensive info
			- [] for tracing program execution in a production env.
		- `void warning( void );`
			- [] Warning messages indicate a potential issue in the system
			- [] the issue can be handled or ignored
		- [] `void error( void );`
			- [] Error messages indicate the unrecoverable error has occurred
			- [] that error is usually critical that it requires manual intervention
	- public function
		- `void complain( std::string level );`
			- [] calls four member functions above depending on the level(param)

## checklist
- don't use:
	- [] a forest of if/else, if/else
- use:
	- [] pointers to member functions
- recommended:
	- [] use examples of comments or choose comments of your own

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
typedef void (Harl::*MemberFuncPtr)(void);
```
This creates a new type called `MemberFuncPtr` which represents a ptr to a memb func

- `void`: ret type (ret nothing)
- `Harl::`: the ptr belongs to the Harl class


