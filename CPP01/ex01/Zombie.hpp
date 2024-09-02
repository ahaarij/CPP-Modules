/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:11 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/30 17:32:28 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
