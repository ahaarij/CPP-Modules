#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat():_name("Aarij"), _grade(69)
{
	std::cout << "Default Constructor Called for " << this->getName() << " who has a grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade):_name("Aarij")
{
	std::cout << "Constructor called with default name (" << this->getName() << ") who has a grade of" << this->getGrade() << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name):_grade(69), _name(name)
{
	std::cout << "Constructor called with name '" << this->getName() << "' who has a default grade of" << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	std::cout << "Constructor called with name '" << this->getName() << "' who has a grade of" << this->getGrade() << std::endl;
	setGrade(grade);
}

// increment and decrement

Bureaucrat::Decrement


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
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException ;
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException ;
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
	std::cout << "Assignment operator overload ( = ) called!" << std::endl;
	this->_grade = copy.getGrade();
	return (*this);
}


// ostream overload for obj



// exception handling? i guess?

std::string Bureaucrat::GradeTooHighException(void)
{
	return ("Grade Too High!\n");
}

std::string Bureaucrat::GradeTooLowException(void)
{
	return ("Grade Too Low!\n");
}

// destructor

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for " << this->getName() << std::endl;
}