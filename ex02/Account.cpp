#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits)
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << _displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account (int initial_deposit)
{
	this->_amount = 0;
	this->_amount += initial_deposit;

	std::cout << _displayTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

~Account (void)
{
	std::cout << _displayTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	makeDeposit( int deposit )
{
	std::cout << _displayTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";;
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	makeWithdrawal( int withdrawal )
{
	int p_amount = checkAmount();
	int amount = p_amount - withdrawal;

	std::cout << _displayTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (amount >= 0)
	{
		std::cout << "withdrawal:" << withdrawal << ";";;
		this->_amount -= withdrawal;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
}

int		checkAmount( void ) const
{
	return (this->_amount);
}

void	displayStatus( void ) const
{
	std::cout << _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

static void	Account::_displayTimestamp( void )
{
	time_t timestamp;

	time(&timestamp);

	std::cout << ctime(&timestamp);
}