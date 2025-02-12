#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "iostream"

class Bureaucrat;

class Form;

class PresidentialPardonForm: public Form
{
	private:
		const std::string	_target;
		PresidentialPardonForm(void);
		// this is here cuz ortho cannonical but also like it says only one constructor that takes one param
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);
		void	execute(Bureaucrat const &copy) const;
		std::string	getTarget(void)const;
};

std::ostream	&operator<<(std::ostream &c, PresidentialPardonForm &copy);
