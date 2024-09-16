#include "Claptrap.hpp"

Claptrap::Claptrap(): _name(""), _hp(10), _energy(10), _att_dmg(0)
{
	std::cout << "Claptrap with no name joins the fight!" << std::endl;
}

Claptrap::Claptrap(std::string name): _name(name), _hp(10), _energy(10), _att_dmg(0)
{
	std::cout << "Claptrap named " << name << " joins the fight!" << std::endl;
}

Claptrap::Claptrap(Claptrap const &c)
{
	std::cout << "Claptrap copy constructor called for " << _name << std::endl;
	operator=(c);
}

Claptrap::~Claptrap()
{
	std::cout << "Claptrap " << _name << " Destroyed!" << std::endl;
}

Claptrap &Claptrap::operator=(Claptrap const &copy)
{
	std::cout << "Claptrap Assignment overload called" << std::endl;
	_name = copy._name;
	_hp = copy._hp;
	_energy = copy._energy;
	_att_dmg = copy._att_dmg;
	return (*this);
}

void	Claptrap::attack(const std::string &target)
{
	if(_energy >= 1)
	{
		std::cout << "Claptrap " << _name << " attacks " << target << " causing " << _att_dmg << " damage!" << std::endl;
		_energy--;
	}
	else
		std::cout << "Claptrap " << _name << " does not have enough energy! " << "(" << _energy << ")" << std::endl;
}

void	Claptrap::takeDamage(unsigned int amount)
{
	if(_hp > amount)
		_hp -= amount;
	else if (_hp > 0)
		_hp = 0;
	else
	{
		std::cout << "Claptrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << _name << " takes " << amount << " damage and is now at " << _hp << " HP!" << std::endl;
}

void	Claptrap::beRepaired(unsigned int amount)
{
	if(_energy > 0 && _hp > 0 && (_hp + amount) <= 10)
	{
		_hp += amount;
		std::cout << "Claptrap " << _name << " heals itself and gained " << amount << " HP!" << std::endl;
		_energy--;
	}
	else if(_energy == 0)
		std::cout << "Claptrap " << _name << " does not have enough energy! " << "(" << _energy << ")" << std::endl;
	else if(_hp == 0)
		std::cout << "Claptrap " << _name << " cannot heal itself as its dead! T_T" << std::endl;
	else
		std::cout << "Claptrap " << _name << " cannot be healed to over *10* HP!" << std::endl;
}
