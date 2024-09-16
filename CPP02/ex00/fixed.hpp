/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:14:29 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/09 09:22:57 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

class Fixed
{
private:
	int _num;
	static const int _bits;
public:
	Fixed();
	Fixed(const Fixed &f);
	~Fixed();
	Fixed &operator=(Fixed const &copy);
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};
