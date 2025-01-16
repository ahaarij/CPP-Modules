#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
	private:
		int					_grade;
		const std::string	_name;
		void				setGrade(int grade);
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
		void					Decrement(void);
		void					Increment(void);


	// derives from std::exception which is a pre-defined class
	// it also provides a virtual what() so it can be changed for better error descriptions.

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

std::ostream &operator<<(std::ostream &c, Bureaucrat const &copy);

# define RESET		"\x1b[0m"
# define BOLD		"\x1b[1m"
# define UNDER		"\x1b[4m"
# define REV		"\x1b[7m"
# define GREY		"\x1b[30m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define PURPLE		"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1b[37m"

#endif