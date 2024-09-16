#include "iostream"
#include "iomanip"

class	Claptrap
{
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_att_dmg;
	public:
		Claptrap();
		Claptrap(std::string name);
		Claptrap(Claptrap const &c);
		Claptrap &operator=(Claptrap const &copy);
		~Claptrap();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
