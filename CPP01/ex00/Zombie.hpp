/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:24:39 by ahaarij           #+#    #+#             */
/*   Updated: 2024/10/01 08:46:48 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <strings.h>
#include <iomanip>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string str);
		~Zombie();
		void	announce(void);
};

Zombie*	newZombie(std::string str);
void	randomChump(std::string str);

#endif
