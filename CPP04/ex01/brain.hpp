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
		Brain &operator=(const Brain &copy);
		const std::string getIdea(const size_t i);
		void	setIdea(size_t i, std::string idea);
		const std::string *getIdeaAddress(const size_t i);
};

#endif
