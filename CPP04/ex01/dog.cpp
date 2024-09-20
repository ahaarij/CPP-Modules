#include "dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called!" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	operator=(copy);
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog Assignment overload called!" << std::endl;
	_type = copy._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << this->_type << " lets out a woof!" << std::endl;
}
