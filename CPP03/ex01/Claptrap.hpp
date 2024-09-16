#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "iostream"
#include "iomanip"



class	Claptrap
{
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_att_dmg;
	public:
		Claptrap();
		Claptrap(std::string name);
		Claptrap(std::string name, unsigned int hp, unsigned int energy, unsigned int attack_dmg);
		Claptrap(Claptrap const &c);
		Claptrap &operator=(Claptrap const &copy);
		~Claptrap();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
