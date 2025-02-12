#include "../includes/Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constructor called!" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern Copy Constructor called!" << std::endl;
    *this = copy;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called!" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern Assignment Operator Overload ( = ) called!" << std::endl;
    if(this == &copy) // ion really need this
        return *this;
    return *this;
}

static Form *retPresident(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

static Form *retRobot(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

static Form *retShrub(const std::string target)
{
    return(new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(const std::string form, const std::string target)
{
    Form *(*formFuncs[])(const std::string target) = {&retPresident, &retRobot, &retShrub};
    std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int i = 0;
    while(i < 3)
    {
        if(forms[i] == form)
        {
            std::cout << "Intern Creates " << form << " for " << target << std::endl;
            return(formFuncs[i](target));
        }
        i++;
    }
    std::cout << "Intern can't create a form called '" << form << "'!" << std::endl;
    return (NULL);
}