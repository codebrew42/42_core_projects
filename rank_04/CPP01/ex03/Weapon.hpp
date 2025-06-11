#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

using		std::string;

class	Weapon
{
public:
					Weapon( void );
					Weapon( string type );
					Weapon( const Weapon& source );
					~Weapon( void );
	const string&	getType( void ) const;
	void			setType( string type );

private:
	string	_type;
};

#endif