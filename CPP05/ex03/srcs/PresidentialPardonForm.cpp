#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), _target("Aarij")
{
    std::cout << "PresidentialPardonForm Default Constructor Called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm Created for " << this->getTarget() << "!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): Form("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
    std::cout << "Copy constructor for PresidentialPardonForm " << this->getTarget() << " called!" << std::endl;
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor for PresidentialPardonForm " << this->getTarget() << " called!" << std::endl;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "PresidentialPardonForm Assignment operator overload ( = ) called!" << std::endl;
    if(this == &copy)
        return (*this);
    return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &copy) const
{
	if(copy.getGrade() > this->getExecGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if(this->getisSignedboolean() == false)
        throw(Form::FormNotSignedException());
    else
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox (weird name bro)!" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void)const
{
	return(this->_target);
}

std::ostream    &operator<<(std::ostream &c, PresidentialPardonForm &copy)
{
    c << "Form: " << copy.getName() << std::endl << "Sign Grade: " << copy.getGrade() << std::endl << "Exec Grade: " << copy.getExecGrade() << std::endl << "Is Signed: " << copy.getisSigned() << std::endl;
    return (c);
}
