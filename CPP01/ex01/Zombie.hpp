/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:11 by ahaarij           #+#    #+#             */
/*   Updated: 2024/10/01 08:46:22 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <strings.h>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string str);
		Zombie(void);
		~Zombie();
		void	announce();
		void	setname(std::string str);
};

Zombie* zombieHorde(int len, std::string str);

#endif
