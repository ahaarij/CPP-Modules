/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:02:41 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/03 13:21:29 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <iomanip>

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string Weapon);
    ~Weapon();
    std::string getType() const;
    void    setType(std::string type);
};

#endif
