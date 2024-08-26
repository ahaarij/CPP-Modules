/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:12:04 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/26 14:54:48 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <strings.h>


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
	std::string		getfirstname(void);
	std::string		getlastname(void);
	std::string		getnickname(void);
	std::string		getnumber(void);
	std::string		getsecret(void);
};

class phonebook
{
private:
	contactinfo _contact[8];
	int	_i;
public:
	phonebook(void);
	~phonebook(void);
	void			add(void);
	void			search(void);
};

int	search_interface(contactinfo _contact[8], int _i);

// put _ in private classes cuz its just a common naming convention to avoid confusion i guess
// probs for dum people ( i will forget no doubt )

#endif
