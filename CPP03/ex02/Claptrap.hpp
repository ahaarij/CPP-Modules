#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "iostream"
#include "iomanip"

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_att_dmg;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hp, unsigned int energy, unsigned int attack_dmg);
		ClapTrap(ClapTrap const &c);
		ClapTrap &operator=(ClapTrap const &copy);
		~ClapTrap();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
