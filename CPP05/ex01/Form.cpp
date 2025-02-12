#include "Form.hpp"

Form::Form():_name("Default"),_signed(false),_sign_grade(150),_exec_grade(150)
{
    std::cout << "Default constructor called for Form" << std::endl;
}

Form::Form(int sign_grade, int exec_grade):_name("Default"),_signed(false),_sign_grade(sign_grade),_exec_grade(exec_grade)
{
    std::cout << "Form Constructor with (" << this->getGrade() << ") Sign Grade and with (" << this->getExecGrade() << ") Exec Grade Called!" << std::endl;

    int x = this->getGrade();
    int y = this->getExecGrade();

    if(x > 150 || y > 150)
        throw(Form::GradeTooLowException());
    else if (x < 1 || y < 1)
        throw(Form::GradeTooHighException());
}

Form::Form(const std::string name):_name(name),_signed(false),_sign_grade(150),_exec_grade(150)
{
    std::cout << "Form Constructor with (" << this->getName() << ") Name Called!" << std::endl; 
}

Form::Form(const std::string name, int sign_grade, int exec_grade):_name(name),_signed(false),_sign_grade(sign_grade),_exec_grade(exec_grade)
{
    std::cout << "Form Constructor with (" << this->getName() << ") Name with (" << this->getGrade() << ") Sign Grade and with (" << this->getExecGrade() << ") Exec Grade Called!" << std::endl;

    int x = this->getGrade();
    int y = this->getExecGrade();

    if(x > 150 || y > 150)
        throw(Form::GradeTooLowException());
    else if (x < 1 || y < 1)
        throw(Form::GradeTooHighException());
}

Form::Form(const Form &copy):_name(copy.getName() + "_copy"),_signed(false),_sign_grade(copy.getGrade()),_exec_grade(copy.getExecGrade())
{
    std::cout << "Form Copy Constructor called for (" << copy.getName() << ") to become (" << this->getName() << ")!" << std::endl;
}

Form    &Form::operator=(const Form &copy)
{
    std::cout << "Form Assignment operator overload ( = ) called!" << std::endl;
    if (this == &copy)
        return (*this);
    // will change for next ex i think there'll be stuff to do then
    return (*this);
}

std::ostream &operator<<(std::ostream &c, Form const &copy)
{
    c << "Form: " << copy.getName() << std::endl << "Sign Grade: " << copy.getGrade() << std::endl << "Exec Grade: " << copy.getExecGrade() << std::endl << "Is Signed: " << copy.getisSigned() << std::endl;
    return (c);
}

Form::~Form()
{
    std::cout << "Destructor called for Form: " << this->getName() << std::endl;
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

const std::string	Form::getisSigned(void) const
{
	if(_signed == true)
		return ("Yurtt");
	else
		return ("Naurr");
}

bool	Form::getisSignedboolean(void) const
{
	return (this->_signed);
}

int	Form::getGrade(void) const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void) const
{
	return(this->_exec_grade);
}

void	Form::beSigned(Bureaucrat &copy)
{
	if(copy.getGrade() > this->getGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if(this->getisSignedboolean() == false)
	{
		this->_signed = true;
		std::cout << "Form " << this->getName() << " was signed by " << copy.getName() << std::endl;
	}
	else
		std::cout << copy.getName() << " has already signed a form!" << std::endl;
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High!");
};

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low!");
};
