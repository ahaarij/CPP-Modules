#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("Aarij");
	ClapTrap b("Pierce");

	b.takeDamage(2);
	b.beRepaired(2);
	b.attack("Aarij");
	a.takeDamage(0);
	a.attack("Pierce");
	b.takeDamage(7);
	b.attack("Ayan");
	b.beRepaired(7);
	a.attack("Pierce");
	b.takeDamage(10000);
}
