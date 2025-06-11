#ifndef HARL_CPP
#define HARL_CPP

#include <string>
#include <iostream>

using					std::cerr;
using					std::string;
using					std::cout;
using					std::endl;

int	displayErrorMessage(const char* message);
int	displayMessage(const char* message);

class Harl{

public:
				Harl(); //default construcgtor
				Harl( const Harl& source );
				~Harl();
	void		complain( std::string level );

private:
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );

	string		_levels[4]; //= {"DEBUG", "INFO", "WARNING", "ERROR"};
	//void		ptrs[4];	//wrong
	void (Harl::*_ptrs[4])(void); //arr of memb func ptr
};

#endif