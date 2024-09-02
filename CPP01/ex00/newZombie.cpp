/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newzombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:38:59 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/28 12:25:39 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string str)
{
	return (new Zombie(str));
}
