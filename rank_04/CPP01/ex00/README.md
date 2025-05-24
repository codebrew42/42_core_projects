# ex00: BraiiiiiiinnnzzzZ

## files to turn in
- [ ] Makefile
- [ ] main.cpp
- [ ] Zombie.{h, hpp}
- [ ] Zombie.cpp
- [ ] newZombie.cpp
- [ ] randomChump.cp

## features
- write a zombie class
	- [ ] add: private string attribute `name`
	- [ ] add: member func `void announce( void );`
		- behavior
		```
		ZOMBIE_NAME: BraiiiiiiinnnzzzZ... //replace: ZOMBIE_NAME
		```
	- [ ] add: member func `Zombie* newZombie( std::string name );`
		- create a zombie
		- name it
		- just returns it (for use outside the func scope)
	- [ ] add: member func `void randomChump( std::string name );`
		- create a zombie
		- name it
		- make it announce itself
- [ ] zombies are destroyed after its use
- [ ] add: destructor
	- print a message with the name of it

## to think
- where to allocate zombies? stack or heap