#include "mem1.hpp"

int main()
{
	//1.alloc on heap
	Zombie* z = new Zombie("Bob");
	delete z; //call destructor && free mem

	//2.alloc on stack
	Zombie y("Alice"); //automatically destroyed when scope ends


}