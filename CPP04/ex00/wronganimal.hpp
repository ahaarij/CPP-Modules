#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iomanip>
#include <iostream>

class	WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);
		~WrongAnimal();
		std::string getType() const;
		void		setType(std::string type);
		void		makeSound() const;
};

#endif
