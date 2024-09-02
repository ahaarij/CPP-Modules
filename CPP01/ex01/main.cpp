/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:22 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/30 17:33:53 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int len, std::string str);

int	main()
{
	int amount = 2;
	int	i = 0;
	Zombie *horde = zombieHorde(amount, "aarij");
	while(i < amount)
	{
		horde[i].announce();
		i++;		
	}
	delete []horde;
}
