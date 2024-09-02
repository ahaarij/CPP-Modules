/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:13 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/30 17:35:49 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int len, std::string str)
{
	if(len < 0)
		return NULL;
	Zombie *horde = new Zombie[len];
	int i = -1;
	while(++i < len)
		horde[i].setname(str);
	return (horde);
}
