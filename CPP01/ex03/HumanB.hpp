/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:01:11 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/03 13:26:58 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon	*_weapon;
public:
	HumanB(std::string str);
	~HumanB();
	void	setWeapon(Weapon &weapon);
    void    attack();
};
