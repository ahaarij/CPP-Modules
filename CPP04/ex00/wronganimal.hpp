#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iomanip>
#include <iostream>

class	Wronganimal
{
	protected:
		std::string _type;
	public:
		Wronganimal();
		Wronganimal(std::string type);
		Wronganimal(const Wronganimal &copy);
		Wronganimal &operator=(const Wronganimal &copy);
		~Wronganimal();
		std::string getType() const;
		void		setType(std::string type);
		void		makeSound() const;
};

#endif
