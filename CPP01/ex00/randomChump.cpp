/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomchump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:42:35 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/28 12:25:49 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string str)
{
	Zombie zomboe = Zombie(str);
	zomboe.announce();
}
