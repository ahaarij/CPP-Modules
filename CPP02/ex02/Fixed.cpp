/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:21:42 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/20 10:16:37 by ahaarij          ###   ########.fr       */
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
	_num = value << _bits;
} // shifting 8 to the left is essetially multipliying. so like if value was 8, it would be like 8 * 2^8 (256) so i would be storing 1280 (this would nnow be fixed point)

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called!" << std::endl;
	_num = (int)roundf(value * (1 << _bits));
} //same thing as before with the shifting, storing it as aa fixed point. roundf rounds to the nearest integer (less than 0.5 would be round down and 0.5 and more would be up). 
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy Constructor called!" << std::endl;
	*this = f;
}

int Fixed::toInt() const
{
	return (int)(_num >> _bits);
} // nonw we're shifting right, so we're essenntially doing value / 2^8 (256). so the 1280 from the int constructor would be 1280 / 256 = 8.

float Fixed::toFloat() const
{
	return(float)_num / (float)(1 << _bits);
} // so first part of this division would be the value, so lets say the value is 512 for example, and the second part would be 256 as we're left shiftinng 1 by 256. so 512/ 256 = 2.00;

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

// ex02 part

bool	Fixed::operator>(Fixed const &copy)
{
	return (this->toFloat() > copy.toFloat());
}

bool	Fixed::operator>=(Fixed const &copy)
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<(Fixed const &copy)
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator<=(Fixed const &copy)
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator==(Fixed const &copy)
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(Fixed const &copy)
{
	return (this->toFloat() != copy.toFloat());
}

float	Fixed::operator+(Fixed const &copy)
{
	return (this->toFloat() + copy.toFloat());	
}

float	Fixed::operator-(Fixed const &copy)
{
	return (this->toFloat() - copy.toFloat());
}

float	Fixed::operator*(Fixed const &copy)
{
	return (this->toFloat() * copy.toFloat());
}

float	Fixed::operator/(Fixed const &copy)
{
	return (this->toFloat() / copy.toFloat());
}

Fixed	Fixed::operator++(void)
{
	this->_num++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_num--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_num;
	return (temp);	
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_num;
	return (temp);
}

Fixed	Fixed::min(Fixed &first, Fixed &second)
{
	if(first.toFloat() <= second.toFloat())
		return (first);
	else
		return(second);
}

const Fixed Fixed::min(Fixed const &first, Fixed const &second)
{
	if(first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	Fixed::max(Fixed &first, Fixed &second)
{
	if(first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed Fixed::max(Fixed const &first, Fixed const &second)
{
	if(first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

std::ostream &operator<<(std::ostream &c, Fixed const &copy)
{
	c << copy.toFloat();
	return (c);
}
