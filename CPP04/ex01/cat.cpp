#include "cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called!" << std::endl;
	_type = "Cat";
	this->_brain = new Brain();
	if(!this->_brain)
	{
		std::cout << "Memory allocation failed!" << std::endl;
		exit (1);
	}
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	operator=(copy);
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat Assignment overload called!" << std::endl;
	_type = copy._type;
	this->_brain = new Brain();
	if(!this->_brain)
	{
		std::cout << "Memory allocation failed!" << std::<unnamed>
		exit (1);
	}
	_brain = copy._brain;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete this->_brain();
}

void	Cat::makeSound() const
{
	std::cout << this->_type << " lets out a meow!" << std::endl;
}
