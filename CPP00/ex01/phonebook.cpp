/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:01:16 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/25 09:30:52 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	isStringWhitespaces(const std::string str)
{
	size_t i = 0;
	while(i < str.length())
	{
		char c = str[i];
		if(c != ' ' && c != '\t')
			return (false);
		i++;
	}
	return (true);
}

PhoneBook::PhoneBook(void)
{
	_i = 0;
}

PhoneBook::~PhoneBook(void)
{
}
int	PhoneBook::exiteof(void)
{
	if(std::cin.eof() || std::cin.fail())
	{
		std::cout << std::endl << RED << "Exiting now" << RESET << std::endl;
		exit(1);
	}
	return 0;
}
void	PhoneBook::add(void)
{
	std::string str;
	str = "";

	if(_i > 7)
	{
		std::cout << BOLD << YELLOW << "Overwriting " << RESET << this->_contact[this->_i % 8].getfirstname() << std::endl;
	}
	while((exiteof() == 0) && str == "")
	{
		std::cout << CYAN << "Enter First Name:" << RESET << std::endl;;
		if(std::getline(std::cin, str) && str != "")
		{
			if(!isStringWhitespaces(str))
				this->_contact[_i % 8].setfirstname(str);
			else
			{
				std::cout << RED << "Invalid Input" << RESET <<std::endl;
				str = "";
			}
		}
	}
	str = "";
	while((exiteof() == 0) && str == "")
	{
		std::cout << CYAN << "Enter Last Name:" << RESET << std::endl;
		if(std::getline(std::cin, str) && str != "")
		{
			if(!isStringWhitespaces(str))
				this->_contact[_i % 8].setlastname(str);
			else
			{
				std::cout << RED << "Invalid Input" << RESET <<std::endl;
				str = "";
			}
		}
	}
	str = "";
	while((exiteof() == 0) && str == "")
	{
		std::cout << CYAN << "Enter Nickname:" << RESET << std::endl;
		if(std::getline(std::cin, str) && str != "")
		{
			if(!isStringWhitespaces(str))
				this->_contact[_i % 8].setnickname(str);
			else
			{
				std::cout << RED << "Invalid Input" << RESET <<std::endl;
				str = "";
			}
		}
	}
	str = "";
	while((exiteof() == 0) && str == "")
	{
		std::cout << CYAN << "Enter Phone Number 😏:" << RESET << std::endl;
		if(std::getline(std::cin, str) && str != "")
		{
			if(str.find_first_not_of("0123456789"))
				this->_contact[_i % 8].setnumber(str);
			else
			{
				std::cout << RED << "Invalid Input" << RESET <<std::endl;
				str = "";
			}
		}
	}
	str = "";
	while((exiteof() == 0) && str == "")
	{
		std::cout << CYAN << "Enter Darkest Secret 👹:" << RESET << std::endl;
		if(std::getline(std::cin, str) && str != "")
		{
			if(!isStringWhitespaces(str))
				this->_contact[_i % 8].setsecret(str);
			else
			{
				std::cout << RED << "Invalid Input" << RESET <<std::endl;
				str = "";
			}
		}
	}
	this->_i++;
}

void	PhoneBook::print(Contact contact)
{
	if(!contact.getfirstname().size())
	{
		std::cout << RED << "Contact does not exist!" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "First Name     : " << RESET << contact.getfirstname() << std::endl;
	std::cout << GREEN << "Last Name      : " << RESET << contact.getlastname() << std::endl;
	std::cout << GREEN << "Nick Name      : " << RESET << contact.getnickname() << std::endl;
	std::cout << GREEN << "Phone Number   : " << RESET << contact.getnumber() << std::endl;
	std::cout << GREEN << "Darkest Secret : " << RESET << contact.getsecret() << std::endl;
}

void	PhoneBook::search(void)
{
	std::string str;
	if(this->_i <= 0 || (!search_interface(this->_contact)))
	{
		std::cout << RED << "PhoneBook is empty!" << RESET << std::endl;
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
	PhoneBook ph;
	std::string str;
	while(str != "EXIT")
	{
		std::cout << PURPLE << "Operations: 'ADD' 'SEARCH' 'EXIT'" << RESET << std::endl;
		std::cout << YELLOW << "PhoneBook : " << RESET;
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
			std::cout << std::endl << RED << "Exiting now" << RESET << std::endl;
			return (0);
		}
	}
	std::cout << RED << "Exiting now" << RESET << std::endl;
	return (0);
}
