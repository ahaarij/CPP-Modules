#include "wronganimal.hpp"

wronganimal::wronganimal()
{
	std::cout << "WrongAnimal Default constructor called!" << std::endl;
	_type = "WrongAnimal";
}

wronganimal::wronganimal(std::string type)
{
	std::cout << "WrongAnimal Constructor with specified type called!" << std::endl;
	_type = type;
}

wronganimal::wronganimal(const wronganimal &copy)
{
	std::cout << "WrongAnimal Copy constructor called!" << std::endl;
	operator=(copy);
}

wronganimal &wronganimal::operator=(wronganimal const &copy)
{
	std::cout << "WrongAnimal Assignment overload called!" << std::endl;
	_type = copy._type;
	return (*this);
}

std::string wronganimal::getType() const
{
	return _type;
}

void	wronganimal::settype(std::string type)
{
	_type = type;
}

void	wronganimal::makeSound() const
{
	std::cout << "The WrongAnimal made a sound!" << std::endl;
}

wronganimal::~wronganimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}