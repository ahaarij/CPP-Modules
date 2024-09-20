#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "Claptrap.hpp"

class Fragtrap : public Claptrap
{
	public:
		Fragtrap();
		Fragtrap(std::string name);
		~Fragtrap();
		Fragtrap(Fragtrap const &copy);
		void	highFiveGuys();
};

#endif
