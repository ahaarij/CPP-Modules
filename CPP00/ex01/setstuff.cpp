/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstuff.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:20:06 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/26 13:47:14 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	contactinfo::setfirstname(std::string str)
{
	this->_first_name = str;
}

void	contactinfo::setlastname(std::string str)
{
	this->_last_name = str;
}

void	contactinfo::setnickname(std::string str)
{
	this->_nickname = str;
}

void	contactinfo::setnumber(std::string str)
{
	this->_number = str;
}

void	contactinfo::setsecret(std::string str)
{
	this->_secret = str;
}

std::string	contactinfo::getfirstname(void)
{
	return (this->_first_name);
}

std::string	contactinfo::getlastname(void)
{
	return (this->_last_name);
}

std::string	contactinfo::getnickname(void)
{
	return (this->_nickname);
}

std::string	contactinfo::getnumber(void)
{
	return (this->_number);
}

std::string	contactinfo::getsecret(void)
{
	return (this->_secret);
}
