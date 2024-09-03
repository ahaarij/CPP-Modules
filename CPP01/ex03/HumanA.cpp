/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:12:58 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/03 13:29:10 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &Weapon):_weapon(Weapon)
{
	this->_name = str;
	std::cout << this->_name << " is here with " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " just died loool" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacked with " << this->_weapon.getType() << std::endl;
}
