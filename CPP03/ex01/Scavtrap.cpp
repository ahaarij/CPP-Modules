#include "Scavtrap.hpp"

Scavtrap::Scavtrap() : Claptrap("", 100, 50, 20)
{
	std::cout << "Scavtrap with no name has been created!" << std::endl;
}

Scavtrap::Scavtrap(std::string name) : Claptrap(name, 100, 50, 20)
{
	std::cout << "Scavtrap named " << name << " joins the fight!" << std::endl;
}

Scavtrap::~Scavtrap()
{
	std::cout << "Scavtrap " << _name << " destroyed!" << std::endl;
}

Scavtrap::Scavtrap(Scavtrap const &copy)
{
	std::cout << "Scavtrap copy constructor called for " << _name << std::endl;
	operator=(copy);
}

void	Scavtrap::attack(std::string const &target)
{
	if(_energy >= 1)
	{
		std::cout << "Scavtrap " << _name << " attacks " << target << " causing " << _att_dmg << " damage!" << std::endl;
		_energy--;
	}
	else
		std::cout << "Scavtrap " << _name << " does not have enough energy! " << "(" << _energy << ")" << std::endl;
}

void	Scavtrap::guardGate()
{
	std::cout << "Scavtrap " << _name << "is guarding the gate!" << std::endl;
}
