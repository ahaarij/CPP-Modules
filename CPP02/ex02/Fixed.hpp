/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:42:09 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/20 10:15:08 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iomanip>
#include <iostream>

class Fixed
{
private:
	int _num;
	static const int _bits;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &f);
	~Fixed();
	//operator overloaded
	Fixed &operator=(Fixed const &copy);
	// bool comparison operator overloads
	bool operator>(Fixed const &copy);
	bool operator>=(Fixed const &copy);
	bool operator<(Fixed const &copy);
	bool operator<=(Fixed const &copy);
	bool operator==(Fixed const &copy);
	bool operator!=(Fixed const &copy);
	// arithmetic operaror overloads
	float operator+(Fixed const &copy);
	float operator-(Fixed const &copy);
	float operator/(Fixed const &copy);
	float operator*(Fixed const &copy);
	// increment and decrement overloads
	Fixed operator++(void);
	Fixed operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	// getters and setters
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	// pub funcs
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed	min(Fixed &first, Fixed &second);
	static const Fixed min(Fixed const &first, Fixed const &second);
	static Fixed	max(Fixed &first, Fixed &second);
	static const Fixed max(Fixed const &first, Fixed const &second);
};

std::ostream &operator<<(std::ostream &c, Fixed const &copy);

#endif
