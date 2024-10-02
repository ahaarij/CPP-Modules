#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Noob", 100, 50, 20)
{
	std::cout << "ScavTrap with noob name has been created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap named " << name << " joins the fight!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
	operator=(copy);
}

void	ScavTrap::attack(std::string const &target)
{
	if(_energy >= 1 && _hp > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _att_dmg << " damage!" << std::endl;
		_energy--;
	}
	else if(_energy >= 1 && _hp <= 0)
	{
		std::cout << "ScavTrap " << _name << " does not have enough HP! " << "(" << _hp << ")" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " does not have enough energy! " << "(" << _energy << ")" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is guarding the gate!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "ScavTrap Assignment overload called" << std::endl;
	_name = copy._name;
	_hp = copy._hp;
	_energy = copy._energy;
	_att_dmg = copy._att_dmg;
	return (*this);
}
