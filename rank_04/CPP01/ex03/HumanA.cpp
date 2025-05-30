#include "HumanA.hpp"

/* why is not possible? Weapon& _wepon
HumanA::HumanA() : _name(NULL), _weapon(NULL) {};
*/
HumanA::HumanA( string name, Weapon& weapon ) 
	: _name(name), _weapon(weapon) {}

HumanA::HumanA( const HumanA& source ) 
	: _name(source._name), _weapon(source._weapon) {}

HumanA::~HumanA() {};

void	HumanA::attack() const
{
	cout << _name << " attacks with their " << _weapon.getType() << endl;
}