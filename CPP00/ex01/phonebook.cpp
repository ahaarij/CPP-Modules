/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:01:16 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/28 00:33:00 by ahaarij          ###   ########.fr       */
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

void	phonebook::print(contactinfo contact)
{
	if(!contact.getfirstname().size())
	{
		std::cout << "Contact does not exist!\n";
		return ;
	}
	std::cout << "First Name     : " << contact.getfirstname() << std::endl;
	std::cout << "Last Name      : " << contact.getlastname() << std::endl;
	std::cout << "Nick Name      : " << contact.getnickname() << std::endl;
	std::cout << "Phone Number   : " << contact.getnumber() << std::endl;
	std::cout << "Darkest Secret : " << contact.getsecret() << std::endl;
}

void	phonebook::search(void)
{
	std::string str;
	if(!search_interface(this->_contact))
	{
		std::cout << "Phonebook is empty!!!!\n";
		return ;
	}
	while(!std::cin.eof())
	{
		std::cout << "Enter an index : ";
		if(std::getline(std::cin, str) && str != "")
		{
			if(str.size() == 1 && (str[0] >= '1' && str[0] <= '8' && this->_contact[str[0] - 1 - '0'].getfirstname().size()))
				break;
		}
		if (str != "")
			std::cout << "invalid index\n";
	}
	if(!std::cin.eof())
		this->print(this->_contact[str[0] - 1 - '0']);
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
