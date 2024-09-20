#include "wrongcat.hpp"

Wrongcat::Wrongcat()
{
	std::cout << "Wrongcat Constructor called!" << std::endl;
	_type = "Wrongcat";
}

Wrongcat::Wrongcat(const Wrongcat &copy)
{
	std::cout << "Wrongcat copy constructor called!" << std::endl;
	operator=(copy);
}

Wrongcat &Wrongcat::operator=(Wrongcat const &copy)
{
	std::cout << "Wrongcat Assignment overload called!" << std::endl;
	_type = copy._type;
	return (*this);
}

Wrongcat::~Wrongcat()
{
	std::cout << "Wrongcat destructor called!" << std::endl;
}

void	Wrongcat::makeSound() const
{
	std::cout << this->_type << " lets out a meoooowwww!" << std::endl;
}
