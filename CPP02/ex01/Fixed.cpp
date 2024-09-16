/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:21:42 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/11 13:38:02 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _num(0)
{
	std::cout << "Default Constructor called!" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int Constructor called!" << std::endl;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called!" << std::endl;
}
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy Constructor called!" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called!" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_num = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_num);
}

void	Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}