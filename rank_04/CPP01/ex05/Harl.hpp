#ifndef HARL_CPP
#define HARL_CPP

#include <string>
#include <iostream>

using	namespace std;

class Harl{

public:
				Harl(); //default construcgtor
				~Harl(); //deconst
	void		complain( std::string level );

private:
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );

	string		_levels[4]; //= {"DEBUG", "INFO", "WARNING", "ERROR"};

};

#endif