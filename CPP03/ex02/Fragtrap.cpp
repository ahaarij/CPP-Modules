#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Noob", 100, 100, 30)
{
	std::cout << "FragTrap with noob name has been created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap named " << name << " joins the fight!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
	operator=(copy);
}

void	FragTrap::highFiveGuys()
{
	std::cout << "You get a high five! And you get a high five! Everyone gets high fives!!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "FragTrap Assignment overload called" << std::endl;
	_name = copy._name;
	_hp = copy._hp;
	_energy = copy._energy;
	_att_dmg = copy._att_dmg;
	return (*this);
}
