/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:01:16 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/24 16:07:56 by ahaarij          ###   ########.fr       */
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
int	phonebook::exiteof(void)
{
	if(std::cin.eof() || std::cin.fail())
		exit(1);
	return 0;
}
void	phonebook::add(void)
{
	std::string str;
	str = "";

	if(_i > 7)
	{
		std::cout << "Overwriting " << this->_contact[this->_i % 8].getfirstname() << std::endl;
	}
	while((exiteof() == 0) && str == "")
	{
		std::cout << "Enter First Name:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setfirstname(str);
	}
	str = "";
	while((exiteof() == 0) && str == "")
	{
		std::cout << "Enter Last Name:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setlastname(str);
	}
	str = "";
	while((exiteof() == 0) && str == "")
	{
		std::cout << "Enter Nickname:\n";
		if(std::getline(std::cin, str) && str != "")
			this->_contact[_i % 8].setnickname(str);
	}
	str = "";
	while((exiteof() == 0) && str == "")
	{
		std::cout << "Enter Phone Number 😏:\n";
		if(std::getline(std::cin, str) && str != "")
		{
			if(str.find_first_not_of("0123456789"))
				this->_contact[_i % 8].setnumber(str);
			else{
				std::cout << "Invalid Input\n";
				str = "";
			}
		}
	}
	str = "";
	while((exiteof() == 0) && str == "")
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
	std::cout GREEN << "First Name     : " << contact.getfirstname() << std::endl;
	std::cout << "Last Name      : " << contact.getlastname() << std::endl;
	std::cout << "Nick Name      : " << contact.getnickname() << std::endl;
	std::cout << "Phone Number   : " << contact.getnumber() << std::endl;
	std::cout << "Darkest Secret : " << contact.getsecret() << std::endl;
}

void	phonebook::search(void)
{
	std::string str;
	if(this->_i <= 0 || (!search_interface(this->_contact)))
	{
		std::cout << RED << "Phonebook is empty!" << RESET << std::endl;
		return ;
	}
	while(!std::cin.eof() || !std::cin.fail())
	{
		std::cout << BLUE << "Enter an index : " << RESET ;
		if(std::getline(std::cin, str) && str != "")
		{
			if(str.size() == 1 && (str[0] >= '1' && str[0] <= '8' && this->_contact[str[0] - 1 - '0'].getfirstname().size()))
				break;
		}
		if (str != "")
			std::cout << RED << "Invalid index" << RESET << std::endl;
	}
	if(!std::cin.eof() && !std::cin.fail())
		this->print(this->_contact[str[0] - 1 - '0']);
	else
	{
		std::cout << std::endl << RED << "Exiting now" << RESET << std::endl;
		exit(1);
	}
}

int	main()
{
	phonebook ph;
	std::string str;
	while(str != "EXIT")
	{
		std::cout << YELLOW << "Phonebook : " << RESET;
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
