/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:02:41 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/31 23:09:44 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

typedef class Weapon
{
private:
    std::string _type;
public:
    Weapon(/* args */);
    ~Weapon();
    std::string &getType(void);
    void    setType(std::string type);
};
