#ifndef HUMANB_HPP
#define HUMANB_HPP

#include	<string>
#include	<iostream>
#include	"Weapon.hpp"

using		std::string;
using		std::cout;
using		std::endl;

class	HumanB
{
public:
						HumanB( string name );
						HumanB( const HumanB& source );
						~HumanB();
	void				attack() const;
	void				attack( Weapon *weapon ) const;
	void				setWeapon( Weapon *wepon );
	Weapon*				_weapon;

private:
			string		_name;
};


#endif