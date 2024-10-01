/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:48:48 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/30 18:55:09 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <iomanip>

class Harl
{
private:
	void	_debug(void);
	void	_info(void);
	void	_error(void);
	void	_warning(void);
public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif
