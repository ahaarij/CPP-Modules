#include "wronganimal.hpp"

Wronganimal::Wronganimal()
{
	std::cout << "WrongAnimal Default constructor called!" << std::endl;
	_type = "WrongAnimal";
}

Wronganimal::Wronganimal(std::string type)
{
	std::cout << "WrongAnimal Constructor with specified type called!" << std::endl;
	_type = type;
}

Wronganimal::Wronganimal(const Wronganimal &copy)
{
	std::cout << "WrongAnimal Copy constructor called!" << std::endl;
	operator=(copy);
}

Wronganimal &Wronganimal::operator=(Wronganimal const &copy)
{
	std::cout << "WrongAnimal Assignment overload called!" << std::endl;
	_type = copy._type;
	return (*this);
}

std::string Wronganimal::getType() const
{
	return _type;
}

void	Wronganimal::setType(std::string type)
{
	_type = type;
}

void	Wronganimal::makeSound() const
{
	std::cout << "The WrongAnimal made a sound!" << std::endl;
}

Wronganimal::~Wronganimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}
