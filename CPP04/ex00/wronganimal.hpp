#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iomanip>
#include <iostream>

class	wronganimal
{
	protected:
		std::string _type;
	public:
		wronganimal();
		wronganimal(std::string type);
		wronganimal(const Animal &copy);
		wronganimal &operator=(const wronganimal &copy);
		~wronganimal();
		std::string getType() const;
		void		setType(std::string type);
		void		makeSound() const;
};

#endif
