/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:01:16 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/26 14:56:40 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

contactinfo::contactinfo(void)
{
}

contactinfo::~contactinfo(void)
{
}

phonebook::phonebook(void)
{
	_i = 0;
}

phonebook::~phonebook(void)
{
}

void	phonebook::add(void)
{
	std::string str;
	str = "";

	if(_i > 7)
	{
		std::cout << "Overwriting " << this->_contact[this->_i % 8].getfirstname() << std::endl;
	}
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter First Name:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setfirstname(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter Last Name:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setlastname(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter Nickname:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setnickname(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter Phone Number 😏:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setnumber(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter Darkest Secret 👹:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setsecret(str);
	}
	this->_i++;
}


void	phonebook::search(void)
{
	std::string str;
	search_interface(this->_contact, _i);
	// if()
	// while(!std::cin.eof())
	// {
		// 
	// }
}

int	main()
{
	phonebook ph;
	std::string str;
	while(str != "EXIT")
	{
		std::cout << "Phonebook : ";
		std::getline(std::cin, str);
		if(str == "ADD")
		{
			ph.add();
		}
		else if(str == "SEARCH")
		{
			ph.search();
		}
		else if(std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
