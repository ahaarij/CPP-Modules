#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class Form;

class ShrubberyCreationForm : public Form
{
    private:
        const std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
        void    execute(Bureaucrat const &copy)const;
        std::string getTarget(void)const;
};

std::ostream &operator<<(std::ostream &c, ShrubberyCreationForm &copy);
