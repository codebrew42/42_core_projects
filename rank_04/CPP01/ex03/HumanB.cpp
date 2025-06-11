#include	"HumanB.hpp"

/*ver1: track weapon by value
	- creates a copy
	- (-) dangling ptr
		- why? local cp dstr-ed when FUNC exits
				-> _weapon = dgl ptr to dest-ed mem
HumanB::HumanB( string name, Weapon weapon )
	: _name(name), _weapon(&weapon) {};
*/

/*ver2 : track weapon by ptr
	- no cpy
	- mem ownership maintained
*/
HumanB::HumanB( string name )
	: _name(name) {}

HumanB::HumanB( const HumanB& source )
	: _name(source._name) {}

HumanB::~HumanB() {}

void	HumanB::attack() const
{
	if ( _weapon == NULL )
		cout << _name << " attacks with no weapons" << endl;
	else
		cout << _name << " attacks with their " << _weapon->getType() << endl;
}

void	HumanB::attack( Weapon* weapon ) const
{
	if ( weapon == NULL )
		cout << _name << " attacks with no weapons" << endl;
	else
		cout << _name << " attacks with their " << weapon->getType() << endl;
}

void	HumanB::setWeapon( Weapon* weapon )
{
	_weapon = weapon;
}
