#pragma once

#include "iostream"

class	Form
{
	private:
		const std::string _name;
		bool	_signed;
		const	int		_grade;
		const	int		_exec_grade;
	public:
		Form();
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);


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
};

std::ostream &operator<<(std::ostream &c, Form const &copy);
