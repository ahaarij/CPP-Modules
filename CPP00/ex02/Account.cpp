/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 01:39:06 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/25 19:15:30 by ahaarij          ###   ########.fr       */
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
    this->_accountIndex = getNbAccounts();
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
    return(Account::_nbAccounts);
}

int    Account::getTotalAmount()
{
    return(Account::_totalAmount);
}

int    Account::getNbDeposits()
{
    return(Account::_totalNbDeposits);
}

int    Account::getNbWithdrawals()
{
    return(Account::_totalNbWithdrawals);
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
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << amount << ";amount:" << this->_amount + amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount += amount;
    Account::_totalNbDeposits++;
    Account::_totalAmount += amount;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if(withdrawal > this->checkAmount())
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->checkAmount() - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    return (true);
}
