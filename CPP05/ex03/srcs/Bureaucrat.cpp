#include "../includes/Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat():_grade(69), _name("Aarij")
{
	std::cout << "Default Constructor Called for " << this->getName() << " who has a grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade):_name("Aarij")
{
	std::cout << "Constructor called with default name (" << this->getName() << ") who has a grade of " << this->getGrade() << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name):_grade(69), _name(name)
{
	std::cout << "Constructor called with name '" << this->getName() << "' who has a default grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_grade(grade),_name(name)
{
	std::cout << "Constructor called with name '" << this->getName() << "' who has a grade of " << this->getGrade() << std::endl;
}

// increment and decrement

void	Bureaucrat::Decrement(void)
{
	std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::Increment(void)
{
	std::cout << "Trying to increment grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}


// getters and setters

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

const int &Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException() ;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException() ;
	else
		this->_grade = grade;
}

// copy constructor and operator overload for equals

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Copy Constructor called for " << copy.getName() << std::endl;
	operator=(copy);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat Assignment operator overload ( = ) called!" << std::endl;
	this->_grade = copy.getGrade();
	return (*this);
}


// ostream overload for obj

std::ostream &operator<<(std::ostream &c, Bureaucrat const &copy)
{
	c << CYAN << copy.getName() << " has a grade of " << copy.getGrade() << RESET << std::endl;
	return (c);
}

// exception handling? i guess?
// so the what() is is basicaly its used to retrieve a descriptive error msg when an exception is thrown. basically
// just provides human readable message describing the error.

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!\n");
}

// Form Signing

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}


// destructor

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for " << this->getName() << std::endl;
}


// new stuff in ex02

void	Bureaucrat::executeForm(Form &form) const
{
	form.execute(*this);
}