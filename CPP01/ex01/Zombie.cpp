/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:17 by ahaarij           #+#    #+#             */
/*   Updated: 2024/10/01 08:48:21 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str)
{
	this->_name = str;
	std::cout << "Successfully created : " << this->_name << std::endl;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie()
{
	std::cout << "Successfully destroyed : " << this->_name << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string str)
{
	this->_name = str;
}
