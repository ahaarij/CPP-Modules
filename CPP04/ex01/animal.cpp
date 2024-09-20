#include "animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called!" << std::endl;
	_type = "Animal";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal Constructor with specified type called! (" << type << ")" << std::endl;
	_type = type;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy constructor called!" << std::endl;
	operator=(copy);
}

Animal &Animal::operator=(Animal const &copy)
{
	std::cout << "Animal Assignment overload called" << std::endl;
	_type = copy._type;
	return (*this);
}


std::string	Animal::getType() const
{
	return _type;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

void	Animal::makeSound() const
{
	std::cout << _type << " made a sound!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}
