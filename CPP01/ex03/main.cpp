/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:36:56 by ahaarij           #+#    #+#             */
/*   Updated: 2024/10/01 08:59:45 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    std::cout << "--------------------------------------" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    std::cout << "--------------------------------------" << std::endl;
    {
        Weapon club = Weapon("spear");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("axe");
        jim.attack();
    }
    std::cout << "--------------------------------------" << std::endl;
    return (0);
}
