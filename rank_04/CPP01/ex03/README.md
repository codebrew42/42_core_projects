# ex03: Unnecessary violence

## files
- [x] Makefile
- [x] main.cpp

- [x] Weapon.hpp
- [x] Weapon.cpp

- [x] HumanA.hpp
- [x] HumanA.cpp

- [x] HumanB.hpp
- [x] HumanB.cpp

## program
- class `Weapon` has
	- [x] private: string `type`
	- [x] getType(): returns a constant reference to `type`
	- [x] setType(): sets `type` using new value passed as a param
- class `HumanA` and class `HumanB` contains
	- [x] class `Weapon`
	- [x] `name`
	- [x] attack() : disp `<NAME> attacks with their <WEAPON TYPE>` (except angle brackets)
	- only difference is in two details
		- [x] `HumanA` takes `Weapon` in its contructor, `HumanB` doesn't
		- [x] `HumanA` always has `Weapon`, `HumanB` may not always does
- check mem leaks

## key concepts
- for each case: which one to use, and why?
	- pointer to a Weapon vs. ref to Weapon?

## notes: interpretation of the assignment
- [1] takes Weapon 
	- meaning = pass it as a param to the constructor
	- hint: that the class's const includes this param
- [2] always has Weapon, not always has Weapon
	- have an attribute `Weapon*` or `Weapon&`
- [3] returns a constant refernce to type
```

const string& Weapon::getType() const //correct
string Weapon::getType() //wrong


```