/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:20:32 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/02 10:48:13 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon;
    public:
        HumanA(std::string str, Weapon &Weapon);
        ~HumanA();
        void    attack();
    };
