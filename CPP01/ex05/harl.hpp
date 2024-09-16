/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:48:48 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/04 16:53:14 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
