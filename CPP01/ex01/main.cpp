/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:22 by ahaarij           #+#    #+#             */
/*   Updated: 2024/10/01 08:46:12 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int amount = 5;
	int	i = 0;
	Zombie *horde = zombieHorde(amount, "aarij");
	while(i < amount)
	{
		horde[i].announce();
		i++;		
	}
	delete [] horde;
}
