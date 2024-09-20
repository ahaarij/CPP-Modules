#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <iomanip>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(Brain const &copy);
		virtual ~Brain();
};

#endif
