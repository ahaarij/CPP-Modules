#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Aarij");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("pierce");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("john");
		b.beRepaired(3);
		// for (int i = 0; i < 12; i++)
		// 	b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap c;
		ScavTrap d("realAarij");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		c.attack("ZelBtw_");
		// for (int i = 0; i < 50; i++)
		// 	c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Luvi");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("Storm trooper");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		FragTrap e;
		FragTrap f("Mark Wahlberg");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		e.highFiveGuys();
		e.attack("Pierce");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("Randolph");
		f.highFiveGuys();
		// for(int i = 0; i < 101; i++)
		// 	f.attack("FragTrap-clone"); 
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}
