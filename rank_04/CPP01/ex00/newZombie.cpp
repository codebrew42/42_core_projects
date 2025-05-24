#include "Zombie.hpp"

/* wrong approach
//ver1: class
class NewZombie
{
private:


public:



};
*/

//ver2 : just function => is possible, erwuenscht
Zombie* NewZombie( string name )
{
	Zombie* z = new Zombie(name);
	return z;
};