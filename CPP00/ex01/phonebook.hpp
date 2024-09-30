/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:12:04 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/30 08:42:54 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <strings.h>
#include <cstdlib>
#include "Contact.hpp"

# define RESET		"\x1b[0m"
# define BOLD		"\x1b[1m"
# define UNDER		"\x1b[4m"
# define REV		"\x1b[7m"
# define GREY		"\x1b[30m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define PURPLE		"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1b[37m"

class PhoneBook
{
private:
	Contact _contact[8];
	int	_i;
public:
	PhoneBook(void);
	~PhoneBook(void);
	int			exiteof(void);
	void			add(void);
	void			search(void);
	void			print(Contact contact);
};

int	search_interface(Contact _contact[8]);
bool	isStringWhitespaces(const std::string str);

#endif
