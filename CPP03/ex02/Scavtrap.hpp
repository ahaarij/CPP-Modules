#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "Claptrap.hpp"

class Scavtrap : public Claptrap
{
	protected:
	public:
		Scavtrap();
		Scavtrap(std::string name);
		~Scavtrap();
		Scavtrap(Scavtrap const &copy);
		void	attack(std::string const &target);
		void	guardGate();
};

#endif
