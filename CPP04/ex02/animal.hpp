#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <iomanip>

class	Animal
{
	protected:
		std::string _type;
		Animal();
	public:
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual ~Animal();
		std::string getType() const;
		void		setType(std::string type);
		virtual void		makeSound() const = 0;
};

#endif
