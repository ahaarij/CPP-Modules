/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:25:53 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/28 11:48:22 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string str);
void	randomChump(std::string str);

int	main()
{
	Zombie *zombie=newZombie("aarij");
	zombie->announce();
	randomChump("h");
	delete zombie;
}
