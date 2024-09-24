/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:12:04 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/24 15:58:00 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <strings.h>

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

class contactinfo
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_secret;
	std::string	_number;
public:
	contactinfo(void);
	~contactinfo(void);
	// setters
	void			setfirstname(std::string str);
	void			setlastname(std::string str);
	void			setnickname(std::string str);
	void			setnumber(std::string str);
	void			setsecret(std::string str);
	// getters
	std::string		getfirstname(void) const;
	std::string		getlastname(void) const;
	std::string		getnickname(void) const;
	std::string		getnumber(void) const;
	std::string		getsecret(void) const;
};

class phonebook
{
private:
	contactinfo _contact[8];
	int	_i;
public:
	phonebook(void);
	~phonebook(void);
	int			exiteof(void);
	void			add(void);
	void			search(void);
	void			print(contactinfo contact);
};

int	search_interface(contactinfo _contact[8]);

// put _ in private classes cuz its just a common naming convention to avoid confusion i guess
// probs for dum people ( i will forget no doubt )

#endif
