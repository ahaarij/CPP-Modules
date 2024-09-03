/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:36:56 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/03 13:36:21 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        }
    {
        Weapon club = Weapon("spear");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("axe");
        jim.attack();
    }
return (0);
}
