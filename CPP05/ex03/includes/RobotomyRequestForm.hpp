#pragma once

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form;

class RobotomyRequestForm : public Form
{
    private:
        const std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);
		void	execute(Bureaucrat const &copy)const;
		std::string	getTarget(void)const;
};

std::ostream	&operator<<(std::ostream &c, RobotomyRequestForm &copy);
