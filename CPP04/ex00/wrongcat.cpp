#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor called!" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal (copy)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	operator=(copy);
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	std::cout << "WrongCat Assignment overload called!" << std::endl;
	_type = copy._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << this->_type << " lets out a meoooowwww!" << std::endl;
}
