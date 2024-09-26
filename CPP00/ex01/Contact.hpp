#ifndef CONTACTINFO_HPP
# define CONTACTINFO_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_secret;
	std::string	_number;
public:
	Contact(void);
	~Contact(void);
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

#endif
