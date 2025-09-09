#include "Weapon.hpp"
#include <iostream>

using			std::string;
using			std::cout;
using			std::endl;

class	HumanA
{
public:
//				HumanA(); no default cstr this time
				HumanA( string name, Weapon& wepon );
				HumanA( const HumanA& source);
				~HumanA();
	void		attack() const; //use const: x changing obj's memb

private:
	string		_name;
	Weapon&		_weapon;
};