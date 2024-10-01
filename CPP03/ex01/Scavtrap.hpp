#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	protected:
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap const &copy);
		void	attack(std::string const &target);
		void	guardGate();
};

#endif
