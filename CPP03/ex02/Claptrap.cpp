#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Noob"), _hp(10), _energy(10), _att_dmg(0)
{
	std::cout << "ClapTrap with noob name joins the fight!" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _energy(10), _att_dmg(0)
{
	std::cout << "ClapTrap named " << name << " joins the fight!" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int energy, unsigned int attack_dmg): _name(name), _hp(hp), _energy(energy), _att_dmg(attack_dmg)
{
	std::cout << "ClapTrap named " << name << " joins the fight!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &c)
{
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
	operator=(c);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " Destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << "ClapTrap Assignment overload called" << std::endl;
	_name = copy._name;
	_hp = copy._hp;
	_energy = copy._energy;
	_att_dmg = copy._att_dmg;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if(_energy >= 1 && _hp > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _att_dmg << " damage!" << std::endl;
		_energy--;
	}
	else if(_energy >= 1 && _hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " does not have enough HP! " << "(" << _hp << ")" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " does not have enough energy! " << "(" << _energy << ")" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if(_hp > amount)
		_hp -= amount;
	else if (_hp > 0)
		_hp = 0;
	else
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage and is now at " << _hp << " HP!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if(_energy > 0 && _hp > 0 && (_hp + amount) <= 10)
	{
		_hp += amount;
		std::cout << "ClapTrap " << _name << " heals itself and gained " << amount << " HP!" << std::endl;
		_energy--;
	}
	else if(_energy == 0)
		std::cout << "ClapTrap " << _name << " does not have enough energy! " << "(" << _energy << ")" << std::endl;
	else if(_hp == 0)
		std::cout << "ClapTrap " << _name << " cannot heal itself as its dead! T_T" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " cannot be healed to over *10* HP!" << std::endl;
}
