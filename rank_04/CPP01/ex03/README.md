# ex03: Unnecessary violence

## files
- [] Makefile
- [] main.cpp

- [] Weapon.hpp
- [] Weapon.cpp

- [] HumanA.hpp
- [] HumanA.cpp

- [] HumanB.hpp
- [] HumanB.cpp

## program
- class `Weapon` has
	- [] private: string type
	- [] getType(): returns a constant refernce to `type`
	- [] setType(): sets `type` using new value passed as a param
- class `HumanA` and class `HumanB` contains
	- [] class `Weapon`
	- [] `name`
	- [] attack() : disp `<NAME> attacks with their <WEAPON TYPE>` (except angle brackets)
	- only difference is in two details
		- [] `HumanA` takes `Weapon` in its contructor, `HumanB` doesn't
		- [] `HumanA` always have `Weapon`, `HumanB` may not always have it
- check mem leaks

## key concepts
- in which cases to use, and why: pointer to a Weapon vs. ref to Weapon?
