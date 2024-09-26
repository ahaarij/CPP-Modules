/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:20:06 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/24 17:06:41 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setfirstname(std::string str)
{
	this->_first_name = str;
}

void	Contact::setlastname(std::string str)
{
	this->_last_name = str;
}

void	Contact::setnickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::setnumber(std::string str)
{
	this->_number = str;
}

void	Contact::setsecret(std::string str)
{
	this->_secret = str;
}

std::string	Contact::getfirstname(void) const
{
	return (this->_first_name);
}

std::string	Contact::getlastname(void) const
{
	return (this->_last_name);
}

std::string	Contact::getnickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getnumber(void) const
{
	return (this->_number);
}

std::string	Contact::getsecret(void) const
{
	return (this->_secret);
}
