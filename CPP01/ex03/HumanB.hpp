/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:01:11 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/30 18:53:45 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

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

#endif
