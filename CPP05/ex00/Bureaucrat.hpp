#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private:
		int					_grade;
		const std::string	_name;
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		const std::string		&getName() const;
		void					setName(std::string name);
		const int				&getGrade() const;
		void					setGrade(int grade);
		std::string				GradeTooLowException(void);
		std::string				GradeTooHighException(void);
		void					Decrement(void);
		void					Increment(void);
};

std::ostream &operator<<(std::ostream &c, Bureaucrat const &copy);

#endif