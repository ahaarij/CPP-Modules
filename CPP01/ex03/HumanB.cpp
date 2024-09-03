/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:28:38 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/03 13:35:55 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str)
{
	this->_weapon = NULL;
	this->_name = str;
	std::cout << this->_name << " is here" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " died" << std::endl;	
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << this->_name << " is holding " << this->_weapon->getType() << std::endl;
}

void	HumanB::attack()
{
	if(this->_weapon == NULL)
	{
		std::cout << this->_name << " Punched with his fist" << std::endl;
	}
	else
	{
		std::cout << this->_name << " is attacking with " << this->_weapon->getType() << std::endl;
	}
}
