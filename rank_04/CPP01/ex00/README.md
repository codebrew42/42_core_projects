# ex00: BraiiiiiiinnnzzzZ

## files to turn in
- [x] Makefile
- [x] main.cpp
- [x] Zombie.{h, hpp}
- [x] Zombie.cpp
- [x] newZombie.cpp
- [x] randomChump.cpp

## features
- write a zombie class
	- [x] add: private string attribute `name`
	- [x] add: member func `void announce( void );`
		- behavior
		```
		ZOMBIE_NAME: BraiiiiiiinnnzzzZ... //replace: ZOMBIE_NAME
		```
	- [x] add: member func `Zombie* newZombie( std::string name );`
		- create a zombie
		- name it
		- just returns it (for use outside the func scope)
	- [x] add: member func `void randomChump( std::string name );`
		- create a zombie
		- name it
		- make it announce itself
- [x] zombies are destroyed after its use
- [x] add: destructor
	- print a message with the name of it

## to think
- where to allocate zombies? stack or heap
- newZombie used heap (alloc, to return zombie)
- randomChump used stack (no need to dynamiclly allc)