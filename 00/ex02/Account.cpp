#include <iostream>
#include "Account.hpp"

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	static int	accountIndex = getNbAccounts();
	static int	amount = getTotalAmount();
	static int	nbDeposits = getNbDeposits();
	static int	nbWithdrawals = getNbWithdrawals();

	std::cout << accountIndex;
	std::cout << amount;
	std::cout << nbDeposits;
	std::cout << nbWithdrawals;
}
