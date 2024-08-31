/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 01:39:06 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/31 22:03:32 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*              Constructor & Destructor              */

Account::Account(int initial_deposit )
{
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_nbAccounts = getNbAccounts();
    this->_amount = initial_deposit;
    Account::_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
    Account::_nbAccounts++;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
    Account::_nbAccounts++;
}

/*              Getters             */

int    Account::getNbAccounts()
{
    return(_nbAccounts);
}

int    Account::getTotalAmount()
{
    return(_totalAmount);
}

int    Account::getNbDeposits()
{
    return(_totalNbDeposits);
}

int    Account::getNbWithdrawals()
{
    return(_totalNbWithdrawals);
}

int     Account::checkAmount(void) const
{
    return(this->_amount);
}

/*              Functions               */

void    Account::_displayTimestamp()
{
    time_t  current_time;
    current_time = time(NULL);
    std::cout << std::put_time(localtime(&current_time), "[%Y%m%d_%H%M%S] ");
}



void    Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::makeDeposit(int amount)
{
    this->_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount" << this->_totalAmount << ";deposit:" << amount << ";amount:" << this->_totalAmount + amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_totalAmount += amount;
    Account::_totalNbDeposits++;
    Account::_totalAmount += amount;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount" << this->_totalAmount << ";withdrawal:";
    if(withdrawal > this->checkAmount())
    {
        std::cout << "reused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->checkAmount() - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    this->_amount -= withdrawal;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    return (true);
}
