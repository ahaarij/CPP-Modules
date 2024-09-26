/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:11:05 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/25 09:02:41 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string		spaces(int n)
{
	std::string str;
	while(n--)
		str.append(" ");
	return(str);
}

std::string		setwidth(std::string str, unsigned int len)
{
	if(str.size() > len)
	{
		str.resize(len);
		str[str.size() -1] = '.';
	}
	return (str);
}

int	search_interface(Contact contact[8])
{
	int i = 0;
	char c = '0';
	std::string str;
	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "|----------|----------|----------|----------|\n";
	while(++c <= '8')
	{
		if(contact[c - 1 - '0'].getfirstname().size() && ++i)
		{
			str = c;
			str = setwidth(str, 10);
			std::cout << '|' << spaces(10 - str.size()) << str;
			str = setwidth(contact[c - 1 - '0'].getfirstname(), 10);
			std::cout << '|' << spaces(10 - str.size()) << str;
			str = setwidth(contact[c - 1 - '0'].getlastname(), 10);
			std::cout << '|' << spaces(10 - str.size()) << str;
			str = setwidth(contact[c - 1 - '0'].getnickname(), 10);
			std::cout << '|' << spaces(10 - str.size()) << str;
			std::cout << '|' << std::endl;
		}
	}
	std::cout << "---------------------------------------------\n";
	return (i);
}
