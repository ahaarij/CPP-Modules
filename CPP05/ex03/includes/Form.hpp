#pragma once

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	protected:
		const std::string _name;
		bool	_signed;
		const	int		_sign_grade;
		const	int		_exec_grade;
		Form();
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);
	public:
		Form(const Form &copy);
	
		virtual ~Form();

		Form &operator=(const Form &copy);

		const std::string	&getName() const;
		const std::string	getisSigned() const;
		bool				getisSignedboolean() const;
		int					getGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat &copy);
		virtual void		execute(Bureaucrat const &copy)const = 0;

		class	GradeTooHighException: public std::exception
	{
		public:
		// throw indicates you're not throwing exceptions, which is the same as noexcept in new versions
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &c, Form const &copy);
