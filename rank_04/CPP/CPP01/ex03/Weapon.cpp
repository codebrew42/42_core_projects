#include "Weapon.hpp"

Weapon::Weapon( void ) {}

Weapon::Weapon( string type )
	: _type(type) {}

Weapon::Weapon( const Weapon& source )
{
	if ( this != &source )
		_type = source._type;
}

Weapon::~Weapon( void ) {}

void			Weapon::setType( string type )
{
	_type = type;
}

const string&	Weapon::getType() const
{
	return _type;
}