#include "Account.hpp"

using	std::cout;
using	std::endl;

//4 members: static (can't be init in init list of class)
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account( int initial_deposit )
	: _accountIndex(Account::_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) //check: wrong
{
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::Account( const Account& source )
	: _accountIndex(Account::_nbAccounts++),
		_amount(source._amount),
		_nbDeposits(source._nbDeposits),
		_nbWithdrawals(source._nbWithdrawals)
{
	Account::_totalAmount += _amount;
}

Account& Account::operator=( const Account& source)
{
	if (this != &source)
	{
		Account::_totalAmount += source._amount - _amount;
		_amount = source._amount;
		_nbDeposits = source._nbDeposits;
		_nbWithdrawals = source._nbWithdrawals;
	}
	return *this;
}

Account::~Account() {
	Account::_displayTimestamp();
	cout << " index:" << Account::_accountIndex;
	cout << ";amount:" << Account::_amount;
	cout << ";closed" << endl;
}


void	Account::_displayTimestamp( void )
{
	time_t			rawTime;
	struct tm		*timeInfo;
	char			buffer[16];

	time (&rawTime); //get current time => put it to *rawTime
	timeInfo = localtime(&rawTime); //localize: rawTime => ret struct tm
	strftime(buffer, 16, "%Y%m%d_%H%M%S", timeInfo); //format to MAXSIZE
	cout << "[" << buffer << "]";
}


void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	int		temp = Account::getNbAccounts();
	cout << " accounts:" << temp;
	temp = getTotalAmount();
	cout << ";total:" << temp;
	temp = getNbDeposits();
	cout << ";deposits:" << temp;
	temp = getNbWithdrawals();
	cout << ";withdrawals:" << temp << endl;

}


int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	cout << " index:" << _accountIndex;
	cout << ";amount:" << _amount;
	cout << ";deposits:" << _nbDeposits;
	cout << ";withdrawals:" << _nbWithdrawals << endl;
}


void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	cout << " index:" << _accountIndex;
	cout << ";p_amount:" << _amount;
	cout << ";deposit:" << deposit;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	cout << ";amount:" << _amount;
	Account::_nbDeposits += 1;
	_totalNbDeposits++;
	cout << ";nb_deposits:" << _nbDeposits << endl;
}

int		Account::checkAmount( void ) const
{
	return 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    cout << " index:" << _accountIndex;
    cout << ";p_amount:" << _amount;
    if (_amount < withdrawal)
    {
        cout << ";withdrawal:refused" << endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    cout << ";withdrawal:" << withdrawal;
    cout << ";amount:" << _amount;
    cout << ";nb_withdrawals:" << _nbWithdrawals << endl;
    return true;
}


/*
Q. why int here is not allowed/necessary?
Q. why const here isn't meaningful?
*/