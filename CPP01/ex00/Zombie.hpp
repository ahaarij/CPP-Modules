/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:24:39 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/28 11:50:09 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
