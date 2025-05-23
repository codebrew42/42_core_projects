#include "Account.hpp"

using	std::cout;


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	: _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) //check: wrong
{
	Account::_nbDeposits += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}
Account::~Account() {}


void	Account::_displayTimestamp( void )
{
	time_t	rawTime;
	
	time (rawTime);
}

void	Account::displayAccountsInfos( void )
{

}

/*
int	Account::getNbAccounts( void )
{
}

int	Account::getTotalAmount( void )
{

}

int	Account::getNbDeposits( void )
{

}

int	Account::getNbWithdrawals( void )
{

}


void	makeDeposit( int deposit )
{

}

bool	makeWithdrawal( int withdrawal )
{

}

int		checkAmount( void ) const
{

}

void	displayStatus( void ) const
{

}
*/


/*
Q. why int here is not allowed/necessary?
Q. why const here isn't meaningful?
*/