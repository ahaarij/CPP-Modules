#include "Fragtrap.hpp"

Fragtrap::Fragtrap(): Claptrap("Noob", 100, 100, 30)
{
	std::cout << "Fragtrap with noob name has been created!" << std::endl;
}

Fragtrap::Fragtrap(std::string name) : Claptrap(name, 100, 100, 30)
{
	std::cout << "Fragtrap named " << name << " joins the fight!" << std::endl;
}

Fragtrap::~Fragtrap()
{
	std::cout << "Fragtrap " << _name << " destroyed" << std::endl;
}

Fragtrap::Fragtrap(Fragtrap const &copy)
{
	std::cout << "Fragtrap copy constructor called for " << _name << std::endl;
	operator=(copy);
}

void	Fragtrap::highFiveGuys()
{
	std::cout << "You get a high five! And you get a high five! Everyone gets high fives!!" << std::endl;
}
