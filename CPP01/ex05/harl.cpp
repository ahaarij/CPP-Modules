/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:50:32 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/04 16:59:55 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl()
{
	;
}

Harl::~Harl()
{
	;
}

void	Harl::_debug(void)
{
	std::cout << "+---------------------------------------------------------------------------------------+" << std::endl;
	std::cout << "|Ackshually i berieve the ewwor with the code is because the compyuter cant compile it🥺|" << std::endl;
	std::cout << "+---------------------------------------------------------------------------------------+" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "+--------------------------------------------------------------------------------------+" << std::endl;
	std::cout << "|Ackshually for your information, nothing is wrong with my code, its you thats wrong 🤓|" << std::endl;
	std::cout << "+--------------------------------------------------------------------------------------+" << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "+----------------------------------------------------------+" << std::endl;
	std::cout << "|Wait, w-what, what the hell happened what did you do 🙁🙁🙁|" << std::endl;
	std::cout << "+----------------------------------------------------------+" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << "|Im warning you buddy you better watch it! 👹👹👹|" << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
}

void	Harl::complain(std::string str)
{
	void (Harl::*functions[])(void) = {&Harl::_debug, &Harl::_info, &Harl::_error, &Harl::_warning}; 
	std::string complaints[] = {"DEBUG", "INFO", "ERROR", "WARNING"};
	int i = 0;
	while(i < 4)
	{
		if(complaints[i] == str)
			(this->*functions[i])();
		i++;
	}
}
