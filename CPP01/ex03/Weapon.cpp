/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:22:20 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/03 13:37:06 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	this->setType(weapon);
}

Weapon::~Weapon()
{
	std::cout << this->getType() << " was thrown away!" << std::endl;
}

std::string Weapon::getType() const
{
	return (_type);
}

void    Weapon::setType(std::string type)
{
	_type = type;
}
