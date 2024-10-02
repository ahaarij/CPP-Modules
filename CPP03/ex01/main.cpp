#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a("Aarij");
	ScavTrap b("Pierce");

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
	b.beRepaired(1);
}

	// std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	// {
	// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	// 	ClapTrap a;
	// 	ClapTrap b("Aarij");

	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	a.attack("pierce");
	// 	a.takeDamage(10);
	// 	a.takeDamage(10);
	// 	a.beRepaired(5);
	// 	a.attack("john");
	// 	b.beRepaired(3);
	// 	// for (int i = 0; i < 12; i++)
	// 	// 	b.attack("Claptrap-clone");
	// 	b.beRepaired(3);
	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// }
	// std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	// {
	// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	// 	ScavTrap c;
	// 	ScavTrap d("realAarij");

	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	c.attack("ZelBtw_");
	// 	// for (int i = 0; i < 50; i++)
	// 	// 	c.attack("ScavTrap-clone");
	// 	c.beRepaired(22);
	// 	c.takeDamage(21);
	// 	c.beRepaired(22);
	// 	c.guardGate();
	// 	d.guardGate();
	// 	d.attack("Luvi");
	// 	d.takeDamage(101);
	// 	d.takeDamage(15);
	// 	d.attack("Storm trooper");
	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// }
