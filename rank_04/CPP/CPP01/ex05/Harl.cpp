#include "Harl.hpp"

//public
Harl::Harl() {
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";

	_ptrs[0] = &Harl::debug;
	_ptrs[1] = &Harl::info;
	_ptrs[2] = &Harl::warning;
	_ptrs[3] = &Harl::error;
}

Harl::Harl( const Harl& source ) 	//: _levels(source._levels) {} //at once: c++11
{
	for (int i = 0; i < 4; i++)
	{
		_levels[i] = source._levels[i];
	}
}

Harl::~Harl() {}

void Harl::complain( string level )
{
	int		functionCalled = 0;

	for (int i = 0; i < 4; i++)
	{
		if (_levels[i] == level)
		{
			(this->*_ptrs[i])();
			functionCalled = 1;
		}
	}
	if (!functionCalled)
		displayMessage("<level> must be either DEBUG, INFO, WARNING, or ERROR");
}

//private
void Harl::debug( void )
{
	displayMessage("* * THIS IS DEBUGGING MESSAGE* * ");
}

void Harl::info( void )
{
	displayMessage("* * THIS IS INFO * * ");
}

void Harl::warning( void )
{
	displayMessage("* * THIS IS WARNING * * ");
}

void Harl::error( void )
{
	displayErrorMessage("* * THIS IS ERROR MESSAGE * * ");
}