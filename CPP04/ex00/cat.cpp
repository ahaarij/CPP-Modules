#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called!" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	operator=(copy);
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat Assignment overload called!" << std::endl;
	_type = copy._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << this->_type << " lets out a meow!" << std::endl;
}
